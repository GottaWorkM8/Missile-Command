#include "Globals.h"

// Menu & Game

const float Globals::MAX_X = 1600.0f;
const float Globals::CENTER_X = MAX_X / 2;
const float Globals::MAX_Y = 900.0f;
const D2D1_COLOR_F Globals::BRUSH_DEFAULT_COLOR = D2D1::ColorF(1.0f, 1.0f, 1.0f, 1.0f);
const D2D1_COLOR_F Globals::GREEN = D2D1::ColorF(0.0f, 1.0f, 0.0f, 1.0f);
const D2D1_COLOR_F Globals::RED = D2D1::ColorF(1.0f, 0.0f, 0.0f, 1.0f);
const D2D1_COLOR_F Globals::POPUP_BACKGROUND_COLOR = D2D1::ColorF(0.0f, 0.0f, 0.0f, 0.65f);

const float Globals::ANIMATION_TIME = 0.3f;
const int Globals::ANIMATION_STAGES = 10;
const float Globals::ANIMATION_STAGE_TIME = ANIMATION_TIME / ANIMATION_STAGES;
const float Globals::ANIMATION_SHIFT_X = 1;
const float Globals::ANIMATION_SHIFT_Y = 1;
const float Globals::ANIMATION_SMALL_SHIFT_X = 0.5f;
const float Globals::ANIMATION_SMALL_SHIFT_Y = 0.5f;

// Menu

const float Globals::TITLE_WIDTH = MAX_X / 2.5f;
const float Globals::TITLE_HEIGHT = MAX_Y / 7;
const Point Globals::TITLE_TOP_LEFT = Point(CENTER_X - TITLE_WIDTH / 2, MAX_Y / 6);

const float Globals::BUTTON_LEFT = MAX_X / 12;
const float Globals::FIRST_BUTTON_Y = MAX_Y / 2.5f;
const float Globals::BUTTON_HEIGHT = MAX_Y / 25;
const float Globals::BUTTON_SPACE = MAX_Y / BUTTON_HEIGHT + MAX_Y / 25;

const Point Globals::CONTINUE_TOP_LEFT = Point(BUTTON_LEFT, FIRST_BUTTON_Y);
const Point Globals::NEW_TOP_LEFT = Point(BUTTON_LEFT, FIRST_BUTTON_Y + BUTTON_SPACE);
const Point Globals::HELP_TOP_LEFT = Point(BUTTON_LEFT, FIRST_BUTTON_Y + 2 * BUTTON_SPACE);
const Point Globals::EXIT_TOP_LEFT = Point(BUTTON_LEFT, FIRST_BUTTON_Y + 3 * BUTTON_SPACE);

const float Globals::HELP_LEFT = MAX_X / 10;
const float Globals::HELP_TOP = MAX_Y / 12;
const float Globals::HELP_RIGHT = MAX_X - HELP_LEFT;
const float Globals::HELP_BOTTOM = MAX_Y - HELP_TOP;

// Game

const float Globals::FRAME_TIME = 1000 / 120; // 120 fps
const float Globals::GAME_TIME = 60.0f; // 60 second turn
const float Globals::BOMB_SPAWN_TIME = 59.0f;

const int Globals::LEVEL1 = 1;
const int Globals::LEVEL2 = 2;
const int Globals::LEVEL3 = 3;
const int Globals::LEVEL4 = 4;
const int Globals::LEVEL5 = 5;
const int Globals::LEVEL_MAX = LEVEL5;

const float Globals::GROUND_Y = MAX_Y - (MAX_Y / 9);

