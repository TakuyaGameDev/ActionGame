#include <DxLib.h>
#include "../.h/Application.h"
#include "../.h/input/KeyInput.h"

void Application::Run(void)
{
    // DxLibの初期化が正常に終わらなかったら
    // ゲームループには入らない
    if (!SystemInit())
    {
        return;
    }
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {

    }
}

void Application::Exit(void)
{
	DxLib_End();
}

void Application::SetScreenSize(Vector2I screen, Vector2I image)
{
    scrSize_.screen_ = screen;
    scrSize_.image_screen_ = image;
}

Application::~Application()
{
}

bool Application::SystemInit(void)
{
    SetScreenSize({ SCREEN_X,SCREEN_Y }, { IMAGE_SCREEN_X,IMAGE_SCREEN_Y });
    // 設定した画面サイズで画面表示
    SetGraphMode(scrSize_.screen_.x, scrSize_.screen_.y, 16);
    ChangeWindowMode(true);
    // ウィンドウラベルセット
    SetWindowText("ActionRectEditor");
    // DxLibの初期化が正常に終了しなかったらfalse
    if (DxLib_Init() == -1)
    {
        return false;
    }
    // キーボード入力装置取得
    key_ = std::make_shared<KeyInput>();
	return true;
}
