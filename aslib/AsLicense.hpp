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
		JUMAN_LICENSE,
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
		aslib_LICENSE,
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
		JUMAN_LICENSE,
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
	};

	constexpr size_t aslib_license_size = sizeof(aslib_license) / sizeof(size_t);

	struct Copyright {
		const char* const c;
		const int32_t start_year;
		const int32_t end_year;
		constexpr Copyright(const char* const c_, const int32_t s_, const int32_t e_) :c(c_), start_year(s_), end_year(e_) {};
	};

	void asLicense(const size_t i, std::string& name_, std::vector<Copyright>& copyright_, std::string& str_)
	{
		switch (i)
		{
		case(aslib_LICENSE):
			name_ = u8"AsLib";
			str_ = u8"These codes are licensed under CC0.";
			return;
		case(libjpeg_LICENSE):
			name_ = u8"libjpeg";
			str_ = u8"This software is based in part on the work of the Independent JPEG Group.";
			return;
		case(libpng_LICENSE):
			name_ = u8"libpng";
			copyright_.emplace_back(Copyright(u8"Glenn Randers-Pehrson", 1998, 2017));
			str_ = u8"";
			return;
		case(libtiff_LICENSE):
			name_ = u8"";
			copyright_.emplace_back(Copyright(u8"", 0, 0));
			str_ = u8"";
			return;
		case(libogg_LICENSE):
			name_ = u8"";
			copyright_.emplace_back(Copyright(u8"", 0, 0));
			str_ = u8"";
			return;
		case(Opus_audio_codec_LICENSE):
			name_ = u8"";
			copyright_.emplace_back(Copyright(u8"", 0, 0));
			str_ = u8"";
			return;
		case(Opusfile_LICENSE):
			name_ = u8"";
			copyright_.emplace_back(Copyright(u8"", 0, 0));
			str_ = u8"";
			return;
		case(Mersenne_Twister_LICENSE):
			name_ = u8"";
			copyright_.emplace_back(Copyright(u8"", 0, 0));
			str_ = u8"";
			return;
		case(Bullet_LICENSE):
			name_ = u8"";
			copyright_.emplace_back(Copyright(u8"", 0, 0));
			str_ = u8"";
			return;
		case(DX_Library_LICENSE):
			name_ = u8"";
			copyright_.emplace_back(Copyright(u8"", 0, 0));
			str_ = u8"";
			return;
		case(Siv3D_Engine_LICENSE):
			name_ = u8"Siv3D Engine";
			copyright_.emplace_back(Copyright(u8"Ryo Suzuki", 2008 , 2018));
			copyright_.emplace_back(Copyright(u8"OpenSiv3D Project", 2016, 2018));
			str_ = u8"";
			return;
		case(HamFramework_LICENSE):
			name_ = u8"HamFramework";
			copyright_.emplace_back(Copyright(u8"HAMSTRO", 2014 , 2018));
			copyright_.emplace_back(Copyright(u8"OpenSiv3D Project", 2016 , 2018));
			str_ = u8"";
			return;
		case(Abseil_LICENSE):
			name_ = u8"Abseil";
			copyright_.emplace_back(Copyright(u8"The Abseil Authors.", 2017, 0));
			str_ = u8"";
			return;
		case(AngelCode_Scripting_Library_LICENSE):
			name_ = u8"AngelCode Scripting Library";
			copyright_.emplace_back(Copyright(u8"Andreas Jonsson", 2003, 2017));
			str_ = u8"";
			return;
		case(Box2D_LICENSE):
			name_ = u8"Box2D";
			copyright_.emplace_back(Copyright(u8"Erin Catto http://www.box2d.org", 2006, 2017));
			str_ = u8"";
			return;
		case(cereal_LICENSE):
			name_ = u8"cereal";
			copyright_.emplace_back(Copyright(u8"Randolph Voorhies, Shane Grant All rights reserved.", 2014, 0));
			str_ = u8"";
			return;
		case(Convenient_Constructs_For_Stepping_Through_a_Range_of_Values_LICENSE):
			name_ = u8"Convenient Constructs For Stepping Through a Range of Values";
			copyright_.emplace_back(Copyright(u8"Mikhail Semenov", 0, 0));
			str_ = u8"Licenced with the Code Project Open Licence (CPOL) http://www.codeproject.com/info/cpol10.aspx";
			return;
		case(clip2tri_LICENSE):
			name_ = u8"clip2tri";
			copyright_.emplace_back(Copyright(u8"Bitfighter developers", 2014, 0));
			str_ = u8"";
			return;
		case(Clipper_LICENSE):
			name_ = u8"Clipper";
			copyright_.emplace_back(Copyright(u8"Angus Johnson", 2010 , 2014));
			str_ = u8"";
			return;
		case(cpptoml_LICENSE):
			name_ = u8"cpptoml";
			copyright_.emplace_back(Copyright(u8"Chase Geigle", 2014, 0));
			str_ = u8"";
			return;
		case(DirectXMath_LICENSE):
			name_ = u8"DirectXMath";
			copyright_.emplace_back(Copyright(u8"Microsoft Corp", 2017, 0));
			str_ = u8"";
			return;
		case(double_conversion_LICENSE):
			name_ = u8"double-conversion";
			copyright_.emplace_back(Copyright(u8"the V8 project authors. All rights reserved.", 2006 , 2011));
			str_ = u8"";
			return;
		case(Easing_Equations_LICENSE):
			name_ = u8"Easing Equations";
			copyright_.emplace_back(Copyright(u8"Robert Penner", 2001, 0));
			str_ = u8"";
			return;
		case(easyexif_LICENSE):
			name_ = u8"easyexif";
			copyright_.emplace_back(Copyright(u8"Mayank Lahiri", 2010 , 2015));
			str_ = u8"";
			return;
		case(FID_LICENSE):
			name_ = u8"FID";
			copyright_.emplace_back(Copyright(u8"hec", 2017, 0));
			str_ = u8"";
			return;
		case(fmt_LICENSE):
			name_ = u8"fmt";
			copyright_.emplace_back(Copyright(u8"Victor Zverovich", 2012 , 2016));
			str_ = u8"";
			return;
		case(Font_Awesome_LICENSE):
			name_ = u8"Font Awesome";
			str_ = u8"";
			return;
		case(FreeType_LICENSE):
			name_ = u8"FreeType";
			str_ = u8"";
			return;
		case(frontal_cat_face_detector_LICENSE):
			name_ = u8"frontal cat face detector";
			copyright_.emplace_back(Copyright(u8"Joseph Howse (Nummist Media Corporation Limited, Halifax, Nova Scotia, Canada). All rights reserved.", 2014 , 2016));
			str_ = u8"";
			return;
		case(giflib_LICENSE):
			name_ = u8"giflib";
			copyright_.emplace_back(Copyright(u8"Eric S.Raymond ", 1997, 0));
			str_ = u8"";
			return;
		case(HarfBuzz_LICENSE):
			name_ = u8"HarfBuzz";
			copyright_.emplace_back(Copyright(u8"Google, Inc.", 2010,2012));
			copyright_.emplace_back(Copyright(u8"Mozilla Foundation", 2012, 0));
			copyright_.emplace_back(Copyright(u8"Codethink Limited", 2011, 0));
			copyright_.emplace_back(Copyright(u8"Nokia Corporation and/or its subsidiary(-ies)", 2008, 2010));
			copyright_.emplace_back(Copyright(u8"Keith Stribley", 2009, 0));
			copyright_.emplace_back(Copyright(u8"Martin Hosken and SIL International", 2009, 0));
			copyright_.emplace_back(Copyright(u8"Chris Wilson", 2007, 0));
			copyright_.emplace_back(Copyright(u8"Behdad Esfahbod", 2006, 0));
			copyright_.emplace_back(Copyright(u8"David Turner", 2005, 0));
			copyright_.emplace_back(Copyright(u8"Red Hat, Inc.", 2004, 2010));
			copyright_.emplace_back(Copyright(u8"David Turner and Werner Lemberg", 1998, 2004));
			str_ = u8"";
			return;
		case(hopscotch_map_LICENSE):
			name_ = u8"hopscotch-map";
			copyright_.emplace_back(Copyright(u8"Tessil", 2017, 0));
			str_ = u8"";
			return;
		case(kld_intersections_LICENSE):
			name_ = u8"kld-intersections";
			copyright_.emplace_back(Copyright(u8"Kevin Lindsey. All rights reserved.", 2013, 0));
			str_ = u8"";
			return;
		case(JUMAN_LICENSE):
			name_ = u8"JUMAN++";
			copyright_.emplace_back(Copyright(u8"The Juman++ Authors https://github.com/ku-nlp/jumanpp", 2016 , 2018));
			str_ = u8"";
			return;
		case(kld_polynomial_LICENSE):
			name_ = u8"kld-polynomial";
			copyright_.emplace_back(Copyright(u8"Kevin Lindsey. All rights reserved.", 2013, 0));
			str_ = u8"";
			return;
		case(lbpcascade_animeface_LICENSE):
			name_ = u8"lbpcascade animeface";
			copyright_.emplace_back(Copyright(u8"by nagadomi@nurs.or.jp", 2011, 0));
			str_ = u8"";
			return;
		case(libjpeg_turbo_LICENSE):
			name_ = u8"libjpeg-turbo";
			copyright_.emplace_back(Copyright(u8"D. R. Commander. All Rights Reserved.", 2009 , 2016));
			str_ = u8"";
			return;
		case(libsvm_LICENSE):
			name_ = u8"libsvm";
			copyright_.emplace_back(Copyright(u8"Chih-Chung Chang and Chih-Jen Lin", 2000 , 2014));
			str_ = u8"";
			return;
		case(LineSegmentIntersection_LICENSE):
			name_ = u8"LineSegmentIntersection";
			copyright_.emplace_back(Copyright(u8"Kristian Lindberg Vinther", 2015, 0));
			str_ = u8"Licenced with the Code Project Open Licence (CPOL) http://www.codeproject.com/info/cpol10.aspx";
			return;
		case(miniutf_LICENSE):
			name_ = u8"miniutf";
			copyright_.emplace_back(Copyright(u8"Dropbox, Inc.", 2013, 0));
			str_ = u8"";
			return;
		case(msinttypes_r29_LICENSE):
			name_ = u8"msinttypes r29";
			copyright_.emplace_back(Copyright(u8"Alexander Chemeris", 2006, 2013));
			str_ = u8"";
			return;
		case(muparser_LICENSE):
			name_ = u8"muparser";
			copyright_.emplace_back(Copyright(u8"Ingo Berg", 2011, 0));
			str_ = u8"";
			return;
		case(nanoflann_LICENSE):
			name_ = u8"nanoflann";
			copyright_.emplace_back(Copyright(u8"Marius Muja (mariusm@cs.ubc.ca). All rights reserved.", 2008 , 2009));
			copyright_.emplace_back(Copyright(u8"David G. Lowe (lowe@cs.ubc.ca). All rights reserved.", 2008 , 2009));
			copyright_.emplace_back(Copyright(u8"Jose L. Blanco (joseluisblancoc@gmail.com). All rights reserved.", 2011, 0));
			str_ = u8"";
			return;
		case(Noto_Fonts_LICENSE):
			name_ = u8"Noto Fonts";
			str_ = u8"Licensed under SIL Open Font License v1.1.";
			return;
		case(OpenCV_LICENSE):
			name_ = u8"";
			copyright_.emplace_back(Copyright(u8"Intel Corporation, all rights reserved.", 2000 , 2018));
			copyright_.emplace_back(Copyright(u8"Willow Garage Inc., all rights reserved.", 2009 , 2011));
			copyright_.emplace_back(Copyright(u8"NVIDIA Corporation, all rights reserved.", 2009 , 2016));
			copyright_.emplace_back(Copyright(u8"Advanced Micro Devices, Inc., all rights reserved.", 2010 , 2013));
			copyright_.emplace_back(Copyright(u8"OpenCV Foundation, all rights reserved.", 2015 , 2016));
			copyright_.emplace_back(Copyright(u8"Itseez Inc., all rights reserved.", 2015 , 2016));
			copyright_.emplace_back(Copyright(u8"Third party copyrights are property of their respective owners.", 0, 0));
			str_ = u8"";
			return;
		case(Poly2Tri_LICENSE):
			name_ = u8"OpenCV";
			copyright_.emplace_back(Copyright(u8"", 0, 0));
			str_ = u8"";
			return;
		case(pffft_LICENSE):
			name_ = u8"";
			copyright_.emplace_back(Copyright(u8"", 0, 0));
			str_ = u8"";
			return;
		case(RapidJSON_LICENSE):
			name_ = u8"";
			copyright_.emplace_back(Copyright(u8"", 0, 0));
			str_ = u8"";
			return;
		case(Recast_Detour_LICENSE):
			name_ = u8"";
			copyright_.emplace_back(Copyright(u8"", 0, 0));
			str_ = u8"";
			return;
		case(SFMT_LICENSE):
			name_ = u8"";
			copyright_.emplace_back(Copyright(u8"", 0, 0));
			str_ = u8"";
			return;
		case(Simple_DirectMedia_Layer_LICENSE):
			name_ = u8"";
			copyright_.emplace_back(Copyright(u8"", 0, 0));
			str_ = u8"";
			return;
		case(TinySoundFont_LICENSE):
			name_ = u8"";
			copyright_.emplace_back(Copyright(u8"", 0, 0));
			str_ = u8"";
			return;
		case(TinyXML_2_LICENSE):
			name_ = u8"";
			copyright_.emplace_back(Copyright(u8"", 0, 0));
			str_ = u8"";
			return;
		case(xxHash_LICENSE):
			name_ = u8"";
			copyright_.emplace_back(Copyright(u8"", 0, 0));
			str_ = u8"";
			return;
		case(zlib_LICENSE):
			name_ = u8"";
			copyright_.emplace_back(Copyright(u8"", 0, 0));
			str_ = u8"";
			return;
		case(Zstandard_LICENSE):
			name_ = u8"";
			copyright_.emplace_back(Copyright(u8"", 0, 0));
			str_ = u8"";
			return;
		}
	}
}
