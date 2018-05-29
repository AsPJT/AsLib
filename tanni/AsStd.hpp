//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asライブラリ
//
//                    制作者: がっちょ (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
	//VS
#if defined(_MSC_VER)

	//ファイル読み込み
	int32_t asRead(const char* const file_name, void* const read_buf, const size_t read_size, const size_t read_nmemb)
	{
		FILE  *cfp_fp;
		const errno_t cfp_error = fopen_s(&cfp_fp, file_name, "rb");
		if (cfp_error) return -1;

		fread(read_buf, read_size, read_nmemb, cfp_fp);
		fclose(cfp_fp);
		return 0;
	}

	//ファイル書き込み
	int32_t asWrite(const char* const file_name, void* const write_buf, const size_t write_size, const size_t write_nmemb)
	{
		FILE  *cfp_fp;
		const errno_t cfp_error = fopen_s(&cfp_fp, file_name, "wb");
		if (cfp_error) return -1;

		fwrite(write_buf, write_size, write_nmemb, cfp_fp);
		fclose(cfp_fp);
		return 0;
	}
	//Android(VS)
#elif defined(__ANDROID__)

	int32_t asWrite(const char* const file_name, void* const write_buf, const size_t write_size, const size_t write_nmemb)
	{
		constexpr size_t file_path_max = 256;

		FILE  *cfp_fp;
		char FilePath[file_path_max];
		DxLib::GetInternalDataPath(FilePath, sizeof(FilePath));

		const std::string fp_name = std::string(FilePath) + "\\" + std::string(file_name);
		cfp_fp = fopen(fp_name.c_str(), "rb");

		if (cfp_fp == nullptr) return -1;

			fwrite(write_buf, write_size, write_nmemb, cfp_fp);
			fclose(cfp_fp);
		return 0;
	}

	int32_t asRead(const char* const file_name, void* const read_buf, const size_t read_size, const size_t read_nmemb)
	{
		constexpr size_t file_path_max = 256;

		FILE  *cfp_fp;
		char FilePath[file_path_max];
		DxLib::GetInternalDataPath(FilePath, sizeof(FilePath));

		const std::string fp_name = std::string(FilePath) + "\\" + std::string(file_name);
		cfp_fp = fopen(fp_name.c_str(), "rb");

		if (cfp_fp == nullptr) return -1;

		fread(read_buf, read_size, read_nmemb, cfp_fp);
		fclose(cfp_fp);
		return 0;
	}

#endif

#if defined(__DXLIB) //DxLib

	//画面サイズ変更
	inline int32_t AsChangeWindowSize(const Pos2& window_size = WINDOW_SIZE)
	{
		return int32_t(DxLib::SetGraphMode(window_size.x, window_size.y, 32));
	}

	//背景色変更
	inline int32_t AsChangeColorBG(const ColorRGB& BG_color = BG_COLOR)
	{
		return int32_t(DxLib::SetBackgroundColor(BG_color.r, BG_color.g, BG_color.b));
	}

#if defined(__WINDOWS__)
	//タイトル変更
	inline int32_t AsChangeTitle(const char* const title)
	{
		return int32_t(DxLib::SetMainWindowText(title));
	}

	inline int32_t AsChangeTitle(const std::string& title)
	{
		return int32_t(DxLib::SetMainWindowText(title.c_str()));
	}
#else
	inline int32_t AsChangeTitle(const char* const title)
	{
		return 0;
	}

	inline int32_t AsChangeTitle(const std::string& title)
	{
		return 0;
	}
#endif

#if defined(__WINDOWS__)
	Pos2 asWindowSizeMain(const Pos2& pos2 = pos2_100)
	{
		return pos2;
	}
#elif defined(__ANDROID__)
	Pos2 asWindowSizeMain(const Pos2& pos2 = pos2_100)
	{
		Pos2 pos;
		pos(-1, -1);
		return pos;
	}
#endif

#if defined(__WINDOWS__)
	Pos2 asWindowSizeTrue(const Pos2& pos2 = pos2_100)
	{
		return pos2;
	}
