#pragma once

#include "Item.h"

class Missile : public Item {

	Point target;

public: 

	Missile();
	Missile(Point center, Point target, float angleRad);

	Point& GetTarget();
};

