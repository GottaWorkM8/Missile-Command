#pragma once

#include <list>
#include "Bomb.h"
#include "Missile.h"
#include "Building.h"
#include "Explosion.h"
#include "Launcher.h"
#include "Game.h"

class ItemManager {

	static Launcher launcher;
	static std::list<Building> buildings;
	static std::list<Missile> missiles;
	static std::list<Bomb> bombs;
	static std::list<Explosion> missileExplosions;
	static std::list<Explosion> bombExplosions;
	
public:

	static Launcher& GetLauncher();
	static void SetLauncher(Launcher launcher);
	static std::list<Building>& GetBuildings();
	static std::list<Missile>& GetMissiles();
	static std::list<Bomb>& GetBombs();
	static std::list<Explosion>& GetMissileExplosions();
	static std::list<Explosion>& GetBombExplosions();
	
	static void AddBuilding(Building building);
	static void AddMissile(Missile missile);
	static void AddBomb(Bomb bomb);
	static void AddBombs(std::list<Bomb> bombs);
	static void AddMissileExplosion(Explosion explosion);
	static void AddBombExplosion(Explosion explosion);
	static void RemoveBuilding(Building building);
	static void RemoveMissile(Missile missile);
	static void RemoveBomb(Bomb bomb);
	static void RemoveMissileExplosion(Explosion explosion);
	static void RemoveBombExplosion(Explosion explosion);
	static void RemoveAllItems();
};

