#pragma once

#include <list>
#include "Item.h"
#include "Bomb.h"
#include "Building.h"
#include "Timer.h"
#include "Source.h"

/// <summary>
/// Class representing every explosion in the game
/// </summary>
class Explosion : public Item {

	float radius;
	float damage;
	int stage;
	Timer stageTimer;
	Source source;
	bool launcherHit;
	std::list<Building*> buildingsHit;
	std::list<Bomb*> bombsHit;

public:

	Explosion();
	Explosion(Point center, float radius, Source source);

	// Sets the rotation angle in radians and degrees to the value given as an argument
	void SetAngleRad(float& angleRad);
	// Sets the rotation angle in radians and degrees to the value given as an argument
	void SetAngleDeg(float& angleDeg);
	// Returns the current radius of the explosion
	float& GetRadius();
	// Sets the current radius of the explosion
	void SetRadius(float& radius);
	// Returns the damage dealt by the explosion
	float& GetDamage();
	// Return the current stage of the explosion
	int& GetStage();
	// Returns the stage timer keeping track of the time before the next stage
	Timer& GetStageTimer();
	// Returns the type of the explosion
	Source& GetSource();
	// Returns the boolean telling if the launcher was already hit once by the explosion
	bool IsLauncherHit();
	// Sets the boolean telling if the launcher was already hit once by the explosion
	void SetLauncherHit(bool launcherHit);
	// Returns the list containing all buildings already hit once by the explosion
	std::list<Building*>& GetBuildingsHit();
	// Returns the list containing all bombs already hit once by the explosion
	std::list<Bomb*>& GetBombsHit();
	
	bool operator==(const Explosion& e) const;

	// Adds the building given as an argument to the list of buildings already hit once by the explosion
	void AddBuildingHit(Building& building);
	// Adds the bomb given as an argument to the list of bombs already hit once by the explosion
	void AddBombHit(Bomb& bomb);
};

