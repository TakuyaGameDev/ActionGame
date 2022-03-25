#include <DxLib.h>
#include "../../.h/Actor/Actor.h"
#include "../../.h/PlayAnimation.h"
#include "../../.h/SpriteCache.h"
#include "../../.h/AnimationCache.h"

Actor::Actor(std::string name):name_(name)
{
	animCnt_ = 0.0f;
	isAnimEnd_ = false;
	isFlipped_ = false;
	isAttack_ = false;
	isJump_ = false;
	attackWaitCnt_ = 0;
	jumpPower_ = 0.0f;
}

Actor::~Actor()
{
}

void Actor::Update(const std::shared_ptr<Controller>& controller)
{
	oldAnimName_ = currentAnimName_;
	// �d�͂�������
	gravity_.Update(*this);
	// ����
	Move(controller);
	// ���݂̃A�j���[�V�����̕ύX
	// ���ݐi�s���̃A�j���[�V��������1�t���[���O�̃A�j���[�V���������������ύX
	if (currentAnimName_ != oldAnimName_)
	{
		// �A�j���[�V�����J�E���g��0�ɂ���
		ResetanimCnt();
		// �A�j���[�V�����I���t���O��false��
		isAnimEnd_ = false;
		// ���݂̃A�j���[�V�������X�V
		currentAnim_ = lpAnimationCache.GetAnimation(name_, currentAnimName_);
	}
	// �A�j���[�V�������s
	PlayAnimation()(*this);
	// �U�����[�V�������I�����Ă�����ړ���������
	if (isAnimEnd_ && isAttack_)
	{
		attackWaitCnt_--;
	}
	if (attackWaitCnt_ <= 0)
	{
		isAttack_ = false;
	}
}

void Actor::Draw(void)
{
	DrawFormatString(0, 0, 0xffffff, "currentAnimation:%s",currentAnimName_.c_str());
	DrawRotaGraph(pos_.x, pos_.y-(size_.y/2),1.0,0.0,
		lpSprite.GetHandle("Actors/" + name_ + "/" + currentAnim_->GetName())[animCnt_], true,isFlipped_,false);
	DrawCircle(pos_.x, pos_.y, 3, 0xff0000, true);
}

