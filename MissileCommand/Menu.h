#pragma once

#include <Windows.h>
#include <thread>
#include <functional>
#include "Point.h"
#include "Verifier.h"

class Menu {

public:

	static const float MAX_X;
	static const float CENTER_X;
	static const float MAX_Y;

	static const float OPTION_X;
	static const float FIRST_OPTION_Y;
	static const float OPTION_HEIGHT;
	static const float OPTION_SPACE;

	static const Point TITLE_TOP_LEFT;
	static const float TITLE_WIDTH;
	static const float TITLE_HEIGHT;

	static const Point NEW_TOP_LEFT;
	static Point newTopLeft;
	static float newWidth;
	static const float NEW_HEIGHT;
	static bool newHovered;

	static const Point EXIT_TOP_LEFT;
	static Point exitTopLeft;
	static float exitWidth;
	static const float EXIT_HEIGHT;
	static bool exitHovered;

	static const float ANIMATION_TIME;
	static const int ANIMATION_STAGES;
	static const float ANIMATION_STAGE_TIME;
	static const float ANIMATION_SHIFT_X;
	static Timer animationTimer;

	static Point pressPos;
	static Point cursorPos;
	static bool gameRunning;

	static void ApplyChoice();
	static void ApplyAnimation();
	static void HandlePress(HWND& hWnd);
	static void HandleMove(HWND& hWnd);
	static void CreateAnimationThread(Point& topLeft, bool& hovered);
	static void AnimateOption(Point& topLeft, bool& hovered);
	static void ContinueGame();
	static void StartNewGame();
	static void ShowHelp();
	static void Exit();
};

