#pragma once

#include "Game.h"

class Verifier {

public:

	static bool Intersect(Point center, float halfWidth, float halfHeight,
		Point circleCenter, float circleRadius);
	static bool BombHit(Bomb bomb, Explosion explosion);
	static bool BuildingHit(Building building, Explosion explosion);
	static bool LauncherHit(Launcher launcher, Explosion explosion);
	static bool GameLost(Launcher launcher, std::list<Building> buildings);
};

