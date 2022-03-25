#pragma once
#include <array>
#include "Actor.h"

#define JUMP_MAX 5.0f
#define JUMP_POWER 0.4f

// 攻撃の種類
enum class ATTACK_VALUATION
{
    // パンチ
    PUNCH,
    // キック
    KICK,
    // 剣
    SWORD,
    MAX
};

using AttackCntWithValuation = std::array<int, static_cast<int>(ATTACK_VALUATION::MAX)>;

class Player :
    public Actor
{
public:
    Player(Vector2I pos);
    ~Player();
    // 動き
    void Move(const std::shared_ptr<Controller>& controller);
    // 初期化
    bool Init(void);

private:
    // 剣を出しているかのフラグ
    bool isDrawingSword_;
    // 各攻撃段階カウンター
    AttackCntWithValuation attackCnt_;

};

