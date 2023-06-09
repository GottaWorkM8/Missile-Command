#include "Verifier.h"

bool Verifier::Within(Point point, Point center, float halfWidth, float halfHeight) {

    float left = center.x - halfWidth;
    float right = center.x + halfWidth;
    float top = center.y - halfHeight;
    float bottom = center.y + halfHeight;

    if (point.x >= left && point.x <= right && point.y >= top && point.y <= bottom)
        return true;

    else return false;
}

bool Verifier::WithinAlt(Point point, Point topLeft, float width, float height) {

    float left = topLeft.x;
    float right = topLeft.x + width;
    float top = topLeft.y;
    float bottom = topLeft.y + height;

    if (point.x >= left && point.x <= right && point.y >= top && point.y <= bottom)
        return true;

    else return false;
}

bool Verifier::Intersect(Point center, float halfWidth, float halfHeight,
    Point circleCenter, float circleRadius) {

    float distanceX = abs(circleCenter.x - center.x);
    float distanceY = abs(circleCenter.y - center.y);

    if (distanceX > (halfWidth + circleRadius))
        return false;

    if (distanceY > (halfHeight + circleRadius))
        return false;

    if (distanceX <= (halfWidth))
        return true;

    if (distanceY <= (halfHeight))
        return true;

    float distanceSq = pow(distanceX - halfWidth, 2) + pow(distanceY - halfHeight, 2);

    return (distanceSq <= pow(circleRadius, 2));
}

bool Verifier::TooClose(float value1, float value2, float minGap) {

    if (std::abs(value1 - value2) < minGap)
        return true;

    else return false;
}

bool Verifier::LauncherInRange(Launcher& launcher, Explosion& explosion) {

    return Intersect(launcher.GetCenter(), Globals::LAUNCHER_HALF_WIDTH, Globals::LAUNCHER_HALF_HEIGHT,
        explosion.GetCenter(), explosion.GetRadius());
}

bool Verifier::BuildingInRange(Building& building, Explosion& explosion) {

    return Intersect(building.GetCenter(), Globals::BUILDING_HALF_WIDTH, Globals::BUILDING_HALF_HEIGHT,
        explosion.GetCenter(), explosion.GetRadius());
}

bool Verifier::BombInRange(Bomb& bomb, Explosion& explosion) {

    return Intersect(bomb.GetCenter(), Globals::BOMB_HALF_WIDTH, Globals::BOMB_HALF_HEIGHT,
        explosion.GetCenter(), explosion.GetRadius());
}

bool Verifier::BuildingOnTheList(Building& building, std::list<Building>& buildings) {

    for (Building& b : buildings)
        if (b == building)
            return true;

    return false;
}

bool Verifier::BombOnTheList(Bomb& bomb, std::list<Bomb>& bombs) {
    
    for (Bomb& b : bombs)
        if (b == bomb)
            return true;

    return false;
}

bool Verifier::GameLost(Launcher& launcher, std::list<Building>& buildings) {

    if (launcher.IsDestroyed() || buildings.empty())
        return true;

    return false;
}

bool Verifier::GameWon(std::list<Bomb>& bombs, float time, bool finished) {

    if (!finished)
        if (time > Globals::GAME_TIME)
            if (bombs.empty())
                return true;

    return false;
}
