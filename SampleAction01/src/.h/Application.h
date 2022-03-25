#pragma once
#include "../.h/Geometory.h"
#include "../.h/Scene/BaseScene.h"

struct Controller;

#define lpApplication Application::GetInstance()

constexpr int SCREEN_X = 1000;
constexpr int SCREEN_Y = 600;

class Application
{
public:
	static Application& GetInstance(void)
	{
		static Application instance_;
		return instance_;
	}
	// �Q�[�����[�v
	void Run(void);
	// DxLib�̏I��
	void Exit(void);

	// �Z�b�^�[----------------------------------
	// ��ʃT�C�Y�̐ݒ�
	void SetScreenSize(Vector2I size)
	{
		this->screen_size_ = size;
	}
	


	// �Q�b�^�[----------------------------------
	Vector2I GetScreenSize(void)
	{
		return screen_size_;
	}

private:
	Application() = default;
	~Application();

	// DxLib�̏������֌W
	// ������������������true
	bool SystemInit(void);

	// ��ʃT�C�Y
	Vector2I screen_size_;

	// �V�[�������p
	Scene scene_;
	// �R���g���[���[�����p
	std::shared_ptr<Controller> controller_;
};

