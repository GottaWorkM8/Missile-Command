#include "Game.h"

bool Game::won = false;
bool Game::finished = false;
int Game::ammo = Globals::MAX_AMMO;
Timer Game::levelTimer = Timer();
Timer Game::ammoTimer = Timer();
Timer Game::missileTimer = Timer();
Timer Game::bombTimer = Timer();
Point Game::missileOrigin = Point();
Point Game::missileTarget = Point();

void Game::Run(int difficulty) {

	/*Level level = Level(difficulty);*/

	levelTimer.Restart();
	ammoTimer.Restart();
	bombTimer.Restart();

	while (true) {

		std::list<Missile>& missiles = ItemManager::GetMissiles();
		std::list<Missile>::iterator i = missiles.begin();

		while (i != missiles.end()) {
		
			if (i->GetCenter().y <= i->GetTarget().y) {
			
				ItemManager::AddExplosion(Explosion(i->GetCenter(), 
					Globals::EXPLOSION_INITIAL_RADIUS, MISSILE));
				missiles.erase(i++);
			}

			else {
			
				MoveMissile(*i);
				i++;
			}
		}

		Launcher& launcher = ItemManager::GetLauncher();
		std::list<Bomb>& bombs = ItemManager::GetBombs();
		std::list<Building>& buildings = ItemManager::GetBuildings();
		std::list<Explosion>& explosions = ItemManager::GetExplosions();
		std::list<Explosion>::iterator j = explosions.begin();

		while (j != explosions.end()) {

			std::list<Bomb>::iterator k = bombs.begin();

			while (k != bombs.end()) {

				if (Verifier::BombHit(*k, *j)) {

					ItemManager::AddExplosion(Explosion(k->GetCenter(),
						Globals::EXPLOSION_INITIAL_RADIUS, NORMAL));
					bombs.erase(k++);
				}

				else k++;
			}

			std::list<Building>::iterator l = buildings.begin();

			while (l != buildings.end()) {

				if (Verifier::BuildingHit(*l, *j))
					buildings.erase(l++);

				else l++;
			}

			if (j->GetStage() == Globals::EXPLOSION_STAGES)
				explosions.erase(j++);

			else if (j->GetStage() == Globals::EXPLOSION_STAGES - 1) {
			
				AdvanceExplosionFinal(*j);
				j++;
			}

			else {

				AdvanceExplosion(*j);
				j++;
			}
		}

		std::list<Bomb>::iterator k = bombs.begin();

		while (k != bombs.end()) {

			if (k->GetCenter().y >= Globals::BOMB_TARGET_Y) {

				ItemManager::AddExplosion(Explosion(k->GetCenter(),
					Globals::EXPLOSION_INITIAL_RADIUS, NORMAL));
				bombs.erase(k++);
			}

			else {

				MoveBomb(*k);
				k++;
			}
		}

		std::list<Flash>& flashes = ItemManager::GetFlashes();
		std::list<Flash>::iterator m = flashes.begin();

		while (m != flashes.end()) {

			if (m->GetStage() == Globals::FLASH_STAGES)
				flashes.erase(m++);

			else {

				AdvanceFlash(*m);
				m++;
			}
		}

		if (ammoTimer.GetElapsedTime() > Globals::AMMO_LOAD_TIME)
			AddAmmo();

		float time = levelTimer.GetElapsedTime();

		if (time <= Globals::GAME_TIME)
			if (bombTimer.GetElapsedTime() > Globals::BOMB_LOAD_TIME)
				DropBombs();

		if (Verifier::GameLost(launcher, buildings))
			finished = true;

		if (time > Globals::GAME_TIME)
			if (bombs.empty() && !finished) {

				finished = true;
				won = true;
			}

		float deltaTime = levelTimer.GetDeltaTime();

		if (deltaTime < Globals::FRAME_TIME)
			Sleep(Globals::FRAME_TIME - deltaTime);
	}
}

void Game::MoveMissile(Missile& missile) {

	missile.SetCenter(Calculator::GetNextPos(missile.GetCenter(), missile.GetAngleRad(), Globals::MISSILE_SPEED));
}

void Game::MoveBomb(Bomb& bomb) {

	bomb.SetCenter(Calculator::GetNextPos(bomb.GetCenter(), bomb.GetAngleRad(), Globals::BOMB_SPEED));
}

void Game::AdvanceExplosion(Explosion& explosion) {

	if (explosion.GetStageTimer().GetElapsedTime() > Globals::EXPLOSION_STAGE_TIME) {

		explosion.GetStageTimer().Restart();
		explosion.GetStage()++;
		float newRadius = explosion.GetRadius() + Globals::EXPLOSION_RADIUS_GROWTH;
		explosion.SetRadius(newRadius);
	}
}

void Game::AdvanceExplosionFinal(Explosion& explosion) {

	if (explosion.GetStageTimer().GetElapsedTime() > Globals::EXPLOSION_FINAL_TIME)
		explosion.GetStage()++;
}

void Game::AdvanceFlash(Flash& flash) {

	if (flash.GetStageTimer().GetElapsedTime() > Globals::FLASH_STAGE_TIME) {

		flash.GetStageTimer().Restart();
		flash.GetStage()++;
		float newRadius = flash.GetRadius() + Globals::FLASH_RADIUS_GROWTH;
		flash.SetRadius(newRadius);
	}
}

void Game::UpdateTarget(HWND& hWnd) {

	POINT target;
	GetCursorPos(&target);
	ScreenToClient(hWnd, &target);
	missileTarget.x = target.x;
	missileTarget.y = target.y;
	LaunchMissile();
}

void Game::UpdateLauncherCannon(HWND& hWnd) {

	POINT cursorPos;
	GetCursorPos(&cursorPos);
	ScreenToClient(hWnd, &cursorPos);
	Point pos = Point(cursorPos.x, cursorPos.y);
	float angleRad = Calculator::GetRadians(Globals::LAUNCHER_CANNON_BOTTOM_CENTER, pos);

	if (angleRad < 0.0f) {

		if (pos.x < Globals::CENTER_X)
			angleRad = 0.0f;

		else angleRad = M_PI;
	}

	angleRad -= M_PI_2;
	ItemManager::GetLauncher().SetAngle(angleRad);
	missileOrigin = Calculator::GetPosBetween(Globals::LAUNCHER_CANNON_BOTTOM_CENTER,
		pos, Globals::LAUNCHER_CANNON_HALF_HEIGHT * 2);
}

void Game::AddAmmo() {

	ammoTimer.Restart();

	if (ammo < Globals::MAX_AMMO)
		ammo++;
}

void Game::LaunchMissile() {
	
	if (!finished)
		if (ammo > 0) {

			float angleRad = Calculator::GetRadians(missileOrigin, missileTarget);

			if (angleRad >= 0.0f) {

				ammo--;

				if (ammo == Globals::MAX_AMMO - 1)
					ammoTimer.Restart();

				angleRad -= M_PI_2;
				ItemManager::AddMissile(Missile(missileOrigin, missileTarget, angleRad));
				ItemManager::AddFlash(Flash(missileOrigin, Globals::FLASH_INITIAL_RADIUS, angleRad));
			}
		}
}

void Game::DropBombs() {

	bombTimer.Restart();
	ItemManager::AddBombs(Generator::GenerateBombs(NORMAL, 2));
}
