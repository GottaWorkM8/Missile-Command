#pragma once

#include <list>
#include "Globals.h"
#include "Bomb.h"
#include "Missile.h"
#include "Building.h"
#include "Explosion.h"
#include "Launcher.h"
#include "Flash.h"

class ItemManager {

	static Launcher launcher;
	static std::list<Building> buildings;
	static std::list<Missile> missiles;
	static std::list<Bomb> bombs;
	static std::list<Explosion> explosions;
	static std::list<Flash> flashes;
	
public:

	static Launcher& GetLauncher();
	static void SetLauncher(Launcher launcher);
	static std::list<Building>& GetBuildings();
	static std::list<Missile>& GetMissiles();
	static std::list<Bomb>& GetBombs();
	static std::list<Explosion>& GetExplosions();
	static std::list<Flash>& GetFlashes();
	
	static void AddBuilding(Building building);
	static void AddMissile(Missile missile);
	static void AddBomb(Bomb bomb);
	static void AddBombs(std::list<Bomb> bombs);
	static void AddExplosion(Explosion explosion);
	static void AddFlash(Flash flash);
	static void RemoveBuilding(Building building);
	static void RemoveMissile(Missile missile);
	static void RemoveBomb(Bomb bomb);
	static void RemoveExplosion(Explosion explosion);
	static void Reset();
};

