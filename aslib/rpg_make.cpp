#define ASLIB_INCLUDE_DL
#include "AsLib.hpp"

//ペイントツール種類
enum :size_t {
	aslib_paint_tool_pen,
	aslib_paint_tool_eraser,
	aslib_paint_tool_empty,
	aslib_paint_tool_pipette,
	aslib_paint_tool_bucket,
	aslib_paint_tool_up_down_layer,
	aslib_paint_tool_see,
	aslib_paint_tool_left,
	aslib_paint_tool_right,
};

struct AsPosFArray {
	PosL4F pos;
	size_t num_x;
	size_t num_y;
	size_t num;
	//float fx = 1.0f;
	//float fy = 1.0f;
	bool is_x = false;
	bool is_y = false;

	void setX(const float f_) { is_x = true; is_y = false; }
	void setY(const float f_) { is_x = false; is_y = true; }

	constexpr AsPosFArray(const PosL4F& p_, const size_t x_ = 1, const size_t y_ = 1) :pos(p_), num_x(x_), num_y(y_), num(x_*y_) {}
	const PosL4F operator[](const size_t num_) {
		if (num_ >= num) return PosL4F();

		const size_t num_x_ = num_ % num_x;
		const size_t num_y_ = num_ / num_x;

		if (is_x) return PosL4F(pos.x + pos.h*num_x_ / num_y, pos.y + pos.h*num_y_ / num_y, pos.h / num_y, pos.h / num_y);
		if (is_y) return PosL4F(pos.x + pos.w*num_x_ / num_x, pos.y + pos.w*num_y_ / num_x, pos.w / num_x, pos.w / num_x);
		return PosL4F(pos.x + pos.w*num_x_ / num_x, pos.y + pos.h*num_y_ / num_y, pos.w / num_x, pos.h / num_y);
	}


};


