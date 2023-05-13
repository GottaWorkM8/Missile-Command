#pragma once

#include "Point.h"
#include "Timer.h"
#include "Source.h"

class Explosion {

	Point center;
	float radius;
	int stage;
	Timer stageTimer;
	Source source;

public:

	Explosion();
	Explosion(Point center, float radius, Source source);

	Point& GetCenter();
	float& GetRadius();
	void SetRadius(float& radius);
	int& GetStage();
	Timer& GetStageTimer();
	Source& GetSource();

	bool operator==(const Explosion& e) const;
};

