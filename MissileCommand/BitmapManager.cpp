#include "BitmapManager.h"

Bitmapper* BitmapManager::bitmapper = nullptr;

ID2D1Bitmap* BitmapManager::menuBitmap = nullptr;
ID2D1Bitmap* BitmapManager::titleBitmap = nullptr;

ID2D1Bitmap* BitmapManager::mapBitmap = nullptr;
ID2D1Bitmap* BitmapManager::launcherBitmap = nullptr;
ID2D1Bitmap* BitmapManager::cannonBitmap = nullptr;
ID2D1Bitmap* BitmapManager::flashBitmap = nullptr;
ID2D1Bitmap* BitmapManager::buildingBitmaps[8] = {};
ID2D1Bitmap* BitmapManager::missileBitmap = nullptr;
ID2D1Bitmap* BitmapManager::normalBombBitmap = nullptr;
ID2D1Bitmap* BitmapManager::nuclearBombBitmap = nullptr;
ID2D1Bitmap* BitmapManager::clusterBombBitmap = nullptr;
ID2D1Bitmap* BitmapManager::napalmBombBitmap = nullptr;
ID2D1Bitmap* BitmapManager::rodBombBitmap = nullptr;
ID2D1Bitmap* BitmapManager::missileExplosionBitmap = nullptr;
ID2D1Bitmap* BitmapManager::normalExplosionBitmap = nullptr;
ID2D1Bitmap* BitmapManager::nuclearExplosionBitmap = nullptr;
ID2D1Bitmap* BitmapManager::clusterExplosionBitmap = nullptr;
ID2D1Bitmap* BitmapManager::napalmExplosionBitmap = nullptr;
ID2D1Bitmap* BitmapManager::rodExplosionBitmap = nullptr;
ID2D1Bitmap* BitmapManager::destructionBitmap = nullptr;
ID2D1Bitmap* BitmapManager::ammoBitmap = nullptr;

ID2D1Bitmap* BitmapManager::homeBitmap = nullptr;
ID2D1Bitmap* BitmapManager::replayBitmap = nullptr;
ID2D1Bitmap* BitmapManager::nextBitmap = nullptr;

std::wstring BitmapManager::GetRandomName(int difficulty) {

	std::wstring prefix;
	std::wstring suffix;

	switch (difficulty) {

		case 1:
			prefix = L"building-asian";
			suffix = std::to_wstring(Generator::GetRandomUniform(1, 7));
			break;

		case 2:
			prefix = L"building-ice";
			suffix = std::to_wstring(Generator::GetRandomUniform(1, 5));
			break;

		case 3:
			prefix = L"building-modern";
			suffix = std::to_wstring(Generator::GetRandomUniform(1, 7));
			break;

		case 4:
			prefix = L"building-desert";
			suffix = std::to_wstring(Generator::GetRandomUniform(1, 8));
			break;

		case 5:
			prefix = L"building-alien";
			suffix = std::to_wstring(Generator::GetRandomUniform(1, 8));
			break;

		default:
			prefix = L"building-asian";
			suffix = std::to_wstring(Generator::GetRandomUniform(1, 7));
			break;
	}

	return prefix + suffix + L".png";
}

void BitmapManager::SetMapBitmap(int difficulty) {

	switch (difficulty) {

		case 1:
			mapBitmap = bitmapper->GetBitmap(L"map-grass.jpg");
			break;

		case 2:
			mapBitmap = bitmapper->GetBitmap(L"map-ice.jpg");
			break;

		case 3:
			mapBitmap = bitmapper->GetBitmap(L"map-river.jpg");
			break;

		case 4:
			mapBitmap = bitmapper->GetBitmap(L"map-rocks.jpg");
			break;

		case 5:
			mapBitmap = bitmapper->GetBitmap(L"map-planets.jpg");
			break;

		default:
			mapBitmap = bitmapper->GetBitmap(L"map-grass.jpg");
			break;
	}
}

void BitmapManager::SetBuildingBitmaps(int difficulty) {

	for (int i = 0; i < 8; i++)
		buildingBitmaps[i] = bitmapper->GetBitmap(GetRandomName(difficulty).c_str());
}

ID2D1Bitmap* BitmapManager::GetMenuBitmap() {
	return menuBitmap;
}

ID2D1Bitmap* BitmapManager::GetTitleBitmap() {
	return titleBitmap;
}

ID2D1Bitmap* BitmapManager::GetMapBitmap() {
	return mapBitmap;
}

ID2D1Bitmap* BitmapManager::GetLauncherBitmap() {
	return launcherBitmap;
}

ID2D1Bitmap* BitmapManager::GetCannonBitmap() {
	return cannonBitmap;
}

ID2D1Bitmap* BitmapManager::GetFlashBitmap() {
	return flashBitmap;
}

ID2D1Bitmap* BitmapManager::GetBuildingBitmap(int index) {
	return buildingBitmaps[index];
}

