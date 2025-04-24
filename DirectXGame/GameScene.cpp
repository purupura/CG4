#include "GameScene.h"
#include <random>

using namespace KamataEngine;
using namespace MathUtility;
std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);

GameScene::~GameScene() { 
	delete modelParticle_; 
	
	for (Particle* particle : particles_) {
		delete particle;
	}
	particles_.clear();
}

void GameScene::Initialize() { 
	srand((unsigned)time(NULL));

}

void GameScene::Update() { 
	if (rand() % 20 == 0) {
		Vector3 position = {distribution(randomEngine) * 30.0f, distribution(randomEngine) * 20.0f, 0};
		ParticleBorn(position);
	}


	for (Particle* particle : particles_) {
		particle->Update();
	}
	particles_.remove_if([](Particle* particle) {
		if (particle->IsFinished()) {
			delete particle;
			return true;
		}
		return false;
	});
}

void GameScene::Draw() { 
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();
	
	Model::PreDraw(dxCommon->GetCommandList());

	for (Particle* particle : particles_) {
		particle->Draw(camera_); 
	}
	

	Model::PostDraw();

}

void GameScene::ParticleBorn(Vector3 position) {
	modelParticle_ = Model::CreateSphere(4, 4);

	camera_.Initialize();
	for (int i = 0; i < 150; i++) {
		Particle* particle = new Particle();
	

		Vector3 position_ = {0.0f, 0.0f, 0.0f};
		
		position_ = position;

		Vector3 velocity = {distribution(randomEngine), distribution(randomEngine), 0};

		Normalize(velocity);
		velocity *= distribution(randomEngine);
		velocity *= 0.1f;

		particle->Initialize(modelParticle_, position_, velocity);

		particles_.push_back(particle);
	}

}
