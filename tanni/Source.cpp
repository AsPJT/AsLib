//�Q�[���G���W��
#define DX_NON_USING_NAMESPACE_DXLIB
#include "DxLib.h"

#define AS_USING_GAME_PAD_MAX
constexpr size_t ASLIB_GAME_PAD_MAX = 16;
#include "AsLib.hpp"

//�V�[��
enum :size_t {
	START_SCENE
};

//�摜
enum :size_t {
	KURO_TEXTURE
};

//�X�^�[�g���
void StartScene(MainControl& mc)
{
	mc.texDraw(KURO_TEXTURE);
	return;
}

//�V�[���R���g���[��������
inline void sceneInit(MainControl& mc)
{
	mc.AddScene(START_SCENE, StartScene);
}

//�摜�R���g���[��������
inline void textureInit(MainControl& mc)
{
	mc.textureAdd("kuro.png");
}

//���C���֐�
int32_t AsMain()
{
	//��{�ݒ�
	MainData as = asReadInit("b.txt", "����������", {720,720}, BG_COLOR);
	
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