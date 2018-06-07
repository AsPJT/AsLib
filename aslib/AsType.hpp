//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - As���C�u����
//
//                    �����: �������� (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
#if defined(ASLIB_INCLUDE_DL) //DxLib

	//�t�H���g�n
	using Font = int;
	constexpr int FONT_INIT = -1;

	//�e�N�X�`���n
	using Tex = int;
	constexpr int TEX_INIT = -1;

#elif defined(ASLIB_INCLUDE_S3) //Siv3D
	using TEXTURE_VECTOR = s3d::Array<s3d::TextureRegion>;
	using AsFont = s3d::Font;
#define FONT_INIT Font(60)
	using Tex = s3d::Texture;
#define TEX_INIT asTex(U"a.png")
#else //Console

#endif
}
