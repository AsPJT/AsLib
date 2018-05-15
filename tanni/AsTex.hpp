//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asƒ‰ƒCƒuƒ‰ƒŠ
//
//                    §ìŽÒ: ‚ª‚Á‚¿‚å (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{

#if defined(__DXLIB) //DxLib

	inline Tex AsLoadTex(const char* const name)
	{
		return Tex(DxLib::LoadGraph(name));
	}

	int32_t AsTexSize(const Tex id, Pos2& texture_size)
	{
		int size_x = 0, size_y = 0;
		if (DxLib::GetGraphSize(id, &size_x, &size_y) == -1) return -1;
		texture_size.x = int32_t(size_x);
		texture_size.y = int32_t(size_y);
		return 0;
	}

	AS_Texture AsLoadAST(const char* const add_name)
	{
		AS_Texture texture_handle;
		texture_handle.id = Tex(DxLib::LoadGraph(add_name));
		AsTexSize(texture_handle.id, texture_handle.pixel_size);
		return texture_handle;
	}

	int32_t asTex(const Tex tex, const Pos4& pos4 = pos4_100, const uint8_t alpha = 255, const ColorRGBA& colorRGBA = color_0)
	{
		if (DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha) == -1) return -1;
		if (DxLib::DrawExtendGraph(int(pos4.x1), int(pos4.y1), int(pos4.x2), int(pos4.y2), tex, TRUE) != -1) return 0;

		if (colorRGBA.a == 0) return -1;
		if (asRect(pos4, colorRGBA) == -1) return -1;
		return -2;
	}

	int32_t AsTexAt(const Tex tex, const Pos4& pos4 = {}, const uint8_t alpha = 255, const ColorRGBA& colorRGBA = color_0) {
		const int32_t sub_x = (pos4.x2 - pos4.x1) >> BIT_SHIFT_DIV_2;
		const int32_t sub_y = (pos4.y2 - pos4.y1) >> BIT_SHIFT_DIV_2;
		const int32_t x1 = pos4.x1 - sub_x;
		const int32_t x2 = pos4.x2 - sub_x;
		const int32_t y1 = pos4.y1 - sub_y;
		const int32_t y2 = pos4.y2 - sub_y;

		const Pos4 new_pos4 = { x1,y1,x2,y2 };
		return asTex(tex, new_pos4, alpha, colorRGBA);
	}

#elif defined(SIV3D_INCLUDED) //Siv3D

#else //Console

#endif

	enum :uint8_t {
		TEXTURE_RATIO,
		TEXTURE_RATIO_X,
		TEXTURE_RATIO_Y
	};

	//todo
	class Texture
	{
	public:
		Texture& operator=(const Tex& add_texture);
		Texture& operator=(const uint8_t& add_alpha);
		Texture& operator=(const ColorRGBA& add_color);
		Texture& operator=(const ColorRGB& add_color);

		Texture& operator()(const Pos4& add_pos);
		Texture& operator()(const Pos4R& add_pos, const Pos2& window_size, const uint8_t mode = 0);

		Tex showID();

	private:
		Tex id = TEX_INIT;
		uint8_t alpha = 255;

		ColorRGBA color = color_0;
		Pos4 pos4 = pos4_0;
		Pos2 pixel_size = pos2_0;
	};

	inline Texture& Texture::operator()(const Pos4& add_pos)
	{
		pos4 = add_pos;
		return *this;
	}

	inline Texture& Texture::operator()(const Pos4R& add_pos, const Pos2& window_size, const uint8_t ratio_mode)
	{
		switch (ratio_mode)
		{
		case TEXTURE_RATIO_X:
			pos4 = toPos4X(add_pos, window_size, pixel_size);
			break;
		case TEXTURE_RATIO_Y:
			pos4 = toPos4Y(add_pos, window_size, pixel_size);
			break;
		default:
			pos4 = toPos4(add_pos, window_size);
			break;
		}
		return *this;
	}

	inline Tex Texture::showID()
	{
		return id;
	}

	inline Texture& Texture::operator=(const Tex& add_texture)
	{
		id = add_texture;
		return *this;
	}

	inline Texture& Texture::operator=(const uint8_t& add_alpha)
	{
		alpha = add_alpha;
		return *this;
	}

	inline Texture& Texture::operator=(const ColorRGBA& add_color)
	{
		color = add_color;
		return *this;
	}

	inline Texture& Texture::operator=(const ColorRGB& add_color)
	{
		color = add_color;
		return *this;
	}

}