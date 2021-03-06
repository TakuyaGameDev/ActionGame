#pragma once
#include "BaseScene.h"

class Title :
    public BaseScene
{
public:
    Title();
    ~Title();

	// 更新(引数は自分)
	Scene Update(Scene own, const std::shared_ptr<Controller>& controller);
	// 初期化
	bool Init(void);
	// 描画
	void Draw(void);
private:

};

