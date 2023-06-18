#pragma once

#include <d2d1.h>
#include <dwrite.h>
#include <cfloat>
#include <xutility>

/// <summary>
/// Class responsible for creating text layouts drawn later by the Graphics class
/// </summary>
class TextRenderer {

	ID2D1HwndRenderTarget* renderTarget;
	IDWriteFactory* writeFactory;

public:

	TextRenderer(ID2D1HwndRenderTarget* renderTarget);
	~TextRenderer();

	// Initializes the TextRenderer instance with default settings
	bool Init();
	// Returns text layout created with the given settings
	IDWriteTextLayout* GetTextLayout(const wchar_t* text, float width, float height);
	// Returns text layout created with the given settings
	IDWriteTextLayout* GetTextLayout(const wchar_t* text, const wchar_t* font, float fontSize, 
		bool bold, float width, float height);
	// Returns text layout created with the given settings, where width is set based on the height and the default font
	IDWriteTextLayout* GetAdjustedTextLayout(const wchar_t* text, float height);
	// Returns text layout created with the given settings, where width is set based on the height and the given font
	IDWriteTextLayout* GetAdjustedTextLayout(const wchar_t* text, const wchar_t* font, 
		bool bold, float height);
};
