/*#######################################################################################
	Made by Kasugaccho
	Made by As Project
	https://github.com/Kasugaccho/AsLib
	wanotaitei@gmail.com

	This code is licensed under CC0.
#######################################################################################*/
#ifndef INCLUDED_AS_PROJECT_LIBRARY_RECT
#define INCLUDED_AS_PROJECT_LIBRARY_RECT


namespace AsLib
{
	inline void asRect(const PosL4& pos_ = {}, const Color& col = {}) noexcept {
#if defined(ASLIB_INCLUDE_DL) //DxLib
		DxLib::SetDrawBlendMode(1, int(col.a));
		DxLib::DrawBox(int(pos_.x), int(pos_.y), int(pos_.x + pos_.w), int(pos_.y + pos_.h), (unsigned int)col, 1);
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		s3d::Rect(pos_.x, pos_.y, pos_.w, pos_.h).draw(s3d::Color(col));
#elif defined(ASLIB_INCLUDE_OF)
		ofSetColor(col.r, col.g, col.b, col.a);
		ofFill();
		ofDrawRectangle(float(pos_.x), float(pos_.y), float(pos_.w), float(pos_.h));
#elif defined(ASLIB_INCLUDE_C2)

#elif defined(ASLIB_INCLUDE_SF)
return 0;
#elif defined(ASLIB_INCLUDE_TP)
#else //Console
#endif
	}
	inline void asRect(const Color& col = {}, const Pos4& pos = {}) noexcept { asRect(pos, col); }
}

#endif //Included AsProject Library