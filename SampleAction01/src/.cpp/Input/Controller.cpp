#include "../../.h/Input/Controller.h"

void Controller::SetCommand(COMMAND cmd, int input)
{
	// 既に登録済みだったら登録させない
	command_.try_emplace(cmd, input);
}
