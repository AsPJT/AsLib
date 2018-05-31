//ゲームエンジン
#define DX_NON_USING_NAMESPACE_DXLIB
#include "DxLib.h"

#define AS_USING_GAME_PAD_MAX
constexpr size_t ASLIB_GAME_PAD_MAX = 16;
#include "AsLib.hpp"

//管理クラス省略
using MC = AsLib::MainControl;

//シーン関数
void startScene(MC& mc);
void mainScene(MC& mc);
void endScene(MC& mc);
void logoScene1(MC& mc);
void logoScene2(MC& mc);
void logoScene3(MC& mc);
void logoScene4(MC& mc);

//シーンID
enum :size_t {
	START_SCENE,
	MAIN_SCENE,
	END_SCENE,
	LOGO_SCENE1,
	LOGO_SCENE2,
	LOGO_SCENE3,
	LOGO_SCENE4,
};

//画像ID
enum :size_t {
	GAHAKU_TEXTURE,
	KURO_TEXTURE
};

//画像UIのID
enum :size_t {
	GAHAKU_TEXUI,
	GAHAKU2_TEXUI
};

//変数ID
enum :size_t {
	game_score,
};

struct Pet
{
	Pos2 pos;
	int32_t hp = 100;
	int32_t water = 100;
	int32_t status = 0;
};

//シーン読み込み
inline void sceneInit(MC& mc)
{
	mc.AddScene(START_SCENE, startScene);
	mc.AddScene(MAIN_SCENE, mainScene);
	mc.AddScene(END_SCENE, endScene);
	mc.AddScene(LOGO_SCENE1, logoScene1);
	mc.AddScene(LOGO_SCENE2, logoScene2);
	mc.AddScene(LOGO_SCENE3, logoScene3);
	mc.AddScene(LOGO_SCENE4, logoScene4);
}

//画像読み込み
inline void textureInit(MC& mc)
{
	mc.textureAdd("gahaku.png");
	mc.textureAdd("kuro.png");
}

//画像読み込み
inline void UI_Init(MC& mc)
{
	mc.textureUI_Add(KURO_TEXTURE, 200, { 200,200,500,500 });
	mc.textureUI_Add(GAHAKU_TEXTURE, 255, { 0,0,200,200 });
}

//開始画面
void startScene(MC& mc)
{
	std::vector<int32_t> gaccho;

	while (mc.isLoop() && AsLoop())
	{
		
	}
	mc.loopEnd();

	//描画レイヤー
	//mc.draw4(GAHAKU_TEXUI);

	//命令レイヤー
	//if (mc.isTexUI_Touch(GAHAKU_TEXUI)) mc.sceneSelect(MAIN_SCENE);
}

//メイン画面
void mainScene(MC& mc)
{

	mc.draw4(GAHAKU2_TEXUI);

	//命令レイヤー
	if (mc.isTexUI_Touch(GAHAKU2_TEXUI)) mc.sceneSelect(LOGO_SCENE1);
}

//終了画面
void endScene(MC& mc)
{
	mc.draw4(GAHAKU_TEXUI);

	//mc.clickTex(KURO_TEXTURE);
}

//タイトルロゴ1
void logoScene1(MC& mc)
{
	mc.drawLogoInOut(GAHAKU_TEXTURE, 1000, 2000, 3000, START_SCENE);
	//if (mc.isTouch()) mc.sceneSelect(START_SCENE);
}

void logoScene2(MC& mc)
{
	mc.drawLogoInOut(GAHAKU_TEXTURE, 1000, 2000, 3000, LOGO_SCENE2);
}

void logoScene3(MC& mc)
{
}

void logoScene4(MC& mc)
{
}

//メイン関数
int32_t AsMain()
{
	//管理クラス
	MC mc(u8"Simple Counter", asWindowSize({ 720,360 }), BG_COLOR);

	//読み込み
	sceneInit(mc);
	textureInit(mc);
	UI_Init(mc);

	//初期シーン
	mc.sceneSelect(LOGO_SCENE1);

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