#include "Music.h"

const LPCWSTR Music::playMenu = L"play musicMenu.wav";
const LPCWSTR Music::stopMenu = L"stop musicMenu.wav";
const LPCWSTR Music::playLevel = L"play musicLevel.wav";
const LPCWSTR Music::playMissile = L"play musicMissile.wav";
const LPCWSTR Music::playExplosion = L"play musicExploxion.wav";
const LPCWSTR Music::playBomb = L"play musicBomb.wav";

void Music::PlaySounds(const std::string& filePath) 
{
	std::thread soundThread([filePath]() {
		PlaySoundA(filePath.c_str(), NULL, SND_FILENAME | SND_ASYNC);
		});

	soundThread.detach();
}

void Music::StopAllSounds()
{
	std::thread stopThread([]() {
		PlaySoundA(nullptr, NULL, SND_ASYNC);
		});

	stopThread.detach();
}

void Music::musicMenu() 
{
	PlaySounds("musicMenu.wav");
}

void Music::musicLevel()
{
	mciSendString(playLevel, NULL, 0, NULL);
}

void Music::musicClear()
{
	StopAllSounds();
}

void Music::musicExploxion()
{
	PlaySounds("musicExploxion.wav");
}

void Music::musicMissle()
{
	PlaySounds("musicMissile.wav");
}
