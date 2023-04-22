#pragma once

#include "Game.h"

class Verifier {

public:

	static bool Intersect(Point center, float halfWidth, float halfHeight,
		Point circleCenter, float circleRadius);
	static bool IsBombHit(Bomb bomb, Explosion explosion);
	static bool IsBuildingHit(Building building, Explosion explosion);
	static bool IsLauncherHit(Launcher launcher, Explosion explosion);
};

