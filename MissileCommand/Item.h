#pragma once

#include "Point.h"
#include "Calculator.h"

/// <summary>
/// Class represents a basic item present in the game and is a base class for some object classes (Bomb, Destruction, Explosion, Flash, Launcher, Missile)
/// </summary>
class Item {

protected:

	Point center;
	float angleRad;
	float angleDeg;

public:

	Item();
	Item(Point center, float angleRad);

	// Returns the center point of the object
	Point& GetCenter();
	// Sets the center point of the object
	void SetCenter(Point center);
	// Returns the rotation angle of the object in radians
	float& GetAngleRad();
	// Returns the rotation angle of the object in degrees
	float& GetAngleDeg();
	bool operator==(const Item& b) const;
	bool operator!=(const Item& b) const;
};

