#include "Intro.h"

Intro::Intro() {

	backgroundColor = Globals::POPUP_BACKGROUND_COLOR;
	textColor = Globals::BRUSH_DEFAULT_COLOR;

	thread = std::thread(&Intro::AnimateIntro, this);
}

Intro::~Intro() {

	if (thread.joinable())
		thread.join();
}

void Intro::AnimateIntro() {

	backgroundColor.a = 0.0f;
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
