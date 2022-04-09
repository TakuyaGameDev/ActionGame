#pragma once
#include <string>
#include <vector>

#include "../.h/Geometory.h"

#define lpFileLoader FileLoader::GetInstance()

// シングルトンインスタンス
class FileLoader
{
public:
	static FileLoader& GetInstance(void)
	{
		return *instance_;
	}
	// 生成
	static void Create(void)
	{
		if (!instance_)
		{
			instance_ = new FileLoader();
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
	// リセットをかける
	static void Reset(void)
	{
		instance_->Destroy();
		instance_->Create();
	}
	// ファイルから画像サイズ情報の取得
	const Vector2I& GetImageSize(std::string filename);
	// ファイル読み込みをした際にそのままAnimationへ登録して画像分割カウントを取得
	const Vector2I& LoadAnimationData(std::string filename);

	// ディレクトリよりファイル名一覧のfind
	void FindFileNameList(std::string path);
	// ディレクトリからfindしたファイル名の取得
	const std::vector<std::string>& GetFilenames(void) const
	{
		return fileNames_;
	}
private:
	FileLoader() = default;
	~FileLoader();

	void operator=(const FileLoader&) = delete;

	static FileLoader* instance_;
	// ディレクトリからfindしてきたファイル名格納用
	std::vector<std::string> fileNames_;
};

