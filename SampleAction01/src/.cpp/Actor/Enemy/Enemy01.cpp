#include "../../../.h/Actor/Enemy/Enemy01.h"
#include "../../../.h/AnimationCache.h"

Enemy01::Enemy01(Vector2I pos):
	Enemy("Enemy/Enemy01")
{
	size_ = Vector2I(225, 72);
	// とりあえず右に設定
	direction_ = DIRECTION::LEFT;
	// 初期化
	Init();
	// ポジションセット(足元)
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
	// Enemy01アニメーションが登録されていなければ登録
	if (!animCache.IsExistActorAnim(name_))
	{
		// 待機モーション
		animCache.SetAnimation(name_, Animation("idle", 4, 0.06f, true));
		// 走りモーション
		animCache.SetAnimation(name_, Animation("run", 8, 0.06f, true));
		// 攻撃モーション
		animCache.SetAnimation(name_, Animation("attack", 8, 0.06f, true));
	}
	// 現在のアニメーション名のセット
	// デフォルトで武器無し待機モーションにしておく
	currentAnimName_ = "idle";
	// 現在のアニメーションのセット
	currentAnim_ = animCache.GetAnimation(name_, currentAnimName_);
	return true;
}
