#pragma once

#include <mutex>

/// <summary>
/// Class responsible for managing resources (launcher, buildings, missiles, bombs, explosions, destructions, flashes) 
/// and making sure there are no conficts resulting from multiple threads accessing the same resource
/// </summary>
class ResourceManager {

	static std::mutex launcherMutex;
	static std::mutex buildingsMutex;
	static std::mutex missilesMutex;
	static std::mutex bombsMutex;
	static std::mutex explosionsMutex;
	static std::mutex destructionsMutex;
	static std::mutex flashesMutex;

public:

	// Returns the pointer to the mutex managing the Launcher instance
	static std::mutex& GetLauncherMutex();
	// Returns the pointer to the mutex managing the Building instances
	static std::mutex& GetBuildingsMutex();
	// Returns the pointer to the mutex managing the Missile instances
	static std::mutex& GetMissilesMutex();
	// Returns the pointer to the mutex managing the Bomb instances
	static std::mutex& GetBombsMutex();
	// Returns the pointer to the mutex managing the Explosions instances
	static std::mutex& GetExplosionsMutex();
	// Returns the pointer to the mutex managing the Destruction instances
	static std::mutex& GetDestructionsMutex();
	// Returns the pointer to the mutex managing the Flash instances
	static std::mutex& GetFlashesMutex();
};