#elif defined(__ANDROID__)
	Pos2 asWindowSizeTrue(const Pos2& pos2 = pos2_100)
	{
		int window_x;
		int window_y;

		if (pos2.x != -1 || pos2.y != -1) return pos2;
		if (DxLib::GetAndroidDisplayResolution(&window_x, &window_y) == -1) return pos2;

		Pos2 pos;
		pos(int32_t(window_x), int32_t(window_y));

		return pos;
	}
#endif

#if defined(__WINDOWS__)
	Pos2 asWindowSize(const Pos2& pos2 = pos2_100)
	{
		return pos2;
	}
#elif defined(__ANDROID__)
	Pos2 asWindowSize(const Pos2& pos2 = pos2_100)
	{
		int window_x;
		int window_y;
		if (DxLib::GetAndroidDisplayResolution(&window_x, &window_y) == -1) return pos2;

		Pos2 pos;
		pos(int32_t(window_x), int32_t(window_y));

		return pos;
	}
#endif

	//初期化
	int32_t AsInit(const Pos2& window_size=WINDOW_SIZE, const ColorRGB& BG_color = BG_COLOR)
	{
		if (DxLib::SetOutApplicationLogValidFlag(FALSE) == -1) return -1;
		if (DxLib::SetChangeScreenModeGraphicsSystemResetFlag(FALSE) == -1) return -1;
#if defined(__WINDOWS__)
		DxLib::SetWindowIconID(22);
		DxLib::SetWindowSizeChangeEnableFlag(TRUE);
		if (DxLib::ChangeWindowMode(TRUE) == -1) return -1;
		if (DxLib::SetUseCharCodeFormat(DX_CHARCODEFORMAT_UTF8) == -1) return -1;
		if (AsChangeWindowSize(window_size) == -1) return -1;
#endif
		if (AsChangeColorBG(BG_color) == -1) return -1;
		if (DxLib::DxLib_Init() == -1) return -1;

#if defined(__ANDROID__)
		if (AsChangeWindowSize(asWindowSize(window_size)) == -1) return -1;
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
#endif
		if (DxLib::SetUseASyncLoadFlag(TRUE) == -1) return -1;

		return 0;
	}

	//終了処理
	inline int32_t asEnd()
	{
		return int32_t(DxLib::DxLib_End());
	}

	//DxLib専用カラーコード変換
	inline unsigned int AsDxColor(const ColorRGB& colorRGB = {})
	{
		return DxLib::GetColor(int(colorRGB.r), int(colorRGB.g), int(colorRGB.b));
	}

	inline unsigned int AsDxColor(const ColorRGBA& colorRGBA = {})
	{
		return DxLib::GetColor(int(colorRGBA.r), int(colorRGBA.g), int(colorRGBA.b));
	}

	//文字出力
	template<typename... Rest>
	inline int32_t asPrint(const char* const format_string, const Rest&... rest)
	{
		return int32_t(DxLib::printfDx(format_string, rest...));
	}

	template<typename... Rest>
	inline int32_t asPrint(const std::string& format_string, const Rest&... rest)
	{
		return int32_t(DxLib::printfDx(format_string.c_str(), rest...));
	}

	inline int32_t asPrint(const std::string& format_string)
	{
		return int32_t(DxLib::printfDx("%s", format_string.c_str()));
	}

	inline int32_t asPrint(const char* format_string)
	{
		return int32_t(DxLib::printfDx("%s", format_string));
	}


#elif defined(SIV3D_INCLUDED) //Siv3D

#else //Console

#endif

	int32_t AsInit(const char* const title = "", const Pos2& window_size = WINDOW_SIZE, const ColorRGB& BG_color = BG_COLOR)
	{
		if (AsChangeTitle(title) == -1) return -1;
		return AsInit(window_size, BG_color);
	}

	int32_t AsInit(const std::string& title = "", const Pos2& window_size = WINDOW_SIZE, const ColorRGB& BG_color = BG_COLOR)
	{
		if (AsChangeTitle(title.c_str()) == -1) return -1;
		return AsInit(window_size, BG_color);
	}


}