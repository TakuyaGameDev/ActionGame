#pragma once
#include "BaseScene.h"
#include "../../.h/Geometory.h"

// 各初期設定をするシーン
class StartUp :
    public BaseScene
{
public:
    StartUp();
    ~StartUp();
    // 更新
    UniqueScene Update(UniqueScene own, const std::shared_ptr<KeyInput>& key, const std::shared_ptr<MouseInput>& mouse);
    // 初期化
    bool Init(void);
    // 描画
    void Draw(void);
private:
    Vector2I mouse_;
};

