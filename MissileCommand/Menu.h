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

/// <summary>
/// Class responsible for handling everything present in the game menu (buttons, button animations, starting the game, exiting the app)
/// </summary>
class Menu {

	static bool gameRunning;
	static bool helpDisplayed;
	static Point pressPos;
	static Point cursorPos;
	static Timer animationTimer;
	static std::list<MenuButton> buttons;

	// Applies changes that take place after user clicked on any menu button
	static void ApplyChoice();
	// Applies animation to the button that user hovered on
	static void ApplyAnimation();
	// Creates animation thread that handles animation of a specific button hovered on by the user 
	static void CreateAnimationThread(Point& topLeft, bool& hovered);
	// Animates a specific button hovered on by the user 
	static void AnimateButton(Point& topLeft, bool& hovered);
	// Task performed after user clicks on the CONTINUE menu button; starts a new game at the highest level the user ever managed to reach
	static void ContinueGame();
	// Task performed after user clicks on the NEW GAME menu button; stars a new game from the very first level
	static void StartNewGame();
	// Task performed after user clicks on the HELP menu button; displays help popup with useful information regarding the game system
	static void ShowHelp();
	// Task performed after user clicks on the EXIT menu button; exits the application by posting a quit message later intercepted by the Window instance
	static void Exit();

public:

	// Returns the boolean telling if the game is running
	static bool IsGameRunning();
	// Sets the boolean telling if the game is running
	static void SetGameRunning(bool running);
	// Returns the boolean telling if the help is displayed in the menu
	static bool IsHelpDisplayed();
	// Sets the boolean telling if the help is displayed in the menu
	static void SetHelpDisplayed(bool displayed);
	// Returns the list containing instances of MenuButton class
	static std::list<MenuButton>& GetButtons();

	// Handles mouse presses in the game menu
	static void HandlePress(HWND& hWnd);
	// Handles mouse movement in the game menu
	static void HandleMove(HWND& hWnd);
	// Restarts the game on the level provided as an argument
	static void RestartGame(int currentDiff);
	// Starts a new game on the next level relative to the one provided as an argument
	static void StartNextGame(int currentDiff);
};

