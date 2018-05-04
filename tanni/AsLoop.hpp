//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asライブラリ
//
//                    制作者: がっちょ (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{

#if defined(__DXLIB) //DxLib

	//メインループ
	bool AsLoop()
	{
		return ((DxLib::ProcessMessage() == 0) && (DxLib::ScreenFlip() == 0) && (DxLib::ClearDrawScreen() == 0) && (DxLib::CheckHitKey(KEY_INPUT_ESCAPE) == 0));
	}

	bool AsLoop(AsInitData& as)
	{
		if (AsLoop() == false) return false;

		return true;
	}

#elif defined(SIV3D_INCLUDED) //Siv3D

#else //Console

#endif

}
