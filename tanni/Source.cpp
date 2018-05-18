//�Q�[���G���W��
#define DX_NON_USING_NAMESPACE_DXLIB
#include "DxLib.h"

#define AS_USING_GAME_PAD_MAX
constexpr size_t ASLIB_GAME_PAD_MAX = 16;
#include "AsLib.hpp"


//�V�[���֐�
void startScene(MainControl& mc);
void mainScene(MainControl& mc);
void endScene(MainControl& mc);
void logoScene1(MainControl& mc);


//�V�[��ID
enum :size_t {
	START_SCENE,
	MAIN_SCENE,
	END_SCENE,
	LOGO_SCENE1,
};

//�摜ID
enum :size_t {
	GAHAKU_TEXTURE,
	KURO_TEXTURE
};

//�摜UI��ID
enum :size_t {
	GAHAKU_TEXUI,
	GAHAKU2_TEXUI
};


//�V�[���ǂݍ���
inline void sceneInit(MainControl& mc)
{
	mc.AddScene(START_SCENE, startScene);
	mc.AddScene(MAIN_SCENE, mainScene);
	mc.AddScene(END_SCENE, endScene);
	mc.AddScene(LOGO_SCENE1, logoScene1);
}

//�摜�ǂݍ���
inline void textureInit(MainControl& mc)
{
	mc.textureAdd("gahaku.png");
	mc.textureAdd("kuro.png");
}

//�摜�ǂݍ���
inline void UI_Init(MainControl& mc)
{
	mc.textureUI_Add(GAHAKU_TEXTURE, 200, { 0,0,100,0,0,100,100,180 });
	mc.textureUI_Add(GAHAKU_TEXTURE, 255, { 0,2,45,86,10,0,467,44 });
}

//�J�n���
void startScene(MainControl& mc)
{
	mc.draw8(GAHAKU_TEXUI);
	mc.sceneSelect(MAIN_SCENE);
	return;
}

//���C�����
void mainScene(MainControl& mc)
{
	mc.draw8(GAHAKU2_TEXUI);
	return;
}

//�I�����
void endScene(MainControl& mc)
{
	mc.draw8(GAHAKU_TEXUI);

	//mc.clickTex(KURO_TEXTURE);
	return;
}

void logoScene1(MainControl& mc)
{
	mc.drawLogoOut(GAHAKU_TEXTURE, 2000,1000, START_SCENE);
	return;
}

//���C���֐�
int32_t AsMain()
{
	//�Ǘ��N���X
	MainControl mc("����������", { 360,360 }, BG_COLOR);

	//�ǂݍ���
	sceneInit(mc);
	textureInit(mc);
	UI_Init(mc);

	//
	mc.sceneSelect(LOGO_SCENE1);

	//���C�����[�v
	while (mc.isLoop()) mc.scenePlay();

	//�I������
	asEnd();
	return 0;
}





//----------------------------------------------------------------------------------------------------





//�e���C�u�����̃��C���֐�
#if defined(__DXLIB) //DxLib
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	return int(AsMain());
}
#elif defined(SIV3D_INCLUDED) //Siv3D
void Main()
{
	AsMain();
	return;
}
#else //Console
int main()
{
	return int(AsMain());
}
#endif