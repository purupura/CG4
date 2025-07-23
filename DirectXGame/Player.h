#pragma once
#include "kamataEngine.h"
#include <assert.h>
#include "Model2.h"

using namespace KamataEngine;

class Player {
public:
	void Initialize(Model2* model);

	void Update();

	void Draw(Camera& camera);

private:
	WorldTransform worldTransform_;

	Model2* model_ = nullptr;

	Input* input_ = nullptr;

};
