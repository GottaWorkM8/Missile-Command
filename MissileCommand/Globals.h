#pragma once

#include <d2d1.h>
#include "Point.h"

/// <summary>
/// Class responsible solely for storing public global constants, used throughout the whole application
/// </summary>
class Globals {

public:

	// Menu & Game
	
	// overall width of the screen (pixels)
	static const float MAX_X;
	// x coordinate of the screen center (pixels)
	static const float CENTER_X;
	// overall height of the screen (pixels)
	static const float MAX_Y;
	// default color meant for the brush (255, 255, 255, 255)
	static const D2D1_COLOR_F BRUSH_DEFAULT_COLOR;
	// color green (0, 255, 0, 255)
	static const D2D1_COLOR_F GREEN;
	// color red (255, 0, 0, 255)
	static const D2D1_COLOR_F RED;
	// background color for popups
	static const D2D1_COLOR_F POPUP_BACKGROUND_COLOR;

	// overall duration of the animation (seconds)
	static const float ANIMATION_TIME;
	// number of stages that animation goes through
	static const int ANIMATION_STAGES;
	// duration of each stage of the animation (seconds)
	static const float ANIMATION_STAGE_TIME;
	// amount of pixels animated object is shifted by horizontally in each stage (1)
	static const float ANIMATION_SHIFT_X;
	// amount of pixels animated object is shifted by vertically in each stage (1)
	static const float ANIMATION_SHIFT_Y;
	// amount of pixels animated object is shifted by horizontally in each stage (0.5)
	static const float ANIMATION_SMALL_SHIFT_X;
	// amount of pixels animated object is shifted by vertically in each stage (0.5)
	static const float ANIMATION_SMALL_SHIFT_Y;

	// Menu

	// coordinates of the top-left corner of the title (pixels)
	static const Point TITLE_TOP_LEFT;
	// width of the title (pixels)
	static const float TITLE_WIDTH;
	// height of the title (pixels)
	static const float TITLE_HEIGHT;

	// x coordinate of left of every menu button (pixels)
	static const float BUTTON_LEFT;
	// y coordinate of the top of the first (heighest) menu button (pixels)
	static const float FIRST_BUTTON_Y;
	// height of every menu button (pixels)
	static const float BUTTON_HEIGHT;
	// vertical space between every pair of menu buttons (pixels)
	static const float BUTTON_SPACE;

	// coordinates of the top-left corner of the CONTINUE button (pixels)
	static const Point CONTINUE_TOP_LEFT;
	// coordinates of the top-left corner of the NEW GAME button (pixels)
	static const Point NEW_TOP_LEFT;
	// coordinates of the top-left corner of the HELP button (pixels)
	static const Point HELP_TOP_LEFT;
	// coordinates of the top-left corner of the EXIT button (pixels)
	static const Point EXIT_TOP_LEFT;

	// x coordinate of the left of the help popup (pixels)
	static const float HELP_LEFT;
	// y coordinate of the top of the help popup (pixels)
	static const float HELP_TOP;
	// x coordinate of the right of the help popup (pixels)
	static const float HELP_RIGHT;
	// y coordinate of the bottom of the help popup (pixels)
	static const float HELP_BOTTOM;

	// Game

	// duration of a single game frame (milliseconds)
	static const float FRAME_TIME;
	// duration of a single game; i.e. amount of time it takes to complete each level (seconds)
	static const float GAME_TIME;
	// amount of time, during which bombs will be spawned; after the specified time, no new bomb will appear (seconds)
	static const float BOMB_SPAWN_TIME;

	// overall number of levels in the game
	static constexpr int LEVELS_NUM = 5;
	// value representing the first game level
	static const int LEVEL1;
	// value representing the second game level
	static const int LEVEL2;
	// value representing the third game level
	static const int LEVEL3;
	// value representing the fourth game level
	static const int LEVEL4;
	// value representing the fifth game level
	static const int LEVEL5;
	// value representing the last game level
	static const int LEVEL_MAX;