const float Globals::BAR_TOP = MAX_Y - MAX_Y / 12;
const float Globals::BAR_ICON_HEIGHT = MAX_Y / 16;
const float Globals::BAR_ICON_WIDTH = BAR_ICON_HEIGHT;
const float Globals::BAR_ICON_TOP = BAR_TOP;
const float Globals::BAR_ICON_BOTTOM = BAR_ICON_TOP + BAR_ICON_HEIGHT;
const float Globals::BAR_ICON_SPACE = MAX_X / 100;
const float Globals::FIRST_BAR_ICON_LEFT = MAX_X / 14;
const float Globals::FIRST_BAR_ICON_RIGHT = FIRST_BAR_ICON_LEFT + BAR_ICON_WIDTH;
const float Globals::SECOND_BAR_ICON_LEFT = FIRST_BAR_ICON_RIGHT + BAR_ICON_SPACE;
const float Globals::SECOND_BAR_ICON_RIGHT = SECOND_BAR_ICON_LEFT + BAR_ICON_WIDTH;
const float Globals::THIRD_BAR_ICON_LEFT = SECOND_BAR_ICON_RIGHT + BAR_ICON_SPACE;
const float Globals::THIRD_BAR_ICON_RIGHT = THIRD_BAR_ICON_LEFT + BAR_ICON_WIDTH;
const float Globals::FOURTH_BAR_ICON_LEFT = THIRD_BAR_ICON_RIGHT + BAR_ICON_SPACE;
const float Globals::FOURTH_BAR_ICON_RIGHT = FOURTH_BAR_ICON_LEFT + BAR_ICON_WIDTH;
const float Globals::FIFTH_BAR_ICON_LEFT = FOURTH_BAR_ICON_RIGHT + BAR_ICON_SPACE;
const float Globals::FIFTH_BAR_ICON_RIGHT = FIFTH_BAR_ICON_LEFT + BAR_ICON_WIDTH;

const float Globals::BAR_SCORE_Y = BAR_TOP + (MAX_Y / 160);
const float Globals::BAR_SCORE_HEIGHT = MAX_Y / 20;

const float Globals::BAR_BOMB_HEIGHT = MAX_Y / 32;
const float Globals::BAR_BOMB_WIDTH = BAR_BOMB_HEIGHT;
const float Globals::BAR_BOMB_TOP = BAR_TOP + 15.0f;
const float Globals::BAR_BOMB_BOTTOM = BAR_BOMB_TOP + BAR_BOMB_HEIGHT;
const float Globals::BAR_BOMB_SPACE = MAX_X / 30;
const float Globals::FIRST_BAR_BOMB_LEFT = MAX_X / 1.4f;
const float Globals::FIRST_BAR_BOMB_RIGHT = FIRST_BAR_BOMB_LEFT + BAR_BOMB_WIDTH;
const float Globals::SECOND_BAR_BOMB_LEFT = FIRST_BAR_BOMB_RIGHT + BAR_BOMB_SPACE;
const float Globals::SECOND_BAR_BOMB_RIGHT = SECOND_BAR_BOMB_LEFT + BAR_BOMB_WIDTH;
const float Globals::THIRD_BAR_BOMB_LEFT = SECOND_BAR_BOMB_RIGHT + BAR_BOMB_SPACE;
const float Globals::THIRD_BAR_BOMB_RIGHT = THIRD_BAR_BOMB_LEFT + BAR_BOMB_WIDTH;
const float Globals::FOURTH_BAR_BOMB_LEFT = THIRD_BAR_BOMB_RIGHT + BAR_BOMB_SPACE;
const float Globals::FOURTH_BAR_BOMB_RIGHT = FOURTH_BAR_BOMB_LEFT + BAR_BOMB_WIDTH;
const float Globals::FIFTH_BAR_BOMB_LEFT = FOURTH_BAR_BOMB_RIGHT + BAR_BOMB_SPACE;
const float Globals::FIFTH_BAR_BOMB_RIGHT = FIFTH_BAR_BOMB_LEFT + BAR_BOMB_WIDTH;

const float Globals::BAR_BOMB_NUM_TOP = BAR_TOP + 20.0f;
const float Globals::BAR_BOMB_NUM_HEIGHT = MAX_Y / 48;
const float Globals::BAR_BOMB_NUM_SPACE = MAX_X / 40;
const float Globals::FIRST_BAR_BOMB_NUM_CENTER = FIRST_BAR_BOMB_LEFT + BAR_BOMB_NUM_SPACE;
const float Globals::SECOND_BAR_BOMB_NUM_CENTER = SECOND_BAR_BOMB_LEFT + BAR_BOMB_NUM_SPACE;
const float Globals::THIRD_BAR_BOMB_NUM_CENTER = THIRD_BAR_BOMB_LEFT + BAR_BOMB_NUM_SPACE;
const float Globals::FOURTH_BAR_BOMB_NUM_CENTER = FOURTH_BAR_BOMB_LEFT + BAR_BOMB_NUM_SPACE;
const float Globals::FIFTH_BAR_BOMB_NUM_CENTER = FIFTH_BAR_BOMB_LEFT + BAR_BOMB_NUM_SPACE;

