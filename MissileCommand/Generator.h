#pragma once

#define _USE_MATH_DEFINES

#include <random>
#include <list>
#include "Game.h"
#include "Bomb.h"

class Generator {

	static std::random_device device;
	static std::mt19937 generator;

public:

	static float GetRandomUniform(float min, float max);
	static float GetRandomNormal(float min, float max);
	static std::list<Bomb> GenerateBombs(int count);
};

