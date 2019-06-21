#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <Windows.h>
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>

#include "Renderer.h"

/// <summary>
/// ���[�U���쏈���N���X
/// </summary>
class Controller {
public:
	/// <summary>
	/// ������
	/// </summary>
	/// <param name="hWnd">�E�B���h�E�n���h��</param>
	/// <param name="pRenderer">�`��N���X�̃C���X�^���X</param>
	/// <returns>����������</returns>
	HRESULT Initialize(HWND hWnd, Renderer* pRenderer);

	/// <summary>
	/// ���\�[�X���J������
	/// </summary>
	void Release();

	/// <summary>
	/// ���[�U����ɂ���ԍX�V
	/// </summary>
	void Update();

private:
	LPDIRECTINPUT8 m_pDirectInput;
	LPDIRECTINPUTDEVICE8 m_pKeyDevice;
	Renderer* m_pRenderer;
};

#endif // !CONTROLLER_H_
