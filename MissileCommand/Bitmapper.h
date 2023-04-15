#pragma once

#include <wincodec.h>
#include "Graphics.h"

class Bitmapper {

	IWICImagingFactory* factory;

public:

	Bitmapper();
	~Bitmapper();

	bool Init();
	ID2D1Bitmap* GetBitmap(const wchar_t* filename, ID2D1HwndRenderTarget* renderTarget);
};



