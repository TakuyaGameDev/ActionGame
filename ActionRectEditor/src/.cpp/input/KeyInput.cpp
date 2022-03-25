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
	GetHitKeyStateAll(&keyState_[0]);

	for (auto cmd : KEY_COMMAND())
	{
		inputKeyCommand_[cmd][static_cast<int>(TRG::OLD)] = inputKeyCommand_[cmd][static_cast<int>(TRG::NOW)];
		inputKeyCommand_[cmd][static_cast<int>(TRG::NOW)] = keyState_[keyCommandTbl_[cmd]];
	}

}

bool KeyInput::Init(void)
{
	
	return true;
}

void KeyInput::SetKeyCommand(KEY_COMMAND cmd, int inputCmd)
{
	keyCommandTbl_.try_emplace(cmd, inputCmd);
}
