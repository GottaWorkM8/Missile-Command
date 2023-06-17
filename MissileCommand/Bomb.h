#pragma once

#include "Item.h"
#include "Source.h"
#include "Globals.h"

/// <summary>
/// Class representing every bomb/bomblet in the game
/// </summary>
class Bomb : public Item {

	Source source;
	float hp;

public:

	Bomb();
	Bomb(Point center, float angleRad, Source source);

	// Returns the type of the bomb
	Source& GetSource();
	// Returns the current amount of health points of the bomb
	float GetHP();

	bool operator==(const Bomb& b) const;

	// Subtracts bomb health points by the amount given as an argument
	void ReceiveDamage(float damage);
};

