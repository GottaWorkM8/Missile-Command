#include "Window.h"

int main() {

	Window* window = new Window();
	bool running = true;

	while (running) {

		if (window->ProcessMessages())
			running = false;

		Sleep(10);
	}

	delete window;

	return 0;
}