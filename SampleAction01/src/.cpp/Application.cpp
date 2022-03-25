#include <DxLib.h>
#include "../.h/Application.h"
#include "../.h/Scene/Title.h"
#include "../.h/Input/KeyInput.h"

Application::~Application()
{
}

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
        // �R���g���[���[�̍X�V
        (*controller_)();
        // �V�[���̍X�V
        scene_ = scene_->Update(move(scene_),controller_);
    }
}

void Application::Exit(void)
{
    // DxLib�̏I��
    DxLib_End();
}

bool Application::SystemInit(void)
{
    // �e��ʃT�C�Y�̐ݒ�
    SetScreenSize({ SCREEN_X,SCREEN_Y });
    // �ݒ肵����ʃT�C�Y�ŉ�ʕ\��
    SetGraphMode(screen_size_.x,screen_size_.y, 16);
    ChangeWindowMode(true);
    // �E�B���h�E���x���Z�b�g
    SetWindowText("SampleAction");
    // DxLib�̏�����������ɏI�����Ȃ�������false
    if (DxLib_Init() == -1)
    {
        return false;
    }
    // �V�[���C���X�^���X������title���
    scene_ = std::make_unique<Title>();
    // �L�[�{�[�h���̓C���X�^���X
    controller_ = std::make_shared<KeyInput>();

    // �R�}���h�Z�b�g(��)
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
