//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asライブラリ
//
//                    制作者: がっちょ (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
#if defined(ASLIB_INCLUDE_DL) //DxLib
	//フォント系
	using Font = int;
	//テクスチャ系
	using Tex = int;
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
	//フォント系
	using Font = s3d::Font;
	//テクスチャ系
	using Tex = s3d::Texture;
//#define TEX_INIT asTex(U"a.png")
#else //Console
	//フォント系
	using Font = int32_t;
	//テクスチャ系
	using Tex = int32_t;
#endif
}
