#include "ItemManager.h"

Launcher ItemManager::launcher = Launcher(Globals::LAUNCHER_CENTER);
std::list<Building> ItemManager::buildings = {
	Building(Globals::BUILDING1_CENTER, 0),
	Building(Globals::BUILDING2_CENTER, 1),
	Building(Globals::BUILDING3_CENTER, 2),
	Building(Globals::BUILDING4_CENTER, 3),
	Building(Globals::BUILDING5_CENTER, 4),
	Building(Globals::BUILDING6_CENTER, 5),
	Building(Globals::BUILDING7_CENTER, 6),
	Building(Globals::BUILDING8_CENTER, 7) };
std::list<Missile> ItemManager::missiles = {};
std::list<Bomb> ItemManager::bombs = {};
std::list<Explosion> ItemManager::explosions = {};
std::list<Destruction> ItemManager::destructions = {};
std::list<Flash> ItemManager::flashes = {};

Launcher& ItemManager::GetLauncher() {
	return launcher;
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

	launcher = Launcher(Globals::LAUNCHER_CENTER);
	buildings = {
		Building(Globals::BUILDING1_CENTER, 0),
		Building(Globals::BUILDING2_CENTER, 1),
		Building(Globals::BUILDING3_CENTER, 2),
		Building(Globals::BUILDING4_CENTER, 3),
		Building(Globals::BUILDING5_CENTER, 4),
		Building(Globals::BUILDING6_CENTER, 5),
		Building(Globals::BUILDING7_CENTER, 6),
		Building(Globals::BUILDING8_CENTER, 7) };
	missiles = {};
	bombs = {};
	explosions = {};
	destructions = {};
	flashes = {};
}