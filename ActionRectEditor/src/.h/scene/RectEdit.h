#pragma once
#include "BaseScene.h"

class RectEdit :
    public BaseScene
{
public:
    RectEdit();
    ~RectEdit();

    // �X�V
    UniqueScene Update(UniqueScene own, const std::shared_ptr<KeyInput>& key, const std::shared_ptr<MouseInput>& mouse);
    // ������
    bool Init(void);
    // �`��
    void Draw(void);

private:
    // �ҏW�X�N���[���{�b�N�X
    BoxRect editScreen_;
    // ��{���\���̈�
    BoxRect baseInfoBox_;
    // �e�e�L�X�g�{�b�N�X
    BoxRect objectTextBox_;
    BoxRect animationTextBox_;
    BoxRect pathNameTextBox_;
    BoxRect loopFlagTextBox_;
    BoxRect maxFrameTextBox_;
    // �ҏW�Ώۂ̉摜�|�W�V����
    Vector2I imagePos_;
};

