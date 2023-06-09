#include "Menu.h"

Timer Menu::animationTimer = Timer();

bool Menu::gameRunning = false;

std::list<MenuButton> Menu::buttons = {
	MenuButton(L"CONTINUE", Globals::CONTINUE_TOP_LEFT, Globals::BUTTON_HEIGHT, &ContinueGame),
	MenuButton(L"NEW GAME", Globals::NEW_TOP_LEFT, Globals::BUTTON_HEIGHT, &StartNewGame),
	MenuButton(L"OPTIONS", Globals::OPTIONS_TOP_LEFT, Globals::BUTTON_HEIGHT, &ShowOptions),
	MenuButton(L"HELP", Globals::HELP_TOP_LEFT, Globals::BUTTON_HEIGHT, &ShowHelp),
	MenuButton(L"EXIT", Globals::EXIT_TOP_LEFT, Globals::BUTTON_HEIGHT, &Exit) };
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

			SetCursor(LoadCursorFromFile(L"radioactive-select.ani"));

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

		if (stage < Globals::ANIMATION_STAGES) {
		
			float elapsedTime = animationTimer.GetElapsedTime();

			if (elapsedTime > Globals::ANIMATION_STAGE_TIME) {

				topLeft.x = topLeft.x + Globals::ANIMATION_SHIFT_X;
				stage++;
				animationTimer.Restart();
			}
		}

		Sleep(1);
	}

	topLeft.x = Globals::BUTTON_X;
}

void Menu::ContinueGame() {

	int diff = Globals::LEVEL5;
	BitmapManager::InitLevel(diff);
	std::thread gameThread = std::thread(Game::Run, diff);
	gameThread.detach();
	gameRunning = true;
	Music::ClearSounds();
	Music::PlayLevel();
}

void Menu::StartNewGame() {

	int diff = Globals::LEVEL3;
	BitmapManager::InitLevel(diff);
	std::thread gameThread = std::thread(Game::Run, diff);
	gameThread.detach();
	gameRunning = true;
	Music::ClearSounds();
	Music::PlayLevel();
}

void Menu::ShowOptions() {

}

void Menu::ShowHelp() {

}

void Menu::Exit() {

	PostQuitMessage(0);
}
