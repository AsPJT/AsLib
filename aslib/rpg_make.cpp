#define ASLIB_INCLUDE_DL
#include "AsLib.hpp"

int32_t asMain()
{
	//�^�C�g��
	MainControl mc(u8"AsRPG", Pos2(960, 540));
	//�L�[
	AsKeyList kl;
	kl.addKeyOK().addKeyBack().addKeyUpDown();

	AsKeyList kl1;
	kl1.addKeyOK().addKeyBack().addKeyCrossW();

	//������
	asSetAttribute(aslib_attribute_num);

	constexpr Pos2 paint_world_p(128,128);
	constexpr Pos2 select_world_p(2,50);
	constexpr Pos2 tool_world_p(2, 5);
	//�����X�^�[
	AsTexture feri(u8"Picture/ikari.png", 6, 4);
	//�}�b�v�e�N�X�`��
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

	//�}�b�v�Ǘ�
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

	AsTextureMapArray paint_main_map= select_main_map;
	AsTextureMapArray tool_main_map;

	//�t�B�[���h����
	AsAllAttribute att;
	att.push(aslib_default_field_attribute_empty);
	att.push(aslib_default_field_attribute_wall);
	att.push(aslib_default_field_attribute_water);
	att.push(aslib_default_field_attribute_keep_out);

	//�}�b�v����
	tool_main_map.resizeMap(tool_world_p);
	tool_main_map.putTexture();

	select_main_map.resizeMap(select_world_p);
	select_main_map.putTexture();

	paint_main_map.resizeMap(paint_world_p);
	paint_main_map.worldMap(2, 4, 8, 9);

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
	constexpr PosA4F pl(select_world_p.x/2, 0.0f, 1.0f, 1.0f);

	//�C�x���g�Ǘ�
	AsMapEventControl tool_map_event(select_world_p, aslib_mob_walk_type_small, nullptr, pl, aslib_map_event_type_mob);

	AsMapEventControl paint_map_event(paint_world_p, aslib_mob_walk_type_big, nullptr, pl, aslib_map_event_type_mob);
	paint_map_event.me[0].fps = 0.3f;
	paint_map_event.me[0].ai = aslib_map_event_ai_empty;
	AsMapEventControl select_map_event(select_world_p, aslib_mob_walk_type_small, nullptr, pl, aslib_map_event_type_mob);
	select_map_event.me[0].fps = 0.3f;
	select_map_event.me[0].ai = aslib_map_event_ai_empty;

	//AsScreen paint_screen(Pos2(asWindowSize().x * 7 / 10, asWindowSize().y));
	//AsScreen select_screen(Pos2(asWindowSize().x * 2 / 10, asWindowSize().y));

	Pos4 tool_area(0, 0, asWindowSize().x / 10, asWindowSize().y);
	Pos4 paint_area(asWindowSize().x * 2 / 10, 0, asWindowSize().x, asWindowSize().y);
	Pos4 select_area(asWindowSize().x / 10, 0, asWindowSize().x * 2 / 10, asWindowSize().y);

	AsScreen tool_screen(tool_area);
	AsScreen paint_screen(paint_area);
	AsScreen select_screen(select_area);

	//�}�b�v�`��Ǘ�
	PosA4F tool_map_p(0.0f, 0.0f, 2.0f, 1.0f);
	AsMapView tool_map_view(tool_map_p, 'x', &select_screen);
	tool_map_view.setMap(tool_world_p);

	PosA4F select_map_p(0.0f, 0.0f, 2.0f, 1.0f);
	AsMapView select_map_view(select_map_p, 'x', &select_screen);
	select_map_view.setMap(select_world_p);

	PosA4F paint_map_p(0.0f, 0.0f, 4.0f, 12.0f);
	AsMapView paint_map_view(paint_map_p, 'y', &paint_screen);
	paint_map_view.setMap(paint_world_p);

	//�I�����Ă���}�b�v��ID
	size_t select_id = 0;

	while (asLoop())
	{
		//�X�V
		select_main_map.update();
		paint_main_map.update();
		select_map_event.update(select_main_map, att, kl);
		paint_map_event.update(paint_main_map, att, kl1);

		//���_
		select_map_view.setMobView(select_map_event);
		paint_map_view.setMobView(paint_map_event);
		//�}�b�v�`��
		tool_map_view.draw(&tool_main_map, &tool_screen);
		//�}�b�v�`��
		select_map_view.draw(&select_main_map, &select_screen);
		//�C�x���g�`��
		select_map_view.draw(&select_map_event, &select_screen);
		//�}�b�v�`��
		paint_map_view.draw(&paint_main_map, &paint_screen);

		//�h��
		select_map_view.select(&select_main_map, 0, &select_id, select_area,&select_screen);
		paint_map_view.paint(&paint_main_map, 1, select_id, paint_area,&paint_screen);

		//�Y�[��
		asTouchPinch(paint_map_p, 10.0f, 30, paint_area);
		paint_map_view.setLookSize(paint_map_p, 'y', &select_screen);
	}
	return 0;
}