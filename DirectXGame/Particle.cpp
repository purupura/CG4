#include "Particle.h"

using namespace MathUtility;

void Particle::Initialize(Model* model, Vector3 position) { 
	assert(model); 
	model_ = model;
	worldTransform_.Initialize();

	objectColor_.Initialize();
	color_ = {1, 1, 0, 1};

	worldTransform_.translation_ = position;

}

void Particle::Update() {
	worldTransform_.TransferMatrix();

	objectColor_.SetColor(color_);

	worldTransform_.translation_ += {0.0f, 0.1f, 0.0f};

	worldTransform_.TransferMatrix();

	worldTransform_.UpdateMatrix();

}

void Particle::Draw(Camera& camera) { 
	model_->Draw(worldTransform_, camera,&objectColor_);

}
