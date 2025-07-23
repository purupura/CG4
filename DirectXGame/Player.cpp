#include "Player.h"

void Player::Initialize(Model2* model) {
	assert(model);
	model_ = model;
	worldTransform_.Initialize();
}

void Player::Update() { 
	worldTransform_.TransferMatrix();

	worldTransform_.translation_.y -= 1.0f;

	worldTransform_.UpdateMatrix();
}

void Player::Draw(Camera& camera) {
	model_->Draw(worldTransform_, camera); }