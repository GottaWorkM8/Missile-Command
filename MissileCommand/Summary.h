#pragma once

#include <d2d1.h>
#include <list>
#include <thread>
#include "Globals.h"
#include "Verifier.h"
#include "SummaryButton.h"
#include "Menu.h"
#include "Game.h"
#include "Music.h"

class Menu;
class Game;

/// <summary>description</summary>
class Summary {

	static bool finished;
	Point pressPos;
	Point cursorPos;
	Timer animationTimer;
	std::list<SummaryButton> buttons;

	void ApplyChoice();
	void ApplyAnimation();
	void CreateAnimationThread(SummaryButton& button);
	void AnimateButton(SummaryButton& button);
	static void GoToMenu();
	static void Replay();
	static void PlayNext();
	static void WaitForReady();

public:

	D2D1_COLOR_F backgroundColor;
	D2D1_COLOR_F textColor;

	Summary();

	bool IsFinished();
	std::list<SummaryButton>& GetButtons();

	void HandlePress(HWND& hWnd);
	void HandleMove(HWND& hWnd);
};

