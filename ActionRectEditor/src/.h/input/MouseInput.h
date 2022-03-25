#pragma once
#include <array>
#include <map>
#include "../../.h/Geometory.h"
#include "TRG.h"
#include "MOUSE_COMMAND.h"

using TrgArray = std::array<bool, static_cast<int>(TRG::MAX)>;
using ClickArray = std::map<MOUSE_COMMAND,TrgArray>;

// �}�E�X�R���g���[������
class MouseInput
{
public:
	MouseInput();
	~MouseInput();
	// �X�V
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
	// �}�E�X�|�C���^�̃|�W�V����
	Vector2I pos_;
	// �N���b�N�̃f�[�^
	ClickArray clickData_;
};

