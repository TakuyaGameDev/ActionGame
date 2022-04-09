#include <DxLib.h>
#include "../../.h/scene/StartUp.h"
#include "../../.h/input/KeyInput.h"
#include "../../.h/input/MouseInput.h"
#include "../../.h/Application.h"
#include "../../.h/Animation.h"
#include "../../.h/ImageManager.h"
#include "../../.h/FileLoader.h"
#include "../../.h/scene/RectEdit.h"

StartUp::StartUp()
{
	if (!Init())
	{
		// 初期化がうまくいかなかったらここに入る

	}
}

StartUp::~StartUp()
{
}

UniqueScene StartUp::Update(UniqueScene own, const std::shared_ptr<KeyInput>& key, const std::shared_ptr<MouseInput>& mouse)
{
	char tmpInputStr[20];
	auto keyInput = key->GetCommand();
	mouse_ = mouse->GetPos();

	// リセットボタン押下時の処理
	if (isAbleReset_)
	{
		if (mouse_.x >= resetBtn_.pos_.x && mouse_.y >= resetBtn_.pos_.y &&
			mouse_.x <= resetBtn_.pos_.x + resetBtn_.size_.x && mouse_.y <= resetBtn_.pos_.y + resetBtn_.size_.y)
		{
			if (mouse->GetClick(MOUSE_COMMAND::CLICK_L)[static_cast<int>(TRG::NOW)] &&
				mouse->GetClick(MOUSE_COMMAND::CLICK_L)[static_cast<int>(TRG::OLD)])
			{
				// 画像管理クラスのリセット
				lpImageManager.Reset();
				// FileLoaderのリセット
				lpFileLoader.Reset();
				nowPhase_ = PHASE_TYPE::ACTOR;
				isAbleReset_ = false;
			}
		}
	}
	if (nowPhase_ == PHASE_TYPE::MAX)
	{
		if (keyInput[KEY_COMMAND::DECIDE][static_cast<int>(TRG::NOW)] &&
			!keyInput[KEY_COMMAND::DECIDE][static_cast<int>(TRG::OLD)])
		{
			return std::make_unique<RectEdit>();
		}
	}

	// 描画
	ClsDrawScreen();
	Draw();
	ScreenFlip();
	if (nowPhase_ != PHASE_TYPE::MAX)
	{
		functionMap_[nowPhase_](tmpInputStr);
	}
	return move(own);
}

bool StartUp::Init(void)
{
	isAbleReset_ = false;
	nowPhase_ = PHASE_TYPE::ACTOR;
	textBox_[static_cast<int>(PHASE_TYPE::ACTOR)] = BoxRect({ 100,100 }, {250,30});
	textBox_[static_cast<int>(PHASE_TYPE::ANIMATION)] = BoxRect({ 100,200 }, { 250,30 });
	textBox_[static_cast<int>(PHASE_TYPE::LOOP)] = BoxRect({ 100,300 }, { 50,30 });
	imagePreviewBox_ = BoxRect({ 100,400 }, { 600,200 });
	animationListBox_ = BoxRect({ 710,30 }, { 478,600 });
	resetBtn_ = BoxRect({ 600,360 }, { 100,30 });
	navStr_ = { "オブジェクト名を入力","FileNo(数字)を入力","ループ再生フラグを入力(1:true 0:false)"};
	// 画像管理クラスの生成
	lpImageManager.Create();
	// FileLoaderの生成
	lpFileLoader.Create();
	functionMap_.try_emplace(PHASE_TYPE::ACTOR, [&](char* inputStr) {
		KeyInputSingleCharString(textBox_[static_cast<int>(nowPhase_)].pos_.x + 3,
			textBox_[static_cast<int>(nowPhase_)].pos_.y + 7,20, inputStr, true);
		lpAnimation.SetObjectName(inputStr);
		imgSize_ = lpFileLoader.GetImageSize(inputStr);
		// ファイルディレクトリのファイル名一覧取得
		lpFileLoader.FindFileNameList(inputStr);
		nowPhase_ = PHASE_TYPE::ANIMATION;
		});
	functionMap_.try_emplace(PHASE_TYPE::ANIMATION, [&](char* inputStr) {
		KeyInputSingleCharString(textBox_[static_cast<int>(nowPhase_)].pos_.x + 3,
			textBox_[static_cast<int>(nowPhase_)].pos_.y + 7, 20, inputStr, true);
		if (std::atoi(inputStr) > 0)
		{
			auto tmpPath = lpFileLoader.GetFilenames()[std::atoi(inputStr) - 1];

			int lastSlashPos = tmpPath.find_last_of('/');

			auto animName = tmpPath.substr(lastSlashPos+1);
			animName = animName.replace(animName.find('.'),animName.size(),"");

			lpAnimation.SetName(animName);
			auto divCnt = lpFileLoader.LoadAnimationData(animName);
			// 入力した文字を基に画像のロード
			lpImageManager.Load(lpAnimation.GetObjectName() + "/" + lpAnimation.GetName(), imgSize_, divCnt);
			nowPhase_ = PHASE_TYPE::LOOP;
		}
	});
	functionMap_.try_emplace(PHASE_TYPE::LOOP, [&](char* inputStr) {
		KeyInputSingleCharString(textBox_[static_cast<int>(nowPhase_)].pos_.x + 3,
			textBox_[static_cast<int>(nowPhase_)].pos_.y + 7, 20, inputStr, true);
		lpAnimation.SetIsLoop(inputStr);
		isAbleReset_ = true;
		nowPhase_ = PHASE_TYPE::MAX;
	});
	return true;
}

