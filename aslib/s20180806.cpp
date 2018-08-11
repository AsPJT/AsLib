#define ASLIB_INCLUDE_DL
#include "AsLib.hpp"

int32_t asMain()
{
	//560, 700
	MainControl mc(u8"AsRPG", Pos2(1280,720));

	//キー
	AsKeyList kl;
	kl.addCross();
	kl.addKeyCross();

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

	//属性数
	asSetAttribute(aslib_attribute_num);

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

	constexpr Pos2 w_pos2(5, 11);

	//マップテクスチャ
	AsTexture crystal1_te(u8"p/crystal1.png");
	AsTexture crystal2_te(u8"p/crystal2.png");
	AsTexture anime_te(u8"p/anime.png", 4);
	AsTexture sea1_te(u8"p/world_umi1.png", 4, 10);
	AsTexture sea2_te(u8"p/world_umi2.png", 4, 10);
	AsTexture sea3_te(u8"p/world_umi1.png", 4, 10);
	AsTexture sea4_te(u8"p/world_umi2.png", 4, 10);
	AsTexture mo1_te(u8"p/world_yama2.png", 2, 10);
	AsTexture mo2_te(u8"p/world_yama2-yuki.png", 2, 10);

	//マップ管理
	AsTextureMapArray tma;
	tma.push(nullptr);
	tma.push(&crystal1_te, aslib_texture_map_field_type_empty);
	tma.push(&crystal2_te, aslib_texture_map_field_type_empty);
	tma.push(&anime_te, aslib_texture_map_field_type_empty);
	tma.push(&sea1_te, aslib_texture_map_field_type_water);
	tma.push(&sea2_te, aslib_texture_map_field_type_water);
	tma.push(&sea3_te, aslib_texture_map_field_type_water);
	tma.push(&sea4_te, aslib_texture_map_field_type_water);
	tma.push(&mo1_te, aslib_texture_map_field_type_wall);
	tma.push(&mo2_te, aslib_texture_map_field_type_wall);
	//属性
	AsAllAttribute att;
	att.push(aslib_default_field_attribute_empty);
	att.push(aslib_default_field_attribute_wall);
	att.push(aslib_default_field_attribute_water);
	att.push(aslib_default_field_attribute_keep_out);

	//マップ生成
	tma.resizeMap(w_pos2);
	tma.putTexture();
	//tma.setLayer(2, 1);
	//tma.randMap(1);
	//tma.putMap(1, 1);
	//tma.mazeMap(4,0,1);

	//モンスター
	AsTexture feri(u8"Picture/ikari.png", 6, 4);

	size_t dir_id = MOB_DOWN;
	size_t move_id = MOB_STOP;
	size_t moving = MOB_CENTER;
	size_t pl_field_type = aslib_attribute_human;
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
		if (movingMob8(att,tma, kl, fps, pl, moving = movingMob(fps, pl, moving),dir_id)) {
			//asPrint("a");
			mobMoveSet(move_id, count);
			//directionMob(moving, dir_id);
		}
		else move_id = MOB_STOP;

		asPrint("(%.2f,%.2f)", pl.x, pl.y);

		mv.setMobView(pl, aslib_mob_walk_type_big);
		mv.draw(&tma);

		//mv.draw(pl2, w_pos2, Color(0, 255, 0, 255));
		//mv.draw(PosA4F(5.5f, 5.5f, 1.0f, 1.0f), w_pos2, Color(0, 205, 50, 255));
		//mv.draw(PosA4F(0.5f, 0.5f, 1.0f, 1.0f), w_pos2, Color(0, 255, 0, 255));
		mv.draw(pl, w_pos2, feri, mobMoveDirect(dir_id, move_id), aslib_mob_walk_type_big);

		//asPrint("(%d)", att.all_id[tma.tm[tma.s[pl.y*tma.s_x + pl.x]].field_type].id[aslib_attribute_human]);
		//tma.putBlock(4, pl, 0);

		//
		inv.selectAdd(mouseWheel()).draw(item).isSelectUp(asKeyL_Up()).isSelectDown(asKeyK_Up());
	}

	return 0;
}