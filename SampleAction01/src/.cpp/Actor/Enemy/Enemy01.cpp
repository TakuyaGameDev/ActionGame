#include "../../../.h/Actor/Enemy/Enemy01.h"
#include "../../../.h/AnimationCache.h"

Enemy01::Enemy01(Vector2I pos):
	Enemy("Enemy/Enemy01")
{
	size_ = Vector2I(225, 72);
	// �Ƃ肠�����E�ɐݒ�
	direction_ = DIRECTION::LEFT;
	// ������
	Init();
	// �|�W�V�����Z�b�g(����)
	SetPos(Vector2I(pos.x + (size_.x / 2), pos.y + size_.y));
}

Enemy01::~Enemy01()
{
}

void Enemy01::Move(const std::shared_ptr<Controller>& controller)
{
	isFlipped_ = (bool)direction_;
}

bool Enemy01::Init(void)
{
	auto& animCache = lpAnimationCache.GetInstance();
	// Enemy01�A�j���[�V�������o�^����Ă��Ȃ���Γo�^
	if (!animCache.IsExistActorAnim(name_))
	{
		// �ҋ@���[�V����
		animCache.SetAnimation(name_, Animation("idle", 4, 0.06f, true));
		// ���胂�[�V����
		animCache.SetAnimation(name_, Animation("run", 8, 0.06f, true));
		// �U�����[�V����
		animCache.SetAnimation(name_, Animation("attack", 8, 0.06f, true));
	}
	// ���݂̃A�j���[�V�������̃Z�b�g
	// �f�t�H���g�ŕ��햳���ҋ@���[�V�����ɂ��Ă���
	currentAnimName_ = "idle";
	// ���݂̃A�j���[�V�����̃Z�b�g
	currentAnim_ = animCache.GetAnimation(name_, currentAnimName_);
	return true;
}
