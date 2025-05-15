#include "GameScene.h"
#include <random>

std::random_device seedGenerator2;
std::mt19937 randomEngine2(seedGenerator2());
std::uniform_real_distribution<float> distribution2(-1.0f, 1.0f);

using namespace KamataEngine;

GameScene::~GameScene() {
	delete modelEffect_;
	for (Effect* effect : effects_) {
		delete effect;
	}
	effects_.clear();
}

void GameScene::Initialize() {
	modelEffect_ = Model::Model::CreateFromOBJ("diamond",true);

	srand((unsigned)time(NULL));

	camera_.Initialize();

}

void GameScene::Update() { 
		if (rand() % 10 == 0) {
		Vector3 position_ = {distribution2(randomEngine2) * 30.0f, distribution2(randomEngine2) * 20.0f, 0.0f};
		EffectBorn(position_);
	}

	for (Effect* effect : effects_) {
		effect->Update();
	}
	effects_.remove_if([](Effect* effect) {
		if (effect->IsFinished()) {
			delete effect;
			return true;
		}
		return false;
	});

}

void GameScene::Draw() {

	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Model::PreDraw(dxCommon->GetCommandList());

	for (Effect* effect : effects_) {
		effect->Draw(camera_);
	}

	Model::PostDraw();
}

void GameScene::EffectBorn(Vector3 position) {



	for (int i = 0; i < 10; i++) {

		Effect* effect = new Effect();

		Vector3 position_ = {0.0f, 0.0f, 0.0f};
		position_ = position;

		effect->Initialize(modelEffect_, position_);

		effects_.push_back(effect);
	}

}
