#pragma once

#include "Globals.h"
#include "ItemManager.h"

class Verifier {

public:

	static bool Within(Point point, Point center, float halfWidth, float halfHeight);
	static bool WithinAlt(Point point, Point topLeft, float width, float height);
	static bool Intersect(Point center, float halfWidth, float halfHeight,
		Point circleCenter, float circleRadius);
	static bool BombHit(Bomb bomb, Explosion explosion);
	static bool BuildingHit(Building building, Explosion explosion);
	static bool LauncherHit(Launcher launcher, Explosion explosion);
	static bool GameLost(Launcher launcher, std::list<Building> buildings);
};

