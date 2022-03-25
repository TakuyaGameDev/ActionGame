#pragma once

// �}�E�X�R�}���h�ꗗ
enum class MOUSE_COMMAND
{
	// ���N���b�N
	CLICK_L,
	// �E�N���b�N
	CLICK_R,
	MAX
};

// InputID��begin�̒�`
static MOUSE_COMMAND begin(MOUSE_COMMAND)
{
	return MOUSE_COMMAND::CLICK_L;
}
// InputID��end�̒�`
static MOUSE_COMMAND end(MOUSE_COMMAND)
{
	return MOUSE_COMMAND::MAX;
}
// InputID++�̒�`
static MOUSE_COMMAND operator++(MOUSE_COMMAND& id)
{
	return (id = MOUSE_COMMAND(std::underlying_type<MOUSE_COMMAND>::type(id) + 1));
}
// �������g��Ԃ��֐�
static MOUSE_COMMAND operator*(MOUSE_COMMAND id)
{
	return id;
}