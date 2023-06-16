#pragma once

#include <mutex>

/// <summary>description</summary>
class ResourceManager {

	static std::mutex launcherMutex;
	static std::mutex buildingsMutex;
	static std::mutex missilesMutex;
	static std::mutex bombsMutex;
	static std::mutex explosionsMutex;
	static std::mutex destructionsMutex;
	static std::mutex flashesMutex;

public:

	static std::mutex& GetLauncherMutex();
	static std::mutex& GetBuildingsMutex();
	static std::mutex& GetMissilesMutex();
	static std::mutex& GetBombsMutex();
	static std::mutex& GetExplosionsMutex();
	static std::mutex& GetDestructionsMutex();
	static std::mutex& GetFlashesMutex();
};

