#include "Game.h"
#include <iostream>

const float Game::maxX = 1600.0f;
const float Game::maxY = 900.0f;
const float Game::groundY = maxY - (maxY / 7);
const float Game::gameFrameTime = 100 / 12; // 120 fps
Timer Game::gameTimer = Timer();
const int Game::maxAmmo = 5;
int Game::ammo = maxAmmo;
const float Game::ammoLoadTime = 0.5f;
Timer Game::ammoTimer = Timer();
const float Game::launcherHalfWidth = 35.0f;
const float Game::launcherHalfHeight = 30.0f;
const float Game::buildingHalfWidth = 25.0f;
const float Game::buildingHalfHeight = 25.0f;
const Point Game::missileOrigin = Point(maxX / 2, groundY - launcherHalfWidth * 2);
Point Game::missileTarget = Point(350.0f, 100.0f);
const float Game::missileHalfWidth = 10.0f;
const float Game::missileHalfHeight = 10.0f;
const float Game::missileSpeed = 10.0f;
const float Game::missileLoadTime = 0.1f;
Timer Game::missileTimer = Timer();
const float Game::bombOriginY = 0.0f;
const float Game::bombOriginMinX = maxX / 20;
const float Game::bombOriginMaxX = maxX - bombOriginMinX;
const float Game::bombHalfWidth = 10.0f;
const float Game::bombHalfHeight = 10.0f;
const float Game::bombTargetY = groundY - bombHalfHeight;
const float Game::bombSpeed = 1.5f;
const float Game::bombLoadTime = 1.0f;
Timer Game::bombTimer = Timer();
const float Game::explosionTime = 0.5f;
const float Game::explosionFinalTime = 0.25f;
const float Game::explosionInitialRadius = 20.0f;
const float Game::explosionFinalRadius = 80.0f;
const int Game::explosionStages = 20;
const float Game::explosionRadiusGrowth = (explosionFinalRadius - explosionInitialRadius) / explosionStages;
const float Game::explosionStageTime = explosionTime / explosionStages;

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
			
				ItemManager::AddMissileExplosion(Explosion(i->GetCenter(), 
					Game::explosionInitialRadius));
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

			if (j->GetCenter().y >= Game::bombTargetY) {

				ItemManager::AddBombExplosion(Explosion(j->GetCenter(),
					Game::explosionInitialRadius));
				bombs.erase(j++);
			}

			else {

				MoveBomb(*j);
				j++;
			}
		}

		std::list<Explosion>& missileExplosions = ItemManager::GetMissileExplosions();
		std::list<Explosion>::iterator k = missileExplosions.begin();

		while (k != missileExplosions.end()) {

			if (k->GetStage() == Game::explosionStages)
				missileExplosions.erase(k++);

			else {

				AdvanceExplosion(*k);
				k++;
			}
		}

		std::list<Explosion>& bombExplosions = ItemManager::GetBombExplosions();
		std::list<Explosion>::iterator l = bombExplosions.begin();

		while (l != bombExplosions.end()) {

			if (l->GetStage() == Game::explosionStages)
				bombExplosions.erase(l++);

			else {

				AdvanceExplosion(*l);
				l++;
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

	if (explosion.GetStageTimer().GetElapsedTime() > explosionStageTime) {

		explosion.GetStageTimer().Restart();
		explosion.GetStage()++;
		float newRadius = explosion.GetRadius() + explosionRadiusGrowth;
		explosion.SetRadius(newRadius);
	}
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


