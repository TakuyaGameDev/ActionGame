#include "../../.h/Input/Controller.h"

void Controller::SetCommand(COMMAND cmd, int input)
{
	// Šù‚É“o˜^Ï‚İ‚¾‚Á‚½‚ç“o˜^‚³‚¹‚È‚¢
	command_.try_emplace(cmd, input);
}
