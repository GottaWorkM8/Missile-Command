#include "Point.h"

Point::Point() {

	this->x = 0.0f;
	this->y = 0.0f;
}

Point::Point(float x, float y) {

	this->x = x;
	this->y = y;
}

bool Point::operator==(const Point& p) const {

	return this->x == p.x && this->y == p.y;
}