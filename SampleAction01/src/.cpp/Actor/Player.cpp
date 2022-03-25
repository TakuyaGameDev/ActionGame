#include "../../.h/Actor/Player.h"
#include "../../.h/Input/Controller.h"
#include "../../.h/AnimationCache.h"

Player::Player(Vector2I pos):
	Actor("Player")
{
	size_ = Vector2I(100, 74);
	// �Ƃ肠�����E�ɐݒ�
	direction_ = DIRECTION::RIGHT;
	// ������
	Init();
	// �|�W�V�����Z�b�g(����)
	SetPos(Vector2I(pos.x + (size_.x/2),pos.y + size_.y));
}

Player::~Player()
{
}

void Player::Move(const std::shared_ptr<Controller>& controller)
{
	auto inputData = controller->GetInputCmd();

	// ����̑�����Ԃ�0��1�̕�����ɕϊ�
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

	// ���鑬�x
	int runSp = 0;

	// �U�����Ă��Ȃ���Έړ�
	if (!isAttack_ && !isJump_)
	{
		// �E�Ɉړ�
		if (inputData[INT(COMMAND::RIGHT)][INT(TRG::NOW)])
		{
			isFlipped_ = INT(COMMAND::RIGHT);
			runSp = 2;
			currentAnimName_ = "run";
		}
		// ���Ɉړ�
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
		// �|�W�V�����ړ�
		pos_.x += runSp;
		pos_.y -= jumpPower_;
		// ����̑���
		if (inputData[INT(COMMAND::EQUIPMENT_OPR)][INT(TRG::NOW)] &&
			!inputData[INT(COMMAND::EQUIPMENT_OPR)][INT(TRG::OLD)])
		{
			// ����𔲂��Ă��Ȃ��Ɣ���
			if (!isDrawingSword_)
			{
				currentAnimName_ = "sword_drawing";
				isDrawingSword_ = true;
			}
			// ����𔲂��Ă���ƒ���
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
		// �U���R�}���h����(�����������̓p���`�A�������͌�)
		if (inputData[INT(COMMAND::ATTACK_PUNCH)][INT(TRG::NOW)] &&
			!inputData[INT(COMMAND::ATTACK_PUNCH)][INT(TRG::OLD)])
		{
			attackWaitCnt_ = 25;
			// �U���t���O��true��
			isAttack_ = true;
			if (isAnimEnd_)
			{
				attackCnt_[INT(ATTACK_VALUATION::PUNCH)]++;
			}
			if (attackCnt_[INT(ATTACK_VALUATION::PUNCH)] >= 3)
			{
				attackCnt_[INT(ATTACK_VALUATION::PUNCH)] = 0;
			}
			// �������Ă��Ȃ���
			if (!isDrawingSword_)
			{
				currentAnimName_ =
					"attack_punch" + std::to_string(attackCnt_[INT(ATTACK_VALUATION::PUNCH)] + 1);
			}
			// ������
			else
			{
				currentAnimName_ =
					"attack1-" + std::to_string(attackCnt_[INT(ATTACK_VALUATION::PUNCH)] + 1);
			}
		}
		// �U���R�}���h����(�L�b�N)
		else if (inputData[INT(COMMAND::ATTACK_KICK)][INT(TRG::NOW)] &&
			!inputData[INT(COMMAND::ATTACK_KICK)][INT(TRG::OLD)])
		{
			attackWaitCnt_ = 25;
			// �U���t���O��true��
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
	// �U���E�F�C�g�J�E���g��0�ɂȂ�����e�U���i�K��0�N��
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
	// �v���C���[�A�j���[�V�������o�^����Ă��Ȃ���Γo�^
	if (!animCache.IsExistActorAnim(name_))
	{
		// ���������ҋ@���[�V����
		animCache.SetAnimation(name_, Animation("idle0", 4,0.06f, true));
		// ��������ҋ@���[�V����
		animCache.SetAnimation(name_, Animation("idle1", 4,0.06f, true));
		// ���胂�[�V����
		animCache.SetAnimation(name_, Animation("run", 6,0.06f, true));
		// �W�����v���[�V����
		animCache.SetAnimation(name_, Animation("jump", 4, 0.4f, false));
		// fall���[�V����(�T�}�[�\���g��̃��[�V����(����))
		animCache.SetAnimation(name_, Animation("fall", 2, 0.1f, false));
		// �T�}�[�\���g(�W�����v��̃��[�V����)
		animCache.SetAnimation(name_, Animation("smrslt", 4, 0.1f, false));
		// ������o�����[�V����
		animCache.SetAnimation(name_, Animation("sword_drawing", 4,0.06f, false));
		// ����𒼂����[�V����
		animCache.SetAnimation(name_, Animation("sword_putaway", 4, 0.06f, false));
		// 1�i�K�ڍU�����[�V����(���킠��)
		animCache.SetAnimation(name_, Animation("attack1-1", 5, 0.1f, false));
		// 2�i�K�ڍU�����[�V����(���킠��)
		animCache.SetAnimation(name_, Animation("attack1-2", 6, 0.1f, false));
		// 3�i�K�ڍU�����[�V����(���킠��)
		animCache.SetAnimation(name_, Animation("attack1-3", 6, 0.1f, false));
		// 1�i�K�ڍU�����[�V����(�p���`)
		animCache.SetAnimation(name_, Animation("attack_punch1", 4, 0.1f, false));
		// 2�i�K�ڍU�����[�V����(�p���`)
		animCache.SetAnimation(name_, Animation("attack_punch2", 5, 0.1f, false));
		// 3�i�K�ڍU�����[�V����(�p���`)
		animCache.SetAnimation(name_, Animation("attack_punch3", 4, 0.1f, false));
		// 1�i�K�ڍU�����[�V����(�L�b�N)
		animCache.SetAnimation(name_, Animation("attack_kick1", 4, 0.1f, false));
		// 2�i�K�ڍU�����[�V����(�L�b�N)
		animCache.SetAnimation(name_, Animation("attack_kick2", 4, 0.1f, false));
	}
	// ������Ԃł͌����o���Ă��Ȃ���Ԃɂ���
	isDrawingSword_ = false;
	j_first_power_ = 10.0f;
	// �e�U���񐔂̐����̏�����
	for (auto& cnt : attackCnt_)
	{
		cnt = 0;
	}
	// ���݂̃A�j���[�V�������̃Z�b�g
	// �f�t�H���g�ŕ��햳���ҋ@���[�V�����ɂ��Ă���
	currentAnimName_ = "idle0";
	// ���݂̃A�j���[�V�����̃Z�b�g
	currentAnim_ = animCache.GetAnimation(name_, currentAnimName_);
	return true;
}
