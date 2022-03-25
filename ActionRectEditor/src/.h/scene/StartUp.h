#pragma once
#include "BaseScene.h"
#include "../../.h/Geometory.h"

// �e�����ݒ������V�[��
class StartUp :
    public BaseScene
{
public:
    StartUp();
    ~StartUp();
    // �X�V
    UniqueScene Update(UniqueScene own, const std::shared_ptr<KeyInput>& key, const std::shared_ptr<MouseInput>& mouse);
    // ������
    bool Init(void);
    // �`��
    void Draw(void);
private:
    Vector2I mouse_;
};

