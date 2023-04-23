#include "StartWindow.h"
#include <iostream>

StartWindow::StartWindow() {

	hWnd = NULL;
	factory = NULL;
	renderTarget = NULL;
	startButtonBitmap = NULL;
}

StartWindow::StartWindow(HWND* hWnd) {

	this->hWnd = hWnd;
	factory = NULL;
	renderTarget = NULL;
	startButtonBitmap = NULL;
}

StartWindow::~StartWindow() {
	if (factory)
		factory->Release();

	if (renderTarget)
		renderTarget->Release();
}

bool StartWindow::Init() {

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

		mapBitmap = bitmapper->GetBitmap(L"start_win1.png", renderTarget);
		startButtonBitmap = bitmapper->GetBitmap(L"image2.png", renderTarget);

		return true;
	}

	return false;
}

void StartWindow::ClearScreen(Color color) {

	renderTarget->Clear(D2D1::ColorF(color.red, color.green, color.blue, color.alpha));
}

void StartWindow::DrawGame(Game game) {

	ClearScreen(Color(1.0f, 1.0f, 1.0f, 1.0f));

	D2D1_RECT_F rect;

	rect = D2D1::RectF(0, 0, Game::MAX_X, Game::MAX_Y);
	renderTarget->DrawBitmap(mapBitmap, rect, 0.85f,
		D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);

	StartButton startButton = ItemManager::GetStartButton();

	rect = D2D1::RectF(startButton.GetCenter().x - Game::START_BUTTON_HALF_WIDTH,
		startButton.GetCenter().y - Game::START_BUTTON_HALF_HEIGHT,
		startButton.GetCenter().x + Game::START_BUTTON_HALF_WIDTH,
		startButton.GetCenter().y + Game::START_BUTTON_HALF_HEIGHT);
	renderTarget->DrawBitmap(startButtonBitmap, rect, 1.0f,
		D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
}




