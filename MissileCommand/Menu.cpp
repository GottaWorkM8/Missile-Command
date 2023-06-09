#include "Menu.h"

bool Menu::gameRunning = false;
bool Menu::helpDisplayed = false;
Timer Menu::animationTimer = Timer();
Point Menu::pressPos = Point();
Point Menu::cursorPos = Point();
std::list<MenuButton> Menu::buttons = {
	MenuButton(L"CONTINUE", Globals::CONTINUE_TOP_LEFT, Globals::BUTTON_HEIGHT, &ContinueGame),
	MenuButton(L"NEW GAME", Globals::NEW_TOP_LEFT, Globals::BUTTON_HEIGHT, &StartNewGame),
	MenuButton(L"HELP", Globals::HELP_TOP_LEFT, Globals::BUTTON_HEIGHT, &ShowHelp),
	MenuButton(L"EXIT", Globals::EXIT_TOP_LEFT, Globals::BUTTON_HEIGHT, &Exit) };

bool Menu::IsGameRunning() {
	return gameRunning;
}

void Menu::SetGameRunning(bool running) {
	gameRunning = running;
}

bool Menu::IsHelpDisplayed() {
	return helpDisplayed;
}

void Menu::SetHelpDisplayed(bool displayed) {
	helpDisplayed = displayed;
}

std::list<MenuButton>& Menu::GetButtons() {
	return buttons;
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

void Menu::RestartGame(int currentDiff) {

	std::thread gameThread = std::thread(Game::Run, currentDiff);
	gameThread.detach();
	gameRunning = true;
	Music::ClearSounds();
	Music::PlayLevel();
}

void Menu::StartNextGame(int currentDiff) {

	int diff = currentDiff + 1;
	BitmapManager::InitLevel(diff);
	std::thread gameThread = std::thread(Game::Run, diff);
	gameThread.detach();
	gameRunning = true;
	Music::ClearSounds();
	Music::PlayLevel();
}

void Menu::ApplyChoice() {

	int i = 0;

	for (MenuButton& button : buttons) {

		if (i == 0 && GameSave::GetCurrentLevel() <= Globals::LEVEL1) {

			i++;
			continue;
		}

		if (Verifier::WithinAlt(pressPos, button.GetTopLeft(), button.GetWidth(), button.GetHeight())) {

			button.PerformTask();
			break;
		}

		i++;
	}
}

void Menu::ApplyAnimation() {

	int i = 0;

	for (MenuButton& button : buttons) {

		if (i == 0 && GameSave::GetCurrentLevel() <= Globals::LEVEL1) {

			i++;
			continue;
		}

		if (Verifier::WithinAlt(cursorPos, button.GetTopLeft(), button.GetWidth(), button.GetHeight())) {

			SetCursor(LoadCursorFromFile(L"radioactive-select.ani"));

			if (!button.IsHovered()) {

				button.SetHovered(true);
				CreateAnimationThread(button.GetTopLeft(), button.IsHovered());
			}
		}

		else button.SetHovered(false);

		i++;
	}
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

				topLeft.x += Globals::ANIMATION_SHIFT_X;
				stage++;
				animationTimer.Restart();
			}
		}

		Sleep(1);
	}

	topLeft.x = Globals::BUTTON_LEFT;
}

void Menu::ContinueGame() {

	int diff = GameSave::GetCurrentLevel();
	BitmapManager::InitLevel(diff);
	std::thread gameThread = std::thread(Game::Run, diff);
	gameThread.detach();
	gameRunning = true;
	Music::ClearSounds();
	Music::PlayLevel();
}

void Menu::StartNewGame() {

	int diff = Globals::LEVEL1;
	BitmapManager::InitLevel(diff);
	std::thread gameThread = std::thread(Game::Run, diff);
	gameThread.detach();
	gameRunning = true;
	Music::ClearSounds();
	Music::PlayLevel();
}

void Menu::ShowHelp() {

	helpDisplayed = true;
}

void Menu::Exit() {

	PostQuitMessage(0);
}
