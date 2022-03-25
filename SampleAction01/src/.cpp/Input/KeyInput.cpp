#include <DxLib.h>
#include "../../.h/Input/KeyInput.h"

KeyInput::KeyInput()
{
	Init();
}

KeyInput::~KeyInput()
{
}

void KeyInput::Update(void)
{
	// �L�[�̓��͏��̎擾
	GetHitKeyStateAll(&keyData_[0]);

	for (auto cmd : COMMAND())
	{
		inputCmd_[INT(cmd)][INT(TRG::OLD)] = inputCmd_[INT(cmd)][INT(TRG::NOW)];
		// ������Ă�����1������̂�true�ɂȂ�
		inputCmd_[INT(cmd)][INT(TRG::NOW)] = keyData_[command_[cmd]];
	}
}

bool KeyInput::Init(void)
{
	
	return true;
}
