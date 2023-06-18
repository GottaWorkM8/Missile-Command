#pragma once

#include "Item.h"
#include "Globals.h"

/// <summary>
/// Class representing the missile launcher present in every game
/// </summary>
class Launcher : public Item {

	float hp;
	bool destroyed;

public:

	Launcher();
	Launcher(Point center);

	// Returns the current amount of health points of the launcher
	float& GetHP();
	// Returns the boolean telling if the launcher has already been destroyed
	bool IsDestroyed();
	// Sets the boolean telling if the launcher has already been destroyed
	void SetDestroyed(bool destroyed);

	// Sets the tilt angle of the launcher cannon to the value given as an argument
	void SetAngle(float angleRad);
	// Subtracts launcher health points by the amount given as an argument
	void ReceiveDamage(float damage);
};

