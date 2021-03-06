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
	// キーの入力情報の取得
	GetHitKeyStateAll(&keyData_[0]);

	for (auto cmd : COMMAND())
	{
		inputCmd_[INT(cmd)][INT(TRG::OLD)] = inputCmd_[INT(cmd)][INT(TRG::NOW)];
		// 押されていたら1が入るのでtrueになる
		inputCmd_[INT(cmd)][INT(TRG::NOW)] = keyData_[command_[cmd]];
	}
}

bool KeyInput::Init(void)
{
	
	return true;
}
