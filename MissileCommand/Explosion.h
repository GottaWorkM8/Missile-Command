#pragma once

#include "Propagation.h"
#include "Point.h"

class Explosion {

	Point center;
	float radius;
	float duration;

public:

	Explosion();
	Explosion(Point center, float radius, float duration);

	float& GetRadius();
	float& GetDuration();

	bool operator==(const Explosion& e) const;
};

