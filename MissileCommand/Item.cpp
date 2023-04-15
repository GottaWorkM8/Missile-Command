#include "Item.h"

Item::Item() {

}

Item::Item(Point center, float angleRad) {

	this->center = center;
	this->angleRad = angleRad;
	this->angleDeg = Calculator::GetDegrees(angleRad);
}

Point& Item::GetCenter() {
	return center;
}

void Item::SetCenter(Point center) {
	this->center = center;
}

float& Item::GetAngleRad() {
	return angleRad;
}

float& Item::GetAngleDeg() {
	return angleDeg;
}

bool Item::operator==(const Item& b) const {

	return this->center == b.center && this->angleRad == b.angleRad;
}

bool Item::operator!=(const Item& b) const {

	return !operator==(b);
}

