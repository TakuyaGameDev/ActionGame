#pragma once
#include "Command.h"
#include <array>
#include <map>

#define INT(X) static_cast<int>(X)

// コマンドのトリガー処理
enum class TRG
{
	NOW,
	OLD,
	MAX
};

// トリガー配列
using TrgArray = std::array<bool, static_cast<int>(TRG::MAX)>;

// コマンドmap
using CommandMap = std::map<COMMAND, int>;
// 入力しているコマンド情報
using InputCommand = std::array<TrgArray,static_cast<int>(COMMAND::MAX)>;

struct Controller
{
	void operator()()
	{
		Update();
	}
	// コマンド入力の更新
	virtual void Update(void) = 0;

	// コマンドのセット
	void SetCommand(COMMAND cmd, int input);
	// 入力コマンドの取得
	const InputCommand& GetInputCmd(void)
	{
		return inputCmd_;
	}
private:

protected:
	// 各コマンドセット用
	CommandMap command_;

	// 入力しているコマンド情報
	InputCommand inputCmd_;
};

