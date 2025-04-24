#include "Particle.h"

using namespace MathUtility;

void Particle::Initialize(Model* model, Vector3 position, Vector3 velocity) { 
	assert(model); 
	model_ = model;
	worldTransform_.Initialize();

	objectColor_.Initialize();
	color_ = {1, 1, 0, 1};

	worldTransform_.translation_ = position;
	worldTransform_.scale_ = {0.2f, 0.2f, 0.2f};
	velocity_ = velocity;
}

void Particle::Update() {
	worldTransform_.TransferMatrix();

	objectColor_.SetColor(color_);

	worldTransform_.translation_ += {velocity_.x, velocity_.y, velocity_.z};

	worldTransform_.TransferMatrix();

	worldTransform_.UpdateMatrix();

}

void Particle::Draw(Camera& camera) { 
	model_->Draw(worldTransform_, camera,&objectColor_);

}
