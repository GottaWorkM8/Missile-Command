#pragma once

#include <wincodec.h>
#include "Graphics.h"

class Bitmapper {

	ID2D1HwndRenderTarget* renderTarget;
	IWICImagingFactory* factory;

public:

	Bitmapper(ID2D1HwndRenderTarget* renderTarget);
	~Bitmapper();

	bool Init();
	ID2D1Bitmap* GetBitmap(const wchar_t* filename);
};



