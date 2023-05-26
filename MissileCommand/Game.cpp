#include "Game.h"

bool Game::intro = true;
bool Game::won = false;
bool Game::finished = true;
const wchar_t* Game::location = L"";
int Game::ammo = Globals::MAX_AMMO;
int Game::score = 0;
int Game::diff = 0;
int Game::normalNum = 0;
int Game::nuclearNum = 0;
int Game::clusterNum = 0;
int Game::napalmNum = 0;
int Game::rodNum = 0;
Timer Game::levelTimer = Timer();
Timer Game::ammoTimer = Timer();
Timer Game::missileTimer = Timer();
Point Game::missileOrigin = Point();
Point Game::missileTarget = Point();

bool Game::GetIntro() {
	return intro;
}

const wchar_t* Game::GetLocation() {
	return location;
}

int Game::GetAmmo() {
	return ammo;
}

int Game::GetScore() {
	return score;
}

int Game::GetDiff() {
	return diff;
}

int Game::GetNormalNum() {
	return normalNum;
}

int Game::GetNuclearNum() {
	return nuclearNum;
}

int Game::GetClusterNum() {
	return clusterNum;
}

int Game::GetNapalmNum() {
	return napalmNum;
}

int Game::GetRodNum() {
	return rodNum;
}

void Game::Run(int difficulty) {

	Level level = Level(difficulty);
	location = level.GetLocation();
	score = 0;
	diff = level.GetDifficulty();
	normalNum = level.GetNormalNum();
	nuclearNum = level.GetNuclearNum();
	clusterNum = level.GetClusterNum();
	napalmNum = level.GetNapalmNum();
	rodNum = level.GetRodNum();
	ItemManager::Reset();

	Popup::CreateIntroThread();
	Sleep(Globals::INTRO_TIME * 1000);
	intro = false;
	finished = false;

	levelTimer.Restart();
	ammoTimer.Restart();

	while (true) {

		std::thread missilesThread(HandleMissiles);
		std::thread explosionsThread(HandleExplosions);
		std::thread bombsThread(HandleBombs);
		std::thread flashesThread(HandleFlashes);
		std::thread destructionsThread(HandleDestructions);

		missilesThread.join();
		explosionsThread.join();
		bombsThread.join();
		flashesThread.join();
		destructionsThread.join();

		if (ammoTimer.GetElapsedTime() > Globals::AMMO_LOAD_TIME)
			AddAmmo();

		float time = levelTimer.GetElapsedTime();

		if (time <= Globals::GAME_TIME)
			DropBombs(level.GetSchedule());

		Launcher& launcher = ItemManager::GetLauncher();
		std::list<Building>& buildings = ItemManager::GetBuildings();

		if (Verifier::GameLost(launcher, buildings))
			finished = true;

		std::list<Bomb>& bombs = ItemManager::GetBombs();

		if (Verifier::GameWon(bombs, time, finished)) {

			finished = true;
			won = true;
		}

		float deltaTime = levelTimer.GetDeltaTime();

		if (deltaTime < Globals::FRAME_TIME)
			Sleep(Globals::FRAME_TIME - deltaTime);
	}
}

void Game::HandleMissiles() {

	std::mutex missilesMutex;
	std::lock_guard<std::mutex> lock(missilesMutex);

	std::list<Missile>& missiles = ItemManager::GetMissiles();
	std::list<Missile>::iterator i = missiles.begin();

	while (i != missiles.end()) {

		if (i->GetCenter().y <= i->GetTarget().y) {

			Music::PlayExplosion();
			ItemManager::AddExplosion(Explosion(i->GetCenter(),
				Globals::EXPLOSION_INITIAL_RADIUS, MISSILE));
			missiles.erase(i++);
		}

		else {

			MoveMissile(*i);
			i++;
		}
	}
}

