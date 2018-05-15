//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - As���C�u����
//
//                    �����: �������� (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
#if defined(__DXLIB) //DxLib
	//using TEXTURE_VECTOR_TYPE = int;
	//using TEXTURE_VECTOR = vector<int>;

	//�t�H���g�n
	using AsFont = int;
	constexpr int FONT_INIT = -1;

	//�e�N�X�`���n
	using Tex = int;
	constexpr int TEX_INIT = -1;

#elif defined(SIV3D_INCLUDED) //Siv3D
	using TEXTURE_VECTOR = Array<TextureRegion>;
	using AsFont = Font;
#define FONT_INIT Font(60)
	using asTex = Texture;
#define TEX_INIT asTex(U"a.png")
#else //Console

#endif
}
