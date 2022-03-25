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
	// オブジェクトの現在のポジション
	auto tmpPos = actor.GetPos();
	// オブジェクトのポジションyが床よりも上にいたら重力をかける
	if (tmpPos.y + g_power_ < lpMap.GetPos(MAP_OBJECT_TYPE::FLOOR).y)
	{
		actor.SetPos(Vector2I(tmpPos.x, tmpPos.y + g_power_));
	}
	// 床と同じポジションにいたら重力加速度をリセット
	else
	{
		g_power_ = 0.0f;
		// ジャンプフラグを折る
		actor.SetisJump(false);
	}
}