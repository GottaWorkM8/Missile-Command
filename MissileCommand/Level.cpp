#include "Level.h"

void Level::SetLevelOne() {

	location = L"Grassy Plains";
	difficulty = Globals::LEVEL1;
	normalNum = 100;
	nuclearNum = 0;
	clusterNum = 0;
	napalmNum = 0;
	rodNum = 0;
	
}

void Level::SetLevelTwo() {

	location = L"Icy Peaks";
	difficulty = Globals::LEVEL2;
	normalNum = 100;
	nuclearNum = 15;
	clusterNum = 0;
	napalmNum = 0;
	rodNum = 0;
}

void Level::SetLevelThree() {

	location = L"Riverside";
	difficulty = Globals::LEVEL3;
	normalNum = 100;
	nuclearNum = 25;
	clusterNum = 15;
	napalmNum = 0;
	rodNum = 0;
}

void Level::SetLevelFour() {

	location = L"Scorching Desert";
	difficulty = Globals::LEVEL4;
	normalNum = 100;
	nuclearNum = 25;
	clusterNum = 25;
	napalmNum = 10;
	rodNum = 0;
}

void Level::SetLevelFive() {

	location = L"Hostile Planet";
	difficulty = Globals::LEVEL5;
	normalNum = 100;
	nuclearNum = 25;
	clusterNum = 25;
	napalmNum = 20;
	rodNum = 10;
}

Level::Level() {

	SetLevelOne();

	maxScore = Calculator::GetMaxScore(normalNum, nuclearNum, clusterNum, napalmNum, rodNum);
	duration = Globals::BOMB_SPAWN_TIME;
	schedule = Schedule(normalNum, nuclearNum, clusterNum, napalmNum, rodNum, duration);
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

	maxScore = Calculator::GetMaxScore(normalNum, nuclearNum, clusterNum, napalmNum, rodNum);
	duration = Globals::BOMB_SPAWN_TIME;
	schedule = Schedule(normalNum, nuclearNum, clusterNum, napalmNum, rodNum, duration);
}

const wchar_t* Level::GetLocation() {
	return location;
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

int Level::GetMaxScore() {
	return maxScore;
}

float Level::GetDuration() {
	return duration;
}

Schedule& Level::GetSchedule() {
	return schedule;
}
