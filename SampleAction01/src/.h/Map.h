#pragma once
#include <vector>
#include "../.h/MapObject/MapObject.h"

#define lpMap Map::GetInstance()

using MapObjects = std::vector<MapObject>;

// �}�b�v�I�u�W�F�N�g���܂Ƃ߂�N���X
// �V���O���g���C���X�^���X
class Map
{
public:
	static Map& GetInstance(void)
	{
		return *instance_;
	}
	// ����
	static void Create(void)
	{
		if (!instance_)
		{
			instance_ = new Map();
		}
	}
	// �j��
	void Destroy(void)
	{
		if (instance_)
		{
			delete instance_;
		}
		instance_ = nullptr;
	}
	// �}�b�v�ɃI�u�W�F�N�g��ǉ�
	void AddObject(MapObject m_object);

	// �}�b�v�I�u�W�F�N�g�̕`��
	void DrawObject(void);


	// �Q�b�^�[
	// �|�W�V�����擾(�����Ƀ^�C�v���w�肵��)
	const Vector2I& GetPos(MAP_OBJECT_TYPE m_objType)
	{
		for (auto object : mapObjects_)
		{
			if (object.GetType() == m_objType)
			{
				return object.GetPos();
			}
		}
		// �G���[�l�Ƃ���(x,y)(-1,-1)��Ԃ�
		return Vector2I(-1,-1);
	}
private:
	Map() = default;
	~Map();

	void operator=(const Map&) = delete;

	static Map* instance_;
	// �}�b�v��̃I�u�W�F�N�g�R���e�i
	MapObjects mapObjects_;
};