int32_t asMain()
{
	//タイトル
	MainControl mc(u8"AsRPG", Pos2(1280, 800),Color(66,66,66));

	//戻る登録数
	AsMapReturnControl mrc(128);

	//マップサイズを決める
	//size_t map_x = size_t(asKeyInputNum(Pos2(0, 0), 2048, 1));
	//size_t map_y = size_t(asKeyInputNum(Pos2(0, 0), 2048, 1));

	//キー
	AsKeyList kl;
	kl.addKeyUpDown();

	AsKeyList kl1;
	kl1.addKeyCrossW();

	//属性数
	asSetAttribute(aslib_attribute_num);

	//サイズ
	Pos2 paint_world_p(128, 128);
	Pos2 select_world_p(2, 100);

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

	//マップ読み込み
	size_t as_t_size = 0;
	std::unique_ptr<AsTexture[]> as_t = select_main_map.readMapCSV(u8"Picture/map_tile.csv", &as_t_size);
	if(as_t_size!=0) select_world_p.y = (select_main_map.t.size() + 1) / 2;
	AsTextureMapArray paint_main_map = select_main_map;

	//ペイントツールテクスチャ
	AsTexture pen_tool_te(u8"p/pen_tool.png");
	AsTexture eraser_tool_te(u8"p/eraser_tool.png");
	AsTexture empty_tool_te(u8"p/move_tool.png");
	AsTexture pipette_tool_te(u8"p/pipette_tool.png");
	AsTexture bucket_tool_te(u8"p/bucket_tool.png");
	AsTexture see_tool_te(u8"p/see_tool.png");
	AsTexture up_down_layer_tool_te(u8"p/up_down_layer_tool.png");
	AsTexture left_tool_te(u8"p/left_tool.png");
	AsTexture right_tool_te(u8"p/right_tool.png");
	AsTexture white_ascll(u8"Picture/white_ascll.png");

	//ペイントツールボタン
	AsPosFArray button_p(Pos4F(0.015f, 0.015f, 0.1f, 1.0f).ratio(), 2, 100);

	float sf = asWindowSizeF().x / asWindowSizeF().y;
	button_p.setY(sf);
	AsTextureButton left_button(button_p[0], &left_tool_te);
	AsTextureButton right_button(button_p[1], &right_tool_te);
	AsTextureButton pen_button(button_p[2], &pen_tool_te);
	AsTextureButton eraser_button(button_p[3], &eraser_tool_te);
	AsTextureButton bucket_button(button_p[4], &bucket_tool_te);
	AsTextureButton pipette_button(button_p[5], &pipette_tool_te);
	AsTextureButton empty_button(button_p[6], &empty_tool_te);
	AsTextureButton see_button(button_p[7], &see_tool_te);
	AsTextureNumButton up_down_layer_button(button_p[8], &up_down_layer_tool_te);


	AsTextureButton white_ascll_button(Pos4F(0.0f, 0.98f - 0.1f*sf, 0.1f, 0.98f).ratio(), &white_ascll);

	//フィールド属性
	AsAllAttribute att;
	att.push(aslib_default_field_attribute_empty);
	att.push(aslib_default_field_attribute_wall);
	att.push(aslib_default_field_attribute_water);
	att.push(aslib_default_field_attribute_keep_out);

	//マップ生成
	select_main_map.resizeMap(select_world_p);
	select_main_map.putTexture();
	//マップ読み込み
	if (paint_main_map.readCSV() == 1 && paint_main_map.readBackupCSV() == 1) {
		paint_main_map.resizeMap(paint_world_p);
		paint_main_map.setLayer(2, 1);
	}
	//大きさ設定
	paint_world_p(int32_t(paint_main_map.s_x), int32_t(paint_main_map.s_y));

	//paint_main_map.worldMap(2, 4, 8, 9);
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
	const PosA4F pl(float(select_world_p.x / 2), 0.0f, 1.0f, 1.0f);

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
	select_map_event.add(&feri, select_id_p, aslib_map_event_type_mob, aslib_map_event_ai_stay);

	Pos4 select_area = Pos4F(0.115f, 0.02f, 0.185f, 0.98f).ratio();
	Pos4 paint_area = Pos4F(0.2f, 0.02f, 0.985f, 0.98f).ratio();
	//Pos4 select_area = Pos4F(0.1f, 0.0f, 0.2f, 1.0f).ratio();
	//Pos4 paint_area = Pos4F(0.2f, 0.0f, 1.0f, 1.0f).ratio();

	//マップ描画管理
	PosA4F select_map_p(0.0f, 0.0f, 2.0f, 1.0f);
	AsMapView select_map_view(select_map_p, 'x', select_area);
	select_map_view.setMap(select_world_p);

	PosA4F paint_map_p(0.0f, 0.0f, 4.0f, 15.0f);
	AsMapView paint_map_view(paint_map_p, 'y', paint_area);
	paint_map_view.setMap(paint_world_p);

	//選択しているマップのID
	size_t select_id = 0;
	Pos2 select_pos;
	//ツールのID
	size_t tool_id = 0;

	size_t select_layer = 1;

	//セーブタイマー
	constexpr size_t auto_save_timer = 60 * 22;
	size_t auto_save_counter = 0;
	constexpr size_t auto_backup_timer = 60 * 55;
	size_t auto_backup_counter = 0;

	while (asLoop())
	{
		//ボタン更新
		pen_button.update();
		eraser_button.update();
		empty_button.update();
		pipette_button.update();
		bucket_button.update();
		see_button.update();
		up_down_layer_button.updateUp();
		up_down_layer_button.updateDown();
		left_button.update();
		right_button.update();
		//更新
		select_main_map.update();
		paint_main_map.update();
		select_map_event.update(select_main_map, att, kl);
		paint_map_event.update(paint_main_map, att, kl1);

		//asMouseWheel(paint_map_p, 5.0f, 30, paint_area);
		select_map_view.setTouchSlide(select_map_event, select_area, 'y');
		select_map_view.setMouseSlide(select_map_event, select_area, 'y');
		select_map_event.me[0].pl.y += float(asMouseWheel(select_area));



		//視点
		select_map_view.setMobView(select_map_event);
		paint_map_view.setMobView(paint_map_event);

		//マップ描画
		if (see_button.isOn()) {
			asRect(paint_area, Color(56, 170, 68));
			paint_map_view.draw(&paint_main_map, &select_layer, paint_area);
		}
		else paint_map_view.draw(&paint_main_map, paint_area);

		//マップ描画
		asRect(select_area, Color(245,245,245));
		select_map_view.draw(&select_main_map, select_area);
		//イベント描画
		select_map_view.draw(&select_map_event, select_area);

		select_map_view.select(&select_main_map, &mrc, 0, &select_pos, &select_id, select_area);

		//ボタンを押したとき
		if (pen_button.up()) tool_id = aslib_paint_tool_pen;
		if (eraser_button.up()) tool_id = aslib_paint_tool_eraser;
		if (pipette_button.up()) tool_id = aslib_paint_tool_pipette;
		if (bucket_button.up()) tool_id = aslib_paint_tool_bucket;
		if (see_button.up()) see_button.bit();
		if (up_down_layer_button.upUp() && select_layer < (paint_main_map.s_layer - 1)) {
			++select_layer;
			//asPrint("a");
		}
		if (up_down_layer_button.upDown() && select_layer != 0) {
			--select_layer;
			//asPrint("b");
		}
		if (empty_button.up()) tool_id = aslib_paint_tool_empty;
		if (left_button.up()) mrc.left(&paint_main_map);
		if (right_button.up()) mrc.right(&paint_main_map);

		switch (tool_id)
		{
		case aslib_paint_tool_eraser:
			select_map_event.me[1].pl.x = 0.5f;
			select_map_event.me[1].pl.y = 0.5f;
			paint_map_view.paint(&paint_main_map, &mrc, select_layer, 0, paint_area);
			break;
		case aslib_paint_tool_pen:
			select_map_event.me[1].pl.x = (select_id % 2) + 0.5f;
			select_map_event.me[1].pl.y = (select_id / 2) + 0.5f;
			paint_map_view.paint(&paint_main_map, &mrc, select_layer, select_id, paint_area);
			break;
		case aslib_paint_tool_bucket:
			select_map_event.me[1].pl.x = (select_id % 2) + 0.5f;
			select_map_event.me[1].pl.y = (select_id / 2) + 0.5f;
			paint_map_view.bucket(&paint_main_map, &mrc, select_layer, select_id, paint_area);
			break;
		case aslib_paint_tool_pipette:
			paint_map_view.select(&paint_main_map, &mrc, select_layer, nullptr, &select_id, paint_area);
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
		see_button.draw();
		up_down_layer_button.draw();
		up_down_layer_button.drawNum(select_layer, Color(81, 78, 72));
		left_button.draw();
		right_button.draw();
		white_ascll_button.draw();

		//自動セーブ
		++auto_save_counter;
		if (auto_save_counter >= auto_save_timer) {
			auto_save_counter = 0;
			paint_main_map.writeCSV();
		}
		++auto_backup_counter;
		if (auto_backup_counter >= auto_backup_timer) {
			auto_backup_counter = 0;
			paint_main_map.writeBackupCSV();
		}
	}
	//終了セーブ
	paint_main_map.writeCSV();
	return 0;
}