const int Globals::MAX_AMMO = 5;
const float Globals::AMMO_LOAD_TIME = 0.5f;

const float Globals::LAUNCHER_HP = 250.0f;
const float Globals::LAUNCHER_PENALTY = 0.2f;
const float Globals::LAUNCHER_HALF_WIDTH = 35.0f;
const float Globals::LAUNCHER_HALF_HEIGHT = 30.0f;
const Point Globals::LAUNCHER_CENTER = Point(CENTER_X, GROUND_Y - LAUNCHER_HALF_HEIGHT);
const float Globals::LAUNCHER_CANNON_HALF_WIDTH = 15.0f;
const float Globals::LAUNCHER_CANNON_HALF_HEIGHT = 30.0f;
const Point Globals::LAUNCHER_CANNON_BOTTOM_CENTER = Point(LAUNCHER_CENTER.x, LAUNCHER_CENTER.y);

const float Globals::BUILDING_HP = 100.0f;
const float Globals::BUILDING_PENALTY = 0.1f;
const float Globals::BUILDING_HALF_WIDTH = 25.0f;
const float Globals::BUILDING_HALF_HEIGHT = 25.0f;
const float Globals::BUILDING_Y = GROUND_Y - BUILDING_HALF_HEIGHT;
const Point Globals::BUILDING1_CENTER = Point(MAX_X / 12, BUILDING_Y);
const Point Globals::BUILDING2_CENTER = Point(MAX_X / 12 * 2, BUILDING_Y);
const Point Globals::BUILDING3_CENTER = Point(MAX_X / 12 * 3, BUILDING_Y);
const Point Globals::BUILDING4_CENTER = Point(MAX_X / 12 * 4, BUILDING_Y);
const Point Globals::BUILDING5_CENTER = Point(MAX_X / 12 * 8, BUILDING_Y);
const Point Globals::BUILDING6_CENTER = Point(MAX_X / 12 * 9, BUILDING_Y);
const Point Globals::BUILDING7_CENTER = Point(MAX_X / 12 * 10, BUILDING_Y);
const Point Globals::BUILDING8_CENTER = Point(MAX_X / 12 * 11, BUILDING_Y);

const float Globals::HEALTH_BAR_TOP = BUILDING_Y + MAX_Y / 30;
const float Globals::HEALTH_BAR_HALF_WIDTH = MAX_X / 50;
const float Globals::LAUNCHER_HEALTH_BAR_HALF_WIDTH = MAX_X / 40;
const float Globals::HEALTH_BAR_HEIGHT = MAX_Y / 150;
const float Globals::LAUNCHER_HEALTH_BAR_HEIGHT = MAX_Y / 100;
const float Globals::MID_HP_THRESHOLD = 60.0f;
const float Globals::LOW_HP_THRESHOLD = 30.0f;
const D2D1_COLOR_F Globals::HIGH_HP_COLOR = D2D1::ColorF(0.0f, 1.0f, 0.0f, 1.0f);
const D2D1_COLOR_F Globals::MID_HP_COLOR = D2D1::ColorF(1.0f, 1.0f, 0.0f, 1.0f);
const D2D1_COLOR_F Globals::LOW_HP_COLOR = D2D1::ColorF(1.0f, 0.0f, 0.0f, 1.0f);

const float Globals::MISSILE_HALF_WIDTH = 10.0f;
const float Globals::MISSILE_HALF_HEIGHT = 10.0f;
const float Globals::MISSILE_DAMAGE = 20.0f;
const float Globals::MISSILE_SPEED = 10.0f;
const float Globals::MISSILE_LOAD_TIME = 0.1f;

