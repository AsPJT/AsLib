#define ASLIB_INCLUDE_DL
#include "AsLib.hpp"

int32_t asMain()
{
	//560, 700
	MainControl mc(u8"AsRPG", Pos2(1280,720));

	//アイテムUIの画像
	Texture item_ui(u8"p/itemUI.png");
	Texture item_ui2(u8"p/itemUI2.png");
	//アイテムの画像
	Texture mushroom_te(u8"p/mushroom.png");
	Texture mushroom2_te(u8"p/mushroom2.png");

	//アイテムデータ
	std::vector<Item> item;
	item.emplace_back(Item(nullptr, u8"Empty"));
	item.emplace_back(Item(&mushroom_te, 10, u8"mushroom"));
	item.emplace_back(Item(&mushroom2_te, 5, u8"mushroom2"));

	enum :size_t
	{
		aslib_item_empty,
		aslib_item_mushroom,
		aslib_item_mushroom2,
	};

	const PosA4 item_pos(Pos4F(0.45f, 0.7f, 0.55f, 0.9f).ratio());
	Font item_font(item_pos.w / 3, u8"Algerian");

	ShareItem share_item(8);
	share_item.push(0, aslib_item_mushroom, 5);
	share_item.push(1, aslib_item_mushroom2, 95);
	share_item.add(aslib_item_mushroom2, 25, item[aslib_item_mushroom2].stack_max);

	Inventory inv(item_ui, item_ui2, item_font, share_item, item_pos, 8, 0);

	constexpr Pos2 w_pos2(23, 27);

	//マップテクスチャ
	AsTexture crystal1_te(u8"p/crystal1.png");
	AsTexture crystal2_te(u8"p/crystal2.png");
	AsTexture anime_te(u8"p/anime.png", 4);
	AsTexture water_te(u8"p/mizu1.png", 4,10);

	//マップ管理
	AsTextureMapArray tma;
	tma.push(nullptr);
	tma.push(&crystal1_te);
	tma.push(&crystal2_te);
	tma.push(&anime_te);
	tma.push(&water_te, aslib_texture_map_field_type_wall);

	//マップ生成
	tma.resizeMap(w_pos2);
	//

	tma.setLayer(2, 1);
	//tma.randMap(1);

	//tma.putMap(1, 1);

	tma.mazeMap(4,0,1);

	//モンスター
	AsTexture feri(u8"Picture/ikari.png", 6, 4);

	size_t dir_id = MOB_DOWN;
	size_t move_id = MOB_STOP;
	size_t moving = MOB_CENTER;
	size_t count = 0;

	constexpr PosA4F pl2(7.5f, 8.5f, 1.0f, 1.0f);
	static PosA4F pl(1.0f, 1.0f, 1.0f, 1.0f);

	constexpr PosA4F map_p(0.0f, 0.0f, 5.0f, 10.0f);
	AsMapView mv(map_p, 'y');
	mv.setMap(w_pos2);
	constexpr float fps = 0.1f;

	while (asLoop())
	{
		tma.update();
		if (movingMobCross(fps, pl,moving) != MOB_CENTER) {
			mobMoveSet(move_id, count);
			directionMobCross(dir_id);
		}
		else move_id = MOB_STOP;

		mv.setMobView(pl, aslib_mob_walk_type_big);
		mv.draw(&tma);

		//mv.draw(pl2, w_pos2, Color(0, 255, 0, 255));
		//mv.draw(PosA4F(5.5f, 5.5f, 1.0f, 1.0f), w_pos2, Color(0, 205, 50, 255));
		//mv.draw(PosA4F(0.5f, 0.5f, 1.0f, 1.0f), w_pos2, Color(0, 255, 0, 255));
		mv.draw(pl, w_pos2, feri, mobMoveDirect(dir_id, move_id), aslib_mob_walk_type_big);

		//tma.putBlock(4, pl, 0);

		//
		inv.selectAdd(mouseWheel()).draw(item).isSelectUp(asKeyL_Up()).isSelectDown(asKeyK_Up());
	}

	return 0;
}