#pragma once

#include "Point.h"
#include "Globals.h"

/// <summary>description</summary>
class Building {

	Point center;
	float hp;
	int index;

public:

	Building();
	Building(Point center, int index);

	Point GetCenter();
	float GetHP();
	int GetIndex();

	bool operator==(const Building& b) const;

	void ReceiveDamage(float damage);
};

