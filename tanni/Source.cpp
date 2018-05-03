#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		return -1;        // エラーが起きたら直ちに終了
	}

	LoadGraph("a.jpg", TRUE);

	while (CheckHitKeyAll() == 0)
	{
		// メッセージループに代わる処理をする
		if (ProcessMessage() == -1)
		{
			break;        // エラーが起きたらループを抜ける
		}
	}

	DxLib_End();

	return 0;
}