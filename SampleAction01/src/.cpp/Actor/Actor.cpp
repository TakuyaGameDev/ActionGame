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
	// 重力をかける
	gravity_.Update(*this);
	// 動き
	Move(controller);
	// 現在のアニメーションの変更
	// 現在進行中のアニメーション名と1フレーム前のアニメーション名が違ったら変更
	if (currentAnimName_ != oldAnimName_)
	{
		// アニメーションカウントを0にする
		ResetanimCnt();
		// アニメーション終了フラグをfalseに
		isAnimEnd_ = false;
		// 現在のアニメーションを更新
		currentAnim_ = lpAnimationCache.GetAnimation(name_, currentAnimName_);
	}
	// アニメーション実行
	PlayAnimation()(*this);
	// 攻撃モーションが終了していたら移動を許可する
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

