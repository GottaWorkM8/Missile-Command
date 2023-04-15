#include "Propagation.h"

Propagation::Propagation() {

}

Propagation::Propagation(int stages) {

	this->stages = stages;
}

bool Propagation::operator==(const Propagation& p) const {

	return this->stages == p.stages;
}
