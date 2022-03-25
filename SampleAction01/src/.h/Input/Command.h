#pragma once
#include <type_traits>

// コマンドをまとめたenumクラス
enum class COMMAND
{
	// 右ボタン
	RIGHT,
	// 左ボタン
	LEFT,
	// 上ボタン
	UP,
	// 下ボタン
	DOWN,
	// 武器の装備、解除のボタン
	EQUIPMENT_OPR,
	// 攻撃ボタン(パンチ)
	ATTACK_PUNCH,
	// 攻撃ボタン(キック)
	ATTACK_KICK,
	// スタートボタン
	START,
	// リセットボタン
	RESET,
	MAX
};

// InputIDのbeginの定義
static COMMAND begin(COMMAND)
{
	return COMMAND::RIGHT;
}
// InputIDのendの定義
static COMMAND end(COMMAND)
{
	return COMMAND::MAX;
}
// InputID++の定義
static COMMAND operator++(COMMAND& id)
{
	return (id = COMMAND(std::underlying_type<COMMAND>::type(id) + 1));
}
// 自分自身を返す関数
static COMMAND operator*(COMMAND id)
{
	return id;
}