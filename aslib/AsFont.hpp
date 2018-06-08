//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asライブラリ
//
//                    制作者: がっちょ (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
	constexpr int32_t FONT_THICK = 7;

	Font asMakeFont(const int32_t& font_size = 10, const char* font_name = "Meiryo UI")
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		return DxLib::CreateFontToHandle(font_name, font_size, FONT_THICK);
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		return Font(font_size);
#else //Console

#endif
	}

	inline Font asMakeFont(const int32_t& font_size, const std::string& font_name)
	{
		return asMakeFont(font_size, font_name);
	}

#if defined(ASLIB_INCLUDE_DL) //DxLib



	int32_t asPrint(const Font font, const char* const format_string = "", const Pos2& pos2 = pos2_0, const ColorRGB& color_rgb = white)
	{
		if (DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255) == -1) return -1;
		if (DxLib::DrawStringFToHandle(float(pos2.x), float(pos2.y), format_string, color_rgb, font) == -1) return -1;
		return 0;
	}

	int32_t asPrint(const Font font, const char* const format_string = "", const Pos2& pos2 = pos2_0, const ColorRGBA& color_rgba = whiteA)
	{
		if (DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, color_rgba.a) == -1) return -1;
		if (DxLib::DrawStringFToHandle(float(pos2.x), float(pos2.y), format_string, color_rgba, font) == -1) return -1;
		return 0;
	}

#elif defined(ASLIB_INCLUDE_S3) //Siv3D

#else //Console

#endif

#if defined(ASLIB_INCLUDE_S3) //Siv3D
	template<typename... Rest>
	std::string printStringS3(const char *format_string, const Rest&... rest)
	{
		constexpr size_t PRINT_STRING_MAX = 1024;
		char sn_string[PRINT_STRING_MAX];
		std::snprintf(sn_string, sizeof(sn_string), format_string, rest...);
		return std::string(sn_string);
	}
#endif

	inline bool asFont(const Font& id_, const char* const format_string, const Pos2& pos_, const ColorRGBA& color_)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		return (DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, int(color_.a)) == 0) && (DxLib::DrawStringToHandle(int(pos_.x), int(pos_.y), format_string, color_, id_, id_) == 0);
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		id_(s3d::Unicode::UTF8ToUTF32(format_string)).draw(double(pos_.x), double(pos_.y), s3d::Color(color_));
		return true;
#else //Console
		
#endif
	}

	template<typename... Rest>
	inline bool asFont(const Font& id_, const char* const format_string, const Pos2& pos_, const ColorRGBA& color_, const Rest&... rest)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		return (DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, int(color_.a)) == 0) && (DxLib::DrawFormatStringToHandle(int(pos_.x), int(pos_.y), color_, id_, format_string, rest...) == 0);
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		id_(s3d::Unicode::UTF8ToUTF32(printStringS3(format_string, rest...))).draw(double(pos_.x), double(pos_.y), s3d::Color(color_));
		return true;
#else //Console

#endif
	}



	struct FontMainData
	{
	public:

		FontMainData(const Font& add_id, const int32_t add_size = 10, const char* const add_fontname = "Meiryo UI", const int32_t add_thick = FONT_THICK)
			:id(add_id), size(add_size), thick(add_thick), fontname(std::string(add_fontname)) {}

		FontMainData& draw(const char* const, const ColorRGBA& = black_RGBA);
		FontMainData& draw(const std::string& string_, const ColorRGBA& color_ = black_RGBA) { return this->draw(string_.c_str(), color_); }
		FontMainData& draw(const ColorRGBA& color_, const std::string& string_) { return this->draw(string_.c_str(), color_); }
		FontMainData& draw(const ColorRGBA& color_, const char* const string_) { return this->draw(string_, color_); }

		//書式付き
		template<typename... Rest>
		FontMainData& draw(const char* const, const Pos2& pos_, const ColorRGBA& color_, const Rest&... rest);
		template<typename... Rest>
		FontMainData& draw(const ColorRGBA& color_, const char* const str_, const Rest&... rest) { return this->draw(str_, pos2_0, color_, rest...); }
		template<typename... Rest>
		FontMainData& draw(const Pos2& pos_, const char* const str_, const Rest&... rest) { return this->draw(str_, pos_, black_RGBA, rest...); }
		template<typename... Rest>
		FontMainData& draw(const char* const str_, const Rest&... rest) { return this->draw(str_, pos2_0, black_RGBA, rest...); }

		//出力
		Font ID() const { return this->id; };
		int32_t Size() const { return this->size; };
		const char* fontName() const { return this->fontname.c_str(); };

	private:
		//フォントデータのID
		Font id;
		//大きさ
		int32_t size = 10;
		//太さ
		int32_t thick;
		//フォント名
		std::string fontname = {};
	};

	inline FontMainData& FontMainData::draw(const char* const format_string, const ColorRGBA& color_)
	{
		asFont(this->id, format_string, { 0,0 }, color_);
		return *this;
	}

	template<typename... Rest>
	inline FontMainData& FontMainData::draw(const char* const format_string, const Pos2& pos_, const ColorRGBA& color_, const Rest&... rest)
	{
		asFont(this->id, format_string, { 0,0 }, color_, rest...);
		return *this;
	}

}