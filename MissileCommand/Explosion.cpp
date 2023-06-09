#include "Explosion.h"

Explosion::Explosion() {

	center = Point(0, 0);
	angleRad = 0;
	angleDeg = Calculator::GetDegrees(angleRad);
	radius = 10.0f;
	damage = Globals::NORMAL_BOMB_DAMAGE;
	stage = 0;
	stageTimer = Timer();
	source = NORMAL;
	launcherHit = false;
	buildingsHit = {};
	bombsHit = {};
}

Explosion::Explosion(Point center, float radius, Source source) {

	this->center = center;
	angleRad = 0;
	angleDeg = Calculator::GetDegrees(angleRad);
	this->radius = radius;

	switch (source) {

		case MISSILE: damage = Globals::MISSILE_DAMAGE;
			break;

		case NORMAL: damage = Globals::NORMAL_BOMB_DAMAGE;
			break;

		case NUCLEAR: damage = Globals::NUCLEAR_BOMB_DAMAGE;
			break;

		case CLUSTER: damage = Globals::BOMBLET_DAMAGE;
			break;

		case NAPALM: damage = Globals::NAPALM_BOMB_DAMAGE;
			break;

		case RODOFGOD: damage = Globals::ROD_BOMB_DAMAGE;
			break;

		default: damage = Globals::NORMAL_BOMB_DAMAGE;
			break;
	}

	stage = 0;
	stageTimer = Timer();
	this->source = source;
	launcherHit = false;
	buildingsHit = {};
	bombsHit = {};
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

float& Explosion::GetDamage() {
	return damage;
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

bool Explosion::IsLauncherHit() {
	return launcherHit;
}

void Explosion::SetLauncherHit(bool launcherHit) {
	this->launcherHit = launcherHit;
}

std::list<Building>& Explosion::GetBuildingsHit() {
	return buildingsHit;
}

void Explosion::SetBuildingsHit(std::list<Building>& buildingsHit) {
	this->buildingsHit = buildingsHit;
}

std::list<Bomb>& Explosion::GetBombsHit() {
	return bombsHit;
}

void Explosion::SetBombsHit(std::list<Bomb>& bombsHit) {
	this->bombsHit = bombsHit;
}

bool Explosion::operator==(const Explosion& e) const {

	return this->center == e.center && this->radius == e.radius &&
		this->stage == e.stage && this->source == e.source;
}
