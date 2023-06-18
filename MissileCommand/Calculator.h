#pragma once

#define _USE_MATH_DEFINES

#include <cmath>
#include <random>
#include <d2d1.h>
#include "Point.h"

/// <summary>
/// Class responsible for processing data in order to provide new data 
/// </summary>
class Calculator {

public:

	// Returns the angle in radians, calculated between the two given points
	static float GetRadians(Point point1, Point point2);
	// Returns the angle in radians, converted from the given angle in degrees
	static float GetRadians(float angleDeg);
	// Returns the angle in degrees, converted from the given angle in radians
	static float GetDegrees(float angleRad);
	// Returns the point being the next position of an object moving at the given speed, tilted by the given angle
	static Point GetNextPos(Point point, float angleRad, float speed);
	// Returns the point that lies on a line connecting the two given points, that is away from the first given point by exactly th distance given as an argument
	static Point GetPosBetween(Point point1, Point point2, float distance);
	// Returns the squared distance between the two given points on a two-dimensional plane
	static float GetDistanceSq(Point point1, Point point2);
	// Returns the distance between the two given points on a two-dimensional plane
	static float GetDistance(Point point1, Point point2);
	// Returns the maximum amount of points that are achievable with given bombs
	static int GetMaxScore(int normalNum, int nuclearNum, int clusterNum, int napalmNum, int rodNum);
	// Returns the height necessary for the given bitmap to maintain its aspect ratio in accordance to the given width
	static float GetProperHeight(ID2D1Bitmap* bitmap, float width);
};

