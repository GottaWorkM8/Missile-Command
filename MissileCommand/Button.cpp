#include "Button.h"

Button::Button() {

	topLeft = Point();
	width = 0;
	height = 0;
	hovered = false;
	task = nullptr;
}

Button::Button(Point topLeft, float width, float height, void (*task)()) {

	this->topLeft = topLeft;
	this->width = 0;
	this->height = 0;
	hovered = false;
	this->task = task;
}

Point& Button::GetTopLeft() {
	return topLeft;
}

float& Button::GetWidth() {
	return width;
}

float& Button::GetHeight() {
	return height;
}

bool& Button::IsHovered() {
	return hovered;
}

void Button::SetHovered(bool hovered) {
	this->hovered = hovered;
}

void Button::PerformTask() {

	task();
}
