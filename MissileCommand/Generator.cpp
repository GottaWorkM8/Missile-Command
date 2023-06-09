#include "Generator.h"

std::random_device Generator::device;
std::mt19937 Generator::generator(device());


int Generator::GetRandomUniform(int min, int max) {

	std::uniform_int_distribution<int> distribution(min, max);

	return distribution(generator);
}

float Generator::GetRandomUniform(float min, float max) {

	std::uniform_real_distribution<float> distribution(min, max);

	return distribution(generator);
}

float Generator::GetRandomNormal(float min, float max) {

	std::normal_distribution<float> distribution(min, max);

	return distribution(generator);
}

Bomb Generator::GenerateBomb(Source source) {

	float bombOriginX = GetRandomUniform(Globals::BOMB_ORIGIN_MIN_X, Globals::BOMB_ORIGIN_MAX_X);
	float bombTargetX = GetRandomUniform(Globals::BOMB_ORIGIN_MIN_X, Globals::BOMB_ORIGIN_MAX_X);
	Point bombOrigin = Point(bombOriginX, Globals::BOMB_ORIGIN_Y);
	Point bombTarget;

	if (source == RODOFGOD)
		bombTarget = Point(bombOriginX, Globals::GROUND_Y);

	else bombTarget = Point(bombTargetX, Globals::GROUND_Y);

	float angleRad = Calculator::GetRadians(bombOrigin, bombTarget);
	angleRad -= (float) M_PI_2;
	
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

Bomb Generator::GenerateBomblet(Explosion& clusterExplosion) {

	float bombTargetX = GetRandomUniform(Globals::BOMB_ORIGIN_MIN_X, Globals::BOMB_ORIGIN_MAX_X);
	Point bombOrigin = Point(clusterExplosion.GetCenter().x, clusterExplosion.GetCenter().y);
	Point bombTarget = Point(bombTargetX, Globals::GROUND_Y);
	float angleRad = Calculator::GetRadians(bombOrigin, bombTarget);
	angleRad -= (float)M_PI_2;

	return Bomb(bombOrigin, angleRad, BOMBLET);
}
