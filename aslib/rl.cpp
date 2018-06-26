#define ASLIB_INCLUDE_DL
#include "AsLib.hpp"

enum :size_t
{
	MOB_DOWN_MOVE1,
	MOB_DOWN_STOP,
	MOB_DOWN_MOVE2,
	MOB_LEFT_DOWN_MOVE1,
	MOB_LEFT_DOWN_STOP,
	MOB_LEFT_DOWN_MOVE2,
	MOB_LEFT_MOVE1,
	MOB_LEFT_STOP,
	MOB_LEFT_MOVE2,
	MOB_RIGHT_DOWN_MOVE1,
	MOB_RIGHT_DOWN_STOP,
	MOB_RIGHT_DOWN_MOVE2,
	MOB_RIGHT_MOVE1,
	MOB_RIGHT_STOP,
	MOB_RIGHT_MOVE2,
	MOB_LEFT_UP_MOVE1,
	MOB_LEFT_UP_STOP,
	MOB_LEFT_UP_MOVE2,
	MOB_UP_MOVE1,
	MOB_UP_STOP,
	MOB_UP_MOVE2,
	MOB_RIGHT_UP_MOVE1,
	MOB_RIGHT_UP_STOP,
	MOB_RIGHT_UP_MOVE2,
};

enum :size_t
{
	MOB_DOWN,
	MOB_UP,
	MOB_LEFT,
	MOB_RIGHT,
	MOB_LEFT_UP,
	MOB_RIGHT_UP,
	MOB_LEFT_DOWN,
	MOB_RIGHT_DOWN,
	MOB_CENTER,
};

enum :size_t
{
	MOB_STOP,//静止
	MOB_MOVE1,//左足
	MOB_MOVE2,//真ん中
	MOB_MOVE3,//右足
	MOB_MOVE4,//真ん中
};

//ダンジョンのサンプルプログラム
int32_t AsMain()
{
	//管理クラス
	MainControl mc(u8"Simple Counter", Pos2(1000, 1000), BG_COLOR);

	AnimeMainData feri(1, AsLoadTex("Picture/ikari.png", 6, 4));

	while (asLoop())
	{
		updateKey();

		

		constexpr Pos2 w_pos2(64, 32);
		static worldMap w(w_pos2);
		static bool is_w = true;
		if (is_w) { w.rand().randC(100); is_w = false; }

		constexpr PosA4R pl2(7.5f, 8.5f, 1.0f, 1.0f);
		static PosA4R pl(5.5f, 5.5f, 1.0f, 1.0f);
		constexpr PosA4R map_p(0.0f, 0.0f, 5.0f, 16.0f);
		static MapView mv(map_p, 'y');

		pl.y += mouseWheel();
		
		constexpr float fps = 1.0f;
		static size_t id = MOB_DOWN_STOP;
		moveMobCross(fps, pl);
		if (asKey(Keyboard_UpArrow)) id = MOB_UP_STOP;
		if (asKey(Keyboard_DownArrow)) id = MOB_DOWN_STOP;

		mv.setMob(pl, w_pos2);
		mv.draw(&w.col[0], w_pos2);

		mv.draw(pl2, w_pos2, ColorRGBA(0, 255, 0, 255));
		mv.draw(PosA4R(5.5f, 5.5f, 1.0f, 1.0f), w_pos2, ColorRGBA(0, 205, 50, 255));
		mv.draw(PosA4R(0.5f, 0.5f, 1.0f, 1.0f), w_pos2, ColorRGBA(0, 255, 0, 255));
		mv.draw(pl, w_pos2, feri, id);

}

	return 0;
}