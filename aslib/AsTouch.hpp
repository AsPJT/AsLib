//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asライブラリ
//
//                    制作者: がっちょ (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{

#if defined(ASLIB_INCLUDE_DL) //DxLib

	//タッチされている数を返す
	inline int32_t asTouchNum()
	{
		return int32_t(DxLib::GetTouchInputNum());
	}

	//タッチされている
	int32_t asTouch(const int32_t touch_id, Pos2& add_pos)
	{
		int touch_x = 0, touch_y = 0;
		if (DxLib::GetTouchInput(touch_id, &touch_x, &touch_y, nullptr, nullptr) == -1) return -1;
		add_pos(int32_t(touch_x), int32_t(touch_y));

		return 0;
	}

#elif defined(ASLIB_INCLUDE_S3) //Siv3D
	//todo(タッチが追加されていない)
	inline int32_t asTouchNum()
	{
		return 0;
	}

	//todo(タッチが追加されていない)
	int32_t asTouch(const int32_t touch_id, Pos2& add_pos)
	{
		touch_id; add_pos;
		return 0;
	}

#else //Console

#endif

}
