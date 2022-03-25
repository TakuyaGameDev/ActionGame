#pragma once
#include "Command.h"
#include <array>
#include <map>

#define INT(X) static_cast<int>(X)

// �R�}���h�̃g���K�[����
enum class TRG
{
	NOW,
	OLD,
	MAX
};

// �g���K�[�z��
using TrgArray = std::array<bool, static_cast<int>(TRG::MAX)>;

// �R�}���hmap
using CommandMap = std::map<COMMAND, int>;
// ���͂��Ă���R�}���h���
using InputCommand = std::array<TrgArray,static_cast<int>(COMMAND::MAX)>;

struct Controller
{
	void operator()()
	{
		Update();
	}
	// �R�}���h���͂̍X�V
	virtual void Update(void) = 0;

	// �R�}���h�̃Z�b�g
	void SetCommand(COMMAND cmd, int input);
	// ���̓R�}���h�̎擾
	const InputCommand& GetInputCmd(void)
	{
		return inputCmd_;
	}
private:

protected:
	// �e�R�}���h�Z�b�g�p
	CommandMap command_;

	// ���͂��Ă���R�}���h���
	InputCommand inputCmd_;
};

