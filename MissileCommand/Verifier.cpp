#include "Verifier.h"

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

bool Verifier::BombHit(Bomb bomb, Explosion explosion) {

    return Intersect(bomb.GetCenter(), Game::BOMB_HALF_WIDTH, Game::BOMB_HALF_HEIGHT, 
        explosion.GetCenter(), explosion.GetRadius());
}

bool Verifier::BuildingHit(Building building, Explosion explosion) {

    return Intersect(building.GetCenter(), Game::BUILDING_HALF_WIDTH, Game::BUILDING_HALF_HEIGHT,
        explosion.GetCenter(), explosion.GetRadius());
}

bool Verifier::LauncherHit(Launcher launcher, Explosion explosion) {

    return Intersect(launcher.GetCenter(), Game::LAUNCHER_HALF_WIDTH, Game::LAUNCHER_HALF_HEIGHT,
        explosion.GetCenter(), explosion.GetRadius());
}

bool Verifier::GameLost(Launcher launcher, std::list<Building> buildings) {

    if (launcher.GetHP() <= 0.0f || buildings.empty())
        return true;

    return false;
}
