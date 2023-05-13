#pragma once

#include "Item.h"
#include "Timer.h"

class Flash : public Item {

	float radius;
	int stage;
	Timer stageTimer;

public:

	Flash();
	Flash(Point center, float radius, float angleRad);

	float& GetRadius();
	void SetRadius(float& radius);
	int& GetStage();
	Timer& GetStageTimer();
};

