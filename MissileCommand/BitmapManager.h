#pragma once

#include <d2d1.h>
#include <string>
#include "Bitmapper.h"
#include "Generator.h"

/// <summary>
/// Class responsible for managing bitmaps created by Bitmapper instance (member)
/// </summary>
class BitmapManager {

	static Bitmapper* bitmapper;

	static ID2D1Bitmap* menuBitmap; 
	static ID2D1Bitmap* titleBitmap;
	static ID2D1Bitmap* helpBitmap;

	static ID2D1Bitmap* mapBitmap;
	static ID2D1Bitmap* launcherBitmap;
	static ID2D1Bitmap* cannonBitmap;
	static ID2D1Bitmap* flashBitmap;
	static ID2D1Bitmap* buildingBitmaps[8];
	static ID2D1Bitmap* missileBitmap;
	static ID2D1Bitmap* normalBombBitmap;
	static ID2D1Bitmap* nuclearBombBitmap;
	static ID2D1Bitmap* clusterBombBitmap;
	static ID2D1Bitmap* bombletBitmap;
	static ID2D1Bitmap* napalmBombBitmap;
	static ID2D1Bitmap* rodBombBitmap;
	static ID2D1Bitmap* missileExplosionBitmap;
	static ID2D1Bitmap* normalExplosionBitmap;
	static ID2D1Bitmap* nuclearExplosionBitmap;
	static ID2D1Bitmap* clusterExplosionBitmap;
	static ID2D1Bitmap* napalmExplosionBitmap;
	static ID2D1Bitmap* rodExplosionBitmap;
	static ID2D1Bitmap* destructionBitmap;
	static ID2D1Bitmap* ammoBitmap;

	static ID2D1Bitmap* hollowStarBitmap;
	static ID2D1Bitmap* goldStarBitmap;
	static ID2D1Bitmap* shinyStarBitmap;
	static ID2D1Bitmap* homeBitmap;
	static ID2D1Bitmap* replayBitmap;
	static ID2D1Bitmap* nextBitmap;

	// Returns string containing the name of a random building for the provided as an argument level
	static std::wstring GetRandomName(int difficulty);
	// Sets bitmaps for certain objects in the game to the ones appropriate for the provided as an argument level
	static void SetMapBitmap(int difficulty);
	// Randomly assings bitmaps for each building present in the provided as an argument level
	static void SetBuildingBitmaps(int difficulty);

public:

	// Returns menu background bitmap
	static ID2D1Bitmap* GetMenuBitmap();
	// Returns menu title bitmap
	static ID2D1Bitmap* GetTitleBitmap();
	// Returns menu help bitmap
	static ID2D1Bitmap* GetHelpBitmap();
	// Returns map bitmap for the specific level
	static ID2D1Bitmap* GetMapBitmap();
	// Returns missile launcher bitmap
	static ID2D1Bitmap* GetLauncherBitmap();
	// Returns missile launcher cannon bitmap
	static ID2D1Bitmap* GetCannonBitmap();
	// Returns missile shot flash bitmap
	static ID2D1Bitmap* GetFlashBitmap();
	// Returns building bitmap for the specific building, for the specific level
	static ID2D1Bitmap* GetBuildingBitmap(int index);
	// Returns missile bitmap
	static ID2D1Bitmap* GetMissileBitmap();
	// Returns normal bomb bitmap
	static ID2D1Bitmap* GetNormalBombBitmap();
	// Returns nuclear bomb bitmap
	static ID2D1Bitmap* GetNuclearBombBitmap();
	// Returns cluster bomb bitmap
	static ID2D1Bitmap* GetClusterBombBitmap();
	// Returns bomblet bitmap
	static ID2D1Bitmap* GetBombletBitmap();
	// Returns napalm bitmap
	static ID2D1Bitmap* GetNapalmBombBitmap();
	// Returns rod of god bitmap
	static ID2D1Bitmap* GetRodBombBitmap();
	// Returns missile explosion bitmap
	static ID2D1Bitmap* GetMissileExplosionBitmap();
	// Returns normal bomb explosion bitmap
	static ID2D1Bitmap* GetNormalExplosionBitmap();
	// Returns nuclear bomb explosion bitmap
	static ID2D1Bitmap* GetNuclearExplosionBitmap();
	// Returns cluster bomb explosion bitmap
	static ID2D1Bitmap* GetClusterExplosionBitmap();
	// Returns napalm explosion bitmap
	static ID2D1Bitmap* GetNapalmExplosionBitmap();
	// Returns rod of god explosion bitmap
	static ID2D1Bitmap* GetRodExplosionBitmap();
	// Returns launcher/building destruction bitmap
	static ID2D1Bitmap* GetDestructionBitmap();
	// Returns ammunition bitmap
	static ID2D1Bitmap* GetAmmoBitmap();
	// Returns hollow star bitmap
	static ID2D1Bitmap* GetHollowStarBitmap();
	// Returns gold star bitmap
	static ID2D1Bitmap* GetGoldStarBitmap();
	// Returns shiny diamond star bitmap
	static ID2D1Bitmap* GetShinyStarBitmap();
	// Returns home button bitmap
	static ID2D1Bitmap* GetHomeBitmap();
	// Returns replay button bitmap
	static ID2D1Bitmap* GetReplayBitmap();
	// Returns next button bitmap
	static ID2D1Bitmap* GetNextBitmap();

	// Sets bitmaps for most objects present in the application, using bitmapper given as an argument
	static void Init(Bitmapper* bitmapper);
	// Sets bitmaps for objects that are appropriate for the given as an argument level
	static void InitLevel(int difficulty);
};

