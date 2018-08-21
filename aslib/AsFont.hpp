//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsProject Library
//
//                    Created by Gaccho (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
	constexpr int32_t FONT_THICK = 7;

	inline const Pos2 asMiddle(const OriginatorFont& id_, const char* const str_, const Pos2& pos_)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		return Pos2(pos_.x - (DxLib::GetDrawStringWidthToHandle(str_, int(std::string(str_).length()), id_) / 2), pos_.y - (DxLib::GetFontSizeToHandle(id_) / 2));
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		id_; str_;
		return pos_;
#elif defined(ASLIB_INCLUDE_OF)
		return Pos2();
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

	OriginatorFont asMakeFont(const int32_t& font_size = 10, const char* const font_name = u8"Meiryo UI")
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		return DxLib::CreateFontToHandle(font_name, font_size, FONT_THICK);
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		//s3d::Unicode::UTF8ToUTF32(font_name)
		//todo
		font_name;
		return OriginatorFont(font_size, s3d::Typeface::Black);
#elif defined(ASLIB_INCLUDE_OF)
		ofTrueTypeFont font;
		std::string str{};
		str += font_name;
		str += u8".ttf";
		font.load(str.c_str(), 70);
		font.setLineHeight(24);
		font.setLetterSpacing(1.0);
		return font;
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

	inline OriginatorFont asMakeFont(const int32_t& font_size, const std::string& font_name)
	{
		return asMakeFont(font_size, font_name.c_str());
	}


	const int32_t asPrint(const OriginatorFont font, const char* const format_string = u8"", const Pos2& pos2 = pos2_0, const ColorRGB& color_rgb = aslib_color_white)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		if (DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255) == -1) return -1;
		if (DxLib::DrawStringFToHandle(float(pos2.x), float(pos2.y), format_string, color_rgb, font) == -1) return -1;
		return 0;
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

	const int32_t asPrint(const OriginatorFont font, const char* const format_string = u8"", const Pos2& pos2 = pos2_0, const Color& color_rgba = aslib_color_white_a)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		if (DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, color_rgba.a) == -1) return -1;
		if (DxLib::DrawStringFToHandle(float(pos2.x), float(pos2.y), format_string, color_rgba, font) == -1) return -1;
		return 0;
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

	template<typename... Rest>
	const std::string printStringS3(const char* const format_string, const Rest&... rest)
	{
		constexpr size_t PRINT_STRING_MAX = 1024;
		char sn_string[PRINT_STRING_MAX];
		snprintf(sn_string, sizeof(sn_string), format_string, rest...);
		return std::string(sn_string);
	}

	inline void asPrintClear() 
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		DxLib::clsDx();
		return;
#else
		return;
#endif
	}

	inline const bool asFont(const OriginatorFont& id_, const char* const format_string, const Pos2& pos_, const Color& color_)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		return (DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, int(color_.a)) == 0) && (DxLib::DrawStringToHandle(int(pos_.x), int(pos_.y), format_string, color_, id_, id_) == 0);
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		id_(s3d::Unicode::UTF8ToUTF32(format_string)).draw(double(pos_.x), double(pos_.y), s3d::Color(color_));
		return true;
#elif defined(ASLIB_INCLUDE_OF)
		id_.drawString(format_string, pos_.x, pos_.y);
		return true;
#elif defined(ASLIB_INCLUDE_C2)
return 0;
#elif defined(ASLIB_INCLUDE_SF)
return 0;
#elif defined(ASLIB_INCLUDE_TP)
		return true;
#else //Console
		return true;
#endif
	}

	inline const bool asFontAt(const OriginatorFont& id_, const char* const format_string, const Pos2& pos_, const Color& color_)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		return asFont(id_, format_string, asMiddle(id_, format_string, pos_), color_);
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		id_(s3d::Unicode::UTF8ToUTF32(format_string)).drawAt(double(pos_.x), double(pos_.y), s3d::Color(color_));
		return true;
#elif defined(ASLIB_INCLUDE_OF)
		id_.drawString(format_string, pos_.x, pos_.y);
		return true;
#elif defined(ASLIB_INCLUDE_C2)
return 0;
#elif defined(ASLIB_INCLUDE_SF)
return 0;
#elif defined(ASLIB_INCLUDE_TP)
		return true;
#else //Console
		return true;
#endif
	}

	template<typename... Rest>
	inline const bool asFont(const OriginatorFont& id_, const char* const format_string, const Pos2& pos_, const Color& color_, const Rest&... rest)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		return (DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, int(color_.a)) == 0) && (DxLib::DrawFormatStringToHandle(int(pos_.x), int(pos_.y), color_, id_, format_string, rest...) == 0);
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		id_(s3d::Unicode::UTF8ToUTF32(printStringS3(format_string, rest...))).draw(double(pos_.x), double(pos_.y), s3d::Color(color_));
		return true;
#elif defined(ASLIB_INCLUDE_OF)
		id_.drawString(format_string, pos_.x, pos_.y);
		return true;
#elif defined(ASLIB_INCLUDE_C2)
return 0;
#elif defined(ASLIB_INCLUDE_SF)
return 0;
#elif defined(ASLIB_INCLUDE_TP)
		return true;
