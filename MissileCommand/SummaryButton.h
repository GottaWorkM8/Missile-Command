#pragma once

#include <functional>
#include "Button.h"

class Summary;

/// <summary>
/// Class representing buttons present in the summary at the end of every game
/// </summary>
class SummaryButton : public Button {

	Point bottomRight;
	float space;

public:

	SummaryButton();
	SummaryButton(Point topLeft, float width, void (*task)());

	// Returns the bottom right point of the summary button
	Point& GetBottomRight();
	// Returns the space between the button icon and the button outer border
	float& GetSpace();

	// Sets the top left point of the summary button
	void SetTopLeft(Point topLeft);
	// Sets the bottom right point of the summary button
	void SetBottomRight(Point bottomRight);
};

