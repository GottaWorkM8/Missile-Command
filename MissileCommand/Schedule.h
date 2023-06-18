#pragma once

#include <list>
#include "Generator.h"
#include "Verifier.h"

/// <summary>
/// Class representing a bomb drop schedule of a game level, 
/// i.e. class is responsible for storing information about the exact time, when each bomb is suppossed to be dropped)
/// </summary>
class Schedule {

	std::list<float> normalDrops;
	std::list<float> nuclearDrops;
	std::list<float> clusterDrops;
	std::list<float> napalmDrops;
	std::list<float> rodDrops;

	// Creates a randomly generated schedule of normal bomb drops, based on the given bomb count and level duration (list containing timestamps)
	void ScheduleNormalDrops(int count, float duration);
	// Creates a randomly generated schedule of nuclear bomb drops, based on the given bomb count and level duration (list containing timestamps)
	void ScheduleNuclearDrops(int count, float duration);
	// Creates a randomly generated schedule of cluster bomb drops, based on the given bomb count and level duration (list containing timestamps)
	void ScheduleClusterDrops(int count, float duration);
	// Creates a randomly generated schedule of napalm bomb drops, based on the given bomb count and level duration (list containing timestamps)
	void ScheduleNapalmDrops(int count, float duration);
	// Creates a randomly generated schedule of rod of god bomb drops, based on the given bomb count and level duration (list containing timestamps)
	void ScheduleRodDrops(int count, float duration);
	// Creates a randomly generated schedule of all bomb drops, based on the given bomb numbers and level duration (5 lists containing timestamps)
	void ScheduleAllBombDrops(int normalNum, int nuclearNum, int clusterNum, int napalmNum,
		int rodNum, float duration);
	// Creates a randomly generated schedule of all bomb drops, based on the given list of Bomb instances and level duration (5 lists containing timestamps)
	void ScheduleAllBombDrops(std::list<Bomb> bombs, float duration);

public:

	Schedule();
	Schedule(int normalNum, int nuclearNum, int clusterNum, int napalmNum, int rodNum, float duration);
	Schedule(std::list<Bomb> bombs, float duration);

	// Returns the list containing all normal bomb drops (timestamps)
	std::list<float>& GetNormalDrops();
	// Returns the list containing all nuclear bomb drops (timestamps)
	std::list<float>& GetNuclearDrops();
	// Returns the list containing all cluster bomb drops (timestamps)
	std::list<float>& GetClusterDrops();
	// Returns the list containing all napalm bomb drops (timestamps)
	std::list<float>& GetNapalmDrops();
	// Returns the list containing all rod of god bomb drops (timestamps)
	std::list<float>& GetRodDrops();
};

