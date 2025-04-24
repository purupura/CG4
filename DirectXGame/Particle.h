#pragma once
#include <KamataEngine.h>

using namespace KamataEngine;
class Particle {
public:

void Initialize(Model*model,Vector3 position);

void Update();

void Draw(Camera& camera);

private:
WorldTransform worldTransform_;

	Model* model_ = nullptr;

	ObjectColor objectColor_;

	Vector4 color_;

};
