#pragma once

#include <dwrite.h>
#include "Button.h"

/// <summary>
/// Class representing buttons present in the game menu
/// </summary>
class MenuButton : public Button {

	IDWriteTextLayout* textLayout;
	const wchar_t* text;

public:

	MenuButton();
	MenuButton(const wchar_t* text, Point topLeft, float height, void (*task)());

	// Returns text layout assigned to the button
	IDWriteTextLayout* GetTextLayout();
	// Assigns text layout to the button
	void SetTextLayout(IDWriteTextLayout* textLayout);
	// Returns text inside the button
	const wchar_t* GetText();
	// Sets width of the button
	void SetWidth(float width);
};

