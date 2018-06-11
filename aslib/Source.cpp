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
	mc.AddScene(START_SCENE, startScene, ColorRGB(100,100,200));
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
	mc.textureUI_Add(KURO_TEXTURE, 200, Pos4(200, 200, 500, 500));
	mc.textureUI_Add(GAHAKU_TEXTURE, 255, Pos4(0, 0, 200, 200));

	mc.animeUI_Add(NUM_ANIME, 200, Pos4(0, 0, 400, 400));
	mc.animeUI_Add(NUM_ANIME, 200, Pos4(50, 50, 400, 400));
}

void batteryScene(MC& mc)
{
	asPrint("%d ",mc.battery.Power());
}

//開始画面
void startScene(MC& mc)
{

	mc.anime(NUM_ANIME);

	//描画レイヤー
	mc.texture(GAHAKU2_TEXUI);

	mc.battery.draw();
	if (mc.battery.Touch()) batteryScene(mc);

	//asBatteryDraw({ 700,200,200,300 });

	static Pos2 p_{ 300,200 };
	mc.vecFont[0].changeSize(mc.wheel());
	//mc.vecFont[0].draw(p_, u8"アニメーション%d",1);
	mc.vecFont[0].drawAt(p_, u8"アニメーション%d",1);



	static TextureMainData texa(AsLoadTex("gahaku.png"));
	//static const Pos8 a = Pos4(300, 300, 600, 700);
	static const Pos8 a = Pos8(300,600,300,300,600,600,600,300);
	static const Pos8 b = (Pos8(Pos4(a)));
	//b(a, 1.57);
	//Pos8 b = Pos8(a, 1.57);
	static double c= 0.0;

	texa.draw(Pos4(a), 150);
	//Pos8 b(a, 1.7);
	texa.draw(Pos8(a,c), 150);
	//c += 0.04;

	Circle(Pos2(700, 400), 50).draw();
	Circle(mc.pos(), 60).draw(ColorRGBA(255, 0, 0, 127));

	//命令レイヤー
	if (mc.upTex0(GAHAKU2_TEXUI)) mc.scene(LOGO_SCENE1);
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
	mc;
}

void logoScene4(MC& mc)
{
	mc;
}

//メイン関数
int32_t AsMain()
{
	//管理クラス
	MC mc(u8"Simple Counter", Pos2(1000, 800), BG_COLOR);

	mc.battery.make(mc.asPos4({ 0.9f,0.02f,0.98f,0.3f }));
	mc.fontAdd(60);

	//TextureMainData texa(AsLoadTex("kuro.png"));
	//Pos8 a = Pos4(300, 300, 600, 700);
	//Pos8 b=(Pos8(Pos4(a)));
	//b(a, 1.57);
	//Pos8 b = Pos8(a, 1.57);

	//texa.draw(Pos4(a),150);
	//Pos8 b(a, 1.7);
	//texa.draw(Pos4(b),150);
	//asStop();

	////読み込み
	sceneInit(mc);
	textureInit(mc);
	UI_Init(mc);

	//初期シーン
	mc.scene(LOGO_SCENE1);
	
	//メインループ
	while (mc.sceneLoop()) mc.scenePlay();

	return 0;
}