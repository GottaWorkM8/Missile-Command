#pragma once

#define _USE_MATH_DEFINES

#include <Windows.h>
#include "Globals.h"
#include "Verifier.h"
#include "Source.h"
#include "Music.h"
#include "Generator.h"
#include "ItemManager.h"
#include "ResourceManager.h"
#include "Level.h"
#include "Intro.h"
#include "Summary.h"
#include "GameSave.h"

/// <summary>
/// Class responsible for managing every aspect of the game (interactions between objects, winning/losing, introduction and summary, 
/// keeping track of score and remaining bombs, as well as time to provide stable framerate)
/// </summary>
class Game {

	static bool pausable;
	static bool paused;
	static bool ready;
	static bool introTime;
	static bool popupUp;
	static bool won;
	static bool playing;
	static bool finished;
	static const wchar_t* location;
	static int ammo;
	static int score;
	static int maxScore;
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
	static Intro* intro;
	static Summary* summary;

	// Handles all missiles (missile movement, explosion after reaching the target)
	static void HandleMissiles();
	// Handles all explosions (radius expansion, interactions with other objects, spawning bomblets)
	static void HandleExplosions();
	// Handles all bombs (bomb movement, explosion after reaching the maximum y coordinate)
	static void HandleBombs();
	// Handles all flashes (size expansion)
	static void HandleFlashes();
	// Handles all destructions (size expansion)
	static void HandleDestructions();
	// Assings new position to the given missile based on its speed and angle
	static void MoveMissile(Missile& missile);
	// Assings new position to the given bomb based on its speed and angle
	static void MoveBomb(Bomb& bomb);
	// Assigns new random rotation angle to the given explosion (makes explosions look decent)
	static void RotateExplosion(Explosion& explosion);
	// Handles stage advancement of the given explosion (when it grows in radius)
	static void AdvanceExplosion(Explosion& explosion);
	// Handles the last stage of the given explosion (when it already has maximum radius)
	static void AdvanceExplosionFinal(Explosion& explosion);
	// Handles stage advancement of the given flash (when it grows in size)
	static void AdvanceFlash(Flash& flash);
	// Assigns new random rotation angle (small change) to the given explosion (makes destructions look decent)
	static void RotateDestruction(Destruction& destruction);
	// Handles stage advancement of the given destruction (when it grows in size)
	static void AdvanceDestruction(Destruction& destruction);
	// Increments the number of available missiles (if it isn't already at the maximum)
	static void AddAmmo();
	// Launches a missile at the position specified by the user's input
	static void LaunchMissile();
	// Spawns bomblets (cluster bomb spawn) at the position of the given cluster explosion, 
	// that are immune to the two given explosions and travel to the randomely chosen location
	static void SpawnBomblets(Explosion& catalystExplosion, Explosion& clusterExplosion);
	// Handles bomb drops according to the provided bomb drop schedule, that is intrinsic to every level
	static void DropBombs(Schedule& schedule, float& time);
	// Handles drops of bombs of the given type, in accordance to the given list of potential bomb drops (also specific type) 
	static void DropSpecificBombs(Source source, std::list<float>& drops, float& time);
	// Updates numbers of remaining bombs (on the right side of the game bar on the bottom of the screen), 
	// by decrementing the number matching the given bomb type
	static void UpdateBombNum(Source source);
	// Increases the current number of points by the amount matching the given bomb type (award for destroying the bomb in the air)
	static void AwardPoints(Source source);
	// Decreases the current number of points by the amount matching the given bomb type (penalty for letting the bomb drop to the ground)
	static void CutPoints(Source source);
	// Decreases the current number of points by the amount matching the given structure type (true - launcher, false - building)
	static void PenalizeDestruction(bool launcher);

public:

	// Returns the boolean telling if the game can be paused at the time (after introduction, before end of the game)
	static bool IsPausable();
	// Returns the boolean telling if the game is paused
	static bool IsPaused();
	// Sets the boolean telling if the game is paused
	static void SetPaused(bool pause);
	// Returns the boolean telling if the game is ready to be started again (second and following games)
	static bool IsReady();
	// Returns the boolean telling if the introduction is progressing
	static bool IsIntroTime();
	// Returns the boolean telling if the popup is displayed (pause or end of the game summary)
	static bool IsPopupUp();
	// Returns the boolean telling if the game has been won
	static bool IsWon();
	// Returns the boolean telling if the game is currently played (not paused)
	static bool IsPlaying();
	// Returns the boolean telling if the game is finished and summary is to be displayed
	static bool IsFinished();
	// Returns string containing the name of the location of the current level
	static const wchar_t* GetLocation();
	// Returns the integer value representing the number of available missiles
	static int GetAmmo();
	// Returns the integer value representing the current number of points 
	static int GetScore();
	// Returns the integer value representing the maximum possible number of points for the level
	static int GetMaxScore();
	// Returns the integer value representing the current level
	static int GetDiff();
	// Returns the integer value representing the number of remaining normal bombs
	static int GetNormalNum();
	// Returns the integer value representing the number of remaining nuclear bombs
	static int GetNuclearNum();
	// Returns the integer value representing the number of remaining cluster bombs
	static int GetClusterNum();
	// Returns the integer value representing the number of remaining napalm bombs
	static int GetNapalmNum();
	// Returns the integer value representing the number of remaining rod of god bombs
	static int GetRodNum();
	// Returns the pointer to the Intro instance
	static Intro*& GetIntro();
	// Returns the pointer to the Summary instance
	static Summary*& GetSummary();

	// Handles everything concerning the game
	static void Run(int difficulty);
	// Updates the target position based on the user input (mouse press) and initiates missile launch
	static void UpdateTarget(HWND& hWnd);
	// Updates the tilt of the launcher cannon and spawn point of missiles based on the user input (mouse movement)
	static void UpdateLauncherCannon(HWND& hWnd);
};