	// y coordinate of the ground level; it influences where the launcher and buildings are placed, as well as where bombs explode by themselves (pixels)
	static const float GROUND_Y;

	// y coordinate of the top of the bar present on the bottom of the game screen (pixels)
	static const float BAR_TOP;
	// y coordinate of the top of every ammo icon present on the game bar (pixels)
	static const float BAR_ICON_TOP;
	// y coordinate of the bottom of every ammo icon present on the game bar (pixels)
	static const float BAR_ICON_BOTTOM;
	// height of every ammo icon present on the game bar (pixels)
	static const float BAR_ICON_HEIGHT;
	// width of every ammo icon present on the game bar (pixels)
	static const float BAR_ICON_WIDTH;
	// horizontal space between every pair of ammo icons present on the game bar (pixels)
	static const float BAR_ICON_SPACE;
	// x coordinate of the left of the first ammo icon present on the game bar (pixels)
	static const float FIRST_BAR_ICON_LEFT;
	// x coordinate of the right of the first ammo icon present on the game bar (pixels)
	static const float FIRST_BAR_ICON_RIGHT;
	// x coordinate of the left of the second ammo icon present on the game bar (pixels)
	static const float SECOND_BAR_ICON_LEFT;
	// x coordinate of the right of the second ammo icon present on the game bar (pixels)
	static const float SECOND_BAR_ICON_RIGHT;
	// x coordinate of the left of the third ammo icon present on the game bar (pixels)
	static const float THIRD_BAR_ICON_LEFT;
	// x coordinate of the right of the third ammo icon present on the game bar (pixels)
	static const float THIRD_BAR_ICON_RIGHT;
	// x coordinate of the left of the fourth ammo icon present on the game bar (pixels)
	static const float FOURTH_BAR_ICON_LEFT;
	// x coordinate of the right of the fourth ammo icon present on the game bar (pixels)
	static const float FOURTH_BAR_ICON_RIGHT;
	// x coordinate of the left of the fifth ammo icon present on the game bar (pixels)
	static const float FIFTH_BAR_ICON_LEFT;
	// x coordinate of the right of the fifth ammo icon present on the game bar (pixels)
	static const float FIFTH_BAR_ICON_RIGHT;

	// y coordinate of the top of the score displayed on the game bar (pixels) 
	static const float BAR_SCORE_Y;
	// height of the score displayed on the game bar (pixels)
	static const float BAR_SCORE_HEIGHT;

	// y coordinate of the top of the bomb icons present on the game bar (pixels)
	static const float BAR_BOMB_TOP;
	// y coordinate of the bottom of the bomb icons present on the game bar (pixels)
	static const float BAR_BOMB_BOTTOM;
	// height of every bomb icon present on the game bar (pixels)
	static const float BAR_BOMB_HEIGHT;
	// width of every bomb icon present on the game bar (pixels)
	static const float BAR_BOMB_WIDTH;
	// horizontal space between every pair of bomb icons present on the game bar (pixels)
	static const float BAR_BOMB_SPACE;
	// x coordinate of the left of the first bomb icon present on the game bar (pixels)
	static const float FIRST_BAR_BOMB_LEFT;
	// x coordinate of the right of the first bomb icon present on the game bar (pixels)
	static const float FIRST_BAR_BOMB_RIGHT;
	// x coordinate of the left of the second bomb icon present on the game bar (pixels)
	static const float SECOND_BAR_BOMB_LEFT;
	// x coordinate of the right of the second bomb icon present on the game bar (pixels)
	static const float SECOND_BAR_BOMB_RIGHT;
	// x coordinate of the left of the third bomb icon present on the game bar (pixels)
	static const float THIRD_BAR_BOMB_LEFT;
	// x coordinate of the right of the third bomb icon present on the game bar (pixels)
	static const float THIRD_BAR_BOMB_RIGHT;
	// x coordinate of the left of the fourth bomb icon present on the game bar (pixels)
	static const float FOURTH_BAR_BOMB_LEFT;
	// x coordinate of the right of the fourth bomb icon present on the game bar (pixels)
	static const float FOURTH_BAR_BOMB_RIGHT;
	// x coordinate of the left of the fifth bomb icon present on the game bar (pixels)
	static const float FIFTH_BAR_BOMB_LEFT;
	// x coordinate of the right of the fifth bomb icon present on the game bar (pixels)
	static const float FIFTH_BAR_BOMB_RIGHT;

