#pragma once
#include <memory>

class BaseScene;
struct Controller;
using Scene = std::unique_ptr<BaseScene>;

class BaseScene
{
public:
	BaseScene();
	~BaseScene();
	// 更新(引数は自分)
	virtual Scene Update(Scene own,const std::shared_ptr<Controller>& controller) = 0;
	// 初期化
	virtual bool Init(void) = 0;
	// 描画
	virtual void Draw(void) = 0;

private:

protected:
	// 各スクリーンのハンドル
	// もしポーズ画面等作成したくなったらの為に作っている
	int scrHdl_;
};

