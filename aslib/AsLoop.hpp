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

	//メインループ
	bool AsLoop()
	{
		return ((DxLib::ProcessMessage() == 0) && (DxLib::ScreenFlip() == 0) && (DxLib::ClearDrawScreen() == 0) && (DxLib::CheckHitKey(KEY_INPUT_ESCAPE) == 0));
	}

#elif defined(ASLIB_INCLUDE_S3) //Siv3D

	//メインループ
	bool AsLoop()
	{
		return s3d::System::Update();
	}

#else //Console

	static bool ASLIB_CONSOLE_LOOP = true;
	bool AsLoop()
	{
		return ASLIB_CONSOLE_LOOP;
	}

#endif

}
