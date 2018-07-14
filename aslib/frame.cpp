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

	MainControl mc(u8"Voice", Pos2(640,360), BG_COLOR);
	int32_t winp = 10;

	//win2//windowa
	TextureWindow window(9, asLoadTexture(u8"win3.png", 3, 3));
	Texture window_ui(asLoadTexture(u8"cho.png"));
	window.readSetString32(u8"str.txt");

	//TextureWindow chara(asLoadTexture(u8"f.png"));

	window.setSound(u8"f");
	window.setName(u8"name");
	window.setPos(Pos4F(0.02f, 0.65f, 0.98f, 0.98f).ratio());
	window.setFrame(winp);
	window.setLine(4);

	asStop();
	while (asLoop()) {
		updateKey();
		//window.setFrame(winp += mouseWheel());
		//chara.draw(Pos4(200,0,500,360));
		if (window.isWindow()) window.drawWindow().update(8).writeString().updateEnd(12).drawEndTexture(window_ui).playSound().printString().printName().next(asKey(Keyboard_a));
	}

	//return asRunApp(mc, new AsMainApp());
	return 0;
}