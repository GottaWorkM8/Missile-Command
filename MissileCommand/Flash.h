#pragma once

#include "Item.h"
#include "Timer.h"

/// <summary>
/// Class representing every flash after the missile shot in the game
/// </summary>
class Flash : public Item {

	float radius;
	int stage;
	Timer stageTimer;

public:

	Flash();
	Flash(Point center, float radius, float angleRad);

	// Returns the current size of the flash
	float& GetRadius();
	// Sets the current size of the flash
	void SetRadius(float& radius);
	// Returns the current stage of the flash
	int& GetStage();
	// Returns the stage timer keeping track of the time before the next stage
	Timer& GetStageTimer();
};

