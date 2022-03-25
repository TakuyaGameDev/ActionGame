#pragma once
#include <array>
#include <map>
#include "../../.h/Geometory.h"
#include "TRG.h"
#include "MOUSE_COMMAND.h"

using TrgArray = std::array<bool, static_cast<int>(TRG::MAX)>;
using ClickArray = std::map<MOUSE_COMMAND,TrgArray>;

// マウスコントロール処理
class MouseInput
{
public:
	MouseInput();
	~MouseInput();
	// 更新
	void Update(void);

	const Vector2I& GetPos(void) const
	{
		return pos_;
	}

	const TrgArray& GetClick(MOUSE_COMMAND m_cmd)
	{
		return clickData_[m_cmd];
	}

private:
	// マウスポインタのポジション
	Vector2I pos_;
	// クリックのデータ
	ClickArray clickData_;
};