	// y coordinate of the top of every bomb number present on the game bar (pixels)
	static const float BAR_BOMB_NUM_TOP;
	// height of every bomb number present on the game bar (pixels)
	static const float BAR_BOMB_NUM_HEIGHT;
	// horizontal space between every pair of bomb numbers present on the game bar (pixels)
	static const float BAR_BOMB_NUM_SPACE;
	// x coordinate of the center of the first bomb number present on the game bar (pixels)
	static const float FIRST_BAR_BOMB_NUM_CENTER;
	// x coordinate of the center of the second bomb number present on the game bar (pixels)
	static const float SECOND_BAR_BOMB_NUM_CENTER;
	// x coordinate of the center of the third bomb number present on the game bar (pixels)
	static const float THIRD_BAR_BOMB_NUM_CENTER;
	// x coordinate of the center of the fourth bomb number present on the game bar (pixels)
	static const float FOURTH_BAR_BOMB_NUM_CENTER;
	// x coordinate of the center of the fifth bomb number present on the game bar (pixels)
	static const float FIFTH_BAR_BOMB_NUM_CENTER;

	// maximum number of ammo at any given time
	static const int MAX_AMMO;
	// duration of loading a single projectile (ammo); i.e. amount of time for a single new projectile to get ready (seconds)
	static const float AMMO_LOAD_TIME;

	// amount of health points launcher has at the start of the game
	static const float LAUNCHER_HP;
	// factor representing percentage of maximum points cut after launcher is destroyed
	static const float LAUNCHER_PENALTY;
	// coordinates of the center of the launcher (pixels) 
	static const Point LAUNCHER_CENTER;
	// half the width of the launcher (pixels)
	static const float LAUNCHER_HALF_WIDTH;
	// half the height of the launcher (pixels)
	static const float LAUNCHER_HALF_HEIGHT;
	// coordinates of the bottom-center of the launcher cannon (pixels) 
	static const Point LAUNCHER_CANNON_BOTTOM_CENTER;
	// half the width of the launcher cannon (pixels)
	static const float LAUNCHER_CANNON_HALF_WIDTH;
	// half the height of the launcher cannon (pixels)
	static const float LAUNCHER_CANNON_HALF_HEIGHT;

	// amount of health points every building has at the start of the game
	static const float BUILDING_HP;
	// factor representing percentage of maximum points cut after any building is destroyed
	static const float BUILDING_PENALTY;
	// half the width of every building (pixels)
	static const float BUILDING_HALF_WIDTH;
	// half the height of every building (pixels)
	static const float BUILDING_HALF_HEIGHT;
	// y coordinate of the center of every building (pixels)
	static const float BUILDING_Y;
	// coordinates of the center of the first building (pixels) 
	static const Point BUILDING1_CENTER;
	// coordinates of the center of the second building (pixels)
	static const Point BUILDING2_CENTER;
	// coordinates of the center of the third building (pixels)
	static const Point BUILDING3_CENTER;
	// coordinates of the center of the fourth building (pixels)
	static const Point BUILDING4_CENTER;
	// coordinates of the center of the fifth building (pixels)
	static const Point BUILDING5_CENTER;
	// coordinates of the center of the sixth building (pixels)
	static const Point BUILDING6_CENTER;
	// coordinates of the center of the seventh building (pixels)
	static const Point BUILDING7_CENTER;
	// coordinates of the center of the eighth building (pixels)
	static const Point BUILDING8_CENTER;

