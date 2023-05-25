#include "Game.h"

bool Game::won = false;
bool Game::finished = false;

const float Game::MAX_X = 1600.0f;
const float Game::CENTER_X = MAX_X / 2;
const float Game::MAX_Y = 900.0f;
const float Game::GROUND_Y = MAX_Y - (MAX_Y / 7);

const float Game::FRAME_TIME = 100 / 12; // 120 fps
const float Game::GAME_TIME = 20.0f; // 60 second turn
Timer Game::gameTimer = Timer();

const int Game::MAX_AMMO = 5;
int Game::ammo = MAX_AMMO;
const float Game::AMMO_LOAD_TIME = 0.5f;
Timer Game::ammoTimer = Timer();

const float Game::LAUNCHER_HP = 250.0f;
const float Game::LAUNCHER_HALF_WIDTH = 35.0f;
const float Game::LAUNCHER_HALF_HEIGHT = 30.0f;
const Point Game::LAUNCHER_CENTER = Point(CENTER_X, GROUND_Y - LAUNCHER_HALF_HEIGHT);
const float Game::LAUNCHER_CANNON_HALF_WIDTH = 15.0f;
const float Game::LAUNCHER_CANNON_HALF_HEIGHT = 30.0f;
const Point Game::LAUNCHER_CANNON_BOTTOM_CENTER = Point(LAUNCHER_CENTER.x, LAUNCHER_CENTER.y);

const float Game::BUILDING_HP = 100.0f;
const float Game::BUILDING_HALF_WIDTH = 25.0f;
const float Game::BUILDING_HALF_HEIGHT = 25.0f;

Point Game::missileOrigin = Point();
Point Game::missileTarget = Point();
const float Game::MISSILE_HALF_WIDTH = 10.0f;
const float Game::MISSILE_HALF_HEIGHT = 10.0f;
const float Game::MISSILE_SPEED = 10.0f;
const float Game::MISSILE_LOAD_TIME = 0.1f;
Timer Game::missileTimer = Timer();

const float Game::BOMB_ORIGIN_Y = 0.0f;
const float Game::BOMB_ORIGIN_MIN_X = MAX_X / 20;
const float Game::BOMB_ORIGIN_MAX_X = MAX_X - BOMB_ORIGIN_MIN_X;
const float Game::BOMB_HALF_WIDTH = 10.0f;
const float Game::BOMB_HALF_HEIGHT = 10.0f;
const float Game::BOMB_TARGET_Y = GROUND_Y - BOMB_HALF_HEIGHT;
const float Game::BOMB_SPEED = 1.5f;
const float Game::BOMB_LOAD_TIME = 1.0f;
Timer Game::bombTimer = Timer();

const float Game::EXPLOSION_PROPAGATION_TIME = 0.5f;
const float Game::EXPLOSION_FINAL_TIME = 0.2f;
const float Game::EXPLOSION_INITIAL_RADIUS = 20.0f;
const float Game::EXPLOSION_FINAL_RADIUS = 80.0f;
const int Game::EXPLOSION_STAGES = 20;
const float Game::EXPLOSION_RADIUS_GROWTH = (EXPLOSION_FINAL_RADIUS 
	- EXPLOSION_INITIAL_RADIUS) / EXPLOSION_STAGES;
const float Game::EXPLOSION_STAGE_TIME = EXPLOSION_PROPAGATION_TIME / EXPLOSION_STAGES;

const float Game::FLASH_PROPAGATION_TIME = 0.1;
const float Game::FLASH_INITIAL_RADIUS = 5.0f;
const float Game::FLASH_FINAL_RADIUS = 15.0f;
const float Game::FLASH_STAGES = 10;
const float Game::FLASH_RADIUS_GROWTH = (FLASH_FINAL_RADIUS - FLASH_INITIAL_RADIUS) / FLASH_STAGES;
const float Game::FLASH_STAGE_TIME = FLASH_PROPAGATION_TIME / FLASH_STAGES;

