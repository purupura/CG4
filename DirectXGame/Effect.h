#pragma once
#include <KamataEngine.h>

using namespace KamataEngine;
class Effect {
public:
	void Initialize(Model* model);

	void Update();

	void Draw(Camera& camera);

private:
	WorldTransform worldTransform_;

	Model* model_ = nullptr;
};