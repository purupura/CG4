#include "GameScene.h"
#include "TitleScene.h"
#include "KamataEngine.h"
#include <Windows.h>

using namespace KamataEngine;

enum class Scene {

	kUnknown = 0,

	kTitle, // タイトルシーン
	kGame,  // ゲームシーン

};

TitleScene* titleScene = nullptr; // タイトルシーンのポインタ

GameScene* gameScene = nullptr; // ゲームシーンのポインタ

Scene scene = Scene::kUnknown; // 現在のシーンを表す変数

void UpdateScene();
void DrawScene();
void ChangeScene();

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	// エンジンの初期化
	KamataEngine::Initialize(L"LE3D_05_カラサワ_ミクム_CG4");
	// DirectXCommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();


	// ゲームシーンの初期化
	gameScene = new GameScene();
	gameScene->Initialize();

	// タイトルシーンの初期化
	titleScene = new TitleScene();
	titleScene->Initialize();

	// シーンをタイトルシーンに設定
	scene = Scene::kTitle;

	// メインループ
	while (true) {
		// エンジンの更新
		if (KamataEngine::Update()) {
			break;
		}

		// シーンの更新と切り替え
		UpdateScene();
		ChangeScene();

		// 描画開始
		dxCommon->PreDraw();

		// シーンの描画
		DrawScene();

		// 描画終了
		dxCommon->PostDraw();
	}
	delete gameScene;
	delete titleScene;

	// nullptrの代入
	gameScene = nullptr;

	// 更新の終了処理
	KamataEngine::Finalize();

	return 0;
}

void UpdateScene() {
	switch (scene) {
	case Scene::kTitle:
		titleScene->Update();
		break;

	case Scene::kGame:
		gameScene->Update();
		break;
	}
}

void DrawScene() {
	switch (scene) {
	case Scene::kTitle:
		titleScene->Draw();
		break;

	case Scene::kGame:
		gameScene->Draw();
		break;
	}

}

void ChangeScene() {
	switch (scene) {
	case Scene::kTitle:
		if (titleScene && titleScene->IsGameFinished()) {
			delete titleScene;
			titleScene = nullptr;
			scene = Scene::kGame;
			gameScene = new GameScene();
			gameScene->Initialize();
		}
		break;

	case Scene::kGame:
		if (gameScene && gameScene->IsFinished()) {
			delete gameScene;
			gameScene = nullptr;
			scene = Scene::kTitle;
			titleScene = new TitleScene();
			titleScene->Initialize();
		}
		break;
	}
}
