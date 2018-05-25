//�Q�[���G���W��
#define DX_NON_USING_NAMESPACE_DXLIB
#include "DxLib.h"

#define AS_USING_GAME_PAD_MAX
constexpr size_t ASLIB_GAME_PAD_MAX = 16;
#include "AsLib.hpp"

//�Ǘ��N���X�ȗ�
using MC = AsLib::MainControl;

//�V�[���֐�
void startScene(MC& mc);
void mainScene(MC& mc);
void endScene(MC& mc);
void logoScene1(MC& mc);
void logoScene2(MC& mc);
void logoScene3(MC& mc);
void logoScene4(MC& mc);

//�V�[��ID
enum :size_t {
	START_SCENE,
	MAIN_SCENE,
	END_SCENE,
	LOGO_SCENE1,
	LOGO_SCENE2,
	LOGO_SCENE3,
	LOGO_SCENE4,
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

//�ϐ�ID
enum :size_t {
	game_score,
};

//�V�[���ǂݍ���
inline void sceneInit(MC& mc)
{
	mc.AddScene(START_SCENE, startScene);
	mc.AddScene(MAIN_SCENE, mainScene);
	mc.AddScene(END_SCENE, endScene);
	mc.AddScene(LOGO_SCENE1, logoScene1);
	mc.AddScene(LOGO_SCENE2, logoScene2);
	mc.AddScene(LOGO_SCENE3, logoScene3);
	mc.AddScene(LOGO_SCENE4, logoScene4);
}

//�摜�ǂݍ���
inline void textureInit(MC& mc)
{
	mc.textureAdd("gahaku.png");
	mc.textureAdd("kuro.png");
}

//�摜�ǂݍ���
inline void UI_Init(MC& mc)
{
	mc.textureUI_Add(KURO_TEXTURE, 200, { 200,200,500,500 });
	mc.textureUI_Add(GAHAKU_TEXTURE, 255, { 0,0,200,200 });
}

//�J�n���
void startScene(MC& mc)
{
	//�`�惌�C���[
	mc.draw4(GAHAKU_TEXUI);

	//���߃��C���[
	if (mc.isTexUI_Touch(GAHAKU_TEXUI)) mc.sceneSelect(MAIN_SCENE);
}

//���C�����
void mainScene(MC& mc)
{

	mc.draw4(GAHAKU2_TEXUI);

	//���߃��C���[
	if (mc.isTexUI_Touch(GAHAKU2_TEXUI)) mc.sceneSelect(LOGO_SCENE1);
}

//�I�����
void endScene(MC& mc)
{
	mc.draw4(GAHAKU_TEXUI);

	//mc.clickTex(KURO_TEXTURE);
}

//�^�C�g�����S1
void logoScene1(MC& mc)
{
	mc.drawLogoInOut(GAHAKU_TEXTURE, 1000, 2000, 3000, START_SCENE);
	//if (mc.isTouch()) mc.sceneSelect(START_SCENE);
}

void logoScene2(MC& mc)
{
	mc.drawLogoInOut(GAHAKU_TEXTURE, 1000, 2000, 3000, LOGO_SCENE2);
}

void logoScene3(MC& mc)
{
}

void logoScene4(MC& mc)
{
}

//���C���֐�
int32_t AsMain()
{
	//�Ǘ��N���X
	MC mc("����������", { 720,360 }, BG_COLOR);

	//�ǂݍ���
	sceneInit(mc);
	textureInit(mc);
	UI_Init(mc);

	//�����V�[��
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