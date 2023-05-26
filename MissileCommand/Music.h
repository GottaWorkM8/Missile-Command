#pragma once

#include <Windows.h>
#include <mmsystem.h>
#include <vector>
#include <thread>
#include <string>

class Music {
public:
	static const LPCWSTR playMenu;
	static const LPCWSTR playLevel;
	static const LPCWSTR playMissile;
	static const LPCWSTR playExplosion;
	static const LPCWSTR playBomb;
	static const LPCWSTR stopMenu;


	static void musicMenu();
	static void musicLevel();
	static void musicClear();
	static void musicExploxion();
	static void musicMissle();
	static void StopAllSounds();

	static void PlaySounds(const std::string& filePath);
};

