#include <DxLib.h>
#include "../../.h/input/MouseInput.h"

MouseInput::MouseInput()
{
	// クリックのフラグを両方初期化
	clickData_[MOUSE_COMMAND::CLICK_L] = { false,false };
	clickData_[MOUSE_COMMAND::CLICK_R] = { false,false };
}

MouseInput::~MouseInput()
{
}

void MouseInput::Update(void)
{
	// マウスポインタの更新
	GetMousePoint(&pos_.x, &pos_.y);

	// マウスの入力(右クリック、左クリック)
	// 1フレーム前のフラグに代入
	// これでトリガー処理を可能にしている
	for (auto m_cmd : MOUSE_COMMAND())
	{
		clickData_[m_cmd][static_cast<int>(TRG::OLD)] = clickData_[m_cmd][static_cast<int>(TRG::NOW)];
	}
	// 左クリック時
	if (GetMouseInput() & MOUSE_INPUT_LEFT)
	{
		clickData_[MOUSE_COMMAND::CLICK_L][static_cast<int>(TRG::NOW)] = true;
	}
	// 左クリックしていない時
	else
	{
		clickData_[MOUSE_COMMAND::CLICK_L][static_cast<int>(TRG::NOW)] = false;
	}
	// 右クリック時
	if (GetMouseInput() & MOUSE_INPUT_RIGHT)
	{
		clickData_[MOUSE_COMMAND::CLICK_R][static_cast<int>(TRG::NOW)] = true;
	}
	// 右クリックしていない時
	else
	{
		clickData_[MOUSE_COMMAND::CLICK_R][static_cast<int>(TRG::NOW)] = false;
	}
}
