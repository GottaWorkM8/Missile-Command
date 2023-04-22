#include "Calculator.h"

float Calculator::GetRadians(Point point1, Point point2) {

    return atan2f(point1.y - point2.y, point1.x - point2.x);
}

float Calculator::GetRadians(float angleDeg) {

    return angleDeg * M_PI / 180;
}

float Calculator::GetDegrees(float angleRad) {

    return angleRad * 180 / M_PI;
}

Point Calculator::GetNextPos(Point point, float angleRad, float speed) {

    float shiftX = speed * sinf(angleRad);
    float shiftY = speed * cosf(angleRad);
    Point newPoint = Point(point.x + shiftX, point.y - shiftY);

    return newPoint;
}

float Calculator::GetDistanceSq(Point point1, Point point2) {

    return powf(point1.x - point2.x, 2) + powf(point1.y - point2.y, 2);
}

float Calculator::GetDistance(Point point1, Point point2) {

    return sqrtf(GetDistanceSq(point1, point2));
}
