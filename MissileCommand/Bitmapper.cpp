#include "Bitmapper.h"

Bitmapper::Bitmapper() {

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

ID2D1Bitmap* Bitmapper::GetBitmap(const wchar_t* filename, ID2D1HwndRenderTarget* renderTarget) {
	
	/*IWICStream* stream = NULL;
	IWICBitmapScaler* scaler = NULL;*/

	IWICBitmapDecoder* decoder = NULL;
	HRESULT hR = factory->CreateDecoderFromFilename(filename, NULL, GENERIC_READ,
		WICDecodeMetadataCacheOnLoad, &decoder);

	if (!SUCCEEDED(hR))
		return NULL;

	IWICBitmapFrameDecode* frame = NULL;
	hR = decoder->GetFrame(0, &frame);

	if (!SUCCEEDED(hR))
		return NULL;

	IWICFormatConverter* converter = NULL;
	hR = factory->CreateFormatConverter(&converter);

	if (!SUCCEEDED(hR))
		return NULL;

	hR = converter->Initialize(frame, GUID_WICPixelFormat32bppPBGRA, WICBitmapDitherTypeNone, 
		NULL, 0.f, WICBitmapPaletteTypeMedianCut);

	if (!SUCCEEDED(hR))
		return NULL;

	ID2D1Bitmap* bitmap = NULL;
	hR = renderTarget->CreateBitmapFromWicBitmap(converter, NULL, &bitmap);
	
	/*decoder->Release();
	frame->Release();
	stream->Release();
	converter->Release();
	scaler->Release();*/

	return bitmap;
}

