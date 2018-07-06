//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asライブラリ
//
//                    制作者: がっちょ (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
#if defined(ASLIB_INCLUDE_S3) //Siv3D
	template<typename... Rest>
	std::string printString(const char *FormatString, const Rest&... rest)
	{

		constexpr int32_t PRINT_STRING_MAX = 1024;
		char snString[PRINT_STRING_MAX];
		snprintf(snString, sizeof(snString), FormatString, rest...);
		return std::string(snString);
	}
#endif

	//ウィンドウサイズを記録する関数
	const Pos2 asWindowSizeSave(const bool b_, const Pos2& p_ = pos2_0)
	{
		static Pos2 p;
		if (b_) p = p_;
		return p;
	}

	//ウィンドウサイズを取得する関数
	inline const Pos2 asWindowSize()
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		return asWindowSizeSave(false);
#elif defined(ASLIB_INCLUDE_S3)
		return Pos2(s3d::Window::Width(), s3d::Window::Height());
#elif defined(ASLIB_INCLUDE_OF)
		return 0;
#elif defined(ASLIB_INCLUDE_TP)
		return 0;
#else //Console
		return 0;
#endif
	}

	inline const Pos2F asWindowSizeF() { return Pos2F(asWindowSize()); }



	//画面サイズ変更
	int32_t asSetWindowSize(const Pos2& window_size = WINDOW_SIZE)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		asWindowSizeSave(true, window_size);
		return int32_t(DxLib::SetGraphMode(window_size.x, window_size.y, 32));
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		s3d::Window::Resize(window_size.x, window_size.y);
		return 0;
#elif defined(ASLIB_INCLUDE_OF)
		return 0;
#elif defined(ASLIB_INCLUDE_TP)
	return 0;
#else //Console
	return 0;
#endif
	}

	//背景色変更
	inline const int32_t asSetBackGround(const ColorRGB& BG_color = BG_COLOR)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		return int32_t(DxLib::SetBackgroundColor(BG_color.r, BG_color.g, BG_color.b));
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		s3d::Graphics::SetBackground(s3d::Color(BG_color));
		return 0;
#elif defined(ASLIB_INCLUDE_OF)
		ofBackground(int(BG_color.r), int(BG_color.g), int(BG_color.b));
		return 0;
#elif defined(ASLIB_INCLUDE_TP)
	return 0;
#else //Console
	return 0;
#endif
	}


	//タイトル変更
	inline const int32_t asSetTitle(const char* const title)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
#if defined(__WINDOWS__)
		return int32_t(DxLib::SetMainWindowText(title));
#else
		return 0;
#endif
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		s3d::Window::SetTitle(s3d::Unicode::UTF8ToUTF32(title));
		return 0;
#elif defined(ASLIB_INCLUDE_OF)
		ofSetWindowTitle(title);
		return 0;
#elif defined(ASLIB_INCLUDE_TP)
	return 0;
#else //Console
	return 0;
#endif
	}


	inline const Pos2 asWindowSizeMain(const Pos2& pos2 = pos2_100)
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

#elif defined(ASLIB_INCLUDE_TP)
	return 0;
#else //Console
	return 0;
#endif
	}

	const Pos2 asWindowSizeTrue(const Pos2& pos2 = pos2_100)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
#if defined(__WINDOWS__)
		if (pos2.x != -1 || pos2.y != -1) return pos2;
		RECT rc;
		GetWindowRect(GetDesktopWindow(), &rc);
		Pos2 full_pos;
		full_pos(int32_t(rc.right - rc.left), int32_t(rc.bottom - rc.top));
		return full_pos;
#elif defined(__ANDROID__)
		int window_x;
		int window_y;

		if (pos2.x != -1 || pos2.y != -1) return pos2;
		if (DxLib::GetAndroidDisplayResolution(&window_x, &window_y) == -1) return pos2;

		Pos2 pos;
		pos(int32_t(window_x), int32_t(window_y));

		return pos;
#endif
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		return pos2;
#elif defined(ASLIB_INCLUDE_OF)
		return 0;
#elif defined(ASLIB_INCLUDE_TP)
	return 0;
#else //Console
	return 0;
#endif
	}

	const bool is_asFullScreenSize(const Pos2& pos2)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		if (pos2.x == -1 || pos2.y == -1) return true;
		else return false;
#elif defined(ASLIB_INCLUDE_OF)
		return 0;
#elif defined(ASLIB_INCLUDE_TP)
	return 0;
#else //Console
	return 0;
#endif
	}

	inline const Pos2 asFullScreenSize()
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		return { -1,-1 };
#elif defined(ASLIB_INCLUDE_OF)

#elif defined(ASLIB_INCLUDE_TP)
	return 0;
#else //Console
	return 0;
#endif
	}


	inline const Pos2 asSP_FullScreenSize(const Pos2& pos2 = pos2_100)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
#if defined(__WINDOWS__)
		return pos2;
#elif defined(__ANDROID__)
		//int window_x;
		//int window_y;
		//if (DxLib::GetAndroidDisplayResolution(&window_x, &window_y) == -1) return pos2;

		//Pos2 pos;
		//pos(int32_t(window_x), int32_t(window_y));

		return { -1,-1 };
#endif
#elif defined(ASLIB_INCLUDE_OF)

#elif defined(ASLIB_INCLUDE_TP)
	return 0;
#else //Console
	return 0;
