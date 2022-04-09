#pragma once
#include <string>

#define lpAnimation Animation::GetInstance()

// アニメーション保存用クラス
// シングルトンインスタンス
class Animation
{
public:
	static Animation& GetInstance(void)
	{
		static Animation instance_;
		return instance_;
	}

	void SetObjectName(std::string objName)
	{
		this->objName_ = objName;
	}
	void SetName(std::string name)
	{
		this->name_ = name;
	}
	void SetIsLoop(std::string loop)
	{
		if (loop == "1")
		{
			this->isLoop_ = true;
		}
		else
		{
			this->isLoop_ = false;
		}
	}
	void SetMaxFrame(int max)
	{
		this->maxFrame_ = max;
	}
	void SetDuration(float duration)
	{
		this->duration_ = duration;
	}

	// オブジェクト名取得
	const std::string& GetObjectName(void)
	{
		return objName_;
	}

	// アニメーション名取得
	const std::string& GetName(void)
	{
		return name_;
	}
	// ループ再生フラグ取得
	const bool& IsLoop(void)
	{
		return isLoop_;
	}
	// 最大コマ数取得
	const int& GetMaxFrame(void)
	{
		return maxFrame_;
	}

private:
	Animation() = default;
	~Animation();

	void operator=(const Animation&) = delete;
	// オブジェクト名
	std::string objName_;
	// アニメーション名
	std::string name_;
	// ループ再生フラグ
	bool isLoop_;
	// アニメーションコマの間隔
	float duration_;
	// 最大コマ数
	int maxFrame_;

};

