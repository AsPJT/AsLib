//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsProject Library
//
//                    Created by Gaccho (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------
#ifndef INCLUDED_AS_PROJECT_LIBRARY_SCREEN
#define INCLUDED_AS_PROJECT_LIBRARY_SCREEN


namespace AsLib
{



	struct AsScreen {
#if defined(ASLIB_INCLUDE_DL) //DxLib
	private:
		std::size_t s_x{};
		std::size_t s_y{};
		OriginatorScreen screen;
		bool is_alpha{ false };
		bool is_error{ true };

		Pos4 p4;
		bool is_p4{ false };

	public:
		const Pos4 pos4()const noexcept { return p4; }
		//void area() { DxLib::SetDrawArea(p4.x1, p4.y1, p4.x2, p4.y2); }
		//void areaClear() { DxLib::SetDrawArea(0, 0, asWindowSize().x, asWindowSize().y); }
		const bool isArea()const noexcept { return is_p4; }
		AsScreen(const Pos4& p_) :s_x(p_.x2 - p_.x1), s_y(p_.y2 - p_.y1), p4(p_), is_p4(true) {};
		AsScreen(const Pos2& p_, const bool is_alpha = true) :s_x(p_.x),s_y(p_.y),screen(DxLib::MakeScreen(int(p_.x), int(p_.y), (is_alpha == true) ? 1 : 0)), is_alpha(is_alpha), is_error(checkScreen(screen)) {}
		~AsScreen() { DxLib::DeleteGraph(screen); }

		const std::size_t x() const noexcept {
			return s_x;
		}
		const std::size_t y() const noexcept {
			return s_y;
		}

		AsScreen& update() noexcept {
			DxLib::SetDrawScreen(this->screen);
			DxLib::ClearDrawScreen();
			DxLib::SetDrawScreen(DX_SCREEN_BACK);
			return *this;
		}
		AsScreen& set() noexcept {
			DxLib::ClearDrawScreen();
			DxLib::SetDrawScreen(this->screen);
			return *this;
		}
		AsScreen& release() noexcept {
			DxLib::SetDrawScreen(DX_SCREEN_BACK);
			return *this;
		}

		AsScreen& draw(const Pos4& p_) noexcept {
			DxLib::DrawExtendGraph(p_.x1, p_.y1, p_.x2, p_.y2, this->screen, TRUE);
			return *this;
		}

		//AsScreen& clear() { DxLib::SetDrawScreen(this->screen); DxLib::ClearDrawScreen(); DxLib::SetDrawScreen(DX_SCREEN_BACK); return *this; }

		bool isError() const noexcept { return this->is_error; }
		bool isAlpha() const noexcept { return this->is_alpha; }
		OriginatorScreen copyScreen() const noexcept { return this->screen; }

#elif defined(ASLIB_INCLUDE_S3) //Siv3D

#elif defined(ASLIB_INCLUDE_OF)

#elif defined(ASLIB_INCLUDE_C2)

#elif defined(ASLIB_INCLUDE_SF)
return 0;
#elif defined(ASLIB_INCLUDE_TP)

#else //Console

#endif

	};



}

#endif //Included AsProject Library