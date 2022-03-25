#include <DxLib.h>
#include "../.h/SpriteCache.h"

void SpriteCache::Load(std::string name)
{
	if (handles_.count(name) <= 0)
	{
		// ‰æ‘œ1–‡•ª‚ÌƒŠƒTƒCƒY
		handles_[name].resize(1);
		handles_[name][0] = LoadGraph(("Images/" + name).c_str());
	}
}

void SpriteCache::Load(std::string name, Vector2I divsize, Vector2I divcnt)
{
	if (handles_.count(name) <= 0)
	{
		handles_[name].resize(divcnt.x * divcnt.y);
		LoadDivGraph(("Images/" + name).c_str(),
			divcnt.x * divcnt.y,
			divcnt.x, divcnt.y,
			divsize.x, divsize.y, &handles_[name][0]);
	}
}

SpriteCache::~SpriteCache()
{
}
