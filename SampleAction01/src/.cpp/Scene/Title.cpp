#include <DxLib.h>
#include "../../.h/Scene/Title.h"
#include "../../.h/Scene/Game.h"
#include "../../.h/Input/Controller.h"

Title::Title()
{
	// ���������s������G���[����\������(�Ɩ��p�G���[�Ƃ���)
	if (!Init())
	{

	}
}

Title::~Title()
{
	// �X�N���[���̍폜
	DeleteGraph(scrHdl_);
}

Scene Title::Update(Scene own, const std::shared_ptr<Controller>& controller)
{
	// �R���g���[���[���̎擾
	auto input = controller->GetInputCmd();

	// �Ƃ肠�����X�^�[�g�{�^���������ꂽ��Game��ʂɈڍs
	if (input[INT(COMMAND::START)][INT(TRG::NOW)]
		&& !input[INT(COMMAND::START)][INT(TRG::OLD)])
	{
		return std::make_unique<Game>();
	}

	// �`��
	Draw();
	return move(own);
}

bool Title::Init(void)
{
	// �����摜�n���h�����G���[�l�������炻�̂��Ƃ̏����͂��Ȃ�
	if (scrHdl_ <= 0)
	{
		return false;
	}
	// �Œ�w�i�n���h���̐���
	SetDrawScreen(scrHdl_);
	DrawFormatString(0,0,0xffffff,"title");
	// �`����BACK�ɕύX
	SetDrawScreen(DX_SCREEN_BACK);
	return true;
}

void Title::Draw(void)
{
	ClsDrawScreen();
	// �Œ�w�i�̕`��
	DrawGraph(0, 0, scrHdl_, true);
	// �L������`�悵�����Ƃ��͂�����ɋL�q
	ScreenFlip();
}
