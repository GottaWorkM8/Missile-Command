#pragma once

#include "Globals.h"
#include "Schedule.h"

class Level {

	const wchar_t* location;
	int difficulty;
	int normalNum;
	int nuclearNum;
	int clusterNum;
	int napalmNum;
	int rodNum;
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
	float GetDuration();
	Schedule& GetSchedule();
};

