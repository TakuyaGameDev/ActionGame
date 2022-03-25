#include "../.h/Animation.h"

Animation::Animation(std::string name, int maxframe, float duration, bool loop)
{
	this->name_ = name;
	this->maxFrame_ = maxframe;
	this->isLoop_ = loop;
	this->duration_ = duration;
}

Animation::~Animation()
{
}
