#pragma once
#include "Controller.h"

// �L�[���
using KeyArray = std::array<char, 256>;

class KeyInput :
    public Controller
{
public:
    KeyInput();
    ~KeyInput();
    // �X�V
    void Update(void);
    // ������
    bool Init(void);
private:
    // �L�[���
    KeyArray keyData_;
};

