//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asƒ‰ƒCƒuƒ‰ƒŠ
//
//                    §ìÒ: ‚ª‚Á‚¿‚å (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
	constexpr int32_t BIT_SHIFT_DIV_2 = 1;
	constexpr int32_t BIT_SHIFT_DIV_256 = 8;

	//F
	struct ColorRGB;
	struct ColorRGBA;

	constexpr uint8_t COLOR_MAX = 255;

	//‚RF
	struct ColorRGB
	{
		ColorRGB& operator++();
		ColorRGB& operator=(const ColorRGBA& add_color);
		ColorRGB& operator+=(const ColorRGB& add_color);
		ColorRGB& operator+=(const ColorRGBA& add_color);
		ColorRGB& operator+(const ColorRGB& add_color);
		ColorRGB& operator+(const ColorRGBA& add_color);
		ColorRGB& operator*=(const ColorRGB& add_color);
		ColorRGB& operator*=(const ColorRGBA& add_color);
		ColorRGB& operator*(const ColorRGB& add_color);
		ColorRGB& operator*(const ColorRGBA& add_color);
		operator ColorRGBA() const;

		uint8_t r = COLOR_MAX;
		uint8_t g = COLOR_MAX;
		uint8_t b = COLOR_MAX;
#if defined(ASLIB_INCLUDE_DL)
		operator unsigned int() const;
#elif defined(ASLIB_INCLUDE_S3)
		operator s3d::Color() const;
#endif
	};
#if defined(ASLIB_INCLUDE_DL)
	inline ColorRGB::operator unsigned int() const
	{
		const unsigned int col = DxLib::GetColor(int(this->r), int(this->g), int(this->b));
		return col;
	}
#elif defined(ASLIB_INCLUDE_S3)
	inline ColorRGB::operator s3d::Color() const
	{
		const s3d::Color col(uint32_t(this->r), uint32_t(this->g), uint32_t(this->b));
		return col;
	}
#endif

	//‚RF{“§‰ß
	struct ColorRGBA
	{
		ColorRGBA& operator++();
		ColorRGBA& operator=(const ColorRGB& add_color);
		ColorRGBA& operator()(const uint8_t add_alpha);
		ColorRGBA& operator+=(const ColorRGB& add_color);
		ColorRGBA& operator+=(const ColorRGBA& add_color);
		ColorRGBA& operator+(const ColorRGB& add_color);
		ColorRGBA& operator+(const ColorRGBA& add_color);
		ColorRGBA& operator*=(const ColorRGB& add_color);
		ColorRGBA& operator*=(const ColorRGBA& add_color);
		ColorRGBA& operator*(const ColorRGB& add_color);
		ColorRGBA& operator*(const ColorRGBA& add_color);
		operator ColorRGB() const;

		uint8_t r = COLOR_MAX;
		uint8_t g = COLOR_MAX;
		uint8_t b = COLOR_MAX;
		uint8_t a = COLOR_MAX;
#if defined(ASLIB_INCLUDE_DL)
		operator unsigned int() const;
#elif defined(ASLIB_INCLUDE_S3)
		operator s3d::Color() const;
#endif
	};

#if defined(ASLIB_INCLUDE_DL)
	inline ColorRGBA::operator unsigned int() const
	{
		const unsigned int col = DxLib::GetColor(int(this->r), int(this->g), int(this->b));
		return col;
	}
#elif defined(ASLIB_INCLUDE_S3)
	inline ColorRGBA::operator s3d::Color() const
	{
		const s3d::Color col(uint32_t(this->r), uint32_t(this->g), uint32_t(this->b), uint32_t(this->a));
		return col;
	}
