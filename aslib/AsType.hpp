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
	//�`��摜�n
	using OriginatorTexture = int;
	//CPU�摜�n
	using OriginatorImage = int;
	//�剹���n
	using OriginatorBGM = int;
	//�������n
	using OriginatorSE = int;
	//����n
	using OriginatorMovie = int;
	//�����n
	using OriginatorFont = int;
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
	//�`��摜�n
	using OriginatorTexture = s3d::Texture;
	//CPU�摜�n
	using OriginatorImage = int32_t;
	//�剹���n
	using OriginatorBGM = s3d::Audio;
	//�������n
	using OriginatorSE = int32_t;
	//����n
	using OriginatorMovie = int32_t;
	//�����n
	using OriginatorFont = s3d::Font;
//#define TEX_INIT asTexture(U"a.png")
#elif defined(ASLIB_INCLUDE_OF)
	//�`��摜�n
	using OriginatorTexture = ofImage;
	//CPU�摜�n
	using OriginatorImage = int32_t;
	//�剹���n
	using OriginatorBGM = int32_t;
	//�������n
	using OriginatorSE = int32_t;
	//����n
	using OriginatorMovie = int32_t;
	//�����n
	using OriginatorFont = int32_t;
#elif defined(ASLIB_INCLUDE_TP)
	//�`��摜�n
	using OriginatorTexture = int32_t;
	//CPU�摜�n
	using OriginatorImage = int32_t;
	//�剹���n
	using OriginatorBGM = int32_t;
	//�������n
	using OriginatorSE = int32_t;
	//����n
	using OriginatorMovie = int32_t;
	//�����n
	using OriginatorFont = int32_t;
#else //Console
	//�`��摜�n
	using OriginatorTexture = int32_t;
	//CPU�摜�n
	using OriginatorImage = int32_t;
	//�剹���n
	using OriginatorBGM = int32_t;
	//�������n
	using OriginatorSE = int32_t;
	//����n
	using OriginatorMovie = int32_t;
	//�����n
	using OriginatorFont = int32_t;
#endif
}
