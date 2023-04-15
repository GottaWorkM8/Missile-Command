#include "Point.h"

Point::Point() {

}

Point::Point(float x, float y) {

	this->x = x;
	this->y = y;
}

bool Point::operator==(const Point& p) const {

	return this->x == p.x && this->y == p.y;
}