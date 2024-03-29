﻿/*#######################################################################################
	Made by Kasugaccho
	Made by As Project
	https://github.com/Kasugaccho/AsLib
	wanotaitei@gmail.com

	This code is licensed under CC0.
#######################################################################################*/
#ifndef INCLUDED_AS_PROJECT_LIBRARY_STD
#define INCLUDED_AS_PROJECT_LIBRARY_STD


namespace AsLib
{
	//ウィンドウサイズを記録する関数
	Pos2 asWindowSizeSave(const bool b_, const Pos2& p_ = pos2_0) noexcept
	{
		static thread_local Pos2 p;
		if (b_) p = p_;
		return p;
	}

	//ウィンドウサイズを取得する関数
	Pos2 asWindowSize() noexcept
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		return asWindowSizeSave(false);
#elif defined(ASLIB_INCLUDE_S3)
		return Pos2(s3d::Window::Width(), s3d::Window::Height());
#elif defined(ASLIB_INCLUDE_OF)
		return asWindowSizeSave(false);
#elif defined(ASLIB_INCLUDE_C2)
return 0;
#elif defined(ASLIB_INCLUDE_SF)
return 0;
#elif defined(ASLIB_INCLUDE_TP)
		return Pos2();
#else //Console
		return Pos2();
#endif
	}

#if defined(ASLIB_INCLUDE_S3) //Siv3D
	template<typename... Rest>
	std::string printString(const char *FormatString, const Rest&... rest) noexcept
	{

		constexpr std::int32_t PRINT_STRING_MAX{ 1024 };
		char snString[PRINT_STRING_MAX];
		snprintf(snString, sizeof(snString), FormatString, rest...);
		return std::string(snString);
	}
#endif

	//初期化を記録
	bool asIsInitSave(const bool b_, const bool& p_ = false) noexcept
	{
		static bool p = false;
		if (b_) p = p_;
		return p;
	}
	//初期化を取得する関数
	inline bool asIsInit() noexcept { return asIsInitSave(false); }

	//ウィンドウサイズを取得する関数(float)
	inline Pos2F asWindowSizeF() noexcept { return Pos2F(asWindowSize()); }

	inline Pos4 asWindowSize4() noexcept { return Pos4(0, 0, asWindowSize()); }
	inline Pos4F asWindowSize4F() noexcept { return Pos4F(0.0f, 0.0f, asWindowSizeF()); }

	//画面サイズ変更
	inline void asSetWindowSize(const Pos2& window_size = aslib_default_window_size) noexcept
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		asWindowSizeSave(true, window_size);
		DxLib::SetGraphMode(window_size.x, window_size.y, 32);
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		s3d::Window::Resize(window_size.x, window_size.y);
#elif defined(ASLIB_INCLUDE_OF)
		asWindowSizeSave(true, window_size);
#elif defined(ASLIB_INCLUDE_C2)
		asWindowSizeSave(true, window_size);
#elif defined(ASLIB_INCLUDE_SF)
return 0;
#elif defined(ASLIB_INCLUDE_TP)
		window_size(0);
#else //Console
		window_size(0);
#endif
	}

	bool asIsWindowSizeW() noexcept {
		return (asWindowSize().x >= asWindowSize().y) ? true : false;
	}
	bool asIsWindowSizeH() noexcept {
		return (asWindowSize().x <= asWindowSize().y) ? true : false;
	}

	//背景色変更
	inline std::int32_t asSetBackGround(const ColorRGB& BG_color = aslib_bg_color) noexcept
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		return std::int32_t(DxLib::SetBackgroundColor(BG_color.r, BG_color.g, BG_color.b));
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		s3d::Graphics::SetBackground(s3d::Color(BG_color));
		return 0;
#elif defined(ASLIB_INCLUDE_OF)
		ofBackground(int(BG_color.r), int(BG_color.g), int(BG_color.b));
		return 0;
#elif defined(ASLIB_INCLUDE_C2)
return 0;
#elif defined(ASLIB_INCLUDE_SF)
return 0;
#elif defined(ASLIB_INCLUDE_TP)
	return 0;
#else //Console
	return 0;
