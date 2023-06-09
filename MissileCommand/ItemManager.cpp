#include "ItemManager.h"

Launcher ItemManager::launcher = Launcher(Point(Globals::MAX_X / 2, Globals::GROUND_Y - Globals::LAUNCHER_HALF_HEIGHT),
	0.0f, Globals::LAUNCHER_HP);
std::list<Building> ItemManager::buildings = {
	Building(Point(Globals::MAX_X / 12, Globals::GROUND_Y - Globals::BUILDING_HALF_HEIGHT), Globals::BUILDING_HP),
	Building(Point(Globals::MAX_X / 12 * 2, Globals::GROUND_Y - Globals::BUILDING_HALF_HEIGHT), Globals::BUILDING_HP),
	Building(Point(Globals::MAX_X / 12 * 3, Globals::GROUND_Y - Globals::BUILDING_HALF_HEIGHT), Globals::BUILDING_HP),
	Building(Point(Globals::MAX_X / 12 * 4, Globals::GROUND_Y - Globals::BUILDING_HALF_HEIGHT), Globals::BUILDING_HP),
	Building(Point(Globals::MAX_X / 12 * 8, Globals::GROUND_Y - Globals::BUILDING_HALF_HEIGHT), Globals::BUILDING_HP),
	Building(Point(Globals::MAX_X / 12 * 9, Globals::GROUND_Y - Globals::BUILDING_HALF_HEIGHT), Globals::BUILDING_HP),
	Building(Point(Globals::MAX_X / 12 * 10, Globals::GROUND_Y - Globals::BUILDING_HALF_HEIGHT), Globals::BUILDING_HP),
	Building(Point(Globals::MAX_X / 12 * 11, Globals::GROUND_Y - Globals::BUILDING_HALF_HEIGHT), Globals::BUILDING_HP)};
std::list<Missile> ItemManager::missiles = {};
std::list<Bomb> ItemManager::bombs = {};
std::list<Explosion> ItemManager::explosions = {};
std::list<Destruction> ItemManager::destructions = {};
std::list<Flash> ItemManager::flashes = {};

Launcher& ItemManager::GetLauncher() {
	return launcher;
}

void ItemManager::SetLauncher(Launcher launch) {
	launcher = launch;
}

std::list<Building>& ItemManager::GetBuildings() {
	return buildings;
}

std::list<Missile>& ItemManager::GetMissiles() {
	return missiles;
}

std::list<Bomb>& ItemManager::GetBombs() {
	return bombs;
}

std::list<Explosion>& ItemManager::GetExplosions() {
	return explosions;
}

std::list<Destruction>& ItemManager::GetDestructions() {
	return destructions;
}

std::list<Flash>& ItemManager::GetFlashes() {
	return flashes;
}

void ItemManager::AddBuilding(Building building) {

	buildings.push_back(building);
}

void ItemManager::AddMissile(Missile missile) {

	missiles.push_back(missile);
}

void ItemManager::AddBomb(Bomb bomb) {

	bombs.push_back(bomb);
}

void ItemManager::AddBombs(std::list<Bomb> newBombs) {

	bombs.splice(bombs.end(), newBombs);
}

void ItemManager::AddExplosion(Explosion explosion) {

	explosions.push_back(explosion);
}

void ItemManager::AddDestruction(Destruction destruction) {

	destructions.push_back(destruction);
}

void ItemManager::AddFlash(Flash flash) {

	flashes.push_back(flash);
}

void ItemManager::Reset() {

	launcher = Launcher(Point(Globals::MAX_X / 2, Globals::GROUND_Y - Globals::LAUNCHER_HALF_HEIGHT),
		0.0f, Globals::LAUNCHER_HP);
	buildings = {
		Building(Point(Globals::MAX_X / 12, Globals::GROUND_Y - Globals::BUILDING_HALF_HEIGHT), Globals::BUILDING_HP),
		Building(Point(Globals::MAX_X / 12 * 2, Globals::GROUND_Y - Globals::BUILDING_HALF_HEIGHT), Globals::BUILDING_HP),
		Building(Point(Globals::MAX_X / 12 * 3, Globals::GROUND_Y - Globals::BUILDING_HALF_HEIGHT), Globals::BUILDING_HP),
		Building(Point(Globals::MAX_X / 12 * 4, Globals::GROUND_Y - Globals::BUILDING_HALF_HEIGHT), Globals::BUILDING_HP),
		Building(Point(Globals::MAX_X / 12 * 8, Globals::GROUND_Y - Globals::BUILDING_HALF_HEIGHT), Globals::BUILDING_HP),
		Building(Point(Globals::MAX_X / 12 * 9, Globals::GROUND_Y - Globals::BUILDING_HALF_HEIGHT), Globals::BUILDING_HP),
		Building(Point(Globals::MAX_X / 12 * 10, Globals::GROUND_Y - Globals::BUILDING_HALF_HEIGHT), Globals::BUILDING_HP),
		Building(Point(Globals::MAX_X / 12 * 11, Globals::GROUND_Y - Globals::BUILDING_HALF_HEIGHT), Globals::BUILDING_HP) };
	missiles = {};
	bombs = {};
	explosions = {};
	destructions = {};
	flashes = {};
}