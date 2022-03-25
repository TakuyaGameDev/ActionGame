#pragma once
#include <type_traits>

// キーボードコマンド一覧
enum class KEY_COMMAND
{
	// 決定
	DECIDE,
	// リセット
	RESET,
	// 保存
	SAVE,
	MAX
};

// InputIDのbeginの定義
static KEY_COMMAND begin(KEY_COMMAND)
{
	return KEY_COMMAND::DECIDE;
}
// InputIDのendの定義
static KEY_COMMAND end(KEY_COMMAND)
{
	return KEY_COMMAND::MAX;
}
// InputID++の定義
static KEY_COMMAND operator++(KEY_COMMAND& id)
{
	return (id = KEY_COMMAND(std::underlying_type<KEY_COMMAND>::type(id) + 1));
}
// 自分自身を返す関数
static KEY_COMMAND operator*(KEY_COMMAND id)
{
	return id;
}