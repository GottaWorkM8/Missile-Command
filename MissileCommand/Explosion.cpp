#include "Explosion.h"

Explosion::Explosion() {

}

Explosion::Explosion(Point center, float radius, Source source) {

	this->center = center;
	this->radius = radius;
	this->stage = 0;
	this->stageTimer = Timer();
	this->source = source;
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

Source& Explosion::GetSource() {
	return source;
}

bool Explosion::operator==(const Explosion& e) const {

	return this->center == e.center && this->radius == e.radius && 
		this->stage == e.stage && this->source == e.source;
}
