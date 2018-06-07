//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsÉâÉCÉuÉâÉä
//
//                    êßçÏé“: Ç™Ç¡ÇøÇÂ (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{

	struct Circle
	{
		Circle() = default;
		constexpr Circle(const Pos2& pos_, const int32_t r_, const ColorRGBA& col_ = black_RGBA) :pos(pos_), r(r_), col(col_) {};
		const Circle& draw() const;
		Pos2 pos;
		int32_t r;
		ColorRGBA col;
	};

#if defined(ASLIB_INCLUDE_DL) //DxLib

	inline const Circle& Circle::draw() const
	{
		DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, int(col.a));
		DxLib::DrawCircle(int(pos.x), int(pos.y), int(r), col, TRUE);
		return *this;
	}

#elif defined(ASLIB_INCLUDE_S3) //Siv3D

#else //Console

#endif

}
