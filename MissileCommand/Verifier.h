#pragma once

#include "Globals.h"
#include "ItemManager.h"

class Verifier {

public:

	static bool Within(Point point, Point center, float halfWidth, float halfHeight);
	static bool WithinAlt(Point point, Point topLeft, float width, float height);
	static bool Intersect(Point center, float halfWidth, float halfHeight,
		Point circleCenter, float circleRadius);
	static bool TooClose(float value1, float value2, float minGap);
	static bool LauncherInRange(Launcher& launcher, Explosion& explosion);
	static bool BuildingInRange(Building& building, Explosion& explosion);
	static bool BombInRange(Bomb& bomb, Explosion& explosion);
	static bool BuildingOnTheList(Building& building, std::list<Building>& buildings);
	static bool BombOnTheList(Bomb& bomb, std::list<Bomb>& bombs);
	static bool GameLost(Launcher& launcher, std::list<Building>& buildings);
	static bool GameWon(std::list<Bomb>& bombs, float time, bool finished);
};

