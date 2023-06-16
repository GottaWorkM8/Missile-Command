#pragma once

#include "Globals.h"
#include "Schedule.h"

/// <summary>description</summary>
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

	const wchar_t* GetLocation();
	int GetDifficulty();
	int GetNormalNum();
	int GetNuclearNum();
	int GetClusterNum();
	int GetNapalmNum();
	int GetRodNum();
	int GetMaxScore();
	float GetDuration();
	Schedule& GetSchedule();
};

