#pragma once

#include <d2d1.h>
#include <thread>
#include "Globals.h"

/// <summary>
/// Class responsible for animating introduction at the start of every game 
/// </summary>
class Intro {

	std::thread thread;

	// Animates intro by changing background color and text color of the introduction at the start of the game
	void AnimateIntro();

public:

	Intro();
	~Intro();

	D2D1_COLOR_F backgroundColor;
	D2D1_COLOR_F textColor;	
};

