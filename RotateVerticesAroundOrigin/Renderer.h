#ifndef RENDERER_H_
#define RENDERER_H_

#include <Windows.h>
#include <d3dx9.h>

/// <summary>
/// �`��N���X
/// </summary>
class Renderer {
public:
	/// <summary>
	/// ������
	/// </summary>
	/// <param name="pDevice">�O���t�B�b�N�f�o�C�X</param>
	/// <returns>����������</returns>
	HRESULT Initialize(LPDIRECT3DDEVICE9 pDevice);

	/// <summary>
	/// ���\�[�X���J������
	/// </summary>
	void Release();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

	/// <summary>
	/// ��]
	/// </summary>
	/// <param name="degree">��]�p(��:�E���A��:�����</param>
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

