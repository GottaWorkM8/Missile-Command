#include "Explosion.h"

Explosion::Explosion() {

	center = Point(0, 0);
	angleRad = 0;
	angleDeg = Calculator::GetDegrees(angleRad);
	radius = 10.0f;
	stage = 0;
	stageTimer = Timer();
	source = NORMAL;
}

Explosion::Explosion(Point center, float radius, Source source) {

	this->center = center;
	this->angleRad = 0;
	this->angleDeg = Calculator::GetDegrees(angleRad);
	this->radius = radius;
	this->stage = 0;
	this->stageTimer = Timer();
	this->source = source;
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

Source& Explosion::GetSource() {
	return source;
}

bool Explosion::operator==(const Explosion& e) const {

	return this->center == e.center && this->radius == e.radius &&
		this->stage == e.stage && this->source == e.source;
}
