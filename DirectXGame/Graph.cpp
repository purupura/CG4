#include "Graph.h"

void Graph::Initialize() {
	dxCommon_ = KamataEngine::DirectXCommon::GetInstance();
	input_ = KamataEngine::Input::GetInstance();

	textureHandle_ = KamataEngine::TextureManager::Load("graphBack.png");

	graphSprite_ = Sprite::Create(textureHandle_, {10.0f, 10.0f});

	textureHandle2_ = KamataEngine::TextureManager::Load("graphFront.png");

	graphSprite2_ = Sprite::Create(textureHandle2_, {10.0f, 10.0f});


}

void Graph::Update() { 
	if (nowGraphGage < 0) {
		nowGraphGage = 1;
	}
	if (nowGraphGage==1) {
		nowGraphGage = 120;
	}
	nowGraphGage -= 1;
	Vector2 size2 = graphSprite_->GetSize();
	size2.x = 150;
	size2.y = 25;
	graphSprite_->SetSize(size2);

	Vector2 size = graphSprite2_->GetSize();
	size.x = nowGraphGage / maxGraphGage * width;
	size.y = 25;

	graphSprite2_->SetSize(size);

	Vector4 color = graphSprite2_->GetColor();
	color.w = 0.5f;
	graphSprite2_->SetColor(color);

	Vector4 color2 = graphSprite_->GetColor();
	color2.w = 0.5f;
	graphSprite_->SetColor(color2);
}

void Graph::Draw() { 
	graphSprite_->Draw();
	graphSprite2_->Draw();
}
