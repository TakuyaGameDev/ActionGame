#pragma once
#include <type_traits>

// �R�}���h���܂Ƃ߂�enum�N���X
enum class COMMAND
{
	// �E�{�^��
	RIGHT,
	// ���{�^��
	LEFT,
	// ��{�^��
	UP,
	// ���{�^��
	DOWN,
	// ����̑����A�����̃{�^��
	EQUIPMENT_OPR,
	// �U���{�^��(�p���`)
	ATTACK_PUNCH,
	// �U���{�^��(�L�b�N)
	ATTACK_KICK,
	// �X�^�[�g�{�^��
	START,
	// ���Z�b�g�{�^��
	RESET,
	MAX
};

// InputID��begin�̒�`
static COMMAND begin(COMMAND)
{
	return COMMAND::RIGHT;
}
// InputID��end�̒�`
static COMMAND end(COMMAND)
{
	return COMMAND::MAX;
}
// InputID++�̒�`
static COMMAND operator++(COMMAND& id)
{
	return (id = COMMAND(std::underlying_type<COMMAND>::type(id) + 1));
}
// �������g��Ԃ��֐�
static COMMAND operator*(COMMAND id)
{
	return id;
}