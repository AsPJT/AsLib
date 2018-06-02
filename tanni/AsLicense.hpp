//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asライブラリ
//
//                    制作者: がっちょ (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
	//ライセンス一覧
	enum :size_t {
		aslib_LICENSE,
		libjpeg_LICENSE,
		libpng_LICENSE,
		libtiff_LICENSE,
		libogg_LICENSE,
		Opus_audio_codec_LICENSE,
		Opusfile_LICENSE,
		Mersenne_Twister_LICENSE,
		Bullet_LICENSE,
		DX_Library_LICENSE,
		Siv3D_Engine_LICENSE,
		HamFramework_LICENSE,
		Abseil_LICENSE,
		AngelCode_Scripting_Library_LICENSE,
		Box2D_LICENSE,
		cereal_LICENSE,
		Convenient_Constructs_For_Stepping_Through_a_Range_of_Values_LICENSE,
		clip2tri_LICENSE,
		Clipper_LICENSE,
		cpptoml_LICENSE,
		DirectXMath_LICENSE,
		double_conversion_LICENSE,
		Easing_Equations_LICENSE,
		easyexif_LICENSE,
		FID_LICENSE,
		fmt_LICENSE,
		Font_Awesome_LICENSE,
		FreeType_LICENSE,
		frontal_cat_face_detector_LICENSE,
		giflib_LICENSE,
		HarfBuzz_LICENSE,
		hopscotch_map_LICENSE,
		kld_intersections_LICENSE,
		kld_polynomial_LICENSE,
		lbpcascade_animeface_LICENSE,
		libjpeg_turbo_LICENSE,
		libsvm_LICENSE,
		LineSegmentIntersection_LICENSE,
		miniutf_LICENSE,
		msinttypes_r29_LICENSE,
		muparser_LICENSE,
		nanoflann_LICENSE,
		Noto_Fonts_LICENSE,
		OpenCV_LICENSE,
		Poly2Tri_LICENSE,
		pffft_LICENSE,
		RapidJSON_LICENSE,
		Recast_Detour_LICENSE,
		SFMT_LICENSE,
		Simple_DirectMedia_Layer_LICENSE,
		TinySoundFont_LICENSE,
		TinyXML_2_LICENSE,
		xxHash_LICENSE,
		zlib_LICENSE,
		Zstandard_LICENSE,
	};

	//使用中のライセンス
	constexpr size_t aslib_license[] = { 
#if defined(ASLIB_INCLUDE_DL) //DxLib
		libjpeg_LICENSE,
		libpng_LICENSE,
		libtiff_LICENSE,
		libogg_LICENSE,
		Opus_audio_codec_LICENSE,
		Opusfile_LICENSE,
		Mersenne_Twister_LICENSE,
		Bullet_LICENSE,
		DX_Library_LICENSE,
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		Siv3D_Engine_LICENSE,
		HamFramework_LICENSE,
		Abseil_LICENSE,
		AngelCode_Scripting_Library_LICENSE,
		Box2D_LICENSE,
		cereal_LICENSE,
		Convenient_Constructs_For_Stepping_Through_a_Range_of_Values_LICENSE,
		clip2tri_LICENSE,
		Clipper_LICENSE,
		cpptoml_LICENSE,
		DirectXMath_LICENSE,
		double_conversion_LICENSE,
		Easing_Equations_LICENSE,
		easyexif_LICENSE,
		FID_LICENSE,
		fmt_LICENSE,
		Font_Awesome_LICENSE,
		FreeType_LICENSE,
		frontal_cat_face_detector_LICENSE,
		giflib_LICENSE,
		HarfBuzz_LICENSE,
		hopscotch_map_LICENSE,
		kld_intersections_LICENSE,
		kld_polynomial_LICENSE,
		lbpcascade_animeface_LICENSE,
		libjpeg_turbo_LICENSE,
		libsvm_LICENSE,
		LineSegmentIntersection_LICENSE,
		miniutf_LICENSE,
		msinttypes_r29_LICENSE,
		muparser_LICENSE,
		nanoflann_LICENSE,
		Noto_Fonts_LICENSE,
		OpenCV_LICENSE,
		Poly2Tri_LICENSE,
		pffft_LICENSE,
		RapidJSON_LICENSE,
		Recast_Detour_LICENSE,
		SFMT_LICENSE,
		Simple_DirectMedia_Layer_LICENSE,
		TinySoundFont_LICENSE,
		TinyXML_2_LICENSE,
		xxHash_LICENSE,
		zlib_LICENSE,
		Zstandard_LICENSE,
#else //Console
#endif
		aslib_LICENSE
	};

	constexpr size_t aslib_license_size = sizeof(aslib_license) / sizeof(size_t);

	void asLicense(const size_t i)
	{
		switch (i)
		{
		case(aslib_LICENSE):
			
			break;
		case(libjpeg_LICENSE):
			asPrint("Copyright (C) 1991-2013, Thomas G. Lane, Guido Vollbeding.\nthis software is based in part on the work of the Independent JPEG Group\n");
			break;
		case(libpng_LICENSE):

			break;
		case(libtiff_LICENSE):

			break;
		case(libogg_LICENSE):

			break;
		case(Opus_audio_codec_LICENSE):

			break;
		case(Opusfile_LICENSE):

			break;
		case(Mersenne_Twister_LICENSE):

			break;
		case(Bullet_LICENSE):

			break;
		case(DX_Library_LICENSE):

			break;
		case(Siv3D_Engine_LICENSE):

			break;
		case(HamFramework_LICENSE):

			break;
		case(Abseil_LICENSE):

			break;
		case(AngelCode_Scripting_Library_LICENSE):

			break;
		case(Box2D_LICENSE):

			break;
		case(cereal_LICENSE):

			break;
		case(Convenient_Constructs_For_Stepping_Through_a_Range_of_Values_LICENSE):

			break;
		case(clip2tri_LICENSE):

			break;
		case(Clipper_LICENSE):

			break;
		case(cpptoml_LICENSE):

			break;
		case(DirectXMath_LICENSE):

			break;
		case(double_conversion_LICENSE):

			break;
		case(Easing_Equations_LICENSE):

			break;
		case(easyexif_LICENSE):

			break;
		case(FID_LICENSE):

			break;
		case(fmt_LICENSE):

			break;
		case(Font_Awesome_LICENSE):

			break;
		case(FreeType_LICENSE):

			break;
		case(frontal_cat_face_detector_LICENSE):

			break;
		case(giflib_LICENSE):

			break;
		case(HarfBuzz_LICENSE):

			break;
		case(hopscotch_map_LICENSE):

			break;
		case(kld_intersections_LICENSE):

			break;
		case(kld_polynomial_LICENSE):

			break;
		case(lbpcascade_animeface_LICENSE):

			break;
		case(libjpeg_turbo_LICENSE):

			break;
		case(libsvm_LICENSE):

			break;
		case(LineSegmentIntersection_LICENSE):

			break;
		case(miniutf_LICENSE):

			break;
		case(msinttypes_r29_LICENSE):

			break;
		case(muparser_LICENSE):

			break;
		case(nanoflann_LICENSE):

			break;
		case(Noto_Fonts_LICENSE):

			break;
		case(OpenCV_LICENSE):

			break;
		case(Poly2Tri_LICENSE):

			break;
		case(pffft_LICENSE):

			break;
		case(RapidJSON_LICENSE):

			break;
		case(Recast_Detour_LICENSE):

			break;
		case(SFMT_LICENSE):

			break;
		case(Simple_DirectMedia_Layer_LICENSE):

			break;
		case(TinySoundFont_LICENSE):

			break;
		case(TinyXML_2_LICENSE):

			break;
		case(xxHash_LICENSE):

			break;
		case(zlib_LICENSE):

			break;
		case(Zstandard_LICENSE):

			break;
		}
	}


}
