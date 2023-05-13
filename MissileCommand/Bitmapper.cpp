#include "Bitmapper.h"

Bitmapper::Bitmapper(ID2D1HwndRenderTarget* renderTarget) {

	this->renderTarget = renderTarget;
	factory = NULL;
}

Bitmapper::~Bitmapper() {

	if (factory)
		factory->Release();
}

bool Bitmapper::Init() {

	HRESULT hR = CoInitializeEx(NULL, COINIT_MULTITHREADED);

	if (!SUCCEEDED(hR))
		return false;

	hR = CoCreateInstance(CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER,
		IID_IWICImagingFactory, (LPVOID*)&factory);

	if (!SUCCEEDED(hR))
		return false;

	return true;
}

ID2D1Bitmap* Bitmapper::GetBitmap(const wchar_t* filename) {

	IWICBitmapDecoder* decoder;
	HRESULT hR = factory->CreateDecoderFromFilename(filename, NULL, GENERIC_READ,
		WICDecodeMetadataCacheOnLoad, &decoder);

	if (!SUCCEEDED(hR))
		return NULL;

	IWICBitmapFrameDecode* frame;
	hR = decoder->GetFrame(0, &frame);

	if (!SUCCEEDED(hR))
		return NULL;

	IWICFormatConverter* converter;
	hR = factory->CreateFormatConverter(&converter);

	if (!SUCCEEDED(hR))
		return NULL;

	hR = converter->Initialize(frame, GUID_WICPixelFormat32bppPBGRA, WICBitmapDitherTypeNone, 
		NULL, 0.0f, WICBitmapPaletteTypeMedianCut);

	if (!SUCCEEDED(hR))
		return NULL;

	ID2D1Bitmap* bitmap;
	hR = renderTarget->CreateBitmapFromWicBitmap(converter, NULL, &bitmap);

	if (!SUCCEEDED(hR))
		return NULL;

	return bitmap;
}

