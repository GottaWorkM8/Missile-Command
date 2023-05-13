#pragma once

#include "Point.h"

class Building {

	Point center;
	float hp;

public:

	Building();
	Building(Point center, float hp);

	Point GetCenter();
	float GetHP();

	bool operator==(const Building& b) const;
};

