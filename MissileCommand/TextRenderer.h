#pragma once

#include <d2d1.h>
#include <dwrite.h>
#include <cfloat>
#include <xutility>

/// <summary>description</summary>
class TextRenderer {

	ID2D1HwndRenderTarget* renderTarget;
	IDWriteFactory* writeFactory;

public:

	TextRenderer(ID2D1HwndRenderTarget* renderTarget);
	~TextRenderer();

	bool Init();
	IDWriteTextLayout* GetTextLayout(const wchar_t* text, float width, float height);
	IDWriteTextLayout* GetTextLayout(const wchar_t* text, const wchar_t* font, float fontSize, 
		bool bold, float width, float height);
	IDWriteTextLayout* GetAdjustedTextLayout(const wchar_t* text, float height);
	IDWriteTextLayout* GetAdjustedTextLayout(const wchar_t* text, const wchar_t* font, 
		bool bold, float height);
};