ID2D1Bitmap* BitmapManager::GetMissileBitmap() {
	return missileBitmap;
}

ID2D1Bitmap* BitmapManager::GetNormalBombBitmap() {
	return normalBombBitmap;
}

ID2D1Bitmap* BitmapManager::GetNuclearBombBitmap() {
	return nuclearBombBitmap;
}

ID2D1Bitmap* BitmapManager::GetClusterBombBitmap() {
	return clusterBombBitmap;
}

ID2D1Bitmap* BitmapManager::GetNapalmBombBitmap() {
	return napalmBombBitmap;
}

ID2D1Bitmap* BitmapManager::GetRodBombBitmap() {
	return rodBombBitmap;
}

ID2D1Bitmap* BitmapManager::GetMissileExplosionBitmap() {
	return missileExplosionBitmap;
}

ID2D1Bitmap* BitmapManager::GetNormalExplosionBitmap() {
	return normalExplosionBitmap;
}

ID2D1Bitmap* BitmapManager::GetNuclearExplosionBitmap() {
	return nuclearExplosionBitmap;
}

ID2D1Bitmap* BitmapManager::GetClusterExplosionBitmap() {
	return clusterExplosionBitmap;
}

ID2D1Bitmap* BitmapManager::GetNapalmExplosionBitmap() {
	return napalmExplosionBitmap;
}

ID2D1Bitmap* BitmapManager::GetRodExplosionBitmap() {
	return rodExplosionBitmap;
}

ID2D1Bitmap* BitmapManager::GetDestructionBitmap() {
	return destructionBitmap;
}

ID2D1Bitmap* BitmapManager::GetAmmoBitmap() {
	return ammoBitmap;
}

ID2D1Bitmap* BitmapManager::GetHomeBitmap() {
	return homeBitmap;
}

ID2D1Bitmap* BitmapManager::GetReplayBitmap() {
	return replayBitmap;
}

ID2D1Bitmap* BitmapManager::GetNextBitmap() {
	return nextBitmap;
}

void BitmapManager::Init(Bitmapper* btmpr) {

	bitmapper = btmpr;
	menuBitmap = bitmapper->GetBitmap(L"menu-background.jpg");
	titleBitmap = bitmapper->GetBitmap(L"menu-title.png");
	mapBitmap = bitmapper->GetBitmap(L"map-grass.jpg");
	launcherBitmap = bitmapper->GetBitmap(L"launcher.png");
	cannonBitmap = bitmapper->GetBitmap(L"launcher-cannon.png");
	flashBitmap = bitmapper->GetBitmap(L"launcher-flash.png");
	buildingBitmaps[0] = bitmapper->GetBitmap(L"building-modern1.png");
	buildingBitmaps[1] = bitmapper->GetBitmap(L"building-modern1.png");
	buildingBitmaps[2] = bitmapper->GetBitmap(L"building-modern1.png");
	buildingBitmaps[3] = bitmapper->GetBitmap(L"building-modern1.png");
	buildingBitmaps[4] = bitmapper->GetBitmap(L"building-modern1.png");
	buildingBitmaps[5] = bitmapper->GetBitmap(L"building-modern1.png");
	buildingBitmaps[6] = bitmapper->GetBitmap(L"building-modern1.png");
	buildingBitmaps[7] = bitmapper->GetBitmap(L"building-modern1.png");
	missileBitmap = bitmapper->GetBitmap(L"missile.png");
	normalBombBitmap = bitmapper->GetBitmap(L"bomb-normal.png");
	nuclearBombBitmap = bitmapper->GetBitmap(L"bomb-nuclear.png");
	clusterBombBitmap = bitmapper->GetBitmap(L"bomb-cluster.png");
	napalmBombBitmap = bitmapper->GetBitmap(L"bomb-napalm.png");
	rodBombBitmap = bitmapper->GetBitmap(L"bomb-rod.png");
	missileExplosionBitmap = bitmapper->GetBitmap(L"explosion-blue.png");
	normalExplosionBitmap = bitmapper->GetBitmap(L"explosion-red.png");
	nuclearExplosionBitmap = bitmapper->GetBitmap(L"explosion-yellow.png");
	clusterExplosionBitmap = bitmapper->GetBitmap(L"explosion-purple.png");
	napalmExplosionBitmap = bitmapper->GetBitmap(L"explosion-yellow.png");
	rodExplosionBitmap = bitmapper->GetBitmap(L"explosion-cyan.png");
	destructionBitmap = bitmapper->GetBitmap(L"destruction.png");
	ammoBitmap = bitmapper->GetBitmap(L"ammo.png");
	homeBitmap = bitmapper->GetBitmap(L"home.png");
	replayBitmap = bitmapper->GetBitmap(L"replay.png");
	nextBitmap = bitmapper->GetBitmap(L"next.png");
}

void BitmapManager::InitLevel(int difficulty) {

	SetMapBitmap(difficulty);
	SetBuildingBitmaps(difficulty);
}
