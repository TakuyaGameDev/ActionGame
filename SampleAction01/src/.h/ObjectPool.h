#pragma once

class ObjectPool
{
public:
	ObjectPool(int size);
	~ObjectPool();
	// プール内の更新
	virtual void Update(void) = 0;
	// プール内の描画
	virtual void Draw(void) = 0;
private:

protected:

};

