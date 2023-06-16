#pragma once

#include <d2d1.h>
#include <string>
#include "Bitmapper.h"
#include "Generator.h"

/// <summary>description</summary>
class BitmapManager {

	static Bitmapper* bitmapper;

	static ID2D1Bitmap* menuBitmap; 
	static ID2D1Bitmap* titleBitmap;

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

	static ID2D1Bitmap* homeBitmap;
	static ID2D1Bitmap* replayBitmap;
	static ID2D1Bitmap* nextBitmap;

	static std::wstring GetRandomName(int difficulty);
	static void SetMapBitmap(int difficulty);
	static void SetBuildingBitmaps(int difficulty);

public:

	static ID2D1Bitmap* GetMenuBitmap();
	static ID2D1Bitmap* GetTitleBitmap();
	static ID2D1Bitmap* GetMapBitmap();
	static ID2D1Bitmap* GetLauncherBitmap();
	static ID2D1Bitmap* GetCannonBitmap();
	static ID2D1Bitmap* GetFlashBitmap();
	static ID2D1Bitmap* GetBuildingBitmap(int index);
	static ID2D1Bitmap* GetMissileBitmap();
	static ID2D1Bitmap* GetNormalBombBitmap();
	static ID2D1Bitmap* GetNuclearBombBitmap();
	static ID2D1Bitmap* GetClusterBombBitmap();
	static ID2D1Bitmap* GetBombletBitmap();
	static ID2D1Bitmap* GetNapalmBombBitmap();
	static ID2D1Bitmap* GetRodBombBitmap();
	static ID2D1Bitmap* GetMissileExplosionBitmap();
	static ID2D1Bitmap* GetNormalExplosionBitmap();
	static ID2D1Bitmap* GetNuclearExplosionBitmap();
	static ID2D1Bitmap* GetClusterExplosionBitmap();
	static ID2D1Bitmap* GetNapalmExplosionBitmap();
	static ID2D1Bitmap* GetRodExplosionBitmap();
	static ID2D1Bitmap* GetDestructionBitmap();
	static ID2D1Bitmap* GetAmmoBitmap();
	static ID2D1Bitmap* GetHomeBitmap();
	static ID2D1Bitmap* GetReplayBitmap();
	static ID2D1Bitmap* GetNextBitmap();

	static void Init(Bitmapper* bitmapper);
	static void InitLevel(int difficulty);
};

