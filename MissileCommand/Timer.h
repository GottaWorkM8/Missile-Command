#pragma once

#include <chrono>

class Timer {
	
	std::chrono::system_clock::time_point startTime, currentTime, lastDeltaTick;
	std::chrono::duration<float> deltaTime;

public:

	Timer();

	void Restart();
	float GetDeltaTime();
	float GetElapsedTime();
};

