#pragma once
#include <string>

#define lpAnimation Animation::GetInstance()

// �A�j���[�V�����ۑ��p�N���X
// �V���O���g���C���X�^���X
class Animation
{
public:
	static Animation& GetInstance(void)
	{
		static Animation instance_;
		return instance_;
	}

	void SetObjectName(std::string objName)
	{
		this->objName_ = objName;
	}
	void SetName(std::string name)
	{
		this->name_ = name;
	}
	void SetIsLoop(std::string loop)
	{
		if (loop == "1")
		{
			this->isLoop_ = true;
		}
		else
		{
			this->isLoop_ = false;
		}
	}
	void SetMaxFrame(int max)
	{
		this->maxFrame_ = max;
	}
	void SetDuration(float duration)
	{
		this->duration_ = duration;
	}

	// �I�u�W�F�N�g���擾
	const std::string& GetObjectName(void)
	{
		return objName_;
	}

	// �A�j���[�V�������擾
	const std::string& GetName(void)
	{
		return name_;
	}
	// ���[�v�Đ��t���O�擾
	const bool& IsLoop(void)
	{
		return isLoop_;
	}
	// �ő�R�}���擾
	const int& GetMaxFrame(void)
	{
		return maxFrame_;
	}

private:
	Animation() = default;
	~Animation();

	void operator=(const Animation&) = delete;
	// �I�u�W�F�N�g��
	std::string objName_;
	// �A�j���[�V������
	std::string name_;
	// ���[�v�Đ��t���O
	bool isLoop_;
	// �A�j���[�V�����R�}�̊Ԋu
	float duration_;
	// �ő�R�}��
	int maxFrame_;

};

