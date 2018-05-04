//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsÉâÉCÉuÉâÉä
//
//                    êßçÏé“: Ç™Ç¡ÇøÇÂ (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{

#if defined(__DXLIB) //DxLib

	constexpr int FONT_THICK = 7;

	inline AsFont AsMakeFont(const int32_t font_size = 10, const char* font_name = "Meiryo UI")
	{
		return DxLib::CreateFontToHandle(font_name, font_size, FONT_THICK);
	}

	inline AsFont AsMakeFont(const int32_t font_size = 10, const std::string& font_name = "Meiryo UI")
	{
		return DxLib::CreateFontToHandle(font_name.c_str(), font_size, FONT_THICK);
	}

	int32_t AsStr(const AsFont font, const char* format_string = "", const Pos2& pos2 = pos2_0, const ColorRGB& color_rgb = white)
	{
		if (DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255) == -1) return -1;
		if (DxLib::DrawStringFToHandle(float(pos2.x), float(pos2.y), format_string, AsDxColor(color_rgb), font) == -1) return -1;
		return 0;
	}

	int32_t AsStr(const AsFont font, const char* format_string = "", const Pos2& pos2 = pos2_0, const ColorRGBA& color_rgba = whiteA)
	{
		if (DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, color_rgba.a) == -1) return -1;
		if (DxLib::DrawStringFToHandle(float(pos2.x), float(pos2.y), format_string, AsDxColor(color_rgba), font) == -1) return -1;
		return 0;
	}

#elif defined(SIV3D_INCLUDED) //Siv3D

#else //Console

#endif

}