const float Globals::BOMB_ORIGIN_Y = 0.0f;
const float Globals::BOMB_ORIGIN_MIN_X = MAX_X / 20;
const float Globals::BOMB_ORIGIN_MAX_X = MAX_X - BOMB_ORIGIN_MIN_X;
const float Globals::BOMB_HALF_WIDTH = 10.0f;
const float Globals::BOMB_HALF_HEIGHT = 10.0f;
const float Globals::BOMB_TARGET_Y = GROUND_Y - BOMB_HALF_HEIGHT;
const float Globals::NORMAL_BOMB_HP = 20.0f;
const float Globals::NORMAL_BOMB_DAMAGE = 50.0f;
const float Globals::NORMAL_BOMB_SPEED = 1.5f;
const int Globals::NORMAL_BOMB_POINTS = 10;
const float Globals::NUCLEAR_BOMB_HP = 20.0f;
const float Globals::NUCLEAR_BOMB_DAMAGE = 100.0f;
const float Globals::NUCLEAR_BOMB_SPEED = 1.0f;
const int Globals::NUCLEAR_BOMB_POINTS = 20;
const float Globals::CLUSTER_BOMB_HP = 20.0f;
const float Globals::CLUSTER_BOMB_DAMAGE = 30.0f;
const float Globals::CLUSTER_BOMB_SPEED = 1.3f;
const int Globals::CLUSTER_BOMB_POINTS = 30;
const float Globals::BOMBLET_HP = 10.0f;
const float Globals::BOMBLET_DAMAGE = 30.0f;
const float Globals::BOMBLET_SPEED = 1.8f;
const int Globals::BOMBLETS_SPAWNED = 3;
const int Globals::BOMBLET_POINTS = 10;
const float Globals::NAPALM_BOMB_HP = 40.0f;
const float Globals::NAPALM_BOMB_DAMAGE = 80.0f;
const float Globals::NAPALM_BOMB_SPEED = 1.0f;
const int Globals::NAPALM_BOMB_POINTS = 40;
const float Globals::ROD_BOMB_HP = 60.0f;
const float Globals::ROD_BOMB_DAMAGE = 150.0f;
const float Globals::ROD_BOMB_SPEED = 2.4f;
const int Globals::ROD_BOMB_POINTS = 60;

const float Globals::EXPLOSION_PROPAGATION_TIME = 0.5f;
const float Globals::EXPLOSION_FINAL_TIME = 0.2f;
const float Globals::EXPLOSION_INITIAL_RADIUS = 20.0f;
const float Globals::NORMAL_EXPLOSION_FINAL_RADIUS = 80.0f;
const float Globals::NUCLEAR_EXPLOSION_FINAL_RADIUS = 160.0f;
const float Globals::CLUSTER_EXPLOSION_FINAL_RADIUS = 60.0f;
const float Globals::BOMBLET_EXPLOSION_FINAL_RADIUS = 60.0f;
const float Globals::NAPALM_EXPLOSION_FINAL_RADIUS = 120.0f;
const float Globals::ROD_EXPLOSION_FINAL_RADIUS = 200.0f;
const int Globals::EXPLOSION_STAGES = 20;
const float Globals::NORMAL_EXPLOSION_RADIUS_GROWTH = (NORMAL_EXPLOSION_FINAL_RADIUS
	- EXPLOSION_INITIAL_RADIUS) / EXPLOSION_STAGES;
const float Globals::NUCLEAR_EXPLOSION_RADIUS_GROWTH = (NUCLEAR_EXPLOSION_FINAL_RADIUS
	- EXPLOSION_INITIAL_RADIUS) / EXPLOSION_STAGES;
const float Globals::CLUSTER_EXPLOSION_RADIUS_GROWTH = (CLUSTER_EXPLOSION_FINAL_RADIUS
	- EXPLOSION_INITIAL_RADIUS) / EXPLOSION_STAGES;
const float Globals::BOMBLET_EXPLOSION_RADIUS_GROWTH = (BOMBLET_EXPLOSION_FINAL_RADIUS
	- EXPLOSION_INITIAL_RADIUS) / EXPLOSION_STAGES;
const float Globals::NAPALM_EXPLOSION_RADIUS_GROWTH = (NAPALM_EXPLOSION_FINAL_RADIUS
	- EXPLOSION_INITIAL_RADIUS) / EXPLOSION_STAGES;
const float Globals::ROD_EXPLOSION_RADIUS_GROWTH = (ROD_EXPLOSION_FINAL_RADIUS
	- EXPLOSION_INITIAL_RADIUS) / EXPLOSION_STAGES;
