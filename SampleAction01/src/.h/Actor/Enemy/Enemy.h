#pragma once
#include "../Actor.h"

// �G�N���X
class Enemy :
    public Actor
{
public:
    Enemy(std::string name);
    ~Enemy();
    // �L�����̓���
    virtual void Move(const std::shared_ptr<Controller>& controller) = 0;
    // �������֘A
    virtual bool Init(void) = 0;

private:

protected:

};

