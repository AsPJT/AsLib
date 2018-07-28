#define ASLIB_INCLUDE_DL
#include "AsLib.hpp"
int32_t asMain()
{
	//640,360//960, 540//320,180
	MainControl mc(u8"Voice", asPlatformPos(Pos2(960,540), aslib_full_screen), BG_COLOR);

	Texture red(u8"p/2_0.png");

	FontMainData font(10, u8"07�ɂ��܂�t�H���g");

	Texture window_t(u8"p/win3.png", 3, 3);

	//win2//windowa
	MessageWindow window(window_t);
	Texture window_ui(u8"p/cho.png");
	window.readSetString32(u8"p/str.txt");
	//Texture ani(u8"p/pet.png", 8, 4);
	Texture ani(u8"p/ya.png", 3);
	std::vector<std::string> list_name{ u8"�v���C���[",u8"���ԂP",u8"���ԂQ" };
	std::vector<Texture*> list_texture{ &red,&window_ui,&window_t };
	WindowEvent window_event(list_name, list_texture);

	//�E�B���h�E�n
	window.setWindowEvent(window_event);
	window.setPerson(true);
	window.setFont(font);
	window.setSound(u8"p/om");
	////window.setName(u8"�Ԃ����̐l");
	window.setPos(Pos4F(0.02f, 0.7f, 0.98f, 0.98f).ratio());
	window.setFrame(Pos4F(0.02f, 0.7f, 0.98f, 0.98f).ratio().h/8);
	window.setLine(4);
	window.setFastForward(true);
	////window.setPerson(red);
	window.setEndAnime(ani);
	window.setUpdate(8);
	window.setUpdateEnd(6);
	//window.setEffectTimer(20);
	//window.setEffect(aslib_effect_event_zoom);

	asStop();
	while (asLoop()) {

		//�E�B���h�E�֘A
		if (window.isWindow()) window.playEffect().update().updateEnd().drawPerson().drawWindow().writeString().drawEndAnime().playSound().printString().printName().next(asKeyEnterUp());
		window.initWindow(asKeyY_Up());

		asPrint("%s", asDrag().c_str());

	}
	return 0;
}