#else //Console
		return true;
#endif
	}

	template<typename... Rest>
	inline const bool asFontAt(const OriginatorFont& id_, const char* const format_string, const Pos2& pos_, const Color& color_, const Rest&... rest)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		return asFont(id_, format_string, asMiddle(id_, printStringS3(format_string, rest...).c_str(), pos_), color_, rest...);
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		id_(s3d::Unicode::UTF8ToUTF32(printStringS3(format_string, rest...))).drawAt(double(pos_.x), double(pos_.y), s3d::Color(color_));
		return true;
#elif defined(ASLIB_INCLUDE_OF)
		id_.drawString(format_string, pos_.x, pos_.y);
		return true;
#elif defined(ASLIB_INCLUDE_C2)
return 0;
#elif defined(ASLIB_INCLUDE_SF)
return 0;
#elif defined(ASLIB_INCLUDE_TP)
		return true;
#else //Console
		return true;
#endif
	}



	struct AsFont
	{
	private:
		//フォントデータのID
		OriginatorFont id;
		//大きさ
		int32_t size = 10;
		//太さ
		int32_t thick = FONT_THICK;
		//フォント名
		std::string fontname = u8"Meiryo UI";
	public:
		AsFont(){}
		AsFont(const int32_t add_size, const char* const str_ = u8"Meiryo UI", const int32_t add_thick = FONT_THICK) :id(asMakeFont(add_size,str_)), size(add_size), thick(add_thick), fontname(std::string(str_)) {}//stdmovea

		AsFont& operator()(const int32_t add_size = 10, const char* const str_ = u8"Meiryo UI", const int32_t add_thick = FONT_THICK)
		{
			id = asMakeFont(add_size, str_);
			size = add_size;
			thick = add_thick;
			fontname = std::string(str_);//stdmovea
			return *this;
		}

		AsFont& draw(const char* const format_string, const Pos2& pos_, const Color& color_) { asFont(this->id, format_string, pos_, color_); return *this; }
		AsFont& draw(const std::string& string_, const Color& color_ = aslib_color_black_a) { return this->draw(string_.c_str(), color_); }
		AsFont& draw(const Color& color_, const std::string& string_) { return this->draw(string_.c_str(), color_); }
		AsFont& draw(const Color& color_, const char* const string_) { return this->draw(string_, color_); }

		AsFont& drawAt(const char* const format_string, const Pos2& pos_, const Color& color_) { asFontAt(this->id, format_string, pos_, color_); return *this; }
		AsFont& drawAt(const std::string& string_, const Color& color_ = aslib_color_black_a) { return this->drawAt(string_.c_str(), color_); }
		AsFont& drawAt(const Color& color_, const std::string& string_) { return this->drawAt(string_.c_str(), color_); }
		AsFont& drawAt(const Color& color_, const char* const string_) { return this->drawAt(string_, color_); }

		//書式付き
		template<typename... Rest>
		AsFont& draw(const char* const format_string, const Pos2& pos_, const Color& color_, const Rest&... rest) { asFont(this->id, format_string, pos_, color_, rest...); return *this; }
		template<typename... Rest>
		AsFont& draw(const Color& color_, const char* const str_, const Rest&... rest) { return this->draw(str_, pos2_0, color_, rest...); }
		template<typename... Rest>
		AsFont& draw(const Pos2& pos_, const char* const str_, const Rest&... rest) { return this->draw(str_, pos_, aslib_color_white_a, rest...); }
		template<typename... Rest>
		AsFont& draw(const char* const str_, const Rest&... rest) { return this->draw(str_, pos2_0, aslib_color_white_a, rest...); }

		//書式付き
		template<typename... Rest>
		AsFont& drawAt(const char* const str_, const Pos2& p_, const Color& c_, const Rest&... rest) { asFontAt(this->id, str_, p_, c_, rest...); return *this; }
		template<typename... Rest>
		AsFont& drawAt(const Color& color_, const char* const str_, const Rest&... rest) { return this->drawAt(str_, pos2_0, color_, rest...); }
		template<typename... Rest>
		AsFont& drawAt(const Pos2& pos_, const char* const str_, const Rest&... rest) { return this->drawAt(str_, pos_, aslib_color_white_a, rest...); }
		template<typename... Rest>
		AsFont& drawAt(const char* const str_, const Rest&... rest) { return this->drawAt(str_, pos2_0, aslib_color_white_a, rest...); }

		//出力
		OriginatorFont ID() const { return this->id; };
		int32_t Size() const { return this->size; };
		const char* const fontName() const { return this->fontname.c_str(); };

		AsFont& changeSize(const int32_t& size_) {
			this->size += size_;
#if defined(ASLIB_INCLUDE_DL) //DxLib
			DxLib::DeleteFontToHandle(this->id);
			this->id = DxLib::CreateFontToHandle(this->fontname.c_str(), this->size, FONT_THICK);
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
			this->id = OriginatorFont(size_);
#elif defined(ASLIB_INCLUDE_OF)

#elif defined(ASLIB_INCLUDE_C2)

#elif defined(ASLIB_INCLUDE_SF)
return 0;
#elif defined(ASLIB_INCLUDE_TP)
#else //Console
#endif
			return *this;
		}
	};

}