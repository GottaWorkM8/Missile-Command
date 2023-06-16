#pragma once

#include "Point.h"
#include "Calculator.h"

/// <summary>description</summary>
class Item {

protected:

	Point center;
	float angleRad;
	float angleDeg;

public:

	Item();
	Item(Point center, float angleRad);

	Point& GetCenter();
	void SetCenter(Point center);
	float& GetAngleRad();
	float& GetAngleDeg();

	bool operator==(const Item& b) const;
	bool operator!=(const Item& b) const;
};

