#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <Windows.h>
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>

#include "Renderer.h"

/// <summary>
/// ユーザ操作処理クラス
/// </summary>
class Controller {
public:
	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name="hWnd">ウィンドウハンドル</param>
	/// <param name="pRenderer">描画クラスのインスタンス</param>
	/// <returns>初期化結果</returns>
	HRESULT Initialize(HWND hWnd, Renderer* pRenderer);

	/// <summary>
	/// リソースを開放する
	/// </summary>
	void Release();

	/// <summary>
	/// ユーザ操作による状態更新
	/// </summary>
	void Update();

private:
	LPDIRECTINPUT8 m_pDirectInput;
	LPDIRECTINPUTDEVICE8 m_pKeyDevice;
	Renderer* m_pRenderer;
};

#endif // !CONTROLLER_H_
