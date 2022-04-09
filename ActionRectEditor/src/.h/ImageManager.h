#pragma once
#include <string>
#include <vector>
#include <map>

#include "../.h/Geometory.h"

#define lpImageManager ImageManager::GetInstance()

using VecInt = std::vector<int>;

class ImageManager
{
public:
	static ImageManager& GetInstance(void)
	{
		return *instance_;
	}
	// ����
	static void Create(void)
	{
		if (!instance_)
		{
			instance_ = new ImageManager();
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
	// ���Z�b�g��������
	static void Reset(void)
	{
		instance_->Destroy();
		instance_->Create();
	}
	void Load(std::string name);
	void Load(std::string name, Vector2I divsize, Vector2I divcnt);

	const VecInt& GetHandles(std::string path)
	{
		return handles_[path];
	}
	// �摜�T�C�Y�擾
	const Vector2I& GetImageSize(void)
	{
		return size_;
	}

private:
	ImageManager() = default;
	~ImageManager();

	void operator=(const ImageManager&) = delete;

	static ImageManager* instance_;

	std::map<std::string, VecInt> handles_;

	Vector2I size_;
};

