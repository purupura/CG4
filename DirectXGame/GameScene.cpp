#include "GameScene.h"

using namespace KamataEngine;

GameScene::~GameScene() {
	delete modelEffect_;
	delete effect_;

	Model2::StaticFinalize();
}

void GameScene::Initialize() {
	dxCommon_ = KamataEngine::DirectXCommon::GetInstance();
	input_ = KamataEngine::Input::GetInstance();

	Model2::StaticInitialize();
	modelEffect_ = Model2::Model2::CreateFromOBJ("diamond", true);

	textureHandle_ = KamataEngine::TextureManager::Load("backGraund.png");
	backGroundSprite_ = new KamataEngine::Sprite();
	backGroundSprite_ = Sprite::Create(textureHandle_, {0.0f,0.0f});

	backGroundSprite2_ = new KamataEngine::Sprite();
	backGroundSprite2_ = Sprite::Create(textureHandle_, {1280.0f, 0.0f});

	effect_ = new Effect();


	effect_->Initialize(modelEffect_);

	camera_.Initialize();

	

}

void GameScene::Update() { 
	effect_->Update();
	if (input_->TriggerKey(DIK_SPACE)) {
		isFinished_ = true;
	}

	BackGroundUpdate();
}

void GameScene::Draw() {

	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Sprite::PreDraw(dxCommon->GetCommandList());

	backGroundSprite_->Draw();
	backGroundSprite2_->Draw();

	Sprite::PostDraw();

	dxCommon->ClearDepthBuffer();

	Model2::PreDraw(dxCommon->GetCommandList());

	effect_->Draw(camera_);

	Model2::PostDraw();


}

void GameScene::BackGroundUpdate() {
	Vector2 pos = backGroundSprite_->GetPosition();

	pos.x -= 1.0f;
	if (pos.x <= -1280) {
		pos.x = 1280.0f;
	}

	backGroundSprite_->SetPosition(pos);

	Vector2 pos2 = backGroundSprite2_->GetPosition();

	pos2.x -= 1.0f;
	if (pos2.x <= -1280) {
		pos2.x = 1280.0f;
	}
	backGroundSprite2_->SetPosition(pos2);
}