#endif
	}

	//タイトルを記録する関数
	std::string asTitleSave(const bool b_, const char* const str_ = nullptr) noexcept
	{
		static std::string aslib_title_save_str;
		if (b_ && str_ != nullptr) aslib_title_save_str = str_;
		return aslib_title_save_str;
	}
	//タイトルを取得する関数
	inline std::string asTitle() noexcept { return asTitleSave(false); }

	//タイトル変更
	inline std::int32_t asSetTitle(const char* const title) noexcept
	{
		asTitleSave(true, title);
#if defined(ASLIB_INCLUDE_DL) //DxLib
#if defined(__WINDOWS__)
		return std::int32_t(DxLib::SetMainWindowText(title));
#else
		return 0;
#endif
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		s3d::Window::SetTitle(s3d::Unicode::UTF8ToUTF32(title));
		return 0;
#elif defined(ASLIB_INCLUDE_OF)
		ofSetWindowTitle(title);
		return 0;
#elif defined(ASLIB_INCLUDE_C2)
return 0;
#elif defined(ASLIB_INCLUDE_SF)
return 0;
#elif defined(ASLIB_INCLUDE_TP)
	return 0;
#else //Console
	return 0;
#endif
	}
	//タイトル変更
	inline std::int32_t asSetTitle(const std::string& title) noexcept
	{
		return asSetTitle(title.c_str());
	}

	inline Pos2 asWindowSizeMain(const Pos2& pos2 = pos2_100) noexcept
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
#if defined(__WINDOWS__)
		return pos2;
#elif defined(__ANDROID__)
		Pos2 pos;
		pos(-1, -1);
		return pos;
#endif
#elif defined(ASLIB_INCLUDE_OF)

#elif defined(ASLIB_INCLUDE_C2)
return 0;
#elif defined(ASLIB_INCLUDE_SF)
return 0;
#elif defined(ASLIB_INCLUDE_TP)
	return 0;
#else //Console
	return 0;
#endif
	}

	Pos2 asWindowSizeTrue(const Pos2& pos2 = pos2_100) noexcept
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
#if defined(__WINDOWS__)
		if (pos2.x != -1 || pos2.y != -1) return pos2;
		RECT rc;
		GetWindowRect(GetDesktopWindow(), &rc);
		Pos2 full_pos;
		full_pos(std::int32_t(rc.right - rc.left), std::int32_t(rc.bottom - rc.top));
		return full_pos;
#elif defined(__ANDROID__)
		int window_x;
		int window_y;

		if (pos2.x != -1 || pos2.y != -1) return pos2;
		if (DxLib::GetAndroidDisplayResolution(&window_x, &window_y) == -1) return pos2;

		Pos2 pos;
		pos(std::int32_t(window_x), std::int32_t(window_y));

		return pos;
#endif
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		return pos2;
#elif defined(ASLIB_INCLUDE_OF)
		return Pos2(0,0);
#elif defined(ASLIB_INCLUDE_C2)
return 0;
#elif defined(ASLIB_INCLUDE_SF)
return 0;
#elif defined(ASLIB_INCLUDE_TP)
	return 0;
#else //Console
	return 0;
#endif
	}

	bool is_asFullScreenSize(const Pos2& pos2) noexcept
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		if (pos2.x == -1 || pos2.y == -1) return true;
		else return false;
#elif defined(ASLIB_INCLUDE_OF)
		return 0;
#elif defined(ASLIB_INCLUDE_C2)
return 0;
#elif defined(ASLIB_INCLUDE_SF)
return 0;
#elif defined(ASLIB_INCLUDE_TP)
	return 0;
#else //Console
	return 0;
#endif
	}

	inline Pos2 asFullScreenSize() noexcept
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		return { -1,-1 };
#elif defined(ASLIB_INCLUDE_OF)
		return 0;
#elif defined(ASLIB_INCLUDE_C2)
return 0;
#elif defined(ASLIB_INCLUDE_SF)
return 0;
#elif defined(ASLIB_INCLUDE_TP)
	return 0;
#else //Console
	return 0;
#endif
	}


	inline Pos2 asSP_FullScreenSize(const Pos2& pos2 = pos2_100) noexcept
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
#if defined(__WINDOWS__)
		return pos2;
#elif defined(__ANDROID__)
		//int window_x;
		//int window_y;
		//if (DxLib::GetAndroidDisplayResolution(&window_x, &window_y) == -1) return pos2;

		//Pos2 pos;
		//pos(std::int32_t(window_x), std::int32_t(window_y));

		return { -1,-1 };
#endif
#elif defined(ASLIB_INCLUDE_OF)
		return 0;
#elif defined(ASLIB_INCLUDE_C2)
return 0;
#elif defined(ASLIB_INCLUDE_SF)
return 0;
#elif defined(ASLIB_INCLUDE_TP)
	return 0;
#else //Console
	return 0;
