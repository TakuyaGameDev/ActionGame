#pragma once

class ObjectPool
{
public:
	ObjectPool(int size);
	~ObjectPool();
	// �v�[�����̍X�V
	virtual void Update(void) = 0;
	// �v�[�����̕`��
	virtual void Draw(void) = 0;
private:

protected:

};

