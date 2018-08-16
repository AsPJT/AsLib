#define ASLIB_INCLUDE_DL
#include "AsLib.hpp"

enum :size_t {
	aslib_paint_tool_pen,
	aslib_paint_tool_eraser,
	aslib_paint_tool_empty,
	aslib_paint_tool_pipette,
	aslib_paint_tool_bucket,
	aslib_paint_tool_left,
	aslib_paint_tool_right,
};


int32_t asMain()
{
	//タイトル
	MainControl mc(u8"AsRPG", Pos2(960,540));

	AsMapReturnControl mrc(100);

	//マップサイズを決める
	//size_t map_x = size_t(asKeyInputNum(Pos2(0, 0), 2048, 1));
	//size_t map_y = size_t(asKeyInputNum(Pos2(0, 0), 2048, 1));

	//キー
	AsKeyList kl;
	kl.addKeyOK().addKeyBack().addKeyUpDown();

	AsKeyList kl1;
	kl1.addKeyOK().addKeyBack().addKeyCrossW();

	//属性数
	asSetAttribute(aslib_attribute_num);

	const Pos2 paint_world_p(128,128);
	constexpr Pos2 select_world_p(2,100);
	constexpr Pos2 tool_world_p(2, 3);
	//モンスター
	AsTexture feri(u8"Picture/ikari.png", 6, 4);
	//マップテクスチャ
	AsTexture crystal1_te(u8"p/crystal1.png");
	AsTexture crystal2_te(u8"p/stone1.png");
	AsTexture anime_te(u8"p/anime.png", 4);
	AsTexture sea1_te(u8"p/world_umi1.png", 4, 10);
	AsTexture sea2_te(u8"p/world_umi2.png", 4, 10);
	AsTexture sea3_te(u8"p/world_umi3.png", 4, 10);
	AsTexture sea4_te(u8"p/world_umi4.png", 4, 10);
	AsTexture mo1_te(u8"p/world_yama2.png", 2, 10);
	AsTexture mo2_te(u8"p/world_yama2-yuki.png", 2, 10);
	AsTexture underground_stairs_te(u8"p/undergroundStairs2.png");

	//マップ管理
	AsTextureMapArray select_main_map;
	select_main_map.push(nullptr);
	select_main_map.push(&crystal1_te, aslib_texture_map_field_type_empty);
	select_main_map.push(&crystal2_te, aslib_texture_map_field_type_empty);
	select_main_map.push(&anime_te, aslib_texture_map_field_type_empty);
	select_main_map.push(&sea1_te, aslib_texture_map_field_type_water);
	select_main_map.push(&sea2_te, aslib_texture_map_field_type_water);
	select_main_map.push(&sea3_te, aslib_texture_map_field_type_water);
	select_main_map.push(&sea4_te, aslib_texture_map_field_type_water);
	select_main_map.push(&mo1_te, aslib_texture_map_field_type_wall);
	select_main_map.push(&mo2_te, aslib_texture_map_field_type_wall);
	select_main_map.push(&underground_stairs_te, aslib_texture_map_field_type_empty);

	size_t read_x = 0;
	size_t read_y = 0;
	const std::string str_ = u8"Picture/map_tile.csv";
	std::vector<std::string> name_;
	std::vector<size_t> vec_;
	if (asSize_t_MapReadCSV(str_, name_, vec_, &read_x, &read_y) != 0) return 0;

	asPrint("%d,%d,%d,%d", name_.size(), vec_.size(), read_x, read_y);

	std::unique_ptr<AsTexture[]> as_t(new AsTexture[read_y]);
	for (size_t i = 0; i < name_.size(); ++i) {
		as_t[i](name_[i].c_str(), vec_[i] * 2, 10);
		select_main_map.push(&as_t[i], aslib_texture_map_field_type_water);
	}

	AsTextureMapArray paint_main_map= select_main_map;
	
	//マップテクスチャ
	AsTexture pen_tool_te(u8"p/pen_tool.png");
	AsTexture eraser_tool_te(u8"p/eraser_tool.png");
	AsTexture empty_tool_te(u8"p/move_tool.png");
	AsTexture pipette_tool_te(u8"p/pipette_tool.png");
	AsTexture bucket_tool_te(u8"p/bucket_tool.png");
	AsTexture left_tool_te(u8"p/left_tool.png");
	AsTexture right_tool_te(u8"p/right_tool.png");

	float sf = asWindowSizeF().x / asWindowSizeF().y;
	AsTextureButton pen_button(Pos4F(0.0f, 0.0f, 0.05f, 0.05f*sf).ratio(), &pen_tool_te);
	AsTextureButton eraser_button(Pos4F(0.05f, 0.0f, 0.1f, 0.05f*sf).ratio(), &eraser_tool_te);
	AsTextureButton empty_button(Pos4F(0.0f, 0.05f*sf, 0.05f, 0.1f*sf).ratio(), &empty_tool_te);
	AsTextureButton pipette_button(Pos4F(0.05f, 0.05f*sf, 0.1f, 0.1f*sf).ratio(), &pipette_tool_te);
	AsTextureButton bucket_button(Pos4F(0.0f, 0.15f*sf, 0.05f, 0.2f*sf).ratio(), &bucket_tool_te);
	AsTextureButton left_button(Pos4F(0.0f, 0.1f*sf, 0.05f, 0.15f*sf).ratio(), &left_tool_te);
	AsTextureButton right_button(Pos4F(0.05f, 0.1f*sf, 0.1f, 0.15f*sf).ratio(), &right_tool_te);

	//フィールド属性
	AsAllAttribute att;
	att.push(aslib_default_field_attribute_empty);
	att.push(aslib_default_field_attribute_wall);
	att.push(aslib_default_field_attribute_water);
	att.push(aslib_default_field_attribute_keep_out);

	//マップ生成
	select_main_map.resizeMap(select_world_p);
	select_main_map.putTexture();

	paint_main_map.resizeMap(paint_world_p);
	//paint_main_map.worldMap(2, 4, 8, 9);
	paint_main_map.setLayer(2, 1);
	//paint_main_map.randMap(1);

	//select_main_map.worldMap(2, 4, 8, 9);
	//select_main_map.resizeMap(select_world_p);
	
	//select_main_map.setLayer(2, 1);
	//select_main_map.randMap(1);
	//select_main_map.putMap(1, 1);
	//select_main_map.mazeMap(4,0,1);

	//constexpr PosA4F pl2(1.0f, 1.0f, 1.0f, 1.0f);
	constexpr PosA4F pl2(7.0f, 8.0f, 3.0f, 3.0f);
	constexpr PosA4F pl3(7.0f, 8.0f, 0.7f, 0.7f);

	//constexpr PosA4F pl(1.0f, 1.0f, 1.0f, 1.0f);
	constexpr PosA4F pl(float(select_world_p.x/2), 0.0f, 1.0f, 1.0f);

	PosA4F tool_id_p(0.5f, 0.5f, 0.7f, 0.7f);
	//イベント管理
	AsMapEventControl tool_map_event(select_world_p, aslib_mob_walk_type_small, nullptr, pl, aslib_map_event_type_mob);
	tool_map_event.add(&feri, tool_id_p, aslib_map_event_type_mob, aslib_map_event_ai_stay);

	PosA4F select_id_p(0.5f, 0.5f, 0.7f, 0.7f);

	AsMapEventControl paint_map_event(paint_world_p, aslib_mob_walk_type_big, nullptr, pl, aslib_map_event_type_mob);
	paint_map_event.me[0].fps = 0.3f;
	paint_map_event.me[0].ai = aslib_map_event_ai_empty;
	AsMapEventControl select_map_event(select_world_p, aslib_mob_walk_type_small, nullptr, pl, aslib_map_event_type_mob);
	select_map_event.me[0].fps = 0.3f;
	select_map_event.me[0].ai = aslib_map_event_ai_empty;
	select_map_event.add(&feri, select_id_p, aslib_map_event_type_mob, aslib_map_event_ai_empty);

	Pos4 select_area = Pos4F(0.1f, 0.0f, 0.2f, 1.0f).ratio();
	Pos4 paint_area = Pos4F(0.2f, 0.0f, 1.0f, 1.0f).ratio();

	AsScreen paint_screen(paint_area);
	AsScreen select_screen(select_area);

	//マップ描画管理
	PosA4F select_map_p(0.0f, 0.0f, 2.0f, 1.0f);
	AsMapView select_map_view(select_map_p, 'x', select_area);
	select_map_view.setMap(select_world_p);

	PosA4F paint_map_p(0.0f, 0.0f, 4.0f, 12.0f);
	AsMapView paint_map_view(paint_map_p, 'y', paint_area);
	paint_map_view.setMap(paint_world_p);

	//選択しているマップのID
	size_t select_id = 0;
	Pos2 select_pos;
	//ツールのID
	size_t tool_id = 0;

	size_t select_layer = 1;

	while (asLoop())
	{
		//更新
		pen_button.update();
		eraser_button.update();
		empty_button.update();
		pipette_button.update();
		bucket_button.update();
		left_button.update();
		right_button.update();

		//asMouseWheel(paint_map_p, 5.0f, 30, paint_area);
		select_map_view.setTouchSlide(select_map_event, select_area,'y');
		select_map_view.setMouseSlide(select_map_event, select_area, 'y');
		select_map_event.me[0].pl.y += float(asMouseWheel(select_area));

		//更新
		select_main_map.update();
		paint_main_map.update();
		select_map_event.update(select_main_map, att, kl);
		paint_map_event.update(paint_main_map, att, kl1);

		//視点
		select_map_view.setMobView(select_map_event);
		paint_map_view.setMobView(paint_map_event);

		//マップ描画
		select_map_view.draw(&select_main_map, &select_screen);
		//イベント描画
		select_map_view.draw(&select_map_event, &select_screen);
		//マップ描画
		paint_map_view.draw(&paint_main_map, &paint_screen);

		//asRect(paint_area, Color(56, 170, 68));
		//paint_map_view.draw(&paint_main_map, &select_layer, &paint_screen);

		select_map_view.select(&select_main_map, &mrc, 0, &select_pos, &select_id, select_area, &select_screen);

		if (pen_button.up()) tool_id = aslib_paint_tool_pen;
		if (eraser_button.up()) tool_id = aslib_paint_tool_eraser;
		if (pipette_button.up()) tool_id = aslib_paint_tool_pipette;
		if (bucket_button.up()) tool_id = aslib_paint_tool_bucket;
		if (empty_button.up()) tool_id = aslib_paint_tool_empty;
		if (left_button.up()) mrc.left(&paint_main_map);
		if (right_button.up()) mrc.right(&paint_main_map);

		switch (tool_id)
		{
		case aslib_paint_tool_eraser:
			select_map_event.me[1].pl.x = 0.5f;
			select_map_event.me[1].pl.y = 0.5f;
			paint_map_view.paint(&paint_main_map, &mrc, select_layer, 0, paint_area, &paint_screen);
			break;
		case aslib_paint_tool_pen:
			select_map_event.me[1].pl.x = (select_id % 2) + 0.5f;
			select_map_event.me[1].pl.y = (select_id / 2) + 0.5f;
			paint_map_view.paint(&paint_main_map, &mrc, select_layer, select_id, paint_area, &paint_screen);
			break;
		case aslib_paint_tool_bucket:
			select_map_event.me[1].pl.x = (select_id % 2) + 0.5f;
			select_map_event.me[1].pl.y = (select_id / 2) + 0.5f;
			paint_map_view.bucket(&paint_main_map, &mrc, select_layer, select_id, paint_area, &paint_screen);
			break;
		case aslib_paint_tool_pipette:
			paint_map_view.select(&paint_main_map, &mrc, select_layer, nullptr, &select_id, paint_area, &paint_screen);
			select_map_event.me[1].pl.x = (select_id % 2) + 0.5f;
			select_map_event.me[1].pl.y = (select_id / 2) + 0.5f;
			break;
		case aslib_paint_tool_empty:
			paint_map_view.setTouchSlide(paint_map_event, paint_area);
			paint_map_view.setMouseSlide(paint_map_event, paint_area);
			//ズーム
			asTouchPinch(paint_map_p, 10.0f, 30, paint_area);
			paint_map_view.setLookSize(paint_map_p, 'y', paint_area);
			break;
		}

		//ボタン描画
		pen_button.bitSet(tool_id == aslib_paint_tool_pen).draw();
		eraser_button.bitSet(tool_id == aslib_paint_tool_eraser).draw();
		empty_button.bitSet(tool_id == aslib_paint_tool_empty).draw();
		pipette_button.bitSet(tool_id == aslib_paint_tool_pipette).draw();
		bucket_button.bitSet(tool_id == aslib_paint_tool_bucket).draw();
		left_button.draw();
		right_button.draw();
	}
	return 0;
}