#pragma once
#include "Controller.h"

// キー情報
using KeyArray = std::array<char, 256>;

class KeyInput :
    public Controller
{
public:
    KeyInput();
    ~KeyInput();
    // 更新
    void Update(void);
    // 初期化
    bool Init(void);
private:
    // キー情報
    KeyArray keyData_;
};

