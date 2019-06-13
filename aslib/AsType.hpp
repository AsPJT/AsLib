/*#######################################################################################
	Made by Kasugaccho
	Made by As Project
	https://github.com/Kasugaccho/AsLib
	wanotaitei@gmail.com

	This code is licensed under CC0.
#######################################################################################*/
#ifndef INCLUDED_AS_PROJECT_LIBRARY_TYPE
#define INCLUDED_AS_PROJECT_LIBRARY_TYPE


namespace AsLib
{
#if defined(ASLIB_INCLUDE_DL) //DxLib
	//描画画像系
	using OriginatorTexture = int;
	//CPU画像系
	using OriginatorImage = int;
	//主音声系
	using OriginatorBGM = int;
	//副音声系
	using OriginatorSE = int;
	//動画系
	using OriginatorMovie = int;
	//文字系
	using OriginatorFont = int;
	//背景画像系
	using OriginatorScreen = int;

	inline bool checkTexture(const OriginatorTexture& ori_) noexcept { return (ori_ == -1) ? false : true; }
	inline bool checkImage(const OriginatorImage& ori_) noexcept { return (ori_ == -1) ? false : true; }
	inline bool checkBGM(const OriginatorBGM& ori_) noexcept { return (ori_ == -1) ? false : true; }
	inline bool checkSE(const OriginatorSE& ori_) noexcept { return (ori_ == -1) ? false : true; }
	inline bool checkMovie(const OriginatorMovie& ori_) noexcept { return (ori_ == -1) ? false : true; }
	inline bool checkFont(const OriginatorFont& ori_) noexcept { return (ori_ == -1) ? false : true; }
	inline bool checkScreen(const OriginatorScreen& ori_) noexcept { return (ori_ == -1) ? false : true; }

#elif defined(ASLIB_INCLUDE_S3) //Siv3D
	//描画画像系
	using OriginatorTexture = s3d::Texture;
	//CPU画像系
	using OriginatorImage = s3d::Image;
	//主音声系
	using OriginatorBGM = s3d::Audio;
	//副音声系
	using OriginatorSE = s3d::Audio;
	//動画系
	using OriginatorMovie = s3d::VideoWriter;
	//文字系
	using OriginatorFont = s3d::Font;
	//背景画像系
	using OriginatorScreen = s3d::Texture;

	inline bool checkTexture(const OriginatorTexture& ori_) noexcept { return (!ori_) ? false : true; }
	inline bool checkImage(const OriginatorImage& ori_) noexcept { return (!ori_) ? false : true; }
	inline bool checkBGM(const OriginatorBGM& ori_) noexcept { return (!ori_) ? false : true; }
	inline bool checkSE(const OriginatorSE& ori_) noexcept { return (!ori_) ? false : true; }
	inline bool checkMovie(const OriginatorMovie& ori_) noexcept { return (!ori_) ? false : true; }
	inline bool checkFont(const OriginatorFont& ori_) noexcept { return (!ori_) ? false : true; }
	inline bool checkScreen(const OriginatorScreen& ori_) noexcept { return (!ori_) ? false : true; }

#elif defined(ASLIB_INCLUDE_OF)
	//描画画像系
	using OriginatorTexture = ofImage;
	//CPU画像系
	using OriginatorImage = std::int32_t;
	//主音声系
	using OriginatorBGM = std::int32_t;
	//副音声系
	using OriginatorSE = std::int32_t;
	//動画系
	using OriginatorMovie = std::int32_t;
	//文字系
	using OriginatorFont = ofTrueTypeFont;
	//背景画像系
	using OriginatorScreen = std::int32_t;
#elif defined(ASLIB_INCLUDE_C2)
	//描画画像系
	using OriginatorTexture = cocos2d::Sprite*;
	//CPU画像系
	using OriginatorImage = std::int32_t;
	//主音声系
	using OriginatorBGM = std::int32_t;
	//副音声系
	using OriginatorSE = std::int32_t;
	//動画系
	using OriginatorMovie = std::int32_t;
	//文字系
	using OriginatorFont = std::int32_t;
	//背景画像系
	using OriginatorScreen = std::int32_t;

