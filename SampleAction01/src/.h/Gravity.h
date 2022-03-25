#pragma once

class Actor;

// 重力クラス
// シングルトンインスタンス(動的)
class Gravity
{
public:
	Gravity();
	~Gravity();
	// 重力の更新、オブジェクトに重力をかける
	void Update(Actor& actor);

private:
	// 重力加速度
	float g_power_;
};

