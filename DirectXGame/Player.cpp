#include "Player.h"

void Player::Initialize(Model2* model) {
	dxCommon_ = KamataEngine::DirectXCommon::GetInstance();
	input_ = KamataEngine::Input::GetInstance();

	assert(model);
	model_ = model;
	worldTransform_.Initialize();
}

void Player::Update() { 
	worldTransform_.TransferMatrix();
	

	
	if (input_->PushKey(DIK_A)) {
		worldTransform_.translation_.x -= 1.0f;
	}
	if (input_->PushKey(DIK_D)) {
		worldTransform_.translation_.x += 1.0f;
	}
	if (input_->PushKey(DIK_W)) {
		worldTransform_.translation_.y += 1.0f;
	}
	if (input_->PushKey(DIK_S)) {
		worldTransform_.translation_.y -= 1.0f;
	}


	worldTransform_.UpdateMatrix();
}

void Player::Draw(Camera& camera) {
	model_->Draw(worldTransform_, camera); }