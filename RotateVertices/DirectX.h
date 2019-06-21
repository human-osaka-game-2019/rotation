#ifndef DIRECTX_H_
#define DIRECTX_H_

#include <d3dx9.h>

#include "Renderer.h"
#include "Controller.h"

/// <summary>
/// DirectXオブジェクトクラス
/// </summary>
class DirectX {
public:
	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name="hWnd">ウィンドウハンドル</param>
	/// <param name="pRenderer">描画クラスのインスタンス</param>
	/// <param name="pController">操作クラスのインスタンス</param>
	/// <returns>初期化結果</returns>
	HRESULT Initialize(HWND hWnd, Renderer* pRenderer, Controller* pController);

	/// <summary>
	/// リソースを解放する
	/// </summary>
	void Release();

private:
	LPDIRECT3D9 m_pDirectX;
	Renderer* m_pRenderer;
	Controller* m_pController;
};

#endif // !DIRECTX_H_

