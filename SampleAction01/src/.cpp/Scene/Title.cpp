#include <DxLib.h>
#include "../../.h/Scene/Title.h"
#include "../../.h/Scene/Game.h"
#include "../../.h/Input/Controller.h"

Title::Title()
{
	// 初期化失敗したらエラー文を表示する(業務用エラーとして)
	if (!Init())
	{

	}
}

Title::~Title()
{
	// スクリーンの削除
	DeleteGraph(scrHdl_);
}

Scene Title::Update(Scene own, const std::shared_ptr<Controller>& controller)
{
	// コントローラー情報の取得
	auto input = controller->GetInputCmd();

	// とりあえずスタートボタンを押されたらGame画面に移行
	if (input[INT(COMMAND::START)][INT(TRG::NOW)]
		&& !input[INT(COMMAND::START)][INT(TRG::OLD)])
	{
		return std::make_unique<Game>();
	}

	// 描画
	Draw();
	return move(own);
}

bool Title::Init(void)
{
	// もし画像ハンドルがエラー値だったらそのあとの処理はしない
	if (scrHdl_ <= 0)
	{
		return false;
	}
	// 固定背景ハンドルの生成
	SetDrawScreen(scrHdl_);
	DrawFormatString(0,0,0xffffff,"title");
	// 描画先をBACKに変更
	SetDrawScreen(DX_SCREEN_BACK);
	return true;
}

void Title::Draw(void)
{
	ClsDrawScreen();
	// 固定背景の描画
	DrawGraph(0, 0, scrHdl_, true);
	// キャラを描画したいときはこちらに記述
	ScreenFlip();
}
