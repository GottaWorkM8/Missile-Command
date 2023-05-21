#include "Level.h"

void Level::SetLevelOne() {

	difficulty = Globals::LEVEL1;
	normalNum = 100;
	nuclearNum = 0;
	clusterNum = 0;
	napalmNum = 0;
	rodNum = 0;
	duration = 60.0f;
	schedule = Schedule(normalNum, nuclearNum, clusterNum, napalmNum, rodNum, duration);
}

void Level::SetLevelTwo() {

	difficulty = Globals::LEVEL2;
	normalNum = 200;
	nuclearNum = 10;
	clusterNum = 0;
	napalmNum = 0;
	rodNum = 0;
	duration = 60.0f;
	schedule = Schedule(normalNum, nuclearNum, clusterNum, napalmNum, rodNum, duration);
}

void Level::SetLevelThree() {

	difficulty = Globals::LEVEL3;
	normalNum = 220;
	nuclearNum = 20;
	clusterNum = 10;
	napalmNum = 0;
	rodNum = 0;
	duration = 60.0f;
	schedule = Schedule(normalNum, nuclearNum, clusterNum, napalmNum, rodNum, duration);
}

void Level::SetLevelFour() {

	difficulty = Globals::LEVEL4;
	normalNum = 230;
	nuclearNum = 25;
	clusterNum = 20;
	napalmNum = 10;
	rodNum = 0;
	duration = 60.0f;
	schedule = Schedule(normalNum, nuclearNum, clusterNum, napalmNum, rodNum, duration);
}

void Level::SetLevelFive() {

	difficulty = Globals::LEVEL5;
	normalNum = 250;
	nuclearNum = 30;
	clusterNum = 25;
	napalmNum = 20;
	rodNum = 10;
	duration = 60.0f;
	schedule = Schedule(normalNum, nuclearNum, clusterNum, napalmNum, rodNum, duration);
}

Level::Level() {

	SetLevelOne();
}

Level::Level(int difficulty) {

	switch (difficulty) {

		case 1: 
			SetLevelOne();
			break;

		case 2:
			SetLevelTwo();
			break;

		case 3:
			SetLevelThree();
			break;

		case 4:
			SetLevelFour();
			break;

		case 5:
			SetLevelFive();
			break;

		default:
			SetLevelOne();
			break;
	}
}

int Level::GetDifficulty() {
	return difficulty;
}

int Level::GetNormalNum() {
	return normalNum;
}

int Level::GetNuclearNum() {
	return nuclearNum;
}

int Level::GetClusterNum() {
	return clusterNum;
}

int Level::GetNapalmNum() {
	return napalmNum;
}

int Level::GetRodNum() {
	return rodNum;
}

float Level::GetDuration() {
	return duration;
}

Schedule& Level::GetSchedule() {
	return schedule;
}
