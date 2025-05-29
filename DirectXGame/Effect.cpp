#include "Effect.h"
#include <random>
#include <cassert>

std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> distribution(5.0f, 20.0f);

std::random_device seedGenerator3;
std::mt19937 randomEngine3(seedGenerator3());
std::uniform_real_distribution<float> distribution3(0.0f, 10.0f);

void Effect::Initialize(Model* model, Vector3 position) {
	assert(model);
	model_ = model;
	worldTransform_.Initialize();
	
	objectColor_.Initialize();
	color_ = {distribution3(randomEngine3), distribution3(randomEngine3), distribution3(randomEngine3), 1};

	// 大きさ（スケール）のY軸を変更（例：3倍）
	worldTransform_.scale_ = {1.0f, distribution(randomEngine), 1.0f};

	// 回転（Z軸）を30度に設定（度→ラジアンに変換）
	worldTransform_.rotation_ = {
	   0.0f,                              // X軸
	   0.0f,                              // Y軸
	    distribution(randomEngine) // Z軸
	};

	worldTransform_.translation_ = position;
}

void Effect::Update() { 
	if (isFinished) {
		return;
	}

	counter_ += 1.0f / 60.0f;

	if (counter_ >= kDuration) {
		counter_ = kDuration;
		isFinished = true;
	}

	worldTransform_.rotation_.z++;

	worldTransform_.TransferMatrix();
	worldTransform_.UpdateMatrix();
	objectColor_.SetColor(color_);
	color_.w = std::clamp(1.0f - counter_ / kDuration, 0.0f, 1.0f);
}

void Effect::Draw(Camera& camera) {
	model_->Draw(worldTransform_, camera,&objectColor_); }