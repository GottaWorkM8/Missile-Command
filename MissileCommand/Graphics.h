#pragma once

#include <Windows.h>
#include <d2d1.h>
#include <wincodec.h>
#include <dwrite.h>
#include "Color.h"
#include "Bitmapper.h"
#include "TextRenderer.h"
#include "Game.h"
#include "Menu.h"

class Graphics {

	HWND* hWnd;
	ID2D1Factory* factory;
	ID2D1HwndRenderTarget* renderTarget;
	ID2D1SolidColorBrush* brush;
	ID2D1Bitmap* menuBitmap;
	ID2D1Bitmap* titleBitmap;
	ID2D1Bitmap* mapBitmap;
	ID2D1Bitmap* cannonBitmap;
	ID2D1Bitmap* launcherBitmap;
	ID2D1Bitmap* buildingBitmap;
	ID2D1Bitmap* missileBitmap;
	ID2D1Bitmap* bombBitmap;
	ID2D1Bitmap* missileExplosionBitmap;
	ID2D1Bitmap* bombExplosionBitmap;
	ID2D1Bitmap* flashBitmap;

public:

	Graphics();
	Graphics(HWND* hWnd);
	~Graphics();

	bool Init();
	void BeginDraw();
	void EndDraw();
	void ClearScreen(Color color);
	void DrawMenu();
	void DrawGame();
};

