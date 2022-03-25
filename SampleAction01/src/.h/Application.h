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
	// ゲームループ
	void Run(void);
	// DxLibの終了
	void Exit(void);

	// セッター----------------------------------
	// 画面サイズの設定
	void SetScreenSize(Vector2I size)
	{
		this->screen_size_ = size;
	}
	


	// ゲッター----------------------------------
	Vector2I GetScreenSize(void)
	{
		return screen_size_;
	}

private:
	Application() = default;
	~Application();

	// DxLibの初期化関係
	// 初期化が成功したらtrue
	bool SystemInit(void);

	// 画面サイズ
	Vector2I screen_size_;

	// シーン生成用
	Scene scene_;
	// コントローラー生成用
	std::shared_ptr<Controller> controller_;
};

