#pragma once
#include "KamataEngine.h"
#include "Effect.h"

class GameScene {
public:
	~GameScene();
	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();


private:


	Model* modelEffect_ = nullptr;

	Camera camera_;

	Effect* effect_ = nullptr;
};