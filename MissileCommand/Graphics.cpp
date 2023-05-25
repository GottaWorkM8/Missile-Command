#include "Graphics.h"

Graphics::Graphics() {
	
	hWnd = NULL;
	factory = NULL;
	renderTarget = NULL;
	textRenderer = NULL;
	brush = NULL;
}

Graphics::Graphics(HWND* hWnd) {

	this->hWnd = hWnd;
	factory = NULL;
	renderTarget = NULL;
	textRenderer = NULL;
	brush = NULL;
}

Graphics::~Graphics() {

	if (factory)
		factory->Release();

	if (renderTarget)
		renderTarget->Release();

	if (textRenderer)
		delete textRenderer;

	if (brush)
		brush->Release();
}

bool Graphics::Init() {

	// necessary to create render target (draw area)
	HRESULT hR = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &factory);

	if (!SUCCEEDED(hR))
		return false;

	RECT rect;

	GetClientRect(*hWnd, &rect);

	D2D1_SIZE_U size = D2D1::SizeU(rect.right, rect.bottom);

	// creation of render target (draw area)
	hR = factory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(), 
		D2D1::HwndRenderTargetProperties(*hWnd, size), &renderTarget);

	if (!SUCCEEDED(hR))
		return false;
	
	// creation of brush needed for drawing text and simple shapes
	hR = renderTarget->CreateSolidColorBrush(D2D1::ColorF(1.0f, 1.0f, 1.0f, 1.0f), &brush);

	if (!SUCCEEDED(hR))
		return false;

	// necessary for creating text that is drawn later
	textRenderer = new TextRenderer(renderTarget);

	if (textRenderer->Init())
		for (MenuButton& button : Menu::GetButtons()) {

			IDWriteTextLayout* textLayout = textRenderer->GetAdjustedTextLayout(button.GetText(),
				L"Arial", true, button.GetHeight());
			button.SetTextLayout(textLayout);
			button.SetWidth(textLayout->GetMaxWidth());
		}

	// necessary for creating bitmaps of image files that are drawn later
	Bitmapper bitmapper = Bitmapper(renderTarget);
	
	// initialization of bitmapper and creation of bitmaps for later use
	if (bitmapper.Init()) {

		menuBitmap = bitmapper.GetBitmap(L"menu-background.jpg");
		titleBitmap = bitmapper.GetBitmap(L"title.png");
		mapBitmap = bitmapper.GetBitmap(L"mountains.jpg");
		cannonBitmap = bitmapper.GetBitmap(L"cannon.png");
		launcherBitmap = bitmapper.GetBitmap(L"dome.png");
		buildingBitmap = bitmapper.GetBitmap(L"building-green.png");
		missileBitmap = bitmapper.GetBitmap(L"missile.png");
		normalBombBitmap = bitmapper.GetBitmap(L"normal.png");
		nuclearBombBitmap = bitmapper.GetBitmap(L"nuclear.png");
		clusterBombBitmap = bitmapper.GetBitmap(L"cluster.png");
		napalmBombBitmap = bitmapper.GetBitmap(L"napalm.png");
		rodBombBitmap = bitmapper.GetBitmap(L"rod-of-god.png");
		missileExplosionBitmap = bitmapper.GetBitmap(L"blue-explosion.png");
		normalExplosionBitmap = bitmapper.GetBitmap(L"red-explosion.png");
		nuclearExplosionBitmap = bitmapper.GetBitmap(L"yellow-explosion.png");
		clusterExplosionBitmap = bitmapper.GetBitmap(L"purple-explosion.png");
		napalmExplosionBitmap = bitmapper.GetBitmap(L"yellow-explosion.png");
		rodExplosionBitmap = bitmapper.GetBitmap(L"cyan-explosion.png");
		flashBitmap = bitmapper.GetBitmap(L"flash.png");
		ammoBitmap = bitmapper.GetBitmap(L"ammo.png");

		return true;
	}

	return false;
}

void Graphics::BeginDraw() {

	renderTarget->BeginDraw();
}

void Graphics::EndDraw() {

	renderTarget->EndDraw();
}

void Graphics::ClearScreen(Color color) {

	renderTarget->Clear(D2D1::ColorF(color.red, color.green, color.blue, color.alpha));
}

