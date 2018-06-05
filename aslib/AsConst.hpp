//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asライブラリ
//
//                    制作者: がっちょ (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{

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

	constexpr ColorRGB black_RGB = { 0 ,0 ,0 };
	constexpr ColorRGBA black_RGBA = { 0 ,0 ,0,255 };

	//フルスクリーン
	constexpr Pos2 FULL_SCREEN_POS = { -1,-1 };

	//原点位置
	constexpr Pos2 pos2_0 = { 0,0 };
	constexpr Pos4 pos4_0 = { 0,0,0,0 };
	constexpr Pos2R pos2R_0 = { 0.0f,0.0f };
	constexpr Pos4R pos4R_0 = { 0.0f,0.0f,0.0f,0.0f };

	constexpr Pos2 pos2_100 = { 100,100 };
	constexpr Pos4 pos4_100 = { 0,0,100,100 };
	constexpr Pos8 pos8_100 = { 0,0,100,0,0,100,100,100 };


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

	Pos4 toPos4X(const Pos4R& add_pos, const Pos2& window_size, const Pos2& add_pixel)
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

}
