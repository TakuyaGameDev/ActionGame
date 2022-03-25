#include <DxLib.h>
#include "../../.h/Scene/Game.h"
#include "../../.h/Actor/Player.h"
#include "../../.h/Actor/Enemy/Enemy01.h"
#include "../../.h/AnimationCache.h"
#include "../../.h/SpriteCache.h"
#include "../../.h/Map.h"

Game::Game()
{
	// �����������Ɏ��s������Ɩ��G���[���b�Z�[�W�\��
	if (!Init())
	{

	}
}

Game::~Game()
{
	// �X�N���[���̍폜
	DeleteGraph(scrHdl_);
}

Scene Game::Update(Scene own, const std::shared_ptr<Controller>& controller)
{
	// �Q�[�����I�u�W�F�N�g�̍X�V
	for (auto& actor : actorList_)
	{
		actor->Update(controller);
	}


	// �`��
	Draw();
	return move(own);
}

bool Game::Init(void)
{
	// �����摜�n���h�����G���[�l�������炻�̂��Ƃ̏����͂��Ȃ�
	if (scrHdl_ <= 0)
	{
		return false;
	}
	// �}�b�v�̐���
	lpMap.Create();
	// �}�b�v�I�u�W�F�N�g�̒ǉ�
	lpMap.AddObject(MapObject(MAP_OBJECT_TYPE::FLOOR,Vector2I(0,540)));
	// �Œ�w�i�n���h���̐���
	SetDrawScreen(scrHdl_);
	// �}�b�v�I�u�W�F�N�g�̕`��
	lpMap.DrawObject();
	// �`����BACK�ɕύX
	SetDrawScreen(DX_SCREEN_BACK);

	// �v���C���[�摜�̃��[�h
	// �ҋ@���[�V����(0:���킵�܂��Ă���ver. 1:���킵�܂��ĂȂ�ver.)
	lpSprite.Load("Actors/Player/idle0.png", Vector2I(100, 74), Vector2I(4, 1));
	lpSprite.Load("Actors/Player/idle1.png", Vector2I(100, 74), Vector2I(4, 1));
	// ��������܂��A�o�����[�V����
	lpSprite.Load("Actors/Player/sword_drawing.png", Vector2I(100, 74), Vector2I(4, 1));
	lpSprite.Load("Actors/Player/sword_putaway.png", Vector2I(100, 74), Vector2I(4, 1));
	// �U�����[�V����(��)
	lpSprite.Load("Actors/Player/attack1-1.png", Vector2I(100, 74), Vector2I(5, 1));
	lpSprite.Load("Actors/Player/attack1-2.png", Vector2I(100, 74), Vector2I(6, 1));
	lpSprite.Load("Actors/Player/attack1-3.png", Vector2I(100, 74), Vector2I(6, 1));
	// �U�����[�V����(�p���`)
	lpSprite.Load("Actors/Player/attack_punch1.png", Vector2I(100, 74), Vector2I(4, 1));
	lpSprite.Load("Actors/Player/attack_punch2.png", Vector2I(100, 74), Vector2I(5, 1));
	lpSprite.Load("Actors/Player/attack_punch3.png", Vector2I(100, 74), Vector2I(4, 1));
	// �U�����[�V����(�L�b�N)
	lpSprite.Load("Actors/Player/attack_kick1.png", Vector2I(100, 74), Vector2I(4, 1));
	lpSprite.Load("Actors/Player/attack_kick2.png", Vector2I(100, 74), Vector2I(4, 1));
	// ���郂�[�V����
	lpSprite.Load("Actors/Player/run.png", Vector2I(100, 74), Vector2I(6, 1));
	// �W�����v���[�V����
	lpSprite.Load("Actors/Player/jump.png", Vector2I(100, 74), Vector2I(4, 1));
	// �W�����v��̃T�}�[�\���g���[�V����
	lpSprite.Load("Actors/Player/smrslt.png", Vector2I(100, 74), Vector2I(4, 1));
	// �T�}�[�\���g��̗������[�V����
	lpSprite.Load("Actors/Player/fall.png", Vector2I(100, 74), Vector2I(2, 1));

	// �G�摜���[�h
	// �ҋ@���[�V����
	lpSprite.Load("Actors/Enemy/Enemy01/idle.png", Vector2I(225, 72), Vector2I(4, 1));
	// ���胂�[�V����
	lpSprite.Load("Actors/Enemy/Enemy01/run.png", Vector2I(225, 72), Vector2I(8, 1));
	// �U�����[�V����
	lpSprite.Load("Actors/Enemy/Enemy01/attack.png", Vector2I(225, 72), Vector2I(8, 1));

	// �A�j���[�V�����L���b�V���̐���
	lpAnimationCache.Create();
	
	// �Q�[�����I�u�W�F�N�g�̐���
	actorList_.push_back(std::make_shared<Player>(Vector2I(0, 0)));
	actorList_.push_back(std::make_shared<Enemy01>(Vector2I(600, 0)));
	return true;
}

void Game::Draw(void)
{
	ClsDrawScreen();
	// �Œ�w�i�̕`��
	DrawGraph(0, 0, scrHdl_, true);
	// �Q�[�����I�u�W�F�N�g�̕`��
	for (auto& actor : actorList_)
	{
		actor->Draw();
	}
	ScreenFlip();
}
