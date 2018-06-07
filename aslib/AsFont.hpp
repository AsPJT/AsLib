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

	constexpr int FONT_THICK = 7;

	inline Font asMakeFont(const int32_t& font_size = 10, const char* font_name = "Meiryo UI")
	{
		return DxLib::CreateFontToHandle(font_name, font_size, FONT_THICK);
	}

	inline Font asMakeFont(const int32_t& font_size = 10, const std::string& font_name = "Meiryo UI")
	{
		return DxLib::CreateFontToHandle(font_name.c_str(), font_size, FONT_THICK);
	}

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

	struct FontMainData 
	{
	public:

		FontMainData(const Font add_id, const int32_t add_size = 10, const char* const add_fontname = "Meiryo UI", const Font add_thick = FONT_THICK)
			:id(add_id), size(add_size), fontname(std::string(add_fontname)), thick(add_thick) {}

		FontMainData& draw(const char* const, const ColorRGBA& = black_RGBA);
		FontMainData& draw(const std::string& string_, const ColorRGBA& color_ = black_RGBA) { return this->draw(string_.c_str(), color_); }
		FontMainData& draw(const ColorRGBA& color_,const std::string& string_) { return this->draw(string_.c_str(), color_); }
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
		Font id = -1;
		//大きさ
		int32_t size = 10;
		//太さ
		int thick;
		//フォント名
		std::string fontname = {};
	};

	inline FontMainData& FontMainData::draw(const char* const format_string, const ColorRGBA& color_rgba)
	{
		DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, int(color_rgba.a));
		DxLib::DrawStringToHandle(0, 0, format_string, color_rgba, this->id);
		return *this;
	}

	template<typename... Rest>
	inline FontMainData& FontMainData::draw(const char* const format_string, const Pos2& pos_, const ColorRGBA& color_, const Rest&... rest)
	{
		DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, int(color_.a));
		DxLib::DrawFormatStringToHandle(int(pos_.x), int(pos_.y), color_, this->id, format_string, rest...);
		return *this;
	}

#elif defined(ASLIB_INCLUDE_S3) //Siv3D

#else //Console

#endif

}