#pragma once

#include <list>
#include "Generator.h"
#include "Verifier.h"

class Schedule {

	std::list<float> normalDrops;
	std::list<float> nuclearDrops;
	std::list<float> clusterDrops;
	std::list<float> napalmDrops;
	std::list<float> rodDrops;

	void ScheduleNormalDrops(int count, float duration);
	void ScheduleNuclearDrops(int count, float duration);
	void ScheduleClusterDrops(int count, float duration);
	void ScheduleNapalmDrops(int count, float duration);
	void ScheduleRodDrops(int count, float duration);
	void ScheduleAllBombDrops(int normalNum, int nuclearNum, int clusterNum, int napalmNum,
		int rodNum, float duration);
	void ScheduleAllBombDrops(std::list<Bomb> bombs, float duration);

public:

	Schedule();
	Schedule(int normalNum, int nuclearNum, int clusterNum, int napalmNum, int rodNum, float duration);
	Schedule(std::list<Bomb> bombs, float duration);

	std::list<float>& GetNormalDrops();
	std::list<float>& GetNuclearDrops();
	std::list<float>& GetClusterDrops();
	std::list<float>& GetNapalmDrops();
	std::list<float>& GetRodDrops();
};

