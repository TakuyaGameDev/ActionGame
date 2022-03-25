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
	// ƒL[‚Ì“ü—Íî•ñ‚Ìæ“¾
	GetHitKeyStateAll(&keyData_[0]);

	for (auto cmd : COMMAND())
	{
		inputCmd_[INT(cmd)][INT(TRG::OLD)] = inputCmd_[INT(cmd)][INT(TRG::NOW)];
		// ‰Ÿ‚³‚ê‚Ä‚¢‚½‚ç1‚ª“ü‚é‚Ì‚Åtrue‚É‚È‚é
		inputCmd_[INT(cmd)][INT(TRG::NOW)] = keyData_[command_[cmd]];
	}
}

bool KeyInput::Init(void)
{
	
	return true;
}
