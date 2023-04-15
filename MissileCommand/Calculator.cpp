#include "Calculator.h"

std::random_device Calculator::device;
std::mt19937 Calculator::generator(device());

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

float Calculator::GetRandomUniform(float min, float max) {

    std::uniform_real_distribution<> distribution(min, max);

    return distribution(generator);
}

float Calculator::GetRandomNormal(float min, float max) {

    std::normal_distribution<> distribution(min, max);

    return distribution(generator);
}
