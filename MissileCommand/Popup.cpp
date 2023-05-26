#include "Popup.h"

D2D1_COLOR_F Popup::backgroundColor = Globals::PROMPT_BACKGROUND_COLOR;
D2D1_COLOR_F Popup::textColor = Globals::BRUSH_DEFAULT_COLOR;

Point Popup::pressPos = Point();
Point Popup::cursorPos = Point();
Timer Popup::animationTimer = Timer();

void Popup::CreateIntroThread() {

	std::thread thread = std::thread(AnimateIntro);
	thread.detach();
}

void Popup::AnimateIntro() {

	backgroundColor = Globals::PROMPT_BACKGROUND_COLOR;
	backgroundColor.a = 0.0f;
	textColor = Globals::BRUSH_DEFAULT_COLOR;
	textColor.a = 0.0f;

	for (int i = 0; i < Globals::INTRO_STAGES; i++) {

		if (i < 20) {

			backgroundColor.a += Globals::INTRO_BACKGROUND_SHIFT;
			textColor.a += Globals::INTRO_TEXT_SHIFT;
		}

		else if (i >= 40) {

			backgroundColor.a -= Globals::INTRO_BACKGROUND_SHIFT;
			textColor.a -= Globals::INTRO_TEXT_SHIFT;
		}

		Sleep(Globals::INTRO_STAGE_TIME * 1000);
	}
}
