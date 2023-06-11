#include "MenuButton.h"

MenuButton::MenuButton() {

	textLayout = nullptr;
	text = L"";
	topLeft = Point();
	width = 0;
	height = 0;
	hovered = false;
	task = nullptr;
}

MenuButton::MenuButton(const wchar_t* text, Point topLeft, float height, void (*task)()) {

	textLayout = nullptr;
	this->text = text;
	this->topLeft = topLeft;
	width = 0;
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

void MenuButton::SetWidth(float width) {
	this->width = width;
}