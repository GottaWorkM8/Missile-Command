#include "Globals.h"

// Menu & Game

const float Globals::MAX_X = 1600.0f;
const float Globals::CENTER_X = MAX_X / 2;
const float Globals::MAX_Y = 900.0f;

// Menu

const float Globals::TITLE_WIDTH = MAX_X / 2.5f;
const float Globals::TITLE_HEIGHT = MAX_Y / 7;
const Point Globals::TITLE_TOP_LEFT = Point(CENTER_X - TITLE_WIDTH / 2, MAX_Y / 6);

const float Globals::BUTTON_X = MAX_X / 12;
const float Globals::FIRST_BUTTON_Y = MAX_Y / 2.5f;
const float Globals::BUTTON_HEIGHT = MAX_Y / 25;
const float Globals::BUTTON_SPACE = MAX_Y / BUTTON_HEIGHT + MAX_Y / 25;

const Point Globals::CONTINUE_TOP_LEFT = Point(BUTTON_X, FIRST_BUTTON_Y);;
const Point Globals::NEW_TOP_LEFT = Point(BUTTON_X, FIRST_BUTTON_Y + BUTTON_SPACE);;
const Point Globals::OPTIONS_TOP_LEFT = Point(BUTTON_X, FIRST_BUTTON_Y + 2 * BUTTON_SPACE);;
const Point Globals::HELP_TOP_LEFT = Point(BUTTON_X, FIRST_BUTTON_Y + 3 * BUTTON_SPACE);;
const Point Globals::EXIT_TOP_LEFT = Point(BUTTON_X, FIRST_BUTTON_Y + 4 * BUTTON_SPACE);;

const float Globals::ANIMATION_TIME = 0.3f;
const int Globals::ANIMATION_STAGES = 20;
const float Globals::ANIMATION_STAGE_TIME = ANIMATION_TIME / ANIMATION_STAGES;
const float Globals::ANIMATION_SHIFT_X = 1;

// Game

const int Globals::LEVEL1 = 1;
const int Globals::LEVEL2 = 2;
const int Globals::LEVEL3 = 3;
const int Globals::LEVEL4 = 4;
const int Globals::LEVEL5 = 5;

const float Globals::GROUND_Y = MAX_Y - (MAX_Y / 7);

const float Globals::FRAME_TIME = 100 / 12; // 120 fps
const float Globals::GAME_TIME = 20.0f; // 60 second turn

const int Globals::MAX_AMMO = 5;
const float Globals::AMMO_LOAD_TIME = 0.5f;

const float Globals::LAUNCHER_HP = 250.0f;
const float Globals::LAUNCHER_HALF_WIDTH = 35.0f;
const float Globals::LAUNCHER_HALF_HEIGHT = 30.0f;
const Point Globals::LAUNCHER_CENTER = Point(CENTER_X, GROUND_Y - LAUNCHER_HALF_HEIGHT);
const float Globals::LAUNCHER_CANNON_HALF_WIDTH = 15.0f;
const float Globals::LAUNCHER_CANNON_HALF_HEIGHT = 30.0f;
const Point Globals::LAUNCHER_CANNON_BOTTOM_CENTER = Point(LAUNCHER_CENTER.x, LAUNCHER_CENTER.y);

const float Globals::BUILDING_HP = 100.0f;
const float Globals::BUILDING_HALF_WIDTH = 25.0f;
const float Globals::BUILDING_HALF_HEIGHT = 25.0f;

const float Globals::MISSILE_HALF_WIDTH = 10.0f;
const float Globals::MISSILE_HALF_HEIGHT = 10.0f;
const float Globals::MISSILE_SPEED = 10.0f;
const float Globals::MISSILE_LOAD_TIME = 0.1f;

const float Globals::BOMB_ORIGIN_Y = 0.0f;
const float Globals::BOMB_ORIGIN_MIN_X = MAX_X / 20;
const float Globals::BOMB_ORIGIN_MAX_X = MAX_X - BOMB_ORIGIN_MIN_X;
const float Globals::BOMB_HALF_WIDTH = 10.0f;
const float Globals::BOMB_HALF_HEIGHT = 10.0f;
const float Globals::BOMB_TARGET_Y = GROUND_Y - BOMB_HALF_HEIGHT;
const float Globals::BOMB_SPEED = 1.5f;
const float Globals::BOMB_LOAD_TIME = 1.0f;

const float Globals::EXPLOSION_PROPAGATION_TIME = 0.5f;
const float Globals::EXPLOSION_FINAL_TIME = 0.2f;
const float Globals::EXPLOSION_INITIAL_RADIUS = 20.0f;
const float Globals::EXPLOSION_FINAL_RADIUS = 80.0f;
const int Globals::EXPLOSION_STAGES = 20;
const float Globals::EXPLOSION_RADIUS_GROWTH = (EXPLOSION_FINAL_RADIUS
	- EXPLOSION_INITIAL_RADIUS) / EXPLOSION_STAGES;
const float Globals::EXPLOSION_STAGE_TIME = EXPLOSION_PROPAGATION_TIME / EXPLOSION_STAGES;

const float Globals::FLASH_PROPAGATION_TIME = 0.1;
const float Globals::FLASH_INITIAL_RADIUS = 5.0f;
const float Globals::FLASH_FINAL_RADIUS = 15.0f;
const float Globals::FLASH_STAGES = 10;
const float Globals::FLASH_RADIUS_GROWTH = (FLASH_FINAL_RADIUS - FLASH_INITIAL_RADIUS) / FLASH_STAGES;
const float Globals::FLASH_STAGE_TIME = FLASH_PROPAGATION_TIME / FLASH_STAGES;