void Game::HandleExplosions() {

	std::mutex explosionsMutex;
	std::lock_guard<std::mutex> lock(explosionsMutex);

	Launcher& launcher = ItemManager::GetLauncher();
	std::list<Bomb>& bombs = ItemManager::GetBombs();
	std::list<Building>& buildings = ItemManager::GetBuildings();
	std::list<Explosion>& explosions = ItemManager::GetExplosions();
	std::list<Explosion>::iterator j = explosions.begin();

	while (j != explosions.end()) {

		std::list<Bomb>::iterator k = bombs.begin();

		while (k != bombs.end()) {

			if (Verifier::BombHit(*k, *j)) {

				Music::PlayExplosion();
				ItemManager::AddExplosion(Explosion(k->GetCenter(),
					Globals::EXPLOSION_INITIAL_RADIUS, k->GetSource()));
				UpdateBombNum(k->GetSource());
				AwardPoints(k->GetSource());
				bombs.erase(k++);
			}

			else k++;
		}

		std::list<Building>::iterator l = buildings.begin();

		while (l != buildings.end()) {

			if (Verifier::BuildingHit(*l, *j)) {

				ItemManager::AddDestruction(Destruction(l->GetCenter(),
					Globals::DESTRUCTION_INITIAL_RADIUS));
				buildings.erase(l++);
			}

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
}

void Game::HandleBombs() {

	std::mutex bombsMutex;
	std::lock_guard<std::mutex> lock(bombsMutex);

	std::list<Bomb>& bombs = ItemManager::GetBombs();
	std::list<Bomb>::iterator k = bombs.begin();

	while (k != bombs.end()) {

		if (k->GetCenter().y >= Globals::BOMB_TARGET_Y) {

			Music::PlayExplosion();
			ItemManager::AddExplosion(Explosion(k->GetCenter(),
				Globals::EXPLOSION_INITIAL_RADIUS, k->GetSource()));
			UpdateBombNum(k->GetSource());
			CutPoints(k->GetSource());
			bombs.erase(k++);
		}

		else {

			MoveBomb(*k);
			k++;
		}
	}
}

void Game::HandleFlashes() {

	std::mutex flashesMutex;
	std::lock_guard<std::mutex> lock(flashesMutex);

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
}

void Game::HandleDestructions() {

	std::mutex destructionsMutex;
	std::lock_guard<std::mutex> lock(destructionsMutex);

	std::list<Destruction>& destructions = ItemManager::GetDestructions();
	std::list<Destruction>::iterator n = destructions.begin();

	while (n != destructions.end()) {

		if (n->GetStage() == Globals::DESTRUCTION_STAGES)
			destructions.erase(n++);

		else {

			AdvanceDestruction(*n);
			n++;
		}
	}
}

void Game::MoveMissile(Missile& missile) {

	missile.SetCenter(Calculator::GetNextPos(missile.GetCenter(), missile.GetAngleRad(), Globals::MISSILE_SPEED));
}

void Game::MoveBomb(Bomb& bomb) {

	float speed;

	switch (bomb.GetSource()) {

		case NORMAL: speed = Globals::NORMAL_BOMB_SPEED;
			break;

		case NUCLEAR: speed = Globals::NUCLEAR_BOMB_SPEED;
			break;

		case CLUSTER: speed = Globals::CLUSTER_BOMB_SPEED;
			break;

		case NAPALM: speed = Globals::NAPALM_BOMB_SPEED;
			break;

		case RODOFGOD: speed = Globals::ROD_BOMB_SPEED;
			break;

		default: speed = Globals::NORMAL_BOMB_SPEED;
			break;
	}

	bomb.SetCenter(Calculator::GetNextPos(bomb.GetCenter(), bomb.GetAngleRad(), speed));
}

void Game::RotateExplosion(Explosion& explosion) {

	float newAngleDeg = explosion.GetAngleDeg() + Generator::GetRandomUniform(0, 180.0f);

	if (newAngleDeg > 360.0f)
		newAngleDeg -= 360.0f;

	float newAngleRad = Calculator::GetRadians(newAngleDeg);
	explosion.SetAngleDeg(newAngleDeg);
	explosion.SetAngleRad(newAngleRad);
}

void Game::AdvanceExplosion(Explosion& explosion) {

	if (explosion.GetStageTimer().GetElapsedTime() > Globals::EXPLOSION_STAGE_TIME) {

		explosion.GetStageTimer().Restart();
		explosion.GetStage()++;
		float newRadius = explosion.GetRadius();

		switch (explosion.GetSource()) {

			case NORMAL: newRadius += Globals::NORMAL_EXPLOSION_RADIUS_GROWTH;
				break;

			case NUCLEAR: newRadius += Globals::NUCLEAR_EXPLOSION_RADIUS_GROWTH;
				break;

			case CLUSTER: newRadius += Globals::CLUSTER_EXPLOSION_RADIUS_GROWTH;
				break;

			case NAPALM: newRadius += Globals::NAPALM_EXPLOSION_RADIUS_GROWTH;
				break;

			case RODOFGOD: newRadius += Globals::ROD_EXPLOSION_RADIUS_GROWTH;
				break;

			default: newRadius += Globals::NORMAL_EXPLOSION_RADIUS_GROWTH;
				break;
		}

		explosion.SetRadius(newRadius);
	}

	RotateExplosion(explosion);
}

void Game::AdvanceExplosionFinal(Explosion& explosion) {

	if (explosion.GetStageTimer().GetElapsedTime() > Globals::EXPLOSION_FINAL_TIME)
		explosion.GetStage()++;

	RotateExplosion(explosion);
}

void Game::AdvanceFlash(Flash& flash) {

	if (flash.GetStageTimer().GetElapsedTime() > Globals::FLASH_STAGE_TIME) {

		flash.GetStageTimer().Restart();
		flash.GetStage()++;
		float newRadius = flash.GetRadius() + Globals::FLASH_RADIUS_GROWTH;
		flash.SetRadius(newRadius);
	}
}

void Game::RotateDestruction(Destruction& destruction) {

	float newAngleDeg = destruction.GetAngleDeg() + Generator::GetRandomUniform(0, 5.0f);

	if (newAngleDeg > 360.0f)
		newAngleDeg -= 360.0f;

	float newAngleRad = Calculator::GetRadians(newAngleDeg);
	destruction.SetAngleDeg(newAngleDeg);
	destruction.SetAngleRad(newAngleRad);
}

void Game::AdvanceDestruction(Destruction& destruction) {

	if (destruction.GetStageTimer().GetElapsedTime() > Globals::DESTRUCTION_STAGE_TIME) {

		destruction.GetStageTimer().Restart();
		destruction.GetStage()++;
		float newRadius = destruction.GetRadius() + Globals::DESTRUCTION_RADIUS_GROWTH;
		destruction.SetRadius(newRadius);
	}

	RotateDestruction(destruction);
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

				Music::PlayMissile();
				ammo--;

				if (ammo == Globals::MAX_AMMO - 1)
					ammoTimer.Restart();

				angleRad -= M_PI_2;
				ItemManager::AddMissile(Missile(missileOrigin, missileTarget, angleRad));
				ItemManager::AddFlash(Flash(missileOrigin, Globals::FLASH_INITIAL_RADIUS, angleRad));
			}
		}
}

