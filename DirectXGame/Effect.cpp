#include "Effect.h"
#include <cassert>

void Effect::Initialize(Model2* model) {
	assert(model);
	model_ = model;
	worldTransform_.Initialize();
}

void Effect::Update() { 
	worldTransform_.TransferMatrix(); }

void Effect::Draw(Camera& camera) {
	model_->Draw(worldTransform_, camera); }