#include "Music.h"

const std::string Music::MISSILE_FILEPATH = "soundMissile.wav";;
const std::string Music::EXPLOSION_FILEPATH = "soundExplosion.wav";;
const wchar_t* Music::PLAY_MENU_CMD = L"play musicMenu.wav";
const wchar_t* Music::STOP_MENU_CMD = L"stop musicMenu.wav";
const wchar_t* Music::PLAY_LEVEL_CMD = L"play musicLevel.wav";
const wchar_t* Music::STOP_LEVEL_CMD = L"stop musicLevel.wav";

void Music::PlaySounds(const std::string& filepath) {

	std::thread soundThread([filepath]() {
		PlaySoundA(filepath.c_str(), NULL, SND_FILENAME | SND_ASYNC);
		});
	soundThread.detach();
}

void Music::PlayMenu() {

	mciSendString(PLAY_MENU_CMD, NULL, 0, NULL);
}

void Music::PlayLevel() {

	mciSendString(PLAY_LEVEL_CMD, NULL, 0, NULL);
}

void Music::PlayExplosion() {

	PlaySounds(EXPLOSION_FILEPATH);
}

void Music::PlayMissile() {

	PlaySounds(MISSILE_FILEPATH);
}

void Music::ClearSounds() {

	mciSendString(STOP_MENU_CMD, NULL, 0, NULL);
	mciSendString(STOP_LEVEL_CMD, NULL, 0, NULL);

	std::thread stopThread([]() {
		PlaySoundA(nullptr, NULL, SND_ASYNC);
		});
	stopThread.detach();
}
