#pragma once

#include <Windows.h>
#include <d2d1.h>
#include <wincodec.h>
#include "Color.h"
#include "Bitmapper.h"
#include "Game.h"

class Graphics {

	HWND* hWnd;
	ID2D1Factory* factory;
	ID2D1HwndRenderTarget* renderTarget;
	ID2D1Bitmap* groundBitmap;
	ID2D1Bitmap* launcherBitmap;
	ID2D1Bitmap* buildingBitmap;
	ID2D1Bitmap* missileBitmap;
	ID2D1Bitmap* bombBitmap;

public:

	Graphics();
	Graphics(HWND* hWnd);
	~Graphics();

	bool Init();
	void BeginDraw() { renderTarget->BeginDraw(); }
	void EndDraw() { renderTarget->EndDraw(); }
	void ClearScreen(Color color);
	void DrawGame(Game game);
};

