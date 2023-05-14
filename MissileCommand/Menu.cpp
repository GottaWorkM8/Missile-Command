#include "Menu.h"

const float Menu::MAX_X = Game::MAX_X;
const float Menu::CENTER_X = Game::CENTER_X;
const float Menu::MAX_Y = Game::MAX_Y;

const float Menu::OPTION_X = MAX_X / 12;
const float Menu::FIRST_OPTION_Y = MAX_Y / 2.5f;
const float Menu::OPTION_HEIGHT = MAX_Y / 25;
const float Menu::OPTION_SPACE = MAX_Y / OPTION_HEIGHT + MAX_Y / 25;

const float Menu::TITLE_WIDTH = MAX_X / 2.5f;
const float Menu::TITLE_HEIGHT = MAX_Y / 7;
const Point Menu::TITLE_TOP_LEFT = Point(CENTER_X - TITLE_WIDTH / 2, MAX_Y / 6);

const Point Menu::NEW_TOP_LEFT = Point(OPTION_X, FIRST_OPTION_Y);;
Point Menu::newTopLeft = NEW_TOP_LEFT;
float Menu::newWidth = 0;
const float Menu::NEW_HEIGHT = OPTION_HEIGHT;
bool Menu::newHovered = false;

const Point Menu::EXIT_TOP_LEFT = Point(OPTION_X, FIRST_OPTION_Y + OPTION_SPACE);
Point Menu::exitTopLeft = EXIT_TOP_LEFT;
float Menu::exitWidth = 0;
const float Menu::EXIT_HEIGHT = OPTION_HEIGHT;
bool Menu::exitHovered = false;

const float Menu::ANIMATION_TIME = 0.3f;
const int Menu::ANIMATION_STAGES = 20;
const float Menu::ANIMATION_STAGE_TIME = ANIMATION_TIME / ANIMATION_STAGES;
const float Menu::ANIMATION_SHIFT_X = 1;
Timer Menu::animationTimer = Timer();

Point Menu::pressPos = Point();
Point Menu::cursorPos = Point();
bool Menu::gameRunning = false;

void Menu::ApplyChoice() {

	if (Verifier::WithinAlt(pressPos, NEW_TOP_LEFT, newWidth, NEW_HEIGHT))
		StartNewGame();

	else if (Verifier::WithinAlt(pressPos, EXIT_TOP_LEFT, exitWidth, EXIT_HEIGHT))
		Exit();
}

void Menu::ApplyAnimation() {

	if (Verifier::WithinAlt(cursorPos, NEW_TOP_LEFT, newWidth, NEW_HEIGHT)) {
		
		exitHovered = false;

		if (!newHovered) {

			newHovered = true;
			CreateAnimationThread(newTopLeft, newHovered);
		}
	}

	else if (Verifier::WithinAlt(cursorPos, EXIT_TOP_LEFT, exitWidth, EXIT_HEIGHT)) {
		
		newHovered = false;

		if (!exitHovered) {

			exitHovered = true;
			CreateAnimationThread(exitTopLeft, exitHovered);
		}
	}

	else {

		newHovered = false;
		exitHovered = false;
	}
}

void Menu::HandlePress(HWND& hWnd) {

	POINT target;
	GetCursorPos(&target);
	ScreenToClient(hWnd, &target);
	pressPos.x = target.x;
	pressPos.y = target.y;
	ApplyChoice();
}

void Menu::HandleMove(HWND& hWnd) {

	POINT target;
	GetCursorPos(&target);
	ScreenToClient(hWnd, &target);
	cursorPos.x = target.x;
	cursorPos.y = target.y;
	ApplyAnimation();
}

void Menu::CreateAnimationThread(Point& topLeft, bool& hovered) {

	std::thread thread = std::thread(AnimateOption, std::ref(topLeft), std::ref(hovered));
	thread.detach();
}

void Menu::AnimateOption(Point& topLeft, bool& hovered) {

	int stage = 0;
	animationTimer.Restart();

	while (hovered) {

		if (stage < 10) {
		
			float elapsedTime = animationTimer.GetElapsedTime();

			if (elapsedTime > ANIMATION_STAGE_TIME) {

				topLeft.x = topLeft.x + ANIMATION_SHIFT_X;
				stage++;
				animationTimer.Restart();
			}
		}

		Sleep(1);
	}

	topLeft.x = OPTION_X;
}

void Menu::ContinueGame() {

}

void Menu::StartNewGame() {

	std::thread gameThread = std::thread(Game::Run);
	gameThread.detach();
	gameRunning = true;
	Music::musicClear();
	Music::musicLevel();
}

void Menu::ShowHelp() {

}

void Menu::Exit() {

	PostQuitMessage(0);
}
