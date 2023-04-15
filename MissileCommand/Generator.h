#pragma once

#define _USE_MATH_DEFINES

#include <random>
#include <list>
#include "Game.h"
#include "Bomb.h"

class Generator {

public:

	static std::list<Bomb> GenerateBombs(int count);
};

