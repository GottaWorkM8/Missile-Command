#pragma once

#include "Point.h"
#include "Timer.h"

class Globals {

public:

	// Menu & Game
	
	static const float MAX_X;
	static const float CENTER_X;
	static const float MAX_Y;

	// Menu

	static const Point TITLE_TOP_LEFT;
	static const float TITLE_WIDTH;
	static const float TITLE_HEIGHT;

	static const float BUTTON_X;
	static const float FIRST_BUTTON_Y;
	static const float BUTTON_HEIGHT;
	static const float BUTTON_SPACE;

	static const Point CONTINUE_TOP_LEFT;
	static const Point NEW_TOP_LEFT;
	static const Point OPTIONS_TOP_LEFT;
	static const Point HELP_TOP_LEFT;
	static const Point EXIT_TOP_LEFT;

	static const float ANIMATION_TIME;
	static const int ANIMATION_STAGES;
	static const float ANIMATION_STAGE_TIME;
	static const float ANIMATION_SHIFT_X;

	// Game

	static const int LEVEL1;
	static const int LEVEL2;
	static const int LEVEL3;
	static const int LEVEL4;
	static const int LEVEL5;

	static const float GROUND_Y;

	static const float FRAME_TIME;
	static const float GAME_TIME;

	static const int MAX_AMMO;
	static const float AMMO_LOAD_TIME;

	static const float LAUNCHER_HP;
	static const Point LAUNCHER_CENTER;
	static const float LAUNCHER_HALF_WIDTH;
	static const float LAUNCHER_HALF_HEIGHT;
	static const Point LAUNCHER_CANNON_BOTTOM_CENTER;
	static const float LAUNCHER_CANNON_HALF_WIDTH;
	static const float LAUNCHER_CANNON_HALF_HEIGHT;

	static const float BUILDING_HP;
	static const float BUILDING_HALF_WIDTH;
	static const float BUILDING_HALF_HEIGHT;

	static const float MISSILE_HALF_WIDTH;
	static const float MISSILE_HALF_HEIGHT;
	static const float MISSILE_SPEED;
	static const float MISSILE_LOAD_TIME;

	static const float BOMB_ORIGIN_Y;
	static const float BOMB_ORIGIN_MIN_X;
	static const float BOMB_ORIGIN_MAX_X;
	static const float BOMB_TARGET_Y;
	static const float BOMB_HALF_WIDTH;
	static const float BOMB_HALF_HEIGHT;
	static const float BOMB_SPEED;
	static const float BOMB_LOAD_TIME;

	static const float EXPLOSION_PROPAGATION_TIME;
	static const float EXPLOSION_FINAL_TIME;
	static const float EXPLOSION_INITIAL_RADIUS;
	static const float EXPLOSION_FINAL_RADIUS;
	static const int EXPLOSION_STAGES;
	static const float EXPLOSION_RADIUS_GROWTH;
	static const float EXPLOSION_STAGE_TIME;

	static const float FLASH_PROPAGATION_TIME;
	static const float FLASH_INITIAL_RADIUS;
	static const float FLASH_FINAL_RADIUS;
	static const float FLASH_STAGES;
	static const float FLASH_RADIUS_GROWTH;
	static const float FLASH_STAGE_TIME;
};

