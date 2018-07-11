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
		MainData(const char* const add_title = u8"", const Pos2& add_window_size = WINDOW_SIZE, const ColorRGB& add_BG_color = BG_COLOR);
		~MainData() = default;

		const Pos2 windowSize() const { return window_size; };
		const ColorRGB colorBG() const { return BG_color; };
		const char* const title() const { return title_name; };

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

	//ファイル読み込み
	const MainData asReadInit(const char* const file_name, const char* const add_title = u8"", const Pos2& add_window_size = WINDOW_SIZE, const ColorRGB& add_BG_color = BG_COLOR)
	{
		MainData init(add_title, add_window_size, add_BG_color);
		if (asRead(file_name, &init, sizeof(init), 1) == 0) asSetTitle(init.title());
		return init;
	}

	//ファイル書き込み
	const int32_t asWriteInit(const char* const file_name, MainData& init)
	{
		return asWrite(file_name, &init, sizeof(init), 1);
	}

}