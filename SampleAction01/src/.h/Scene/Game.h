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

	// �X�V(�����͎���)
	Scene Update(Scene own, const std::shared_ptr<Controller>& controller);
	// ������
	bool Init(void);
	// �`��
	void Draw(void);
private:
	// �Q�[�����I�u�W�F�N�g���܂Ƃ߂����X�g(���C���œ�������)
	std::vector<SharedActor> actorList_;
};

