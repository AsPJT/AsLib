//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - As���C�u����
//
//                    �����: �������� (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{

	//�^�b�`����Ă��鐔��Ԃ�
	inline const int32_t asTouchNum()
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		return int32_t(DxLib::GetTouchInputNum());
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		return 0;
#elif defined(ASLIB_INCLUDE_OF)

#elif defined(ASLIB_INCLUDE_TP)
		return 0;
#else //Console
		return 0;
#endif
	}

	//�^�b�`����Ă���
	const int32_t asTouch(const int32_t touch_id, Pos2& add_pos)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		int touch_x = 0, touch_y = 0;
		if (DxLib::GetTouchInput(touch_id, &touch_x, &touch_y, nullptr, nullptr) == -1) return -1;
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

	const Pos2 asTouch(const int32_t touch_id)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		int touch_x = 0, touch_y = 0;
		DxLib::GetTouchInput(touch_id, &touch_x, &touch_y, nullptr, nullptr);
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

}
