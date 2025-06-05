#include "GameScene.h"
#include <cassert>

using namespace KamataEngine;

GameScene::~GameScene() {
	delete modelEffect_;
	delete effect_;

	Model2::StaticFinalize();
}

void GameScene::Initialize() {
	Model2::StaticInitialize();
	modelEffect_ = Model2::Model2::CreateSquare();

	effect_ = new Effect();


	effect_->Initialize(modelEffect_);

	camera_.Initialize();

	

}

void GameScene::Update() { effect_->Update(); }

void GameScene::Draw() {
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();
	if (!dxCommon) {
		// ここで nullptr なら即時エラー、初期化不足の可能性大
		assert(false && "DirectXCommon is nullptr!");
		return;
	}

	ID3D12GraphicsCommandList* cmdList = dxCommon->GetCommandList();
	if (!cmdList) {
		assert(false && "CommandList is nullptr!");
		return;
	}

	Model2::PreDraw(cmdList);

	effect_->Draw(camera_);

	Model2::PostDraw();
}
