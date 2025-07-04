#pragma once
#include "KamataEngine.h"
#include "Effect.h"
#include "Model2.h"

class GameScene {
public:
	~GameScene();
	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();

	bool IsFinished() const { return isFinished_; }

private:
	DirectXCommon* dxCommon_ = nullptr;

	Model2* modelEffect_ = nullptr;

	Camera camera_;

	Effect* effect_ = nullptr;

	Input* input_ = nullptr;

	bool isFinished_ = false;


};