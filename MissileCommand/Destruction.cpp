#include "Destruction.h"

Destruction::Destruction() {

	center = Point(0, 0);
	angleRad = 0;
	angleDeg = Calculator::GetDegrees(angleRad);
	radius = 10.0f;
	stage = 0;
	stageTimer = Timer();
}

Destruction::Destruction(Point center, float radius) {

	this->center = center;
	angleRad = 0;
	angleDeg = Calculator::GetDegrees(angleRad);
	this->radius = radius;
	stage = 0;
	stageTimer = Timer();
}

void Destruction::SetAngleRad(float& angleRad) {
	this->angleRad = angleRad;
}

void Destruction::SetAngleDeg(float& angleDeg) {
	this->angleDeg = angleDeg;
}

float& Destruction::GetRadius() {
	return radius;
}

void Destruction::SetRadius(float& radius) {
	this->radius = radius;
}

int& Destruction::GetStage() {
	return stage;
}

Timer& Destruction::GetStageTimer() {
	return stageTimer;
}
