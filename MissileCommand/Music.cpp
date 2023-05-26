#include "Music.h"

const std::string Music::MENU_FILEPATH = "musicMenu.wav";
const std::string Music::LEVEL_FILEPATH = "musicLevel.wav";;
const std::string Music::MISSILE_FILEPATH = "soundMissile.wav";;
const std::string Music::EXPLOSION_FILEPATH = "soundExplosion.wav";;
const wchar_t* Music::PLAY_MENU_CMD = L"play musicLevel.wav";

void Music::PlaySounds(const std::string& filepath) {

	std::thread soundThread([filepath]() {
		PlaySoundA(filepath.c_str(), NULL, SND_FILENAME | SND_ASYNC);
		});

	soundThread.detach();
}

void Music::PlayMenu() {

	PlaySounds(MENU_FILEPATH);
}

void Music::PlayLevel() {

	mciSendString(PLAY_MENU_CMD, NULL, 0, NULL);
}

void Music::PlayExplosion() {

	PlaySounds(EXPLOSION_FILEPATH);
}

void Music::PlayMissile() {

	PlaySounds(MISSILE_FILEPATH);
}

void Music::ClearSounds() {

	std::thread stopThread([]() {
		PlaySoundA(nullptr, NULL, SND_ASYNC);
		});

	stopThread.detach();
}
