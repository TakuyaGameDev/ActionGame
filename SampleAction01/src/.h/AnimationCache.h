#pragma once
#include <map>
#include <string>
#include <vector>

#include "../.h/Animation.h"

// ゲームオブジェクトのアニメーションデータ
using ActorAnimation = std::map<std::string, std::vector<Animation>>;

#define lpAnimationCache AnimationCache::GetInstance()

// アニメーションに関するデータを保存しておくクラス
// シングルトンインスタンス
// 敵の場合は同じ敵がいても使いまわしを可能にするため
class AnimationCache
{
public:
	static AnimationCache& GetInstance(void)
	{
		return *instance_;
	}
	// 生成
	static void Create(void)
	{
		if (!instance_)
		{
			instance_ = new AnimationCache();
		}
	}
	// 破棄
	static void Destroy(void)
	{
		if (instance_)
		{
			delete instance_;
		}
		instance_ = nullptr;
	}
	// 常に指定オブジェクトに対するアニメーションデータが登録済みであればtrueを返す
	bool IsExistActorAnim(std::string actorname)
	{
		if (actorAnims_.count(actorname) > 0)
		{
			return true;
		}
		return false;
	}
	// アニメーションセット
	// IsExistActorAnim()がfalseの場合にアニメーションを格納していく
	void SetAnimation(std::string actorname, const Animation& animation);

	// アニメーション取得
	Animation* GetAnimation(std::string actorname, std::string animname)
	{
		// アニメーションが見つかれば対応したアニメーションデータを返す
		if (actorAnims_.count(actorname) > 0)
		{
			for (auto& animation : actorAnims_[actorname])
			{
				if (animation.GetName() == animname)
				{
					return &animation;
				}
			}
		}
		// 見つからなかったらnullを返す
		return nullptr;
	}
private:
	AnimationCache() = default;
	~AnimationCache();

	static AnimationCache* instance_;
	// ゲームオブジェクトのアニメーションデータ格納用
	ActorAnimation actorAnims_;
};

