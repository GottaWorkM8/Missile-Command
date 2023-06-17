#pragma once

#include <d2d1.h>
#include <wincodec.h>

/// <summary>
/// Class responsible for creating bitmaps from .png and .jpg files
/// </summary>
class Bitmapper {

	ID2D1HwndRenderTarget* renderTarget;
	IWICImagingFactory* factory;

public:

	Bitmapper(ID2D1HwndRenderTarget* renderTarget);
	~Bitmapper();

	// Initializes Bitmapper instance with default settings
	bool Init();
	// Returns bitmap created from the given as an argument image file
	ID2D1Bitmap* GetBitmap(const wchar_t* filename);
};



