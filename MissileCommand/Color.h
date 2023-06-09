#pragma once

/// <summary>
/// Class representing RGBA colors
/// </summary>
class Color {

public:

	float red;
	float green;
	float blue;
	float alpha;

	Color();
	Color(float red, float green, float blue, float alpha);
	Color(float red, float green, float blue);

	bool operator==(const Color& c) const;
};

