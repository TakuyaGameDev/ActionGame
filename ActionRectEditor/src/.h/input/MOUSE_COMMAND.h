#pragma once

// マウスコマンド一覧
enum class MOUSE_COMMAND
{
	// 左クリック
	CLICK_L,
	// 右クリック
	CLICK_R,
	MAX
};

// InputIDのbeginの定義
static MOUSE_COMMAND begin(MOUSE_COMMAND)
{
	return MOUSE_COMMAND::CLICK_L;
}
// InputIDのendの定義
static MOUSE_COMMAND end(MOUSE_COMMAND)
{
	return MOUSE_COMMAND::MAX;
}
// InputID++の定義
static MOUSE_COMMAND operator++(MOUSE_COMMAND& id)
{
	return (id = MOUSE_COMMAND(std::underlying_type<MOUSE_COMMAND>::type(id) + 1));
}
// 自分自身を返す関数
static MOUSE_COMMAND operator*(MOUSE_COMMAND id)
{
	return id;
}