#endif

	inline ColorRGBA::operator ColorRGB() const
	{
		ColorRGB col;
		col.r = this->r;
		col.g = this->g;
		col.b = this->b;
		return col;
	}

	inline ColorRGB::operator ColorRGBA() const
	{
		ColorRGBA col;
		col.r = this->r;
		col.g = this->g;
		col.b = this->b;
		return col;
	}

	void asColorMul(uint8_t& color1, const uint8_t color2)
	{
		color1 = uint8_t((int32_t(color1) * int32_t(color2)) >> BIT_SHIFT_DIV_256);
	}

	void asColorMul(ColorRGB& color1, const ColorRGB& color2)
	{
		asColorMul(color1.r, color2.r);
		asColorMul(color1.g, color2.g);
		asColorMul(color1.b, color2.b);
	}

	void asColorMul(ColorRGB& color1, const ColorRGBA& color2)
	{
		asColorMul(color1.r, color2.r);
		asColorMul(color1.g, color2.g);
		asColorMul(color1.b, color2.b);
	}

	void asColorMul(ColorRGBA& color1, const ColorRGB& color2)
	{
		asColorMul(color1.r, color2.r);
		asColorMul(color1.g, color2.g);
		asColorMul(color1.b, color2.b);
	}

	void asColorMul(ColorRGBA& color1, const ColorRGBA& color2)
	{
		asColorMul(color1.r, color2.r);
		asColorMul(color1.g, color2.g);
		asColorMul(color1.b, color2.b);
		asColorMul(color1.a, color2.a);
	}

	void asColorAdd(uint8_t& color1, const uint8_t color2)
	{
		int32_t color32 = int32_t(color1) + int32_t(color2);
		if (color32 >= COLOR_MAX) color1 = uint8_t(COLOR_MAX);
		else color1 = uint8_t(color32);
	}

	void asColorAdd(ColorRGB& color1, const ColorRGB& color2)
	{
		asColorAdd(color1.r, color2.r);
		asColorAdd(color1.g, color2.g);
		asColorAdd(color1.b, color2.b);
	}

	void asColorAdd(ColorRGB& color1, const ColorRGBA& color2)
	{
		asColorAdd(color1.r, color2.r);
		asColorAdd(color1.g, color2.g);
		asColorAdd(color1.b, color2.b);
	}

	void asColorAdd(ColorRGBA& color1, const ColorRGB& color2)
	{
		asColorAdd(color1.r, color2.r);
		asColorAdd(color1.g, color2.g);
		asColorAdd(color1.b, color2.b);
	}

	void asColorAdd(ColorRGBA& color1, const ColorRGBA& color2)
	{
		asColorAdd(color1.r, color2.r);
		asColorAdd(color1.g, color2.g);
		asColorAdd(color1.b, color2.b);
		asColorAdd(color1.a, color2.a);
	}

	inline ColorRGB& ColorRGB::operator++()
	{
		if (this->r != COLOR_MAX)++this->r;
		if (this->g != COLOR_MAX)++this->g;
		if (this->b != COLOR_MAX)++this->b;
		return *this;
	}

	inline ColorRGBA& ColorRGBA::operator++()
	{
		if (this->r != COLOR_MAX)++this->r;
		if (this->g != COLOR_MAX)++this->g;
		if (this->b != COLOR_MAX)++this->b;
		if (this->a != COLOR_MAX)++this->a;
		return *this;
	}

	inline ColorRGB& ColorRGB::operator*(const ColorRGB& add_color)
	{
		asColorMul(*this, add_color);
		return *this;
	}

	inline ColorRGB& ColorRGB::operator*(const ColorRGBA& add_color)
	{
		asColorMul(*this, add_color);
		return *this;
	}

	inline ColorRGBA& ColorRGBA::operator*(const ColorRGB& add_color)
	{
		asColorMul(*this, add_color);
		return *this;
	}

	inline ColorRGBA& ColorRGBA::operator*(const ColorRGBA& add_color)
	{
		asColorMul(*this, add_color);
		return *this;
	}

	inline ColorRGBA& ColorRGBA::operator*=(const ColorRGB& add_color)
	{
		asColorMul(*this, add_color);
		return *this;
	}

	inline ColorRGBA& ColorRGBA::operator*=(const ColorRGBA& add_color)
	{
		asColorMul(*this, add_color);
		return *this;
	}

	inline ColorRGB& ColorRGB::operator*=(const ColorRGB& add_color)
	{
		asColorMul(*this, add_color);
		return *this;
	}

	inline ColorRGB& ColorRGB::operator*=(const ColorRGBA& add_color)
	{
		asColorMul(*this, add_color);
		return *this;
	}


	inline ColorRGB& ColorRGB::operator+(const ColorRGB& add_color)
	{
		asColorAdd(*this, add_color);
		return *this;
	}

	inline ColorRGB& ColorRGB::operator+(const ColorRGBA& add_color)
	{
		asColorAdd(*this, add_color);
		return *this;
	}

	inline ColorRGBA& ColorRGBA::operator+(const ColorRGB& add_color)
	{
		asColorAdd(*this, add_color);
		return *this;
	}

	inline ColorRGBA& ColorRGBA::operator+(const ColorRGBA& add_color)
	{
		asColorAdd(*this, add_color);
		return *this;
	}

	inline ColorRGBA& ColorRGBA::operator+=(const ColorRGB& add_color)
	{
		asColorAdd(*this, add_color);
		return *this;
	}

	inline ColorRGBA& ColorRGBA::operator+=(const ColorRGBA& add_color)
	{
		asColorAdd(*this, add_color);
		return *this;
	}

	inline ColorRGB& ColorRGB::operator+=(const ColorRGB& add_color)
	{
		asColorAdd(*this, add_color);
		return *this;
	}

	inline ColorRGB& ColorRGB::operator+=(const ColorRGBA& add_color)
	{
		asColorAdd(*this, add_color);
		return *this;
	}

	inline ColorRGBA& ColorRGBA::operator()(const uint8_t add_alpha = COLOR_MAX)
	{
		this->a = add_alpha;
		return *this;
	}

	inline ColorRGB& ColorRGB::operator=(const ColorRGBA& add_color)
	{
		this->r = add_color.r;
		this->g = add_color.g;
		this->b = add_color.b;
		return *this;
	}

	inline ColorRGBA& ColorRGBA::operator=(const ColorRGB& add_color)
	{
		this->r = add_color.r;
		this->g = add_color.g;
		this->b = add_color.b;
		this->a = 255;
		return *this;
	}

}
