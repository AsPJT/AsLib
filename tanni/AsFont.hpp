//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asƒ‰ƒCƒuƒ‰ƒŠ
//
//                    §ìŽÒ: ‚ª‚Á‚¿‚å (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{

#if defined(__DXLIB) //DxLib

	constexpr int FONT_THICK = 7;

	inline AsFont asMakeFont(const int32_t& font_size = 10, const char* font_name = "Meiryo UI")
	{
		return DxLib::CreateFontToHandle(font_name, font_size, FONT_THICK);
	}

	inline AsFont asMakeFont(const int32_t& font_size = 10, const std::string& font_name = "Meiryo UI")
	{
		return DxLib::CreateFontToHandle(font_name.c_str(), font_size, FONT_THICK);
	}

	int32_t asPrint(const AsFont font, const char* const format_string = "", const Pos2& pos2 = pos2_0, const ColorRGB& color_rgb = white)
	{
		if (DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255) == -1) return -1;
		if (DxLib::DrawStringFToHandle(float(pos2.x), float(pos2.y), format_string, AsDxColor(color_rgb), font) == -1) return -1;
		return 0;
	}

	int32_t asPrint(const AsFont font, const char* const format_string = "", const Pos2& pos2 = pos2_0, const ColorRGBA& color_rgba = whiteA)
	{
		if (DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, color_rgba.a) == -1) return -1;
		if (DxLib::DrawStringFToHandle(float(pos2.x), float(pos2.y), format_string, AsDxColor(color_rgba), font) == -1) return -1;
		return 0;
	}

	struct FontMainData 
	{
	public:

		FontMainData(const int add_id, const int32_t = 10, const char* const = {}, const int = FONT_THICK);

		FontMainData& draw(const std::string&, const ColorRGB& = colorRGB_0);
		FontMainData& draw(const std::string&, const ColorRGBA& = colorRGBA_0);

		//o—Í
		int ID() const { return this->id; };
		int32_t Size() const { return this->size; };
		const char* fontName() const { return this->fontname.c_str(); };

	private:
		//
		int id = -1;
		int32_t size = 10;
		int thick;
		std::string fontname = {};
	};

	inline FontMainData::FontMainData(const int add_id, const int32_t add_size, const char* const add_fontname, const int add_thick)
	{
		id = add_id;
		size = add_size;
		fontname = add_fontname;
		thick = add_thick;
	}

	inline FontMainData& FontMainData::draw(const std::string& format_string, const ColorRGB& color_rgb)
	{
		DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
		DxLib::DrawStringToHandle(0, 0, format_string.c_str(), AsDxColor(color_rgb), this->id);
		return *this;
	}

	inline FontMainData& FontMainData::draw(const std::string& format_string, const ColorRGBA& color_rgba)
	{
		DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, int(color_rgba.a));
		DxLib::DrawStringToHandle(0, 0, format_string.c_str(), AsDxColor(color_rgba), this->id);
		return *this;
}


#elif defined(SIV3D_INCLUDED) //Siv3D

#else //Console

#endif

}