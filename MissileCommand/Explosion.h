#pragma once

#include "Item.h"
#include "Timer.h"
#include "Source.h"

class Explosion : public Item {

	float radius;
	int stage;
	Timer stageTimer;
	Source source;

public:

	Explosion();
	Explosion(Point center, float radius, Source source);

	void SetAngleRad(float& angleRad);
	void SetAngleDeg(float& angleDeg);
	float& GetRadius();
	void SetRadius(float& radius);
	int& GetStage();
	Timer& GetStageTimer();
	Source& GetSource();

	bool operator==(const Explosion& e) const;
};

