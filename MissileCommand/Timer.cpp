#include "Timer.h"

Timer::Timer() {

	startTime = currentTime = lastDeltaTick = std::chrono::system_clock::now();
	deltaTime = std::chrono::duration<float>(0);
}

void Timer::Restart() {

	startTime = std::chrono::system_clock::now();
}

float Timer::GetDeltaTime() {

	currentTime = std::chrono::system_clock::now();
	deltaTime = currentTime - lastDeltaTick;
	lastDeltaTick = currentTime;

	return deltaTime.count();
}

float Timer::GetElapsedTime() {

	currentTime = std::chrono::system_clock::now();
	std::chrono::duration<float> elapsedTime = currentTime - startTime;

	return elapsedTime.count();
}

void Timer::IncrementStartTime(std::chrono::milliseconds duration) {

	startTime += duration;
	lastDeltaTick += duration;
}
