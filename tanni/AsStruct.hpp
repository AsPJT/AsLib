//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asライブラリ
//
//                    制作者: がっちょ (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------

namespace AsLib
{
	constexpr bool IS_HEIGHT = true;
	constexpr bool IS_WIDTH = false;

	constexpr int32_t BIT_SHIFT_DIV_2 = 1;
	constexpr int32_t BIT_SHIFT_DIV_256 = 8;

	struct Pos2;
	struct Pos2R;
	struct Pos4;
	struct Pos4R;
	struct ColorRGB;
	struct ColorRGBA;

	//大きさ(2D)
	struct Pos2
	{
		Pos2& operator=(const Pos4& add_pos);
		Pos2& operator()(const int32_t pos_size = 0);
		Pos2& operator()(const int32_t pos_x, const int32_t pos_y);
		int32_t x = 0;
		int32_t y = 0;
	};

	//画面比での大きさ(2D)
	struct Pos2R
	{
		Pos2R& operator=(const Pos4R& add_pos);
		Pos2R& operator()(const float pos_size = 0.0f);
		Pos2R& operator()(const float pos_x, const float pos_y);
		float x = 1.0f;
		float y = 1.0f;
	};

	//四角形の大きさ
	struct Pos4
	{
		Pos4& operator=(const Pos2& add_pos);
		int32_t x1 = 0;
		int32_t y1 = 0;
		int32_t x2 = 0;
		int32_t y2 = 0;
	};

	//画面比での四角形の大きさ
	struct Pos4R
	{
		Pos4R& operator=(const Pos2R& add_pos);
		float x1 = 0.0f;
		float y1 = 0.0f;
		float x2 = 1.0f;
		float y2 = 1.0f;
	};

	inline Pos2& Pos2::operator()(const int32_t pos_x, const int32_t pos_y)
	{
		this->x = pos_x;
		this->y = pos_y;
		return *this;
	}

	inline Pos2& Pos2::operator()(const int32_t pos_size)
	{
		this->x = pos_size;
		this->y = pos_size;
		return *this;
	}

	inline Pos2R& Pos2R::operator()(const float pos_x, const float pos_y)
	{
		this->x = pos_x;
		this->y = pos_y;
		return *this;
	}

	inline Pos2R& Pos2R::operator()(const float pos_size)
	{
		this->x = pos_size;
		this->y = pos_size;
		return *this;
	}

	inline Pos2& Pos2::operator=(const Pos4& add_pos)
	{
		this->x = add_pos.x2;
		this->y = add_pos.y2;
		return *this;
	}

	inline Pos4& Pos4::operator=(const Pos2& add_pos)
	{
		this->x1 = 0;
		this->y1 = 0;
		this->x2 = add_pos.x;
		this->y2 = add_pos.y;
		return *this;
	}

	inline Pos2R& Pos2R::operator=(const Pos4R& add_pos)
	{
		this->x = add_pos.x2;
		this->y = add_pos.y2;
		return *this;
	}

	inline Pos4R& Pos4R::operator=(const Pos2R& add_pos)
	{
		this->x1 = 0.0f;
		this->y1 = 0.0f;
		this->x2 = add_pos.x;
		this->y2 = add_pos.y;
		return *this;
	}

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

		uint8_t r = COLOR_MAX;
		uint8_t g = COLOR_MAX;
		uint8_t b = COLOR_MAX;
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

	//デフォルト背景色
	constexpr uint8_t BG_COLOR_R = 230;
	constexpr uint8_t BG_COLOR_G = 230;
	constexpr uint8_t BG_COLOR_B = 230;
	constexpr ColorRGB BG_COLOR = { BG_COLOR_R ,BG_COLOR_G ,BG_COLOR_B };

	//デフォルトウィンドウサイズ
	constexpr int32_t WINDOW_SIZE_X = 360;
	constexpr int32_t WINDOW_SIZE_Y = 640;
	constexpr Pos2 WINDOW_SIZE = { WINDOW_SIZE_X ,WINDOW_SIZE_Y };


	//色
	constexpr ColorRGB white = { 250 ,250 ,250 };
	constexpr ColorRGBA whiteA = { 250 ,250 ,250 ,255 };

	//原点位置
	constexpr Pos2 pos2_0 = { 0,0 };
	constexpr Pos4 pos4_0 = { 0,0,0,0 };
	constexpr Pos2R pos2R_0 = { 0.0f,0.0f };
	constexpr Pos4R pos4R_0 = { 0.0f,0.0f,0.0f,0.0f };
	
	constexpr Pos2 pos2_100 = { 100,100 };
	constexpr Pos4 pos4_100 = { 0,0,100,100 };


	//全選択
	constexpr Pos2R pos2R_all = { 1.0f,1.0f };
	constexpr Pos4R pos4R_all = { 0.0f,0.0f,1.0f,1.0f };

	//無色
	constexpr ColorRGBA color_0 = { 0,0,0,0 };
	constexpr ColorRGB colorRGB_0 = { 0,0,0 };
	constexpr ColorRGBA colorRGBA_0 = { 0,0,0,0 };

	Pos4 toPos4(const Pos4R& add_pos, const Pos2& window_size)
	{
		Pos4 pos4;
		pos4.x1 = int32_t(add_pos.x1 * float(window_size.x));
		pos4.y1 = int32_t(add_pos.y1 * float(window_size.y));
		pos4.x2 = int32_t(add_pos.x2 * float(window_size.x));
		pos4.y2 = int32_t(add_pos.y2 * float(window_size.y));
		return pos4;
	}

	Pos4 toPos4X(const Pos4R& add_pos, const Pos2& window_size,const Pos2& add_pixel)
	{
		const float pixel_size = float(add_pixel.x) / float(add_pixel.y);
		Pos4 pos4;
		pos4.x1 = int32_t(add_pos.x1 * float(window_size.x));
		pos4.y1 = int32_t(add_pos.y1 * float(window_size.y));
		pos4.x2 = int32_t(add_pos.x2 * float(window_size.x));
		pos4.y2 = int32_t(add_pos.x2 * pixel_size * float(window_size.y));
		return pos4;
	}

	Pos4 toPos4Y(const Pos4R& add_pos, const Pos2& window_size, const Pos2& add_pixel)
	{
		const float pixel_size = float(add_pixel.y) / float(add_pixel.x);
		Pos4 pos4;
		pos4.x1 = int32_t(add_pos.x1 * float(window_size.x));
		pos4.y1 = int32_t(add_pos.y1 * float(window_size.y));
		pos4.x2 = int32_t(add_pos.y2 * pixel_size * float(window_size.x));
		pos4.y2 = int32_t(add_pos.y2 * float(window_size.y));
		return pos4;
	}


#if defined(__DXLIB) //DxLib

	struct AS_Texture
	{
		int id = TEX_INIT;
		uint8_t alpha = 255;

		ColorRGBA color = color_0;
		Pos4 pos4 = pos4_0;
		Pos2 pixel_size = pos2_0;
	};

#elif defined(SIV3D_INCLUDED) //Siv3D

#else //Console

#endif

}