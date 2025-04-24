#include "Particle.h"

void Particle::Initialize(Model* model) { 
	assert(model); 
	model_ = model;
	worldTransform_.Initialize();

	objectColor_.Initialize();
	color_ = {1, 1, 0, 1};

}

void Particle::Update() { 
	worldTransform_.TransferMatrix(); 

}

void Particle::Draw(Camera& camera) { 
	model_->Draw(worldTransform_, camera);

}
