//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asƒ‰ƒCƒuƒ‰ƒŠ
//
//                    §ìÒ: ‚ª‚Á‚¿‚å (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{

#if defined(ASLIB_INCLUDE_DL) //DxLib

	int32_t asStop()
	{
		if (DxLib::ScreenFlip() == -1) return -1;
		if (DxLib::WaitKey() == -1) return -1;
		return 0;
	}

#elif defined(ASLIB_INCLUDE_S3) //Siv3D

	int32_t asStop()
	{
		//s3d::WaitKey();
		return 0;
	}

#else //Console

	inline int32_t asStop()
	{
		return 0;
	}

#endif

}
