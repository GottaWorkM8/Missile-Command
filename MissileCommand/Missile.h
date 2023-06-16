#pragma once

#include "Item.h"

/// <summary>description</summary>
class Missile : public Item {

	Point target;

public: 

	Missile();
	Missile(Point center, Point target, float angleRad);

	Point& GetTarget();
};

