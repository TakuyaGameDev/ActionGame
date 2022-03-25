#include "../../.h/Actor/Player.h"
#include "../../.h/Input/Controller.h"
#include "../../.h/AnimationCache.h"

Player::Player(Vector2I pos):
	Actor("Player")
{
	size_ = Vector2I(100, 74);
	// とりあえず右に設定
	direction_ = DIRECTION::RIGHT;
	// 初期化
	Init();
	// ポジションセット(足元)
	SetPos(Vector2I(pos.x + (size_.x/2),pos.y + size_.y));
}

Player::~Player()
{
}

void Player::Move(const std::shared_ptr<Controller>& controller)
{
	auto inputData = controller->GetInputCmd();

	// 武器の装備状態で0か1の文字列に変換
	auto getEquipmentStatus = [&](const bool& equipmentFlg) {
		return (equipmentFlg == false ? 0 : 1);
	};
	
	if (isAnimEnd_ && attackWaitCnt_ <= 0 && !isJump_)
	{
		currentAnimName_ = "idle"+std::to_string(getEquipmentStatus(isDrawingSword_));
	}
	else
	{
		if (currentAnimName_ == "run")
		{
			currentAnimName_ = "idle"+std::to_string(getEquipmentStatus(isDrawingSword_));
		}
	}

	// 走る速度
	int runSp = 0;

	// 攻撃していなければ移動
	if (!isAttack_ && !isJump_)
	{
		// 右に移動
		if (inputData[INT(COMMAND::RIGHT)][INT(TRG::NOW)])
		{
			isFlipped_ = INT(COMMAND::RIGHT);
			runSp = 2;
			currentAnimName_ = "run";
		}
		// 左に移動
		else if (inputData[INT(COMMAND::LEFT)][INT(TRG::NOW)])
		{
			isFlipped_ = INT(COMMAND::LEFT);
			runSp = -2;
			currentAnimName_ = "run";
		}
		if (inputData[INT(COMMAND::UP)][INT(TRG::NOW)] &&
			!inputData[INT(COMMAND::UP)][INT(TRG::OLD)])
		{
			isJump_ = true;
			j_first_power_ = 10.0f;
			currentAnimName_ = "jump";
		}
		// ポジション移動
		pos_.x += runSp;
		pos_.y -= jumpPower_;
		// 武器の操作
		if (inputData[INT(COMMAND::EQUIPMENT_OPR)][INT(TRG::NOW)] &&
			!inputData[INT(COMMAND::EQUIPMENT_OPR)][INT(TRG::OLD)])
		{
			// 武器を抜いていないと抜く
			if (!isDrawingSword_)
			{
				currentAnimName_ = "sword_drawing";
				isDrawingSword_ = true;
			}
			// 武器を抜いていると直す
			else
			{
				currentAnimName_ = "sword_putaway";
				isDrawingSword_ = false;
			}
		}
	}
	if (isJump_)
	{
		if (j_first_power_ <= 0.0f)
		{
			if (currentAnimName_ != "smrslt")
			{
				currentAnimName_ = "smrslt";
			}
		}
		else
		{
			j_first_power_ -= JUMP_POWER;
			pos_.y -= j_first_power_;
		}
	}
	else
	{
		// 攻撃コマンド押下(装備解除時はパンチ、装備時は剣)
		if (inputData[INT(COMMAND::ATTACK_PUNCH)][INT(TRG::NOW)] &&
			!inputData[INT(COMMAND::ATTACK_PUNCH)][INT(TRG::OLD)])
		{
			attackWaitCnt_ = 25;
			// 攻撃フラグをtrueに
			isAttack_ = true;
			if (isAnimEnd_)
			{
				attackCnt_[INT(ATTACK_VALUATION::PUNCH)]++;
			}
			if (attackCnt_[INT(ATTACK_VALUATION::PUNCH)] >= 3)
			{
				attackCnt_[INT(ATTACK_VALUATION::PUNCH)] = 0;
			}
			// 抜刀していない時
			if (!isDrawingSword_)
			{
				currentAnimName_ =
					"attack_punch" + std::to_string(attackCnt_[INT(ATTACK_VALUATION::PUNCH)] + 1);
			}
			// 抜刀時
			else
			{
				currentAnimName_ =
					"attack1-" + std::to_string(attackCnt_[INT(ATTACK_VALUATION::PUNCH)] + 1);
			}
		}
		// 攻撃コマンド押下(キック)
		else if (inputData[INT(COMMAND::ATTACK_KICK)][INT(TRG::NOW)] &&
			!inputData[INT(COMMAND::ATTACK_KICK)][INT(TRG::OLD)])
		{
			attackWaitCnt_ = 25;
			// 攻撃フラグをtrueに
			isAttack_ = true;
			if (isAnimEnd_)
			{
				attackCnt_[INT(ATTACK_VALUATION::KICK)]++;
			}
			if (attackCnt_[INT(ATTACK_VALUATION::KICK)] >= 2)
			{
				attackCnt_[INT(ATTACK_VALUATION::KICK)] = 0;
			}
			currentAnimName_ =
				"attack_kick" + std::to_string(attackCnt_[INT(ATTACK_VALUATION::KICK)] + 1);
		}
	}
	// 攻撃ウェイトカウントが0になったら各攻撃段階を0クリ
	if (attackWaitCnt_ <= 0)
	{
		for (auto& cnt : attackCnt_)
		{
			cnt = 0;
		}
	}
}

