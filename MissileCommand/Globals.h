#pragma once

#include <d2d1.h>
#include "Point.h"

class Globals {

public:

	// Menu & Game
	
	static const float MAX_X;
	static const float CENTER_X;
	static const float MAX_Y;
	static const D2D1_COLOR_F BRUSH_DEFAULT_COLOR;
	static const D2D1_COLOR_F PROMPT_BACKGROUND_COLOR;

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

	static const float INTRO_BAR_Y;
	static const float INTRO_BAR_BOTTOM;
	static const float INTRO_BAR_HEIGHT;
	static const float INTRO_Y;
	static const float INTRO_HEIGHT;
	static const float INTRO_TIME;
	static const int INTRO_STAGES;
	static const float INTRO_STAGE_TIME;
	static const float INTRO_BACKGROUND_SHIFT;
	static const float INTRO_TEXT_SHIFT;

	static const float BAR_Y;
	static const float BAR_ICON_Y;
	static const float BAR_ICON_BOTTOM;
	static const float BAR_ICON_HEIGHT;
	static const float BAR_ICON_WIDTH;
	static const float BAR_ICON_SPACE;
	static const float FIRST_BAR_ICON_X;
	static const float FIRST_BAR_ICON_RIGHT;
	static const float SECOND_BAR_ICON_X;
	static const float SECOND_BAR_ICON_RIGHT;
	static const float THIRD_BAR_ICON_X;
	static const float THIRD_BAR_ICON_RIGHT;
	static const float FOURTH_BAR_ICON_X;
	static const float FOURTH_BAR_ICON_RIGHT;
	static const float FIFTH_BAR_ICON_X;
	static const float FIFTH_BAR_ICON_RIGHT;

	static const float BAR_SCORE_Y;
	static const float BAR_SCORE_HEIGHT;

	static const float BAR_BOMB_Y;
	static const float BAR_BOMB_BOTTOM;
	static const float BAR_BOMB_HEIGHT;
	static const float BAR_BOMB_WIDTH;
	static const float BAR_BOMB_SPACE;
	static const float FIRST_BAR_BOMB_X;
	static const float FIRST_BAR_BOMB_RIGHT;
	static const float SECOND_BAR_BOMB_X;
	static const float SECOND_BAR_BOMB_RIGHT;
	static const float THIRD_BAR_BOMB_X;
	static const float THIRD_BAR_BOMB_RIGHT;
	static const float FOURTH_BAR_BOMB_X;
	static const float FOURTH_BAR_BOMB_RIGHT;
	static const float FIFTH_BAR_BOMB_X;
	static const float FIFTH_BAR_BOMB_RIGHT;

	static const float BAR_BOMB_NUM_Y;
	static const float BAR_BOMB_NUM_HEIGHT;
	static const float BAR_BOMB_NUM_SPACE;
	static const float FIRST_BAR_BOMB_NUM_CENTER;
	static const float SECOND_BAR_BOMB_NUM_CENTER;
	static const float THIRD_BAR_BOMB_NUM_CENTER;
	static const float FOURTH_BAR_BOMB_NUM_CENTER;
	static const float FIFTH_BAR_BOMB_NUM_CENTER;

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
	static const float NORMAL_BOMB_SPEED;
	static const float NUCLEAR_BOMB_SPEED;
	static const float CLUSTER_BOMB_SPEED;
	static const float NAPALM_BOMB_SPEED;
	static const float ROD_BOMB_SPEED;
	static const float BOMB_LOAD_TIME;

	static const float EXPLOSION_PROPAGATION_TIME;
	static const float EXPLOSION_FINAL_TIME;
	static const float EXPLOSION_INITIAL_RADIUS;
	static const float NORMAL_EXPLOSION_FINAL_RADIUS;
	static const float NUCLEAR_EXPLOSION_FINAL_RADIUS;
	static const float CLUSTER_EXPLOSION_FINAL_RADIUS;
	static const float NAPALM_EXPLOSION_FINAL_RADIUS;
	static const float ROD_EXPLOSION_FINAL_RADIUS;
	static const int EXPLOSION_STAGES;
	static const float NORMAL_EXPLOSION_RADIUS_GROWTH;
	static const float NUCLEAR_EXPLOSION_RADIUS_GROWTH;
	static const float CLUSTER_EXPLOSION_RADIUS_GROWTH;
	static const float NAPALM_EXPLOSION_RADIUS_GROWTH;
	static const float ROD_EXPLOSION_RADIUS_GROWTH;
	static const float EXPLOSION_STAGE_TIME;

	static const float FLASH_PROPAGATION_TIME;
	static const float FLASH_INITIAL_RADIUS;
	static const float FLASH_FINAL_RADIUS;
	static const int FLASH_STAGES;
	static const float FLASH_RADIUS_GROWTH;
	static const float FLASH_STAGE_TIME;

	static const float DESTRUCTION_PROPAGATION_TIME;
	static const float DESTRUCTION_INITIAL_RADIUS;
	static const float DESTRUCTION_FINAL_RADIUS;
	static const int DESTRUCTION_STAGES;
	static const float DESTRUCTION_RADIUS_GROWTH;
	static const float DESTRUCTION_STAGE_TIME;
};

