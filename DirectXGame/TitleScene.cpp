#include "TitleScene.h"
TitleScene::~TitleScene() {
	delete titleSprite_;
}

void TitleScene::Initialize() {
	dxCommon_ = KamataEngine::DirectXCommon::GetInstance();
	input_ = KamataEngine::Input::GetInstance();

	textureHandle_ = KamataEngine::TextureManager::Load("title.png");
	titleSprite_ = new KamataEngine::Sprite();
	titleSprite_ = Sprite::Create(textureHandle_, {0, 0});
}

void TitleScene::Update() { 
	if (input_->TriggerKey(DIK_SPACE)) {
		isGameFinished_ = true;
	}

}

void TitleScene::Draw() {
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Sprite::PreDraw(dxCommon->GetCommandList());
	titleSprite_->Draw();
	Sprite::PostDraw();
}