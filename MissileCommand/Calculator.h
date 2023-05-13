#pragma once

#define _USE_MATH_DEFINES

#include <cmath>
#include <random>
#include "Point.h"

class Calculator {

public:

	static float GetRadians(Point point1, Point point2);
	static float GetRadians(float angleDeg);
	static float GetDegrees(float angleRad);
	static Point GetNextPos(Point point, float angleRad, float speed);
	static Point GetPosBetween(Point point1, Point point2, float distance);
	static float GetDistanceSq(Point point1, Point point2);
	static float GetDistance(Point point1, Point point2);
};

