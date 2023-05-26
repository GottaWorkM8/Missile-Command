#pragma once

#define _USE_MATH_DEFINES

#include <Windows.h>
#include "Globals.h"
#include "Verifier.h"
#include "Generator.h"
#include "ItemManager.h"
#include "Level.h"
#include "Popup.h"

class Game {

	static bool intro;
	static bool won;
	static bool finished;
	static const wchar_t* location;
	static int ammo;
	static int score;
	static int diff;
	static int normalNum;
	static int nuclearNum;
	static int clusterNum;
	static int napalmNum;
	static int rodNum;
	static Timer levelTimer;
	static Timer ammoTimer;
	static Timer missileTimer;
	static Point missileOrigin;
	static Point missileTarget;

	static void MoveMissile(Missile& missile);
	static void MoveBomb(Bomb& bomb);
	static void RotateExplosion(Explosion& explosion);
	static void AdvanceExplosion(Explosion& explosion);
	static void AdvanceExplosionFinal(Explosion& explosion);
	static void AdvanceFlash(Flash& flash);
	static void RotateDestruction(Destruction& destruction);
	static void AdvanceDestruction(Destruction& destruction);
	static void AddAmmo();
	static void LaunchMissile();
	static void DropBombs(Schedule& schedule);
	static void DropSpecificBombs(Source source, std::list<float>& drops);
	static void UpdateBombNum(Source source);
	static void AwardPoints(Source source);
	static void CutPoints(Source source);

public:

	static bool GetIntro();
	static const wchar_t* GetLocation();
	static int GetAmmo();
	static int GetScore();
	static int GetDiff();
	static int GetNormalNum();
	static int GetNuclearNum();
	static int GetClusterNum();
	static int GetNapalmNum();
	static int GetRodNum();

	static void Run(int difficulty);
	static void UpdateTarget(HWND& hWnd);
	static void UpdateLauncherCannon(HWND& hWnd);
};
