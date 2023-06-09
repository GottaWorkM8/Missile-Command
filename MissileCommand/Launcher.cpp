#include "Launcher.h"

Launcher::Launcher() {

	center = Point(0, 0);
	angleRad = 0;
	hp = Globals::LAUNCHER_HP;
	destroyed = false;
}

Launcher::Launcher(Point center) {

	this->center = center;
	angleRad = 0;
	angleDeg = Calculator::GetDegrees(angleRad);
	hp = Globals::LAUNCHER_HP;
	destroyed = false;
}

float& Launcher::GetHP() {
	return hp;
}

bool Launcher::IsDestroyed() {
	return destroyed;
}

void Launcher::SetDestroyed(bool destroyed) {
	this->destroyed = destroyed;
}

void Launcher::SetAngle(float angleRad) {

	this->angleRad = angleRad;
	this->angleDeg = Calculator::GetDegrees(angleRad);
}

void Launcher::ReceiveDamage(float damage) {

	hp -= damage;
}

