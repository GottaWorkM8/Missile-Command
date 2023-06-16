#pragma once

#include "Item.h"
#include "Timer.h"

/// <summary>description</summary>
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