#endif
	}


	std::int32_t makeLog(const std::string& str_) noexcept
	{
		asWrite(str_, "<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"/>");
		asAddWrite(str_, "<title>");
		asAddWrite(str_, asTitle().c_str());
		asAddWrite(str_, "</title>");
		asAddWrite(str_, "<style>body{background-color:#f9f9f9;font-family:'SegoeUI','メイリオ','Meiryo','ヒラギノ角ゴProW3','HiraginoKakuGothicPro','Osaka','ＭＳＰゴシック','MSPGothic','Arial',sans-serif;}h2{color:#333333;text-align:center;font-size:28px;}h3{color:#333333;text-align:center;font-size:24px;}main{font-size:14px;line-height:2;word-wrap:break-word;}main.name{color:#333333;text-align:center;font-size:20px;}main.copyright{padding-bottom:8px;color:#555555;text-align:center;font-size:12px;}main.license{padding-bottom:24px;color:#888888;text-align:center;font-size:9px;}</style></head><body>");
		asAddWrite(str_, "<h2>");
		asAddWrite(str_, asTitle().c_str());
		asAddWrite(str_, "</h2><br><h3>Licenses</h3>");

		std::string license_name = "";
		std::vector<Copyright> license_copyright;
		std::string license_str = "";
		for (std::size_t i{}; i < aslib_license_size; ++i) {
			license_copyright.clear();
			asLicense(aslib_license[i], license_name, license_copyright, license_str);

			asAddWrite(str_, "<main class=\"name\">");
			asAddWrite(str_, license_name.c_str());
			asAddWrite(str_, "</main>");

			for (std::size_t j{}; j < license_copyright.size(); ++j) {
				asAddWrite(str_, "<main class=\"copyright\">");
				asAddWrite(str_, license_copyright[j].write());
				asAddWrite(str_, "</main>");
			}

			asAddWrite(str_, "<main class=\"license\">");
			asAddWrite(str_, license_str.c_str());
			asAddWrite(str_, "</main>");
		}

		asAddWrite(str_, "</body></html>");
		return 0;
	}

	std::int32_t makeLog() noexcept {
		return makeLog(asTitle() + "_Licenses.html");
	}

	//初期化
	std::int32_t AsInit(const Pos2& p_ = aslib_default_window_size, const ColorRGB& BG_color = aslib_bg_color) noexcept
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		DxLib::SetOutApplicationLogValidFlag(FALSE);
		DxLib::SetChangeScreenModeGraphicsSystemResetFlag(FALSE);
#if defined(__WINDOWS__)
		DxLib::SetWindowIconID(22);
		DxLib::SetWindowSizeChangeEnableFlag(TRUE);
		DxLib::SetUseCharCodeFormat(DX_CHARCODEFORMAT_UTF8);

		//フルスクリーンモード
		if (is_asFullScreenSize(p_)) {
			DxLib::SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_NATIVE);
			if (DxLib::ChangeWindowMode(FALSE) == -1) return -1;
			RECT rc;
			GetWindowRect(GetDesktopWindow(), &rc);
			Pos2 full_pos;
			full_pos(std::int32_t(rc.right - rc.left), std::int32_t(rc.bottom - rc.top));
			asSetWindowSize(full_pos);
		}
		else {//通常のモード
			if (DxLib::ChangeWindowMode(TRUE) == -1) return -1;
			asSetWindowSize(p_);
			DxLib::SetAlwaysRunFlag(TRUE);
		}
#endif
		if (asSetBackGround(BG_color) == -1) return -1;
		//ここで初期化
		if (DxLib::DxLib_Init() == -1) return -1;
		//描画
		DxLib::DrawExtendGraph(p_.x / 4, p_.y / 4, p_.x * 3 / 4, p_.y * 3 / 4, DxLib::LoadGraph("Picture/aslib.png"), TRUE);
#if defined(__WINDOWS__)
		//フルスクリーンモード
		if (is_asFullScreenSize(p_)) {
			//マウスの表示をON
			DxLib::SetMouseDispFlag(TRUE);
		}
#endif
#if defined(__ANDROID__)
		asSetWindowSize(asWindowSizeTrue(p_));
#endif
		if (DxLib::SetDXArchiveExtension("as") == -1) return -1;

		if (DxLib::SetDrawScreen(DX_SCREEN_BACK)) return -1;

		if (DxLib::SetFontSize(20) == -1) return -1;
		//DX_FONTTYPE_ANTIALIASING_EDGE//DX_FONTTYPE_NORMAL
		if (DxLib::ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE_8X8) == -1) return -1;
#if defined(__WINDOWS__)
		DxLib::SetActiveKeyInput(-1);
		if (DxLib::SetKeyInputStringColor(
			0xff000000, 0xff000000,
			0xffffffff, 0xff000000,
			0xff000000, 0xffcde8ff,
			0xff000000, 0xffffffff,
			0xff9f9f9f, 0xffffffff,
			0xffa0a0a0, 0xffffffff,
			0xffadd6ff, 0xff000000,
			0xffffffff, 0xff000000,
			0xffffffff) == -1) return -1;

		DxLib::SetUseDirectInputFlag(TRUE);
		DxLib::SetDragFileValidFlag(1);
#endif
		if (DxLib::SetUseASyncLoadFlag(FALSE) == -1) return -1;
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		s3d::Window::Resize(p_.x, p_.y);
		s3d::Graphics::SetBackground(s3d::Color(BG_color));
		static s3d::RenderStateBlock2D wireframe(s3d::SamplerState::ClampNearest);
