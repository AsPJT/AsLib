//ゲームエンジン
#define DX_NON_USING_NAMESPACE_DXLIB
#include "DxLib.h"

#define AS_USING_GAME_PAD_MAX
constexpr size_t ASLIB_GAME_PAD_MAX = 16;
#include "AsLib.hpp"

enum :size_t {
	START_SCENE
};

enum :size_t {
	GAHAKU_TEXTURE
};

void StartScene(MainControl& mc)
{
	mc.texture_render[0].draw();
	//mc.texDraw(GAHAKU_TEXTURE);
	return;
}

//メイン関数
int32_t AsMain()
{
	MainData as = asReadInit("b.txt", "あいうえお", {720,720}, BG_COLOR);
	MainControl mc(as);

	mc.AddScene(START_SCENE, StartScene);

	//初期シーンをスタート画面にする
	mc.sceneSelect(START_SCENE);

	Texture astest("gahaku.png");
	asPrint("%d ",astest.draw());
	asStop();

	//gahaku
	//mc.textureAdd("gahaku.png");

	//メインループ
	//while (mc.isLoop()) mc.scenePlay();

	////画面上部のUI情報
	//constexpr int UI_DIVIDE_SIZE = 10;
	//constexpr int UI_DIVIDE_STR_SIZE = 20;

	//const Pos2 UI_size = asReadPos2("a.txt");

	//ColorRGB UI_color = { 165, 212, 173 };

	////フォント
	//std::string select_font = "Meiryo UI";
	//AsFont font_handle = asMakeFont(as.windowSize().y / UI_DIVIDE_STR_SIZE, select_font);

	//Texture texture("mihon.jpg");

	//ColorRGBA color1 = { 100,0,0,255 }, color2 = { 0,100,0,255 }, color3 = color1;
	//Pos4 p1 = { 0,0,100,100 }, p2 = { 100,0,200,100 }, p3 = { 200,0,300,100 }, p4 = { 300,0,400,100 };

	//asRect(p1, color1);
	//asRect(p2, color2);

	//color3 = color1 + color2;
	//++color3;
	//asRect(p3, color3);

	//color3 = color1 * color2;
	//asRect(p4, color3);

	//std::string key_string = asKeyInput({200,200});
	//asPrint(key_string);

	//while (AsLoop())
	//{

	//	//asPrint(font_handle, "こんにちは！ようこそ！", pos2_0, white);

	//	//texture(pos4R_all, as.windowSize(), TEXTURE_RATIO_X).draw();
	//}

	//asStop();

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