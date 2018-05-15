//�Q�[���G���W��
#define DX_NON_USING_NAMESPACE_DXLIB
#include "DxLib.h"

#define AS_USING_GAME_PAD_MAX
constexpr size_t ASLIB_GAME_PAD_MAX = 16;
#include "AsLib.hpp"

void StartScene(MainControl& mc);
void MainScene(MainControl& mc);

//�V�[��ID
enum :size_t {
	START_SCENE
};

//�V�[���R���g���[��������
inline void sceneInit(MainControl& mc)
{
	mc.AddScene(START_SCENE, StartScene);
}

//�摜ID
enum :size_t {
	GAHAKU_TEXTURE
};

//�摜�R���g���[��������
inline void textureInit(MainControl& mc)
{
	mc.textureAdd("gahaku.png");
}

//�X�^�[�g���
void StartScene(MainControl& mc)
{
	mc.texDraw(GAHAKU_TEXTURE);

	return;
}

//���C�����
void MainScene(MainControl& mc)
{
	mc.texDraw(GAHAKU_TEXTURE);
	return;
}

//���C���֐�
int32_t AsMain()
{
	//��{�ݒ�
	MainData as("����������", {720,720}, BG_COLOR);
	
	//�Ǘ��N���X
	MainControl mc(as);

	//�V�[���ǉ�
	sceneInit(mc);

	//�摜�ǉ�
	textureInit(mc);

	//�����V�[�����X�^�[�g��ʂɂ���
	mc.sceneSelect(START_SCENE);

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