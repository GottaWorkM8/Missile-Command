#pragma once
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

class Music {
public:
	static const LPCWSTR playMenu;
	static const LPCWSTR playLevel;
	static const LPCWSTR playMissile;
	static const LPCWSTR playExplosion;
	static const LPCWSTR stopMenu;


	static void musicMenu();
	static void musicLevel();
	static void musicClear();
	static void musicExploxion();
	static void musicMissle();
};

