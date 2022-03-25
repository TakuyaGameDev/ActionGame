#include <DxLib.h>
#include "../.h/Map.h"

Map* Map::instance_ = nullptr;

void Map::AddObject(MapObject m_object)
{
	mapObjects_.push_back(m_object);
}

void Map::DrawObject(void)
{
	for (auto object : mapObjects_)
	{
		auto objType = object.GetType();
		// ここでオブジェクトのタイプ毎に描画をしていく
		// 今はとにかくDrawLine等で対応
		// 後々name等で画像表示に変更
		switch (objType)
		{
			case MAP_OBJECT_TYPE::FLOOR:
				DrawLine(object.GetPos().x, object.GetPos().y, object.GetPos().x + 1000, object.GetPos().y, 0xffffff);
			break;

		}
	}
}

Map::~Map()
{
}
