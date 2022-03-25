#pragma once
#include "Enemy.h"

// 仮の敵クラス
class Enemy01 :
    public Enemy
{
public:
    Enemy01(Vector2I pos);
    ~Enemy01();

    void Move(const std::shared_ptr<Controller>& controller);
    bool Init(void);
private:
};

