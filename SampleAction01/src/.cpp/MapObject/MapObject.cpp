#include "../../.h/MapObject/MapObject.h"

MapObject::MapObject(MAP_OBJECT_TYPE m_objType, Vector2I pos):
	type_(m_objType)
{
	this->pos_ = pos;
}

MapObject::~MapObject()
{
}
