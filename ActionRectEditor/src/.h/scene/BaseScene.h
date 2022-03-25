#pragma once
#include <memory>

class BaseScene;
class KeyInput;
class MouseInput;

using UniqueScene = std::unique_ptr<BaseScene>;

// 各シーンの親
class BaseScene
{
public:
	BaseScene();
	~BaseScene();

	virtual UniqueScene Update(UniqueScene own, const std::shared_ptr<KeyInput>& key,const std::shared_ptr<MouseInput>& mouse) = 0;
	virtual bool Init(void) = 0;
	virtual void Draw(void) = 0;

private:

};

