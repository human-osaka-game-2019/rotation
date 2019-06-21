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

	return S_OK;
}

void Renderer::Release() {
	m_pTexture->Release();
	m_pDevice->Release();
}

void Renderer::Draw() {
	// ���l�^�ƂȂ钸�_���
	CUSTOMVERTEX original[4]
	{
		{ 0.0f, 0.0f },
		{ 186.0f, 0.0f },
		{ 186.0f, 126.0f },
		{ 0.0f, 126.0f }
	};

	// ��]�p��degree����radian�ɕϊ����Asin��cos�̒l���Z�o
	double radian = m_Degree * M_PI / 180;
	float sine = (float)sin(radian);
	float cosine = (float)cos(radian);

	// �ݒ肳�ꂽ��]�p�ɉ����A���_�𒆐S�Ƃ��ĉ�]������
	CUSTOMVERTEX elephant[4];
	for (int i = 0; i < sizeof(elephant) / sizeof(CUSTOMVERTEX); i++) {
		// ��]���x = ��]�O��x�Ecos�� - ��]�O��y�Esin��
		elephant[i].x = original[i].x * cosine - original[i].y * sine;

		// ��]���y = ��]�O��x�Esin�� + ��]�O��y�Ecos�� 
		elephant[i].y = original[i].x * sine + original[i].y * cosine;

		elephant[i].z = 0.0f;
		elephant[i].rhw = 1.0f;
		elephant[i].color = 0xFFFFFFFF;
		elephant[i].tu = (original[i].x == 0.0f ? 0.0f : 1.0f);
		elephant[i].tv = (original[i].y == 0.0f ? 0.0f : 1.0f);
	}

	//��ʂ̏���
	m_pDevice->Clear(0, NULL,
		D3DCLEAR_TARGET,
		D3DCOLOR_XRGB(0x00, 0x00, 0x00),
		1.0, 0);

	//�`��̊J�n
	m_pDevice->BeginScene();
	m_pDevice->SetTexture(0, m_pTexture);
	m_pDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, elephant, sizeof(CUSTOMVERTEX));

	m_pDevice->EndScene();
	m_pDevice->Present(NULL, NULL, NULL, NULL);
}