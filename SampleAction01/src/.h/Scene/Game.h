#pragma once
#include <memory>
#include <vector>
#include "BaseScene.h"

class Actor;

using SharedActor = std::shared_ptr<Actor>;

class Game :
    public BaseScene
{
public:
	Game();
	~Game();

	// 更新(引数は自分)
	Scene Update(Scene own, const std::shared_ptr<Controller>& controller);
	// 初期化
	bool Init(void);
	// 描画
	void Draw(void);
private:
	// ゲーム内オブジェクトをまとめたリスト(メインで動くもの)
	std::vector<SharedActor> actorList_;
};

