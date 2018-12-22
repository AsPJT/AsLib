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
	//�w�i�摜�n
	using OriginatorScreen = int;

	inline bool checkTexture(const OriginatorTexture& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkImage(const OriginatorImage& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkBGM(const OriginatorBGM& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkSE(const OriginatorSE& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkMovie(const OriginatorMovie& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkFont(const OriginatorFont& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkScreen(const OriginatorScreen& ori_) { return (ori_ == -1) ? false : true; }

#elif defined(ASLIB_INCLUDE_S3) //Siv3D
	//�`��摜�n
	using OriginatorTexture = s3d::Texture;
	//CPU�摜�n
	using OriginatorImage = s3d::Image;
	//�剹���n
	using OriginatorBGM = s3d::Audio;
	//�������n
	using OriginatorSE = s3d::Audio;
	//����n
	using OriginatorMovie = s3d::VideoWriter;
	//�����n
	using OriginatorFont = s3d::Font;
	//�w�i�摜�n
	using OriginatorScreen = s3d::Texture;

	inline bool checkTexture(const OriginatorTexture& ori_) { return (!ori_) ? false : true; }
	inline bool checkImage(const OriginatorImage& ori_) { return (!ori_) ? false : true; }
	inline bool checkBGM(const OriginatorBGM& ori_) { return (!ori_) ? false : true; }
	inline bool checkSE(const OriginatorSE& ori_) { return (!ori_) ? false : true; }
	inline bool checkMovie(const OriginatorMovie& ori_) { return (!ori_) ? false : true; }
	inline bool checkFont(const OriginatorFont& ori_) { return (!ori_) ? false : true; }
	inline bool checkScreen(const OriginatorScreen& ori_) { return (!ori_) ? false : true; }

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
	using OriginatorFont = ofTrueTypeFont;
	//�w�i�摜�n
	using OriginatorScreen = int32_t;
#elif defined(ASLIB_INCLUDE_C2)
	//�`��摜�n
	using OriginatorTexture = cocos2d::Sprite*;
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
	//�w�i�摜�n
	using OriginatorScreen = int32_t;

	inline bool checkTexture(const OriginatorTexture& ori_) { return (ori_ == nullptr) ? false : true; }
	inline bool checkImage(const OriginatorImage& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkBGM(const OriginatorBGM& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkSE(const OriginatorSE& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkMovie(const OriginatorMovie& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkFont(const OriginatorFont& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkScreen(const OriginatorScreen& ori_) { return (ori_ == -1) ? false : true; }
#elif defined(ASLIB_INCLUDE_SF)
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
	//�w�i�摜�n
	using OriginatorScreen = int32_t;

	inline bool checkTexture(const OriginatorTexture& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkImage(const OriginatorImage& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkBGM(const OriginatorBGM& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkSE(const OriginatorSE& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkMovie(const OriginatorMovie& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkFont(const OriginatorFont& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkScreen(const OriginatorScreen& ori_) { return (ori_ == -1) ? false : true; }
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
	//�w�i�摜�n
	using OriginatorScreen = int32_t;

	inline bool checkTexture(const OriginatorTexture& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkImage(const OriginatorImage& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkBGM(const OriginatorBGM& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkSE(const OriginatorSE& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkMovie(const OriginatorMovie& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkFont(const OriginatorFont& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkScreen(const OriginatorScreen& ori_) { return (ori_ == -1) ? false : true; }

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
	//�w�i�摜�n
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