void Game::Run() {

	gameTimer.Restart();
	bombTimer.Restart();
	ammoTimer.Restart();

	while (true) {

		std::list<Missile>& missiles = ItemManager::GetMissiles();
		std::list<Missile>::iterator i = missiles.begin();

		while (i != missiles.end()) {
		
			if (i->GetCenter().y <= i->GetTarget().y) {
				Music::musicExploxion();
				ItemManager::AddExplosion(Explosion(i->GetCenter(), 
					Game::EXPLOSION_INITIAL_RADIUS, missile));
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
					Music::musicExploxion();
					ItemManager::AddExplosion(Explosion(k->GetCenter(),
						Game::EXPLOSION_INITIAL_RADIUS, normal));
					bombs.erase(k++);
				}

				else k++;
			}

			std::list<Building>::iterator l = buildings.begin();

			while (l != buildings.end()) {

				if (Verifier::BuildingHit(*l, *j)) {
					buildings.erase(l++);
				}
				else l++;
			}

			if (j->GetStage() == Game::EXPLOSION_STAGES)
				explosions.erase(j++);

			else if (j->GetStage() == Game::EXPLOSION_STAGES - 1) {
			
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

			if (k->GetCenter().y >= Game::BOMB_TARGET_Y) {
				Music::musicExploxion();
				ItemManager::AddExplosion(Explosion(k->GetCenter(),
					Game::EXPLOSION_INITIAL_RADIUS, normal));
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

			if (m->GetStage() == Game::FLASH_STAGES)
				flashes.erase(m++);

			else {

				AdvanceFlash(*m);
				m++;
			}
		}

		if (ammoTimer.GetElapsedTime() > AMMO_LOAD_TIME)
			AddAmmo();

		float time = gameTimer.GetElapsedTime();

		if (time <= GAME_TIME)
			if (bombTimer.GetElapsedTime() > BOMB_LOAD_TIME)
				DropBombs();

		if (Verifier::GameLost(launcher, buildings))
			finished = true;

		if (time > GAME_TIME)
			if (bombs.empty() && !finished) {

				finished = true;
				won = true;
			}

		float deltaTime = gameTimer.GetDeltaTime();

		if (deltaTime < FRAME_TIME)
			Sleep(FRAME_TIME - deltaTime);
	}
}

void Game::MoveMissile(Missile& missile) {

	missile.SetCenter(Calculator::GetNextPos(missile.GetCenter(), missile.GetAngleRad(), MISSILE_SPEED));
}

void Game::MoveBomb(Bomb& bomb) {

	bomb.SetCenter(Calculator::GetNextPos(bomb.GetCenter(), bomb.GetAngleRad(), BOMB_SPEED));
}

void Game::AdvanceExplosion(Explosion& explosion) {

	if (explosion.GetStageTimer().GetElapsedTime() > EXPLOSION_STAGE_TIME) {

		explosion.GetStageTimer().Restart();
		explosion.GetStage()++;
		float newRadius = explosion.GetRadius() + EXPLOSION_RADIUS_GROWTH;
		explosion.SetRadius(newRadius);
	}
}

void Game::AdvanceExplosionFinal(Explosion& explosion) {

	if (explosion.GetStageTimer().GetElapsedTime() > EXPLOSION_FINAL_TIME)
		explosion.GetStage()++;
}

void Game::AdvanceFlash(Flash& flash) {

	if (flash.GetStageTimer().GetElapsedTime() > FLASH_STAGE_TIME) {

		flash.GetStageTimer().Restart();
		flash.GetStage()++;
		float newRadius = flash.GetRadius() + FLASH_RADIUS_GROWTH;
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
	float angleRad = Calculator::GetRadians(LAUNCHER_CANNON_BOTTOM_CENTER, pos);

	if (angleRad < 0.0f) {

		if (pos.x < CENTER_X)
			angleRad = 0.0f;

		else angleRad = M_PI;
	}

	angleRad -= M_PI_2;
	ItemManager::GetLauncher().SetAngle(angleRad);
	missileOrigin = Calculator::GetPosBetween(LAUNCHER_CANNON_BOTTOM_CENTER, 
		pos, LAUNCHER_CANNON_HALF_HEIGHT * 2);
}

void Game::AddAmmo() {

	ammoTimer.Restart();

	if (ammo < MAX_AMMO)
		ammo++;
}

void Game::LaunchMissile() {
	
	if (!finished)
		if (ammo > 0) {

			float angleRad = Calculator::GetRadians(missileOrigin, missileTarget);

			if (angleRad >= 0.0f) {
				Music::musicMissle();
				ammo--;

				if (ammo == MAX_AMMO - 1)
					ammoTimer.Restart();

				angleRad -= M_PI_2;
				ItemManager::AddMissile(Missile(missileOrigin, missileTarget, angleRad));
				ItemManager::AddFlash(Flash(missileOrigin, FLASH_INITIAL_RADIUS, angleRad));
			}
		}
}

void Game::DropBombs() {

	bombTimer.Restart();
	ItemManager::AddBombs(Generator::GenerateBombs(2));
}
