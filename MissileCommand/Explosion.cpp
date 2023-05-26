#include "Explosion.h"

Explosion::Explosion() {

	center = Point(0, 0);
	angleRad = 0;
	angleDeg = Calculator::GetDegrees(angleRad);
	radius = 10.0f;
	stage = 0;
	stageTimer = Timer();
	source = NORMAL;
	bombsHit = {};
	buildingsHit = {};
	launcherHit = false;
}

Explosion::Explosion(Point center, float radius, Source source) {

	this->center = center;
	angleRad = 0;
	angleDeg = Calculator::GetDegrees(angleRad);
	this->radius = radius;
	stage = 0;
	stageTimer = Timer();
	this->source = source;
	bombsHit = {};
	buildingsHit = {};
	launcherHit = false;
}

void Explosion::SetAngleRad(float& angleRad) {
	this->angleRad = angleRad;
}

void Explosion::SetAngleDeg(float& angleDeg) {
	this->angleDeg = angleDeg;
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

std::list<Bomb>& Explosion::GetBombsHit() {
	return bombsHit;
}

void Explosion::SetBombsHit(std::list<Bomb>& bombsHit) {
	this->bombsHit = bombsHit;
}

std::list<Building>& Explosion::GetBuildingsHit() {
	return buildingsHit;
}

void Explosion::SetBuildingsHit(std::list<Building>& buildingsHit) {
	this->buildingsHit = buildingsHit;
}

bool& Explosion::IsLauncherHit() {
	return launcherHit;
}

void Explosion::SetLauncherHit(bool& launcherHit) {
	this->launcherHit = launcherHit;
}

bool Explosion::operator==(const Explosion& e) const {

	return this->center == e.center && this->radius == e.radius &&
		this->stage == e.stage && this->source == e.source;
}
