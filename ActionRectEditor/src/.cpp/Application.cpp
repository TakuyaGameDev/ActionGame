#include <DxLib.h>
#include "../.h/Application.h"
#include "../.h/input/KeyInput.h"

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
    // �L�[�{�[�h���͑��u�擾
    key_ = std::make_shared<KeyInput>();
	return true;
}
