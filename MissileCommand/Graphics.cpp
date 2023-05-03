#include "Graphics.h"

Graphics::Graphics() {
	
	hWnd = NULL;
	factory = NULL;
	renderTarget = NULL;
	launcherBitmap = NULL;
	buildingBitmap = NULL;
	missileBitmap = NULL;
	bombBitmap = NULL;
}

Graphics::Graphics(HWND* hWnd) {

	this->hWnd = hWnd;
	factory = NULL;
	renderTarget = NULL;
	launcherBitmap = NULL;
	buildingBitmap = NULL;
	missileBitmap = NULL;
	bombBitmap = NULL;
}

Graphics::~Graphics() {

	if (factory)
		factory->Release();

	if (renderTarget)
		renderTarget->Release();
}

bool Graphics::Init() {

	HRESULT hR = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &factory);

	if (!SUCCEEDED(hR))
		return false;

	RECT rect;

	GetClientRect(*hWnd, &rect);

	D2D1_SIZE_U size = D2D1::SizeU(rect.right, rect.bottom);

	factory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(), 
		D2D1::HwndRenderTargetProperties(*hWnd, size), &renderTarget);

	if (!SUCCEEDED(hR))
		return false;

	Bitmapper b = Bitmapper();
	Bitmapper* bitmapper = &b;
	
	if (b.Init()) {

		mapBitmap = bitmapper->GetBitmap(L"mountains.jpg", renderTarget);
		cannonBitmap = bitmapper->GetBitmap(L"cannon.png", renderTarget);
		launcherBitmap = bitmapper->GetBitmap(L"dome.png", renderTarget);
		buildingBitmap = bitmapper->GetBitmap(L"building.png", renderTarget);
		missileBitmap = bitmapper->GetBitmap(L"missile.png", renderTarget);
		bombBitmap = bitmapper->GetBitmap(L"bomb.png", renderTarget);
		missileExplosionBitmap = bitmapper->GetBitmap(L"blue-explosion.png", renderTarget);
		bombExplosionBitmap = bitmapper->GetBitmap(L"red-explosion.png", renderTarget);
		flashBitmap = bitmapper->GetBitmap(L"flash.png", renderTarget);

		return true;
	}

	return false;
}

void Graphics::ClearScreen(Color color) {

	renderTarget->Clear(D2D1::ColorF(color.red, color.green, color.blue, color.alpha));
}

void Graphics::DrawMenu(Menu menu) {

}

