//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asライブラリ
//
//                    制作者: がっちょ (wanotaitei@gmail.com)
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

	const bool updateTouch_(const bool is_down_, const bool is_up_ = false) {
		static size_t aslib_touch_num = 0;
		const size_t num = asTouchNum();

		bool is_true = false;

		if (is_down_&&aslib_touch_num < num) is_true = true;
		else if (is_up_&&aslib_touch_num > num) is_true = true;

		aslib_touch_num = num;
		return is_true;
	}

	inline const bool asIsTouch() { return (asTouchNum() == 0) ? false : true; }
	inline const bool asIsTouchUp() { return updateTouch_(false, true); }
	inline const bool asIsTouchDown() { return updateTouch_(true, false); }

	inline void updateTouch() {

	}

}
