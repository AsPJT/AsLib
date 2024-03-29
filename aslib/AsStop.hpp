﻿/*#######################################################################################
	Made by Kasugaccho
	Made by As Project
	https://github.com/Kasugaccho/AsLib
	wanotaitei@gmail.com

	This code is licensed under CC0.
#######################################################################################*/
#ifndef INCLUDED_AS_PROJECT_LIBRARY_STOP
#define INCLUDED_AS_PROJECT_LIBRARY_STOP


namespace AsLib
{

	inline void asStop() noexcept
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		DxLib::ScreenFlip();
		DxLib::WaitKey();
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
#elif defined(ASLIB_INCLUDE_OF)
#elif defined(ASLIB_INCLUDE_C2)

#elif defined(ASLIB_INCLUDE_SF)
return 0;
#elif defined(ASLIB_INCLUDE_TP)
#else //Console
#endif
	}

}

#endif //Included AsProject Library