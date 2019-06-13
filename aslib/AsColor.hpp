/*#######################################################################################
	Made by Kasugaccho
	Made by As Project
	https://github.com/Kasugaccho/AsLib
	wanotaitei@gmail.com

	This code is licensed under CC0.
#######################################################################################*/
#ifndef INCLUDED_AS_PROJECT_LIBRARY_COLOR
#define INCLUDED_AS_PROJECT_LIBRARY_COLOR


namespace AsLib
{
	constexpr std::int32_t BIT_SHIFT_DIV_2{ 1 };
	constexpr std::int32_t BIT_SHIFT_DIV_256{ 8 };

	//色
	struct ColorRGB;
	struct Color;

	constexpr std::uint8_t COLOR_MAX{ 255 };

	//３色
	struct ColorRGB
	{
		ColorRGB& operator++() noexcept;
		ColorRGB& operator=(const Color& add_color) noexcept;
		ColorRGB& operator+=(const ColorRGB& add_color) noexcept;
		ColorRGB& operator+=(const Color& add_color) noexcept;
		ColorRGB& operator+(const ColorRGB& add_color) noexcept;
		ColorRGB& operator+(const Color& add_color) noexcept;
		ColorRGB& operator*=(const ColorRGB& add_color) noexcept;
		ColorRGB& operator*=(const Color& add_color) noexcept;
		ColorRGB& operator*(const ColorRGB& add_color) noexcept;
		ColorRGB& operator*(const Color& add_color) noexcept;
		operator Color() const;

		std::uint8_t r{ COLOR_MAX };
		std::uint8_t g{ COLOR_MAX };
		std::uint8_t b{ COLOR_MAX };

		ColorRGB() = default;
		constexpr explicit ColorRGB(const std::uint8_t r_, const std::uint8_t g_, const std::uint8_t b_, const std::uint8_t a_) :r(r_), g(g_), b(b_) { };
		constexpr explicit ColorRGB(const std::uint8_t r_, const std::uint8_t g_, const std::uint8_t b_) :r(r_), g(g_), b(b_) {};

		//他のライブラリ対応
		const unsigned int uint() noexcept { return ((unsigned int)(this->r << 0x10) + (unsigned int)(this->g << 0x8) + (unsigned int)(this->b & 0xff)); }
		constexpr explicit ColorRGB(const unsigned int col_) :r(std::uint8_t((col_ & 0xffffff) >> 0x10)), g(std::uint8_t((col_ & 0xffff) >> 0x8)), b(std::uint8_t(col_ & 0xff)) {}
#if defined(ASLIB_INCLUDE_DL)
		operator unsigned int() const noexcept { return DxLib::GetColor(int(this->r), int(this->g), int(this->b)); };
#elif defined(ASLIB_INCLUDE_S3)
		operator s3d::Color() const
		{
			const s3d::Color col(std::uint32_t(this->r), std::uint32_t(this->g), std::uint32_t(this->b));
			return col;
		};
#endif
	};

	//３色＋透過
	struct Color
	{
		Color& operator++() noexcept;
		Color& operator=(const ColorRGB& add_color) noexcept;
		Color& operator()(const std::uint8_t add_alpha) noexcept;
		Color& operator+=(const ColorRGB& add_color) noexcept;
		Color& operator+=(const Color& add_color) noexcept;
		Color& operator+(const ColorRGB& add_color) noexcept;
		Color& operator+(const Color& add_color) noexcept;
		Color& operator*=(const ColorRGB& add_color) noexcept;
		Color& operator*=(const Color& add_color) noexcept;
		Color& operator*(const ColorRGB& add_color) noexcept;
		Color& operator*(const Color& add_color) noexcept;
		operator ColorRGB() const;

		std::uint8_t r{ COLOR_MAX };
		std::uint8_t g{ COLOR_MAX };
		std::uint8_t b{ COLOR_MAX };
		std::uint8_t a{ COLOR_MAX };

		Color() = default;
		//no noexcept
		constexpr Color(const std::uint8_t r_, const std::uint8_t g_, const std::uint8_t b_, const std::uint8_t a_) :r(r_), g(g_), b(b_), a(a_) {};
		constexpr Color(const std::uint8_t r_, const std::uint8_t g_, const std::uint8_t b_) :r(r_), g(g_), b(b_), a(COLOR_MAX) {};