#endif
	}

	//初期化
	const int32_t AsInit(const Pos2& window_size = WINDOW_SIZE, const ColorRGB& BG_color = BG_COLOR)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		if (DxLib::SetOutApplicationLogValidFlag(FALSE) == -1) return -1;
		if (DxLib::SetChangeScreenModeGraphicsSystemResetFlag(FALSE) == -1) return -1;
#if defined(__WINDOWS__)
		DxLib::SetWindowIconID(22);
		DxLib::SetWindowSizeChangeEnableFlag(TRUE);
		if (DxLib::SetUseCharCodeFormat(DX_CHARCODEFORMAT_UTF8) == -1) return -1;

		//フルスクリーンモード
		if (is_asFullScreenSize(window_size)) {
			DxLib::SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_NATIVE);
			if (DxLib::ChangeWindowMode(FALSE) == -1) return -1;
			RECT rc;
			GetWindowRect(GetDesktopWindow(), &rc);
			Pos2 full_pos;
			full_pos(int32_t(rc.right - rc.left), int32_t(rc.bottom - rc.top));
			if (asSetWindowSize(full_pos) == -1) return -1;
		}
		else {//通常のモード
			if (DxLib::ChangeWindowMode(TRUE) == -1) return -1;
			if (asSetWindowSize(window_size) == -1) return -1;
		}
#endif
		if (asSetBackGround(BG_color) == -1) return -1;
		//ここで初期化
		if (DxLib::DxLib_Init() == -1) return -1;

#if defined(__WINDOWS__)
		//フルスクリーンモード
		if (is_asFullScreenSize(window_size)) {
			//マウスの表示をON
			DxLib::SetMouseDispFlag(TRUE);
		}
#endif
#if defined(__ANDROID__)
		if (asSetWindowSize(asWindowSizeTrue(window_size)) == -1) return -1;
#endif
		if (DxLib::SetDXArchiveExtension("as") == -1) return -1;

		if (DxLib::SetDrawScreen(DX_SCREEN_BACK)) return -1;

		if (DxLib::SetFontSize(20) == -1) return -1;
		if (DxLib::ChangeFontType(DX_FONTTYPE_NORMAL) == -1) return -1;
#if defined(__WINDOWS__)
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
#endif
		if (DxLib::SetUseASyncLoadFlag(FALSE) == -1) return -1;

		return 0;
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		s3d::Window::Resize(window_size.x, window_size.y);
		s3d::Graphics::SetBackground(s3d::Color(BG_color));
		static s3d::RenderStateBlock2D wireframe(s3d::SamplerState::ClampNearest);
		return 0;
#elif defined(ASLIB_INCLUDE_OF)
		//asSetWindowSize(window_size);
		asSetBackGround(BG_color);
		return 0;
#elif defined(ASLIB_INCLUDE_TP)
return 0;
#else //Console
return 0;
#endif
	}

	//終了処理
	inline const int32_t asEnd()
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		return int32_t(DxLib::DxLib_End());
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		return 0;
#elif defined(ASLIB_INCLUDE_OF)

#elif defined(ASLIB_INCLUDE_TP)
return 0;
#else //Console
return 0;
#endif
	}

	//文字出力
	template<typename... Rest>
	inline const int32_t asPrint(const char* const format_string, const Rest&... rest)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		return int32_t(DxLib::printfDx(format_string, rest...));
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		s3d::Print(s3d::Unicode::UTF8ToUTF32(printString(format_string, rest...)));
		return 0;
#elif defined(ASLIB_INCLUDE_OF)

#elif defined(ASLIB_INCLUDE_TP)
return 0;
#else //Console
return 0;
#endif
	}
	inline const int32_t asPrint(const char* const format_string)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		return int32_t(DxLib::printfDx("%s", format_string));
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		s3d::Print(s3d::Unicode::UTF8ToUTF32(format_string));
		return 0;
#elif defined(ASLIB_INCLUDE_OF)
		return 0;
#elif defined(ASLIB_INCLUDE_TP)
return 0;
#else //Console
return 0;
#endif
	}

//以降は他ライブラリ依存なし----------

	const int32_t AsInit(const char* const title = "", const Pos2& window_size = WINDOW_SIZE, const ColorRGB& BG_color = BG_COLOR)
	{
		if (asSetTitle(title) == -1) return -1;
		return AsInit(window_size, BG_color);
	}

	const int32_t AsInit(const std::string& title = "", const Pos2& window_size = WINDOW_SIZE, const ColorRGB& BG_color = BG_COLOR)
	{
		if (asSetTitle(title.c_str()) == -1) return -1;
		return AsInit(window_size, BG_color);
	}

	template<typename... Rest>
	inline const int32_t asPrint(const std::string& format_string, const Rest&... rest)
	{
		return asPrint(format_string.c_str(), rest...);
	}

	inline const int32_t asPrint(const std::string& format_string)
	{
		return asPrint(format_string.c_str());
	}

	//タイトル変更
	inline const int32_t asSetTitle(const std::string& title)
	{
		return asSetTitle(title.c_str());
	}

	//タイトルを記録する関数
	const char* const asTitleSave(const bool b_, const char* const str_ = nullptr)
	{
		static std::string str;
		if (b_ && str_ != nullptr) str = str_;
		return str.c_str();
	}
	//タイトルを取得する関数
	inline const char* const asTitle() { return asTitleSave(false); }

}