#include "SummaryButton.h"

SummaryButton::SummaryButton() {

	space = 0;
	topLeft = Point();
	width = 0;
	height = 0;
	hovered = false;
	task = nullptr;
}

SummaryButton::SummaryButton(Point topLeft, float width, void (*task)()) {

	space = 10.0f;
	this->topLeft = topLeft;
	this->bottomRight = Point(topLeft.x + width, topLeft.y + width);
	this->width = width;
	this->height = width;
	hovered = false;
	this->task = task;
}

Point& SummaryButton::GetBottomRight() {
	return bottomRight;
}

float& SummaryButton::GetSpace() {
	return space;
}

void SummaryButton::SetTopLeft(Point topLeft) {
	
	this->topLeft = topLeft;
	width = bottomRight.x - topLeft.x;
	height = width;
}

void SummaryButton::SetBottomRight(Point bottomRight) {

	this->bottomRight = bottomRight;
	width = bottomRight.x - topLeft.x;
	height = width;
}
