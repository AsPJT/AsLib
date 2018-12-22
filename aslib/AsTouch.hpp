//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsProject Library
//
//                    Created by Gaccho (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------
#ifndef INCLUDED_AS_PROJECT_LIBRARY_TOUCH
#define INCLUDED_AS_PROJECT_LIBRARY_TOUCH


namespace AsLib
{

	//タッチされている数を返す
	inline size_t asTouchNum() noexcept
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		return size_t(DxLib::GetTouchInputNum());
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		return 0;
#elif defined(ASLIB_INCLUDE_OF)
		return 0;
#elif defined(ASLIB_INCLUDE_C2)
return 0;
#elif defined(ASLIB_INCLUDE_SF)
return 0;
#elif defined(ASLIB_INCLUDE_TP)
		return 0;
#else //Console
		return 0;
#endif
	}

	//タッチされている
	int32_t asTouch(const size_t touch_id, Pos2& add_pos) noexcept
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		int touch_x{}, touch_y{};
		if (DxLib::GetTouchInput(int(touch_id), &touch_x, &touch_y, nullptr, nullptr) == -1) return -1;
		add_pos(int32_t(touch_x), int32_t(touch_y));
		return 0;
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		return 0;
#elif defined(ASLIB_INCLUDE_OF)
		return 0;
#elif defined(ASLIB_INCLUDE_C2)
return 0;
#elif defined(ASLIB_INCLUDE_SF)
return 0;
#elif defined(ASLIB_INCLUDE_TP)
		return 0;
#else //Console
		return 0;
#endif
	}

	Pos2 asTouch(const size_t touch_id) noexcept
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		int touch_x{}, touch_y{};
		DxLib::GetTouchInput(int(touch_id), &touch_x, &touch_y, nullptr, nullptr);
		return Pos2(int32_t(touch_x), int32_t(touch_y));
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		return 0;
#elif defined(ASLIB_INCLUDE_OF)
		return 0;
#elif defined(ASLIB_INCLUDE_C2)
return 0;
#elif defined(ASLIB_INCLUDE_SF)
return 0;
#elif defined(ASLIB_INCLUDE_TP)
		return 0;
#else //Console
		return 0;
#endif
	}

	int32_t asTouchPinch(const bool is_update = false) noexcept {
		static int32_t total_p{};
		if (!is_update) return total_p;

		static bool is_pinch{ false };
		if (asTouchNum() != 2) {
			is_pinch = false;
			return total_p = 0;
		}
		static int32_t before_p{};

		const Pos2 after_p0{ asTouch(0) };
		const Pos2 after_p1{ asTouch(1) };
		const int32_t after_p{ int32_t(hypot(abs(after_p0.x - after_p1.x), abs(after_p0.y - after_p1.y))) };

		if (!is_pinch) {
			is_pinch = true;
			before_p = after_p;
			return 0;
		}
		is_pinch = true;
		total_p = after_p - before_p;
		before_p = after_p;
		return total_p;
	}
	int32_t asTouchPinch(const Pos4& area_) noexcept {
		if (asTouchNum() != 2) return 0;
		if (!isArea(area_, asTouch(0)) || !isArea(area_, asTouch(1))) return 0;
		return asTouchPinch();
	}

	inline void asTouchPinch(int32_t& add_) noexcept {
		add_ += asTouchPinch();
		if (add_ < 0) add_ = 0;
	}

	inline bool asIsTouchPinch() noexcept {
		return (asTouchPinch() == 0) ? false : true;
	}
	//
	inline void asTouchPinch(PosA4F& add_, const float f_ = 5.0, const int32_t view_max_ = 0, Pos4 area_ = aslib_default_area) noexcept {
		if (!isArea(area_)) area_ = asWindowSize4();
		float pinch{ asTouchPinch(area_) / f_ };
		add_.w -= pinch;
		add_.h -= pinch;
		if (add_.w < 1.0f) add_.w = 1.0f;
		if (add_.h < 1.0f) add_.h = 1.0f;
		if (view_max_ == 0) return;
		if (int32_t(add_.w) >= view_max_) add_.w = float(view_max_);
		if (int32_t(add_.h) >= view_max_) add_.h = float(view_max_);
	}

	Pos2 asTouchSlide(const bool is_update = false) noexcept {
		static Pos2 total_p{};
		if (!is_update) return total_p;

		static bool is_pinch{ false };
		if (asTouchNum() != 1) {
			is_pinch = false;
			return total_p(0, 0);
		}
		static Pos2 before_p{};
		const Pos2 after_p{ asTouch(0) };

		if (!is_pinch) {
			is_pinch = true;
			before_p = after_p;
			return 0;
		}
		is_pinch = true;
		total_p(before_p.x-after_p.x, before_p.y-after_p.y);
		before_p = after_p;
		return total_p;
	}

	Pos2 asTouchSlide(const Pos4& area_) noexcept {
		if (asTouchNum() != 1) return 0;
		if (!isArea(area_, asTouch(0))) return 0;
		return asTouchSlide();
	}

	Pos2 updateTouchPos(const bool is_push = false,const Pos2& p_ = { -1,-1 }) noexcept {
		static Pos2 aslib_end_num_pos{};
		return (is_push) ? aslib_end_num_pos = p_ : aslib_end_num_pos;
	}

	inline Pos2 asTouchEndPos() noexcept { return updateTouchPos(false); }

	bool asTouchUp(const bool on_ = false, const bool update_ = false) noexcept {
		static bool is_touch{ false };
		if (on_) is_touch = update_;
		return is_touch;
	}
	bool asTouchDown(const bool on_ = false, const bool update_ = false) noexcept {
		static bool is_touch{ false };
		if (on_) is_touch = update_;
		return is_touch;
	}

	Pos2 asTouchUpPos(const bool on_ = false, const Pos2 update_ = false) noexcept {
		static Pos2 is_touch(0, 0);
		if (on_) is_touch = update_;
		return is_touch;
	}

	//毎フレーム更新
	void updateTouch() noexcept {
		static size_t aslib_num{};

		const size_t num{ asTouchNum() };
		if (aslib_num != num && num != 0) updateTouchPos(true, asTouch(num - 1));

		//ピンチ更新
		asTouchPinch(true);
		//スライド更新
		asTouchSlide(true);
		
		static size_t before_num{};
		static Pos2 before_up_pos(0, 0);

		asTouchUpPos(true, before_up_pos);
		asTouchUp(true, before_num > num);
		asTouchDown(true, before_num < num);

		//今回のを入れる
		before_num = num;
		if (before_num != 0) before_up_pos = asTouch(before_num - 1);
	}

	inline bool asTouch() noexcept { return (asTouchNum() == 0) ? false : true; }

	bool asTouch(const Pos4& p_) noexcept {
		const size_t num{ asTouchNum() };
		Pos2 touch_p;
		for (size_t i{}; i < num; ++i) {
			touch_p = asTouch(i);
			if (touch_p.x > p_.x1&&touch_p.y > p_.y1&&touch_p.x < p_.x2&&touch_p.y < p_.y2) return true;
		}
		return false;
	}

}

#endif //Included AsProject Library