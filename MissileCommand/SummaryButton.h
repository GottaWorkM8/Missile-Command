#pragma once

#include <functional>
#include "Button.h"

class Summary;

class SummaryButton : public Button {

	Point bottomRight;
	float space;

public:

	SummaryButton();
	SummaryButton(Point topLeft, float width, void (*task)());

	Point& GetBottomRight();
	float& GetSpace();

	void SetTopLeft(Point topLeft);
	void SetBottomRight(Point bottomRight);
};

