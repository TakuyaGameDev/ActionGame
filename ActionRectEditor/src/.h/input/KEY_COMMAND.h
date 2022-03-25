#pragma once
#include <type_traits>

// �L�[�{�[�h�R�}���h�ꗗ
enum class KEY_COMMAND
{
	// ����
	DECIDE,
	// ���Z�b�g
	RESET,
	// �ۑ�
	SAVE,
	MAX
};

// InputID��begin�̒�`
static KEY_COMMAND begin(KEY_COMMAND)
{
	return KEY_COMMAND::DECIDE;
}
// InputID��end�̒�`
static KEY_COMMAND end(KEY_COMMAND)
{
	return KEY_COMMAND::MAX;
}
// InputID++�̒�`
static KEY_COMMAND operator++(KEY_COMMAND& id)
{
	return (id = KEY_COMMAND(std::underlying_type<KEY_COMMAND>::type(id) + 1));
}
// �������g��Ԃ��֐�
static KEY_COMMAND operator*(KEY_COMMAND id)
{
	return id;
}