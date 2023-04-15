#pragma once

#include "Point.h"

class Launcher {

	Point center;
	float angle;

public:

	Launcher();
	Launcher(Point center, float angle);

	Point GetCenter();
	float GetAngle();
};

