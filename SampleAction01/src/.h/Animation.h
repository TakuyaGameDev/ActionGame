#pragma once
#include <map>
#include <string>

class Animation
{
public:
	Animation(std::string name,int maxframe, float duration,bool loop);
	~Animation();

	// �A�j���[�V�������擾
	const std::string& GetName(void) const
	{
		return name_;
	}
	// �ő�t���[�����擾
	const int& GetmaxFrame(void) const
	{
		return maxFrame_;
	}
	// ���[�v�Đ��t���O�擾
	const bool& GetisLoop(void) const 
	{
		return isLoop_;
	}
	// �A�j���[�V�����Ԋu�̎擾
	const float& GetDuration(void) const
	{
		return duration_;
	}

private:
	// �A�j���[�V������
	std::string name_;
	// �ő�t���[����
	int maxFrame_;
	// ���[�v�Đ��t���O
	bool isLoop_;
	// �A�j���[�V�����Ԋu
	float duration_;
};

