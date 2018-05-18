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

	class MainData
	{
	public:
		MainData(const char* const add_title = "", const Pos2& add_window_size = WINDOW_SIZE, const ColorRGB& add_BG_color = BG_COLOR);
		~MainData();

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

	inline MainData::MainData(const char* const add_title, const Pos2& add_window_size, const ColorRGB& add_BG_color)
	{
		for (size_t i = 0; i < TITLE_STR_SIZE_MAX; ++i) {
			if (add_title[i] == '\0') break;
			title_name[i] = add_title[i];
		}

		window_size = add_window_size;
		BG_color = add_BG_color;
	}

	inline MainData::~MainData()
	{
	}

	inline Pos2 MainData::windowSize()
	{
		return window_size;
	}

	inline ColorRGB MainData::colorBG()
	{
		return BG_color;
	}

	inline const char * MainData::title()
	{
		return title_name;
	}

	//ファイル読み込み
	MainData asReadInit(const char* const file_name, const char* const add_title = "", const Pos2& add_window_size = WINDOW_SIZE, const ColorRGB& add_BG_color = BG_COLOR)
	{
		MainData init(add_title, add_window_size, add_BG_color);
		if (asRead(file_name, &init, sizeof(init), 1) == 0) AsChangeTitle(init.title());
		return init;
	}

	//ファイル書き込み
	int32_t asWriteInit(const char* const file_name, MainData& init)
	{
		return asWrite(file_name, &init, sizeof(init), 1);
	}

}