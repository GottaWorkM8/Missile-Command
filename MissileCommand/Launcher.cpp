#include "Launcher.h"

Launcher::Launcher() {

}

Launcher::Launcher(Point center, float angle) {

	this->center = center;
	this->angle = angle;
}

Point Launcher::GetCenter() {
	return center;
}

float Launcher::GetAngle() {
	return angle;
}