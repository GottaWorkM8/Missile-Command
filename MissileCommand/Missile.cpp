#include "Missile.h"

Missile::Missile() {

}

Missile::Missile(Point center, Point target, float angleRad) {

	this->center = center;
	this->target = target;
	this->angleRad = angleRad;
	this->angleDeg = Calculator::GetDegrees(angleRad);
}

Point& Missile::GetTarget() {
	return target;
}
