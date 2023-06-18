#pragma once

#include "Globals.h"
#include "ItemManager.h"

/// <summary>
/// Class responsible for processing data in order to pass a judgement (true or false)
/// </summary>
class Verifier {

public:

	// Returns the boolean telling if the given point is within the boundaries of the given rectangle
	static bool Within(Point point, Point center, float halfWidth, float halfHeight);
	// Returns the boolean telling if the given point is within the boundaries of the given rectangle
	static bool WithinAlt(Point point, Point topLeft, float width, float height);
	// Returns the boolean telling if the given rectangle intersects with the given circle 
	static bool Intersect(Point center, float halfWidth, float halfHeight,
		Point circleCenter, float circleRadius);
	// Returns the boolean telling if the two given float values are too close to each other 
	// (meaning the absolute difference between the two is smaller than minGap provided)
	static bool TooClose(float value1, float value2, float minGap);
	// Returns the boolean telling if the given launcher is within the current range of the given explosion
	static bool LauncherInRange(Launcher& launcher, Explosion& explosion);
	// Returns the boolean telling if the given building is within the current range of the given explosion
	static bool BuildingInRange(Building& building, Explosion& explosion);
	// Returns the boolean telling if the given bomb is within the current range of the given explosion
	static bool BombInRange(Bomb& bomb, Explosion& explosion);
	// Returns the boolean telling if the given building is present on the provided list of buildings
	static bool BuildingOnTheList(Building& building, std::list<Building*>& buildings);
	// Returns the boolean telling if the given bomb is present on the provided list of bombs
	static bool BombOnTheList(Bomb& bomb, std::list<Bomb*>& bombs);
	// Returns the boolean telling if the conditions to lose the game have been met
	static bool GameLost(Launcher& launcher, std::list<Building>& buildings);
	// Returns the boolean telling if the conditions to win the game have been met
	static bool GameWon(std::list<Bomb>& bombs, float time);
	// Returns the boolean telling if the given difficulty is a valid one (is in the valid range of values)
	static bool ValidLevel(int difficulty);
	// Returns the boolean telling if the given score is a valid one (is in the valid range of values)
	static bool ValidScore(int score);
};

