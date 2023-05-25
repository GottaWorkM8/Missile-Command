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
const float Globals::BAR_Y = MAX_Y - (MAX_Y / 12);

const float Globals::BAR_ICON_HEIGHT = MAX_Y / 16;
const float Globals::BAR_ICON_WIDTH = BAR_ICON_HEIGHT;
const float Globals::BAR_ICON_Y = BAR_Y;
const float Globals::BAR_ICON_BOTTOM = BAR_ICON_Y + BAR_ICON_HEIGHT;
const float Globals::BAR_ICON_SPACE = MAX_X / 100;
const float Globals::FIRST_BAR_ICON_X = MAX_X / 14;
const float Globals::FIRST_BAR_ICON_RIGHT = FIRST_BAR_ICON_X + BAR_ICON_WIDTH;
const float Globals::SECOND_BAR_ICON_X = FIRST_BAR_ICON_RIGHT + BAR_ICON_SPACE;
const float Globals::SECOND_BAR_ICON_RIGHT = SECOND_BAR_ICON_X + BAR_ICON_WIDTH;
const float Globals::THIRD_BAR_ICON_X = SECOND_BAR_ICON_RIGHT + BAR_ICON_SPACE;
const float Globals::THIRD_BAR_ICON_RIGHT = THIRD_BAR_ICON_X + BAR_ICON_WIDTH;
const float Globals::FOURTH_BAR_ICON_X = THIRD_BAR_ICON_RIGHT + BAR_ICON_SPACE;
const float Globals::FOURTH_BAR_ICON_RIGHT = FOURTH_BAR_ICON_X + BAR_ICON_WIDTH;
const float Globals::FIFTH_BAR_ICON_X = FOURTH_BAR_ICON_RIGHT + BAR_ICON_SPACE;
const float Globals::FIFTH_BAR_ICON_RIGHT = FIFTH_BAR_ICON_X + BAR_ICON_WIDTH;

const float Globals::BAR_SCORE_Y = BAR_Y + (MAX_Y / 160);
const float Globals::BAR_SCORE_HEIGHT = MAX_Y / 20;

const float Globals::BAR_BOMB_HEIGHT = MAX_Y / 32;
const float Globals::BAR_BOMB_WIDTH = BAR_BOMB_HEIGHT;
const float Globals::BAR_BOMB_Y = BAR_Y + 15.0f;
const float Globals::BAR_BOMB_BOTTOM = BAR_BOMB_Y + BAR_BOMB_HEIGHT;
const float Globals::BAR_BOMB_SPACE = MAX_X / 30;
const float Globals::FIRST_BAR_BOMB_X = MAX_X / 1.4f;
const float Globals::FIRST_BAR_BOMB_RIGHT = FIRST_BAR_BOMB_X + BAR_BOMB_WIDTH;
const float Globals::SECOND_BAR_BOMB_X = FIRST_BAR_BOMB_RIGHT + BAR_BOMB_SPACE;
const float Globals::SECOND_BAR_BOMB_RIGHT = SECOND_BAR_BOMB_X + BAR_BOMB_WIDTH;
const float Globals::THIRD_BAR_BOMB_X = SECOND_BAR_BOMB_RIGHT + BAR_BOMB_SPACE;
const float Globals::THIRD_BAR_BOMB_RIGHT = THIRD_BAR_BOMB_X + BAR_BOMB_WIDTH;
const float Globals::FOURTH_BAR_BOMB_X = THIRD_BAR_BOMB_RIGHT + BAR_BOMB_SPACE;
const float Globals::FOURTH_BAR_BOMB_RIGHT = FOURTH_BAR_BOMB_X + BAR_BOMB_WIDTH;
const float Globals::FIFTH_BAR_BOMB_X = FOURTH_BAR_BOMB_RIGHT + BAR_BOMB_SPACE;
const float Globals::FIFTH_BAR_BOMB_RIGHT = FIFTH_BAR_BOMB_X + BAR_BOMB_WIDTH;

