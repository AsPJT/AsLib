//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsÉâÉCÉuÉâÉä
//
//                    êßçÏé“: Ç™Ç¡ÇøÇÂ (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{

	//â~Çï`âÊ
	inline bool asCircle(const Pos2& pos_, const int32_t& r_,const ColorRGBA& col_)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		return 	(DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, int(col_.a)) == 0) && (DxLib::DrawCircle(int(pos_.x), int(pos_.y), int(r_), col_, TRUE) == 0);
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		//todo
		return true;
#else //Console

#endif
	}

	struct Circle
	{
		Circle() = default;
		constexpr Circle(const Pos2& pos_, const int32_t r_, const ColorRGBA& col_ = black_RGBA) :pos(pos_), r(r_), col(col_) {};
		const Circle& draw() const { asCircle(pos, r, col); return *this; }
		Pos2 pos;
		int32_t r;
		ColorRGBA col;
	};

}
