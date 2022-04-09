#include <DxLib.h>
#include "../.h/ImageManager.h"

ImageManager* ImageManager::instance_ = nullptr;

void ImageManager::Load(std::string name)
{
	if (handles_.count(name) <= 0)
	{
		handles_[name].resize(1);
		handles_[name][0] = LoadGraph(("Images/Actors/" + name + ".png").c_str());
	}
}

void ImageManager::Load(std::string name, Vector2I divsize, Vector2I divcnt)
{
	if (handles_.count(name) <= 0)
	{
		handles_[name].resize(divcnt.x * divcnt.y);
		LoadDivGraph(("Images/Actors/" + name + ".png").c_str(), divcnt.x * divcnt.y, divcnt.x, divcnt.y, divsize.x, divsize.y, &handles_[name][0]);
		size_ = divsize;
	}
}

ImageManager::~ImageManager()
{
}
