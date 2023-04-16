#pragma once

#include "Propagation.h"
#include "Point.h"
#include "Timer.h"

class Explosion {

	Point center;
	float radius;
	int stage;
	Timer stageTimer;

public:

	Explosion();
	Explosion(Point center, float radius);

	Point& GetCenter();
	float& GetRadius();
	void SetRadius(float& radius);
	int& GetStage();
	Timer& GetStageTimer();

	bool operator==(const Explosion& e) const;
};

