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

	Tex AsLoadTex(const char* const name)
	{
		return Tex(DxLib::LoadGraph(name));
	}

	int32_t AsTexSize(const Tex handle, Pos2& texture_size)
	{
		int size_x = 0, size_y = 0;
		if (DxLib::GetGraphSize(handle, &size_x, &size_y) == -1) return -1;
		texture_size.x = int32_t(size_x);
		texture_size.y = int32_t(size_y);
		return 0;
	}

	Tex AsLoadTex(const char* const name, Pos2& texture_size)
	{
		Tex texture_handle = Tex(DxLib::LoadGraph(name));
		AsTexSize(texture_handle, texture_size);
		return texture_handle;
	}

	int32_t AsTex(const Tex tex, const Pos4& pos4 = {}, const uint8_t alpha = 255, const ColorRGBA& colorRGBA = color_0) {
		if (DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha) == -1) return -1;
		if (DxLib::DrawExtendGraph(int(pos4.x1), int(pos4.y1), int(pos4.x2), int(pos4.y2), tex, TRUE) != -1) return 0;

		if (colorRGBA.a == 0) return -1;
		if (AsRect(pos4, colorRGBA) == -1) return -1;
		return -2;
	}

	int32_t AsTexAt(const Tex tex, const Pos4& pos4 = {}, const uint8_t alpha = 255, const ColorRGBA& colorRGBA = color_0) {
		const int32_t sub_x = (pos4.x2 - pos4.x1) / 2;
		const int32_t sub_y = (pos4.y2 - pos4.y1) / 2;
		const int32_t x1 = pos4.x1 - sub_x;
		const int32_t x2 = pos4.x2 - sub_x;
		const int32_t y1 = pos4.y1 - sub_y;
		const int32_t y2 = pos4.y2 - sub_y;

		const Pos4 new_pos4 = { x1,y1,x2,y2 };
		return AsTex(tex, new_pos4, alpha, colorRGBA);
	}

#elif defined(SIV3D_INCLUDED) //Siv3D

#else //Console

#endif

	enum :uint8_t {
		TEXTURE_RATIO,
		TEXTURE_RATIO_X,
		TEXTURE_RATIO_Y
	};

	class Texture
	{
	public:
		Texture(const char* const name);
		int32_t draw();
		int32_t drawAt();
		Texture& operator=(const Tex& add_texture);
		Texture& operator=(const uint8_t& add_alpha);
		Texture& operator=(const ColorRGBA& add_color);
		Texture& operator=(const ColorRGB& add_color);

		Texture& operator()(const Pos4& add_pos);
		Texture& operator()(const Pos4R& add_pos, const Pos2& window_size, const uint8_t mode = 0);

	private:
		Tex handle = TEX_INIT;
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

	inline Texture& Texture::operator=(const Tex& add_texture)
	{
		handle = add_texture;
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

	inline Texture::Texture(const char* const name)
	{
		handle = AsLoadTex(name, pixel_size);
	}

	inline int32_t Texture::draw()
	{
		return AsTex(handle, pos4, alpha, color);
	}

	inline int32_t Texture::drawAt()
	{
		return AsTexAt(handle, pos4, alpha, color);
	}



}