const float Globals::EXPLOSION_STAGE_TIME = EXPLOSION_PROPAGATION_TIME / EXPLOSION_STAGES;

const float Globals::FLASH_PROPAGATION_TIME = 0.1;
const float Globals::FLASH_INITIAL_RADIUS = 5.0f;
const float Globals::FLASH_FINAL_RADIUS = 15.0f;
const int Globals::FLASH_STAGES = 10;
const float Globals::FLASH_RADIUS_GROWTH = (FLASH_FINAL_RADIUS - FLASH_INITIAL_RADIUS) / FLASH_STAGES;
const float Globals::FLASH_STAGE_TIME = FLASH_PROPAGATION_TIME / FLASH_STAGES;

const float Globals::DESTRUCTION_PROPAGATION_TIME = 0.4f;
const float Globals::DESTRUCTION_INITIAL_RADIUS = 10.0f;
const float Globals::DESTRUCTION_FINAL_RADIUS = 50.0f;
const int Globals::DESTRUCTION_STAGES = 20;
const float Globals::DESTRUCTION_RADIUS_GROWTH = (DESTRUCTION_FINAL_RADIUS - DESTRUCTION_INITIAL_RADIUS) / DESTRUCTION_STAGES;
const float Globals::DESTRUCTION_STAGE_TIME = DESTRUCTION_PROPAGATION_TIME / DESTRUCTION_STAGES;

// Intro

const float Globals::INTRO_BAR_HEIGHT = MAX_Y / 12;
const float Globals::INTRO_BAR_TOP = MAX_Y / 5;
const float Globals::INTRO_BAR_BOTTOM = INTRO_BAR_TOP + INTRO_BAR_HEIGHT;
const float Globals::INTRO_TOP = INTRO_BAR_TOP + (MAX_Y / 50);
const float Globals::INTRO_HEIGHT = MAX_Y / 20;
const float Globals::INTRO_TIME = 3.5f;
const int Globals::INTRO_STAGES = 60;
const float Globals::INTRO_STAGE_TIME = INTRO_TIME / INTRO_STAGES;
const float Globals::INTRO_BACKGROUND_SHIFT = POPUP_BACKGROUND_COLOR.a / 20;
const float Globals::INTRO_TEXT_SHIFT = BRUSH_DEFAULT_COLOR.a / 20;

// Summary

