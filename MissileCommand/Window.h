#pragma once

#include <Windows.h>
#include <thread>
#include <atomic>
#include "Graphics.h"
#include "resource.h"

class Window {

	static const wchar_t* CLASS_NAME;
	HINSTANCE hInstance;
	HWND hWnd;
	Graphics graphics;

	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

public:

	Window();
	Window(const Window&) = delete;
	~Window();

	Window& operator = (const Window&) = delete;

	bool ProcessMessages();
};

