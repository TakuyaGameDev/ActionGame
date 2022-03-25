#pragma once
#include <string>
#include <map>
#include <vector>

#include "../.h/Geometory.h"

// Int型のコンテナ
using VecInt = std::vector<int>;
// 画像ハンドルを格納するための型(文字列で認識)
using Handle = std::map<std::string, VecInt>;

#define lpSprite SpriteCache::GetInstance()

// 画像を保存しておくクラス
// シングルトン
class SpriteCache
{
public:
	static SpriteCache& GetInstance(void)
	{
		static SpriteCache instance_;
		return instance_;
	}
	// 画像単体ロード
	void Load(std::string name);
	// 画像連番でのロード
	void Load(std::string name, Vector2I divsize, Vector2I divcnt);

	// ゲッター
	// 画像ハンドル取得
	const VecInt& GetHandle(std::string name)
	{
		return handles_[name + ".png"];
	}

private:
	SpriteCache() = default;
	~SpriteCache();
	// 画像ハンドル格納用
	Handle handles_;
};

