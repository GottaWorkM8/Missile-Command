#pragma once

/// <summary>
/// Class representing a point on a two-dimensional plane
/// </summary>
class Point {

public:

	float x;
	float y;

	Point();
	Point(float x, float y);

	bool operator==(const Point& p) const;
};

