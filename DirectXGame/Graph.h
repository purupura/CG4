#pragma once
#include "kamataEngine.h"

using namespace KamataEngine;

class Graph {
public:

	~Graph();

	void Initialize();

	void Update();

	void Draw();

	Vector2 numberSize = {32.0f, 64.0f};

private:
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;

	WorldTransform worldTransform_;

	uint32_t textureHandle_ = 0;
	uint32_t textureHandle2_ = 0;
	uint32_t textureHandle3_ = 0;
	Sprite* graphSprite_ = nullptr; 
	Sprite* graphSprite2_ = nullptr; 
    Sprite* graphSprite3_[5]{}; 

	float maxGraphGage = 120; //(20秒)
	float nowGraphGage = maxGraphGage;
	float width = 150;


 
    int32_t number = 777; // "number" を定義
};
