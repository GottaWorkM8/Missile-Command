#include "Generator.h"

std::random_device Generator::device;
std::mt19937 Generator::generator(device());

float Generator::GetRandomUniform(float min, float max) {

	std::uniform_real_distribution<> distribution(min, max);

	return (float) distribution(generator);
}

float Generator::GetRandomNormal(float min, float max) {

	std::normal_distribution<> distribution(min, max);

	return (float) distribution(generator);
}

Bomb Generator::GenerateBomb(Source source) {

	float bombOriginX = GetRandomUniform(Globals::BOMB_ORIGIN_MIN_X, Globals::BOMB_ORIGIN_MAX_X);
	float bombTargetX = GetRandomUniform(Globals::BOMB_ORIGIN_MIN_X, Globals::BOMB_ORIGIN_MAX_X);
	Point bombOrigin = Point(bombOriginX, Globals::BOMB_ORIGIN_Y);
	Point bombTarget = Point(bombTargetX, Globals::GROUND_Y);
	float angleRad = Calculator::GetRadians(bombOrigin, bombTarget);
	angleRad -= (float)M_PI_2;
	
	switch (source) {

		case NORMAL:
		case NUCLEAR:
		case CLUSTER:
		case NAPALM:
		case RODOFGOD:
			return Bomb(bombOrigin, angleRad, source);

		default:
			return Bomb(bombOrigin, angleRad, NORMAL);
	}
}

std::list<Bomb> Generator::GenerateBombs(Source source, int count) {

	std::list<Bomb> list;

	for (int i = 0; i < count; i++)
		list.push_back(GenerateBomb(source));
	
	return list;
}
