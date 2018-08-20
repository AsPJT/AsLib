#define ASLIB_INCLUDE_DL
#include "AsLib.hpp"

int32_t asMain()
{
	

	//560, 700
	MainControl mc(u8"AsRPG", Pos2(960,540));

	//キー
	AsKeyList kl;
	kl.addKeyOK().addKeyBack().addKeyCross().addKeyCrossW();
	
	//プレイヤーキャラテクスチャ
	Texture red_te(u8"p/2_0.png");
	//メッセージフォント
	AsFont font(10, u8"07にくまるフォント");
	//ウィンドウテクスチャ
	Texture window_te(u8"p/win3.png", 3, 3);
	//win2//windowa
	MessageWindow window(window_te);
	Texture window_ui(u8"p/cho.png");
	//window.readSetString32(u8"p/str.txt");
	//Texture ani(u8"p/pet.png", 8, 4);
	Texture ani(u8"p/ya.png", 3);
	std::vector<std::string> list_name{ u8"プレイヤー",u8"仲間１",u8"仲間２" };
	std::vector<Texture*> list_texture{ &red_te,&window_ui,&window_te };
	WindowEvent window_event(list_name, list_texture);

	//ウィンドウ系
	window.setWindowEvent(window_event);
	window.setPerson(true);
	window.setFont(font);
	window.setSound(u8"p/om");
	////window.setName(u8"赤い髪の人");
	window.setPos(Pos4F(0.02f, 0.7f, 0.98f, 0.98f).ratio());
	window.setFrame(Pos4F(0.02f, 0.7f, 0.98f, 0.98f).ratio().h / 8);
	window.setLine(4);
	window.setFastForward(true);
	////window.setPerson(red);
	window.setEndAnime(ani);
	window.setUpdate(8);
	window.setUpdateEnd(6);
	window.setEffectTimer(20);
	window.setEffect(aslib_effect_event_zoom);

	//AsEventMessageWindow emw(&window);

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

	//Texture key_cross_te(u8"p/key_cross.png", 3, 3);
	

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

	constexpr Pos2 w_pos2(64,64);
	//モンスター
	AsTexture feri(u8"Picture/ikari.png", 6, 4);
	//マップテクスチャ
	//AsTexture crystal1_te(u8"p/crystal1.png");
	//AsTexture crystal2_te(u8"p/stone1.png");
	//AsTexture anime_te(u8"p/anime.png", 4);
	//AsTexture sea1_te(u8"p/world_umi1.png", 4, 10);
	//AsTexture sea2_te(u8"p/world_umi2.png", 4, 10);
	//AsTexture sea3_te(u8"p/world_umi1.png", 4, 10);
	//AsTexture sea4_te(u8"p/world_umi2.png", 4, 10);
	//AsTexture mo1_te(u8"p/world_yama2.png", 2, 10);
	//AsTexture mo2_te(u8"p/world_yama2-yuki.png", 2, 10);
	//AsTexture underground_stairs_te(u8"p/undergroundStairs2.png");

	//マップ管理
	AsTextureMapArray main_map;
	main_map.push(nullptr);
	//マップ読み込み
	std::unique_ptr<AsTexture[]> as_t = main_map.readMapCSV(u8"Picture/map_tile.csv", nullptr);

	//main_map.push(&crystal1_te, aslib_texture_map_field_type_empty);
	//main_map.push(&crystal2_te, aslib_texture_map_field_type_empty);
	//main_map.push(&anime_te, aslib_texture_map_field_type_empty);
	//main_map.push(&sea1_te, aslib_texture_map_field_type_water);
	//main_map.push(&sea2_te, aslib_texture_map_field_type_water);
	//main_map.push(&sea3_te, aslib_texture_map_field_type_water);
	//main_map.push(&sea4_te, aslib_texture_map_field_type_water);
	//main_map.push(&mo1_te, aslib_texture_map_field_type_wall);
	//main_map.push(&mo2_te, aslib_texture_map_field_type_wall);
	//main_map.push(&underground_stairs_te, aslib_texture_map_field_type_empty);

	//size_t read_x = 0;
	//size_t read_y = 0;
	//const std::string str_ = u8"map_tile.csv";
	//std::vector<std::string> name_;
	//std::vector<size_t> vec_;
	//if (asSize_t_MapReadCSV(str_, name_, vec_, &read_x, &read_y) != 0) return 0;

	//asPrint("%d,%d,%d,%d", name_.size(), vec_.size(), read_x, read_y);

	//std::unique_ptr<AsTexture[]> as_t(new AsTexture[read_y]);
	//for (size_t i = 0; i < name_.size(); ++i) {
	//	as_t[i](name_[i].c_str(), vec_[i] * 2, 10);
	//	main_map.push(&as_t[i], aslib_texture_map_field_type_water);
	//}
	//マップ読み込み
	//size_t as_t_size = 0;
	//std::unique_ptr<AsTexture[]> as_t = main_map.readMapCSV(u8"Picture/map_tile.csv", &as_t_size);

	//フィールド属性
	AsAllAttribute att;
	att.push(aslib_default_field_attribute_empty);
	att.push(aslib_default_field_attribute_wall);
	att.push(aslib_default_field_attribute_water);
	att.push(aslib_default_field_attribute_keep_out);

	//マップ生成
	main_map.resizeMap(w_pos2);
	main_map.worldMap(2, 4, 8, 9);
	//if (main_map.readCSV() == 1 && main_map.readBackupCSV() == 1) {
		//main_map.resizeMap(w_pos2);
		//main_map.setLayer(2, 1);
		//main_map.randMap(1);
	//}
	//main_map.resizeMap(w_pos2);
	//main_map.putTexture();
	//main_map.setLayer(2, 1);
	//main_map.randMap(1);
	//main_map.putMap(1, 1);
	//main_map.mazeMap(4,0,1);

	//constexpr PosA4F pl2(1.0f, 1.0f, 1.0f, 1.0f);
	constexpr PosA4F pl2(7.0f, 8.0f, 3.0f, 3.0f);
	constexpr PosA4F pl3(7.0f, 8.0f, 0.7f, 0.7f);

	constexpr PosA4F pl(1.0f, 1.0f, 1.0f, 1.0f);

	//イベント管理
	AsMapEventControl map_event(w_pos2,aslib_mob_walk_type_big, &feri, pl, aslib_map_event_type_mob);
	map_event.spawn().add(&feri, pl2, aslib_map_event_type_mob);

	AsEventMessageWindow emw(&window, u8"p/str.txt");
	map_event.me[1].event_init = aslib_event_init_tolk;
	map_event.me[1].med.emplace_back(&emw);

	//マップ描画管理
	PosA4F map_p(0.0f, 0.0f, 5.0f, 10.0f);
	AsMapView map_view(map_p, 'y');
	map_view.setMap(w_pos2);
	
	//constexpr size_t auto_save_timer = 60 * 22;
	//size_t auto_save_counter = 0;
	//constexpr size_t auto_backup_timer = 60 * 55;
	//size_t auto_backup_counter = 0;

	//プレイヤー初期スポーン指定
	map_event.setLandSpawn(main_map,att);

	//臨時タッチ
	Pos2 touch_event;

	while (asLoop())
	{

		//臨時タッチ
		//if (asTouch()) {
		//	touch_event = asTouchEndPos();
		//	if (touch_event.x < asWindowSize().x / 3) {
		//		if (touch_event.y < asWindowSize().y / 3) { asKeySet(aslib_key_w); asKeySet(aslib_key_a); }
		//		else if (touch_event.y < asWindowSize().y * 2 / 3) { asKeySet(aslib_key_a); }
		//		else { asKeySet(aslib_key_a); asKeySet(aslib_key_s); }
		//	}
		//	else if (touch_event.x < asWindowSize().x * 2 / 3) {
		//		if (touch_event.y < asWindowSize().y / 3) { asKeySet(aslib_key_w); }
		//		else if (touch_event.y < asWindowSize().y * 2 / 3) {}
		//		else { asKeySet(aslib_key_s); }
		//	}
		//	else {
		//		if (touch_event.y < asWindowSize().y / 3) { asKeySet(aslib_key_w); asKeySet(aslib_key_d); }
		//		else if (touch_event.y < asWindowSize().y * 2 / 3) { asKeySet(aslib_key_d); }
		//		else { asKeySet(aslib_key_d); asKeySet(aslib_key_s); }
		//	}
		//}

		//更新
		main_map.update();
		map_event.update(main_map, att, kl);
		//視点
		map_view.setMobView(map_event);
		//マップ描画
		map_view.draw(&main_map);
		//イベント描画
		map_view.draw(&map_event);
		//ランダムスポーン
		map_event.spawn(1).add(&feri, pl3, aslib_map_event_type_mob);
		//ズーム
		asTouchPinch(map_p, 10.0f,30);
		map_view.setLookSize(map_p, 'y');

		//イベント起動
		map_event.play_event();
		//会話起動イベント
		map_event.talk(kl.is_ok());

		//++auto_save_counter;
		//if (auto_save_counter >= auto_save_timer) {
		//	auto_save_counter = 0;
		//	main_map.writeCSV();
		//}
		//++auto_backup_counter;
		//if (auto_backup_counter >= auto_backup_timer) {
		//	auto_backup_counter = 0;
		//	main_map.writeBackupCSV();
		//}

		//ウィンドウ関連
		if (window.isWindow()) window.playEffect().update().updateEnd().drawPerson().drawWindow().writeString().drawEndAnime().playSound().printString().printName().next(kl.is_ok());
		else inv.selectAdd(mouseWheel()).draw(item).isSelectUp(asKeyL_Up()).isSelectDown(asKeyK_Up());
	}

	//main_map.writeCSV();

	//for (size_t i = 0; i < kl.ok.size(); ++i) if (kl.ok[i] < 256 && asKeyUp(kl.ok[i])) main_map.putBlock(4, pl, 1);
	//

	return 0;
}