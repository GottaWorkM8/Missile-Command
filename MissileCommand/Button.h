#pragma once

#include <dwrite.h>
#include "Point.h"

/// <summary>
/// Class represents a basic button and is a base class for some button classes (MenuButton, SummaryButton)
/// </summary>
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

	// Returns top left point of the button
	Point& GetTopLeft();
	// Returns width of the button
	float& GetWidth();
	// Returns height of the button
	float& GetHeight();
	// Returns boolean telling if the button is hovered
	bool& IsHovered();
	// Sets boolean telling if the button is hovered
	void SetHovered(bool hovered);

	// Performs task assigned to the button during the initialization
	void PerformTask();
};