	inline bool checkTexture(const OriginatorTexture& ori_) noexcept { return (ori_ == nullptr) ? false : true; }
	inline bool checkImage(const OriginatorImage& ori_) noexcept { return (ori_ == -1) ? false : true; }
	inline bool checkBGM(const OriginatorBGM& ori_) noexcept { return (ori_ == -1) ? false : true; }
	inline bool checkSE(const OriginatorSE& ori_) noexcept { return (ori_ == -1) ? false : true; }
	inline bool checkMovie(const OriginatorMovie& ori_) noexcept { return (ori_ == -1) ? false : true; }
	inline bool checkFont(const OriginatorFont& ori_) noexcept { return (ori_ == -1) ? false : true; }
	inline bool checkScreen(const OriginatorScreen& ori_) noexcept { return (ori_ == -1) ? false : true; }
#elif defined(ASLIB_INCLUDE_SF)
	//描画画像系
	using OriginatorTexture = std::int32_t;
	//CPU画像系
	using OriginatorImage = std::int32_t;
	//主音声系
	using OriginatorBGM = std::int32_t;
	//副音声系
	using OriginatorSE = std::int32_t;
	//動画系
	using OriginatorMovie = std::int32_t;
	//文字系
	using OriginatorFont = std::int32_t;
	//背景画像系
	using OriginatorScreen = std::int32_t;

	inline bool checkTexture(const OriginatorTexture& ori_) noexcept { return (ori_ == -1) ? false : true; }
	inline bool checkImage(const OriginatorImage& ori_) noexcept { return (ori_ == -1) ? false : true; }
	inline bool checkBGM(const OriginatorBGM& ori_) noexcept { return (ori_ == -1) ? false : true; }
	inline bool checkSE(const OriginatorSE& ori_) noexcept { return (ori_ == -1) ? false : true; }
	inline bool checkMovie(const OriginatorMovie& ori_) noexcept { return (ori_ == -1) ? false : true; }
	inline bool checkFont(const OriginatorFont& ori_) noexcept { return (ori_ == -1) ? false : true; }
	inline bool checkScreen(const OriginatorScreen& ori_) noexcept { return (ori_ == -1) ? false : true; }
#elif defined(ASLIB_INCLUDE_TP)
	//描画画像系
	using OriginatorTexture = std::int32_t;
	//CPU画像系
	using OriginatorImage = std::int32_t;
	//主音声系
	using OriginatorBGM = std::int32_t;
	//副音声系
	using OriginatorSE = std::int32_t;
	//動画系
	using OriginatorMovie = std::int32_t;
	//文字系
	using OriginatorFont = std::int32_t;
	//背景画像系
	using OriginatorScreen = std::int32_t;

	inline bool checkTexture(const OriginatorTexture& ori_) noexcept { return (ori_ == -1) ? false : true; }
	inline bool checkImage(const OriginatorImage& ori_) noexcept { return (ori_ == -1) ? false : true; }
	inline bool checkBGM(const OriginatorBGM& ori_) noexcept { return (ori_ == -1) ? false : true; }
	inline bool checkSE(const OriginatorSE& ori_) noexcept { return (ori_ == -1) ? false : true; }
	inline bool checkMovie(const OriginatorMovie& ori_) noexcept { return (ori_ == -1) ? false : true; }
	inline bool checkFont(const OriginatorFont& ori_) noexcept { return (ori_ == -1) ? false : true; }
	inline bool checkScreen(const OriginatorScreen& ori_) noexcept { return (ori_ == -1) ? false : true; }

#else //Console
	//描画画像系
	using OriginatorTexture = std::int32_t;
	//CPU画像系
	using OriginatorImage = std::int32_t;
	//主音声系
	using OriginatorBGM = std::int32_t;
	//副音声系
	using OriginatorSE = std::int32_t;
	//動画系
	using OriginatorMovie = std::int32_t;
	//文字系
	using OriginatorFont = std::int32_t;
	//背景画像系
	using OriginatorScreen = std::int32_t;

	inline bool checkTexture(const OriginatorTexture& ori_) noexcept { return (ori_ == -1) ? false : true; }
	inline bool checkImage(const OriginatorImage& ori_) noexcept { return (ori_ == -1) ? false : true; }
	inline bool checkBGM(const OriginatorBGM& ori_) noexcept { return (ori_ == -1) ? false : true; }
	inline bool checkSE(const OriginatorSE& ori_) noexcept { return (ori_ == -1) ? false : true; }
	inline bool checkMovie(const OriginatorMovie& ori_) noexcept { return (ori_ == -1) ? false : true; }
	inline bool checkFont(const OriginatorFont& ori_) noexcept { return (ori_ == -1) ? false : true; }
	inline bool checkScreen(const OriginatorScreen& ori_) noexcept { return (ori_ == -1) ? false : true; }

#endif
}

#endif //Included AsProject Library