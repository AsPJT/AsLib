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
	inline void asCircle(const Pos2& pos_, const int32_t& r_,const Color& col_)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		DxLib::SetDrawBlendMode(1, int(col_.a)); 
		DxLib::DrawCircle(int(pos_.x), int(pos_.y), int(r_), (unsigned int)col_, 1);
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		s3d::Circle(double(pos_.x), double(pos_.y), r_).draw(col_);
#elif defined(ASLIB_INCLUDE_OF)
		ofSetColor(col_.r, col_.g, col_.b, col_.a);
		ofFill();
		ofDrawCircle(float(pos_.x), float(pos_.y), float(r_));
#elif defined(ASLIB_INCLUDE_TP)
#else //Console
#endif
	}

	inline void asCircle(const PosA4& pos_, const Color& col_) { asCircle(Pos2(pos_), pos_.w, col_); }

	struct Circle
	{
		Circle() = default;
		constexpr Circle(const Pos2& pos_, const int32_t r_, const Color& col_ = black_RGBA) :pos(pos_), r(r_), col(col_) {};
		const Circle& draw() const { asCircle(pos, r, col); return *this; }
		const Circle& draw(const Pos2& pos_) const { asCircle(pos_, r, col); return *this; }
		const Circle& draw(const Color& col_) const { asCircle(pos, r, col_); return *this; }
		Pos2 pos;
		int32_t r;
		Color col;
	};

}
