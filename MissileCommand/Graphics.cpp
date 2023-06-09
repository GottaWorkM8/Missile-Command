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
	hR = renderTarget->CreateSolidColorBrush(Globals::BRUSH_DEFAULT_COLOR, &brush);

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
	bitmapper = new Bitmapper(renderTarget);
	
	// initialization of bitmapper and creation of bitmaps for later use
	if (bitmapper->Init())
		BitmapManager::Init(bitmapper);

	else return false;

	return true;
}

void Graphics::BeginDraw() {

	renderTarget->BeginDraw();
}

void Graphics::EndDraw() {

	renderTarget->EndDraw();
}

void Graphics::ClearScreen() {

	renderTarget->Clear(Globals::BRUSH_DEFAULT_COLOR);
}

void Graphics::DrawMenu() {

	ClearScreen();

	D2D1_RECT_F rect;

	rect = D2D1::RectF(0, 0, Globals::MAX_X, Globals::MAX_Y);
	renderTarget->DrawBitmap(BitmapManager::GetMenuBitmap(), rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);

	rect = D2D1::RectF(Globals::TITLE_TOP_LEFT.x, Globals::TITLE_TOP_LEFT.y,
		Globals::TITLE_TOP_LEFT.x + Globals::TITLE_WIDTH, Globals::TITLE_TOP_LEFT.y + Globals::TITLE_HEIGHT);
	renderTarget->DrawBitmap(BitmapManager::GetTitleBitmap(), rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);

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

	ClearScreen();

	D2D1_RECT_F rect;

	rect = D2D1::RectF(0, 0, Globals::MAX_X, Globals::MAX_Y);
	renderTarget->DrawBitmap(BitmapManager::GetMapBitmap(), rect, 0.85f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);

	for (Flash flash : ItemManager::GetFlashes()) {

		rect = D2D1::RectF(flash.GetCenter().x - flash.GetRadius(),
			flash.GetCenter().y - flash.GetRadius(),
			flash.GetCenter().x + flash.GetRadius(),
			flash.GetCenter().y + flash.GetRadius());
		renderTarget->SetTransform(D2D1::Matrix3x2F::Rotation(flash.GetAngleDeg(),
			D2D1::Point2F(flash.GetCenter().x, flash.GetCenter().y)));
		renderTarget->DrawBitmap(BitmapManager::GetFlashBitmap(), rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
		renderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
	}

	Launcher launcher = ItemManager::GetLauncher();

	rect = D2D1::RectF(Globals::LAUNCHER_CANNON_BOTTOM_CENTER.x - Globals::LAUNCHER_CANNON_HALF_WIDTH,
		Globals::LAUNCHER_CANNON_BOTTOM_CENTER.y - Globals::LAUNCHER_CANNON_HALF_HEIGHT * 2,
		Globals::LAUNCHER_CANNON_BOTTOM_CENTER.x + Globals::LAUNCHER_CANNON_HALF_WIDTH,
		Globals::LAUNCHER_CANNON_BOTTOM_CENTER.y);
	renderTarget->SetTransform(D2D1::Matrix3x2F::Rotation(launcher.GetAngleDeg(),
		D2D1::Point2F(Globals::LAUNCHER_CANNON_BOTTOM_CENTER.x, Globals::LAUNCHER_CANNON_BOTTOM_CENTER.y)));
	renderTarget->DrawBitmap(BitmapManager::GetCannonBitmap(), rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
	renderTarget->SetTransform(D2D1::Matrix3x2F::Identity());

	rect = D2D1::RectF(launcher.GetCenter().x - Globals::LAUNCHER_HALF_WIDTH,
		launcher.GetCenter().y - Globals::LAUNCHER_HALF_HEIGHT,
		launcher.GetCenter().x + Globals::LAUNCHER_HALF_WIDTH,
		launcher.GetCenter().y + Globals::LAUNCHER_HALF_HEIGHT);
	renderTarget->DrawBitmap(BitmapManager::GetLauncherBitmap(), rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);

	int index = 0;

	for (Building building : ItemManager::GetBuildings()) {

		rect = D2D1::RectF(building.GetCenter().x - Globals::BUILDING_HALF_WIDTH,
			building.GetCenter().y - Globals::BUILDING_HALF_HEIGHT,
			building.GetCenter().x + Globals::BUILDING_HALF_WIDTH,
			building.GetCenter().y + Globals::BUILDING_HALF_HEIGHT);
		
		D2D1_SIZE_U originalSize = BitmapManager::GetBuildingBitmap(index)->GetPixelSize();
		float desiredHeight = static_cast<float>(originalSize.height) / originalSize.width * Globals::BUILDING_HALF_WIDTH * 2;
		rect.top = rect.bottom - desiredHeight;
		renderTarget->DrawBitmap(BitmapManager::GetBuildingBitmap(index), rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
		index++;
	}

	for (Missile missile : ItemManager::GetMissiles()) {

		rect = D2D1::RectF(missile.GetCenter().x - Globals::MISSILE_HALF_WIDTH,
			missile.GetCenter().y - Globals::MISSILE_HALF_HEIGHT,
			missile.GetCenter().x + Globals::MISSILE_HALF_WIDTH,
			missile.GetCenter().y + Globals::MISSILE_HALF_HEIGHT);
		renderTarget->SetTransform(D2D1::Matrix3x2F::Rotation(missile.GetAngleDeg(), 
			D2D1::Point2F(missile.GetCenter().x, missile.GetCenter().y)));
		renderTarget->DrawBitmap(BitmapManager::GetMissileBitmap(), rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
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
				renderTarget->DrawBitmap(BitmapManager::GetNormalBombBitmap(), rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
				break;

			case NUCLEAR:
				renderTarget->DrawBitmap(BitmapManager::GetNuclearBombBitmap(), rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
				break;

			case CLUSTER:
				renderTarget->DrawBitmap(BitmapManager::GetClusterBombBitmap(), rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
				break;

			case NAPALM:
				renderTarget->DrawBitmap(BitmapManager::GetNapalmBombBitmap(), rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
				break;

			case RODOFGOD:
				renderTarget->DrawBitmap(BitmapManager::GetRodBombBitmap(), rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
				break;

			default:
				renderTarget->DrawBitmap(BitmapManager::GetNormalBombBitmap(), rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
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
				renderTarget->DrawBitmap(BitmapManager::GetMissileExplosionBitmap(), rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
				break;

			case NORMAL: 
				renderTarget->DrawBitmap(BitmapManager::GetNormalExplosionBitmap(), rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
				break;

			case NUCLEAR:
				renderTarget->DrawBitmap(BitmapManager::GetNuclearExplosionBitmap(), rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
				break;

			case CLUSTER:
				renderTarget->DrawBitmap(BitmapManager::GetClusterExplosionBitmap(), rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
				break;

			case NAPALM:
				renderTarget->DrawBitmap(BitmapManager::GetNapalmExplosionBitmap(), rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
				break;

			case RODOFGOD: 
				renderTarget->DrawBitmap(BitmapManager::GetRodExplosionBitmap(), rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
				break;

			default:
				renderTarget->DrawBitmap(BitmapManager::GetNormalExplosionBitmap(), rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
				break;
		}

		renderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
	}

	for (Destruction destruction : ItemManager::GetDestructions()) {

		rect = D2D1::RectF(destruction.GetCenter().x - destruction.GetRadius(),
			destruction.GetCenter().y - destruction.GetRadius(),
			destruction.GetCenter().x + destruction.GetRadius(),
			destruction.GetCenter().y + destruction.GetRadius());
		renderTarget->SetTransform(D2D1::Matrix3x2F::Rotation(destruction.GetAngleDeg(),
			D2D1::Point2F(destruction.GetCenter().x, destruction.GetCenter().y)));
		renderTarget->DrawBitmap(BitmapManager::GetDestructionBitmap(), rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
		renderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
	}

	if (Game::GetIntro())
		DrawIntro();

	DrawBar();
}

void Graphics::DrawIntro() {

	D2D1_RECT_F rect = D2D1::RectF(0, Globals::INTRO_BAR_Y, Globals::MAX_X, Globals::INTRO_BAR_BOTTOM);
	brush->SetColor(Popup::backgroundColor);
	renderTarget->FillRectangle(rect, brush);
	brush->SetColor(Popup::textColor);
	DrawLabel(Game::GetLocation(), L"Courier New", Globals::INTRO_HEIGHT, Point(Globals::CENTER_X, Globals::INTRO_Y), true);
}

void Graphics::DrawBar() {

	D2D1_RECT_F rect = D2D1::RectF(0, Globals::BAR_Y, Globals::MAX_X, Globals::MAX_Y);
	D2D1_POINT_2F point1;
	D2D1_POINT_2F point2;
	point1.x = rect.left;
	point1.y = rect.top;
	point2.x = rect.right;
	point2.y = rect.top;
	brush->SetColor(Globals::PROMPT_BACKGROUND_COLOR);;
	renderTarget->FillRectangle(rect, brush);
	brush->SetColor(Globals::BRUSH_DEFAULT_COLOR);
	renderTarget->DrawLine(point1, point2, brush);

	float alpha = 1.0f;
	float newAlpha = 0.3f;

	rect = D2D1::RectF(Globals::FIRST_BAR_ICON_X, Globals::BAR_ICON_Y, Globals::FIRST_BAR_ICON_RIGHT, Globals::BAR_ICON_BOTTOM);

	if (Game::GetAmmo() < 1)
		alpha = newAlpha;

	renderTarget->DrawBitmap(BitmapManager::GetAmmoBitmap(), rect, alpha, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
	rect = D2D1::RectF(Globals::SECOND_BAR_ICON_X, Globals::BAR_ICON_Y, Globals::SECOND_BAR_ICON_RIGHT, Globals::BAR_ICON_BOTTOM);

	if (Game::GetAmmo() < 2)
		alpha = newAlpha;

	renderTarget->DrawBitmap(BitmapManager::GetAmmoBitmap(), rect, alpha, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
	rect = D2D1::RectF(Globals::THIRD_BAR_ICON_X, Globals::BAR_ICON_Y, Globals::THIRD_BAR_ICON_RIGHT, Globals::BAR_ICON_BOTTOM);

	if (Game::GetAmmo() < 3)
		alpha = newAlpha;

	renderTarget->DrawBitmap(BitmapManager::GetAmmoBitmap(), rect, alpha, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
	rect = D2D1::RectF(Globals::FOURTH_BAR_ICON_X, Globals::BAR_ICON_Y, Globals::FOURTH_BAR_ICON_RIGHT, Globals::BAR_ICON_BOTTOM);

	if (Game::GetAmmo() < 4)
		alpha = newAlpha;

	renderTarget->DrawBitmap(BitmapManager::GetAmmoBitmap(), rect, alpha, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
	rect = D2D1::RectF(Globals::FIFTH_BAR_ICON_X, Globals::BAR_ICON_Y, Globals::FIFTH_BAR_ICON_RIGHT, Globals::BAR_ICON_BOTTOM);

	if (Game::GetAmmo() < 5)
		alpha = newAlpha;

	renderTarget->DrawBitmap(BitmapManager::GetAmmoBitmap(), rect, alpha, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);

	DrawInt(Game::GetScore(), L"Tahoma", Globals::BAR_SCORE_HEIGHT, Point(Globals::CENTER_X, Globals::BAR_SCORE_Y), false);

	rect = D2D1::RectF(Globals::FIRST_BAR_BOMB_X, Globals::BAR_BOMB_Y, Globals::FIRST_BAR_BOMB_RIGHT, Globals::BAR_BOMB_BOTTOM);
	renderTarget->DrawBitmap(BitmapManager::GetNormalBombBitmap(), rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
	DrawInt(Game::GetNormalNum(), L"Times New Roman", Globals::BAR_BOMB_NUM_HEIGHT, 
		Point(Globals::FIRST_BAR_BOMB_NUM_CENTER, Globals::BAR_BOMB_NUM_Y), false);

	rect = D2D1::RectF(Globals::SECOND_BAR_BOMB_X, Globals::BAR_BOMB_Y, Globals::SECOND_BAR_BOMB_RIGHT, Globals::BAR_BOMB_BOTTOM);
	renderTarget->DrawBitmap(BitmapManager::GetNuclearBombBitmap(), rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
	DrawInt(Game::GetNuclearNum(), L"Times New Roman", Globals::BAR_BOMB_NUM_HEIGHT, 
		Point(Globals::SECOND_BAR_BOMB_NUM_CENTER, Globals::BAR_BOMB_NUM_Y), false);

	rect = D2D1::RectF(Globals::THIRD_BAR_BOMB_X, Globals::BAR_BOMB_Y, Globals::THIRD_BAR_BOMB_RIGHT, Globals::BAR_BOMB_BOTTOM);
	renderTarget->DrawBitmap(BitmapManager::GetClusterBombBitmap(), rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
	DrawInt(Game::GetClusterNum(), L"Times New Roman", Globals::BAR_BOMB_NUM_HEIGHT, 
		Point(Globals::THIRD_BAR_BOMB_NUM_CENTER, Globals::BAR_BOMB_NUM_Y), false);

	rect = D2D1::RectF(Globals::FOURTH_BAR_BOMB_X, Globals::BAR_BOMB_Y, Globals::FOURTH_BAR_BOMB_RIGHT, Globals::BAR_BOMB_BOTTOM);
	renderTarget->DrawBitmap(BitmapManager::GetNapalmBombBitmap(), rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
	DrawInt(Game::GetNapalmNum(), L"Times New Roman", Globals::BAR_BOMB_NUM_HEIGHT, 
		Point(Globals::FOURTH_BAR_BOMB_NUM_CENTER, Globals::BAR_BOMB_NUM_Y), false);

	rect = D2D1::RectF(Globals::FIFTH_BAR_BOMB_X, Globals::BAR_BOMB_Y, Globals::FIFTH_BAR_BOMB_RIGHT, Globals::BAR_BOMB_BOTTOM);
	renderTarget->DrawBitmap(BitmapManager::GetRodBombBitmap(), rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
	DrawInt(Game::GetRodNum(), L"Times New Roman", Globals::BAR_BOMB_NUM_HEIGHT, 
		Point(Globals::FIFTH_BAR_BOMB_NUM_CENTER, Globals::BAR_BOMB_NUM_Y), false);
}

void Graphics::DrawInt(int num, const wchar_t* font, float height, Point topCenter, bool bold) {

	std::wstringstream wss;
	wss << num;
	std::wstring ws = wss.str();
	const wchar_t* text = ws.c_str();

	DrawLabel(text, font, height, topCenter, bold);
}

void Graphics::DrawLabel(const wchar_t* text, const wchar_t* font, float height, Point topCenter, bool bold) {

	IDWriteTextLayout* textLayout = textRenderer->GetAdjustedTextLayout(text, font, bold, height);
	DWRITE_TEXT_METRICS textMetrics;
	textLayout->GetMetrics(&textMetrics);
	float width = textMetrics.width;
	renderTarget->DrawTextLayout(D2D1::Point2F(topCenter.x - (width / 2), topCenter.y), textLayout, brush);
}
