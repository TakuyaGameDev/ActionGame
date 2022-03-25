#include <DxLib.h>
#include "../../.h/Scene/Game.h"
#include "../../.h/Actor/Player.h"
#include "../../.h/Actor/Enemy/Enemy01.h"
#include "../../.h/AnimationCache.h"
#include "../../.h/SpriteCache.h"
#include "../../.h/Map.h"

Game::Game()
{
	// もし初期化に失敗したら業務エラーメッセージ表示
	if (!Init())
	{

	}
}

Game::~Game()
{
	// スクリーンの削除
	DeleteGraph(scrHdl_);
}

Scene Game::Update(Scene own, const std::shared_ptr<Controller>& controller)
{
	// ゲーム内オブジェクトの更新
	for (auto& actor : actorList_)
	{
		actor->Update(controller);
	}


	// 描画
	Draw();
	return move(own);
}

bool Game::Init(void)
{
	// もし画像ハンドルがエラー値だったらそのあとの処理はしない
	if (scrHdl_ <= 0)
	{
		return false;
	}
	// マップの生成
	lpMap.Create();
	// マップオブジェクトの追加
	lpMap.AddObject(MapObject(MAP_OBJECT_TYPE::FLOOR,Vector2I(0,540)));
	// 固定背景ハンドルの生成
	SetDrawScreen(scrHdl_);
	// マップオブジェクトの描画
	lpMap.DrawObject();
	// 描画先をBACKに変更
	SetDrawScreen(DX_SCREEN_BACK);

	// プレイヤー画像のロード
	// 待機モーション(0:武器しまっているver. 1:武器しまってないver.)
	lpSprite.Load("Actors/Player/idle0.png", Vector2I(100, 74), Vector2I(4, 1));
	lpSprite.Load("Actors/Player/idle1.png", Vector2I(100, 74), Vector2I(4, 1));
	// 武器をしまう、出すモーション
	lpSprite.Load("Actors/Player/sword_drawing.png", Vector2I(100, 74), Vector2I(4, 1));
	lpSprite.Load("Actors/Player/sword_putaway.png", Vector2I(100, 74), Vector2I(4, 1));
	// 攻撃モーション(剣)
	lpSprite.Load("Actors/Player/attack1-1.png", Vector2I(100, 74), Vector2I(5, 1));
	lpSprite.Load("Actors/Player/attack1-2.png", Vector2I(100, 74), Vector2I(6, 1));
	lpSprite.Load("Actors/Player/attack1-3.png", Vector2I(100, 74), Vector2I(6, 1));
	// 攻撃モーション(パンチ)
	lpSprite.Load("Actors/Player/attack_punch1.png", Vector2I(100, 74), Vector2I(4, 1));
	lpSprite.Load("Actors/Player/attack_punch2.png", Vector2I(100, 74), Vector2I(5, 1));
	lpSprite.Load("Actors/Player/attack_punch3.png", Vector2I(100, 74), Vector2I(4, 1));
	// 攻撃モーション(キック)
	lpSprite.Load("Actors/Player/attack_kick1.png", Vector2I(100, 74), Vector2I(4, 1));
	lpSprite.Load("Actors/Player/attack_kick2.png", Vector2I(100, 74), Vector2I(4, 1));
	// 走るモーション
	lpSprite.Load("Actors/Player/run.png", Vector2I(100, 74), Vector2I(6, 1));
	// ジャンプモーション
	lpSprite.Load("Actors/Player/jump.png", Vector2I(100, 74), Vector2I(4, 1));
	// ジャンプ後のサマーソルトモーション
	lpSprite.Load("Actors/Player/smrslt.png", Vector2I(100, 74), Vector2I(4, 1));
	// サマーソルト後の落下モーション
	lpSprite.Load("Actors/Player/fall.png", Vector2I(100, 74), Vector2I(2, 1));

	// 敵画像ロード
	// 待機モーション
	lpSprite.Load("Actors/Enemy/Enemy01/idle.png", Vector2I(225, 72), Vector2I(4, 1));
	// 走りモーション
	lpSprite.Load("Actors/Enemy/Enemy01/run.png", Vector2I(225, 72), Vector2I(8, 1));
	// 攻撃モーション
	lpSprite.Load("Actors/Enemy/Enemy01/attack.png", Vector2I(225, 72), Vector2I(8, 1));

	// アニメーションキャッシュの生成
	lpAnimationCache.Create();
	
	// ゲーム内オブジェクトの生成
	actorList_.push_back(std::make_shared<Player>(Vector2I(0, 0)));
	actorList_.push_back(std::make_shared<Enemy01>(Vector2I(600, 0)));
	return true;
}

void Game::Draw(void)
{
	ClsDrawScreen();
	// 固定背景の描画
	DrawGraph(0, 0, scrHdl_, true);
	// ゲーム内オブジェクトの描画
	for (auto& actor : actorList_)
	{
		actor->Draw();
	}
	ScreenFlip();
}
