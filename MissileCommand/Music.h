#pragma once
#include <Windows.h>
#include <SDL_mixer.h>
#include <mmsystem.h>
#include <vector>
#pragma comment(lib, "winmm.lib")

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
	static void musicBomb();
	static void musicMissle();


	void addSoundEffect(const char* path);

	void playSoundEffect(const int which) const;

private:

	std::vector<Mix_Chunk*> mSoundEffectBank;
};

