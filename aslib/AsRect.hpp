//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsProject Library
//
//                    Created by Gaccho (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
	inline void asRect(const PosL4& pos_ = {}, const Color& col = {}) {
#if defined(ASLIB_INCLUDE_DL) //DxLib
		DxLib::SetDrawBlendMode(1, int(col.a));
		DxLib::DrawBox(int(pos_.x), int(pos_.y), int(pos_.x + pos_.w), int(pos_.y + pos_.h), (unsigned int)col, 1);
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		s3d::Rect(pos_.x, pos_.y, pos_.w, pos_.h).draw(s3d::Color(col));
#elif defined(ASLIB_INCLUDE_OF)
		ofSetColor(col.r, col.g, col.b, col.a);
		ofFill();
		ofDrawRectangle(float(pos_.x), float(pos_.y), float(pos_.w), float(pos_.h));
#elif defined(ASLIB_INCLUDE_TP)
#else //Console
#endif
	}
	inline void asRect(const Color& col = {}, const Pos4& pos = {}) { asRect(pos, col); }
}
