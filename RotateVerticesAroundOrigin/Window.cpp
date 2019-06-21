#include "Window.h"

/***********************************************************************/
// Global Methods
/***********************************************************************/

// ウィンドウプロシージャ
static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
	switch (msg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, msg, wp, lp);
}


/***********************************************************************/
// Public Methods
/***********************************************************************/

HWND Window::Create() {
	HINSTANCE hInstance = GetModuleHandle(NULL);
	const TCHAR* title = Title();

	WNDCLASS Wndclass;
	Wndclass.style = CS_HREDRAW | CS_VREDRAW;
	Wndclass.lpfnWndProc = WndProc;
	Wndclass.cbClsExtra = Wndclass.cbWndExtra = 0;
	Wndclass.hInstance = hInstance;
	Wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	Wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	Wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	Wndclass.lpszMenuName = NULL;
	Wndclass.lpszClassName = title;
	RegisterClass(&Wndclass);

	return CreateWindow(
		title,
		title,
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		WIDTH,
		HEIGHT,
		NULL,
		NULL,
		hInstance,
		NULL
	);
}

bool Window::ProcessWindowMessage(MSG* pMsg) {
	if (PeekMessage(pMsg, NULL, 0, 0, PM_REMOVE)) {
		TranslateMessage(pMsg);
		DispatchMessage(pMsg);
		return true;
	}

	return false;
}
