//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsÉâÉCÉuÉâÉä
//
//                    êßçÏé“: Ç™Ç¡ÇøÇÂ (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
#if defined(__DXLIB) //DxLib

	int32_t asRect(const Pos4& pos4 = {}, const ColorRGB& colorRGB = {}) {
		if (DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255) == -1) return -1;
		if (DxLib::DrawBox(int(pos4.x1), int(pos4.y1), int(pos4.x2), int(pos4.y2), AsDxColor(colorRGB), TRUE) == -1) return -1;
		return 0;
	}

	int32_t asRect(const Pos4& pos4 = {}, const ColorRGBA& colorRGBA = {}) {
		if (DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, colorRGBA.a) == -1) return -1;
		if (DxLib::DrawBox(int(pos4.x1), int(pos4.y1), int(pos4.x2), int(pos4.y2), AsDxColor(colorRGBA), TRUE) == -1) return -1;
		return 0;
	}

	int32_t asRect(const Pos2& pos2 = {}, const ColorRGB& colorRGB = {}) {
		if (DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255) == -1) return -1;
		if (DxLib::DrawBox(0, 0, int(pos2.x), int(pos2.y), AsDxColor(colorRGB), TRUE) == -1) return -1;
		return 0;
	}

	int32_t asRect(const Pos2& pos2 = {}, const ColorRGBA& colorRGBA = {}) {
		if (DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, colorRGBA.a) == -1) return -1;
		if (DxLib::DrawBox(0, 0, int(pos2.x), int(pos2.y), AsDxColor(colorRGBA), TRUE) == -1) return -1;
		return 0;
	}

	int32_t asRect(const int32_t xy = 0, const ColorRGBA& colorRGBA = {}) {
		if (DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, colorRGBA.a) == -1) return -1;
		if (DxLib::DrawBox(0, 0, int(xy), int(xy), AsDxColor(colorRGBA), TRUE) == -1) return -1;
		return 0;
	}

	int32_t asRect(const int32_t x = 0, const int32_t y = 0, const ColorRGBA& colorRGBA = {}) {
		if (DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, colorRGBA.a) == -1) return -1;
		if (DxLib::DrawBox(0, 0, int(x), int(y), AsDxColor(colorRGBA), TRUE) == -1) return -1;
		return 0;
	}

	int32_t asRect(const int32_t x1 = 0, const int32_t y1 = 0, const int32_t xy2 = 0, const ColorRGBA& colorRGBA = {}) {
		if (DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, colorRGBA.a) == -1) return -1;
		if (DxLib::DrawBox(int(x1), int(y1), int(xy2), int(xy2), AsDxColor(colorRGBA), TRUE) == -1) return -1;
		return 0;
	}

	int32_t asRect(const int32_t x1 = 0, const int32_t y1 = 0, const int32_t x2 = 0, const int32_t y2 = 0, const ColorRGBA& colorRGBA = {}) {
		if (DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, colorRGBA.a) == -1) return -1;
		if (DxLib::DrawBox(int(x1), int(y1), int(x2), int(y2), AsDxColor(colorRGBA), TRUE) == -1) return -1;
		return 0;
	}

	int32_t asRect(const int32_t xy = 0, const ColorRGB& colorRGB = {}) {
		if (DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255) == -1) return -1;
		if (DxLib::DrawBox(0, 0, int(xy), int(xy), AsDxColor(colorRGB), TRUE) == -1) return -1;
		return 0;
	}

	int32_t asRect(const int32_t x = 0, const int32_t y = 0, const ColorRGB& colorRGB = {}) {
		if (DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255) == -1) return -1;
		if (DxLib::DrawBox(0, 0, int(x), int(y), AsDxColor(colorRGB), TRUE) == -1) return -1;
		return 0;
	}

	int32_t asRect(const int32_t x1 = 0, const int32_t y1 = 0, const int32_t xy2 = 0, const ColorRGB& colorRGB = {}) {
		if (DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255) == -1) return -1;
		if (DxLib::DrawBox(int(x1), int(y1), int(xy2), int(xy2), AsDxColor(colorRGB), TRUE) == -1) return -1;
		return 0;
	}

	int32_t asRect(const int32_t x1 = 0, const int32_t y1 = 0, const int32_t x2 = 0, const int32_t y2 = 0, const ColorRGB& colorRGB = {}) {
		if (DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255) == -1) return -1;
		if (DxLib::DrawBox(int(x1), int(y1), int(x2), int(y2), AsDxColor(colorRGB), TRUE) == -1) return -1;
		return 0;
	}

#elif defined(SIV3D_INCLUDED) //Siv3D

#else //Console

#endif
}
