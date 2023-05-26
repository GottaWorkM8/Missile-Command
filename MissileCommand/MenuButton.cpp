#include "MenuButton.h"

MenuButton::MenuButton() {

}

MenuButton::MenuButton(const wchar_t* text, Point topLeft, float height, void (*task)()) {

	this->text = text;
	this->topLeft = topLeft;
	this->height = height;
	this->hovered = false;
	this->task = task;
}

IDWriteTextLayout* MenuButton::GetTextLayout() {
	return textLayout;
}

void MenuButton::SetTextLayout(IDWriteTextLayout* textLayout) {
	this->textLayout = textLayout;
}

const wchar_t* MenuButton::GetText() {
	return text;
}

Point& MenuButton::GetTopLeft() {
	return topLeft;
}

float& MenuButton::GetWidth() {
	return width;
}

void MenuButton::SetWidth(float width) {
	this->width = width;
}

float& MenuButton::GetHeight() {
	return height;
}

bool& MenuButton::IsHovered() {
	return hovered;
}

void MenuButton::SetHovered(bool hovered) {
	this->hovered = hovered;
}

void MenuButton::PerformTask() {

	task();
}
