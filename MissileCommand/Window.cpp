#include "Window.h"

const wchar_t* Window::CLASS_NAME = L"Window";
HCURSOR Window::hCursor = LoadCursorFromFile(L"radioactive-cursor.cur");
HCURSOR Window::hGameCursor = LoadCursorFromFile(L"radioactive-precision.ani");

LRESULT CALLBACK Window::WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	switch (uMsg) {

		case WM_LBUTTONDOWN:
			if (Menu::IsGameRunning())
				if (Game::IsPopupUp())
					Game::GetSummary()->HandlePress(hWnd);
				else Game::UpdateTarget(hWnd);
			else {
				if (Menu::IsHelpDisplayed())
					Menu::SetHelpDisplayed(false);
				else Menu::HandlePress(hWnd); }
			break;

		case WM_MOUSEMOVE:
			if (Menu::IsGameRunning()) {
				Game::UpdateLauncherCannon(hWnd);
				if (Game::IsPopupUp())
					Game::GetSummary()->HandleMove(hWnd); }
			else
				if (!Menu::IsHelpDisplayed())
					Menu::HandleMove(hWnd);
			break;

		case WM_SETCURSOR:
			if (Menu::IsGameRunning())
				SetCursor(hGameCursor);
			else SetCursor(hCursor);
			break;

		case WM_KEYDOWN:
			if (wParam == VK_ESCAPE) {
				if (Menu::IsGameRunning()) {
					if (!Game::IsFinished()) {
						if (Game::IsPausable()) {
							if (Game::IsPaused()) {
								if (Game::GetSummary()->IsDeletable())
									Game::SetPaused(false); }
							else Game::SetPaused(true); }}}}
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

Window::Window(): hInstance(GetModuleHandle(nullptr)) {

	WNDCLASS wndClass = {};
	wndClass.lpszClassName = CLASS_NAME;
	wndClass.hInstance = hInstance;
	wndClass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LOGO));
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

	graphics = Graphics(&hWnd);
	graphics.Init();


	Music::PlayMenu();

	GameSave::LoadFromFile();

	ShowWindow(GetConsoleWindow(), SW_HIDE);
	ShowWindow(hWnd, SW_SHOW);
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

			if (Menu::IsGameRunning())
				graphics.DrawGame();

			else {

				if (Menu::IsHelpDisplayed())
					graphics.DrawHelp();

				else graphics.DrawMenu();
			}

			graphics.EndDraw();
		}
	}

	return true;
}
