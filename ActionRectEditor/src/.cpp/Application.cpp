#include <DxLib.h>
#include "../.h/Application.h"
#include "../.h/input/KeyInput.h"
#include "../.h/input/MouseInput.h"

#include "../.h/scene/StartUp.h"

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
        // キーボード押下情報更新
        key_->Update();
        // マウス情報の更新
        mouse_->Update();
        // シーン更新
        scene_ = scene_->Update(move(scene_), key_,mouse_);
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
    // 各画面サイズの設定
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
    // キーボード入力装置生成
    key_ = std::make_shared<KeyInput>();
    // 決定ボタン
    key_->SetKeyCommand(KEY_COMMAND::DECIDE, KEY_INPUT_RETURN);
    // セーブボタン
    key_->SetKeyCommand(KEY_COMMAND::SAVE, KEY_INPUT_S);
    // undoボタン
    key_->SetKeyCommand(KEY_COMMAND::UNDO, KEY_INPUT_Z);
    // コントロールキー
    key_->SetKeyCommand(KEY_COMMAND::CTRL, KEY_INPUT_LCONTROL);
    // マウス入力装置生成
    mouse_ = std::make_shared<MouseInput>();

    // 初期シーンでインスタンス
    scene_ = std::make_unique<StartUp>();
	return true;
}
