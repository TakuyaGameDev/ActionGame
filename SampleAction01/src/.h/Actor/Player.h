#pragma once
#include <array>
#include "Actor.h"

#define JUMP_MAX 5.0f
#define JUMP_POWER 0.4f

// �U���̎��
enum class ATTACK_VALUATION
{
    // �p���`
    PUNCH,
    // �L�b�N
    KICK,
    // ��
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
    // ����
    void Move(const std::shared_ptr<Controller>& controller);
    // ������
    bool Init(void);

private:
    // �����o���Ă��邩�̃t���O
    bool isDrawingSword_;
    // �e�U���i�K�J�E���^�[
    AttackCntWithValuation attackCnt_;

};

