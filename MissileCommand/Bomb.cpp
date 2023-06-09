#include "Bomb.h"

Bomb::Bomb() {

	center = Point(0, 0);
	angleRad = 0;
	source = NORMAL;
	hp = Globals::NORMAL_BOMB_HP;
}

Bomb::Bomb(Point center, float angleRad, Source source) {

	this->center = center;
	this->angleRad = angleRad;
	this->angleDeg = Calculator::GetDegrees(angleRad);
	this->source = source;

	switch (source) {

		case NORMAL: this->hp = Globals::NORMAL_BOMB_HP;
			break;

		case NUCLEAR: this->hp = Globals::NUCLEAR_BOMB_HP;
			break;

		case CLUSTER: this->hp = Globals::CLUSTER_BOMB_HP;
			break;

		case NAPALM: this->hp = Globals::NAPALM_BOMB_HP;
			break;

		case RODOFGOD: this->hp = Globals::ROD_BOMB_HP;
			break;

		default: this->hp = Globals::NORMAL_BOMB_HP;
			break;
	}
}

Source& Bomb::GetSource() {
	return source;
}

float Bomb::GetHP() {
	return hp;
}

bool Bomb::operator==(const Bomb& b) const {

	return this->center == b.center && this->angleRad == b.angleRad && this->source == b.source && this->hp == hp;
}

void Bomb::ReceiveDamage(float damage) {

	hp -= damage;
}
