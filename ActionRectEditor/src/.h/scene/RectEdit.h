#pragma once
#include "BaseScene.h"

class RectEdit :
    public BaseScene
{
public:
    RectEdit();
    ~RectEdit();

    // 更新
    UniqueScene Update(UniqueScene own, const std::shared_ptr<KeyInput>& key, const std::shared_ptr<MouseInput>& mouse);
    // 初期化
    bool Init(void);
    // 描画
    void Draw(void);

private:
    // 編集スクリーンボックス
    BoxRect editScreen_;
    // 基本情報表示領域
    BoxRect baseInfoBox_;
    // 各テキストボックス
    BoxRect objectTextBox_;
    BoxRect animationTextBox_;
    BoxRect pathNameTextBox_;
    BoxRect loopFlagTextBox_;
    BoxRect maxFrameTextBox_;
    // 編集対象の画像ポジション
    Vector2I imagePos_;
};

