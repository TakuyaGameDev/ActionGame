#pragma once
#include "BaseScene.h"

class Title :
    public BaseScene
{
public:
    Title();
    ~Title();

	// �X�V(�����͎���)
	Scene Update(Scene own, const std::shared_ptr<Controller>& controller);
	// ������
	bool Init(void);
	// �`��
	void Draw(void);
private:

};

