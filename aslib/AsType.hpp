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
	//�e�N�X�`���n
	using Tex = int;
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
	//�t�H���g�n
	using Font = s3d::Font;
	//�e�N�X�`���n
	using Tex = s3d::Texture;
//#define TEX_INIT asTex(U"a.png")
#else //Console
	//�t�H���g�n
	using Font = int32_t;
	//�e�N�X�`���n
	using Tex = int32_t;
#endif
}
