#include "../.h/AnimationCache.h"

AnimationCache* AnimationCache::instance_ = nullptr;

void AnimationCache::SetAnimation(std::string actorname, const Animation& animation)
{
	actorAnims_[actorname].push_back(animation);
}

AnimationCache::~AnimationCache()
{

}
