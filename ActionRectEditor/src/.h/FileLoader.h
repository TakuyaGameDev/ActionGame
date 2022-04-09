#pragma once
#include <string>
#include <vector>

#include "../.h/Geometory.h"

#define lpFileLoader FileLoader::GetInstance()

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
	// �t�@�C������摜�T�C�Y���̎擾
	const Vector2I& GetImageSize(std::string filename);
	// �t�@�C���ǂݍ��݂������ۂɂ��̂܂�Animation�֓o�^���ĉ摜�����J�E���g���擾
	const Vector2I& LoadAnimationData(std::string filename);

	// �f�B���N�g�����t�@�C�����ꗗ��find
	void FindFileNameList(std::string path);
	// �f�B���N�g������find�����t�@�C�����̎擾
	const std::vector<std::string>& GetFilenames(void) const
	{
		return fileNames_;
	}
private:
	FileLoader() = default;
	~FileLoader();

	void operator=(const FileLoader&) = delete;

	static FileLoader* instance_;
	// �f�B���N�g������find���Ă����t�@�C�����i�[�p
	std::vector<std::string> fileNames_;
};