void Graphics::DrawMenu() {

	ClearScreen(Color(1.0f, 1.0f, 1.0f, 1.0f));

	D2D1_RECT_F rect;

	rect = D2D1::RectF(0, 0, Globals::MAX_X, Globals::MAX_Y);
	renderTarget->DrawBitmap(menuBitmap, rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);

	rect = D2D1::RectF(Globals::TITLE_TOP_LEFT.x, Globals::TITLE_TOP_LEFT.y,
		Globals::TITLE_TOP_LEFT.x + Globals::TITLE_WIDTH, Globals::TITLE_TOP_LEFT.y + Globals::TITLE_HEIGHT);
	renderTarget->DrawBitmap(titleBitmap, rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);

	for (MenuButton& button : Menu::GetButtons()) {
	
		if (button.IsHovered())
			renderTarget->DrawTextLayout(D2D1::Point2F(button.GetTopLeft().x, button.GetTopLeft().y),
				button.GetTextLayout(), brush);

		else {

			D2D1_COLOR_F color = brush->GetColor();
			color.a = 0.8f;
			brush->SetColor(color);
			renderTarget->DrawTextLayout(D2D1::Point2F(button.GetTopLeft().x, button.GetTopLeft().y),
				button.GetTextLayout(), brush);
			color.a = 1.0f;
			brush->SetColor(color);
		}
	}
}

