#pragma once

#include <dwrite.h>
#include "Point.h"

class MenuButton {

	IDWriteTextLayout* textLayout;
	const wchar_t* text;
	Point topLeft;
	float width;
	float height;
	bool hovered;
	void (*task)();

public:

	MenuButton();
	MenuButton(const wchar_t* text, Point topLeft, float height, void (*task)());

	IDWriteTextLayout* GetTextLayout();
	void SetTextLayout(IDWriteTextLayout* textLayout);
	const wchar_t* GetText();
	Point& GetTopLeft();
	float& GetWidth();
	void SetWidth(float width);
	float& GetHeight();
	bool& IsHovered();
	void SetHovered(bool hovered);

	void PerformTask();
};

