//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsProject Library
//
//                    Created by Gaccho (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------
#ifndef INCLUDED_AS_PROJECT_LIBRARY_ASFILE
#define INCLUDED_AS_PROJECT_LIBRARY_ASFILE

namespace AsLib
{
	//Pos
	inline int32_t asReadPos(const char* const file_name, Pos2& p_) noexcept { return asRead(file_name, &p_, sizeof(p_), 1); }
	inline int32_t asReadPos(const char* const file_name, Pos4& p_) noexcept { return asRead(file_name, &p_, sizeof(p_), 1); }
	inline int32_t asReadPos(const char* const file_name, PosA4& p_) noexcept { return asRead(file_name, &p_, sizeof(p_), 1); }
	inline int32_t asReadPos(const char* const file_name, PosL4& p_) noexcept { return asRead(file_name, &p_, sizeof(p_), 1); }
	inline int32_t asReadPos(const char* const file_name, Pos8& p_) noexcept { return asRead(file_name, &p_, sizeof(p_), 1); }
	inline int32_t asReadPos(const char* const file_name, Pos2F& p_) noexcept { return asRead(file_name, &p_, sizeof(p_), 1); }
	inline int32_t asReadPos(const char* const file_name, Pos4F& p_) noexcept { return asRead(file_name, &p_, sizeof(p_), 1); }
	inline int32_t asReadPos(const char* const file_name, PosA4F& p_) noexcept { return asRead(file_name, &p_, sizeof(p_), 1); }
	inline int32_t asReadPos(const char* const file_name, PosL4F& p_) noexcept { return asRead(file_name, &p_, sizeof(p_), 1); }
	inline int32_t asReadPos(const char* const file_name, Pos8F& p_) noexcept { return asRead(file_name, &p_, sizeof(p_), 1); }

	inline int32_t asReadFloat(const char* const file_name, float& p_) noexcept { return asRead(file_name, &p_, sizeof(p_), 1); }
	inline int32_t asReadTime(const char* const file_name, time_t& p_) noexcept { return asRead(file_name, &p_, sizeof(p_), 1); }

	//Pos
	inline int32_t asWritePos(const char* const file_name, Pos2& p_) noexcept { return asWrite(file_name, &p_, sizeof(p_), 1); }
	inline int32_t asWritePos(const char* const file_name, Pos4& p_) noexcept { return asWrite(file_name, &p_, sizeof(p_), 1); }
	inline int32_t asWritePos(const char* const file_name, PosA4& p_) noexcept { return asWrite(file_name, &p_, sizeof(p_), 1); }
	inline int32_t asWritePos(const char* const file_name, PosL4& p_) noexcept { return asWrite(file_name, &p_, sizeof(p_), 1); }
	inline int32_t asWritePos(const char* const file_name, Pos8& p_) noexcept { return asWrite(file_name, &p_, sizeof(p_), 1); }
	inline int32_t asWritePos(const char* const file_name, Pos2F& p_) noexcept { return asWrite(file_name, &p_, sizeof(p_), 1); }
	inline int32_t asWritePos(const char* const file_name, Pos4F& p_) noexcept { return asWrite(file_name, &p_, sizeof(p_), 1); }
	inline int32_t asWritePos(const char* const file_name, PosA4F& p_) noexcept { return asWrite(file_name, &p_, sizeof(p_), 1); }
	inline int32_t asWritePos(const char* const file_name, PosL4F& p_) noexcept { return asWrite(file_name, &p_, sizeof(p_), 1); }
	inline int32_t asWritePos(const char* const file_name, Pos8F& p_) noexcept { return asWrite(file_name, &p_, sizeof(p_), 1); }

	inline int32_t asWriteFloat(const char* const file_name, float& p_) noexcept { return asWrite(file_name, &p_, sizeof(p_), 1); }
	inline int32_t asWriteTime(const char* const file_name, time_t& p_) noexcept { return asWrite(file_name, &p_, sizeof(p_), 1); }

