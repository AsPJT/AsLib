//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsProject Library
//
//                    Created by Gaccho (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{

	inline void asStop()
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		DxLib::ScreenFlip();
		DxLib::WaitKey();
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
#elif defined(ASLIB_INCLUDE_OF)
#elif defined(ASLIB_INCLUDE_C2)

#elif defined(ASLIB_INCLUDE_TP)
#else //Console
#endif
	}

}
