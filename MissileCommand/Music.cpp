#include "Music.h"
#include <SDL.h>
#include <iostream>

const LPCWSTR Music::playMenu = L"play musicMenu.wav";
const LPCWSTR Music::stopMenu = L"stop musicMenu.wav";
const LPCWSTR Music::playLevel = L"play musicLevel.wav";
const LPCWSTR Music::playMissile = L"play musicMissile.wav";
const LPCWSTR Music::playExplosion = L"play musicExploxion.wav";

void Music::musicMenu() 
{
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        printf("B³¹d inicjalizacji SDL: %s\n", SDL_GetError());
    }

    // Inicjalizacja SDL_mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("B³¹d inicjalizacji SDL_mixer: %s\n", Mix_GetError());
    }

    // Wczytanie pliku dŸwiêkowego
    Mix_Chunk* sound = Mix_LoadWAV("musicMenu.wav");
    if (!sound) {
        printf("B³¹d wczytywania pliku dŸwiêkowego: %s\n", Mix_GetError());
    }

    // Odtwarzanie dŸwiêku
    if (Mix_PlayChannel(-1, sound, 0) == -1) {
        printf("B³¹d odtwarzania dŸwiêku: %s\n", Mix_GetError());
    }

    // Czekanie na zakoñczenie odtwarzania
    while (Mix_Playing(-1))
        SDL_Delay(100);

    // Zwolnienie zasobów
    Mix_FreeChunk(sound);
    Mix_CloseAudio();
    SDL_Quit();

}

void Music::musicLevel()
{
	mciSendString(playLevel, NULL, 0, NULL);
}

void Music::musicClear()
{
	mciSendString(stopMenu, NULL, 0, NULL);
}

void Music::musicExploxion()
{
	mciSendString(Music::playExplosion, NULL, 0, 0);
}

void Music::musicMissle()
{
	mciSendString(Music::playMissile, NULL, 0, 0);
}
