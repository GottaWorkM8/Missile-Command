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

std::list<Bomb> Generator::GenerateBombs(int count) {

	std::list<Bomb> list;
	float bombOriginX;
	float bombTargetX;
	Point bombOrigin;
	Point bombTarget;
	float angleRad;

	for (int i = 0; i < count; i++) {

		bombOriginX = GetRandomUniform(Game::BOMB_ORIGIN_MIN_X, Game::BOMB_ORIGIN_MAX_X);
		bombOrigin = Point(bombOriginX, Game::BOMB_ORIGIN_Y);
		bombTargetX = GetRandomUniform(Game::BOMB_ORIGIN_MIN_X, Game::BOMB_ORIGIN_MAX_X);
		bombTarget = Point(bombTargetX, Game::GROUND_Y);
		angleRad = Calculator::GetRadians(bombOrigin, bombTarget);
		angleRad -= (float) M_PI_2;

		list.push_back(Bomb(Point(bombOriginX, Game::BOMB_ORIGIN_Y), angleRad));
	}
	
	return list;
}
