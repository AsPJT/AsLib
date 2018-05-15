//ゲームエンジン
#define DX_NON_USING_NAMESPACE_DXLIB
#include "DxLib.h"

#define AS_USING_GAME_PAD_MAX
constexpr size_t ASLIB_GAME_PAD_MAX = 16;
#include "AsLib.hpp"

//シーン
enum :size_t {
	START_SCENE
};

//画像
enum :size_t {
	KURO_TEXTURE
};

//スタート画面
void StartScene(MainControl& mc)
{
	mc.texDraw(KURO_TEXTURE);
	return;
}

//シーンコントロール初期化
inline void sceneInit(MainControl& mc)
{
	mc.AddScene(START_SCENE, StartScene);
}

//画像コントロール初期化
inline void textureInit(MainControl& mc)
{
	mc.textureAdd("kuro.png");
}

//メイン関数
int32_t AsMain()
{
	//基本設定
	MainData as = asReadInit("b.txt", "あいうえお", {720,720}, BG_COLOR);
	
	//管理クラス
	MainControl mc(as);

	//シーン追加
	sceneInit(mc);

	//画像追加
	textureInit(mc);

	//初期シーンをスタート画面にする
	mc.sceneSelect(START_SCENE);

	//メインループ
	while (mc.isLoop()) mc.scenePlay();

	//終了処理
	asEnd();

	return 0;
}





//----------------------------------------------------------------------------------------------------





//各ライブラリのメイン関数
#if defined(__DXLIB) //DxLib
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	return int(AsMain());
}
#elif defined(SIV3D_INCLUDED) //Siv3D
void Main()
{
	AsMain();
	return;
}
#else //Console
int main()
{
	return int(AsMain());
}
#endif