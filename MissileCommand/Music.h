#pragma once

#include <Windows.h>
#include <mmsystem.h>
#include <vector>
#include <thread>
#include <string>

/// <summary>description</summary>
class Music {

public:

	static const std::string MISSILE_FILEPATH;
	static const std::string EXPLOSION_FILEPATH;
	static const std::string SHORT_EXPLOSION_FILEPATH;
	static const wchar_t* PLAY_MENU_CMD;
	static const wchar_t* STOP_MENU_CMD;
	static const wchar_t* PLAY_LEVEL_CMD;
	static const wchar_t* STOP_LEVEL_CMD;

	static void PlaySounds(const std::string& filepath);
	static void PlayMenu();
	static void PlayLevel();
	static void PlayExplosion();
	static void PlayMissile();
	static void ClearSounds();
};

