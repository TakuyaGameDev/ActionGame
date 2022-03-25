#pragma once
#include <map>
#include <string>

class Animation
{
public:
	Animation(std::string name,int maxframe, float duration,bool loop);
	~Animation();

	// アニメーション名取得
	const std::string& GetName(void) const
	{
		return name_;
	}
	// 最大フレーム数取得
	const int& GetmaxFrame(void) const
	{
		return maxFrame_;
	}
	// ループ再生フラグ取得
	const bool& GetisLoop(void) const 
	{
		return isLoop_;
	}
	// アニメーション間隔の取得
	const float& GetDuration(void) const
	{
		return duration_;
	}

private:
	// アニメーション名
	std::string name_;
	// 最大フレーム数
	int maxFrame_;
	// ループ再生フラグ
	bool isLoop_;
	// アニメーション間隔
	float duration_;
};

