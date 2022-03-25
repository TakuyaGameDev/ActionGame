#pragma once
#include <vector>
#include "../.h/MapObject/MapObject.h"

#define lpMap Map::GetInstance()

using MapObjects = std::vector<MapObject>;

// マップオブジェクトをまとめるクラス
// シングルトンインスタンス
class Map
{
public:
	static Map& GetInstance(void)
	{
		return *instance_;
	}
	// 生成
	static void Create(void)
	{
		if (!instance_)
		{
			instance_ = new Map();
		}
	}
	// 破棄
	void Destroy(void)
	{
		if (instance_)
		{
			delete instance_;
		}
		instance_ = nullptr;
	}
	// マップにオブジェクトを追加
	void AddObject(MapObject m_object);

	// マップオブジェクトの描画
	void DrawObject(void);


	// ゲッター
	// ポジション取得(引数にタイプを指定して)
	const Vector2I& GetPos(MAP_OBJECT_TYPE m_objType)
	{
		for (auto object : mapObjects_)
		{
			if (object.GetType() == m_objType)
			{
				return object.GetPos();
			}
		}
		// エラー値として(x,y)(-1,-1)を返す
		return Vector2I(-1,-1);
	}
private:
	Map() = default;
	~Map();

	void operator=(const Map&) = delete;

	static Map* instance_;
	// マップ上のオブジェクトコンテナ
	MapObjects mapObjects_;
};

