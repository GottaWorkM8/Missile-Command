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
#include "BitmapManager.h"
#include "ItemManager.h"
#include "Menu.h"

class Graphics {

	HWND* hWnd;
	ID2D1Factory* factory;
	ID2D1HwndRenderTarget* renderTarget;
	Bitmapper* bitmapper;
	TextRenderer* textRenderer;
	ID2D1SolidColorBrush* brush;

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
	void DrawSummary();
	void DrawBar();
	void DrawInt(int num, const wchar_t* font, float height, Point topCenter, bool bold);
	void DrawInt(int num, const wchar_t* font, float height, float left, float top, bool bold);
	void DrawTitle(const wchar_t* text, const wchar_t* font, float height, Point topCenter, bool bold);
	void DrawTitle(const wchar_t* text, const wchar_t* font, float height, float left, float top, bool bold);
	void DrawSubtitles(const wchar_t* text, const wchar_t* font, float fontSize, float width, float height, Point topCenter, bool bold);
};

