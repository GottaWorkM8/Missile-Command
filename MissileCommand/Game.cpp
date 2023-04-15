#include "Game.h"
#include <iostream>

const float Game::maxX = 700.0f;
const float Game::maxY = 700.0f;
const float Game::groundY = maxY - 100.0f;
const float Game::gameFrameTime = 100 / 12; // 120 fps
Timer Game::gameTimer = Timer();
const int Game::maxAmmo = 5;
int Game::ammo = maxAmmo;
const float Game::ammoLoadTime = 0.5f;
Timer Game::ammoTimer = Timer();
const float Game::launcherHalfWidth = 25.0f;
const float Game::launcherHalfHeight = 25.0f;
const float Game::buildingHalfWidth = 25.0f;
const float Game::buildingHalfHeight = 25.0f;
const Point Game::missileOrigin = Point(maxX / 2, groundY - launcherHalfWidth * 2);
Point Game::missileTarget = Point(350.0f, 100.0f);
const float Game::missileHalfWidth = 10.0f;
const float Game::missileHalfHeight = 10.0f;
const float Game::missileSpeed = 10.0f;
const float Game::missileLoadTime = 0.1f;
Timer Game::missileTimer = Timer();
const float Game::bombOriginY = 50.0f;
const float Game::bombOriginMinX = 50.0f;
const float Game::bombOriginMaxX = maxX - bombOriginMinX;
const float Game::bombHalfWidth = 10.0f;
const float Game::bombHalfHeight = 10.0f;
const float Game::bombSpeed = 1.5f;
const float Game::bombLoadTime = 1.0f;
Timer Game::bombTimer = Timer();
const float Game::explosionTime = 1.5f;
const float Game::explosionFinalTime = 0.5f;
const float Game::explosionInitialRadius = 50.0f;
const float Game::explosionFinalRadius = 100.0f;
const int Game::explosionStages = 10;

void Game::Run() {

	bool running = true;
	gameTimer.Restart();
	bombTimer.Restart();
	ammoTimer.Restart();

	while (running) {

		std::list<Missile>& missiles = ItemManager::GetMissiles();
		std::list<Missile>::iterator i = missiles.begin();

		while (i != missiles.end()) {
		
			if (i->GetCenter().y <= i->GetTarget().y) {
			
				ItemManager::AddExplosion(Explosion(i->GetCenter(), 
					Game::explosionInitialRadius, Game::explosionTime));
				missiles.erase(i++);
			}

			else {
			
				MoveMissile(*i);
				i++;
			}
		}

		std::list<Bomb>& bombs = ItemManager::GetBombs();
		std::list<Bomb>::iterator j = bombs.begin();

		while (j != bombs.end()) {

			if (j->GetCenter().y >= Game::groundY) {

				ItemManager::AddExplosion(Explosion(j->GetCenter(),
					Game::explosionInitialRadius, Game::explosionTime));
				bombs.erase(j++);
			}

			else {

				MoveBomb(*j);
				j++;
			}
		}

		std::list<Explosion>& explosions = ItemManager::GetExplosions();
		std::list<Explosion>::iterator k = explosions.begin();

		while (k != explosions.end()) {

			if (k->GetDuration() >= Game::explosionTime)
				explosions.erase(k++);

			else {

				AdvanceExplosion(*k);
				k++;
			}
		}

		if (ammoTimer.GetElapsedTime() > ammoLoadTime)
			AddAmmo();

		if (bombTimer.GetElapsedTime() > bombLoadTime)
			DropBombs();

		float time = gameTimer.GetDeltaTime();

		if (time < gameFrameTime)
			Sleep(gameFrameTime - time);
	}
}

void Game::MoveMissile(Missile& missile) {

	missile.SetCenter(Calculator::GetNextPos(missile.GetCenter(), missile.GetAngleRad(), missileSpeed));
}

void Game::MoveBomb(Bomb& bomb) {

	bomb.SetCenter(Calculator::GetNextPos(bomb.GetCenter(), bomb.GetAngleRad(), bombSpeed));
}

void Game::AdvanceExplosion(Explosion& explosion) {

	explosion.GetRadius();
}

void Game::ChooseTarget(HWND& hWnd) {

	POINT target;

	GetCursorPos(&target);
	ScreenToClient(hWnd, &target);

	missileTarget.x = target.x;
	missileTarget.y = target.y;

	LaunchMissile();
}

void Game::AddAmmo() {

	ammoTimer.Restart();

	if (ammo < maxAmmo)
		ammo++;
}

void Game::LaunchMissile() {
	
	if (ammo > 0) {

		float angleRad = Calculator::GetRadians(missileOrigin, missileTarget);

		if (angleRad >= 0.0f) {

			ammo--;

			if (ammo == maxAmmo - 1)
				ammoTimer.Restart();

			angleRad -= M_PI_2;
			ItemManager::AddMissile(Missile(missileOrigin, missileTarget, angleRad));
		}
	}
}

//void Game::ExplodeMissile(Missile& missile) {
//
//	ItemManager::RemoveMissile(missile);
//}

void Game::DropBombs() {

	bombTimer.Restart();
	ItemManager::AddBombs(Generator::GenerateBombs(2));
}

//void Game::ExplodeBomb(Bomb& bomb) {
//
//	ItemManager::RemoveBomb(bomb);
//}

//void Game::DestroyBuilding(Building& building) {
//
//	ItemManager::RemoveBuilding(building);
//}


