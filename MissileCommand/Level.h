#pragma once

#include "Globals.h"
#include "Schedule.h"

/// <summary>
/// Class representing every level present in the game
/// </summary>
class Level {

	const wchar_t* location;
	int difficulty;
	int normalNum;
	int nuclearNum;
	int clusterNum;
	int napalmNum;
	int rodNum;
	int maxScore;
	float duration;
	Schedule schedule;

	void SetLevelOne();
	void SetLevelTwo();
	void SetLevelThree();
	void SetLevelFour();
	void SetLevelFive();

public:

	Level();
	Level(int difficulty);

	// Returns the string containing the name of the location of the level
	const wchar_t* GetLocation();
	// Returns the integer value representing the difficulty level
	int GetDifficulty();
	// Returns the total number of normal bombs at the level
	int GetNormalNum();
	// Returns the total number of nuclear bombs at the level
	int GetNuclearNum();
	// Returns the total number of cluster bombs at the level
	int GetClusterNum();
	// Returns the total number of napalm bombs at the level
	int GetNapalmNum();
	// Returns the total number of rod of god bombs at the level
	int GetRodNum();
	// Returns the maximum possible score to achieve at the level
	int GetMaxScore();
	// Returns the duration of the level (seconds)
	float GetDuration();
	// Returns the pointer to the Schedule instance (contains lists containing very specific information on bomb drops)
	Schedule& GetSchedule();
};

