#define ASLIB_INCLUDE_DL
#include "AsLib.hpp"

int32_t asMain()
{
	MainControl mc(u8"AsRPG", Pos2(560, 700));

	//マップテクスチャ
	AsTexture empty_texture(u8"p/empty.png");
	AsTexture crystal1_texture(u8"p/crystal1.png");
	AsTexture crystal2_texture(u8"p/crystal2.png");

	//マップ管理
	AsTextureMapArray tma;
	tma.add(empty_texture);
	tma.add(crystal1_texture);
	tma.add(crystal2_texture);

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
	}
	constexpr PosA4F pl2(7.5f, 8.5f, 1.0f, 1.0f);
	static PosA4F pl(0.5f, 0.5f, 1.0f, 1.0f);

	constexpr PosA4F map_p(0.0f, 0.0f, 5.0f, 20.0f);
	AsMapView mv(map_p, 'y');
	mv.setMap(w_pos2);
	constexpr float fps = 0.2f;

	while (asLoop())
	{
		pl.y += mouseWheel();
		if (moveMobCross(fps, pl)) mobMoveSet(move_id, count);
		else move_id = MOB_STOP;
		if (asKeyUp()) dir_id = MOB_UP;
		else if (asKeyDown()) dir_id = MOB_DOWN;
		else if (asKeyLeft()) dir_id = MOB_LEFT;
		else if (asKeyRight()) dir_id = MOB_RIGHT;

		mv.setMob(pl, w_pos2);
		mv.draw(&w.col[0], w_pos2);
		mv.draw(pl2, w_pos2, Color(0, 255, 0, 255));
		mv.draw(PosA4F(5.5f, 5.5f, 1.0f, 1.0f), w_pos2, Color(0, 205, 50, 255));
		mv.draw(PosA4F(0.5f, 0.5f, 1.0f, 1.0f), w_pos2, Color(0, 255, 0, 255));
		mv.draw(pl, w_pos2, feri, mobMoveDirect(dir_id, move_id));
	}
	return 0;
}