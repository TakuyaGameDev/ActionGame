#pragma once
#include <functional>
#include <map>
#include <array>
#include <string>
#include "BaseScene.h"

// 入力ターン
enum class PHASE_TYPE
{
    ACTOR,
    ANIMATION,
    LOOP,
    MAX
};

// InputIDのbeginの定義
static PHASE_TYPE begin(PHASE_TYPE)
{
    return PHASE_TYPE::ACTOR;
}
// InputIDのendの定義
static PHASE_TYPE end(PHASE_TYPE)
{
    return PHASE_TYPE::MAX;
}
// InputID++の定義
static PHASE_TYPE operator++(PHASE_TYPE& id)
{
    return (id = PHASE_TYPE(std::underlying_type<PHASE_TYPE>::type(id) + 1));
}
// 自分自身を返す関数
static PHASE_TYPE operator*(PHASE_TYPE id)
{
    return id;
}

using InputBoxPosition = std::array<BoxRect, static_cast<int>(PHASE_TYPE::MAX)>;

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
    // 現在の入力ターン
    PHASE_TYPE nowPhase_;
    Vector2I mouse_;
    // 各文字のテキストボックスの情報(position,size)
    InputBoxPosition textBox_;
    // 画像プレビューボックス
    BoxRect imagePreviewBox_;
    // アニメーション名一覧表示ボックス
    BoxRect animationListBox_;
    // 画像サイズ
    Vector2I imgSize_;
    // リセットボタン
    BoxRect resetBtn_;
    // リセットボタン押下可能なフラグ
    bool isAbleReset_;
    // ナビゲーション用の文字列
    std::array<std::string, static_cast<int>(PHASE_TYPE::MAX)> navStr_;
    std::map<PHASE_TYPE, std::function<void(char*)>> functionMap_;
};

