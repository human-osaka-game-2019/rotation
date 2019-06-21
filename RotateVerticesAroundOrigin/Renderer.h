#ifndef RENDERER_H_
#define RENDERER_H_

#include <Windows.h>
#include <d3dx9.h>

/// <summary>
/// 描画クラス
/// </summary>
class Renderer {
public:
	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name="pDevice">グラフィックデバイス</param>
	/// <returns>初期化結果</returns>
	HRESULT Initialize(LPDIRECT3DDEVICE9 pDevice);

	/// <summary>
	/// リソースを開放する
	/// </summary>
	void Release();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	/// <summary>
	/// 回転
	/// </summary>
	/// <param name="degree">回転角(正:右回り、負:左回り</param>
	void Rotate(int degree) { m_Degree += degree; }

private:
	struct CUSTOMVERTEX
	{
		FLOAT	x, y, z, rhw;
		DWORD	color;
		FLOAT	tu, tv;
	};

	LPDIRECT3DDEVICE9 m_pDevice;
	LPDIRECT3DTEXTURE9 m_pTexture;
	const TCHAR* ImageFileName() { return TEXT("Elephant.png"); }
	static const DWORD FVF = (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);
	int m_Degree;
};

#endif // !RENDERER_H_

