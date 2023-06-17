#pragma once

#include <chrono>

/// <summary>
/// Class representing every timer in the application and these make sure that animations progress smoothly and constant periods between events are maintained
/// </summary>
class Timer {
	
	std::chrono::system_clock::time_point startTime, currentTime, lastDeltaTick;
	std::chrono::duration<float> deltaTime;

public:

	Timer();

	// Sets the timestamp of the beginning, that is used as reference to calculate elapsed time, to current time
	void Restart();
	// Returns time in milliseconds that passed from the last call of GetDeltaTime method (if there were none returns time passed from object initialization)
	float GetDeltaTime();
	// Returns time in milliseconds that passed trom the last call of Restart method (if there were none returns time passed from object initialization)
	float GetElapsedTime();
	// Increments the timestamp of the beginning, that is used as reference to calculate elapsed time, by the given value 
	// (used to correct the timer when the game is paused)
	void IncrementStartTime(std::chrono::milliseconds duration);
};

