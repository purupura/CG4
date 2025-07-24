#pragma once
#include "kamataEngine.h"

using namespace KamataEngine;

class Graph {
public:
	void Initialize();

	void Update();

	void Draw();

private:
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;

	WorldTransform worldTransform_;

	uint32_t textureHandle_ = 0;
	uint32_t textureHandle2_ = 0;
	Sprite* graphSprite_ = nullptr; 
	Sprite* graphSprite2_ = nullptr;

	float maxGraphGage = 120; //(20秒)
	float nowGraphGage = maxGraphGage;
	float width = 150;

};
