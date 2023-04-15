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

		groundBitmap = bitmapper->GetBitmap(L"mountains.jpg", renderTarget);
		launcherBitmap = bitmapper->GetBitmap(L"barracks.png", renderTarget);
		buildingBitmap = bitmapper->GetBitmap(L"building.png", renderTarget);
		missileBitmap = bitmapper->GetBitmap(L"missile.png", renderTarget);
		bombBitmap = bitmapper->GetBitmap(L"bomb.png", renderTarget);

		return true;
	}

	return false;
}

void Graphics::ClearScreen(Color color) {

	renderTarget->Clear(D2D1::ColorF(color.red, color.green, color.blue, color.alpha));
}

void Graphics::DrawGame(Game game) {

	ClearScreen(Color(1.0f, 1.0f, 1.0f, 1.0f));

	D2D1_RECT_F rect;

	rect = D2D1::RectF(0, 0, Game::maxX, Game::maxY);
	renderTarget->DrawBitmap(groundBitmap, rect, 0.85f,
		D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);

	Launcher launcher = ItemManager::GetLauncher();

	rect = D2D1::RectF(launcher.GetCenter().x - Game::launcherHalfWidth,
		launcher.GetCenter().y - Game::launcherHalfHeight,
		launcher.GetCenter().x + Game::launcherHalfWidth,
		launcher.GetCenter().y + Game::launcherHalfHeight);
	renderTarget->DrawBitmap(launcherBitmap, rect, 1.0f,
		D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);

	for (Building building : ItemManager::GetBuildings()) {

		rect = D2D1::RectF(building.GetCenter().x - Game::buildingHalfWidth,
			building.GetCenter().y - Game::buildingHalfHeight,
			building.GetCenter().x + Game::buildingHalfWidth,
			building.GetCenter().y + Game::buildingHalfHeight);
		renderTarget->DrawBitmap(buildingBitmap, rect, 1.0f,
			D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
	}

	for (Missile missile : ItemManager::GetMissiles()) {

		rect = D2D1::RectF(missile.GetCenter().x - Game::missileHalfWidth,
			missile.GetCenter().y - Game::missileHalfHeight,
			missile.GetCenter().x + Game::missileHalfWidth,
			missile.GetCenter().y + Game::missileHalfHeight);
		renderTarget->SetTransform(D2D1::Matrix3x2F::Rotation(missile.GetAngleDeg(), 
			D2D1::Point2F(missile.GetCenter().x, missile.GetCenter().y)));
		renderTarget->DrawBitmap(missileBitmap, rect, 1.0f,
			D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
		renderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
	}

	for (Bomb bomb : ItemManager::GetBombs()) {

		rect = D2D1::RectF(bomb.GetCenter().x - Game::bombHalfWidth,
			bomb.GetCenter().y - Game::bombHalfHeight,
			bomb.GetCenter().x + Game::bombHalfWidth,
			bomb.GetCenter().y + Game::bombHalfHeight);
		renderTarget->SetTransform(D2D1::Matrix3x2F::Rotation(bomb.GetAngleDeg() + 180.0f,
			D2D1::Point2F(bomb.GetCenter().x, bomb.GetCenter().y)));
		renderTarget->DrawBitmap(bombBitmap, rect, 1.0f,
			D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
		renderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
	}

	for (Explosion explosion : ItemManager::GetExplosions()) {

	}
}




