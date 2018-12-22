//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsProject Library
//
//                    Created by Gaccho (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------
#ifndef INCLUDED_AS_PROJECT_LIBRARY_TYPE
#define INCLUDED_AS_PROJECT_LIBRARY_TYPE


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
	//”wŒi‰æ‘œŒn
	using OriginatorScreen = int;

	inline bool checkTexture(const OriginatorTexture& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkImage(const OriginatorImage& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkBGM(const OriginatorBGM& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkSE(const OriginatorSE& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkMovie(const OriginatorMovie& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkFont(const OriginatorFont& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkScreen(const OriginatorScreen& ori_) { return (ori_ == -1) ? false : true; }

#elif defined(ASLIB_INCLUDE_S3) //Siv3D
	//•`‰æ‰æ‘œŒn
	using OriginatorTexture = s3d::Texture;
	//CPU‰æ‘œŒn
	using OriginatorImage = s3d::Image;
	//å‰¹ºŒn
	using OriginatorBGM = s3d::Audio;
	//•›‰¹ºŒn
	using OriginatorSE = s3d::Audio;
	//“®‰æŒn
	using OriginatorMovie = s3d::VideoWriter;
	//•¶šŒn
	using OriginatorFont = s3d::Font;
	//”wŒi‰æ‘œŒn
	using OriginatorScreen = s3d::Texture;

	inline bool checkTexture(const OriginatorTexture& ori_) { return (!ori_) ? false : true; }
	inline bool checkImage(const OriginatorImage& ori_) { return (!ori_) ? false : true; }
	inline bool checkBGM(const OriginatorBGM& ori_) { return (!ori_) ? false : true; }
	inline bool checkSE(const OriginatorSE& ori_) { return (!ori_) ? false : true; }
	inline bool checkMovie(const OriginatorMovie& ori_) { return (!ori_) ? false : true; }
	inline bool checkFont(const OriginatorFont& ori_) { return (!ori_) ? false : true; }
	inline bool checkScreen(const OriginatorScreen& ori_) { return (!ori_) ? false : true; }

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
	using OriginatorFont = ofTrueTypeFont;
	//”wŒi‰æ‘œŒn
	using OriginatorScreen = int32_t;
#elif defined(ASLIB_INCLUDE_C2)
	//•`‰æ‰æ‘œŒn
	using OriginatorTexture = cocos2d::Sprite*;
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
	//”wŒi‰æ‘œŒn
	using OriginatorScreen = int32_t;

	inline bool checkTexture(const OriginatorTexture& ori_) { return (ori_ == nullptr) ? false : true; }
	inline bool checkImage(const OriginatorImage& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkBGM(const OriginatorBGM& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkSE(const OriginatorSE& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkMovie(const OriginatorMovie& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkFont(const OriginatorFont& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkScreen(const OriginatorScreen& ori_) { return (ori_ == -1) ? false : true; }
#elif defined(ASLIB_INCLUDE_SF)
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
	//”wŒi‰æ‘œŒn
	using OriginatorScreen = int32_t;

	inline bool checkTexture(const OriginatorTexture& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkImage(const OriginatorImage& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkBGM(const OriginatorBGM& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkSE(const OriginatorSE& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkMovie(const OriginatorMovie& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkFont(const OriginatorFont& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkScreen(const OriginatorScreen& ori_) { return (ori_ == -1) ? false : true; }
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
	//”wŒi‰æ‘œŒn
	using OriginatorScreen = int32_t;

	inline bool checkTexture(const OriginatorTexture& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkImage(const OriginatorImage& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkBGM(const OriginatorBGM& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkSE(const OriginatorSE& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkMovie(const OriginatorMovie& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkFont(const OriginatorFont& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkScreen(const OriginatorScreen& ori_) { return (ori_ == -1) ? false : true; }

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
	//”wŒi‰æ‘œŒn
	using OriginatorScreen = int32_t;

	inline bool checkTexture(const OriginatorTexture& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkImage(const OriginatorImage& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkBGM(const OriginatorBGM& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkSE(const OriginatorSE& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkMovie(const OriginatorMovie& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkFont(const OriginatorFont& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkScreen(const OriginatorScreen& ori_) { return (ori_ == -1) ? false : true; }

#endif
}

#endif //Included AsProject Library