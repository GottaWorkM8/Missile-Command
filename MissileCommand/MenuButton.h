#pragma once

#include <dwrite.h>
#include "Button.h"

class MenuButton : public Button {

	IDWriteTextLayout* textLayout;
	const wchar_t* text;

public:

	MenuButton();
	MenuButton(const wchar_t* text, Point topLeft, float height, void (*task)());

	IDWriteTextLayout* GetTextLayout();
	void SetTextLayout(IDWriteTextLayout* textLayout);
	const wchar_t* GetText();
	void SetWidth(float width);
};