	//Pos
	inline int32_t asWritePos(const char* const file_name, const Pos2& p_) noexcept { Pos2 p(p_); return asWrite(file_name, &p, sizeof(p_), 1); }
	inline int32_t asWritePos(const char* const file_name, const Pos4& p_) noexcept { Pos4 p(p_); return asWrite(file_name, &p, sizeof(p_), 1); }
	inline int32_t asWritePos(const char* const file_name, const PosA4& p_) noexcept { PosA4 p(p_); return asWrite(file_name, &p, sizeof(p_), 1); }
	inline int32_t asWritePos(const char* const file_name, const PosL4& p_) noexcept { PosL4 p(p_); return asWrite(file_name, &p, sizeof(p_), 1); }
	inline int32_t asWritePos(const char* const file_name, const Pos8& p_) noexcept { Pos8 p(p_); return asWrite(file_name, &p, sizeof(p_), 1); }
	inline int32_t asWritePos(const char* const file_name, const Pos2F& p_) noexcept { Pos2F p(p_); return asWrite(file_name, &p, sizeof(p_), 1); }
	inline int32_t asWritePos(const char* const file_name, const Pos4F& p_) noexcept { Pos4F p(p_); return asWrite(file_name, &p, sizeof(p_), 1); }
	inline int32_t asWritePos(const char* const file_name, const PosA4F& p_) noexcept { PosA4F p(p_); return asWrite(file_name, &p, sizeof(p_), 1); }
	inline int32_t asWritePos(const char* const file_name, const PosL4F& p_) noexcept { PosL4F p(p_); return asWrite(file_name, &p, sizeof(p_), 1); }
	inline int32_t asWritePos(const char* const file_name, const Pos8F& p_) noexcept { Pos8F p(p_); return asWrite(file_name, &p, sizeof(p_), 1); }

	inline int32_t asWriteFloat(const char* const file_name, const float& p_) noexcept { float p(p_); return asWrite(file_name, &p, sizeof(p_), 1); }
	inline int32_t asWriteTime(const char* const file_name, const time_t& p_) noexcept { time_t p(p_); return asWrite(file_name, &p, sizeof(p_), 1); }

	const Pos2 asReadPos2(const char* const file_name) noexcept
	{
		Pos2 pos2;
		asRead(file_name, &pos2, sizeof(pos2), 1);
		return pos2;
	}

	inline int32_t asReadPos2(const char* const file_name, Pos2& pos2) noexcept
	{
		return asRead(file_name, &pos2, sizeof(pos2), 1);
	}

	inline int32_t asReadPos4(const char* const file_name, Pos4& pos4) noexcept
	{
		return asRead(file_name, &pos4, sizeof(pos4), 1);
	}

	inline int32_t asReadRGB(const char* const file_name, ColorRGB& color) noexcept
	{
		return asRead(file_name, &color, sizeof(color), 1);
	}

	inline int32_t asReadRGBA(const char* const file_name, Color& color) noexcept
	{
		return asRead(file_name, &color, sizeof(color), 1);
	}


	int32_t asWritePos2(const char* const file_name, const Pos2& add_pos2) noexcept
	{
		Pos2 pos2 = add_pos2;
		return asWrite(file_name, &pos2, sizeof(pos2), 1);
	}

	int32_t asWritePos4(const char* const file_name, const Pos4& add_pos4) noexcept
	{
		Pos4 pos4 = add_pos4;
		return asWrite(file_name, &pos4, sizeof(pos4), 1);
	}

	int32_t asWriteRGB(const char* const file_name, const ColorRGB& add_color) noexcept
	{
		ColorRGB color = add_color;
		return asWrite(file_name, &color, sizeof(color), 1);
	}

	int32_t asWriteRGBA(const char* const file_name, const Color& add_color) noexcept
	{
		Color color = add_color;
		return asWrite(file_name, &color, sizeof(color), 1);
	}

}

#endif //Included AsProject Library