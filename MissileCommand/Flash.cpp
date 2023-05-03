#include "Flash.h"

Flash::Flash() {

}

Flash::Flash(Point center, float radius, float angleRad) {

	this->center = center;
	this->radius = radius;
	this->angleRad = angleRad;
	this->angleDeg = Calculator::GetDegrees(angleRad);
	this->stage = 0;
	this->stageTimer = Timer();
}

float& Flash::GetRadius() {
	return radius;
}

void Flash::SetRadius(float& radius) {
	this->radius = radius;
}

int& Flash::GetStage() {
	return stage;
}

Timer& Flash::GetStageTimer() {
	return stageTimer;
}
