#define ASLIB_INCLUDE_DL
#include "AsLib.hpp"
#include "AsFrameWorks.hpp"

struct AsMainApp : public AsBaseApp {
	//-----------------------------------
	//変数
	//-----------------------------------
	
	PosL4 aaa{ 100, 100, 100, 100 };
	int b = 0;

	//-----------------------------------
	//関数
	//-----------------------------------

	//開始
	void asInit() {
		
	}
	//更新
	void asUpdate() {
		++aaa.x;
	}
	//描画
	void asDraw() {
		asRect(Pos4(aaa), ColorRGBA(255, 255, 255, 255));
	}
	//終了
	void asExit() {}
};

int32_t asMain()
{
	MainControl mc(u8"AsFrameWorks", Pos2(1000, 1000), BG_COLOR);
	return asRunApp(mc, new AsMainApp());
}