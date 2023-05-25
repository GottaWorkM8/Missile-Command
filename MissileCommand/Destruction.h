#pragma once

#include "Item.h"
#include "Timer.h"

class Destruction : public Item {

	float radius;
	int stage;
	Timer stageTimer;

public:

	Destruction();
	Destruction(Point center, float radius);

	void SetAngleRad(float& angleRad);
	void SetAngleDeg(float& angleDeg);
	float& GetRadius();
	void SetRadius(float& radius);
	int& GetStage();
	Timer& GetStageTimer();
};

