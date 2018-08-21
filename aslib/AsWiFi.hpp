//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsProject Library
//
//                    Created by Gaccho (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
	inline const int32_t asWifi()
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
#if defined(__ANDROID__)
		//<uses-permission android:name="android.permission.ACCESS_WIFI_STATE" />�ǉ�����
		return int32_t(DxLib::GetWifiSignalLevel());
#else
		return 0;
#endif
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		return 0;
#elif defined(ASLIB_INCLUDE_OF)
		return 0;
#elif defined(ASLIB_INCLUDE_C2)
return 0;
#elif defined(ASLIB_INCLUDE_TP)
		return 0;
#else
		return 0;
#endif
	}
}
