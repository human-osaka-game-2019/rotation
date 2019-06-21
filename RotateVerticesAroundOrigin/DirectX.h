#ifndef DIRECTX_H_
#define DIRECTX_H_

#include <d3dx9.h>

#include "Renderer.h"
#include "Controller.h"

/// <summary>
/// DirectX�I�u�W�F�N�g�N���X
/// </summary>
class DirectX {
public:
	/// <summary>
	/// ������
	/// </summary>
	/// <param name="hWnd">�E�B���h�E�n���h��</param>
	/// <param name="pRenderer">�`��N���X�̃C���X�^���X</param>
	/// <param name="pController">����N���X�̃C���X�^���X</param>
	/// <returns>����������</returns>
	HRESULT Initialize(HWND hWnd, Renderer* pRenderer, Controller* pController);

	/// <summary>
	/// ���\�[�X���������
	/// </summary>
	void Release();

private:
	LPDIRECT3D9 m_pDirectX;
	Renderer* m_pRenderer;
	Controller* m_pController;
};

#endif // !DIRECTX_H_

