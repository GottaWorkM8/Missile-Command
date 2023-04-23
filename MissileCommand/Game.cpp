#include "Game.h"

const float Game::MAX_X = 1600.0f;
const float Game::MAX_Y = 900.0f;
const float Game::GROUND_Y = MAX_Y - (MAX_Y / 7);
const float Game::FRAME_TIME = 100 / 12; // 120 fps
Timer Game::gameTimer = Timer();
const int Game::MAX_AMMO = 5;
int Game::ammo = MAX_AMMO;
const float Game::AMMO_LOAD_TIME = 0.5f;
Timer Game::ammoTimer = Timer();
const float Game::LAUNCHER_HALF_WIDTH = 35.0f;
const float Game::LAUNCHER_HALF_HEIGHT = 30.0f;

const float Game::START_BUTTON_HALF_WIDTH = 190.0f;
const float Game::START_BUTTON_HALF_HEIGHT = 70.0f;

const float Game::BUILDING_HALF_WIDTH = 25.0f;
const float Game::BUILDING_HALF_HEIGHT = 25.0f;
const Point Game::missileOrigin = Point(MAX_X / 2, GROUND_Y - LAUNCHER_HALF_WIDTH * 2);
Point Game::missileTarget = Point(350.0f, 100.0f);
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
bool Game::running = true;

void Game::Run() {
	gameTimer.Restart();
	bombTimer.Restart();
	ammoTimer.Restart();

	while (running) {

		std::list<Missile>& missiles = ItemManager::GetMissiles();
		std::list<Missile>::iterator i = missiles.begin();

		while (i != missiles.end()) {
		
			if (i->GetCenter().y <= i->GetTarget().y) {
			
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

				if (Verifier::IsBombHit(*k, *j)) {

					ItemManager::AddExplosion(Explosion(k->GetCenter(),
						Game::EXPLOSION_INITIAL_RADIUS, normal));
					bombs.erase(k++);
				}

				else k++;
			}

			std::list<Building>::iterator l = buildings.begin();

			while (l != buildings.end()) {

				if (Verifier::IsBuildingHit(*l, *j))
					buildings.erase(l++);

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

				ItemManager::AddExplosion(Explosion(k->GetCenter(),
					Game::EXPLOSION_INITIAL_RADIUS, normal));
				bombs.erase(k++);
			}

			else {

				MoveBomb(*k);
				k++;
			}
		}

		if (ammoTimer.GetElapsedTime() > AMMO_LOAD_TIME)
			AddAmmo();

		if (bombTimer.GetElapsedTime() > BOMB_LOAD_TIME)
			DropBombs();

		float time = gameTimer.GetDeltaTime();

		if (time < FRAME_TIME)
			Sleep(FRAME_TIME - time);

		if (buildings.empty()) {
			running = false;
		}
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

void Game::ChooseTarget(HWND& hWnd) {

	POINT target;

	GetCursorPos(&target);
	ScreenToClient(hWnd, &target);

	missileTarget.x = target.x;
	missileTarget.y = target.y;

	LaunchMissile();
}

bool Game::ChooseOption(HWND& hWnd) {

	POINT option;

	GetCursorPos(&option);
	ScreenToClient(hWnd, &option);

	Point startButton = Point(Game::MAX_X / 2, Game::GROUND_Y - Game::LAUNCHER_HALF_HEIGHT);

	if( (option.x >= ( startButton.x - Game::START_BUTTON_HALF_WIDTH )) && (option.x <= (startButton.x + Game::START_BUTTON_HALF_WIDTH))
		&& (option.y >= (startButton.x - Game::START_BUTTON_HALF_HEIGHT)) && (option.y <= (startButton.x + Game::START_BUTTON_HALF_HEIGHT))) {
		return true;
	}

	return false;
}

void Game::AddAmmo() {

	ammoTimer.Restart();

	if (ammo < MAX_AMMO)
		ammo++;
}

void Game::LaunchMissile() {
	
	if (ammo > 0) {

		float angleRad = Calculator::GetRadians(missileOrigin, missileTarget);

		if (angleRad >= 0.0f) {

			ammo--;

			if (ammo == MAX_AMMO - 1)
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


