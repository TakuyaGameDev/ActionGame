#include <DxLib.h>
#include "../../.h/input/MouseInput.h"

MouseInput::MouseInput()
{
	// �N���b�N�̃t���O�𗼕�������
	clickData_[MOUSE_COMMAND::CLICK_L] = { false,false };
	clickData_[MOUSE_COMMAND::CLICK_R] = { false,false };
}

MouseInput::~MouseInput()
{
}

void MouseInput::Update(void)
{
	// �}�E�X�|�C���^�̍X�V
	GetMousePoint(&pos_.x, &pos_.y);

	// �}�E�X�̓���(�E�N���b�N�A���N���b�N)
	// 1�t���[���O�̃t���O�ɑ��
	// ����Ńg���K�[�������\�ɂ��Ă���
	for (auto m_cmd : MOUSE_COMMAND())
	{
		clickData_[m_cmd][static_cast<int>(TRG::OLD)] = clickData_[m_cmd][static_cast<int>(TRG::NOW)];
	}
	// ���N���b�N��
	if (GetMouseInput() & MOUSE_INPUT_LEFT)
	{
		clickData_[MOUSE_COMMAND::CLICK_L][static_cast<int>(TRG::NOW)] = true;
	}
	// ���N���b�N���Ă��Ȃ���
	else
	{
		clickData_[MOUSE_COMMAND::CLICK_L][static_cast<int>(TRG::NOW)] = false;
	}
	// �E�N���b�N��
	if (GetMouseInput() & MOUSE_INPUT_RIGHT)
	{
		clickData_[MOUSE_COMMAND::CLICK_R][static_cast<int>(TRG::NOW)] = true;
	}
	// �E�N���b�N���Ă��Ȃ���
	else
	{
		clickData_[MOUSE_COMMAND::CLICK_R][static_cast<int>(TRG::NOW)] = false;
	}
}
