//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asƒ‰ƒCƒuƒ‰ƒŠ
//
//                    §ìÒ: ‚ª‚Á‚¿‚å (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
	constexpr bool IS_HEIGHT = true;
	constexpr bool IS_WIDTH = false;

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

		uint8_t r = COLOR_MAX;
		uint8_t g = COLOR_MAX;
		uint8_t b = COLOR_MAX;
	};

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

		uint8_t r = COLOR_MAX;
		uint8_t g = COLOR_MAX;
		uint8_t b = COLOR_MAX;
		uint8_t a = COLOR_MAX;
	};

	void asColorMul(uint8_t& color1, const uint8_t color2)
	{
		color1 = uint8_t((int32_t(color1) * int32_t(color2)) >> BIT_SHIFT_DIV_256);
		return;
	}

	void asColorMul(ColorRGB& color1, const ColorRGB& color2)
	{
		asColorMul(color1.r, color2.r);
		asColorMul(color1.g, color2.g);
		asColorMul(color1.b, color2.b);
		return;
	}

	void asColorMul(ColorRGB& color1, const ColorRGBA& color2)
	{
		asColorMul(color1.r, color2.r);
		asColorMul(color1.g, color2.g);
		asColorMul(color1.b, color2.b);
		return;
	}

	void asColorMul(ColorRGBA& color1, const ColorRGB& color2)
	{
		asColorMul(color1.r, color2.r);
		asColorMul(color1.g, color2.g);
		asColorMul(color1.b, color2.b);
		return;
	}

	void asColorMul(ColorRGBA& color1, const ColorRGBA& color2)
	{
		asColorMul(color1.r, color2.r);
		asColorMul(color1.g, color2.g);
		asColorMul(color1.b, color2.b);
		asColorMul(color1.a, color2.a);
		return;
	}

	void asColorAdd(uint8_t& color1, const uint8_t color2)
	{
		int32_t color32 = int32_t(color1) + int32_t(color2);
		if (color32 >= COLOR_MAX) color1 = uint8_t(COLOR_MAX);
		else color1 = uint8_t(color32);

		return;
	}

	void asColorAdd(ColorRGB& color1, const ColorRGB& color2)
	{
		asColorAdd(color1.r, color2.r);
		asColorAdd(color1.g, color2.g);
		asColorAdd(color1.b, color2.b);
		return;
	}

	void asColorAdd(ColorRGB& color1, const ColorRGBA& color2)
	{
		asColorAdd(color1.r, color2.r);
		asColorAdd(color1.g, color2.g);
		asColorAdd(color1.b, color2.b);
		return;
	}

	void asColorAdd(ColorRGBA& color1, const ColorRGB& color2)
	{
		asColorAdd(color1.r, color2.r);
		asColorAdd(color1.g, color2.g);
		asColorAdd(color1.b, color2.b);
		return;
	}

	void asColorAdd(ColorRGBA& color1, const ColorRGBA& color2)
	{
		asColorAdd(color1.r, color2.r);
		asColorAdd(color1.g, color2.g);
		asColorAdd(color1.b, color2.b);
		asColorAdd(color1.a, color2.a);
		return;
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
