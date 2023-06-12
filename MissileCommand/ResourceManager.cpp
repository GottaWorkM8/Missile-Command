#include "ResourceManager.h"

std::mutex ResourceManager::launcherMutex;
std::mutex ResourceManager::buildingsMutex;
std::mutex ResourceManager::missilesMutex;
std::mutex ResourceManager::bombsMutex;
std::mutex ResourceManager::explosionsMutex;
std::mutex ResourceManager::destructionsMutex;
std::mutex ResourceManager::flashesMutex;

std::mutex& ResourceManager::GetLauncherMutex() {
	return launcherMutex;
}

std::mutex& ResourceManager::GetBuildingsMutex() {
	return buildingsMutex;
}

std::mutex& ResourceManager::GetMissilesMutex() {
	return missilesMutex;
}

std::mutex& ResourceManager::GetBombsMutex() {
	return bombsMutex;
}

std::mutex& ResourceManager::GetExplosionsMutex() {
	return explosionsMutex;
}

std::mutex& ResourceManager::GetDestructionsMutex() {
	return destructionsMutex;
}

std::mutex& ResourceManager::GetFlashesMutex() {
	return flashesMutex;
}
