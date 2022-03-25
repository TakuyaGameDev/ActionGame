#pragma once
#include <memory>
#include "../.h/Geometory.h"
#include "../.h/scene/BaseScene.h"

class KeyInput;
class MouseInput;

#define lpApplication Application::GetInstance()

struct ScrSize
{
	Vector2I screen_;
	Vector2I image_screen_;
};

// ��ʑS�̂̃T�C�Y
#define SCREEN_X 1200
#define SCREEN_Y 640
// �摜��\������ӏ��̃T�C�Y
#define IMAGE_SCREEN_X 300
#define IMAGE_SCREEN_Y 250

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
	// �A�v���̏I��
	void Exit(void);
	// �e��ʂ̃T�C�Y�Z�b�g
	void SetScreenSize(Vector2I screen, Vector2I image);

	// ��ʑS�̂̃T�C�Y�擾
	const Vector2I& GetScreenSize(void)
	{
		return scrSize_.screen_;
	}
	// �ҏW�Ώۉ摜�̃X�N���[���T�C�Y�擾
	const Vector2I& GetImageScreenSize(void)
	{
		return scrSize_.image_screen_;
	}

private:
	Application() = default;
	~Application();

	void operator=(const Application&) = delete;
	// DxLib�������֘A
	bool SystemInit(void);

	ScrSize scrSize_;

	std::shared_ptr<KeyInput> key_;
	std::shared_ptr<MouseInput> mouse_;

	UniqueScene scene_;
};

