#include "Renderer.h"

#define _USE_MATH_DEFINES
#include <math.h>

/***********************************************************************/
// Public Methods
/***********************************************************************/

HRESULT Renderer::Initialize(LPDIRECT3DDEVICE9 pDevice) {
	m_pDevice = pDevice;

	m_pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	m_pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	m_pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	m_pDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	m_pDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);

	m_pDevice->SetFVF(FVF);

	D3DXCreateTextureFromFile(
		m_pDevice,
		ImageFileName(),
		&m_pTexture);

	m_Degree = 0;
	m_Offset = { 640.0f, 360.0f };

	return S_OK;
}

void Renderer::Release() {
	m_pTexture->Release();
	m_pDevice->Release();
}

void Renderer::Draw() {
	// 元ネタとなる頂点情報
	CUSTOMVERTEX original[4]
	{
		{ -93.0f, -63.0f },
		{ 93.0f, -63.0f },
		{ 93.0f, 63.0f },
		{ -93.0f, 63.0f }
	};

	// 回転角をdegreeからradianに変換し、sinとcosの値を算出
	double radian = m_Degree * M_PI / 180;
	float sine = (float)sin(radian);
	float cosine = (float)cos(radian);

	// 設定された回転角に応じ、原点を中心として回転させる
	CUSTOMVERTEX elephant[4];
	for (int i = 0; i < sizeof(elephant) / sizeof(CUSTOMVERTEX); i++) {
		// 回転後のx = 回転前のx・cosθ - 回転前のy・sinθ
		elephant[i].x = original[i].x * cosine - original[i].y * sine;
		elephant[i].x += m_Offset.x;

		// 回転後のy = 回転前のx・sinθ + 回転前のy・cosθ 
		elephant[i].y = original[i].x * sine + original[i].y * cosine;
		elephant[i].y += m_Offset.y;

		elephant[i].z = 0.0f;
		elephant[i].rhw = 1.0f;
		elephant[i].color = 0xFFFFFFFF;
		elephant[i].tu = (i % 3 == 0 ? 0.0f : 1.0f);
		elephant[i].tv = (i < 2 ? 0.0f : 1.0f);
	}

	//画面の消去
	m_pDevice->Clear(0, NULL,
		D3DCLEAR_TARGET,
		D3DCOLOR_XRGB(0x00, 0x00, 0x00),
		1.0, 0);

	//描画の開始
	m_pDevice->BeginScene();
	m_pDevice->SetTexture(0, m_pTexture);
	m_pDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, elephant, sizeof(CUSTOMVERTEX));

	m_pDevice->EndScene();
	m_pDevice->Present(NULL, NULL, NULL, NULL);
}
