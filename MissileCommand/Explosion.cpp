#include "Explosion.h"

Explosion::Explosion() {

}

Explosion::Explosion(Point center, float radius, float duration) {

	this->center = center;
	this->radius = radius;
	this->duration = duration;
}

float& Explosion::GetRadius() {
	return radius;
}

float& Explosion::GetDuration() {
	return duration;
}

bool Explosion::operator==(const Explosion& e) const {

	return this->center == e.center && this->radius == e.radius && this->duration == e.duration;
}
