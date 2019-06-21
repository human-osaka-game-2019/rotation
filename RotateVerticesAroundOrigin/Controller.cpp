#include "Controller.h"

/***********************************************************************/
// Public Methods
/***********************************************************************/

HRESULT Controller::Initialize(HWND hWnd, Renderer* pRenderer) {
	m_pRenderer = pRenderer;

	HRESULT hr = DirectInput8Create(GetModuleHandle(NULL), DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)& m_pDirectInput, NULL);
	if (FAILED(hr)) {
		return hr;
	}

	hr = m_pDirectInput->CreateDevice(GUID_SysKeyboard, &m_pKeyDevice, NULL);
	if (FAILED(hr)) {
		return hr;
	}

	hr = m_pKeyDevice->SetDataFormat(&c_dfDIKeyboard);
	if (FAILED(hr)) {
		return hr;
	}

	hr = m_pKeyDevice->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND);
	if (FAILED(hr)) {
		return hr;
	}

	m_pKeyDevice->Acquire();
	return S_OK;
}

void Controller::Release() {
	m_pKeyDevice->Release();
	m_pDirectInput->Release();
}

void Controller::Update() {
	HRESULT hr = m_pKeyDevice->Acquire();
	if ((hr == DI_OK) || (hr == S_FALSE)) {
		BYTE diks[256];
		m_pKeyDevice->GetDeviceState(sizeof(diks), &diks);

		if (diks[DIK_LEFT] & 0x80) {
			m_pRenderer->Rotate(-10);
		}
		if (diks[DIK_RIGHT] & 0x80) {
			m_pRenderer->Rotate(10);
		}
	}
}