void Graphics::DrawGame(Game game) {

	ClearScreen(Color(1.0f, 1.0f, 1.0f, 1.0f));

	D2D1_RECT_F rect;

	rect = D2D1::RectF(0, 0, Game::MAX_X, Game::MAX_Y);
	renderTarget->DrawBitmap(mapBitmap, rect, 0.85f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);

	for (Flash flash : ItemManager::GetFlashes()) {

		rect = D2D1::RectF(flash.GetCenter().x - flash.GetRadius(),
			flash.GetCenter().y - flash.GetRadius(),
			flash.GetCenter().x + flash.GetRadius(),
			flash.GetCenter().y + flash.GetRadius());
		renderTarget->SetTransform(D2D1::Matrix3x2F::Rotation(flash.GetAngleDeg(),
			D2D1::Point2F(flash.GetCenter().x, flash.GetCenter().y)));
		renderTarget->DrawBitmap(flashBitmap, rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
		renderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
	}

	Launcher launcher = ItemManager::GetLauncher();

	rect = D2D1::RectF(Game::LAUNCHER_CANNON_BOTTOM_CENTER.x - Game::LAUNCHER_CANNON_HALF_WIDTH, 
		Game::LAUNCHER_CANNON_BOTTOM_CENTER.y - Game::LAUNCHER_CANNON_HALF_HEIGHT * 2, 
		Game::LAUNCHER_CANNON_BOTTOM_CENTER.x + Game::LAUNCHER_CANNON_HALF_WIDTH, 
		Game::LAUNCHER_CANNON_BOTTOM_CENTER.y);
	renderTarget->SetTransform(D2D1::Matrix3x2F::Rotation(launcher.GetAngleDeg(),
		D2D1::Point2F(Game::LAUNCHER_CANNON_BOTTOM_CENTER.x, Game::LAUNCHER_CANNON_BOTTOM_CENTER.y)));
	renderTarget->DrawBitmap(cannonBitmap, rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
	renderTarget->SetTransform(D2D1::Matrix3x2F::Identity());

	rect = D2D1::RectF(launcher.GetCenter().x - Game::LAUNCHER_HALF_WIDTH,
		launcher.GetCenter().y - Game::LAUNCHER_HALF_HEIGHT,
		launcher.GetCenter().x + Game::LAUNCHER_HALF_WIDTH,
		launcher.GetCenter().y + Game::LAUNCHER_HALF_HEIGHT);
	renderTarget->DrawBitmap(launcherBitmap, rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);

	for (Building building : ItemManager::GetBuildings()) {

		rect = D2D1::RectF(building.GetCenter().x - Game::BUILDING_HALF_WIDTH,
			building.GetCenter().y - Game::BUILDING_HALF_HEIGHT,
			building.GetCenter().x + Game::BUILDING_HALF_WIDTH,
			building.GetCenter().y + Game::BUILDING_HALF_HEIGHT);
		renderTarget->DrawBitmap(buildingBitmap, rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
	}

	for (Missile missile : ItemManager::GetMissiles()) {

		rect = D2D1::RectF(missile.GetCenter().x - Game::MISSILE_HALF_WIDTH,
			missile.GetCenter().y - Game::MISSILE_HALF_HEIGHT,
			missile.GetCenter().x + Game::MISSILE_HALF_WIDTH,
			missile.GetCenter().y + Game::MISSILE_HALF_HEIGHT);
		renderTarget->SetTransform(D2D1::Matrix3x2F::Rotation(missile.GetAngleDeg(), 
			D2D1::Point2F(missile.GetCenter().x, missile.GetCenter().y)));
		renderTarget->DrawBitmap(missileBitmap, rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
		renderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
	}

	for (Bomb bomb : ItemManager::GetBombs()) {

		rect = D2D1::RectF(bomb.GetCenter().x - Game::BOMB_HALF_WIDTH,
			bomb.GetCenter().y - Game::BOMB_HALF_HEIGHT,
			bomb.GetCenter().x + Game::BOMB_HALF_WIDTH,
			bomb.GetCenter().y + Game::BOMB_HALF_HEIGHT);
		renderTarget->SetTransform(D2D1::Matrix3x2F::Rotation(bomb.GetAngleDeg() + 180.0f,
			D2D1::Point2F(bomb.GetCenter().x, bomb.GetCenter().y)));
		renderTarget->DrawBitmap(bombBitmap, rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
		renderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
	}

	for (Explosion explosion : ItemManager::GetExplosions()) {

		rect = D2D1::RectF(explosion.GetCenter().x - explosion.GetRadius(),
			explosion.GetCenter().y - explosion.GetRadius(),
			explosion.GetCenter().x + explosion.GetRadius(),
			explosion.GetCenter().y + explosion.GetRadius());
		renderTarget->SetTransform(D2D1::Matrix3x2F::Rotation(Generator::GetRandomUniform(0.0f, 360.0f),
			D2D1::Point2F(explosion.GetCenter().x, explosion.GetCenter().y)));
		
		switch (explosion.GetSource()) {
		
			case missile: renderTarget->DrawBitmap(missileExplosionBitmap, rect, 1.0f, 
				D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
				break;

			case normal: renderTarget->DrawBitmap(bombExplosionBitmap, rect, 1.0f,
				D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
				break;
		}

		renderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
	}
}




