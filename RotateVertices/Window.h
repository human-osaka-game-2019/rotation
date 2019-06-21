#ifndef WINDOW_H_
#define WINDOW_H_

#include <Windows.h>

/// <summary>
/// ウィンドウに関する処理を行うクラス
/// </summary>
class Window {
public:
	/// <summary>
	/// ウィンドウを生成する
	/// </summary>
	/// <returns>ウィンドウハンドル</returns>
	HWND Create();

	/// <summary>
	/// ウィンドウメッセージを処理する
	/// </summary>
	/// <param name="pMsg">メッセージ構造体へのポインタ</param>
	/// <returns>メッセージを処理した場合はtrue、メッセージ未受信だった場合はfalse</returns>
	bool ProcessWindowMessage(MSG* pMsg);

private:
	/// <summary>
	/// ウィンドウタイトル文字列を取得する
	/// </summary>
	/// <returns>ウィンドウタイトル</returns>
	static const TCHAR* Title() { return TEXT("原点(画面左上)で回転"); }

	/// <summary>
	/// ウィンドウの幅
	/// </summary>
	static const int WIDTH = 1280;

	/// <summary>
	/// ウィンドウの高さ
	/// </summary>
	static const int HEIGHT = 720;
};

#endif // WINDOW_H_
