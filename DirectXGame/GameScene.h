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

	void EffectBorn(Vector3 position);


private:


	Model* modelEffect_ = nullptr;

	Camera camera_;
	std::list<Effect*> effects_;

};