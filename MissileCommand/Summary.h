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

/// <summary>
/// Class responsible for handling everything present in the summary at the end of every game and during pause 
/// (points, stars, buttons, going back to menu, replaying the level or playing the next one)
/// </summary>
class Summary {

	static bool finished;
	static bool deletable;
	bool won;
	int score;
	int highscore;
	int maxScore;
	int scoreStarsNum;
	int scoreHollowStarsNum;
	int highscoreStarsNum;
	int highscoreHollowStarsNum;
	Point pressPos;
	Point cursorPos;
	Timer animationTimer;
	std::list<SummaryButton> buttons;

	// Applies changes that take place after user clicked on any menu button
	void ApplyChoice();
	// Applies animation to the button that user hovered on
	void ApplyAnimation();
	// Creates animation thread that handles animation of a specific button hovered on by the user 
	void CreateAnimationThread(SummaryButton& button);
	// Animates a specific button hovered on by the user 
	void AnimateButton(SummaryButton& button);
	// Task performed after user clicks on the HOME summary button; application goes back to the game menu 
	static void GoToMenu();
	// Task performed after user clicks on the REPLAY summary button; starts a new game on the same level as a previous one
	static void Replay();
	// Task performed after user clicks on the NEXT summary button; starts a new game on the next level relative to the previous one
	static void PlayNext();
	// Freezes the thread, awaiting the moment the game can be played again
	static void WaitForReady();

public:

	D2D1_COLOR_F backgroundColor;
	D2D1_COLOR_F textColor;

	Summary(bool won, int score, int maxScore);

	// Returns the boolean telling if user is finished with the summary, i.e. if user clicked on any button present on the summary popup
	bool IsFinished();
	// Returns the boolean telling if all detached threads have completed their work and the object is ready to be deleted
	bool IsDeletable();
	// Returns the boolean telling if user won recently played level
	bool IsWon();
	// Returns the integer representing the amount of points user accumulated after playing the recent level
	int GetScore();
	// Returns the integer representing the maximum amount of points user managed to ever accumulate playing the recent level
	int GetHighscore();
	// Returns the integer representing the maximum amount of points possible to accumulate playing the recent level
	int GetMaxScore(); 
	// Returns the integer representing the number of stars rewarded to the player for the recently played level
	int GetScoreStarsNum();
	// Returns the integer representing the number of stars player failed to obtain for playing the recent level
	int GetScoreHollowStarsNum();
	// Returns the integer representing the number of stars ever rewarded to the player for the recently played level
	int GetHighscoreStarsNum();
	// Returns the integer representing the smallest number of stars player ever failed to obtain playing the recent level
	int GetHighscoreHollowStarsNum();
	// Returns the list containing instances of SummaryButton class
	std::list<SummaryButton>& GetButtons();

	// Handles mouse presses in the summary popup
	void HandlePress(HWND& hWnd);
	// Handles mouse movement in the summary popup
	void HandleMove(HWND& hWnd);
};

