//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asƒ‰ƒCƒuƒ‰ƒŠ
//
//                    §ìÒ: ‚ª‚Á‚¿‚å (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
#if defined(ASLIB_INCLUDE_DL) //DxLib
	//•`‰æ‰æ‘œŒn
	using OriginatorTexture = int;
	//CPU‰æ‘œŒn
	using OriginatorImage = int;
	//å‰¹ºŒn
	using OriginatorBGM = int;
	//•›‰¹ºŒn
	using OriginatorSE = int;
	//“®‰æŒn
	using OriginatorMovie = int;
	//•¶šŒn
	using OriginatorFont = int;
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
	//•`‰æ‰æ‘œŒn
	using OriginatorTexture = s3d::Texture;
	//CPU‰æ‘œŒn
	using OriginatorImage = int32_t;
	//å‰¹ºŒn
	using OriginatorBGM = s3d::Audio;
	//•›‰¹ºŒn
	using OriginatorSE = int32_t;
	//“®‰æŒn
	using OriginatorMovie = int32_t;
	//•¶šŒn
	using OriginatorFont = s3d::Font;
//#define TEX_INIT asTexture(U"a.png")
#elif defined(ASLIB_INCLUDE_OF)
	//•`‰æ‰æ‘œŒn
	using OriginatorTexture = ofImage;
	//CPU‰æ‘œŒn
	using OriginatorImage = int32_t;
	//å‰¹ºŒn
	using OriginatorBGM = int32_t;
	//•›‰¹ºŒn
	using OriginatorSE = int32_t;
	//“®‰æŒn
	using OriginatorMovie = int32_t;
	//•¶šŒn
	using OriginatorFont = int32_t;
#elif defined(ASLIB_INCLUDE_TP)
	//•`‰æ‰æ‘œŒn
	using OriginatorTexture = int32_t;
	//CPU‰æ‘œŒn
	using OriginatorImage = int32_t;
	//å‰¹ºŒn
	using OriginatorBGM = int32_t;
	//•›‰¹ºŒn
	using OriginatorSE = int32_t;
	//“®‰æŒn
	using OriginatorMovie = int32_t;
	//•¶šŒn
	using OriginatorFont = int32_t;
#else //Console
	//•`‰æ‰æ‘œŒn
	using OriginatorTexture = int32_t;
	//CPU‰æ‘œŒn
	using OriginatorImage = int32_t;
	//å‰¹ºŒn
	using OriginatorBGM = int32_t;
	//•›‰¹ºŒn
	using OriginatorSE = int32_t;
	//“®‰æŒn
	using OriginatorMovie = int32_t;
	//•¶šŒn
	using OriginatorFont = int32_t;
#endif
}
