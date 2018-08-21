#define ASLIB_INCLUDE_DL
#include "AsLib.hpp"

//void drawa(Texture& t_) {
//
//}

//void drawAll(const int t_) {
//
//}

int32_t asMain() {
	MainControl mc("Ascll_Texture", Pos2(540, 400));
	Texture a(u8"p/mushroom.png");
	//drawa(a);

	//int b=DxLib::LoadGraph(u8"p/mushroom.png");
	//int x, y;
	//DxLib::GetGraphSize(b, &x, &y);
	//

	a(PosL4(0, 0, 400, 400)).setID(0).setAlpha(150).drawAuto();

	//a.draw();
	asStop();

	return 0;
}