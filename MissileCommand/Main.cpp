#include <iostream>
#include "Window.h"

int main() {

	std::cout << "Creating Window\n";

	Window* window = new Window();
	bool running = true;

	while (running) {

		if (window->ProcessMessages()) {

			std::cout << "Closing Window\n";
			running = false;	
		}

		Sleep(10);
	}

	delete window;

	return 0;
}