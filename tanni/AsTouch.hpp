//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - As���C�u����
//
//                    �����: �������� (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{

#if defined(ASLIB_INCLUDE_DL) //DxLib

	//�^�b�`����Ă��鐔��Ԃ�
	inline int32_t asTouchNum()
	{
		return int32_t(DxLib::GetTouchInputNum());
	}

	//�^�b�`����Ă���
	int32_t asTouch(const int32_t touch_id, Pos2& add_pos)
	{
		int touch_x = 0, touch_y = 0;
		if (DxLib::GetTouchInput(touch_id, &touch_x, &touch_y, nullptr, nullptr) == -1) return -1;
		add_pos(int32_t(touch_x), int32_t(touch_y));

		return 0;
	}

#elif defined(ASLIB_INCLUDE_S3) //Siv3D
	//todo(�^�b�`���ǉ�����Ă��Ȃ�)
	inline int32_t asTouchNum()
	{
		return 0;
	}

	//todo(�^�b�`���ǉ�����Ă��Ȃ�)
	int32_t asTouch(const int32_t touch_id, Pos2& add_pos)
	{
		touch_id; add_pos;
		return 0;
	}

#else //Console

#endif

}
