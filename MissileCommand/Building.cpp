#include "Building.h"

Building::Building() {

}

Building::Building(Point center, float hp) {

	this->center = center;
	this->hp = hp;
}

Point Building::GetCenter() {
	return center;
}

float Building::GetHP() {
	return hp;
}

bool Building::operator==(const Building& b) const {

	return this->center == b.center && this->hp == hp;
}
