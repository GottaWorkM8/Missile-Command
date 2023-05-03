#include "Calculator.h"

float Calculator::GetRadians(Point point1, Point point2) {

    return atan2f(point1.y - point2.y, point1.x - point2.x);
}

float Calculator::GetRadians(float angleDeg) {

    return (float) angleDeg * M_PI / 180;
}

float Calculator::GetDegrees(float angleRad) {

    return (float) angleRad * 180 / M_PI;
}

Point Calculator::GetNextPos(Point point, float angleRad, float speed) {

    float shiftX = speed * sinf(angleRad);
    float shiftY = speed * cosf(angleRad);
    Point newPoint = Point(point.x + shiftX, point.y - shiftY);

    return newPoint;
}

Point Calculator::GetPosBetween(Point point1, Point point2, float distance) {
    
    float diffX = point2.x - point1.x;
    float diffY = point2.y - point1.y;
    float diff = GetDistance(point1, point2);
    float unitX = diffX / diff;
    float unitY = diffY / diff;
    Point newPoint = Point(point1.x + distance * unitX, point1.y + distance * unitY);

    return newPoint;
}

float Calculator::GetDistanceSq(Point point1, Point point2) {

    return powf(point1.x - point2.x, 2) + powf(point1.y - point2.y, 2);
}

float Calculator::GetDistance(Point point1, Point point2) {

    return sqrtf(GetDistanceSq(point1, point2));
}
