#pragma once
#include <vector>
#include "ObjectPool.h"

class EnemyPool :
    public ObjectPool
{
public:
    EnemyPool(int size);
    ~EnemyPool();
    // �X�V
    void Update(void);
    // �`��
    void Draw(void);

private:
};

