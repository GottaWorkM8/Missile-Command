#pragma once

#include <d2d1.h>
#include <thread>
#include "Globals.h"

/// <summary>description</summary>
class Intro {

	std::thread thread;

	void AnimateIntro();

public:

	Intro();
	~Intro();

	D2D1_COLOR_F backgroundColor;
	D2D1_COLOR_F textColor;	
};

