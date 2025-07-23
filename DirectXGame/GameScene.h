#pragma once
#include "KamataEngine.h"
#include "Effect.h"
#include "Model2.h"
#include "Player.h"

class GameScene {
public:
	~GameScene();
	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();

	void BackGroundUpdate();

	bool IsFinished() const { return isFinished_; }

private:
	DirectXCommon* dxCommon_ = nullptr;

	Model2* modelEffect_ = nullptr;
	Model2* modelPlayer_ = nullptr;

	Camera camera_;

	Effect* effect_ = nullptr;

	Input* input_ = nullptr;

	bool isFinished_ = false;

	uint32_t textureHandle_ = 0;
	Sprite* backGroundSprite_ = nullptr; //背景の画像
	Sprite* backGroundSprite2_ = nullptr;

	// 　自キャラ
	Player* player_ = nullptr;
};