#pragma once
#include <string>
#include <memory>
#include "../Geometory.h"
#include "../Animation.h"
#include "../../.h/Gravity.h"
#include "../../.h/Direction.h"

struct Controller;

// �Q�[���œ����I�u�W�F�N�g�e�N���X
class Actor
{
public:
	Actor(std::string name);
	~Actor();
	// �X�V
	virtual void Update(const std::shared_ptr<Controller>& controller);
	// �L�����̓���
	virtual void Move(const std::shared_ptr<Controller>& controller = nullptr) = 0;
	// �������֘A
	virtual bool Init(void) = 0;
	// �`��
	virtual void Draw(void);

	// �A�j���[�V�����J�E���^�[��0�N��
	void ResetanimCnt(void)
	{
		this->animCnt_ = 0.0f;
	}

	// �Z�b�^�[
	// �|�W�V�����Z�b�g
	void SetPos(Vector2I pos)
	{
		this->pos_ = pos;
	}

	// �A�j���[�V�����J�E���g�̉��Z
	void AddanimCnt(float cnt)
	{
		this->animCnt_ += cnt;
	}
	// �A�j���[�V�����J�E���g�Z�b�g
	void SetanimCnt(float cnt)
	{
		this->animCnt_ = cnt;
	}
	// �A�j���[�V�����I���t���O�Z�b�g
	void SetisAnimEnd(bool end)
	{
		this->isAnimEnd_ = end;
	}
	// �W�����v�t���O�Z�b�g
	void SetisJump(bool jFlg)
	{
		this->isJump_ = jFlg;
	}
	


	// �Q�b�^�[
	// �|�W�V�����擾
	const Vector2I& GetPos(void)
	{
		return this->pos_;
	}
	// �A�j���[�V�����J�E���^�[�擾
	const float& GetanimCnt(void)
	{
		return this->animCnt_;
	}
	// ���݂̃A�j���[�V�����擾
	const Animation& GetCurrentAnim(void)
	{
		return *this->currentAnim_;
	}
	// ���݂̃A�j���[�V�������̎擾
	const std::string& GetCurrentAnimName(void)
	{
		return currentAnimName_;
	}
	// �W�����v���Ȃ̂��̔���t���O�擾
	const bool& IsJump(void)
	{
		return isJump_;
	}
private:

protected:
	// �A�j���[�V�����J�E���g
	float animCnt_;
	// �A�j���[�V�����I���t���O
	bool isAnimEnd_;
	// �����̖��O
	const std::string name_;
	// �������Ă���A�j���[�V������
	std::string currentAnimName_;
	// 1�t���[���O�̃A�j���[�V������
	std::string oldAnimName_;
	// �|�W�V����
	Vector2I pos_;
	// �I�u�W�F�N�g�̃T�C�Y
	Vector2I size_;
	// ����
	DIRECTION direction_;
	// ���]�t���O
	bool isFlipped_;
	// ���݂̃A�j���[�V����
	Animation* currentAnim_;
	// �d��
	Gravity gravity_;
	// �U�����Ă��邩�̔���t���O
	bool isAttack_;
	// �W�����v���Ă��邩�̔���t���O
	bool isJump_;
	// �W�����v��
	float jumpPower_;
	// �U���A�g�ׂ̈̃E�F�C�g�J�E���^�[
	// �U�����I���Ă���idle���[�V�����ɖ߂�̂ł͂Ȃ��A�������Ԃ������Ė߂��
	int attackWaitCnt_;
	// �W�����v�����x
	float j_first_power_;
};

