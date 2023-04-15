#pragma once

#define _USE_MATH_DEFINES

#include <cmath>
#include <random>
#include "Point.h"

class Calculator {

	static std::random_device device;
	static std::mt19937 generator;

public:

	static float GetRadians(Point point1, Point point2);
	static float GetRadians(float angleDeg);
	static float GetDegrees(float angleRad);
	static Point GetNextPos(Point point, float angleRad, float speed);
	static float GetRandomUniform(float min, float max);
	static float GetRandomNormal(float min, float max);
};

