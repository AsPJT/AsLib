#define ASLIB_INCLUDE_DL
#include "AsLib.hpp"

//ダンジョンのサンプルプログラム
int32_t asMain()
{
	MainControl mc(u8"Simple Counter", Pos2(560, 700));

	//モンスター
	std::vector<AsTexture> monster;
	monster.push_back({ u8"Picture/ikari.png", 6, 4 });

	AsTexture feri(u8"Picture/ikari.png", 6, 4);

	AsTexture crystal1(u8"p/crystal1.png");

	size_t dir_id = MOB_DOWN;
	size_t move_id = MOB_STOP;
	size_t count = 0;

	constexpr Pos2 w_pos2(8, 8);
	worldMap w(w_pos2);
	bool is_w = true;

	if (is_w) {
		w.rand().randC(100); is_w = false;
		w.col[0] = { 255,255,255,255 };
		//w.col[32*64-1] = { 255,0,0,255 };
	}
	constexpr PosA4F pl2(7.5f, 8.5f, 1.0f, 1.0f);
	static PosA4F pl(0.5f, 0.5f, 1.0f, 1.0f);

	constexpr PosA4F map_p(0.0f, 0.0f, 5.0f, 20.0f);
	MapView mv(map_p, 'y');
	mv.setMap(w_pos2);

	while (asLoop())
	{




		pl.y += mouseWheel();

		constexpr float fps = 0.2f;
		if (moveMobCross(fps, pl)) mobMoveSet(move_id, count);
		else move_id = MOB_STOP;

		//DxLib::clsDx();
		//DxLib::printfDx("(%f,%f,%f,%f)", pl.x, pl.y, pl.w, pl.h);

		if (asKeyUp()) dir_id = MOB_UP;
		else if (asKeyDown()) dir_id = MOB_DOWN;
		else if (asKeyLeft()) dir_id = MOB_LEFT;
		else if (asKeyRight()) dir_id = MOB_RIGHT;
		//マップ描画の中心をプレイヤーの位置にセット
		mv.setMob(pl, w_pos2);
		mv.draw(&w.col[0], w_pos2);

		mv.draw(pl2, w_pos2, Color(0, 255, 0, 255));
		mv.draw(PosA4F(5.5f, 5.5f, 1.0f, 1.0f), w_pos2, Color(0, 205, 50, 255));
		mv.draw(PosA4F(0.5f, 0.5f, 1.0f, 1.0f), w_pos2, Color(0, 255, 0, 255));
		mv.draw(pl, w_pos2, feri, mobMoveDirect(dir_id, move_id));

	}

	return 0;
}