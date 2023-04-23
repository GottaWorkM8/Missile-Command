#include <Windows.h>
#include <d2d1.h>
#include <wincodec.h>
#include "Color.h"
#include "Bitmapper.h"
#include "Game.h"

class StartWindow {

	HWND* hWnd;
	ID2D1Factory* factory;
	ID2D1HwndRenderTarget* renderTarget;
	ID2D1Bitmap* mapBitmap;
	ID2D1Bitmap* startButtonBitmap;
	//ID2D1SolidColorBrush* startButtonBrush;

public:

	StartWindow();
	StartWindow(HWND* hWnd);
	~StartWindow();

	void BeginDraw() { renderTarget->BeginDraw(); }
	void EndDraw() { renderTarget->EndDraw(); }
	bool Init();
	void ClearScreen(Color color);
	void DrawGame(Game game);
};

