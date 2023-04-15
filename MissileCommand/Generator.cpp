#include "Generator.h"
#include <iostream>

std::list<Bomb> Generator::GenerateBombs(int count) {

	std::list<Bomb> list;
	float bombOriginX;
	float bombTargetX;
	Point bombOrigin;
	Point bombTarget;
	float angleRad;

	for (int i = 0; i < count; i++) {

		bombOriginX = Calculator::GetRandomUniform(Game::bombOriginMinX, Game::bombOriginMaxX);
		bombOrigin = Point(bombOriginX, Game::bombOriginY);
		bombTargetX = Calculator::GetRandomUniform(Game::bombOriginMinX, Game::bombOriginMaxX);
		bombTarget = Point(bombTargetX, Game::groundY);
		angleRad = Calculator::GetRadians(bombOrigin, bombTarget);
		angleRad -= M_PI_2;

		list.push_back(Bomb(Point(bombOriginX, Game::bombOriginY), angleRad));
	}
	
	return list;
}
