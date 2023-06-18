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

/// <summary>
/// Class responsible for drawing bitmaps, text layouts and simple shapes on the render target
/// </summary>
class Graphics {

	HWND* hWnd;
	ID2D1Factory* factory;
	ID2D1HwndRenderTarget* renderTarget;
	Bitmapper* bitmapper;
	TextRenderer* textRenderer;
	ID2D1SolidColorBrush* brush;

	// Draws game level introduction on the render target
	void DrawIntro();
	// Draws game level summary on the render target
	void DrawSummary();
	// Draws user UI bar at the bottom of the screen on the render target
	void DrawBar();
	// Creates text layout from integer and draws it on the render target
	void DrawInt(int num, const wchar_t* font, float height, Point topCenter, bool bold);
	// Creates text layout from integer and draws it on the render target
	void DrawInt(int num, const wchar_t* font, float height, float left, float top, bool bold);
	// Creates text layout from string of characters and draws it on the render target
	void DrawTitle(const wchar_t* text, const wchar_t* font, float height, Point topCenter, bool bold);
	// Creates text layout from string of characters and draws it on the render target
	void DrawTitle(const wchar_t* text, const wchar_t* font, float height, float left, float top, bool bold);
	// Creates text layout from string of characters and draws it on the render target
	void DrawSubtitles(const wchar_t* text, const wchar_t* font, float fontSize, float width, float height, Point topCenter, bool bold);

public:

	Graphics();
	Graphics(HWND* hWnd);
	~Graphics();

	// Initializes Graphics instance with default settings
	bool Init();
	// Method that needs to be invoked before any drawing on the render target takes place
	void BeginDraw();
	// Method that needs to be invoked after drawing on the render target and before invoking BeginDraw method again
	void EndDraw();
	// Clears the screen of any content previously drawn on the render target
	void ClearScreen();
	// Draws all objects present in the menu on the render target
	void DrawMenu();
	// Draws help bitmap on the render target
	void DrawHelp();
	// Draws all objects present in the game on the render target
	void DrawGame();
};

