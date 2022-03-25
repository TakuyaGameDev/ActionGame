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
	// �X�V(�����͎���)
	virtual Scene Update(Scene own,const std::shared_ptr<Controller>& controller) = 0;
	// ������
	virtual bool Init(void) = 0;
	// �`��
	virtual void Draw(void) = 0;

private:

protected:
	// �e�X�N���[���̃n���h��
	// �����|�[�Y��ʓ��쐬�������Ȃ�����ׂ̈ɍ���Ă���
	int scrHdl_;
};

