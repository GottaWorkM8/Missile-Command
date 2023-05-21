#pragma once

#define _USE_MATH_DEFINES

#include <Windows.h>
#include "Globals.h"
#include "Verifier.h"
#include "Generator.h"
#include "ItemManager.h"

class Game {

	static bool won;
	static bool finished;
	static int ammo;
	static Timer levelTimer;
	static Timer ammoTimer;
	static Timer missileTimer;
	static Timer bombTimer;
	static Point missileOrigin;
	static Point missileTarget;

	static void MoveMissile(Missile& missile);
	static void MoveBomb(Bomb& bomb);
	static void AdvanceExplosion(Explosion& explosion);
	static void AdvanceExplosionFinal(Explosion& explosion);
	static void AdvanceFlash(Flash& flash);
	static void AddAmmo();
	static void LaunchMissile();
	static void DropBombs();

public:

	static void Run(int difficulty);
	static void UpdateTarget(HWND& hWnd);
	static void UpdateLauncherCannon(HWND& hWnd);
};
