#define ASLIB_INCLUDE_DL
#include "AsLib.hpp"

//dir_move
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
//dir
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
//move
enum :size_t
{
	MOB_STOP,//静止
	MOB_MOVE1,//左足
	MOB_MOVE2,//真ん中
	MOB_MOVE3,//右足
	MOB_MOVE4,//真ん中
};

const size_t mobMoveDirect(const size_t mob_direct_id,const size_t mob_move_id)
{
	switch (mob_move_id)
	{
	case MOB_STOP:
		switch (mob_direct_id) {
		case MOB_DOWN:return MOB_DOWN_STOP;
		case MOB_UP:return MOB_UP_STOP;
		case MOB_LEFT:return MOB_LEFT_STOP;
		case MOB_RIGHT:return MOB_RIGHT_STOP;
		case MOB_LEFT_UP:return MOB_LEFT_UP_STOP;
		case MOB_RIGHT_UP:return MOB_RIGHT_UP_STOP;
		case MOB_LEFT_DOWN:return MOB_LEFT_DOWN_STOP;
		case MOB_RIGHT_DOWN:return MOB_RIGHT_DOWN_STOP;
		}
		break;
	case MOB_MOVE1:
		switch (mob_direct_id) {
		case MOB_DOWN:return MOB_DOWN_MOVE1;
		case MOB_UP:return MOB_UP_MOVE1;
		case MOB_LEFT:return MOB_LEFT_MOVE1;
		case MOB_RIGHT:return MOB_RIGHT_MOVE1;
		case MOB_LEFT_UP:return MOB_LEFT_UP_MOVE1;
		case MOB_RIGHT_UP:return MOB_RIGHT_UP_MOVE1;
		case MOB_LEFT_DOWN:return MOB_LEFT_DOWN_MOVE1;
		case MOB_RIGHT_DOWN:return MOB_RIGHT_DOWN_MOVE1;
		}
		break;
	case MOB_MOVE2:
		switch (mob_direct_id) {
		case MOB_DOWN:return MOB_DOWN_STOP;
		case MOB_UP:return MOB_UP_STOP;
		case MOB_LEFT:return MOB_LEFT_STOP;
		case MOB_RIGHT:return MOB_RIGHT_STOP;
		case MOB_LEFT_UP:return MOB_LEFT_UP_STOP;
		case MOB_RIGHT_UP:return MOB_RIGHT_UP_STOP;
		case MOB_LEFT_DOWN:return MOB_LEFT_DOWN_STOP;
		case MOB_RIGHT_DOWN:return MOB_RIGHT_DOWN_STOP;
		}
		break;
	case MOB_MOVE3:
		switch (mob_direct_id) {
		case MOB_DOWN:return MOB_DOWN_MOVE2;
		case MOB_UP:return MOB_UP_MOVE2;
		case MOB_LEFT:return MOB_LEFT_MOVE2;
		case MOB_RIGHT:return MOB_RIGHT_MOVE2;
		case MOB_LEFT_UP:return MOB_LEFT_UP_MOVE2;
		case MOB_RIGHT_UP:return MOB_RIGHT_UP_MOVE2;
		case MOB_LEFT_DOWN:return MOB_LEFT_DOWN_MOVE2;
		case MOB_RIGHT_DOWN:return MOB_RIGHT_DOWN_MOVE2;
		}
		break;
	case MOB_MOVE4:
		switch (mob_direct_id) {
		case MOB_DOWN:return MOB_DOWN_STOP;
		case MOB_UP:return MOB_UP_STOP;
		case MOB_LEFT:return MOB_LEFT_STOP;
		case MOB_RIGHT:return MOB_RIGHT_STOP;
		case MOB_LEFT_UP:return MOB_LEFT_UP_STOP;
		case MOB_RIGHT_UP:return MOB_RIGHT_UP_STOP;
		case MOB_LEFT_DOWN:return MOB_LEFT_DOWN_STOP;
		case MOB_RIGHT_DOWN:return MOB_RIGHT_DOWN_STOP;
		}
		break;
	}
	return 0;
}

const bool mobMoveSet(size_t& move_id_, size_t& count, const size_t move_max = 6)
{
	switch (move_id_)
	{
	case MOB_STOP:
		++move_id_;
		return true;
	case MOB_MOVE1:
	case MOB_MOVE2:
	case MOB_MOVE3:
		++count;
		if (count >= move_max) {
			count = 0;
			++move_id_;
		}
		return true;
	case MOB_MOVE4:
		++count;
		if (count >= move_max) {
			count = 0;
			move_id_ = MOB_MOVE1;
		}
		return true;
	}
	return false;
}

//ダンジョンのサンプルプログラム
int32_t asMain()
{
	//管理クラス
	MainControl mc(u8"Simple Counter", Pos2(1000, 1000), BG_COLOR);

	AnimeMainData feri(1, asLoadTex("Picture/ikari.png", 6, 4));

	//size_t id = MOB_DOWN_STOP;
	size_t dir_id = MOB_DOWN;
	size_t move_id = MOB_STOP;
	size_t count = 0;

	while (asLoop())
	{
		updateKey();

		

		constexpr Pos2 w_pos2(64, 32);
		static worldMap w(w_pos2);
		static bool is_w = true;
		if (is_w) { w.rand().randC(100); is_w = false; }

		constexpr PosA4R pl2(7.5f, 8.5f, 1.0f, 1.0f);
		static PosA4R pl(5.5f, 5.5f, 1.0f, 1.0f);
		constexpr PosA4R map_p(0.0f, 0.0f, 5.0f, 10.0f);
		static MapView mv(map_p, 'y');

		pl.y += mouseWheel();
		
		constexpr float fps = 1.0f;
		if (moveMobCross(fps, pl)) {
			mobMoveSet(move_id, count);
		}
		else move_id = MOB_STOP;


		if (asKey(Keyboard_UpArrow)) dir_id = MOB_UP;
		else if (asKey(Keyboard_DownArrow)) dir_id = MOB_DOWN;
		else if (asKey(Keyboard_LeftArrow)) dir_id = MOB_LEFT;
		else if (asKey(Keyboard_RightArrow)) dir_id = MOB_RIGHT;

		mv.setMob(pl, w_pos2);
		mv.draw(&w.col[0], w_pos2);

		mv.draw(pl2, w_pos2, ColorRGBA(0, 255, 0, 255));
		mv.draw(PosA4R(5.5f, 5.5f, 1.0f, 1.0f), w_pos2, ColorRGBA(0, 205, 50, 255));
		mv.draw(PosA4R(0.5f, 0.5f, 1.0f, 1.0f), w_pos2, ColorRGBA(0, 255, 0, 255));
		mv.draw(pl, w_pos2, feri, mobMoveDirect(dir_id, move_id));

}

	return 0;
}