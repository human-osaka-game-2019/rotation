#include<Windows.h>
#include<mmsystem.h>

#include "Window.h"
#include "DirectX.h"
#include "Renderer.h"
#include "Controller.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE fPrevInstance, PSTR IpCmdLine, int nCndShow) {
	Window window;
	HWND hWnd = window.Create();
	if (!hWnd) {
		return -1;
	}

	Renderer renderer;
	Controller controller;

	DirectX directX;
	if (FAILED(directX.Initialize(hWnd, &renderer, &controller))) {
		return -1;
	}

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	timeBeginPeriod(1);
	DWORD lastUpdated = timeGetTime();
	while (msg.message != WM_QUIT) {
		if (!window.ProcessWindowMessage(&msg)) {
			DWORD currentTime = timeGetTime();
			if (currentTime - lastUpdated >= 1000 / 60) {
				controller.Update();
				renderer.Draw();
				lastUpdated = currentTime;
			}
		}

		Sleep(1);
	}

 	timeEndPeriod(1);
	directX.Release();

	return 0;
}
