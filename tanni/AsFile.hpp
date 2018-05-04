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

	Pos2 AsReadPos2(const char* const file_name)
	{
		Pos2 pos2;
		AsRead(file_name, &pos2, sizeof(pos2), 1);
		return pos2;
	}

	inline int32_t AsReadPos2(const char* const file_name, Pos2& pos2)
	{
		return AsRead(file_name, &pos2, sizeof(pos2), 1);
	}

	inline int32_t AsReadPos4(const char* const file_name, Pos4& pos4)
	{
		return AsRead(file_name, &pos4, sizeof(pos4), 1);
	}

	inline int32_t AsReadRGB(const char* const file_name, ColorRGB& color)
	{
		return AsRead(file_name, &color, sizeof(color), 1);
	}

	inline int32_t AsReadRGBA(const char* const file_name, ColorRGBA& color)
	{
		return AsRead(file_name, &color, sizeof(color), 1);
	}


	int32_t AsWritePos2(const char* const file_name, const Pos2& add_pos2)
	{
		Pos2 pos2 = add_pos2;
		return AsWrite(file_name, &pos2, sizeof(pos2), 1);
	}

	int32_t AsWritePos4(const char* const file_name, const Pos4& add_pos4)
	{
		Pos4 pos4 = add_pos4;
		return AsWrite(file_name, &pos4, sizeof(pos4), 1);
	}

	int32_t AsWriteRGB(const char* const file_name, const ColorRGB& add_color)
	{
		ColorRGB color = add_color;
		return AsWrite(file_name, &color, sizeof(color), 1);
	}

	int32_t AsWriteRGBA(const char* const file_name, const ColorRGBA& add_color)
	{
		ColorRGBA color = add_color;
		return AsWrite(file_name, &color, sizeof(color), 1);
	}

}