	// y coordinate of the top of the health bar beneath the launcher and every building (pixels)
	static const float HEALTH_BAR_TOP;
	// half the width of the health bar beneath every building (pixels)
	static const float HEALTH_BAR_HALF_WIDTH;
	// half the width of the health bar beneath the launcher (pixels)
	static const float LAUNCHER_HEALTH_BAR_HALF_WIDTH;
	// height of the health bar beneath every building (pixels)
	static const float HEALTH_BAR_HEIGHT;
	// height of the health bar beneath the launcher (pixels)
	static const float LAUNCHER_HEALTH_BAR_HEIGHT;
	// higher limit of the percentage of maximum hp considered mediocre
	static const float MID_HP_THRESHOLD;
	// higher limit of the percentage of maximum hp considered low
	static const float LOW_HP_THRESHOLD;
	// color representing health when it is above mediocre
	static const D2D1_COLOR_F HIGH_HP_COLOR;
	// color representing health when it is above low
	static const D2D1_COLOR_F MID_HP_COLOR;
	// color representing health when it is low
	static const D2D1_COLOR_F LOW_HP_COLOR;

	// half the width of the missile (pixels)
	static const float MISSILE_HALF_WIDTH;
	// half the height of the missile (pixels)
	static const float MISSILE_HALF_HEIGHT;
	// amount of damage points every missile explosion deals
	static const float MISSILE_DAMAGE;
	// factor representing the speed of every missile
	static const float MISSILE_SPEED;
	// minimum amount of time between every missile shot
	static const float MISSILE_LOAD_TIME;

	// y coordinate of the center of every bomb, except bomblets, upon spawn (pixels)
	static const float BOMB_ORIGIN_Y;
	// represents minimum value of x coordinate of the center of any bomb, at any time (pixels)
	static const float BOMB_ORIGIN_MIN_X;
	// represents maximum value of x coordinate of the center of any bomb, at any time (pixels)
	static const float BOMB_ORIGIN_MAX_X;
	// represents maximum value of y coordinate of the center of any bomb, at any time; i.e. when bombs y coordinate reaches this value they explode by themselves (pixels)
	static const float BOMB_TARGET_Y;
	// half the width of every bomb (pixels)
	static const float BOMB_HALF_WIDTH;
	// half the height of every bomb (pixels)
	static const float BOMB_HALF_HEIGHT;
	// amount of health points every new normal bomb has upon spawn
	static const float NORMAL_BOMB_HP;
	// amount of damage points every normal bomb explosion deals
	static const float NORMAL_BOMB_DAMAGE;
	// factor representing the speed of every normal bomb
	static const float NORMAL_BOMB_SPEED;
	// amount of points rewarded/cut upon normal bomb destruction/fall
	static const int NORMAL_BOMB_POINTS;
	// amount of health points every new nuclear bomb has upon spawn
	static const float NUCLEAR_BOMB_HP;
	// amount of damage points every nuclear bomb explosion deals
	static const float NUCLEAR_BOMB_DAMAGE;
	// factor representing the speed of every nuclear bomb
	static const float NUCLEAR_BOMB_SPEED;
	// amount of points rewarded/cut upon nuclear bomb destruction/fall
	static const int NUCLEAR_BOMB_POINTS;
	// amount of health points every new cluster bomb has upon spawn
	static const float CLUSTER_BOMB_HP;
	// amount of damage points every cluster bomb explosion deals
	static const float CLUSTER_BOMB_DAMAGE;
	// factor representing the speed of every cluster bomb
	static const float CLUSTER_BOMB_SPEED;
	// amount of points rewarded/cut upon cluster bomb destruction/fall
	static const int CLUSTER_BOMB_POINTS;
	// amount of health points every new bomblet has upon spawn
	static const float BOMBLET_HP;
	// amount of damage points every bomblet explosion deals
	static const float BOMBLET_DAMAGE;
	// factor representing the speed of every bomblet
	static const float BOMBLET_SPEED;
	// number of bomblets spawned after the destruction of cluster bomb in the air
	static const int BOMBLETS_SPAWNED;
	// amount of points cut upon bomblet fall
	static const int BOMBLET_POINTS;
	// amount of health points every new napalm bomb has upon spawn
	static const float NAPALM_BOMB_HP;
	// amount of damage points every napalm bomb explosion deals
	static const float NAPALM_BOMB_DAMAGE;
	// factor representing the speed of every napalm bomb
	static const float NAPALM_BOMB_SPEED;
	static const int NAPALM_BOMB_POINTS;
	// amount of health points every new rod of god has upon spawn
	static const float ROD_BOMB_HP;
	// amount of damage points every rod of god explosion deals
	static const float ROD_BOMB_DAMAGE;
	// factor representing the speed of every rod of god
	static const float ROD_BOMB_SPEED;
	// amount of points rewarded/cut upon rod of god destruction/fall
	static const int ROD_BOMB_POINTS;

