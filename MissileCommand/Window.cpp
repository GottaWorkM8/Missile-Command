#include "Window.h"

const wchar_t* Window::CLASS_NAME = L"Window";

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	switch (uMsg) {

	case WM_LBUTTONDOWN:
		Game::ChooseTarget(hWnd);
		break;

	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

Window::Window(): hInstance(GetModuleHandle(nullptr)) {

	WNDCLASS wndClass = {};
	wndClass.lpszClassName = CLASS_NAME;
	wndClass.hInstance = hInstance;
	wndClass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.lpfnWndProc = WindowProc;

	RegisterClass(&wndClass);
	
	DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;

	float width = 700;
	float height = 700;
	
	RECT rect;
	rect.left = (GetSystemMetrics(SM_CXSCREEN) - width) / 2;
	rect.right = rect.left + width;	
	rect.top = (GetSystemMetrics(SM_CYSCREEN) - height) / 2;
	rect.bottom = rect.top + height;

	AdjustWindowRect(&rect, style, false);

	hWnd = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, CLASS_NAME, L"Missile Command", style,
		rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, NULL, NULL, hInstance, NULL);

	graphics = Graphics(&hWnd);
	graphics.Init();

	ShowWindow(hWnd, SW_SHOW);

	std::thread gameThread = std::thread(Game::Run);
	gameThread.detach();
}
 
Window::~Window() {

	UnregisterClass(CLASS_NAME, hInstance);
}

bool Window::ProcessMessages() {
	
	MSG msg = {};

	while (msg.message != WM_QUIT) {

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
		
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		else {

			graphics.BeginDraw();
			graphics.DrawGame(game);
			graphics.EndDraw();
		}
	}

	return true;
}