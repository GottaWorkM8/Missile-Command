#include "Summary.h"

bool Summary::finished = false;

Summary::Summary(bool won, int score, int maxScore) {

	backgroundColor = Globals::POPUP_BACKGROUND_COLOR;
	textColor = Globals::BRUSH_DEFAULT_COLOR;
	finished = false;
	this->won = won;
	this->score = score;
	highscore = GameSave::GetHighscore(Game::GetDiff());
	this->maxScore = maxScore;

	if (score >= 0)
		scoreStarsNum = score / (maxScore / Globals::SUMMARY_STAR_NUM) + 1;

	else scoreStarsNum = 0;

	scoreHollowStarsNum = Globals::SUMMARY_STAR_NUM - scoreStarsNum;
	highscoreStarsNum = highscore / (maxScore / Globals::SUMMARY_STAR_NUM) + 1;
	highscoreHollowStarsNum = Globals::SUMMARY_STAR_NUM - highscoreStarsNum;
	pressPos = Point();
	cursorPos = Point();
	animationTimer = Timer();
	buttons = {
		SummaryButton(Point(Globals::SUMMARY_MENU_LEFT, Globals::SUMMARY_MENU_TOP), Globals::SUMMARY_BUTTON_WIDTH, &GoToMenu),
		SummaryButton(Point(Globals::SUMMARY_REPLAY_LEFT, Globals::SUMMARY_REPLAY_TOP), Globals::SUMMARY_BUTTON_WIDTH, &Replay),
		SummaryButton(Point(Globals::SUMMARY_NEXT_LEFT, Globals::SUMMARY_NEXT_TOP), Globals::SUMMARY_BUTTON_WIDTH, &PlayNext) };
}

bool Summary::IsFinished() {
	return finished;
}

bool Summary::IsWon() {
	return won;
}

int Summary::GetScore() {
	return score;
}

int Summary::GetHighscore() {
	return highscore;
}

int Summary::GetMaxScore() {
	return maxScore;
}

int Summary::GetScoreStarsNum() {
	return scoreStarsNum;
}

int Summary::GetScoreHollowStarsNum() {
	return scoreHollowStarsNum;
}

int Summary::GetHighscoreStarsNum() {
	return highscoreStarsNum;
}

int Summary::GetHighscoreHollowStarsNum() {
	return highscoreHollowStarsNum;
}

std::list<SummaryButton>& Summary::GetButtons() {
	return buttons;
}

void Summary::HandlePress(HWND& hWnd) {

	POINT target;
	GetCursorPos(&target);
	ScreenToClient(hWnd, &target);
	pressPos.x = target.x;
	pressPos.y = target.y;
	ApplyChoice();
}

void Summary::HandleMove(HWND& hWnd) {

	POINT target;
	GetCursorPos(&target);
	ScreenToClient(hWnd, &target);
	cursorPos.x = target.x;
	cursorPos.y = target.y;
	ApplyAnimation();
}

void Summary::ApplyChoice() {
	
	int i = 0;

	for (SummaryButton& button : buttons) {

		if (i == 2 && GameSave::GetCurrentLevel() <= Game::GetDiff()) {
		
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

void Summary::ApplyAnimation() {

	int i = 0;

	for (SummaryButton& button : buttons) {

		if (i == 2 && GameSave::GetCurrentLevel() <= Game::GetDiff()) {

			i++;
			continue;
		}

		if (Verifier::WithinAlt(cursorPos, button.GetTopLeft(), button.GetWidth(), button.GetHeight())) {

			SetCursor(LoadCursorFromFile(L"radioactive-select.ani"));

			if (!button.IsHovered()) {

				button.SetHovered(true);
				CreateAnimationThread(button);
			}
		}

		else button.SetHovered(false);

		i++;
	}
}

void Summary::CreateAnimationThread(SummaryButton& button) {

	std::thread thread = std::thread([this, &button]() {
		this->AnimateButton(button);
	});
	thread.detach();
}

void Summary::AnimateButton(SummaryButton& button) {

	int stage = 0;
	animationTimer.Restart();

	Point originalTopLeft = button.GetTopLeft();
	Point originalBottomRight = button.GetBottomRight();

	while (button.IsHovered()) {

		if (stage < Globals::ANIMATION_STAGES) {

			float elapsedTime = animationTimer.GetElapsedTime();

			if (elapsedTime > Globals::ANIMATION_STAGE_TIME) {

				button.SetTopLeft(Point(button.GetTopLeft().x - Globals::ANIMATION_SMALL_SHIFT_X, button.GetTopLeft().y - Globals::ANIMATION_SMALL_SHIFT_Y));
				button.SetBottomRight(Point(button.GetBottomRight().x + Globals::ANIMATION_SMALL_SHIFT_X, button.GetBottomRight().y + Globals::ANIMATION_SMALL_SHIFT_Y));
				stage++;
				animationTimer.Restart();
			}
		}

		Sleep(1);
	}

	button.SetTopLeft(originalTopLeft);
	button.SetBottomRight(originalBottomRight);
}

void Summary::GoToMenu() {

	finished = true;
	std::thread waitingThread = std::thread(WaitForReady);
	
	if (waitingThread.joinable())
		waitingThread.join();
	
	Music::ClearSounds();
	Music::PlayMenu();
	Menu::SetGameRunning(false);
}

void Summary::Replay() {

	int diff = Game::GetDiff();
	finished = true;
	std::thread waitingThread = std::thread(WaitForReady);

	if (waitingThread.joinable())
		waitingThread.join();
	
	Menu::SetGameRunning(false);
	Menu::RestartGame(diff);
}

void Summary::PlayNext() {

	int diff = Game::GetDiff();
	finished = true;
	std::thread waitingThread = std::thread(WaitForReady);

	if (waitingThread.joinable())
		waitingThread.join();

	Menu::SetGameRunning(false);
	Menu::StartNextGame(diff);
}

void Summary::WaitForReady() {

	while (!Game::IsReady())
		Sleep(10);
}
