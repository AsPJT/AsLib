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
	const bool asCircle(const Pos2& pos_, const int32_t& r_,const ColorRGBA& col_)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		return 	(DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, int(col_.a)) == 0) && (DxLib::DrawCircle(int(pos_.x), int(pos_.y), int(r_), col_, TRUE) == 0);
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		s3d::Circle(double(pos_.x), double(pos_.y), r_).draw(col_);
		return true;
#elif defined(ASLIB_INCLUDE_OF)
		ofSetColor(col_.r, col_.g, col_.b, col_.a);
		ofFill();
		ofDrawCircle(float(pos_.x), float(pos_.y), float(r_));
		return true;
#elif defined(ASLIB_INCLUDE_TP)
		return true;
#else //Console
		return true;
#endif
	}

	inline const bool asCircle(const PosA4& pos_, const ColorRGBA& col_) { return asCircle(Pos2(pos_), pos_.w, col_); }

	struct Circle
	{
		Circle() = default;
		constexpr Circle(const Pos2& pos_, const int32_t r_, const ColorRGBA& col_ = black_RGBA) :pos(pos_), r(r_), col(col_) {};
		const Circle& draw() const { asCircle(pos, r, col); return *this; }
		const Circle& draw(const Pos2& pos_) const { asCircle(pos_, r, col); return *this; }
		const Circle& draw(const ColorRGBA& col_) const { asCircle(pos, r, col_); return *this; }
		Pos2 pos;
		int32_t r;
		ColorRGBA col;
	};

}
