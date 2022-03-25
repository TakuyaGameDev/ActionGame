#pragma once
#include <string>

// ファイル操作クラス
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
	static void Destroy(void)
	{
		if (instance_)
		{
			delete instance_;
		}
		instance_ = nullptr;
	}
	// ファイル読み込み
	void Read(std::string filename);
private:
	FileLoader() = default;
	~FileLoader();

	static FileLoader* instance_;
};

