#pragma once

#include <list>
#include "Globals.h"
#include "Bomb.h"
#include "Missile.h"
#include "Building.h"
#include "Explosion.h"
#include "Destruction.h"
#include "Launcher.h"
#include "Flash.h"

/// <summary>
/// Class responsible for storing and managing all objects present in the game (Bomb, Building, Destruction, Explosion, Flash, Launcher, Missile)
/// </summary>
class ItemManager {

	static Launcher launcher;
	static std::list<Building> buildings;
	static std::list<Missile> missiles;
	static std::list<Bomb> bombs;
	static std::list<Explosion> explosions;
	static std::list<Destruction> destructions;
	static std::list<Flash> flashes;
	
public:

	// Returns the pointer to the Launcher object
	static Launcher& GetLauncher();
	// Returns the list containing pointers to all currently existing Building objects
	static std::list<Building>& GetBuildings();
	// Returns the list containing pointers to all currently existing Missile objects
	static std::list<Missile>& GetMissiles();
	// Returns the list containing pointers to all currently existing Bomb objects
	static std::list<Bomb>& GetBombs();
	// Returns the list containing pointers to all currently existing Explosion objects
	static std::list<Explosion>& GetExplosions();
	// Returns the list containing pointers to all currently existing Destruction objects
	static std::list<Destruction>& GetDestructions();
	// Returns the list containing pointers to all currently existing Flash objects
	static std::list<Flash>& GetFlashes();
	
	// Adds the object given as an argument to the list of buildings
	static void AddBuilding(Building building);
	// Adds the object given as an argument to the list of missiles
	static void AddMissile(Missile missile);
	// Adds the object given as an argument to the list of bombs
	static void AddBomb(Bomb bomb);
	// Adds the object given as an argument to the list of explosions
	static void AddExplosion(Explosion explosion);
	// Adds the object given as an argument to the list of destructions
	static void AddDestruction(Destruction destruction);
	// Adds the object given as an argument to the list of flashes
	static void AddFlash(Flash flash);
	// Sets all lists content to default
	static void Reset();
};
