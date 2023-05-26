#pragma once

#include <Windows.h>
#include <d2d1.h>
#include <wincodec.h>
#include <dwrite.h>
#include <sstream>
#include <string>
#include <thread>
#include "Globals.h"
#include "Bitmapper.h"
#include "TextRenderer.h"
#include "ItemManager.h"
#include "Menu.h"
#include "Popup.h"

class Graphics {

	HWND* hWnd;
	ID2D1Factory* factory;
	ID2D1HwndRenderTarget* renderTarget;
	TextRenderer* textRenderer;
	ID2D1SolidColorBrush* brush;
	ID2D1Bitmap* menuBitmap;
	ID2D1Bitmap* titleBitmap;
	ID2D1Bitmap* mapBitmap1;
	ID2D1Bitmap* mapBitmap2;
	ID2D1Bitmap* mapBitmap3;
	ID2D1Bitmap* mapBitmap4;
	ID2D1Bitmap* mapBitmap5;
	ID2D1Bitmap* launcherBitmap;
	ID2D1Bitmap* cannonBitmap;
	ID2D1Bitmap* flashBitmap;
	ID2D1Bitmap* buildingBitmap;
	ID2D1Bitmap* missileBitmap;
	ID2D1Bitmap* normalBombBitmap;
	ID2D1Bitmap* nuclearBombBitmap;
	ID2D1Bitmap* clusterBombBitmap;
	ID2D1Bitmap* napalmBombBitmap;
	ID2D1Bitmap* rodBombBitmap;
	ID2D1Bitmap* missileExplosionBitmap;
	ID2D1Bitmap* normalExplosionBitmap;
	ID2D1Bitmap* nuclearExplosionBitmap;
	ID2D1Bitmap* clusterExplosionBitmap;
	ID2D1Bitmap* napalmExplosionBitmap;
	ID2D1Bitmap* rodExplosionBitmap;
	ID2D1Bitmap* destructionBitmap;
	ID2D1Bitmap* ammoBitmap;

public:

	Graphics();
	Graphics(HWND* hWnd);
	~Graphics();

	bool Init();
	void BeginDraw();
	void EndDraw();
	void ClearScreen();
	void DrawMenu();
	void DrawGame();
	void DrawIntro();
	void DrawBar();
	void DrawInt(int num, const wchar_t* font, float height, Point topCenter, bool bold);
	void DrawLabel(const wchar_t* text, const wchar_t* font, float height, Point topCenter, bool bold);
};

