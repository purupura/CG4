#pragma once
#include <KamataEngine.h>

using namespace KamataEngine;
class Effect {
public:
	void Initialize(Model* model,Vector3 position);

	void Update();

	void Draw(Camera& camera);

	bool IsFinished() { return isFinished; }

private:
	WorldTransform worldTransform_;

	Model* model_ = nullptr;

	ObjectColor objectColor_;

	Vector4 color_;

	bool isFinished = false;

	float counter_ = 0.0f;

	const float kDuration = 1.0f;
};