void StartUp::Draw(void)
{
	DrawFormatString(20,20, 0xffffff, "RectEditor.StartUp");
	for (auto phase : PHASE_TYPE())
	{
		DrawFormatString(textBox_[static_cast<int>(phase)].pos_.x, textBox_[static_cast<int>(phase)].pos_.y - 20, 0xffffff, "%s", navStr_[static_cast<int>(phase)].c_str());
	}
	for (auto box : textBox_)
	{
		DrawBox(box.pos_.x, box.pos_.y, box.pos_.x + box.size_.x, box.pos_.y + box.size_.y, 0xffffff, false);
	}
	if (lpAnimation.GetObjectName() != "")
	{
		DrawFormatString(textBox_[static_cast<int>(PHASE_TYPE::ACTOR)].pos_.x + textBox_[static_cast<int>(PHASE_TYPE::ACTOR)].size_.x + 50,
			textBox_[static_cast<int>(PHASE_TYPE::ACTOR)].pos_.y + 10, 0xffffff, "%s", lpAnimation.GetObjectName().c_str());
	}
	if (lpAnimation.GetName() != "")
	{
		DrawFormatString(textBox_[static_cast<int>(PHASE_TYPE::ANIMATION)].pos_.x + textBox_[static_cast<int>(PHASE_TYPE::ANIMATION)].size_.x + 50,
			textBox_[static_cast<int>(PHASE_TYPE::ANIMATION)].pos_.y + 10, 0xffffff, "%s", lpAnimation.GetName().c_str());
	}
	DrawFormatString(textBox_[static_cast<int>(PHASE_TYPE::LOOP)].pos_.x + textBox_[static_cast<int>(PHASE_TYPE::LOOP)].size_.x + 50,
		textBox_[static_cast<int>(PHASE_TYPE::LOOP)].pos_.y + 10, 0xffffff,lpAnimation.IsLoop()?"true":"false");

	DrawFormatString(imagePreviewBox_.pos_.x, imagePreviewBox_.pos_.y - 20, 0xffffff, "画像プレビュー");
	DrawBox(imagePreviewBox_.pos_.x, imagePreviewBox_.pos_.y,
		imagePreviewBox_.pos_.x + imagePreviewBox_.size_.x,
		imagePreviewBox_.pos_.y + imagePreviewBox_.size_.y, 0xa0a0a0, true);

	DrawFormatString(animationListBox_.pos_.x, animationListBox_.pos_.y - 20, 0xffffff, "ファイルリスト");

	DrawBox(animationListBox_.pos_.x, animationListBox_.pos_.y,
		animationListBox_.pos_.x + animationListBox_.size_.x,
		animationListBox_.pos_.y + animationListBox_.size_.y, 0xffffff, true);

	// リセット押下可能でない場合
	if (!isAbleReset_)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 120);
		DrawBox(resetBtn_.pos_.x, resetBtn_.pos_.y,
			resetBtn_.pos_.x + resetBtn_.size_.x,
			resetBtn_.pos_.y + resetBtn_.size_.y,
			0xa0a0a0, true);
		DrawFormatString(resetBtn_.pos_.x + 17, resetBtn_.pos_.y + 7, 0xffffff, "リセット");
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	else
	{
		DrawBox(resetBtn_.pos_.x, resetBtn_.pos_.y,
			resetBtn_.pos_.x + resetBtn_.size_.x,
			resetBtn_.pos_.y + resetBtn_.size_.y,
			0xa0a0a0, true);
		DrawFormatString(resetBtn_.pos_.x + 17, resetBtn_.pos_.y + 7, 0xffffff, "リセット");
	}

	if (lpFileLoader.GetFilenames().size())
	{
		for (int i = 0; i < lpFileLoader.GetFilenames().size(); i++)
		{
			auto noStr = std::to_string(i+1);
			if (i / 10 <= 0 && i != 9)
			{
				noStr.insert(0,"0");
			}
			DrawFormatString(animationListBox_.pos_.x + 15,
				animationListBox_.pos_.y + 15 + (i * 23),
				0x000000, "・FileNo.%s:%s",
				noStr.c_str(), lpFileLoader.GetFilenames()[i].c_str());
		}
	}
	if (nowPhase_ == PHASE_TYPE::LOOP || nowPhase_ == PHASE_TYPE::MAX)
	{
		for (int i = 0; i < lpImageManager.GetHandles(lpAnimation.GetObjectName() + "/" + lpAnimation.GetName()).size(); i++)
		{
			DrawGraph(imagePreviewBox_.pos_.x + (i * 100),
				imagePreviewBox_.pos_.y + (imagePreviewBox_.size_.y/2-lpImageManager.GetImageSize().y/2),
				lpImageManager.GetHandles(lpAnimation.GetObjectName() + "/" + lpAnimation.GetName())[i], true);
		}
	}

	if (nowPhase_ == PHASE_TYPE::MAX)
	{
		DrawFormatString(0, 610, 0xff0000, "←Enterキーで編集へ");
	}
}
