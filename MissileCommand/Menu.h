#pragma once

#include <Windows.h>
#include <thread>
#include <list>
#include <functional>
#include "Globals.h"
#include "Verifier.h"
#include "Music.h"
#include "MenuButton.h"
#include "BitmapManager.h"
#include "Game.h"
#include "GameSave.h"

class Menu {

	static bool gameRunning;
	static Point pressPos;
	static Point cursorPos;
	static Timer animationTimer;
	static std::list<MenuButton> buttons;

	static void ApplyChoice();
	static void ApplyAnimation();
	static void CreateAnimationThread(Point& topLeft, bool& hovered);
	static void AnimateButton(Point& topLeft, bool& hovered);
	static void ContinueGame();
	static void StartNewGame();
	static void ShowOptions();
	static void ShowHelp();
	static void Exit();

public:

	static bool IsGameRunning();
	static void SetGameRunning(bool running);
	static std::list<MenuButton>& GetButtons();

	static void HandlePress(HWND& hWnd);
	static void HandleMove(HWND& hWnd);
	static void RestartGame(int currentDiff);
	static void StartNextGame(int currentDiff);
};

