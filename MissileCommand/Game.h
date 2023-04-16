#pragma once

#define _USE_MATH_DEFINES

#include <Windows.h>
#include "Point.h"
#include "ItemManager.h"
#include "Timer.h"
#include "Calculator.h"
#include "Generator.h"

class Game {

public:

	static const float maxX;
	static const float maxY;
	static const float groundY;
	static const float gameFrameTime;
	static Timer gameTimer;

	static int ammo;
	static const int maxAmmo;
	static const float ammoLoadTime;
	static Timer ammoTimer;

	static const float launcherHalfWidth;
	static const float launcherHalfHeight;

	static const float buildingHalfWidth;
	static const float buildingHalfHeight;

	static const Point missileOrigin;
	static Point missileTarget;
	static const float missileHalfWidth;
	static const float missileHalfHeight;
	static const float missileSpeed;
	static const float missileLoadTime;
	static Timer missileTimer;

	static const float bombOriginY;
	static const float bombOriginMinX;
	static const float bombOriginMaxX;
	static const float bombTargetY;
	static const float bombHalfWidth;
	static const float bombHalfHeight;
	static const float bombSpeed;
	static const float bombLoadTime;
	static Timer bombTimer;

	static const float explosionTime;
	static const float explosionFinalTime;
	static const float explosionInitialRadius;
	static const float explosionFinalRadius;
	static const int explosionStages;
	static const float explosionRadiusGrowth;
	static const float explosionStageTime;

	static void Run();
	static void MoveMissile(Missile& missile);
	static void MoveBomb(Bomb& bomb);
	static void AdvanceExplosion(Explosion& explosion);
	static void ChooseTarget(HWND& hWnd);
	static void AddAmmo();
	static void LaunchMissile();
	//static void ExplodeMissile(Missile& missile);
	static void DropBombs();
	//static void ExplodeBomb(Bomb& bomb);
	//static void DestroyBuilding(Building& building);
};

