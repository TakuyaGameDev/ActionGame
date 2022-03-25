#pragma once
#include "BaseScene.h"

class Title :
    public BaseScene
{
public:
    Title();
    ~Title();

	// XV(ˆø”‚Í©•ª)
	Scene Update(Scene own, const std::shared_ptr<Controller>& controller);
	// ‰Šú‰»
	bool Init(void);
	// •`‰æ
	void Draw(void);
private:

};

