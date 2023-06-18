#include "Game.h"
#include <iostream>

bool Game::pausable = false;
bool Game::paused = false;
bool Game::ready = false;
bool Game::introTime = true;
bool Game::popupUp = false;
bool Game::won = false;
bool Game::playing = false;
bool Game::finished = false;
const wchar_t* Game::location = L"";
int Game::ammo = Globals::MAX_AMMO;
int Game::score = 0;
int Game::maxScore = 0;
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
Intro* Game::intro = nullptr;
Summary* Game::summary = nullptr;

bool Game::IsPausable() {
	return pausable;
}

bool Game::IsPaused() {
	return paused;
}

void Game::SetPaused(bool pause) {
	paused = pause;
}

bool Game::IsReady() {
	return ready;
}

bool Game::IsIntroTime() {
	return introTime;
}

bool Game::IsPopupUp() {
	return popupUp;
}

bool Game::IsWon() {
	return won;
}

bool Game::IsPlaying() {
	return playing;
}

bool Game::IsFinished() {
	return finished;
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

int Game::GetMaxScore() {
	return maxScore;
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

Intro*& Game::GetIntro() {
	return intro;
}

Summary*& Game::GetSummary() {
	return summary;
}

void Game::Run(int difficulty) {

	ready = false;

	// Setting the level
	Level level = Level(difficulty);
	location = level.GetLocation();
	score = 0;
	maxScore = level.GetMaxScore();
	diff = level.GetDifficulty();
	normalNum = level.GetNormalNum();
	nuclearNum = level.GetNuclearNum();
	clusterNum = level.GetClusterNum();
	napalmNum = level.GetNapalmNum();
	rodNum = level.GetRodNum();
	ItemManager::Reset();

	// Performing level introduction
	intro = new Intro();
	introTime = true;
	Sleep(Globals::INTRO_TIME * 1000);
	introTime = false;
	delete intro;
	intro = nullptr;

	playing = true;
	pausable = true;

	// Reseting both timers
	float levelTime = 0;
	float ammoTime = 0;
	levelTimer.Restart();
	ammoTimer.Restart();
	levelTimer.GetDeltaTime();
	ammoTimer.GetDeltaTime();

	while (true) {

		// Pausing and unpausing the game (popup) 
		if (paused) {

			playing = false;
			summary = new Summary(won, score, maxScore);
			popupUp = true;

			while (paused && !summary->IsFinished())
				Sleep(10);

			if (!paused) {

				popupUp = false;
				delete summary;
				summary = nullptr;
				playing = true;
				levelTimer.GetDeltaTime();
				ammoTimer.GetDeltaTime();
			}

			else finished = true;

			paused = false;
		}

		// Creating multiple threads handling game objects
		std::thread missilesThread(HandleMissiles);
		std::thread explosionsThread(HandleExplosions);
		std::thread bombsThread(HandleBombs);
		std::thread flashesThread(HandleFlashes);
		std::thread destructionsThread(HandleDestructions);

		// Joining created threads
		missilesThread.join();
		explosionsThread.join();
		bombsThread.join();
		flashesThread.join();
		destructionsThread.join();

		// Handling ammo restoration
		ammoTime += ammoTimer.GetDeltaTime();

		if (ammoTime > Globals::AMMO_LOAD_TIME) {

			AddAmmo();
			ammoTime = 0;
		}

		// Handling bomb drops
		levelTime += levelTimer.GetDeltaTime();

		if (levelTime <= Globals::GAME_TIME)
			DropBombs(level.GetSchedule(), levelTime);

		// Handling checks for game loss and game win
		Launcher& launcher = ItemManager::GetLauncher();
		std::list<Building>& buildings = ItemManager::GetBuildings();

		if (!finished && Verifier::GameLost(launcher, buildings)) {

			pausable = false;
			GameSave::Update(difficulty, score, won);
			playing = false;
			summary = new Summary(won, score, maxScore);
			popupUp = true;
			finished = true;
		}

		std::list<Bomb>& bombs = ItemManager::GetBombs();

		levelTime += levelTimer.GetDeltaTime();

		if (!finished && Verifier::GameWon(bombs, levelTime)) {

			pausable = false;

			if (score <= 0)
				won = false;

			else won = true;
			
			GameSave::Update(difficulty, score, won);
			playing = false;
			summary = new Summary(won, score, maxScore);
			popupUp = true;
			finished = true;
		}

		// Handling summary popup at the end of the game
		if (summary != nullptr)
			if (summary->IsFinished()) {
			
				// Reseting all values for the next future game
				pausable = false;
				paused = false;
				won = false;
				playing = false;
				finished = false;
				location = L"";
				ammo = Globals::MAX_AMMO;
				score = 0;
				maxScore = 0;
				diff = 0;
				normalNum = 0;
				nuclearNum = 0;
				clusterNum = 0;
				napalmNum = 0;
				rodNum = 0;
				ItemManager::Reset();
				levelTimer = Timer();
				ammoTimer = Timer();
				missileTimer = Timer();
				popupUp = false;
				delete summary;
				summary = nullptr;

				ready = true;

				return;
			}

		// Maintaining stable framerate (120 fps)
		float deltaTime = levelTimer.GetDeltaTime();
		levelTime += deltaTime;

		if (deltaTime < Globals::FRAME_TIME)
			Sleep(Globals::FRAME_TIME - deltaTime);
	}
}

void Game::HandleMissiles() {

	std::list<Missile>& missiles = ItemManager::GetMissiles();

	ResourceManager::GetMissilesMutex().lock();

	std::list<Missile>::iterator i = missiles.begin();

	while (i != missiles.end()) {

		if (i->GetCenter().y <= i->GetTarget().y) {

			Music::PlayExplosion();
			ItemManager::AddExplosion(Explosion(i->GetCenter(),
				Globals::EXPLOSION_INITIAL_RADIUS, MISSILE));
			i = missiles.erase(i);
		}

		else {

			MoveMissile(*i);
			i++;
		}
	}

	ResourceManager::GetMissilesMutex().unlock();
}

void Game::HandleExplosions() {

	Launcher& launcher = ItemManager::GetLauncher();
	std::list<Bomb>& bombs = ItemManager::GetBombs();
	std::list<Building>& buildings = ItemManager::GetBuildings();
	std::list<Explosion>& explosions = ItemManager::GetExplosions();

	ResourceManager::GetExplosionsMutex().lock();

	std::list<Explosion>::iterator j = explosions.begin();

	while (j != explosions.end()) {

		ResourceManager::GetBombsMutex().lock();

		std::list<Bomb>::iterator k = bombs.begin();

		while (k != bombs.end()) {

			if (Verifier::BombInRange(*k, *j)) {

				if (Verifier::BombOnTheList(*k, j->GetBombsHit()))
					k++;

				else {

					k->ReceiveDamage(j->GetDamage());
					j->AddBombHit(*k);

					if (k->GetHP() <= 0) {

						Music::PlayExplosion();
						ItemManager::AddExplosion(Explosion(k->GetCenter(),
							Globals::EXPLOSION_INITIAL_RADIUS, k->GetSource()));
						UpdateBombNum(k->GetSource());
						AwardPoints(k->GetSource());

						if (k->GetSource() == CLUSTER)
							SpawnBomblets(*j, explosions.back());

						k = bombs.erase(k);
					}

					else k++;
				}
			}

			else k++;
		}

		ResourceManager::GetBombsMutex().unlock();

		ResourceManager::GetBuildingsMutex().lock();

		std::list<Building>::iterator l = buildings.begin();

		while (l != buildings.end()) {

			if (Verifier::BuildingInRange(*l, *j)) {

				if (Verifier::BuildingOnTheList(*l, j->GetBuildingsHit()))
					l++;

				else {

					l->ReceiveDamage(j->GetDamage());
					j->AddBuildingHit(*l);

					if (l->GetHP() <= 0) {

						Music::PlayExplosion();
						ItemManager::AddDestruction(Destruction(l->GetCenter(),
							Globals::DESTRUCTION_INITIAL_RADIUS));
						PenalizeDestruction(false);
						l = buildings.erase(l);
					}

					else l++;
				}
			}

			else l++;
		}

		ResourceManager::GetBuildingsMutex().unlock();

		ResourceManager::GetLauncherMutex().lock();

		if (Verifier::LauncherInRange(launcher, *j)) {

			if (!j->IsLauncherHit()) {

				launcher.ReceiveDamage(j->GetDamage());
				j->SetLauncherHit(true);

				if (launcher.GetHP() <= 0 && !launcher.IsDestroyed()) {

					Music::PlayExplosion();
					ItemManager::AddDestruction(Destruction(launcher.GetCenter(),
						Globals::DESTRUCTION_INITIAL_RADIUS));
					PenalizeDestruction(true);
					launcher.SetDestroyed(true);
				}
			}
		}

		ResourceManager::GetLauncherMutex().unlock();

		if (j->GetStage() == Globals::EXPLOSION_STAGES)
			j = explosions.erase(j);

		else if (j->GetStage() == Globals::EXPLOSION_STAGES - 1) {

			AdvanceExplosionFinal(*j);
			j++;
		}
    
		else {

			AdvanceExplosion(*j);
			j++;
		}
	}

	ResourceManager::GetExplosionsMutex().unlock();
}

void Game::HandleBombs() {

	std::list<Bomb>& bombs = ItemManager::GetBombs();

	ResourceManager::GetBombsMutex().lock();

	std::list<Bomb>::iterator k = bombs.begin();

	while (k != bombs.end()) {

		if (k->GetCenter().y >= Globals::BOMB_TARGET_Y) {

			Music::PlayExplosion();
			ItemManager::AddExplosion(Explosion(k->GetCenter(),
				Globals::EXPLOSION_INITIAL_RADIUS, k->GetSource()));
			UpdateBombNum(k->GetSource());
			CutPoints(k->GetSource());
			k = bombs.erase(k);
		}

		else {

			MoveBomb(*k);
			k++;
		}
	}

	ResourceManager::GetBombsMutex().unlock();
}

void Game::HandleFlashes() {

	std::list<Flash>& flashes = ItemManager::GetFlashes();

	ResourceManager::GetFlashesMutex().lock();

	std::list<Flash>::iterator m = flashes.begin();

	while (m != flashes.end()) {

		if (m->GetStage() == Globals::FLASH_STAGES)
			m = flashes.erase(m);

		else {

			AdvanceFlash(*m);
			m++;
		}
	}

	ResourceManager::GetFlashesMutex().unlock();
}

void Game::HandleDestructions() {

	std::list<Destruction>& destructions = ItemManager::GetDestructions();

	ResourceManager::GetDestructionsMutex().lock();

	std::list<Destruction>::iterator n = destructions.begin();

	while (n != destructions.end()) {

		if (n->GetStage() == Globals::DESTRUCTION_STAGES)
			n = destructions.erase(n);

		else {

			AdvanceDestruction(*n);
			n++;
		}
	}

	ResourceManager::GetDestructionsMutex().unlock();
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

		case BOMBLET: speed = Globals::BOMBLET_SPEED;
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

	float newAngleDeg = explosion.GetAngleDeg() + Generator::GetRandomUniform(0.0f, 180.0f);

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

			case BOMBLET: newRadius += Globals::BOMBLET_EXPLOSION_RADIUS_GROWTH;
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

	float newAngleDeg = destruction.GetAngleDeg() + Generator::GetRandomUniform(0.0f, 5.0f);

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

	if (ammo < Globals::MAX_AMMO)
		ammo++;
}

void Game::LaunchMissile() {

	if (playing)
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

void Game::SpawnBomblets(Explosion& catalystExplosion, Explosion& clusterExplosion) {

	for (int i = 0; i < Globals::BOMBLETS_SPAWNED; i++)
		ItemManager::AddBomb(Generator::GenerateBomblet(clusterExplosion));
	
	std::list<Bomb>& bombs = ItemManager::GetBombs();
	std::list<Bomb>::iterator b = bombs.end();
	std::advance(b, -Globals::BOMBLETS_SPAWNED);

	while (b != bombs.end()) {

		catalystExplosion.AddBombHit(*b);
		clusterExplosion.AddBombHit(*b);
		b++;
	}
}

void Game::DropBombs(Schedule& schedule, float& time) {

	DropSpecificBombs(NORMAL, schedule.GetNormalDrops(), time);
	DropSpecificBombs(NUCLEAR, schedule.GetNuclearDrops(), time);
	DropSpecificBombs(CLUSTER, schedule.GetClusterDrops(), time);
	DropSpecificBombs(NAPALM, schedule.GetNapalmDrops(), time);
	DropSpecificBombs(RODOFGOD, schedule.GetRodDrops(), time);
}

void Game::DropSpecificBombs(Source source, std::list<float>& drops, float& time) {

	switch (source) {

		case NORMAL:
		case NUCLEAR:
		case CLUSTER:
		case NAPALM:
		case RODOFGOD: {
			std::list<float>::iterator i = drops.begin();
			while (i != drops.end()) {
				if (*i <= time) {
					ItemManager::AddBomb(Generator::GenerateBomb(source));
					i = drops.erase(i);
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

	if (!finished) {

		switch (source) {

			case NORMAL: score += Globals::NORMAL_BOMB_POINTS;
				break;

			case NUCLEAR: score += Globals::NUCLEAR_BOMB_POINTS;
				break;

			case CLUSTER: score += Globals::CLUSTER_BOMB_POINTS;
				break;

			case NAPALM: score += Globals::NAPALM_BOMB_POINTS;
				break;

			case RODOFGOD: score += Globals::ROD_BOMB_POINTS;
				break;

			default:
				break;
		}
	}
}

void Game::CutPoints(Source source) {

	if (!finished) {

		switch (source) {

			case NORMAL: score -= Globals::NORMAL_BOMB_POINTS;
				break;

			case NUCLEAR: score -= Globals::NUCLEAR_BOMB_POINTS;
				break;

			case CLUSTER: score -= Globals::CLUSTER_BOMB_POINTS;
				break;

			case BOMBLET: score -= Globals::BOMBLET_POINTS;
				break;

			case NAPALM: score -= Globals::NAPALM_BOMB_POINTS;
				break;

			case RODOFGOD: score -= Globals::ROD_BOMB_POINTS;
				break;

			default:
				break;
		}
	}
}

void Game::PenalizeDestruction(bool launcher) {

	if (launcher)
		score -= maxScore * Globals::LAUNCHER_PENALTY;

	else score -= maxScore * Globals::BUILDING_PENALTY;
}