const float Globals::BAR_BOMB_NUM_Y = BAR_Y + 20.0f;
const float Globals::BAR_BOMB_NUM_HEIGHT = MAX_Y / 48;
const float Globals::BAR_BOMB_NUM_SPACE = MAX_X / 40;
const float Globals::FIRST_BAR_BOMB_NUM_CENTER = FIRST_BAR_BOMB_X + BAR_BOMB_NUM_SPACE;
const float Globals::SECOND_BAR_BOMB_NUM_CENTER = SECOND_BAR_BOMB_X + BAR_BOMB_NUM_SPACE;
const float Globals::THIRD_BAR_BOMB_NUM_CENTER = THIRD_BAR_BOMB_X + BAR_BOMB_NUM_SPACE;
const float Globals::FOURTH_BAR_BOMB_NUM_CENTER = FOURTH_BAR_BOMB_X + BAR_BOMB_NUM_SPACE;
const float Globals::FIFTH_BAR_BOMB_NUM_CENTER = FIFTH_BAR_BOMB_X + BAR_BOMB_NUM_SPACE;

const float Globals::FRAME_TIME = 100 / 12; // 120 fps
const float Globals::GAME_TIME = 60.0f; // 60 second turn

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
const float Globals::NORMAL_BOMB_SPEED = 1.5f;
const float Globals::NUCLEAR_BOMB_SPEED = 1.0f;
const float Globals::CLUSTER_BOMB_SPEED = 1.2f;
const float Globals::NAPALM_BOMB_SPEED = 1.2f;
const float Globals::ROD_BOMB_SPEED = 2.5f;
const float Globals::BOMB_LOAD_TIME = 1.0f;

const float Globals::EXPLOSION_PROPAGATION_TIME = 0.5f;
const float Globals::EXPLOSION_FINAL_TIME = 0.2f;
const float Globals::EXPLOSION_INITIAL_RADIUS = 20.0f;
const float Globals::NORMAL_EXPLOSION_FINAL_RADIUS = 80.0f;
const float Globals::NUCLEAR_EXPLOSION_FINAL_RADIUS = 160.0f;
const float Globals::CLUSTER_EXPLOSION_FINAL_RADIUS = 40.0f;
const float Globals::NAPALM_EXPLOSION_FINAL_RADIUS = 40.0f;
const float Globals::ROD_EXPLOSION_FINAL_RADIUS = 200.0f;
const int Globals::EXPLOSION_STAGES = 20;
const float Globals::NORMAL_EXPLOSION_RADIUS_GROWTH = (NORMAL_EXPLOSION_FINAL_RADIUS
	- EXPLOSION_INITIAL_RADIUS) / EXPLOSION_STAGES;
const float Globals::NUCLEAR_EXPLOSION_RADIUS_GROWTH = (NUCLEAR_EXPLOSION_FINAL_RADIUS
	- EXPLOSION_INITIAL_RADIUS) / EXPLOSION_STAGES;
const float Globals::CLUSTER_EXPLOSION_RADIUS_GROWTH = (CLUSTER_EXPLOSION_FINAL_RADIUS
	- EXPLOSION_INITIAL_RADIUS) / EXPLOSION_STAGES;
const float Globals::NAPALM_EXPLOSION_RADIUS_GROWTH = (NAPALM_EXPLOSION_FINAL_RADIUS
	- EXPLOSION_INITIAL_RADIUS) / EXPLOSION_STAGES;
const float Globals::ROD_EXPLOSION_RADIUS_GROWTH = (ROD_EXPLOSION_FINAL_RADIUS
	- EXPLOSION_INITIAL_RADIUS) / EXPLOSION_STAGES;
const float Globals::EXPLOSION_STAGE_TIME = EXPLOSION_PROPAGATION_TIME / EXPLOSION_STAGES;

const float Globals::FLASH_PROPAGATION_TIME = 0.1;
const float Globals::FLASH_INITIAL_RADIUS = 5.0f;
const float Globals::FLASH_FINAL_RADIUS = 15.0f;
const float Globals::FLASH_STAGES = 10;
const float Globals::FLASH_RADIUS_GROWTH = (FLASH_FINAL_RADIUS - FLASH_INITIAL_RADIUS) / FLASH_STAGES;
const float Globals::FLASH_STAGE_TIME = FLASH_PROPAGATION_TIME / FLASH_STAGES;