#pragma once

class Actor;

// �d�̓N���X
// �V���O���g���C���X�^���X(���I)
class Gravity
{
public:
	Gravity();
	~Gravity();
	// �d�͂̍X�V�A�I�u�W�F�N�g�ɏd�͂�������
	void Update(Actor& actor);

private:
	// �d�͉����x
	float g_power_;
};

