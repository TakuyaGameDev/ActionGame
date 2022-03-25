#pragma once
#include "../../.h/Geometory.h"
#include "../MapObject/MapObjectType.h"

class MapObject
{
public:
	MapObject(MAP_OBJECT_TYPE m_objType,Vector2I pos);
	~MapObject();

	// セッター-----------------------------------


	// ゲッター
	// ポジション取得
	const Vector2I& GetPos(void) const
	{
		return this->pos_;
	}
	// タイプ取得
	const MAP_OBJECT_TYPE& GetType(void) const
	{
		return this->type_;
	}

private:
	// ポジション
	Vector2I pos_;
	// サイズ
	Vector2I size_;
	// 自分のオブジェクトタイプ
	const MAP_OBJECT_TYPE type_;
};

