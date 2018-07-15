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
	//640,360
	MainControl mc(u8"Voice", Pos2(960,540), BG_COLOR);
	int32_t winp = 21;

	//win2//windowa
	TextureWindow window(9, asLoadTexture(u8"win3.png", 3, 3));
	Texture window_ui(asLoadTexture(u8"cho.png"));
	window.readSetString32(u8"str.txt");

	Texture ani(32, asLoadTexture(u8"pet.png", 8,4));

	//TextureWindow chara(asLoadTexture(u8"f.png"));
	FontMainData font(asMakeFont(0, u8"07にくまるフォント"), 0, u8"07にくまるフォント");
	window.setFont(font);
	window.setSound(u8"f");
	window.setName(u8"不思議な池袋");
	window.setPos(Pos4F(0.02f, 0.65f, 0.98f, 0.98f).ratio());
	window.setFrame(winp);
	window.setLine(4);
	window.setFastForward(true);

	Counter count;
	Counter count2;

	asStop();
	while (asLoop()) {
		updateKey();
		count.update(asKey(Keyboard_a));
		count2.update(asKey(Keyboard_s));
		//window.setFrame(winp += mouseWheel());
		//chara.draw(Pos4(200,0,500,360));
		if (window.isWindow()) window.drawWindow().update(8).writeString().updateEnd(1).drawEndAnime(ani).playSound().printString().printName().next(count.Up());
		if (count2.Up()) {
			//window.readSetString32(u8"str.txt");
			window.initWindow();
		}
	}

	//return asRunApp(mc, new AsMainApp());
	return 0;
}