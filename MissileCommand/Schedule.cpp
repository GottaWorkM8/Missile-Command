#include "Schedule.h"

void Schedule::ScheduleNormalDrops(int count, float duration) {

	std::list<float> list;
	float minGap = duration / (count * 2);
	float maxGap = duration / count * 2;

	while (list.size() < count) {

		float value = Generator::GetRandomUniform(0, duration);
		bool valid = true;

		for (float existingValue : list)
			if (std::abs(value - existingValue) < minGap || std::abs(value - existingValue) > maxGap) {

				valid = false;
				break;
			}

		if (valid)
			list.push_back(value);
	}

	list.sort();
	normalDrops = list;
}

void Schedule::ScheduleNuclearDrops(int count, float duration) {

	std::list<float> list;
	float minTime = duration / 10;

	while (list.size() < count)
		list.push_back(Generator::GetRandomUniform(minTime, duration));

	list.sort();
	nuclearDrops = list;
}

void Schedule::ScheduleClusterDrops(int count, float duration) {

	std::list<float> list;
	float minTime = duration / 10;

	while (list.size() < count)
		list.push_back(Generator::GetRandomUniform(minTime, duration));

	list.sort();
	clusterDrops = list;
}

void Schedule::ScheduleNapalmDrops(int count, float duration) {

	std::list<float> list;
	float minTime = duration / 10;

	while (list.size() < count)
		list.push_back(Generator::GetRandomUniform(minTime, duration));

	list.sort();
	napalmDrops = list;
}

void Schedule::ScheduleRodDrops(int count, float duration) {

	std::list<float> list;
	float minTime = duration / 2;

	while (list.size() < count)
		list.push_back(Generator::GetRandomUniform(minTime, duration));

	list.sort();
	rodDrops = list;
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
