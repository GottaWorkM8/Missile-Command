#pragma once

#include <Windows.h>
#include <WinUser.h>
#include <Shlwapi.h>
#include <thread>
#include <atomic>
#include "Graphics.h"
#include "resource.h"
#include "Music.h"

/// <summary>
/// Class representing the application window, handles user inputs and provides a render target for the Graphics class
/// </summary>
class Window {

	static const wchar_t* CLASS_NAME;
	static HCURSOR hCursor;
	static HCURSOR hGameCursor;
	HINSTANCE hInstance;
	HWND hWnd;
	Graphics graphics;

	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

public:

	Window();
	Window(const Window&) = delete;
	~Window();

	Window& operator = (const Window&) = delete;

	// Processes messages from the operating system's message queue and handles them accordingly
	bool ProcessMessages();
};

