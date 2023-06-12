#include "Building.h"

Building::Building() {

	center = Point(0, 0);
	hp = Globals::BUILDING_HP;
	index = 0;
}

Building::Building(Point center, int index) {

	this->center = center;
	this->hp = Globals::BUILDING_HP;
	this->index = index;
}

Point Building::GetCenter() {
	return center;
}

float Building::GetHP() {
	return hp;
}

int Building::GetIndex() {
	return index;
}

bool Building::operator==(const Building& b) const {

	return this->center == b.center && this->hp == hp;
}

void Building::ReceiveDamage(float damage) {

	hp -= damage;
}
