//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asライブラリ
//
//                    制作者: がっちょ (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
	constexpr size_t TITLE_STR_SIZE_MAX = 255;

	class AsInitData
	{
	public:
		AsInitData(const char* const add_title = "", const Pos2& add_window_size = WINDOW_SIZE, const ColorRGB& add_BG_color = BG_COLOR);
		~AsInitData();

		Pos2 windowSize();
		ColorRGB colorBG();
		const char* title();

	private:
		//ウィンドウサイズ
		Pos2 window_size = WINDOW_SIZE;

		//背景色
		ColorRGB BG_color = BG_COLOR;

		//タイトル
		char title_name[TITLE_STR_SIZE_MAX + 1] = {};
	};

	inline AsInitData::AsInitData(const char* const add_title, const Pos2& add_window_size, const ColorRGB& add_BG_color)
	{
		for (size_t i = 0; i < TITLE_STR_SIZE_MAX; ++i) {
			if (add_title[i] == '\0') break;
			title_name[i] = add_title[i];
		}

		window_size = add_window_size;
		BG_color = add_BG_color;

		
		AsInit(title_name, window_size, BG_color);
	}

	inline AsInitData::~AsInitData()
	{
	}

	inline Pos2 AsInitData::windowSize()
	{
		return window_size;
	}

	inline ColorRGB AsInitData::colorBG()
	{
		return BG_color;
	}

	inline const char * AsInitData::title()
	{
		return title_name;
	}

	//ファイル読み込み
	AsInitData AsReadInit(const char* const file_name, const char* const add_title = "", const Pos2& add_window_size = WINDOW_SIZE, const ColorRGB& add_BG_color = BG_COLOR)
	{
		AsInitData init(add_title, add_window_size, add_BG_color);
		if (AsRead(file_name, &init, sizeof(init), 1) == 0) AsChangeTitle(init.title());
		return init;
	}

	//ファイル書き込み
	int32_t AsWriteInit(const char* const file_name, AsInitData& init)
	{
		return AsWrite(file_name, &init, sizeof(init), 1);
	}

}