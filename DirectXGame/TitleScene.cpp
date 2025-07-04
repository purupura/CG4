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

	textureHandle2_ = KamataEngine::TextureManager::Load("PUSH.png");
	PushSprite_ = new KamataEngine::Sprite();
	PushSprite_ = Sprite::Create(textureHandle2_, {0, 0});
}

void TitleScene::Update() { 
	pushTimer_--;
	if (input_->TriggerKey(DIK_SPACE)) {
		isGameFinished_ = true;
	}

	if(pushTimer_ == 0) {
		pushTimer_ = 120; 
	}
}

void TitleScene::Draw() {
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Sprite::PreDraw(dxCommon->GetCommandList());
	titleSprite_->Draw();
	if (pushTimer_ > 60) {
		PushSprite_->Draw();
	}

	Sprite::PostDraw();
}