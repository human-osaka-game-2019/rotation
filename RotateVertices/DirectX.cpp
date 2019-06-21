#include "DirectX.h"

/***********************************************************************/
// Public Methods
/***********************************************************************/

HRESULT DirectX::Initialize(HWND hWnd, Renderer* pRenderer, Controller* pController) {
	m_pRenderer = pRenderer;
	m_pController = pController;

	m_pDirectX = Direct3DCreate9(D3D_SDK_VERSION);
	if (m_pDirectX == NULL) {
		return E_FAIL;
	}

	D3DDISPLAYMODE displayMode;
	m_pDirectX->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &displayMode);

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(D3DPRESENT_PARAMETERS));

	d3dpp.BackBufferFormat = displayMode.Format;
	d3dpp.BackBufferCount = 1;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.Windowed = TRUE;

	LPDIRECT3DDEVICE9 pDevice;

	if (FAILED(m_pDirectX->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp, &pDevice))) {
		return E_FAIL;
	}

	if (FAILED(m_pRenderer->Initialize(pDevice))) {
		return E_FAIL;
	}

	if (FAILED(m_pController->Initialize(hWnd, m_pRenderer))) {
		return E_FAIL;
	}

	return S_OK;
}

void DirectX::Release() {
	m_pRenderer->Release();
	m_pDirectX->Release();
}
