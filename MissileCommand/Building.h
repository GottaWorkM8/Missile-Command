#pragma once

#include "Point.h"

class Building {

	Point center;

public:

	Building();
	Building(Point center);

	Point GetCenter();

	bool operator==(const Building& b) const;
};

