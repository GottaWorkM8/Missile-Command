#pragma once

#include <Windows.h>
#include <thread>
#include <list>
#include <functional>
#include "Point.h"
#include "Verifier.h"
#include "MenuButton.h"

class Menu {

	static std::list<MenuButton> buttons;
	static Point pressPos;
	static Point cursorPos;

public:

	static const float MAX_X;
	static const float CENTER_X;
	static const float MAX_Y;

	static const Point TITLE_TOP_LEFT;
	static const float TITLE_WIDTH;
	static const float TITLE_HEIGHT;

	static const float BUTTON_X;
	static const float FIRST_BUTTON_Y;
	static const float BUTTON_HEIGHT;
	static const float BUTTON_SPACE;

	static const Point CONTINUE_TOP_LEFT;
	static const Point NEW_TOP_LEFT;
	static const Point OPTIONS_TOP_LEFT;
	static const Point HELP_TOP_LEFT;
	static const Point EXIT_TOP_LEFT;

	static const float ANIMATION_TIME;
	static const int ANIMATION_STAGES;
	static const float ANIMATION_STAGE_TIME;
	static const float ANIMATION_SHIFT_X;
	static Timer animationTimer;

	static bool gameRunning;

	static std::list<MenuButton>& GetButtons();

	static void ApplyChoice();
	static void ApplyAnimation();
	static void HandlePress(HWND& hWnd);
	static void HandleMove(HWND& hWnd);
	static void CreateAnimationThread(Point& topLeft, bool& hovered);
	static void AnimateButton(Point& topLeft, bool& hovered);
	static void ContinueGame();
	static void StartNewGame();
	static void ShowOptions();
	static void ShowHelp();
	static void Exit();
};

