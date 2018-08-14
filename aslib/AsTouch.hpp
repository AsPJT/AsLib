//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsProject Library
//
//                    Created by Gaccho (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{

	//タッチされている数を返す
	inline const size_t asTouchNum()
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		return size_t(DxLib::GetTouchInputNum());
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		return 0;
#elif defined(ASLIB_INCLUDE_OF)
		return 0;
#elif defined(ASLIB_INCLUDE_TP)
		return 0;
#else //Console
		return 0;
#endif
	}

	//タッチされている
	const int32_t asTouch(const size_t touch_id, Pos2& add_pos)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		int touch_x = 0, touch_y = 0;
		if (DxLib::GetTouchInput(int(touch_id), &touch_x, &touch_y, nullptr, nullptr) == -1) return -1;
		add_pos(int32_t(touch_x), int32_t(touch_y));
		return 0;
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		return 0;
#elif defined(ASLIB_INCLUDE_OF)
		return 0;
#elif defined(ASLIB_INCLUDE_TP)
		return 0;
#else //Console
		return 0;
#endif
	}

	const Pos2 asTouch(const size_t touch_id)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		int touch_x = 0, touch_y = 0;
		DxLib::GetTouchInput(int(touch_id), &touch_x, &touch_y, nullptr, nullptr);
		return Pos2(int32_t(touch_x), int32_t(touch_y));
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		return 0;
#elif defined(ASLIB_INCLUDE_OF)
		return 0;
#elif defined(ASLIB_INCLUDE_TP)
		return 0;
#else //Console
		return 0;
#endif
	}

	const int32_t asTouchPinch(const bool is_update = false) {
		static int32_t total_p = 0;
		if (!is_update) return total_p;

		static bool is_pinch = false;
		if (asTouchNum() != 2) {
			is_pinch = false;
			return total_p = 0;
		}
		static int32_t before_p{};

		const Pos2 after_p0 = asTouch(0);
		const Pos2 after_p1 = asTouch(1);
		const int32_t after_p = int32_t(hypot(abs(after_p0.x - after_p1.x), abs(after_p0.y - after_p1.y)));

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
	const int32_t asTouchPinch(const Pos4& area_) {
		if (asTouchNum() != 2) return 0;
		if (!isArea(area_, asTouch(0)) || !isArea(area_, asTouch(1))) return 0;
		return asTouchPinch();
	}

	inline void asTouchPinch(int32_t& add_) {
		add_ += asTouchPinch();
		if (add_ < 0) add_ = 0;
	}

	inline const bool asIsTouchPinch() {
		return (asTouchPinch() == 0) ? false : true;
	}
	//
	inline void asTouchPinch(PosA4F& add_, const float f_ = 5, const int32_t view_max_ = 0, Pos4 area_ = aslib_default_area) {
		if (!isArea(area_)) area_ = asWindowSize4();
		float pinch = asTouchPinch(area_) / f_;
		add_.w -= pinch;
		add_.h -= pinch;
		if (add_.w < 1.0f) add_.w = 1.0f;
		if (add_.h < 1.0f) add_.h = 1.0f;
		if (view_max_ == 0) return;
		if (int32_t(add_.w) >= view_max_) add_.w = float(view_max_);
		if (int32_t(add_.h) >= view_max_) add_.h = float(view_max_);
	}

	const Pos2 updateTouchPos(const bool is_push = false,const Pos2& p_ = { -1,-1 }) {
		static Pos2 aslib_end_num_pos{};
		return (is_push) ? aslib_end_num_pos = p_ : aslib_end_num_pos;
	}

	inline const Pos2 asTouchEndPos() { return updateTouchPos(false); }

	void updateTouch() {
		static size_t aslib_num = 0;

		const size_t num = asTouchNum();
		if (aslib_num != num && num != 0) updateTouchPos(true, asTouch(num - 1));

		asTouchPinch(true);
	}

	const bool updateTouch_(const bool is_down_, const bool is_up_ = false) {
		static size_t aslib_touch_num = 0;
		const size_t num = asTouchNum();

		bool is_true = false;

		if (is_down_&&aslib_touch_num < num) is_true = true;
		else if (is_up_&&aslib_touch_num > num) is_true = true;

		aslib_touch_num = num;
		return is_true;
	}

	inline const bool asTouch() { return (asTouchNum() == 0) ? false : true; }
	inline const bool asTouchUp() { return updateTouch_(false, true); }
	inline const bool asTouchDown() { return updateTouch_(true, false); }

	const Pos2 asTouchUpPos() { return updateTouch_(false, true); }



}
