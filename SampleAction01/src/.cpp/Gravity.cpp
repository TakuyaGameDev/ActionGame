#include "../.h/Gravity.h"
#include "../.h/Actor/Actor.h"
#include "../.h/Map.h"

Gravity::Gravity()
{
	g_power_ = 0.0f;
}

Gravity::~Gravity()
{
}

void Gravity::Update(Actor& actor)
{
	g_power_ += 0.155f;
	if (actor.GetCurrentAnimName() == "jump")
	{
		g_power_ = 0.0f;
	}
	// �I�u�W�F�N�g�̌��݂̃|�W�V����
	auto tmpPos = actor.GetPos();
	// �I�u�W�F�N�g�̃|�W�V����y����������ɂ�����d�͂�������
	if (tmpPos.y + g_power_ < lpMap.GetPos(MAP_OBJECT_TYPE::FLOOR).y)
	{
		actor.SetPos(Vector2I(tmpPos.x, tmpPos.y + g_power_));
	}
	// ���Ɠ����|�W�V�����ɂ�����d�͉����x�����Z�b�g
	else
	{
		g_power_ = 0.0f;
		// �W�����v�t���O��܂�
		actor.SetisJump(false);
	}
}