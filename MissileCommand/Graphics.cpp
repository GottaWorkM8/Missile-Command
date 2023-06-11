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

	if (Game::GetSummary() != nullptr)
		if (Game::GetSummary()->IsFinished())
			return;

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

	if (!launcher.IsDestroyed()) {

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
	}

	for (Building building : ItemManager::GetBuildings()) {

		rect = D2D1::RectF(building.GetCenter().x - Globals::BUILDING_HALF_WIDTH,
			building.GetCenter().y - Globals::BUILDING_HALF_HEIGHT,
			building.GetCenter().x + Globals::BUILDING_HALF_WIDTH,
			building.GetCenter().y + Globals::BUILDING_HALF_HEIGHT);

		float properHeight = Calculator::GetProperHeight(BitmapManager::GetBuildingBitmap(building.GetIndex()), Globals::BUILDING_HALF_WIDTH * 2);
		rect.top = rect.bottom - properHeight;
		renderTarget->DrawBitmap(BitmapManager::GetBuildingBitmap(building.GetIndex()), rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
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

	for (Building building : ItemManager::GetBuildings()) {

		float buildingHP = building.GetHP();
		float left = building.GetCenter().x - Globals::HEALTH_BAR_HALF_WIDTH;
		float right = building.GetCenter().x + Globals::HEALTH_BAR_HALF_WIDTH;

		rect = D2D1::RectF(left, Globals::HEALTH_BAR_Y, left + (right - left) * buildingHP / Globals::BUILDING_HP, Globals::HEALTH_BAR_Y + Globals::HEALTH_BAR_HEIGHT);

		if (buildingHP <= 30.0f) {

			brush->SetColor(Globals::LOW_HP_COLOR);
			renderTarget->FillRectangle(rect, brush);
			brush->SetColor(Globals::BRUSH_DEFAULT_COLOR);
		}

		else if (buildingHP <= 60.0f) {

			brush->SetColor(Globals::MID_HP_COLOR);
			renderTarget->FillRectangle(rect, brush);
			brush->SetColor(Globals::BRUSH_DEFAULT_COLOR);
		}

		else {

			brush->SetColor(Globals::HIGH_HP_COLOR);
			renderTarget->FillRectangle(rect, brush);
			brush->SetColor(Globals::BRUSH_DEFAULT_COLOR);
		}

		rect = D2D1::RectF(left, Globals::HEALTH_BAR_Y, right, Globals::HEALTH_BAR_Y + Globals::HEALTH_BAR_HEIGHT);
		renderTarget->DrawRectangle(rect, brush);
	}

	if (!launcher.IsDestroyed()) {

		float launcherHP = launcher.GetHP();
		float left = launcher.GetCenter().x - Globals::LAUNCHER_HEALTH_BAR_HALF_WIDTH;
		float right = launcher.GetCenter().x + Globals::LAUNCHER_HEALTH_BAR_HALF_WIDTH;

		rect = D2D1::RectF(left, Globals::HEALTH_BAR_Y,
			left + (right - left) * launcherHP / Globals::LAUNCHER_HP, Globals::HEALTH_BAR_Y + Globals::LAUNCHER_HEALTH_BAR_HEIGHT);

		if (launcherHP <= 30.0f) {

			brush->SetColor(Globals::LOW_HP_COLOR);
			renderTarget->FillRectangle(rect, brush);
			brush->SetColor(Globals::BRUSH_DEFAULT_COLOR);
		}

		else if (launcherHP <= 60.0f) {

			brush->SetColor(Globals::MID_HP_COLOR);
			renderTarget->FillRectangle(rect, brush);
			brush->SetColor(Globals::BRUSH_DEFAULT_COLOR);
		}

		else {

			brush->SetColor(Globals::HIGH_HP_COLOR);
			renderTarget->FillRectangle(rect, brush);
			brush->SetColor(Globals::BRUSH_DEFAULT_COLOR);
		}

		rect = D2D1::RectF(left, Globals::HEALTH_BAR_Y, right, Globals::HEALTH_BAR_Y + Globals::LAUNCHER_HEALTH_BAR_HEIGHT);
		renderTarget->DrawRectangle(rect, brush);
	}

	if (Game::IsIntroTime())
		if (Game::GetIntro() != nullptr)
			DrawIntro();

	if (Game::IsFinished())
		if (Game::GetSummary() != nullptr)
			DrawSummary();

	DrawBar();
}

void Graphics::DrawIntro() {

	D2D1_RECT_F rect = D2D1::RectF(0, Globals::INTRO_BAR_Y, Globals::MAX_X, Globals::INTRO_BAR_BOTTOM);
	brush->SetColor(Game::GetIntro()->backgroundColor);
	renderTarget->FillRectangle(rect, brush);

	brush->SetColor(Game::GetIntro()->textColor);
	DrawTitle(Game::GetLocation(), L"Courier New", Globals::INTRO_HEIGHT, Point(Globals::CENTER_X, Globals::INTRO_Y), true);
}

void Graphics::DrawSummary() {

	D2D1_ROUNDED_RECT roundedRect = D2D1::RoundedRect(D2D1::RectF(Globals::SUMMARY_DIALOG_LEFT, Globals::SUMMARY_DIALOG_TOP,
		Globals::SUMMARY_DIALOG_RIGHT, Globals::SUMMARY_DIALOG_BOTTOM), 10.0f, 10.0f);
	brush->SetColor(Game::GetSummary()->backgroundColor);
	renderTarget->FillRoundedRectangle(roundedRect, brush);

	brush->SetColor(Game::GetSummary()->textColor);

	if (Game::IsWon()) {

		brush->SetColor(Globals::GREEN);
		DrawTitle(L"Mission completed", L"Courier New", Globals::SUMMARY_TITLE_HEIGHT, Point(Globals::CENTER_X, Globals::SUMMARY_TITLE_TOP), true);
		brush->SetColor(Globals::BRUSH_DEFAULT_COLOR);

		if (Game::GetScore() == Game::GetMaxScore())
			DrawSubtitles(L"Exceptional performance! You managed to destroy all the bombs without letting a single one put harm to the city. Great job!", L"Times New Roman",
				18.0f, Globals::SUMMARY_TEXT_WIDTH, Globals::SUMMARY_TEXT_HEIGHT, Point(Globals::CENTER_X, Globals::SUMMARY_TEXT_TOP), false);

		else DrawSubtitles(L"We won the battle! You managed to protect the city with little harm to the infrastructure and its inhabitants. Good job!", L"Times New Roman",
			18.0f, Globals::SUMMARY_TEXT_WIDTH, Globals::SUMMARY_TEXT_HEIGHT, Point(Globals::CENTER_X, Globals::SUMMARY_TEXT_TOP), false);
	}

	else {

		brush->SetColor(Globals::RED);
		DrawTitle(L"Mission failed", L"Courier New", Globals::SUMMARY_TITLE_HEIGHT, Point(Globals::CENTER_X, Globals::SUMMARY_TITLE_TOP), true);
		brush->SetColor(Globals::BRUSH_DEFAULT_COLOR);

		if (Game::GetScore() > 0)
			DrawSubtitles(L"The battle has been lost! You dealt some damage to the enemy forces, but the cost was far too great. In the end we were not able to defeat the enemy.",
				L"Times New Roman", 18.0f, Globals::SUMMARY_TEXT_WIDTH, Globals::SUMMARY_TEXT_HEIGHT, Point(Globals::CENTER_X, Globals::SUMMARY_TEXT_TOP), false);

		else DrawSubtitles(L"What a disaster! Our defenses got completely compromised and loses in civilians are uncountable. That was a shameful display!",
			L"Times New Roman", 18.0f, Globals::SUMMARY_TEXT_WIDTH, Globals::SUMMARY_TEXT_HEIGHT, Point(Globals::CENTER_X, Globals::SUMMARY_TEXT_TOP), false);
	}

	roundedRect = D2D1::RoundedRect(D2D1::RectF(Globals::SUMMARY_SEPARATOR_LEFT, Globals::SUMMARY_SEPARATOR_TOP,
		Globals::SUMMARY_SEPARATOR_RIGHT, Globals::SUMMARY_SEPARATOR_BOTTOM), 4.0f, 4.0f);
	renderTarget->FillRoundedRectangle(roundedRect, brush);

	DrawTitle(L"Score: ", L"Courier New", Globals::SUMMARY_SCORE_HEIGHT, Globals::SUMMARY_SCORE_LEFT, Globals::SUMMARY_SCORE_TOP, true);
	DrawInt(Game::GetScore(), L"Courier New", Globals::SUMMARY_SCORE_NUM_HEIGHT, Globals::SUMMARY_SCORE_NUM_LEFT, Globals::SUMMARY_SCORE_NUM_TOP, true);

	DrawTitle(L"Highscore: ", L"Courier New", Globals::SUMMARY_HIGHSCORE_HEIGHT, Globals::SUMMARY_HIGHSCORE_LEFT, Globals::SUMMARY_HIGHSCORE_TOP, true);
	DrawInt(Game::GetScore(), L"Courier New", Globals::SUMMARY_HIGHSCORE_NUM_HEIGHT, Globals::SUMMARY_HIGHSCORE_NUM_LEFT, Globals::SUMMARY_HIGHSCORE_NUM_TOP, true);

	D2D1_RECT_F rect;
	int i = 0;

	for (SummaryButton& button : Game::GetSummary()->GetButtons()) {

		rect = D2D1::RectF(button.GetTopLeft().x, button.GetTopLeft().y, button.GetBottomRight().x, button.GetBottomRight().y);
		roundedRect = D2D1::RoundedRect(rect, 10.0f, 10.0f);

		if (button.IsHovered()) {

			renderTarget->FillRoundedRectangle(roundedRect, brush);
			brush->SetColor(D2D1::ColorF(0.0f, 0.0f, 0.0f, 1.0f));
			renderTarget->DrawRoundedRectangle(roundedRect, brush);
		}

		else {

			D2D1_COLOR_F color = Globals::BRUSH_DEFAULT_COLOR;
			color.a = 0.8f;
			brush->SetColor(color);
			renderTarget->FillRoundedRectangle(roundedRect, brush);
			brush->SetColor(D2D1::ColorF(0.0f, 0.0f, 0.0f, 1.0f));
			renderTarget->DrawRoundedRectangle(roundedRect, brush);
			brush->SetColor(Globals::BRUSH_DEFAULT_COLOR);
		}

		rect.left += button.GetSpace();
		rect.top += button.GetSpace();
		rect.right -= button.GetSpace();
		rect.bottom -= button.GetSpace();

		if (button.IsHovered()) {

			if (i == 0)
				renderTarget->DrawBitmap(BitmapManager::GetHomeBitmap(), rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);

			else if (i == 1)
				renderTarget->DrawBitmap(BitmapManager::GetReplayBitmap(), rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);

			else renderTarget->DrawBitmap(BitmapManager::GetNextBitmap(), rect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
		}

		else {

			if (i == 0)
				renderTarget->DrawBitmap(BitmapManager::GetHomeBitmap(), rect, 0.8f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);

			else if (i == 1)
				renderTarget->DrawBitmap(BitmapManager::GetReplayBitmap(), rect, 0.8f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);

			else renderTarget->DrawBitmap(BitmapManager::GetNextBitmap(), rect, 0.8f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
		}

		i++;
	}
}

void Graphics::DrawBar() {

	D2D1_RECT_F rect = D2D1::RectF(0, Globals::BAR_Y, Globals::MAX_X, Globals::MAX_Y);
	D2D1_POINT_2F point1;
	D2D1_POINT_2F point2;
	point1.x = rect.left;
	point1.y = rect.top;
	point2.x = rect.right;
	point2.y = rect.top;
	brush->SetColor(Globals::POPUP_BACKGROUND_COLOR);;
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
	DrawTitle(text, font, height, topCenter, bold);
}

void Graphics::DrawInt(int num, const wchar_t* font, float height, float left, float top, bool bold) {

	std::wstringstream wss;
	wss << num;
	std::wstring ws = wss.str();
	const wchar_t* text = ws.c_str();
	DrawTitle(text, font, height, left, top, bold);
}

void Graphics::DrawTitle(const wchar_t* text, const wchar_t* font, float height, Point topCenter, bool bold) {

	IDWriteTextLayout* textLayout = textRenderer->GetAdjustedTextLayout(text, font, bold, height);
	DWRITE_TEXT_METRICS textMetrics;
	textLayout->GetMetrics(&textMetrics);
	float width = textMetrics.width;
	renderTarget->DrawTextLayout(D2D1::Point2F(topCenter.x - (width / 2), topCenter.y), textLayout, brush);
}

void Graphics::DrawTitle(const wchar_t* text, const wchar_t* font, float height, float left, float top, bool bold) {

	IDWriteTextLayout* textLayout = textRenderer->GetAdjustedTextLayout(text, font, bold, height);
	renderTarget->DrawTextLayout(D2D1::Point2F(left, top), textLayout, brush);
}

void Graphics::DrawSubtitles(const wchar_t* text, const wchar_t* font, float fontSize, float width, float height, Point topCenter, bool bold) {

	IDWriteTextLayout* textLayout = textRenderer->GetTextLayout(text, font, fontSize, bold, width, height);
	DWRITE_TEXT_METRICS textMetrics;
	textLayout->GetMetrics(&textMetrics);
	float textWidth = textMetrics.width;
	renderTarget->DrawTextLayout(D2D1::Point2F(topCenter.x - (textWidth / 2), topCenter.y), textLayout, brush);
}
