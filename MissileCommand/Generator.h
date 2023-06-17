#pragma once

#define _USE_MATH_DEFINES

#include <random>
#include <list>
#include <cmath>
#include "Globals.h"
#include "Bomb.h"
#include "Explosion.h"

/// <summary>
/// Class responsible for introducing randomness to the game as well as generating bombs/bomblets present in every game
/// </summary>
class Generator {

	static std::random_device device;
	static std::mt19937 generator;

public:

	// Returns random integer value of uniform distribution between given minimum and maximum values (min and max included)
	static int GetRandomUniform(int min, int max);
	// Returns random float value of uniform distribution between given minimum and maximum values (min included, max not included)
	static float GetRandomUniform(float min, float max);
	// Returns random float value of normal (Gaussian) distribution between given minimum and maximum values (min included, max not included)
	static float GetRandomNormal(float min, float max);
	// Returns a single bomb of the given type with random spawn and target points
	static Bomb GenerateBomb(Source source);
	// Returns a single bomblet (cluster bomb spawn) of the given type with a random target point
	static Bomb GenerateBomblet(Explosion& clusterExplosion);
};

