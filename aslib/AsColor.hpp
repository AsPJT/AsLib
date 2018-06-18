//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asライブラリ
//
//                    制作者: がっちょ (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
	constexpr int32_t BIT_SHIFT_DIV_2 = 1;
	constexpr int32_t BIT_SHIFT_DIV_256 = 8;

	//色
	struct ColorRGB;
	struct ColorRGBA;

	constexpr uint8_t COLOR_MAX = 255;

	//３色
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

		ColorRGB() = default;
		constexpr ColorRGB(const uint8_t r_, const uint8_t g_, const uint8_t b_, const uint8_t a_) :r(r_), g(g_), b(b_) { };
		constexpr ColorRGB(const uint8_t r_, const uint8_t g_, const uint8_t b_) :r(r_), g(g_), b(b_) {};

		//他のライブラリ対応
		const unsigned int uint() { return ((unsigned int)(this->r << 0x10) + (unsigned int)(this->g << 0x8) + (unsigned int)(this->b & 0xff)); }
		constexpr ColorRGB(const unsigned int col_) :r(uint8_t((col_ & 0xffffff) >> 0x10)), g(uint8_t((col_ & 0xffff) >> 0x8)), b(uint8_t(col_ & 0xff)) {}
#if defined(ASLIB_INCLUDE_DL)
		operator unsigned int() const { return DxLib::GetColor(int(this->r), int(this->g), int(this->b)); };
#elif defined(ASLIB_INCLUDE_S3)
		operator s3d::Color() const
		{
			const s3d::Color col(uint32_t(this->r), uint32_t(this->g), uint32_t(this->b));
			return col;
		};
#endif
	};

	//３色＋透過
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

		ColorRGBA() = default;
		constexpr ColorRGBA(const uint8_t r_, const uint8_t g_, const uint8_t b_, const uint8_t a_) :r(r_), g(g_), b(b_), a(a_) {};
		constexpr ColorRGBA(const uint8_t r_, const uint8_t g_, const uint8_t b_) :r(r_), g(g_), b(b_), a(uint8_t(255)) {};

		//他のライブラリ対応
		const unsigned int uint() { return ((unsigned int)(this->r << 0x10) + (unsigned int)(this->g << 0x8) + (unsigned int)(this->b & 0xff)); }
		constexpr ColorRGBA(const unsigned int col_) :r(uint8_t((col_ & 0xffffff) >> 0x10)), g(uint8_t((col_ & 0xffff) >> 0x8)), b(uint8_t(col_ & 0xff)) {}
#if defined(ASLIB_INCLUDE_DL)
		operator unsigned int() const { return DxLib::GetColor(int(this->r), int(this->g), int(this->b)); };
#elif defined(ASLIB_INCLUDE_S3)
		operator s3d::Color() const { return s3d::Color(uint32_t(this->r), uint32_t(this->g), uint32_t(this->b), uint32_t(this->a)); };
		operator s3d::ColorF() const { return s3d::ColorF(s3d::Color(uint32_t(this->r), uint32_t(this->g), uint32_t(this->b), uint32_t(this->a))); };
#endif
	};

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

	inline void asRand(ColorRGBA& c_) { c_.r = asRand8(); c_.g = asRand8(); c_.b = asRand8(); c_.a = 255; }
	inline void asRandA(ColorRGBA& c_) { c_.r = asRand8(); c_.g = asRand8(); c_.b = asRand8(); c_.a = asRand8(); }
	inline void asRand(ColorRGBA* const array_, const size_t s_) { for (size_t i = 0; i < s_; ++i) asRand(array_[i]); }
	inline void asRandA(ColorRGBA* const array_, const size_t s_) { for (size_t i = 0; i < s_; ++i) asRandA(array_[i]); }
	inline void asRand(ColorRGBA& c_, const uint8_t m_) { c_.r = asRand8(m_); c_.g = asRand8(m_); c_.b = asRand8(m_); c_.a = 255; }
	inline void asRandA(ColorRGBA& c_, const uint8_t m_) { c_.r = asRand8(m_); c_.g = asRand8(m_); c_.b = asRand8(m_); c_.a = asRand8(m_); }
	inline void asRand(ColorRGBA* const array_, const size_t s_, const uint8_t m_) { for (size_t i = 0; i < s_; ++i) asRand(array_[i], m_); }
	inline void asRandA(ColorRGBA* const array_, const size_t s_, const uint8_t m_) { for (size_t i = 0; i < s_; ++i) asRandA(array_[i], m_); }
}
