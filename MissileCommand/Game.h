#pragma once

#define _USE_MATH_DEFINES

#include <Windows.h>
#include "Point.h"
#include "ItemManager.h"
#include "Timer.h"
#include "Calculator.h"
#include "Generator.h"
#include "Verifier.h"
#include "Source.h"

class Game {

public:

	static const float MAX_X;
	static const float MAX_Y;
	static const float GROUND_Y;
	static const float FRAME_TIME;
	static Timer gameTimer;

	static int ammo;
	static const int MAX_AMMO;
	static const float AMMO_LOAD_TIME;
	static Timer ammoTimer;

	static const float LAUNCHER_HALF_WIDTH;
	static const float LAUNCHER_HALF_HEIGHT;

	static const float START_BUTTON_HALF_WIDTH;
	static const float START_BUTTON_HALF_HEIGHT;
	static Point optionTarget;

	static const float BUILDING_HALF_WIDTH;
	static const float BUILDING_HALF_HEIGHT;

	static const Point missileOrigin;
	static Point missileTarget;
	static const float MISSILE_HALF_WIDTH;
	static const float MISSILE_HALF_HEIGHT;
	static const float MISSILE_SPEED;
	static const float MISSILE_LOAD_TIME;
	static Timer missileTimer;

	static const float BOMB_ORIGIN_Y;
	static const float BOMB_ORIGIN_MIN_X;
	static const float BOMB_ORIGIN_MAX_X;
	static const float BOMB_TARGET_Y;
	static const float BOMB_HALF_WIDTH;
	static const float BOMB_HALF_HEIGHT;
	static const float BOMB_SPEED;
	static const float BOMB_LOAD_TIME;
	static Timer bombTimer;

	static const float EXPLOSION_PROPAGATION_TIME;
	static const float EXPLOSION_FINAL_TIME;
	static const float EXPLOSION_INITIAL_RADIUS;
	static const float EXPLOSION_FINAL_RADIUS;
	static const int EXPLOSION_STAGES;
	static const float EXPLOSION_RADIUS_GROWTH;
	static const float EXPLOSION_STAGE_TIME;

	static bool running;

	static void Run();
	static void MenuOption();
	static void MoveMissile(Missile& missile);
	static void MoveBomb(Bomb& bomb);
	static void AdvanceExplosion(Explosion& explosion);
	static void AdvanceExplosionFinal(Explosion& explosion);
	static void ChooseTarget(HWND& hWnd);
	static bool ChooseOption(HWND& hWnd);
	static void AddAmmo();
	static void LaunchMissile();
	//static void ExplodeMissile(Missile& missile);
	static void DropBombs();
	//static void ExplodeBomb(Bomb& bomb);
	//static void DestroyBuilding(Building& building);
};

