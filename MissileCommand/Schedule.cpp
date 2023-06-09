#include "Schedule.h"

void Schedule::ScheduleNormalDrops(int count, float duration) {

	std::list<float> drops;
	float minGap = duration / (count * 2);

	while (drops.size() < count) {

		float newDrop = Generator::GetRandomUniform(0.0f, duration);
		bool valid = true;

		for (float drop : drops)
			if (Verifier::TooClose(newDrop, drop, minGap)) {
			
				valid = false;
				break;
			}

		if (valid)
			drops.push_back(newDrop);
	}

	drops.sort();
	normalDrops = drops;
}

void Schedule::ScheduleNuclearDrops(int count, float duration) {

	std::list<float> drops;
	float minTime = duration / 10;

	while (drops.size() < count)
		drops.push_back(Generator::GetRandomUniform(minTime, duration));

	drops.sort();
	nuclearDrops = drops;
}

void Schedule::ScheduleClusterDrops(int count, float duration) {

	std::list<float> drops;
	float minTime = duration / 10;

	while (drops.size() < count)
		drops.push_back(Generator::GetRandomUniform(minTime, duration));

	drops.sort();
	clusterDrops = drops;
}

void Schedule::ScheduleNapalmDrops(int count, float duration) {

	std::list<float> drops;
	float minTime = duration / 10;

	while (drops.size() < count)
		drops.push_back(Generator::GetRandomUniform(minTime, duration));

	drops.sort();
	napalmDrops = drops;
}

void Schedule::ScheduleRodDrops(int count, float duration) {

	std::list<float> drops;
	float minTime = duration / 2;

	while (drops.size() < count)
		drops.push_back(Generator::GetRandomUniform(minTime, duration));

	drops.sort();
	rodDrops = drops;
}

void Schedule::ScheduleAllBombDrops(int normalNum, int nuclearNum, int clusterNum, int napalmNum, 
	int rodNum, float duration) {

	ScheduleNormalDrops(normalNum, duration);
	ScheduleNuclearDrops(nuclearNum, duration);
	ScheduleClusterDrops(clusterNum, duration);
	ScheduleNapalmDrops(napalmNum, duration);
	ScheduleRodDrops(rodNum, duration);
}

void Schedule::ScheduleAllBombDrops(std::list<Bomb> bombs, float duration) {

	int normalNum = 0;
	int nuclearNum = 0;
	int clusterNum = 0;
	int napalmNum = 0;
	int rodNum = 0;

	for (Bomb bomb : bombs) {

		switch (bomb.GetSource()) {

			case NORMAL: 
				normalNum++;
				break;

			case NUCLEAR:
				nuclearNum++;
				break;

			case CLUSTER:
				clusterNum++;
				break;

			case NAPALM:
				napalmNum++;
				break;

			case RODOFGOD:
				rodNum++;
				break;

			default:
				break;
		}
	}

	ScheduleAllBombDrops(normalNum, nuclearNum, clusterNum, napalmNum, rodNum, duration);
}

Schedule::Schedule() {

	normalDrops = {};
	nuclearDrops = {};
	clusterDrops = {};
	napalmDrops = {};
	rodDrops = {};
}

Schedule::Schedule(int normalNum, int nuclearNum, int clusterNum, int napalmNum, int rodNum, float duration) {

	ScheduleAllBombDrops(normalNum, nuclearNum, clusterNum, napalmNum, rodNum, duration);
}

Schedule::Schedule(std::list<Bomb> bombs, float duration) {

	ScheduleAllBombDrops(bombs, duration);
}

std::list<float>& Schedule::GetNormalDrops() {
	return normalDrops;
}

std::list<float>& Schedule::GetNuclearDrops() {
	return nuclearDrops;
}

std::list<float>& Schedule::GetClusterDrops() {
	return clusterDrops;
}

std::list<float>& Schedule::GetNapalmDrops() {
	return napalmDrops;
}

std::list<float>& Schedule::GetRodDrops() {
	return rodDrops;
}
