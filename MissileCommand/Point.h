#pragma once

class Point {

public:

	float x;
	float y;

	Point();
	Point(float x, float y);

	bool operator==(const Point& p) const;
};

