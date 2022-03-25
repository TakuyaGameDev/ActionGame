#pragma once
#include "TRG.h"
#include "KEY_COMMAND.h"
#include <array>
#include <map>

using KeyState = std::array<char, 256>;

using TrgBool = std::array<bool, static_cast<int>(TRG::MAX)>;
// �L�[�{�[�h�R�}���h
using KeyCommand = std::map<KEY_COMMAND, int>;

using KeyCommandMap = std::map<KEY_COMMAND, TrgBool>;

class KeyInput
{
public:
    KeyInput();
    ~KeyInput();
    // �X�V
    void Update(void);
    // ������
    bool Init(void);
    // �R�}���h�̃Z�b�g
    void SetKeyCommand(KEY_COMMAND cmd, int inputCmd);
    // ���ݓ��̓R�}���h�̎擾
    const KeyCommandMap& GetCommand(void)
    {
        return inputKeyCommand_;
    }
private:
    KeyState keyState_;
    KeyCommand keyCommandTbl_;
    // ���͂��Ă���R�}���h
    KeyCommandMap inputKeyCommand_;
};

