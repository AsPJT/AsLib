//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsProject Library
//
//                    Created by Gaccho (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------
#ifndef INCLUDED_AS_PROJECT_LIBRARY_LOOP
#define INCLUDED_AS_PROJECT_LIBRARY_LOOP


namespace AsLib
{
	//���C�����[�v
	const bool asLoop()
	{
		updateKey();
		updateTouch();
		updateMouse();
#if defined(ASLIB_INCLUDE_DL) //DxLib
		return ((asIsInit()==true&& DxLib::ProcessMessage() == 0) && (DxLib::ScreenFlip() == 0) && (DxLib::ClearDrawScreen() == 0) && (DxLib::CheckHitKey(KEY_INPUT_ESCAPE) == 0));
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		return s3d::System::Update();
#elif defined(ASLIB_INCLUDE_OF)
		return false;
#elif defined(ASLIB_INCLUDE_C2)
return 0;
#elif defined(ASLIB_INCLUDE_SF)
return 0;
#elif defined(ASLIB_INCLUDE_TP)
		return false;
#else //Console
		return false;
#endif
	}

	//���C�����[�v
	const bool asNoClearLoop()
	{
		updateKey();
		updateTouch();
		updateMouse();
#if defined(ASLIB_INCLUDE_DL) //DxLib
		return ((asIsInit() == true && DxLib::ProcessMessage() == 0) && (DxLib::ScreenFlip() == 0) && (DxLib::CheckHitKey(KEY_INPUT_ESCAPE) == 0));
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		return s3d::System::Update();
#elif defined(ASLIB_INCLUDE_OF)
		return false;
#elif defined(ASLIB_INCLUDE_C2)
return 0;
#elif defined(ASLIB_INCLUDE_SF)
return 0;
#elif defined(ASLIB_INCLUDE_TP)
		return false;
#else //Console
		return false;
#endif
	}

}

#endif //Included AsProject Library