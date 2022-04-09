#include <DxLib.h>
#include "../../.h/Application.h"
#include "../../.h/scene/RectEdit.h"
#include "../../.h/FileLoader.h"
#include "../../.h/ImageManager.h"
#include "../../.h/Animation.h"

RectEdit::RectEdit()
{
	if (!Init())
	{

	}
}

RectEdit::~RectEdit()
{
}

UniqueScene RectEdit::Update(UniqueScene own, const std::shared_ptr<KeyInput>& key, const std::shared_ptr<MouseInput>& mouse)
{
	

	ClsDrawScreen();
	Draw();
	ScreenFlip();
	return move(own);
}

bool RectEdit::Init(void)
{
	editScreen_.size_ = { 400,400 };
	editScreen_.pos_ = { lpApplication.GetScreenSize().x - (editScreen_.size_.x +50),
					     lpApplication.GetScreenSize().y / 2 - (editScreen_.size_.y / 2) };

	baseInfoBox_ = BoxRect({ 40,50 }, { 570,250 });
	objectTextBox_ = BoxRect({ 50,120 }, { 250,30 });
	animationTextBox_ = BoxRect({ 350,120 }, { 250,30 });
	pathNameTextBox_ = BoxRect({ 50,190 }, { 435,30 });
	loopFlagTextBox_ = BoxRect({ 50,260 }, { 100,30 });
	maxFrameTextBox_ = BoxRect({ 400,260 }, { 30,30 });

	imagePos_ = { editScreen_.pos_.x + (editScreen_.size_.x / 2),editScreen_.pos_.y + (editScreen_.size_.y / 2) };
	return true;
}

void RectEdit::Draw(void)
{
	DrawFormatString(20,20, 0xffffff, "RectEditor.RectEdit");


	DrawBox(baseInfoBox_.pos_.x, baseInfoBox_.pos_.y,
		baseInfoBox_.pos_.x + baseInfoBox_.size_.x,
		baseInfoBox_.pos_.y + baseInfoBox_.size_.y,
		0x00f0ff, true);
	// ��{��񃉃x���\��
	DrawFormatString(baseInfoBox_.pos_.x + 5, baseInfoBox_.pos_.y + 15, 0x000000, "��{���");

	// �e�\��------------------------------------------------------------
	// �I�u�W�F�N�g��
	DrawFormatString(objectTextBox_.pos_.x, objectTextBox_.pos_.y - 20, 0x000000, "�I�u�W�F�N�g��");
	DrawBox(objectTextBox_.pos_.x, objectTextBox_.pos_.y,
		objectTextBox_.pos_.x + objectTextBox_.size_.x,
		objectTextBox_.pos_.y + objectTextBox_.size_.y,
		0xffffff, true);
	DrawFormatString(objectTextBox_.pos_.x + 5, objectTextBox_.pos_.y + 7, 0xff0000, "%s",lpAnimation.GetObjectName().c_str());

	// �A�j���[�V������
	DrawFormatString(animationTextBox_.pos_.x, animationTextBox_.pos_.y - 20, 0x000000, "�A�j���[�V������");
	DrawBox(animationTextBox_.pos_.x, animationTextBox_.pos_.y,
		animationTextBox_.pos_.x + animationTextBox_.size_.x,
		animationTextBox_.pos_.y + animationTextBox_.size_.y,
		0xffffff, true);
	DrawFormatString(animationTextBox_.pos_.x + 5, animationTextBox_.pos_.y + 7, 0xff0000, "%s", lpAnimation.GetName().c_str());

	// �t�@�C���p�X��
	DrawFormatString(pathNameTextBox_.pos_.x, pathNameTextBox_.pos_.y - 20, 0x000000, "�t�@�C���p�X��");
	DrawBox(pathNameTextBox_.pos_.x, pathNameTextBox_.pos_.y,
		pathNameTextBox_.pos_.x + pathNameTextBox_.size_.x,
		pathNameTextBox_.pos_.y + pathNameTextBox_.size_.y,
		0xffffff, true);
	DrawFormatString(pathNameTextBox_.pos_.x + 5, pathNameTextBox_.pos_.y + 7,
		0xff0000, "Images/Actors/%s/%s.png",
		lpAnimation.GetObjectName().c_str(), lpAnimation.GetName().c_str());

	// ���[�v�Đ��ۂ̃t���O
	DrawFormatString(loopFlagTextBox_.pos_.x, loopFlagTextBox_.pos_.y - 20, 0x000000, "���[�v(true:���[�v false:���[�v�Ȃ�)");
	DrawBox(loopFlagTextBox_.pos_.x, loopFlagTextBox_.pos_.y,
		loopFlagTextBox_.pos_.x + loopFlagTextBox_.size_.x,
		loopFlagTextBox_.pos_.y + loopFlagTextBox_.size_.y,
		0xffffff, true);
	lpAnimation.IsLoop() ?
		DrawFormatString(loopFlagTextBox_.pos_.x + 5, loopFlagTextBox_.pos_.y + 7, 0xff0000, "true") :
		DrawFormatString(loopFlagTextBox_.pos_.x + 5, loopFlagTextBox_.pos_.y + 7, 0xff0000, "false");

	// �ő�R�}��
	DrawFormatString(maxFrameTextBox_.pos_.x, maxFrameTextBox_.pos_.y - 20, 0x000000, "�ő�R�}��");
	DrawBox(maxFrameTextBox_.pos_.x, maxFrameTextBox_.pos_.y,
		maxFrameTextBox_.pos_.x + maxFrameTextBox_.size_.x,
		maxFrameTextBox_.pos_.y + maxFrameTextBox_.size_.y,
		0xffffff, true);
	DrawFormatString(maxFrameTextBox_.pos_.x + 5, maxFrameTextBox_.pos_.y + 7, 0xff0000, "%d", lpAnimation.GetMaxFrame());

	// �ҏW�Ώۉ摜�\���̈�
	DrawBox(editScreen_.pos_.x, editScreen_.pos_.y,
		editScreen_.pos_.x + editScreen_.size_.x,
		editScreen_.pos_.y + editScreen_.size_.y,
		0xa0a0a0, true);

	// �ҏW�Ώۉ摜�\��
	DrawRotaGraph(imagePos_.x, imagePos_.y, 1.0, 0.0,
		lpImageManager.GetHandles(lpAnimation.GetObjectName() + "/" + lpAnimation.GetName())[0], true);
}
