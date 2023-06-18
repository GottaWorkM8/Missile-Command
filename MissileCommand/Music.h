#pragma once

#include <Windows.h>
#include <mmsystem.h>
#include <vector>
#include <thread>
#include <string>

/// <summary>
/// Class responsible for providing audio for many events as well as background music
/// </summary>
class Music {

public:

	static const std::string MISSILE_FILEPATH;
	static const std::string EXPLOSION_FILEPATH;
	static const std::string SHORT_EXPLOSION_FILEPATH;
	static const wchar_t* PLAY_MENU_CMD;
	static const wchar_t* STOP_MENU_CMD;
	static const wchar_t* PLAY_LEVEL_CMD;
	static const wchar_t* STOP_LEVEL_CMD;

	// Plays audio file specified by its name as an argument
	static void PlaySounds(const std::string& filepath);
	// Plays menu background music
	static void PlayMenu();
	// Plays level background music
	static void PlayLevel();
	// Plays the explosion sound
	static void PlayExplosion();
	// Plays the missile shot sound
	static void PlayMissile();
	// Clears all sounds, including background music
	static void ClearSounds();
};