void Game::DropBombs(Schedule& schedule) {

	DropSpecificBombs(NORMAL, schedule.GetNormalDrops());
	DropSpecificBombs(NUCLEAR, schedule.GetNuclearDrops());
	DropSpecificBombs(CLUSTER, schedule.GetClusterDrops());
	DropSpecificBombs(NAPALM, schedule.GetNapalmDrops());
	DropSpecificBombs(RODOFGOD, schedule.GetRodDrops());
}

void Game::DropSpecificBombs(Source source, std::list<float>& drops) {

	switch (source) {

		case NORMAL:
		case NUCLEAR:
		case CLUSTER:
		case NAPALM:
		case RODOFGOD: {
			std::list<float>::iterator i = drops.begin();
			while (i != drops.end()) {
				if (*i <= levelTimer.GetElapsedTime()) {
					ItemManager::AddBomb(Generator::GenerateBomb(source));
					drops.erase(i++);
				}
				else break;
			}
			break;
		}

		default:
			break;
	}
}

void Game::UpdateBombNum(Source source) {

	switch (source) {

		case NORMAL: normalNum--;
			break;

		case NUCLEAR: nuclearNum--;
			break;

		case CLUSTER: clusterNum--;
			break;

		case NAPALM: napalmNum--;
			break;

		case RODOFGOD: rodNum--;
			break;

		default:
			break;
	}
}

void Game::AwardPoints(Source source) {

	switch (source) {

		case NORMAL: score += 10;
			break;

		case NUCLEAR: score += 30;
			break;

		case CLUSTER: score += 20;
			break;

		case NAPALM: score += 40;
			break;

		case RODOFGOD: score += 80;
			break;

		default:
			break;
	}
}

void Game::CutPoints(Source source) {

	switch (source) {

		case NORMAL: score -= 30;
			break;

		case NUCLEAR: score -= 150;
			break;

		case CLUSTER: score -= 30;
			break;

		case NAPALM: score -= 200;
			break;

		case RODOFGOD: score -= 300;
			break;

		default:
			break;
	}
}
