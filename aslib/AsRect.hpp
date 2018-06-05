//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsÉâÉCÉuÉâÉä
//
//                    êßçÏé“: Ç™Ç¡ÇøÇÂ (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
#if defined(ASLIB_INCLUDE_DL) //DxLib

	int32_t asRect(const Pos4& pos = {}, const ColorRGBA& col = {}) {
		if (DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, col.a) == -1) return -1;
		if (DxLib::DrawBox(int(pos.x1), int(pos.y1), int(pos.x2), int(pos.y2), col, TRUE) == -1) return -1;
		return 0;
	}

#elif defined(ASLIB_INCLUDE_S3) //Siv3D

	int32_t asRect(const Pos4& pos_ = {}, const ColorRGBA& colorRGBA = {}) {
		static PosL4 pos;
		pos = pos_;
		s3d::Rect(pos.x, pos.y, pos.w, pos.h).draw(s3d::Color(colorRGBA));
		return 0;
}

#else //Console

#endif

	inline int32_t asRect(const ColorRGBA& col = {}, const Pos4& pos = {}) { return asRect(pos, col); }

}
