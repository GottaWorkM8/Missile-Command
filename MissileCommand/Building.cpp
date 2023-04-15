#include "Building.h"

Building::Building() {

}

Building::Building(Point center) {

	this->center = center;
}

Point Building::GetCenter() {
	return center;
}

bool Building::operator==(const Building& b) const {

	return this->center == b.center;
}
