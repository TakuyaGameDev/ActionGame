#include "../../.h/Input/Controller.h"

void Controller::SetCommand(COMMAND cmd, int input)
{
	// ���ɓo�^�ς݂�������o�^�����Ȃ�
	command_.try_emplace(cmd, input);
}
