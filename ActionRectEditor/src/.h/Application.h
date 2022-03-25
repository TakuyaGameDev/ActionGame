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

// 画面全体のサイズ
#define SCREEN_X 1200
#define SCREEN_Y 640
// 画像を表示する箇所のサイズ
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
	// ゲームループ
	void Run(void);
	// アプリの終了
	void Exit(void);
	// 各画面のサイズセット
	void SetScreenSize(Vector2I screen, Vector2I image);

	// 画面全体のサイズ取得
	const Vector2I& GetScreenSize(void)
	{
		return scrSize_.screen_;
	}
	// 編集対象画像のスクリーンサイズ取得
	const Vector2I& GetImageScreenSize(void)
	{
		return scrSize_.image_screen_;
	}

private:
	Application() = default;
	~Application();

	void operator=(const Application&) = delete;
	// DxLib初期化関連
	bool SystemInit(void);

	ScrSize scrSize_;

	std::shared_ptr<KeyInput> key_;
	std::shared_ptr<MouseInput> mouse_;

	UniqueScene scene_;
};

