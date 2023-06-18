#include "Window.h"

// Main method being the starting point of the application
int main() {

	Window* window = new Window();
	bool running = true;

	while (running) {

		if (window->ProcessMessages())
			running = false;

		Sleep(1);
	}

	delete window;

	return 0;
}