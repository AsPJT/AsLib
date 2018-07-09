//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsÉâÉCÉuÉâÉä
//
//                    êßçÏé“: Ç™Ç¡ÇøÇÂ (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
	const int32_t asRect(const Pos4& pos_ = {}, const ColorRGBA& col = {}) {
#if defined(ASLIB_INCLUDE_DL) //DxLib
		if (DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, col.a) == -1) return -1;
		if (DxLib::DrawBox(int(pos_.x1), int(pos_.y1), int(pos_.x2), int(pos_.y2), col, TRUE) == -1) return -1;
		return 0;
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		const PosL4 as_rect_pos(pos_);
		s3d::Rect(as_rect_pos.x, as_rect_pos.y, as_rect_pos.w, as_rect_pos.h).draw(s3d::Color(col));
		return 0;
#elif defined(ASLIB_INCLUDE_OF)
		const PosL4 as_rect_pos(pos_);
		ofSetColor(col.r, col.g, col.b, col.a);
		ofFill();
		ofDrawRectangle(float(as_rect_pos.x), float(as_rect_pos.y), float(as_rect_pos.w), float(as_rect_pos.h));
		return 0;
#elif defined(ASLIB_INCLUDE_TP)
		return 0;
#else //Console
		return 0;
#endif
	}
	inline int32_t asRect(const ColorRGBA& col = {}, const Pos4& pos = {}) { return asRect(pos, col); }
}
