#include "Explosion.h"

Explosion::Explosion() {

}

Explosion::Explosion(Point center, float radius) {

	this->center = center;
	this->radius = radius;
	this->stage = 1;
	this->stageTimer = Timer();
}

Point& Explosion::GetCenter() {
	return center;
}

float& Explosion::GetRadius() {
	return radius;
}

void Explosion::SetRadius(float& radius) {
	this->radius = radius;
}

int& Explosion::GetStage() {
	return stage;
}

Timer& Explosion::GetStageTimer() {
	return stageTimer;
}

bool Explosion::operator==(const Explosion& e) const {

	return this->center == e.center && this->radius == e.radius && this->stage == e.stage;
}
