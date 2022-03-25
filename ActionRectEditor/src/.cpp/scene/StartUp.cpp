#include <DxLib.h>
#include "../../.h/scene/StartUp.h"
#include "../../.h/input/KeyInput.h"
#include "../../.h/input/MouseInput.h"

StartUp::StartUp()
{
	if (!Init())
	{
		// ‰Šú‰»‚ª‚¤‚Ü‚­‚¢‚©‚È‚©‚Á‚½‚ç‚±‚±‚É“ü‚é

	}
}

StartUp::~StartUp()
{
}

UniqueScene StartUp::Update(UniqueScene own, const std::shared_ptr<KeyInput>& key, const std::shared_ptr<MouseInput>& mouse)
{
	auto keyInput = key->GetCommand();
	mouse_ = mouse->GetPos();

	// •`‰æ
	ClsDrawScreen();
	Draw();
	ScreenFlip();
	return move(own);
}

bool StartUp::Init(void)
{
	return true;
}

void StartUp::Draw(void)
{
	DrawFormatString(0, 0, 0xffffff, "StartUp");
	DrawCircle(mouse_.x, mouse_.y, 2, 0x00ff00, true);
}
