#include "Bomb.h"

Bomb::Bomb() {

	center = Point(0, 0);
	angleRad = 0;
	source = NORMAL;
}

Bomb::Bomb(Point center, float angleRad, Source source) {

	this->center = center;
	this->angleRad = angleRad;
	this->angleDeg = Calculator::GetDegrees(angleRad);
	this->source = source;
}

Source& Bomb::GetSource() {
	return source;
}
