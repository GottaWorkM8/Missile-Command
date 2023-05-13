#include "Menu.h"

const float Menu::MAX_X = Game::MAX_X;
const float Menu::CENTER_X = Game::CENTER_X;
const float Menu::MAX_Y = Game::MAX_Y;

const float Menu::TITLE_WIDTH = MAX_X / 2.5f;
const float Menu::TITLE_HEIGHT = MAX_Y / 7;
const Point Menu::TITLE_TOP_LEFT = Point(CENTER_X - TITLE_WIDTH / 2, MAX_Y / 6);

const float Menu::BUTTON_X = MAX_X / 12;
const float Menu::FIRST_BUTTON_Y = MAX_Y / 2.5f;
const float Menu::BUTTON_HEIGHT = MAX_Y / 25;
const float Menu::BUTTON_SPACE = MAX_Y / BUTTON_HEIGHT + MAX_Y / 25;

const Point Menu::CONTINUE_TOP_LEFT = Point(BUTTON_X, FIRST_BUTTON_Y);;
const Point Menu::NEW_TOP_LEFT = Point(BUTTON_X, FIRST_BUTTON_Y + BUTTON_SPACE);;
const Point Menu::OPTIONS_TOP_LEFT = Point(BUTTON_X, FIRST_BUTTON_Y + 2 * BUTTON_SPACE);;
const Point Menu::HELP_TOP_LEFT = Point(BUTTON_X, FIRST_BUTTON_Y + 3 * BUTTON_SPACE);;
const Point Menu::EXIT_TOP_LEFT = Point(BUTTON_X, FIRST_BUTTON_Y + 4 * BUTTON_SPACE);;

const float Menu::ANIMATION_TIME = 0.3f;
const int Menu::ANIMATION_STAGES = 20;
const float Menu::ANIMATION_STAGE_TIME = ANIMATION_TIME / ANIMATION_STAGES;
const float Menu::ANIMATION_SHIFT_X = 1;
Timer Menu::animationTimer = Timer();

bool Menu::gameRunning = false;

std::list<MenuButton> Menu::buttons = {
	MenuButton(L"CONTINUE", CONTINUE_TOP_LEFT, BUTTON_HEIGHT, &ContinueGame),
	MenuButton(L"NEW GAME", NEW_TOP_LEFT, BUTTON_HEIGHT, &StartNewGame),
	MenuButton(L"OPTIONS", OPTIONS_TOP_LEFT, BUTTON_HEIGHT, &ShowOptions),
	MenuButton(L"HELP", HELP_TOP_LEFT, BUTTON_HEIGHT, &ShowHelp),
	MenuButton(L"EXIT", EXIT_TOP_LEFT, BUTTON_HEIGHT, &Exit) };
Point Menu::pressPos = Point();
Point Menu::cursorPos = Point();

std::list<MenuButton>& Menu::GetButtons() {
	return buttons;
}

void Menu::ApplyChoice() {

	for (MenuButton& button : buttons)
		if (Verifier::WithinAlt(pressPos, button.GetTopLeft(), button.GetWidth(), button.GetHeight())) {

			button.PerformTask();
			break;
		}
}

void Menu::ApplyAnimation() {

	for (MenuButton& button : buttons) {

		if (Verifier::WithinAlt(cursorPos, button.GetTopLeft(), button.GetWidth(), button.GetHeight())) {

			SetCursor(LoadCursor(NULL, IDC_HAND));

			if (!button.IsHovered()) {

				button.SetHovered(true);
				CreateAnimationThread(button.GetTopLeft(), button.IsHovered());
			}
		}

		else button.SetHovered(false);
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

	std::thread thread = std::thread(AnimateButton, std::ref(topLeft), std::ref(hovered));
	thread.detach();
}

void Menu::AnimateButton(Point& topLeft, bool& hovered) {

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

	topLeft.x = BUTTON_X;
}

void Menu::ContinueGame() {

}

void Menu::StartNewGame() {

	std::thread gameThread = std::thread(Game::Run);
	gameThread.detach();
	gameRunning = true;
}

void Menu::ShowOptions() {

}

void Menu::ShowHelp() {

}

void Menu::Exit() {

	PostQuitMessage(0);
}
