#include "ItemManager.h"

Launcher ItemManager::launcher = Launcher(Point(Game::maxX / 2, 
	Game::groundY - Game::launcherHalfHeight), 0.0f);
std::list<Building> ItemManager::buildings = {
	Building(Point(Game::maxX / 12, Game::groundY - Game::buildingHalfHeight)), 
	Building(Point(Game::maxX / 12 * 2, Game::groundY - Game::buildingHalfHeight)),
	Building(Point(Game::maxX / 12 * 3, Game::groundY - Game::buildingHalfHeight)),
	Building(Point(Game::maxX / 12 * 4, Game::groundY - Game::buildingHalfHeight)),
	Building(Point(Game::maxX / 12 * 8, Game::groundY - Game::buildingHalfHeight)),
	Building(Point(Game::maxX / 12 * 9, Game::groundY - Game::buildingHalfHeight)),
	Building(Point(Game::maxX / 12 * 10, Game::groundY - Game::buildingHalfHeight)),
	Building(Point(Game::maxX / 12 * 11, Game::groundY - Game::buildingHalfHeight))};
std::list<Missile> ItemManager::missiles = {};
std::list<Bomb> ItemManager::bombs = {};
std::list<Explosion> ItemManager::missileExplosions = {};
std::list<Explosion> ItemManager::bombExplosions = {};

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

std::list<Explosion>& ItemManager::GetMissileExplosions() {
	return missileExplosions;
}

std::list<Explosion>& ItemManager::GetBombExplosions() {
	return bombExplosions;
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

void ItemManager::AddMissileExplosion(Explosion explosion) {

	missileExplosions.push_back(explosion);
}

void ItemManager::AddBombExplosion(Explosion explosion) {

	bombExplosions.push_back(explosion);
}

void ItemManager::RemoveBuilding(Building building) {

	buildings.remove(building);
}

void ItemManager::RemoveMissile(Missile missile) {

	missiles.remove(missile);
}

void ItemManager::RemoveBomb(Bomb bomb) {

	bombs.remove(bomb);
}

void ItemManager::RemoveMissileExplosion(Explosion explosion) {

	missileExplosions.remove(explosion);
}

void ItemManager::RemoveBombExplosion(Explosion explosion) {

	bombExplosions.remove(explosion);
}

void ItemManager::RemoveAllItems() {

	buildings.clear();
	missiles.clear();
	bombs.clear();
	missileExplosions.clear();
	bombExplosions.clear();
}