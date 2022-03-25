#pragma once
#include "TRG.h"
#include "KEY_COMMAND.h"
#include <array>
#include <map>

using KeyState = std::array<char, 256>;

using TrgBool = std::array<bool, static_cast<int>(TRG::MAX)>;
// キーボードコマンド
using KeyCommand = std::map<KEY_COMMAND, int>;

using KeyCommandMap = std::map<KEY_COMMAND, TrgBool>;

class KeyInput
{
public:
    KeyInput();
    ~KeyInput();
    // 更新
    void Update(void);
    // 初期化
    bool Init(void);
    // コマンドのセット
    void SetKeyCommand(KEY_COMMAND cmd, int inputCmd);
    // 現在入力コマンドの取得
    const KeyCommandMap& GetCommand(void)
    {
        return inputKeyCommand_;
    }
private:
    KeyState keyState_;
    KeyCommand keyCommandTbl_;
    // 入力しているコマンド
    KeyCommandMap inputKeyCommand_;
};

