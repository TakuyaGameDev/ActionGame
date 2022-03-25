#pragma once
#include <map>
#include <string>
#include <vector>

#include "../.h/Animation.h"

// �Q�[���I�u�W�F�N�g�̃A�j���[�V�����f�[�^
using ActorAnimation = std::map<std::string, std::vector<Animation>>;

#define lpAnimationCache AnimationCache::GetInstance()

// �A�j���[�V�����Ɋւ���f�[�^��ۑ����Ă����N���X
// �V���O���g���C���X�^���X
// �G�̏ꍇ�͓����G�����Ă��g���܂킵���\�ɂ��邽��
class AnimationCache
{
public:
	static AnimationCache& GetInstance(void)
	{
		return *instance_;
	}
	// ����
	static void Create(void)
	{
		if (!instance_)
		{
			instance_ = new AnimationCache();
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
	// ��Ɏw��I�u�W�F�N�g�ɑ΂���A�j���[�V�����f�[�^���o�^�ς݂ł����true��Ԃ�
	bool IsExistActorAnim(std::string actorname)
	{
		if (actorAnims_.count(actorname) > 0)
		{
			return true;
		}
		return false;
	}
	// �A�j���[�V�����Z�b�g
	// IsExistActorAnim()��false�̏ꍇ�ɃA�j���[�V�������i�[���Ă���
	void SetAnimation(std::string actorname, const Animation& animation);

	// �A�j���[�V�����擾
	Animation* GetAnimation(std::string actorname, std::string animname)
	{
		// �A�j���[�V������������ΑΉ������A�j���[�V�����f�[�^��Ԃ�
		if (actorAnims_.count(actorname) > 0)
		{
			for (auto& animation : actorAnims_[actorname])
			{
				if (animation.GetName() == animname)
				{
					return &animation;
				}
			}
		}
		// ������Ȃ�������null��Ԃ�
		return nullptr;
	}
private:
	AnimationCache() = default;
	~AnimationCache();

	static AnimationCache* instance_;
	// �Q�[���I�u�W�F�N�g�̃A�j���[�V�����f�[�^�i�[�p
	ActorAnimation actorAnims_;
};

