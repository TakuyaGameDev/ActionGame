#pragma once
#include "../Actor.h"

// 敵クラス
class Enemy :
    public Actor
{
public:
    Enemy(std::string name);
    ~Enemy();
    // キャラの動き
    virtual void Move(const std::shared_ptr<Controller>& controller) = 0;
    // 初期化関連
    virtual bool Init(void) = 0;

private:

protected:

};

