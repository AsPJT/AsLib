//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asライブラリ
//
//                    制作者: がっちょ (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
	//メインループ
	const bool asLoop()
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		return ((DxLib::ProcessMessage() == 0) && (DxLib::ScreenFlip() == 0) && (DxLib::ClearDrawScreen() == 0) && (DxLib::CheckHitKey(KEY_INPUT_ESCAPE) == 0));
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		return s3d::System::Update();
#elif defined(ASLIB_INCLUDE_TP)
		return false;
#else //Console
		return false;
#endif
	}
}
