#pragma once
#include "../../.h/Geometory.h"
#include "../MapObject/MapObjectType.h"

class MapObject
{
public:
	MapObject(MAP_OBJECT_TYPE m_objType,Vector2I pos);
	~MapObject();

	// �Z�b�^�[-----------------------------------


	// �Q�b�^�[
	// �|�W�V�����擾
	const Vector2I& GetPos(void) const
	{
		return this->pos_;
	}
	// �^�C�v�擾
	const MAP_OBJECT_TYPE& GetType(void) const
	{
		return this->type_;
	}

private:
	// �|�W�V����
	Vector2I pos_;
	// �T�C�Y
	Vector2I size_;
	// �����̃I�u�W�F�N�g�^�C�v
	const MAP_OBJECT_TYPE type_;
};