	// duration of propagation of every explosion; i.e. amount of time between explosion appearing to achieving its maximum explosion radius (seconds)
	static const float EXPLOSION_PROPAGATION_TIME;
	// duration of the final stage of every explosion; final stage is when explosion radius is at its maximum (seconds)
	static const float EXPLOSION_FINAL_TIME;
	// initial radius of every explosion (pixels)
	static const float EXPLOSION_INITIAL_RADIUS;
	// final radius of every normal bomb explosion (pixels)
	static const float NORMAL_EXPLOSION_FINAL_RADIUS;
	// final radius of every nuclear bomb explosion (pixels)
	static const float NUCLEAR_EXPLOSION_FINAL_RADIUS;
	// final radius of every cluster bomb explosion (pixels)
	static const float CLUSTER_EXPLOSION_FINAL_RADIUS;
	// final radius of every bomblet explosion (pixels)
	static const float BOMBLET_EXPLOSION_FINAL_RADIUS;
	// final radius of every napalm bomb explosion (pixels)
	static const float NAPALM_EXPLOSION_FINAL_RADIUS;
	// final radius of every rod of god explosion (pixels)
	static const float ROD_EXPLOSION_FINAL_RADIUS;
	// number of stages every explosion goes through from its initial to achieve maximum radius
	static const int EXPLOSION_STAGES;
	// value representing increase in radius of the normal bomb explosion in every stage of the explosion, except final (pixels)
	static const float NORMAL_EXPLOSION_RADIUS_GROWTH;
	// value representing increase in radius of the nuclear bomb explosion in every stage of the explosion, except final (pixels)
	static const float NUCLEAR_EXPLOSION_RADIUS_GROWTH;
	// value representing increase in radius of the cluster bomb explosion in every stage of the explosion, except final (pixels)
	static const float CLUSTER_EXPLOSION_RADIUS_GROWTH;
	// value representing increase in radius of the bomblet explosion in every stage of the explosion, except final (pixels)
	static const float BOMBLET_EXPLOSION_RADIUS_GROWTH;
	// value representing increase in radius of the napalm bomb explosion in every stage of the explosion, except final (pixels)
	static const float NAPALM_EXPLOSION_RADIUS_GROWTH;
	// value representing increase in radius of the rod of god explosion in every stage of the explosion, except final (pixels)
	static const float ROD_EXPLOSION_RADIUS_GROWTH;
	// duration of every stage, except final, of every explosion
	static const float EXPLOSION_STAGE_TIME;

	// duration of propagation of the flash appearing after every missile shot; i.e. amount of time between the flash appearing to achieving its maximum size (seconds)
	static const float FLASH_PROPAGATION_TIME;
	// initial size of every missile shot flash (pixels)
	static const float FLASH_INITIAL_RADIUS;
	// final size of every missile shot flash (pixels)
	static const float FLASH_FINAL_RADIUS;
	// number of stages every missile shot flash goes through from its initial to achieve maximum size
	static const int FLASH_STAGES;
	// value representing increase in size of the missile shot flash in every stage of the it (pixels)
	static const float FLASH_RADIUS_GROWTH;
	// duration of every stage of every missile shot flash
	static const float FLASH_STAGE_TIME;

