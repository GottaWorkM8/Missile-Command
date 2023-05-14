#include "Music.h"

const LPCWSTR Music::playMenu = L"play musicMenu.wav";
const LPCWSTR Music::stopMenu = L"stop musicMenu.wav";
const LPCWSTR Music::playLevel = L"play musicLevel.wav";
const LPCWSTR Music::playMissile = L"play musicMissile.wav";
const LPCWSTR Music::playExploxion = L"play musicExploxion.wav";

void Music::musicMenu() 
{
	mciSendString(playMenu, NULL, 0, 0);
}

void Music::musicLevel()
{
	mciSendString(playLevel, NULL, 0, 0);
}

void Music::musicClear()
{
	mciSendString(stopMenu, NULL, 0, NULL);
}

void Music::musicExploxion()
{
	mciSendString(playExploxion, NULL, 0, 0);
}

void Music::musicMissle()
{
	mciSendString(playMissile, NULL, 0, 0);
}