bool Player::Init(void)
{
	auto& animCache = lpAnimationCache.GetInstance();
	// プレイヤーアニメーションが登録されていなければ登録
	if (!animCache.IsExistActorAnim(name_))
	{
		// 装備無し待機モーション
		animCache.SetAnimation(name_, Animation("idle0", 4,0.06f, true));
		// 装備あり待機モーション
		animCache.SetAnimation(name_, Animation("idle1", 4,0.06f, true));
		// 走りモーション
		animCache.SetAnimation(name_, Animation("run", 6,0.06f, true));
		// ジャンプモーション
		animCache.SetAnimation(name_, Animation("jump", 4, 0.4f, false));
		// fallモーション(サマーソルト後のモーション(落下))
		animCache.SetAnimation(name_, Animation("fall", 2, 0.1f, false));
		// サマーソルト(ジャンプ後のモーション)
		animCache.SetAnimation(name_, Animation("smrslt", 4, 0.1f, false));
		// 武器を出すモーション
		animCache.SetAnimation(name_, Animation("sword_drawing", 4,0.06f, false));
		// 武器を直すモーション
		animCache.SetAnimation(name_, Animation("sword_putaway", 4, 0.06f, false));
		// 1段階目攻撃モーション(武器あり)
		animCache.SetAnimation(name_, Animation("attack1-1", 5, 0.1f, false));
		// 2段階目攻撃モーション(武器あり)
		animCache.SetAnimation(name_, Animation("attack1-2", 6, 0.1f, false));
		// 3段階目攻撃モーション(武器あり)
		animCache.SetAnimation(name_, Animation("attack1-3", 6, 0.1f, false));
		// 1段階目攻撃モーション(パンチ)
		animCache.SetAnimation(name_, Animation("attack_punch1", 4, 0.1f, false));
		// 2段階目攻撃モーション(パンチ)
		animCache.SetAnimation(name_, Animation("attack_punch2", 5, 0.1f, false));
		// 3段階目攻撃モーション(パンチ)
		animCache.SetAnimation(name_, Animation("attack_punch3", 4, 0.1f, false));
		// 1段階目攻撃モーション(キック)
		animCache.SetAnimation(name_, Animation("attack_kick1", 4, 0.1f, false));
		// 2段階目攻撃モーション(キック)
		animCache.SetAnimation(name_, Animation("attack_kick2", 4, 0.1f, false));
	}
	// 初期状態では剣を出していない状態にする
	isDrawingSword_ = false;
	j_first_power_ = 10.0f;
	// 各攻撃回数の整数の初期化
	for (auto& cnt : attackCnt_)
	{
		cnt = 0;
	}
	// 現在のアニメーション名のセット
	// デフォルトで武器無し待機モーションにしておく
	currentAnimName_ = "idle0";
	// 現在のアニメーションのセット
	currentAnim_ = animCache.GetAnimation(name_, currentAnimName_);
	return true;
}
