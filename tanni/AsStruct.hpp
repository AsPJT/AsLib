//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asライブラリ
//
//                    制作者: がっちょ (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------

constexpr bool IS_HEIGHT = true;
constexpr bool IS_WIDTH = false;

namespace AsLib
{
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
		int32_t x = 100;
		int32_t y = 100;
	};

	//画面比での大きさ(2D)
	struct Pos2R
	{
		float x = 1.0f;
		float y = 1.0f;
	};

	//四角形の大きさ
	struct Pos4
	{
		Pos4& operator=(const Pos2& add_pos);
		int32_t x1 = 0;
		int32_t y1 = 0;
		int32_t x2 = 100;
		int32_t y2 = 100;
	};

	//画面比での四角形の大きさ
	struct Pos4R
	{
		float x1 = 0.0f;
		float y1 = 0.0f;
		float x2 = 1.0f;
		float y2 = 1.0f;
	};

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


	//３色
	struct ColorRGB
	{
		ColorRGB& operator=(const ColorRGBA& add_color);
		uint8_t r = 255;
		uint8_t g = 255;
		uint8_t b = 255;
	};

	//３色＋透過
	struct ColorRGBA
	{
		ColorRGBA& operator=(const ColorRGB& add_color);
		uint8_t r = 255;
		uint8_t g = 255;
		uint8_t b = 255;
		uint8_t a = 255;
	};

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
		float pixel_size = float(add_pixel.x) / float(add_pixel.y);
		Pos4 pos4;
		pos4.x1 = int32_t(add_pos.x1 * float(window_size.x));
		pos4.y1 = int32_t(add_pos.y1 * float(window_size.y));
		pos4.x2 = int32_t(add_pos.x2 * float(window_size.x));
		pos4.y2 = int32_t(add_pos.x2 * pixel_size * float(window_size.y));
		return pos4;
	}

	Pos4 toPos4Y(const Pos4R& add_pos, const Pos2& window_size, const Pos2& add_pixel)
	{
		float pixel_size = float(add_pixel.y) / float(add_pixel.x);
		Pos4 pos4;
		pos4.x1 = int32_t(add_pos.x1 * float(window_size.x));
		pos4.y1 = int32_t(add_pos.y1 * float(window_size.y));
		pos4.x2 = int32_t(add_pos.y2 * pixel_size * float(window_size.x));
		pos4.y2 = int32_t(add_pos.y2 * float(window_size.y));
		return pos4;
	}
}