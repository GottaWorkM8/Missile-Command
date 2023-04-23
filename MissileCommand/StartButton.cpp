#include "StartButton.h"

StartButton::StartButton() {

}

StartButton::StartButton(Point center) {

	this->center = center;
}

Point StartButton::GetCenter() {
	return center;
}