#pragma once

#include <dwrite.h>
#include "Point.h"

/// <summary>description</summary>
class Button {

protected:

	Point topLeft;
	float width;
	float height;
	bool hovered;
	void (*task)();

public:

	Button();
	Button(Point topLeft, float width, float height, void (*task)());

	Point& GetTopLeft();
	float& GetWidth();
	float& GetHeight();
	bool& IsHovered();
	void SetHovered(bool hovered);

	void PerformTask();
};

