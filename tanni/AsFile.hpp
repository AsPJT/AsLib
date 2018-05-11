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

#elif defined(SIV3D_INCLUDED) //Siv3D

#else //Console

#endif

	Pos2 asReadPos2(const char* const file_name)
	{
		Pos2 pos2;
		asRead(file_name, &pos2, sizeof(pos2), 1);
		return pos2;
	}

	inline int32_t asReadPos2(const char* const file_name, Pos2& pos2)
	{
		return asRead(file_name, &pos2, sizeof(pos2), 1);
	}

	inline int32_t asReadPos4(const char* const file_name, Pos4& pos4)
	{
		return asRead(file_name, &pos4, sizeof(pos4), 1);
	}

	inline int32_t asReadRGB(const char* const file_name, ColorRGB& color)
	{
		return asRead(file_name, &color, sizeof(color), 1);
	}

	inline int32_t asReadRGBA(const char* const file_name, ColorRGBA& color)
	{
		return asRead(file_name, &color, sizeof(color), 1);
	}


	int32_t asWritePos2(const char* const file_name, const Pos2& add_pos2)
	{
		Pos2 pos2 = add_pos2;
		return asWrite(file_name, &pos2, sizeof(pos2), 1);
	}

	int32_t asWritePos4(const char* const file_name, const Pos4& add_pos4)
	{
		Pos4 pos4 = add_pos4;
		return asWrite(file_name, &pos4, sizeof(pos4), 1);
	}

	int32_t asWriteRGB(const char* const file_name, const ColorRGB& add_color)
	{
		ColorRGB color = add_color;
		return asWrite(file_name, &color, sizeof(color), 1);
	}

	int32_t asWriteRGBA(const char* const file_name, const ColorRGBA& add_color)
	{
		ColorRGBA color = add_color;
		return asWrite(file_name, &color, sizeof(color), 1);
	}

}