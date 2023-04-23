#include "Window.h"
#include <iostream>

const wchar_t* Window::CLASS_NAME = L"Window";
static bool gameStart = false;
static unsigned int first = 0;

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	switch (uMsg) {

	case WM_KEYDOWN:
		if (wParam == VK_RETURN) {
			gameStart = true;
			if (first == 0) first++;
		}
		break;

	case WM_LBUTTONDOWN:
		if (gameStart == true) {
			Game::ChooseTarget(hWnd);
		}
		else {
			bool result = Game::ChooseOption(hWnd);
			if (result) {
				gameStart = true;
				if (first == 0) first++;
			}
		}
		break;

	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}

	return 0;
}

Window::Window(): hInstance(GetModuleHandle(nullptr)){

	WNDCLASS wndClass = {};
	wndClass.lpszClassName = CLASS_NAME;
	wndClass.hInstance = hInstance;
	wndClass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.lpfnWndProc = WindowProc;

	RegisterClass(&wndClass);
	
	DWORD style = WS_POPUP | WS_VISIBLE;

	int width = 1600;
	int height = 900;
	
	RECT rect;
	rect.left = (GetSystemMetrics(SM_CXSCREEN) - width) / 2;
	rect.right = rect.left + width;	
	rect.top = (GetSystemMetrics(SM_CYSCREEN) - height) / 2;
	rect.bottom = rect.top + height;

	AdjustWindowRect(&rect, style, false);

	HDC hDC = ::GetWindowDC(NULL);
	SetWindowPos(hWnd, NULL, 0, 0, GetDeviceCaps(hDC, HORZRES), 
		GetDeviceCaps(hDC, VERTRES), SWP_FRAMECHANGED);

	hWnd = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, CLASS_NAME, L"Missile Command", style,
		rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, NULL, NULL, hInstance, NULL);


	startWindow = StartWindow(&hWnd);
	startWindow.Init();

	graphics = Graphics(&hWnd);
	graphics.Init();

	ShowWindow(GetConsoleWindow(), SW_HIDE);
	ShowWindow(hWnd, SW_SHOW);
}
 
Window::~Window() {

	UnregisterClass(CLASS_NAME, hInstance);
}

void Window::StartGame() {
	Window::gameThread = std::thread(Game::Run);
	Window::gameThread.detach();
}

bool Window::ProcessMessages() {
	
	MSG msg = {};

	while (msg.message != WM_QUIT) {

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
		
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		else {
			if (gameStart) {
				if (first == 1) {
					Window::StartGame();
					first++;
				}
				graphics.BeginDraw();
				graphics.DrawGame(game);
				graphics.EndDraw();
			}

			else {

				startWindow.BeginDraw();
				startWindow.DrawGame(game);
				startWindow.EndDraw();

			}
			if (Game::running == false) {
				DestroyWindow(hWnd);
			}


		}
	}

	return true;
}