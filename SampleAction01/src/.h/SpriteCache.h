#pragma once
#include <string>
#include <map>
#include <vector>

#include "../.h/Geometory.h"

// Int�^�̃R���e�i
using VecInt = std::vector<int>;
// �摜�n���h�����i�[���邽�߂̌^(������ŔF��)
using Handle = std::map<std::string, VecInt>;

#define lpSprite SpriteCache::GetInstance()

// �摜��ۑ����Ă����N���X
// �V���O���g��
class SpriteCache
{
public:
	static SpriteCache& GetInstance(void)
	{
		static SpriteCache instance_;
		return instance_;
	}
	// �摜�P�̃��[�h
	void Load(std::string name);
	// �摜�A�Ԃł̃��[�h
	void Load(std::string name, Vector2I divsize, Vector2I divcnt);

	// �Q�b�^�[
	// �摜�n���h���擾
	const VecInt& GetHandle(std::string name)
	{
		return handles_[name + ".png"];
	}

private:
	SpriteCache() = default;
	~SpriteCache();
	// �摜�n���h���i�[�p
	Handle handles_;
};

