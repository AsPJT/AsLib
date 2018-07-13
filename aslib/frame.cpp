#define ASLIB_INCLUDE_DL
#include "AsLib.hpp"
//#include "AsFrameWorks.hpp"
//
//struct AsMainApp : public AsBaseApp {
//	//-----------------------------------
//	//変数
//	//-----------------------------------
//	
//	PosL4 aaa{ 100, 100, 100, 100 };
//	int b = 0;
//	int32_t winp = 80;
//
//	TextureWindow window;
//
//	//-----------------------------------
//	//関数
//	//-----------------------------------
//
//	//開始
//	void asInit() {
//		window(9,asLoadTexture(u8"win2.png", 3, 3));
//	}
//	//更新
//	void asUpdate() {
//		//++aaa.x;
//		if(asKey(Keyboard_UpArrow)) winp += 1;
//		else if (asKey(Keyboard_DownArrow)) winp -= 1;
//	}
//	//描画
//	void asDraw() {
//		//asRect(Pos4(aaa), Color(255, 255, 255, 255));
//
//		window.drawWindow(Pos4(200, 200, 800, 400),Pos2(winp));
//
//	}
//	//終了
//	void asExit() {}
//};

int32_t asMain()
{
	MainControl mc(u8"AsFrameWorks", Pos2(960,540), BG_COLOR);
	int32_t winp = 40;

	TextureWindow window(9, asLoadTexture(u8"win2.png", 3, 3));
	window.setString32(u8"こんにちはあいうえおかきくけこ");

	FontMainData f(asMakeFont(30, u8"07ラノベPOP"));

	//asStop();

	while (asLoop()) {
		winp += mouseWheel();
		window.drawWindow(PosA4(500, 400, 800, 200), Pos2(winp)).update(5).writeString().printString(f);
	}

	//return asRunApp(mc, new AsMainApp());
	return 0;
}