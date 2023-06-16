#pragma once

#define _USE_MATH_DEFINES

#include <random>
#include <list>
#include <cmath>
#include "Globals.h"
#include "Bomb.h"
#include "Explosion.h"

/// <summary>description</summary>
class Generator {

	static std::random_device device;
	static std::mt19937 generator;

public:

	static int GetRandomUniform(int min, int max);
	static float GetRandomUniform(float min, float max);
	static float GetRandomNormal(float min, float max);
	static Bomb GenerateBomb(Source source);
	static Bomb GenerateBomblet(Explosion& clusterExplosion);
};

