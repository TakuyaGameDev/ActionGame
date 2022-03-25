#pragma once
#include <string>

// �t�@�C������N���X
// �V���O���g���C���X�^���X

class FileLoader
{
public:
	static FileLoader& GetInstance(void)
	{
		return *instance_;
	}
	// ����
	static void Create(void)
	{
		if (!instance_)
		{
			instance_ = new FileLoader();
		}
	}
	// �j��
	static void Destroy(void)
	{
		if (instance_)
		{
			delete instance_;
		}
		instance_ = nullptr;
	}
	// �t�@�C���ǂݍ���
	void Read(std::string filename);
private:
	FileLoader() = default;
	~FileLoader();

	static FileLoader* instance_;
};

