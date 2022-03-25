#include <DxLib.h>
#include "../.h/Application.h"
#include "../.h/Scene/Title.h"
#include "../.h/Input/KeyInput.h"

Application::~Application()
{
}

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
        // コントローラーの更新
        (*controller_)();
        // シーンの更新
        scene_ = scene_->Update(move(scene_),controller_);
    }
}

void Application::Exit(void)
{
    // DxLibの終了
    DxLib_End();
}

bool Application::SystemInit(void)
{
    // 各画面サイズの設定
    SetScreenSize({ SCREEN_X,SCREEN_Y });
    // 設定した画面サイズで画面表示
    SetGraphMode(screen_size_.x,screen_size_.y, 16);
    ChangeWindowMode(true);
    // ウィンドウラベルセット
    SetWindowText("SampleAction");
    // DxLibの初期化が正常に終了しなかったらfalse
    if (DxLib_Init() == -1)
    {
        return false;
    }
    // シーンインスタンス初期はtitle画面
    scene_ = std::make_unique<Title>();
    // キーボード入力インスタンス
    controller_ = std::make_shared<KeyInput>();

    // コマンドセット(仮)
    controller_->SetCommand(COMMAND::START, KEY_INPUT_RETURN);
    controller_->SetCommand(COMMAND::RESET, KEY_INPUT_SPACE);
    controller_->SetCommand(COMMAND::RIGHT, KEY_INPUT_RIGHT);
    controller_->SetCommand(COMMAND::LEFT, KEY_INPUT_LEFT);
    controller_->SetCommand(COMMAND::UP, KEY_INPUT_UP);
    controller_->SetCommand(COMMAND::DOWN, KEY_INPUT_DOWN);
    controller_->SetCommand(COMMAND::EQUIPMENT_OPR, KEY_INPUT_E);
    controller_->SetCommand(COMMAND::ATTACK_PUNCH, KEY_INPUT_A);
    controller_->SetCommand(COMMAND::ATTACK_KICK, KEY_INPUT_S);


    return true;
}
