#define ASLIB_INCLUDE_DL
#define __WINDOWS__

#include "AsLib.hpp"

//ペイントツール種類
enum :std::size_t {
	aslib_paint_tool_pen,
	aslib_paint_tool_eraser,
	aslib_paint_tool_empty,
	aslib_paint_tool_pipette,
	aslib_paint_tool_bucket,
	aslib_paint_tool_up_down_layer,
	aslib_paint_tool_event,
	aslib_paint_tool_see,
	aslib_paint_tool_left,
	aslib_paint_tool_right,
	aslib_paint_tool_option,
};

std::int32_t asMain()
{
	//1280, 800
	//タイトル
	MainControl mc("AsRPG", asPlatformPos(Pos2(960, 540)), Color(66, 66, 66));

	//戻る登録数
	AsMapReturnControl mrc(128);

	AsKeyButton kb(2, Pos4F(0.1f, 0.1f, 0.2f, 0.15f).ratio());
	//AsKeyInput ki(10);
	//ki.on();
	//kb.on();

	//マップサイズを決める
	//std::size_t map_x = std::size_t(asKeyInputNum(Pos2(0, 0), 2048, 1));
	//std::size_t map_y = std::size_t(asKeyInputNum(Pos2(0, 0), 2048, 1));

	//キー
	AsKeyList kl;
	kl.addKeyUpDown();

	AsKeyList kl1;
	kl1.addKeyCrossW();

	//属性数
	asSetAttribute(aslib_attribute_num);

	//サイズ
	Pos2 paint_world_p(128, 128);
	Pos2 select_world_p(8, 100);

	//モンスター
	//AsTexture feri(u8"p/ikari.png", 6, 4);
	AsTexture sui("Picture/Tool/select_ui.png");
	//AsTexture sta(u8"p/start_ui.png");

	//マップ管理
	AsTextureMapArray select_main_map;
	select_main_map.push(nullptr);

	//マップ個数 読み込み
	std::size_t as_t_size{};
	//マップデータ読み込み
	const std::unique_ptr<AsTexture[]> as_t = select_main_map.readMapCSV("Picture/map_tile.csv", &as_t_size);
	if (as_t_size != 0) select_world_p.y = static_cast<std::int_least32_t>((select_main_map.t.size() + 1) / 8);
	AsTextureMapArray paint_main_map{ select_main_map };

	//ペイントツールテクスチャ
	AsTexture pen_tool_te("Picture/Tool/pen_tool.png");
	AsTexture eraser_tool_te("Picture/Tool/eraser_tool.png");
	AsTexture empty_tool_te("Picture/Tool/move_tool.png");
	AsTexture pipette_tool_te("Picture/Tool/pipette_tool.png");
	AsTexture bucket_tool_te("Picture/Tool/bucket_tool.png");
	AsTexture see_tool_te("Picture/Tool/see_tool.png");
	AsTexture up_down_layer_tool_te("Picture/Tool/layer_tool.png");
	AsTexture event_tool_te("Picture/Tool/event_tool.png");
	AsTexture left_tool_te("Picture/Tool/left_tool.png");
	AsTexture right_tool_te("Picture/Tool/right_tool.png");
	AsTexture option_tool_te("Picture/Tool/option_tool.png");
	AsTexture white_ascll("Picture/white_ascll.png");

	//ペイントツールボタン
	AsPosFArray button_p(Pos4F(0.02f, 0.415f, 0.285f, 1.0f).ratio(), 6, 100);

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
	AsTextureButton event_button(button_p[9], &event_tool_te);
	AsTextureButton option_button(button_p[10], &option_tool_te);

	//AsTextureButton white_ascll_button(Pos4F(0.0f, 0.98f - 0.1f*sf, 0.1f, 0.98f).ratio(), &white_ascll);

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
	paint_world_p(std::int32_t(paint_main_map.s_x), std::int32_t(paint_main_map.s_y));

	//paint_main_map.worldMap(2, 4, 8, 9);
	//paint_main_map.randMap(1);
	//select_main_map.worldMap(2, 4, 8, 9);
	//select_main_map.resizeMap(select_world_p);

	//select_main_map.setLayer(2, 1);
	//select_main_map.randMap(1);
	//select_main_map.putMap(1, 1);
	//select_main_map.mazeMap(4,0,1);

	//constexpr PosA4F pl2(1.0f, 1.0f, 1.0f, 1.0f);
	//constexpr PosA4F pl2(7.0f, 8.0f, 3.0f, 3.0f);
	//constexpr PosA4F pl3(7.0f, 8.0f, 0.7f, 0.7f);

	//constexpr PosA4F pl(1.0f, 1.0f, 1.0f, 1.0f);
	const PosA4F pl(float(select_world_p.x / 2), 0.0f, 1.0f, 1.0f);

	PosA4F tool_id_p(0.5f, 0.5f, 0.7f, 0.7f);
	//イベント管理
	AsMapEventControl tool_map_event(select_world_p, aslib_mob_walk_type_small, nullptr, pl, aslib_map_event_type_mob);
	//tool_map_event.add(&feri, tool_id_p, aslib_map_event_type_mob, aslib_map_event_ai_stay);

	PosA4F select_id_p(0.5f, 0.5f, 1.0f, 1.0f);
	PosA4F paint_id_p(0.5f, 0.5f, 1.0f, 1.0f);

	AsMapEventControl paint_map_event(paint_world_p, aslib_mob_walk_type_small, nullptr, pl, aslib_map_event_type_mob);
	paint_map_event.me[0].fps = 0.3f;
	paint_map_event.me[0].ai = aslib_map_event_ai_empty;
	paint_map_event.add(&sui, paint_id_p, aslib_map_event_type_empty, aslib_map_event_ai_stay);
	//paint_map_event.add(&sta, paint_id_p, aslib_map_event_type_empty, aslib_map_event_ai_stay);
	//paint_map_event.add(&feri, paint_id_p, aslib_map_event_type_empty, aslib_map_event_ai_stay);

	AsMapEventControl select_map_event(select_world_p, aslib_mob_walk_type_small, nullptr, pl, aslib_map_event_type_mob);
	select_map_event.me[0].fps = 0.3f;
	select_map_event.me[0].ai = aslib_map_event_ai_empty;
	select_map_event.add(&sui, select_id_p, aslib_map_event_type_empty, aslib_map_event_ai_stay);

	Pos4 select_area = Pos4F(0.02f, 0.02f, 0.285f, 0.38f).ratio();
	//Pos4 select_area = Pos4F(0.115f, 0.02f, 0.185f, 0.98f).ratio();
	Pos4 paint_area = Pos4F(0.3f, 0.02f, 0.985f, 0.98f).ratio();
	//Pos4 select_area = Pos4F(0.1f, 0.0f, 0.2f, 1.0f).ratio();
	//Pos4 paint_area = Pos4F(0.2f, 0.0f, 1.0f, 1.0f).ratio();

	//マップ描画管理
	PosA4F select_map_p(0.0f, 0.0f, 8.0f, 1.0f);
	AsMapView select_map_view(select_map_p, 'x', select_area);
	select_map_view.setMap(select_world_p);

	PosA4F paint_map_p(0.0f, 0.0f, 4.0f, 11.0f);
	AsMapView paint_map_view(paint_map_p, 'y', paint_area);
	paint_map_view.setMap(paint_world_p);

	//選択しているマップのID
	std::size_t select_id{};
	Pos2 select_pos;
	//ツールのID
	std::size_t tool_id{};

	std::size_t select_layer{ 1 };
	bool is_select{ false };

	//セーブタイマー
	constexpr std::size_t auto_save_timer{ 60 * 22 };
	std::size_t auto_save_counter{};
	constexpr std::size_t auto_backup_timer{ 60 * 55 };
	std::size_t auto_backup_counter{};

	Pos2 paint_touch_pos;

	//ki.input(u8"aaaa");
	while (asLoop())
	{
		kb.update();
		kb.on(kb.up());

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
		event_button.update();
		option_button.update();
		//更新
		select_main_map.update();
		paint_main_map.update();
		select_map_event.update(select_main_map, att, kl);
		paint_map_event.update(paint_main_map, att, kl1);

		//asMouseWheel(paint_map_p, 5.0f, 30, paint_area);
		select_map_view.setTouchSlide(select_map_event, select_area, 'y');
		select_map_view.setMouseSlide(select_map_event, select_area, 'y');
		select_map_event.me[0].pl.y += float(asMouseWheel(select_area));

		//選択地点
		switch (tool_id)
		{
		case aslib_paint_tool_empty:break;
		default:
			paint_map_view.mouseSelect(&paint_main_map, &mrc, 0, &paint_touch_pos, nullptr, paint_area);
			paint_map_view.select(&paint_main_map, &mrc, 0, &paint_touch_pos, nullptr, paint_area);
			paint_map_event.me[1].pl.x = float(paint_touch_pos.x) + 0.5f;
			paint_map_event.me[1].pl.y = float(paint_touch_pos.y) + 0.5f;
			break;
		}
		//視点
		select_map_view.setMobView(select_map_event);
		paint_map_view.setMobView(paint_map_event);



		is_select = select_map_view.select(&select_main_map, &mrc, 0, &select_pos, &select_id, select_area);

		//テスト
		//paint_map_view.eventSelect(&paint_map_event, &mrc, select_layer, nullptr, &select_id, paint_area);

		//ボタンを押したとき
		if (pen_button.up()) tool_id = aslib_paint_tool_pen;
		if (eraser_button.up()) tool_id = aslib_paint_tool_eraser;
		if (pipette_button.up()) tool_id = aslib_paint_tool_pipette;
		if (bucket_button.up()) tool_id = aslib_paint_tool_bucket;
		if (event_button.up()) tool_id = aslib_paint_tool_event;
		if (option_button.up()) tool_id = aslib_paint_tool_option;
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

		//マップ描画
		if (see_button.isOn()) {
			asRect(paint_area, Color(56, 170, 68));
			paint_map_view.draw(&paint_main_map, &select_layer, paint_area);
		}
		else paint_map_view.draw(&paint_main_map, paint_area);
		paint_map_view.draw(&paint_map_event, paint_area);

		//マップ描画
		switch (tool_id)
		{
		case aslib_paint_tool_event:
			break;
		case aslib_paint_tool_option:
			//ki.draw(Pos2(50,500));
			kb.drawButton();
			kb.drawString();
			break;
		default:
			asRect(select_area, Color(245, 245, 245));
			select_map_view.draw(&select_main_map, select_area);
			select_map_view.draw(&select_map_event, select_area);
			break;
		}

		switch (tool_id)
		{
		case aslib_paint_tool_eraser:
			if (is_select) tool_id = aslib_paint_tool_pen;
			select_map_event.me[1].pl.x = 0.5f;
			select_map_event.me[1].pl.y = 0.5f;
			paint_map_view.paint(&paint_main_map, &mrc, select_layer, 0, paint_area);
			break;
		case aslib_paint_tool_pen:
			select_map_event.me[1].pl.x = (select_id % 8) + 0.5f;
			select_map_event.me[1].pl.y = (select_id / 8) + 0.5f;
			paint_map_view.paint(&paint_main_map, &mrc, select_layer, select_id, paint_area);
			break;
		case aslib_paint_tool_bucket:
			select_map_event.me[1].pl.x = (select_id % 8) + 0.5f;
			select_map_event.me[1].pl.y = (select_id / 8) + 0.5f;
			paint_map_view.bucket(&paint_main_map, &mrc, select_layer, select_id, paint_area);
			break;
		case aslib_paint_tool_pipette:
			paint_map_view.select(&paint_main_map, &mrc, select_layer, nullptr, &select_id, paint_area);
			select_map_event.me[1].pl.x = (select_id % 8) + 0.5f;
			select_map_event.me[1].pl.y = (select_id / 8) + 0.5f;
			break;
		case aslib_paint_tool_empty:
			if (is_select) tool_id = aslib_paint_tool_pen;
			paint_map_view.setTouchSlide(paint_map_event, paint_area);
			paint_map_view.setMouseSlide(paint_map_event, paint_area);
			//ズーム
			asTouchPinch(paint_map_p, 10.0f, 30, paint_area);
			paint_map_view.setLookSize(paint_map_p, 'y', paint_area);
			break;
		case aslib_paint_tool_event:
			break;
		}

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
		event_button.bitSet(tool_id == aslib_paint_tool_event).draw();
		option_button.bitSet(tool_id == aslib_paint_tool_option).draw();
		//white_ascll_button.draw();



	}
	//終了セーブ
	paint_main_map.writeCSV();
	return 0;
}
