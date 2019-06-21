#ifndef WINDOW_H_
#define WINDOW_H_

#include <Windows.h>

/// <summary>
/// �E�B���h�E�Ɋւ��鏈�����s���N���X
/// </summary>
class Window {
public:
	/// <summary>
	/// �E�B���h�E�𐶐�����
	/// </summary>
	/// <returns>�E�B���h�E�n���h��</returns>
	HWND Create();

	/// <summary>
	/// �E�B���h�E���b�Z�[�W����������
	/// </summary>
	/// <param name="pMsg">���b�Z�[�W�\���̂ւ̃|�C���^</param>
	/// <returns>���b�Z�[�W�����������ꍇ��true�A���b�Z�[�W����M�������ꍇ��false</returns>
	bool ProcessWindowMessage(MSG* pMsg);

private:
	/// <summary>
	/// �E�B���h�E�^�C�g����������擾����
	/// </summary>
	/// <returns>�E�B���h�E�^�C�g��</returns>
	static const TCHAR* Title() { return TEXT("���_(��ʍ���)�ŉ�]"); }

	/// <summary>
	/// �E�B���h�E�̕�
	/// </summary>
	static const int WIDTH = 1280;

	/// <summary>
	/// �E�B���h�E�̍���
	/// </summary>
	static const int HEIGHT = 720;
};

#endif // WINDOW_H_
