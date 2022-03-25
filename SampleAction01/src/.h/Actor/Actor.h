#pragma once
#include <string>
#include <memory>
#include "../Geometory.h"
#include "../Animation.h"
#include "../../.h/Gravity.h"
#include "../../.h/Direction.h"

struct Controller;

// ゲームで動くオブジェクト親クラス
class Actor
{
public:
	Actor(std::string name);
	~Actor();
	// 更新
	virtual void Update(const std::shared_ptr<Controller>& controller);
	// キャラの動き
	virtual void Move(const std::shared_ptr<Controller>& controller = nullptr) = 0;
	// 初期化関連
	virtual bool Init(void) = 0;
	// 描画
	virtual void Draw(void);

	// アニメーションカウンターの0クリ
	void ResetanimCnt(void)
	{
		this->animCnt_ = 0.0f;
	}

	// セッター
	// ポジションセット
	void SetPos(Vector2I pos)
	{
		this->pos_ = pos;
	}

	// アニメーションカウントの加算
	void AddanimCnt(float cnt)
	{
		this->animCnt_ += cnt;
	}
	// アニメーションカウントセット
	void SetanimCnt(float cnt)
	{
		this->animCnt_ = cnt;
	}
	// アニメーション終了フラグセット
	void SetisAnimEnd(bool end)
	{
		this->isAnimEnd_ = end;
	}
	// ジャンプフラグセット
	void SetisJump(bool jFlg)
	{
		this->isJump_ = jFlg;
	}
	


	// ゲッター
	// ポジション取得
	const Vector2I& GetPos(void)
	{
		return this->pos_;
	}
	// アニメーションカウンター取得
	const float& GetanimCnt(void)
	{
		return this->animCnt_;
	}
	// 現在のアニメーション取得
	const Animation& GetCurrentAnim(void)
	{
		return *this->currentAnim_;
	}
	// 現在のアニメーション名の取得
	const std::string& GetCurrentAnimName(void)
	{
		return currentAnimName_;
	}
	// ジャンプ中なのかの判定フラグ取得
	const bool& IsJump(void)
	{
		return isJump_;
	}
private:

protected:
	// アニメーションカウント
	float animCnt_;
	// アニメーション終了フラグ
	bool isAnimEnd_;
	// 自分の名前
	const std::string name_;
	// 今走っているアニメーション名
	std::string currentAnimName_;
	// 1フレーム前のアニメーション名
	std::string oldAnimName_;
	// ポジション
	Vector2I pos_;
	// オブジェクトのサイズ
	Vector2I size_;
	// 方向
	DIRECTION direction_;
	// 反転フラグ
	bool isFlipped_;
	// 現在のアニメーション
	Animation* currentAnim_;
	// 重力
	Gravity gravity_;
	// 攻撃しているかの判定フラグ
	bool isAttack_;
	// ジャンプしているかの判定フラグ
	bool isJump_;
	// ジャンプ力
	float jumpPower_;
	// 攻撃連携の為のウェイトカウンター
	// 攻撃を終えてすぐidleモーションに戻るのではなく、少し時間をおいて戻る為
	int attackWaitCnt_;
	// ジャンプ初速度
	float j_first_power_;
};