		//他のライブラリ対応
		const unsigned int uint() noexcept { return ((unsigned int)(this->r << 0x10) + (unsigned int)(this->g << 0x8) + (unsigned int)(this->b & 0xff)); }
		constexpr Color(const unsigned int col_) :r(std::uint8_t((col_ & 0xffffff) >> 0x10)), g(std::uint8_t((col_ & 0xffff) >> 0x8)), b(std::uint8_t(col_ & 0xff)) {}
#if defined(ASLIB_INCLUDE_DL)
		operator unsigned int() const noexcept { return DxLib::GetColor(int(this->r), int(this->g), int(this->b)); };
#elif defined(ASLIB_INCLUDE_S3)
		operator s3d::Color() const noexcept { return s3d::Color(std::uint32_t(this->r), std::uint32_t(this->g), std::uint32_t(this->b), std::uint32_t(this->a)); };
		operator s3d::ColorF() const noexcept { return s3d::ColorF(s3d::Color(std::uint32_t(this->r), std::uint32_t(this->g), std::uint32_t(this->b), std::uint32_t(this->a))); };
#endif
	};

	inline Color::operator ColorRGB() const
	{
		ColorRGB col;
		col.r = this->r;
		col.g = this->g;
		col.b = this->b;
		return col;
	}

	inline ColorRGB::operator Color() const
	{
		Color col;
		col.r = this->r;
		col.g = this->g;
		col.b = this->b;
		return col;
	}

	void asColorMul(std::uint8_t& color1, const std::uint8_t color2) noexcept
	{
		color1 = std::uint8_t((std::int32_t(color1) * std::int32_t(color2)) >> BIT_SHIFT_DIV_256);
	}

	void asColorMul(ColorRGB& color1, const ColorRGB& color2) noexcept
	{
		asColorMul(color1.r, color2.r);
		asColorMul(color1.g, color2.g);
		asColorMul(color1.b, color2.b);
	}

	void asColorMul(ColorRGB& color1, const Color& color2) noexcept
	{
		asColorMul(color1.r, color2.r);
		asColorMul(color1.g, color2.g);
		asColorMul(color1.b, color2.b);
	}

	void asColorMul(Color& color1, const ColorRGB& color2) noexcept
	{
		asColorMul(color1.r, color2.r);
		asColorMul(color1.g, color2.g);
		asColorMul(color1.b, color2.b);
	}

	void asColorMul(Color& color1, const Color& color2) noexcept
	{
		asColorMul(color1.r, color2.r);
		asColorMul(color1.g, color2.g);
		asColorMul(color1.b, color2.b);
		asColorMul(color1.a, color2.a);
	}

	void asColorAdd(std::uint8_t& color1, const std::uint8_t color2) noexcept
	{
		std::int32_t color32 = std::int32_t(color1) + std::int32_t(color2);
		if (color32 >= COLOR_MAX) color1 = std::uint8_t(COLOR_MAX);
		else color1 = std::uint8_t(color32);
	}

	void asColorAdd(ColorRGB& color1, const ColorRGB& color2) noexcept
	{
		asColorAdd(color1.r, color2.r);
		asColorAdd(color1.g, color2.g);
		asColorAdd(color1.b, color2.b);
	}

	void asColorAdd(ColorRGB& color1, const Color& color2) noexcept
	{
		asColorAdd(color1.r, color2.r);
		asColorAdd(color1.g, color2.g);
		asColorAdd(color1.b, color2.b);
	}

	void asColorAdd(Color& color1, const ColorRGB& color2) noexcept
	{
		asColorAdd(color1.r, color2.r);
		asColorAdd(color1.g, color2.g);
		asColorAdd(color1.b, color2.b);
	}

	void asColorAdd(Color& color1, const Color& color2) noexcept
	{
		asColorAdd(color1.r, color2.r);
		asColorAdd(color1.g, color2.g);
		asColorAdd(color1.b, color2.b);
		asColorAdd(color1.a, color2.a);
	}

	inline ColorRGB& ColorRGB::operator++() noexcept
	{
		if (this->r != COLOR_MAX)++this->r;
		if (this->g != COLOR_MAX)++this->g;
		if (this->b != COLOR_MAX)++this->b;
		return *this;
	}

	inline Color& Color::operator++() noexcept
	{
		if (this->r != COLOR_MAX)++this->r;
		if (this->g != COLOR_MAX)++this->g;
		if (this->b != COLOR_MAX)++this->b;
		if (this->a != COLOR_MAX)++this->a;
		return *this;
	}

