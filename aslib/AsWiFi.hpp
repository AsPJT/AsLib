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

#if defined(__ANDROID__)

	//<uses-permission android:name="android.permission.ACCESS_WIFI_STATE" />�ǉ�����
	inline int32_t asWifi()
	{
		return int32_t(GetWifiSignalLevel());
}
#endif

#elif defined(ASLIB_INCLUDE_S3) //Siv3D

#else //Console

#endif

}
