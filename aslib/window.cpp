#define ASLIB_INCLUDE_DL
#include "AsLib.hpp"
int32_t asMain()
{
	//640,360//960, 540//320,180
	MainControl mc(u8"Voice", Pos2(960, 540), BG_COLOR);

	int32_t winp = 21;
	FontMainData font(10, u8"07‚É‚­‚Ü‚éƒtƒHƒ“ƒg");
	//win2//windowa
	TextureWindow window(u8"win3.png", 3, 3);
	Texture window_ui(u8"cho.png");
	window.readSetString32(u8"str.txt");

	Texture ani(u8"pet.png", 8, 4);

	window.setFont(font);
	window.setSound(u8"f");
	window.setName(u8"‚ ‚¢‚¤‚¦‚¨");
	window.setPos(Pos4F(0.02f, 0.7f, 0.98f, 0.98f).ratio());
	window.setFrame(winp);
	window.setLine(4);
	window.setFastForward(true);

	asStop();
	while (asLoop()) {
		if (window.isWindow()) window.drawWindow().update(8).writeString().updateEnd(1).drawEndAnime(ani).playSound().printString().printName().next(asKeyA_Up());
		window.initWindow(asKeyY_Up());
	}
	return 0;
}