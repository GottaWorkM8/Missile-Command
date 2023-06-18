#pragma once

#include "Point.h"
#include "Globals.h"

/// <summary>
/// Class representing every building in the game
/// </summary>
class Building {

	Point center;
	float hp;
	int index;

public:

	Building();
	Building(Point center, int index);

	// Returns the center point of the building
	Point GetCenter();
	// Returns the current amount of health points of the building
	float GetHP();
	// Returns the position on the map [0-7] of the building
	int GetIndex();

	bool operator==(const Building& b) const;

	// Subtracts building health points by the amount given as an argument
	void ReceiveDamage(float damage);
};

