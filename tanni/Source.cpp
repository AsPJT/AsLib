#define ASLIB_INCLUDE_DL
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

//アニメID
enum :size_t {
	NUM_ANIME,
};

//アニメUIのID
enum :size_t {
	TITLE_ANIMEUI,
	NUM_ANIMEUI,
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
	mc.AddScene(START_SCENE, startScene, {100,100,200});
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

	mc.animeAdd("anime.png", 4);
}

//画像読み込み
inline void UI_Init(MC& mc)
{
	mc.textureUI_Add(KURO_TEXTURE, 200, { 200,200,500,500 });
	mc.textureUI_Add(GAHAKU_TEXTURE, 255, { 0,0,200,200 });

	mc.animeUI_Add(NUM_ANIME, 200, { 0,0,400,400 });
	mc.animeUI_Add(NUM_ANIME, 200, { 50,50,400,400 });
}

//開始画面
void startScene(MC& mc)
{

	//while (mc.isLoop() && AsLoop())
	//{
		mc.anime(NUM_ANIME);
	//}
	//mc.loopEnd();

	//描画レイヤー
	mc.texture(GAHAKU_TEXUI);

	asBatteryDraw({ 700,700,200,300 });

	//命令レイヤー
	if (mc.upTex0(GAHAKU_TEXUI)) mc.scene(MAIN_SCENE);
}

//メイン画面
void mainScene(MC& mc)
{

	mc.texture(GAHAKU2_TEXUI);

	//命令レイヤー
	if (mc.upTex0(GAHAKU2_TEXUI)) mc.scene(LOGO_SCENE1);
}

//終了画面
void endScene(MC& mc)
{
	mc.texture(GAHAKU_TEXUI);

	//mc.clickTex(KURO_TEXTURE);
}

//タイトルロゴ1
void logoScene1(MC& mc)
{
	//mc.logoAnime(TITLE_ANIMEUI, 600, 1700, 2000, START_SCENE);
	//mc.anime(NUM_ANIME);
	mc.logoTex(GAHAKU_TEXTURE, 600, 1700, 2000, START_SCENE);
	if (mc.isUp()) mc.scene(START_SCENE);
}

void logoScene2(MC& mc)
{
	mc.logoTex(GAHAKU_TEXTURE, 1000, 2000, 3000, LOGO_SCENE2);
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
	MC mc(u8"Simple Counter", FULL_SCREEN_POS, BG_COLOR);

	//読み込み
	sceneInit(mc);
	textureInit(mc);
	UI_Init(mc);

	//初期シーン
	mc.scene(LOGO_SCENE1);
	
	//メインループ
	while (mc.isLoop()) mc.scenePlay();

	return 0;
}