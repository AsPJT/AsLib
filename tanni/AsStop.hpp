//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asƒ‰ƒCƒuƒ‰ƒŠ
//
//                    §ìÒ: ‚ª‚Á‚¿‚å (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{

#if defined(__DXLIB) //DxLib

	int32_t asStop()
	{
		if (DxLib::ScreenFlip() == -1) return -1;
		if (DxLib::WaitKey() == -1) return -1;
		return 0;
	}

#elif defined(SIV3D_INCLUDED) //Siv3D

#else //Console

	inline int32_t asStop()
	{
		return 0;
	}

#endif

}
