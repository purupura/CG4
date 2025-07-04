#pragma once
#include <KamataEngine.h>

using namespace KamataEngine;
class TitleScene {

	public:
	~TitleScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	bool IsGameFinished() const { return isGameFinished_; }

	private:
	bool isGameFinished_ = false; // ゲーム終了フラグ

	uint32_t textureHandle_ = 0;   
	Sprite* titleSprite_ = nullptr; // タイトル画面の画像
	Input* input_ = nullptr;
	DirectXCommon* dxCommon_ = nullptr;
};
