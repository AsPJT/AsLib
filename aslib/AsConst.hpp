//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsProject Library
//
//                    Created by Gaccho (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------
#ifndef INCLUDED_AS_PROJECT_LIBRARY_CONST
#define INCLUDED_AS_PROJECT_LIBRARY_CONST


namespace AsLib
{
	constexpr Pos4 aslib_default_area(-1, -1, -1, -1);
	bool isArea(const Pos4& area_) noexcept {
		return (area_.x1 < 0 || area_.y1 < 0 || area_.x2 < 0 || area_.y2 < 0) ? false : true;
	}
	bool isArea(const Pos4& area_,const Pos2& p_) noexcept {
		return (area_.x1 > p_.x || area_.y1 > p_.y || area_.x2 < p_.x || area_.y2 < p_.y) ? false : true;
	}

	//デフォルト背景色
	constexpr uint8_t aslib_bg_color_r{ 230 };
	constexpr uint8_t aslib_bg_color_g{ 230 };
	constexpr uint8_t aslib_bg_color_b{ 230 };
	constexpr ColorRGB aslib_bg_color(aslib_bg_color_r, aslib_bg_color_g, aslib_bg_color_b);
	constexpr ColorRGB defaultColorBG() noexcept { return aslib_bg_color; }

	//デフォルトウィンドウサイズ
	constexpr int32_t aslib_default_window_size_x{ 360 };
	constexpr int32_t aslib_default_window_size_y{ 640 };
	constexpr Pos2 aslib_default_window_size(aslib_default_window_size_x, aslib_default_window_size_y);
	constexpr Pos2 defaultWindowSize() noexcept { return aslib_default_window_size; }


	//色
	constexpr ColorRGB aslib_color_white(250, 250, 250);
	constexpr Color aslib_color_white_a(250, 250, 250, 255);

	constexpr ColorRGB aslib_color_black(0, 0, 0);
	constexpr Color aslib_color_black_a(0, 0, 0, 255);

	//フルスクリーン
	constexpr Pos2 aslib_full_screen_pos(-1, -1);

	//原点位置
	constexpr Pos2 pos2_0(0, 0);
	constexpr Pos4 pos4_0(0, 0, 0, 0);
	constexpr Pos2F pos2R_0(0.0f, 0.0f);
	constexpr Pos4F pos4R_0(0.0f, 0.0f, 0.0f, 0.0f);

	constexpr Pos2 pos2_100(100, 100);
	constexpr Pos4 pos4_100(0, 0, 100, 100);
	constexpr Pos8 pos8_100(0, 0, 100, 0, 0, 100, 100, 100);


	//全選択
	constexpr Pos2F pos2R_all(1.0f, 1.0f);
	constexpr Pos4F pos4R_all(0.0f, 0.0f, 1.0f, 1.0f);

	//無色
	constexpr Color color_0(0, 0, 0, 0);
	constexpr ColorRGB colorRGB_0(0, 0, 0);
	constexpr Color colorRGBA_0(0, 0, 0, 0);

	Pos4 toPos4(const Pos4F& add_pos, const Pos2& window_size) noexcept
	{
		return Pos4(int32_t(add_pos.x1 * float(window_size.x)), int32_t(add_pos.y1 * float(window_size.y)), int32_t(add_pos.x2 * float(window_size.x)), int32_t(add_pos.y2 * float(window_size.y)));
	}

	Pos4 toPos4X(const Pos4F& add_pos, const Pos2& window_size, const Pos2& add_pixel) noexcept
	{
		const float pixel_size{ float(add_pixel.x) / float(add_pixel.y) };
		return Pos4(int32_t(add_pos.x1 * float(window_size.x)), int32_t(add_pos.y1 * float(window_size.y)), int32_t(add_pos.x2 * float(window_size.x)), int32_t(add_pos.x2 * pixel_size * float(window_size.y)));
	}

	Pos4 toPos4Y(const Pos4F& add_pos, const Pos2& window_size, const Pos2& add_pixel) noexcept
	{
		const float pixel_size{ float(add_pixel.y) / float(add_pixel.x) };
		return 		Pos4(int32_t(add_pos.x1 * float(window_size.x)), int32_t(add_pos.y1 * float(window_size.y)), int32_t(add_pos.y2 * pixel_size * float(window_size.x)), int32_t(add_pos.y2 * float(window_size.y)));
	}

}

#endif //Included AsProject Library