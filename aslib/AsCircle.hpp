/*#######################################################################################
	Made by Kasugaccho
	Made by As Project
	https://github.com/Kasugaccho/AsLib
	wanotaitei@gmail.com

	This code is licensed under CC0.
#######################################################################################*/
#ifndef INCLUDED_AS_PROJECT_LIBRARY_CIRCLE
#define INCLUDED_AS_PROJECT_LIBRARY_CIRCLE


namespace AsLib
{

	//円を描画
	inline void asCircle(const Pos2& pos_, const std::int32_t& r_,const Color& col_) noexcept
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
#elif defined(ASLIB_INCLUDE_C2)

#elif defined(ASLIB_INCLUDE_SF)
return 0;
#elif defined(ASLIB_INCLUDE_TP)
#else //Console
#endif
	}

	inline void asCircle(const PosA4& pos_, const Color& col_) noexcept { asCircle(Pos2(pos_), pos_.w, col_); }

	struct Circle
	{
		Circle() = default;
		constexpr explicit Circle(const Pos2& pos_, const std::int32_t r_, const Color& col_ = aslib_color_black_a) :pos(pos_), r(r_), col(col_) {};
		//const only
		const Circle& draw() const noexcept { asCircle(pos, r, col); return *this; }
		const Circle& draw(const Pos2& pos_) const noexcept { asCircle(pos_, r, col); return *this; }
		const Circle& draw(const Color& col_) const noexcept { asCircle(pos, r, col_); return *this; }
		Pos2 pos;
		std::int32_t r;
		Color col;
	};

}

#endif //Included AsProject Library