#elif defined(ASLIB_INCLUDE_OF)
		asSetWindowSize(asWindowSizeTrue(p_));
		//asSetWindowSize(p_);
		asSetBackGround(BG_color);
#elif defined(ASLIB_INCLUDE_C2)
		asSetWindowSize(p_);
#elif defined(ASLIB_INCLUDE_SF)
return 0;
#elif defined(ASLIB_INCLUDE_TP)
#else //Console
#endif

#if !defined(ASLIB_DONOT_USE_LOG)
		makeLog();
#endif
		asSRand8(std::uint8_t(std::time(nullptr) & 0xff));
		asSRand32(std::uint32_t(std::time(nullptr) & 0xffffffff));
		asIsInitSave(true, true);
		return 0;
	}

	//終了処理
	inline std::int32_t asEnd() noexcept
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		return std::int32_t(DxLib::DxLib_End());
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		return 0;
#elif defined(ASLIB_INCLUDE_OF)
		return 0;
#elif defined(ASLIB_INCLUDE_C2)
return 0;
#elif defined(ASLIB_INCLUDE_SF)
return 0;
#elif defined(ASLIB_INCLUDE_TP)
return 0;
#else //Console
return 0;
#endif
	}

	//文字出力
	template<typename... Rest>
	inline std::int32_t asPrint(const char* const format_string, const Rest&... rest) noexcept
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		return std::int32_t(DxLib::printfDx(format_string, rest...));
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		s3d::Print(s3d::Unicode::UTF8ToUTF32(printString(format_string, rest...)));
		return 0;
#elif defined(ASLIB_INCLUDE_OF)
		return 0;
#elif defined(ASLIB_INCLUDE_C2)
return 0;
#elif defined(ASLIB_INCLUDE_SF)
return 0;
#elif defined(ASLIB_INCLUDE_TP)
return 0;
#else //Console
return 0;
#endif
	}

	inline std::int32_t asPrint(const char* const format_string) noexcept
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		return static_cast<std::int32_t>(DxLib::printfDx("%s", format_string));
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		s3d::Print(s3d::Unicode::UTF8ToUTF32(format_string));
		return 0;
#elif defined(ASLIB_INCLUDE_OF)
		return 0;
#elif defined(ASLIB_INCLUDE_C2)
return 0;
#elif defined(ASLIB_INCLUDE_SF)
return 0;
#elif defined(ASLIB_INCLUDE_TP)
		return 0;
#else //Console
		return 0;
#endif
	}

//以降は他ライブラリ依存なし----------

	std::int32_t AsInit(const char* const title = "", const Pos2& window_size = aslib_default_window_size, const ColorRGB& BG_color = aslib_bg_color) noexcept
	{
		if (asSetTitle(title) == -1) return -1;
		return AsInit(window_size, BG_color);
	}

	std::int32_t AsInit(const std::string& title = "", const Pos2& window_size = aslib_default_window_size, const ColorRGB& BG_color = aslib_bg_color) noexcept
	{
		if (asSetTitle(title.c_str()) == -1) return -1;
		return AsInit(window_size, BG_color);
	}

	template<typename... Rest>
	inline std::int32_t asPrint(const std::string& format_string, const Rest&... rest) noexcept
	{
		return asPrint(format_string.c_str(), rest...);
	}

	inline std::int32_t asPrint(const std::string& format_string) noexcept
	{
		return asPrint(format_string.c_str());
	}

//	template<typename p_>
//	const Coordinate_L4<p_> Coordinate_4<p_>::ratio() { return Pos4(std::int32_t(this->x1*asWindowSizeF().x), std::int32_t(this->y1*asWindowSizeF().y), std::int32_t(this->x2*asWindowSizeF().x), std::int32_t(this->y2*asWindowSizeF().y)); }
//	template<typename p_>
//	const Coordinate_L4<p_> Coordinate_4<p_>::ratio(const Coordinate_2<p_> p_) { return Pos4(std::int32_t(this->x1*p_.x), std::int32_t(this->y1*p_.y), std::int32_t(this->x2*p_.x), std::int32_t(this->y2*p_.y)); }


	const PosL4 Pos4F::ratio() { return Pos4(std::int32_t(this->x1*asWindowSizeF().x), std::int32_t(this->y1*asWindowSizeF().y), std::int32_t(this->x2*asWindowSizeF().x), std::int32_t(this->y2*asWindowSizeF().y)); }

	const PosL4 Pos4F::ratio(const Pos2F p_) { return Pos4(std::int32_t(this->x1*p_.x), std::int32_t(this->y1*p_.y), std::int32_t(this->x2*p_.x), std::int32_t(this->y2*p_.y)); }


}

#endif //Included AsProject Library