#define ASLIB_INCLUDE_DL
#include "AsLib.hpp"
#include "AsFrameWorks.hpp"

struct AsMainApp : public AsBaseApp {
	//-----------------------------------
	//�ϐ�
	//-----------------------------------
	
	PosL4 aaa{ 100, 100, 100, 100 };
	int b = 0;

	//-----------------------------------
	//�֐�
	//-----------------------------------

	//�J�n
	void asInit() {
		
	}
	//�X�V
	void asUpdate() {
		++aaa.x;
	}
	//�`��
	void asDraw() {
		asRect(Pos4(aaa), ColorRGBA(255, 255, 255, 255));
	}
	//�I��
	void asExit() {}
};

int32_t asMain()
{
	MainControl mc(u8"AsFrameWorks", Pos2(1000, 1000), BG_COLOR);
	return asRunApp(mc, new AsMainApp());
}