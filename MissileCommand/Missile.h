#pragma once

#include "Item.h"

/// <summary>
/// Class representing every missile in the game
/// </summary>
class Missile : public Item {

	Point target;

public: 

	Missile();
	Missile(Point center, Point target, float angleRad);

	// Returns the point being the final destination of the missile, i.e. point where it explodes
	Point& GetTarget();
};

