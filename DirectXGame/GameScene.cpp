#include "GameScene.h"

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

	for (int i = 0; i < 10; i++) {
		
		Effect* effect = new Effect();

		Vector3 position = {0.0f, 0.0f, 0.0f};

		effect->Initialize(modelEffect_, position);

		effects_.push_back(effect);

	}

	camera_.Initialize();

}

void GameScene::Update() { 
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