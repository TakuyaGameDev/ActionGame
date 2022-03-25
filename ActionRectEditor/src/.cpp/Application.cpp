#include <DxLib.h>
#include "../.h/Application.h"
#include "../.h/input/KeyInput.h"
#include "../.h/input/MouseInput.h"

#include "../.h/scene/StartUp.h"

void Application::Run(void)
{
    // DxLib�̏�����������ɏI���Ȃ�������
    // �Q�[�����[�v�ɂ͓���Ȃ�
    if (!SystemInit())
    {
        return;
    }
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        // �L�[�{�[�h�������X�V
        key_->Update();
        // �}�E�X���̍X�V
        mouse_->Update();
        // �V�[���X�V
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
    // �e��ʃT�C�Y�̐ݒ�
    SetScreenSize({ SCREEN_X,SCREEN_Y }, { IMAGE_SCREEN_X,IMAGE_SCREEN_Y });
    // �ݒ肵����ʃT�C�Y�ŉ�ʕ\��
    SetGraphMode(scrSize_.screen_.x, scrSize_.screen_.y, 16);
    ChangeWindowMode(true);
    // �E�B���h�E���x���Z�b�g
    SetWindowText("ActionRectEditor");
    // DxLib�̏�����������ɏI�����Ȃ�������false
    if (DxLib_Init() == -1)
    {
        return false;
    }
    // �L�[�{�[�h���͑��u����
    key_ = std::make_shared<KeyInput>();
    // ����{�^��
    key_->SetKeyCommand(KEY_COMMAND::DECIDE, KEY_INPUT_RETURN);
    // �Z�[�u�{�^��
    key_->SetKeyCommand(KEY_COMMAND::SAVE, KEY_INPUT_S);
    // undo�{�^��
    key_->SetKeyCommand(KEY_COMMAND::UNDO, KEY_INPUT_Z);
    // �R���g���[���L�[
    key_->SetKeyCommand(KEY_COMMAND::CTRL, KEY_INPUT_LCONTROL);
    // �}�E�X���͑��u����
    mouse_ = std::make_shared<MouseInput>();

    // �����V�[���ŃC���X�^���X
    scene_ = std::make_unique<StartUp>();
	return true;
}
