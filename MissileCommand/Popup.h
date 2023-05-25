#pragma once

#include <d2d1.h>
#include <thread>
#include "Globals.h"
#include "Game.h"

class Popup {

	static Point pressPos;
	static Point cursorPos;
	static Timer animationTimer;

public:

	static D2D1_COLOR_F backgroundColor;
	static D2D1_COLOR_F textColor;

	static void CreateIntroThread();
	static void AnimateIntro();
};