	inline ColorRGB& ColorRGB::operator*(const ColorRGB& add_color) noexcept
	{
		asColorMul(*this, add_color);
		return *this;
	}

	inline ColorRGB& ColorRGB::operator*(const Color& add_color) noexcept
	{
		asColorMul(*this, add_color);
		return *this;
	}

	inline Color& Color::operator*(const ColorRGB& add_color) noexcept
	{
		asColorMul(*this, add_color);
		return *this;
	}

	inline Color& Color::operator*(const Color& add_color) noexcept
	{
		asColorMul(*this, add_color);
		return *this;
	}

	inline Color& Color::operator*=(const ColorRGB& add_color) noexcept
	{
		asColorMul(*this, add_color);
		return *this;
	}

	inline Color& Color::operator*=(const Color& add_color) noexcept
	{
		asColorMul(*this, add_color);
		return *this;
	}

	inline ColorRGB& ColorRGB::operator*=(const ColorRGB& add_color) noexcept
	{
		asColorMul(*this, add_color);
		return *this;
	}

	inline ColorRGB& ColorRGB::operator*=(const Color& add_color) noexcept
	{
		asColorMul(*this, add_color);
		return *this;
	}


	inline ColorRGB& ColorRGB::operator+(const ColorRGB& add_color) noexcept
	{
		asColorAdd(*this, add_color);
		return *this;
	}

	inline ColorRGB& ColorRGB::operator+(const Color& add_color) noexcept
	{
		asColorAdd(*this, add_color);
		return *this;
	}

	inline Color& Color::operator+(const ColorRGB& add_color) noexcept
	{
		asColorAdd(*this, add_color);
		return *this;
	}

	inline Color& Color::operator+(const Color& add_color) noexcept
	{
		asColorAdd(*this, add_color);
		return *this;
	}

	inline Color& Color::operator+=(const ColorRGB& add_color) noexcept
	{
		asColorAdd(*this, add_color);
		return *this;
	}

	inline Color& Color::operator+=(const Color& add_color) noexcept
	{
		asColorAdd(*this, add_color);
		return *this;
	}

	inline ColorRGB& ColorRGB::operator+=(const ColorRGB& add_color) noexcept
	{
		asColorAdd(*this, add_color);
		return *this;
	}

	inline ColorRGB& ColorRGB::operator+=(const Color& add_color) noexcept
	{
		asColorAdd(*this, add_color);
		return *this;
	}

	inline Color& Color::operator()(const std::uint8_t add_alpha = COLOR_MAX) noexcept
	{
		this->a = add_alpha;
		return *this;
	}

	inline ColorRGB& ColorRGB::operator=(const Color& add_color) noexcept
	{
		this->r = add_color.r;
		this->g = add_color.g;
		this->b = add_color.b;
		return *this;
	}

	inline Color& Color::operator=(const ColorRGB& add_color) noexcept
	{
		this->r = add_color.r;
		this->g = add_color.g;
		this->b = add_color.b;
		this->a = 255;
		return *this;
	}

	inline void asRand(Color& c_) noexcept { c_.r = asRand8(); c_.g = asRand8(); c_.b = asRand8(); c_.a = 255; }
	inline void asRandA(Color& c_) noexcept { c_.r = asRand8(); c_.g = asRand8(); c_.b = asRand8(); c_.a = asRand8(); }
	inline void asRand(Color* const array_, const std::size_t s_) noexcept { for (std::size_t i{}; i < s_; ++i) asRand(array_[i]); }
	inline void asRandA(Color* const array_, const std::size_t s_) noexcept { for (std::size_t i{}; i < s_; ++i) asRandA(array_[i]); }
	inline void asRand(Color& c_, const std::uint8_t m_) noexcept { c_.r = asRand8(m_); c_.g = asRand8(m_); c_.b = asRand8(m_); c_.a = 255; }
	inline void asRandA(Color& c_, const std::uint8_t m_) noexcept { c_.r = asRand8(m_); c_.g = asRand8(m_); c_.b = asRand8(m_); c_.a = asRand8(m_); }
	inline void asRand(Color* const array_, const std::size_t s_, const std::uint8_t m_) noexcept { for (std::size_t i{}; i < s_; ++i) asRand(array_[i], m_); }
	inline void asRandA(Color* const array_, const std::size_t s_, const std::uint8_t m_) noexcept { for (std::size_t i{}; i < s_; ++i) asRandA(array_[i], m_); }
}

#endif //Included AsProject Library