	// duration of propagation of the destruction appearing after every launcher/building collapse; i.e. amount of time between the destruction appearing to achieving its maximum size (seconds)
	static const float DESTRUCTION_PROPAGATION_TIME;
	// initial size of launcher/building destruction (pixels)
	static const float DESTRUCTION_INITIAL_RADIUS;
	// final size of launcher/building destruction (pixels)
	static const float DESTRUCTION_FINAL_RADIUS;
	// number of stages every launcher/building destruction goes through from its initial to achieve maximum size
	static const int DESTRUCTION_STAGES;
	// value representing increase in size of the launcher/building destruction in every stage of the it (pixels)
	static const float DESTRUCTION_RADIUS_GROWTH;
	// duration of every stage of every launcher/building destruction
	static const float DESTRUCTION_STAGE_TIME;

	// Intro

	// y coordinate of the top of the introduction bar at the start of every game (pixels)
	static const float INTRO_BAR_TOP;
	// y coordinate of the bottom of the introduction bar at the start of every game (pixels)
	static const float INTRO_BAR_BOTTOM;
	// height of the introduction bar at the start of every game (pixels)
	static const float INTRO_BAR_HEIGHT;
	// y coordinate of the top of the introduction text at the start of every game (pixels)
	static const float INTRO_TOP;
	// height of the introduction text at the start of every game (pixels)
	static const float INTRO_HEIGHT;
	// duration of the introduction at the start of every game (seconds)
	static const float INTRO_TIME;
	// number of stages that introduction at the start of every game goes through
	static const int INTRO_STAGES;
	// duration of each stage of the introduction at the start of every game
	static const float INTRO_STAGE_TIME;
	// change in color in each introduction stage
	static const float INTRO_BACKGROUND_SHIFT;
	// change in color in each introduction stage
	static const float INTRO_TEXT_SHIFT;

	// Summary

