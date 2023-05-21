#pragma once

#define _USE_MATH_DEFINES

#include <random>
#include <list>
#include "Globals.h"
#include "Bomb.h"

class Generator {

	static std::random_device device;
	static std::mt19937 generator;

public:

	static float GetRandomUniform(float min, float max);
	static float GetRandomNormal(float min, float max);
	static Bomb GenerateBomb(Source source);
	static std::list<Bomb> GenerateBombs(Source source, int count);
};