void Graphics::DrawGame() {

	ClearScreen(Color(1.0f, 1.0f, 1.0f, 1.0f));

	D2D1_RECT_F rect;

	rect = D2D1::RectF(0, 0, Globals::MAX_X, Globals::MAX_Y);
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

	rect = D2D1::RectF(Globals::LAUNCHER_CANNON_BOTTOM_CENTER.x - Globals::LAUNCHER_CANNON_HALF_WIDTH,
		Globals::LAUNCHER_CANNON_BOTTOM_CENTER.y - Globals::LAUNCHER_CANNON_HALF_HEIGHT * 2,
		Globals::LAUNCHER_CANNON_BOTTOM_CENTER.x + Globals::LAUNCHER_CANNON_HALF_WIDTH,
		Globals::LAUNCHER_CANNON_BOTTOM_CENTER.y);
	renderTarget->SetTransform(D2D1::Matrix3x2F::Rotation(launcher.GetAngleDeg(),
		D2D1::Point2F(Globals::LAUNCHER_CANNON_BOTTOM_CENTER.x, Globals::LAUNCHER_CANNON_BOTTOM_CENTER.y)));
	renderTarget->DrawBitmap(cannonBitmap, rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
	renderTarget->SetTransform(D2D1::Matrix3x2F::Identity());

	rect = D2D1::RectF(launcher.GetCenter().x - Globals::LAUNCHER_HALF_WIDTH,
		launcher.GetCenter().y - Globals::LAUNCHER_HALF_HEIGHT,
		launcher.GetCenter().x + Globals::LAUNCHER_HALF_WIDTH,
		launcher.GetCenter().y + Globals::LAUNCHER_HALF_HEIGHT);
	renderTarget->DrawBitmap(launcherBitmap, rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);

	for (Building building : ItemManager::GetBuildings()) {

		rect = D2D1::RectF(building.GetCenter().x - Globals::BUILDING_HALF_WIDTH,
			building.GetCenter().y - Globals::BUILDING_HALF_HEIGHT,
			building.GetCenter().x + Globals::BUILDING_HALF_WIDTH,
			building.GetCenter().y + Globals::BUILDING_HALF_HEIGHT);
		renderTarget->DrawBitmap(buildingBitmap, rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
	}

	for (Missile missile : ItemManager::GetMissiles()) {

		rect = D2D1::RectF(missile.GetCenter().x - Globals::MISSILE_HALF_WIDTH,
			missile.GetCenter().y - Globals::MISSILE_HALF_HEIGHT,
			missile.GetCenter().x + Globals::MISSILE_HALF_WIDTH,
			missile.GetCenter().y + Globals::MISSILE_HALF_HEIGHT);
		renderTarget->SetTransform(D2D1::Matrix3x2F::Rotation(missile.GetAngleDeg(), 
			D2D1::Point2F(missile.GetCenter().x, missile.GetCenter().y)));
		renderTarget->DrawBitmap(missileBitmap, rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
		renderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
	}

	for (Bomb bomb : ItemManager::GetBombs()) {

		rect = D2D1::RectF(bomb.GetCenter().x - Globals::BOMB_HALF_WIDTH,
			bomb.GetCenter().y - Globals::BOMB_HALF_HEIGHT,
			bomb.GetCenter().x + Globals::BOMB_HALF_WIDTH,
			bomb.GetCenter().y + Globals::BOMB_HALF_HEIGHT);
		renderTarget->SetTransform(D2D1::Matrix3x2F::Rotation(bomb.GetAngleDeg() + 180.0f,
			D2D1::Point2F(bomb.GetCenter().x, bomb.GetCenter().y)));

		switch (bomb.GetSource()) {

			case NORMAL:
				renderTarget->DrawBitmap(normalBombBitmap, rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
				break;

			case NUCLEAR:
				renderTarget->DrawBitmap(nuclearBombBitmap, rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
				break;

			case CLUSTER:
				renderTarget->DrawBitmap(clusterBombBitmap, rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
				break;

			case NAPALM:
				renderTarget->DrawBitmap(napalmBombBitmap, rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
				break;

			case RODOFGOD:
				renderTarget->DrawBitmap(rodBombBitmap, rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
				break;

			default:
				renderTarget->DrawBitmap(normalBombBitmap, rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
				break;
		}

		renderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
	}

	for (Explosion explosion : ItemManager::GetExplosions()) {

		rect = D2D1::RectF(explosion.GetCenter().x - explosion.GetRadius(),
			explosion.GetCenter().y - explosion.GetRadius(),
			explosion.GetCenter().x + explosion.GetRadius(),
			explosion.GetCenter().y + explosion.GetRadius());
		renderTarget->SetTransform(D2D1::Matrix3x2F::Rotation(explosion.GetAngleDeg(),
			D2D1::Point2F(explosion.GetCenter().x, explosion.GetCenter().y)));
		
		switch (explosion.GetSource()) {
		
			case MISSILE: 
				renderTarget->DrawBitmap(missileExplosionBitmap, rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
				break;

			case NORMAL: 
				renderTarget->DrawBitmap(normalExplosionBitmap, rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
				break;

			case NUCLEAR:
				renderTarget->DrawBitmap(nuclearExplosionBitmap, rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
				break;

			case CLUSTER:
				renderTarget->DrawBitmap(clusterExplosionBitmap, rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
				break;

			case NAPALM:
				renderTarget->DrawBitmap(napalmExplosionBitmap, rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
				break;

			case RODOFGOD: 
				renderTarget->DrawBitmap(rodExplosionBitmap, rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
				break;

			default:
				renderTarget->DrawBitmap(normalExplosionBitmap, rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
				break;
		}

		renderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
	}

	DrawBar();
}

void Graphics::DrawBar() {

	D2D1_RECT_F rect = D2D1::RectF(0, Globals::BAR_Y, Globals::MAX_X, Globals::MAX_Y);
	D2D1_COLOR_F prevColor = brush->GetColor();
	D2D1_COLOR_F newColor = D2D1::ColorF(0.0f, 0.0f, 0.0f, 0.5f);
	brush->SetColor(newColor);
	renderTarget->FillRectangle(rect, brush);
	brush->SetColor(prevColor);

	float alpha = 1.0f;
	float newAlpha = 0.3f;

	rect = D2D1::RectF(Globals::FIRST_BAR_ICON_X, Globals::BAR_ICON_Y, Globals::FIRST_BAR_ICON_RIGHT, Globals::BAR_ICON_BOTTOM);

	if (Game::GetAmmo() < 1)
		alpha = newAlpha;

	renderTarget->DrawBitmap(ammoBitmap, rect, alpha, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
	rect = D2D1::RectF(Globals::SECOND_BAR_ICON_X, Globals::BAR_ICON_Y, Globals::SECOND_BAR_ICON_RIGHT, Globals::BAR_ICON_BOTTOM);

	if (Game::GetAmmo() < 2)
		alpha = newAlpha;

	renderTarget->DrawBitmap(ammoBitmap, rect, alpha, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
	rect = D2D1::RectF(Globals::THIRD_BAR_ICON_X, Globals::BAR_ICON_Y, Globals::THIRD_BAR_ICON_RIGHT, Globals::BAR_ICON_BOTTOM);

	if (Game::GetAmmo() < 3)
		alpha = newAlpha;

	renderTarget->DrawBitmap(ammoBitmap, rect, alpha, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
	rect = D2D1::RectF(Globals::FOURTH_BAR_ICON_X, Globals::BAR_ICON_Y, Globals::FOURTH_BAR_ICON_RIGHT, Globals::BAR_ICON_BOTTOM);

	if (Game::GetAmmo() < 4)
		alpha = newAlpha;

	renderTarget->DrawBitmap(ammoBitmap, rect, alpha, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
	rect = D2D1::RectF(Globals::FIFTH_BAR_ICON_X, Globals::BAR_ICON_Y, Globals::FIFTH_BAR_ICON_RIGHT, Globals::BAR_ICON_BOTTOM);

	if (Game::GetAmmo() < 5)
		alpha = newAlpha;

	renderTarget->DrawBitmap(ammoBitmap, rect, alpha, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);

	DrawInt(Game::GetScore(), Globals::BAR_SCORE_HEIGHT, Point(Globals::CENTER_X, Globals::BAR_SCORE_Y));

	rect = D2D1::RectF(Globals::FIRST_BAR_BOMB_X, Globals::BAR_BOMB_Y, Globals::FIRST_BAR_BOMB_RIGHT, Globals::BAR_BOMB_BOTTOM);
	renderTarget->DrawBitmap(normalBombBitmap, rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
	DrawInt(Game::GetNormalNum(), Globals::BAR_BOMB_NUM_HEIGHT, Point(Globals::FIRST_BAR_BOMB_NUM_CENTER, Globals::BAR_BOMB_NUM_Y));

	rect = D2D1::RectF(Globals::SECOND_BAR_BOMB_X, Globals::BAR_BOMB_Y, Globals::SECOND_BAR_BOMB_RIGHT, Globals::BAR_BOMB_BOTTOM);
	renderTarget->DrawBitmap(nuclearBombBitmap, rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
	DrawInt(Game::GetNuclearNum(), Globals::BAR_BOMB_NUM_HEIGHT, Point(Globals::SECOND_BAR_BOMB_NUM_CENTER, Globals::BAR_BOMB_NUM_Y));

	rect = D2D1::RectF(Globals::THIRD_BAR_BOMB_X, Globals::BAR_BOMB_Y, Globals::THIRD_BAR_BOMB_RIGHT, Globals::BAR_BOMB_BOTTOM);
	renderTarget->DrawBitmap(clusterBombBitmap, rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
	DrawInt(Game::GetClusterNum(), Globals::BAR_BOMB_NUM_HEIGHT, Point(Globals::THIRD_BAR_BOMB_NUM_CENTER, Globals::BAR_BOMB_NUM_Y));

	rect = D2D1::RectF(Globals::FOURTH_BAR_BOMB_X, Globals::BAR_BOMB_Y, Globals::FOURTH_BAR_BOMB_RIGHT, Globals::BAR_BOMB_BOTTOM);
	renderTarget->DrawBitmap(napalmBombBitmap, rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
	DrawInt(Game::GetNapalmNum(), Globals::BAR_BOMB_NUM_HEIGHT, Point(Globals::FOURTH_BAR_BOMB_NUM_CENTER, Globals::BAR_BOMB_NUM_Y));

	rect = D2D1::RectF(Globals::FIFTH_BAR_BOMB_X, Globals::BAR_BOMB_Y, Globals::FIFTH_BAR_BOMB_RIGHT, Globals::BAR_BOMB_BOTTOM);
	renderTarget->DrawBitmap(rodBombBitmap, rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
	DrawInt(Game::GetRodNum(), Globals::BAR_BOMB_NUM_HEIGHT, Point(Globals::FIFTH_BAR_BOMB_NUM_CENTER, Globals::BAR_BOMB_NUM_Y));
}

void Graphics::DrawInt(int num, float height, Point topCenter) {

	std::wstringstream wss;
	wss << num;
	std::wstring ws = wss.str();
	const wchar_t* text = ws.c_str();

	IDWriteTextLayout* textLayout = textRenderer->GetAdjustedTextLayout(text, L"Times New Roman", false, height);
	DWRITE_TEXT_METRICS textMetrics;
	textLayout->GetMetrics(&textMetrics);
	float width = textMetrics.width;
	renderTarget->DrawTextLayout(D2D1::Point2F(topCenter.x - (width / 2), topCenter.y), textLayout, brush);
}