	// x coordinate of the left of the summary dialog popup (pixels)
	static const float SUMMARY_DIALOG_LEFT;
	// y coordinate of the top of the summary dialog popup (pixels)
	static const float SUMMARY_DIALOG_TOP;
	// x coordinate of the right of the summary dialog popup (pixels)
	static const float SUMMARY_DIALOG_RIGHT;
	// y coordinate of the bottom of the summary dialog popup (pixels)
	static const float SUMMARY_DIALOG_BOTTOM;
	// x coordinate of the left of the summary dialog popup's title (pixels)
	static const float SUMMARY_TITLE_TOP;
	// height of the summary dialog popup's title (pixels)
	static const float SUMMARY_TITLE_HEIGHT;
	// height of the summary dialog popup's title-subtitles separator (pixels)
	static const float SUMMARY_SEPARATOR_HEIGHT;
	// x coordinate of the left of the summary dialog popup's title-subtitles separator (pixels)
	static const float SUMMARY_SEPARATOR_LEFT;
	// y coordinate of the top of the summary dialog popup's title-subtitles separator (pixels)
	static const float SUMMARY_SEPARATOR_TOP;
	// x coordinate of the right of the summary dialog popup's title-subtitles separator (pixels)
	static const float SUMMARY_SEPARATOR_RIGHT;
	// y coordinate of the bottom of the summary dialog popup's title-subtitles separator (pixels)
	static const float SUMMARY_SEPARATOR_BOTTOM;
	// x coordinate of the left of the summary dialog popup's subtitles (pixels)
	static const float SUMMARY_TEXT_LEFT;
	// y coordinate of the top of the summary dialog popup's subtitles (pixels)
	static const float SUMMARY_TEXT_TOP;
	// width of the summary dialog popup's subtitles (pixels)
	static const float SUMMARY_TEXT_WIDTH;
	// height of the summary dialog popup's subtitles (pixels)
	static const float SUMMARY_TEXT_HEIGHT;
	// x coordinate of the left of the summary dialog popup's score label (pixels)
	static const float SUMMARY_SCORE_LEFT;
	// y coordinate of the top of the summary dialog popup's score label (pixels)
	static const float SUMMARY_SCORE_TOP;
	// height of the summary dialog popup's score label (pixels)
	static const float SUMMARY_SCORE_HEIGHT;
	// x coordinate of the left of the summary dialog popup's score number (pixels)
	static const float SUMMARY_SCORE_NUM_LEFT;
	// y coordinate of the top of the summary dialog popup's score number (pixels)
	static const float SUMMARY_SCORE_NUM_TOP;
	// height of the summary dialog popup's score number (pixels)
	static const float SUMMARY_SCORE_NUM_HEIGHT;
	// x coordinate of the left of the summary dialog popup's highscore label (pixels)
	static const float SUMMARY_HIGHSCORE_LEFT;
	// y coordinate of the top of the summary dialog popup's highscore label (pixels)
	static const float SUMMARY_HIGHSCORE_TOP;
	// height of the summary dialog popup's highscore label (pixels)
	static const float SUMMARY_HIGHSCORE_HEIGHT;
	// x coordinate of the left of the summary dialog popup's highscore number (pixels)
	static const float SUMMARY_HIGHSCORE_NUM_LEFT;
	// y coordinate of the top of the summary dialog popup's highscore number (pixels)
	static const float SUMMARY_HIGHSCORE_NUM_TOP;
	// height of the summary dialog popup's highscore number (pixels)
	static const float SUMMARY_HIGHSCORE_NUM_HEIGHT;
	// x coordinate of the left of the first summary dialog popup's score star icon (pixels)
	static const float SUMMARY_SCORE_STAR_LEFT;
	// y coordinate of the top of every summary dialog popup's score star icon (pixels)
	static const float SUMMARY_SCORE_STAR_TOP;
	// x coordinate of the right of the first summary dialog popup's score star icon (pixels)
	static const float SUMMARY_SCORE_STAR_RIGHT;
	// y coordinate of the bottom of every summary dialog popup's score star icon (pixels)
	static const float SUMMARY_SCORE_STAR_BOTTOM;
	// horizontal space (width included) between every pair of summary dialog popup's score star icons
	static const float SUMMARY_SCORE_STAR_SPACE;
	// x coordinate of the left of the first summary dialog popup's highscore star icon (pixels)
	static const float SUMMARY_HIGHSCORE_STAR_LEFT;
	// y coordinate of the top of every summary dialog popup's highscore star icon (pixels)
	static const float SUMMARY_HIGHSCORE_STAR_TOP;
	// x coordinate of the right of the first summary dialog popup's highscore star icon (pixels)
	static const float SUMMARY_HIGHSCORE_STAR_RIGHT;
	// y coordinate of the bottom of every summary dialog popup's highscore star icon (pixels)
	static const float SUMMARY_HIGHSCORE_STAR_BOTTOM;
	// horizontal space (width included) between every pair of summary dialog popup's highscore star icons
	static const float SUMMARY_HIGHSCORE_STAR_SPACE;
	// number of stars representing summary dialog popup's score and highscore
	static const int SUMMARY_STAR_NUM;
	// width of every summary dialog popup's button (pixels)
	static const float SUMMARY_BUTTON_WIDTH;
	// space between every pair of summary dialog popup's buttons (pixels)
	static const float SUMMARY_BUTTON_SPACE;
	// x coordinate of the left of the summary dialog popup's REPLAY button (pixels)
	static const float SUMMARY_REPLAY_LEFT;
	// y coordinate of the top of the summary dialog popup's REPLAY button (pixels)
	static const float SUMMARY_REPLAY_TOP;
	// x coordinate of the left of the summary dialog popup's MENU button (pixels)
	static const float SUMMARY_MENU_LEFT;
	// y coordinate of the top of the summary dialog popup's MENU button (pixels)
	static const float SUMMARY_MENU_TOP;
	// x coordinate of the left of the summary dialog popup's NEXT button (pixels)
	static const float SUMMARY_NEXT_LEFT;
	// y coordinate of the top of the summary dialog popup's NEXT button (pixels)
	static const float SUMMARY_NEXT_TOP;
};