const float Globals::SUMMARY_DIALOG_LEFT = MAX_X / 4;
const float Globals::SUMMARY_DIALOG_TOP = MAX_Y / 5;
const float Globals::SUMMARY_DIALOG_RIGHT = MAX_X / 4 * 3;
const float Globals::SUMMARY_DIALOG_BOTTOM = MAX_Y / 5 * 4;
const float Globals::SUMMARY_TITLE_TOP = SUMMARY_DIALOG_TOP + MAX_Y / 25;
const float Globals::SUMMARY_TITLE_HEIGHT = MAX_Y / 20;
const float Globals::SUMMARY_SEPARATOR_HEIGHT = MAX_Y / 200;
const float Globals::SUMMARY_SEPARATOR_LEFT = SUMMARY_DIALOG_LEFT + MAX_X / 30;
const float Globals::SUMMARY_SEPARATOR_TOP = SUMMARY_TITLE_TOP + MAX_Y / 15;
const float Globals::SUMMARY_SEPARATOR_RIGHT = SUMMARY_DIALOG_RIGHT - MAX_X / 30;
const float Globals::SUMMARY_SEPARATOR_BOTTOM = SUMMARY_SEPARATOR_TOP + SUMMARY_SEPARATOR_HEIGHT;
const float Globals::SUMMARY_TEXT_LEFT = SUMMARY_SEPARATOR_LEFT;
const float Globals::SUMMARY_TEXT_TOP = SUMMARY_SEPARATOR_TOP + MAX_Y / 20;
const float Globals::SUMMARY_TEXT_WIDTH = SUMMARY_SEPARATOR_RIGHT - SUMMARY_SEPARATOR_LEFT;
const float Globals::SUMMARY_TEXT_HEIGHT = MAX_Y / 10;
const float Globals::SUMMARY_SCORE_LEFT = SUMMARY_TEXT_LEFT;
const float Globals::SUMMARY_SCORE_TOP = SUMMARY_TEXT_TOP + SUMMARY_TEXT_HEIGHT + MAX_Y / 50;
const float Globals::SUMMARY_SCORE_HEIGHT = MAX_Y / 25;
const float Globals::SUMMARY_SCORE_NUM_LEFT = SUMMARY_SCORE_LEFT + MAX_X / 13;
const float Globals::SUMMARY_SCORE_NUM_TOP = SUMMARY_SCORE_TOP;
const float Globals::SUMMARY_SCORE_NUM_HEIGHT = SUMMARY_SCORE_HEIGHT;
const float Globals::SUMMARY_HIGHSCORE_LEFT = SUMMARY_TEXT_LEFT;
const float Globals::SUMMARY_HIGHSCORE_TOP = SUMMARY_SCORE_TOP + SUMMARY_SCORE_HEIGHT + MAX_Y / 25;
const float Globals::SUMMARY_HIGHSCORE_HEIGHT = MAX_Y / 40;
const float Globals::SUMMARY_HIGHSCORE_NUM_LEFT = SUMMARY_HIGHSCORE_LEFT + MAX_X / 12;
const float Globals::SUMMARY_HIGHSCORE_NUM_TOP = SUMMARY_HIGHSCORE_TOP;
const float Globals::SUMMARY_HIGHSCORE_NUM_HEIGHT = SUMMARY_HIGHSCORE_HEIGHT;
const float Globals::SUMMARY_SCORE_STAR_LEFT = SUMMARY_SCORE_LEFT + MAX_X / 6.5f;
const float Globals::SUMMARY_SCORE_STAR_TOP = SUMMARY_SCORE_TOP - SUMMARY_SCORE_HEIGHT / 2;
const float Globals::SUMMARY_SCORE_STAR_RIGHT = SUMMARY_SCORE_STAR_LEFT + MAX_X / 24;
const float Globals::SUMMARY_SCORE_STAR_BOTTOM = SUMMARY_SCORE_STAR_TOP + MAX_Y / 14;
const float Globals::SUMMARY_SCORE_STAR_SPACE = SUMMARY_SCORE_STAR_RIGHT - SUMMARY_SCORE_STAR_LEFT + MAX_X / 70;
const float Globals::SUMMARY_HIGHSCORE_STAR_LEFT = SUMMARY_HIGHSCORE_LEFT + MAX_X / 7;
const float Globals::SUMMARY_HIGHSCORE_STAR_TOP = SUMMARY_HIGHSCORE_TOP - SUMMARY_HIGHSCORE_HEIGHT / 2;
const float Globals::SUMMARY_HIGHSCORE_STAR_RIGHT = SUMMARY_HIGHSCORE_STAR_LEFT + MAX_X / 30;
const float Globals::SUMMARY_HIGHSCORE_STAR_BOTTOM = SUMMARY_HIGHSCORE_STAR_TOP + MAX_Y / 18;
const float Globals::SUMMARY_HIGHSCORE_STAR_SPACE = SUMMARY_HIGHSCORE_STAR_RIGHT - SUMMARY_HIGHSCORE_STAR_LEFT + MAX_X / 80;
const int Globals::SUMMARY_STAR_NUM = 5;
const float Globals::SUMMARY_BUTTON_WIDTH = MAX_X / 20;
const float Globals::SUMMARY_BUTTON_SPACE = MAX_X / 15;
const float Globals::SUMMARY_REPLAY_LEFT = CENTER_X - SUMMARY_BUTTON_WIDTH / 2;
const float Globals::SUMMARY_REPLAY_TOP = SUMMARY_DIALOG_BOTTOM - SUMMARY_BUTTON_WIDTH * 1.5f;
const float Globals::SUMMARY_MENU_LEFT = SUMMARY_REPLAY_LEFT - SUMMARY_BUTTON_SPACE - SUMMARY_BUTTON_WIDTH;
const float Globals::SUMMARY_MENU_TOP = SUMMARY_REPLAY_TOP;
const float Globals::SUMMARY_NEXT_LEFT = SUMMARY_REPLAY_LEFT + SUMMARY_BUTTON_WIDTH + SUMMARY_BUTTON_SPACE;
const float Globals::SUMMARY_NEXT_TOP = SUMMARY_REPLAY_TOP;
