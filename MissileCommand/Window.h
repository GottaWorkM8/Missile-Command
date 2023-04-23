#pragma once

#include <Windows.h>
#include <thread>
#include <atomic>
#include "Graphics.h"
#include "Game.h"
#include "resource.h"
#include "StartWindow.h"

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

class Window {

	static const wchar_t* CLASS_NAME;
	HINSTANCE hInstance;
	HWND hWnd;
	Graphics graphics;
	StartWindow startWindow;
	Game game;
	std::thread gameThread;

public:

	Window();
	Window(const Window&) = delete;
	~Window();

	Window& operator = (const Window&) = delete;

	bool ProcessMessages();
	void StartGame();
};

