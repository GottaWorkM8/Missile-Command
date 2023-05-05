#include "TextRenderer.h"

TextRenderer::TextRenderer(ID2D1HwndRenderTarget* renderTarget) {

	this->renderTarget = renderTarget;
	writeFactory = NULL;
}

TextRenderer::~TextRenderer() {

	if (writeFactory)
		writeFactory->Release();
}

bool TextRenderer::Init() {

	HRESULT hR = DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory),
		reinterpret_cast<IUnknown**>(&writeFactory));

	if (!SUCCEEDED(hR))
		return false;

	else return true;
}

IDWriteTextLayout* TextRenderer::GetTextLayout(const wchar_t* text, float width, float height) {

	return GetTextLayout(text, L"Arial", 18.0f, false, width, height);
}

IDWriteTextLayout* TextRenderer::GetTextLayout(const wchar_t* text, const wchar_t* font, 
	float fontSize, bool bold, float width, float height) {

	IDWriteTextFormat* textFormat;
	DWRITE_FONT_WEIGHT weight;
	
	if (bold)
		weight = DWRITE_FONT_WEIGHT_BOLD;

	else weight = DWRITE_FONT_WEIGHT_NORMAL;
	
	HRESULT hR = writeFactory->CreateTextFormat(font, NULL, weight,
		DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, fontSize, L"", &textFormat);

	if (!SUCCEEDED(hR))
		return NULL;

	IDWriteTextLayout* textLayout;
	hR = writeFactory->CreateTextLayout(text, wcslen(text), textFormat,
		width, height, &textLayout);

	if (!SUCCEEDED(hR))
		return NULL;

	return textLayout;
}

IDWriteTextLayout* TextRenderer::GetAdjustedTextLayout(const wchar_t* text, float height) {

	return GetAdjustedTextLayout(text, L"Arial", false, height);
}

IDWriteTextLayout* TextRenderer::GetAdjustedTextLayout(const wchar_t* text, const wchar_t* font, 
	bool bold, float height) {

	float bigFontSize = 1000.0f;

	IDWriteTextFormat* textFormat;
	DWRITE_FONT_WEIGHT weight;

	if (bold)
		weight = DWRITE_FONT_WEIGHT_BOLD;

	else weight = DWRITE_FONT_WEIGHT_NORMAL;

	HRESULT hR = writeFactory->CreateTextFormat(font, NULL, weight,
		DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, bigFontSize, L"", &textFormat);

	if (!SUCCEEDED(hR))
		return NULL;

	IDWriteTextLayout* textLayout;
	hR = writeFactory->CreateTextLayout(L"X", 1, textFormat,
		FLT_MAX, FLT_MAX, &textLayout);

	if (!SUCCEEDED(hR))
		return NULL;

	DWRITE_TEXT_METRICS metrics;
	hR = textLayout->GetMetrics(&metrics);

	if (!SUCCEEDED(hR))
		return NULL;

	float lineHeight = metrics.height;
	float fontSize = height / lineHeight * bigFontSize;

	hR = writeFactory->CreateTextFormat(L"Arial", NULL, weight,
		DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, fontSize, L"", &textFormat);

	if (!SUCCEEDED(hR))
		return NULL;

	hR = writeFactory->CreateTextLayout(text, wcslen(text), textFormat,
		1000, height, &textLayout);

	if (!SUCCEEDED(hR))
		return NULL;

	hR = textLayout->GetMetrics(&metrics);

	if (!SUCCEEDED(hR))
		return NULL;

	float width = metrics.width;
	hR = writeFactory->CreateTextLayout(text, wcslen(text), textFormat,
		width, height, &textLayout);

	if (!SUCCEEDED(hR))
		return NULL;

	return textLayout;
}



