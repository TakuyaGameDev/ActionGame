#include <DxLib.h>
#include "../../.h/Scene/BaseScene.h"
#include "../../.h/Application.h"

BaseScene::BaseScene()
{
	scrHdl_ = MakeScreen(lpApplication.GetScreenSize().x,lpApplication.GetScreenSize().y,true);
}

BaseScene::~BaseScene()
{
}
