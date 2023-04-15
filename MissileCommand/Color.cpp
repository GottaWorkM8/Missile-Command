#include "Color.h"

Color::Color() {

}

Color::Color(float red, float green, float blue, float alpha) {

	this->red = red;
	this->green = green;
	this->blue = blue;
	this->alpha = alpha;
}

Color::Color(float red, float green, float blue) {

	this->red = red;
	this->green = green;
	this->blue = blue;
}

bool Color::operator==(const Color& c) const {

	return this->red == c.red && this->green == c.green && this->blue == c.blue && this->alpha == c.alpha;
}
