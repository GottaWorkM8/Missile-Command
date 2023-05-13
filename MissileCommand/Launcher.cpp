#include "Launcher.h"

Launcher::Launcher() {

}

Launcher::Launcher(Point center, float angleRad, float hp) {

	this->center = center;
	this->angleRad = angleRad;
	this->angleDeg = Calculator::GetDegrees(angleRad);
	this->hp = hp;
}

float& Launcher::GetHP() {
	return hp;
}

void Launcher::SetAngle(float angleRad) {

	this->angleRad = angleRad;
	this->angleDeg = Calculator::GetDegrees(angleRad);
}

