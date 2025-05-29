#include "GameScene.h"

using namespace KamataEngine;

GameScene::~GameScene() {
	delete modelEffect_;
	delete effect_;

	Model2::StaticFinalize();
}

void GameScene::Initialize() {
	Model2::StaticInitialize();
	modelEffect_ = Model2::Model2::CreateFromOBJ("diamond", true);

	effect_ = new Effect();


	effect_->Initialize(modelEffect_);

	camera_.Initialize();

	

}

void GameScene::Update() { effect_->Update(); }

void GameScene::Draw() {

	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Model2::PreDraw(dxCommon->GetCommandList());

	effect_->Draw(camera_);

	Model2::PostDraw();
}