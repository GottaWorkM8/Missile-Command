#pragma once

#include "Item.h"
#include "Timer.h"

/// <summary>
/// Class representing every structure collapse, i.e. destruction of the launcher or any building
/// </summary>
class Destruction : public Item {

	float radius;
	int stage;
	Timer stageTimer;

public:

	Destruction();
	Destruction(Point center, float radius);

	// Sets the rotation angle in radians and degrees to the value given as an argument
	void SetAngleRad(float& angleRad);
	// Sets the rotation angle in radians and degrees to the value given as an argument
	void SetAngleDeg(float& angleDeg);
	// Returns the current size of the destruction
	float& GetRadius();
	// Sets the current size of the destruction
	void SetRadius(float& radius);
	// Returns the current stage of the destruction
	int& GetStage();
	// Returns the stage timer keeping track of the time before the next stage
	Timer& GetStageTimer();
};

