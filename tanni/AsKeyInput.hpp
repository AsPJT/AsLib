//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asƒ‰ƒCƒuƒ‰ƒŠ
//
//                    §ìŽÒ: ‚ª‚Á‚¿‚å (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
	constexpr size_t KEY_INPUT_CHAR_MAX = 255;
	constexpr size_t KEY_INPUT_CHAR_MAX_1 = KEY_INPUT_CHAR_MAX + 1;

#if defined(__DXLIB) //DxLib

#if defined(__ANDROID__)

//	int32_t asKeyInput(char* name, const Pos2& pos2 = pos2_0, const size_t max_char = KEY_INPUT_CHAR_MAX)
//	{
//#if defined(DXLIB_ANDROID_MAKE_FUNCTION)
//		return asKeyInputAndroid(&name, pos2, max_char);
//#else
//		return 0;
//#endif
//	}

#else

	inline int32_t asKeyInput(char* name, const Pos2& pos2 = pos2_0, const size_t& max_char = KEY_INPUT_CHAR_MAX)
	{
		return int32_t(DxLib::KeyInputString(int(pos2.x), int(pos2.y), max_char, name, TRUE));
	}

	inline int32_t asKeyInput1Byte(char* name, const Pos2& pos2 = pos2_0, const size_t& max_char = KEY_INPUT_CHAR_MAX)
	{
		return int32_t(DxLib::KeyInputSingleCharString(int(pos2.x), int(pos2.y), max_char, name, TRUE));
	}

	inline int32_t asKeyInputNum(const Pos2& pos2 = pos2_0, const int32_t& max_num = 10, const int32_t& min_num = 0)
	{
		return int32_t(DxLib::KeyInputNumber(pos2.x, pos2.y, max_num - 1, min_num + 1, TRUE));
	}

#endif

#elif defined(SIV3D_INCLUDED) //Siv3D

#else //Console

	int32_t asKeyInput(char* name, const Pos2& pos2 = pos2_0, const size_t max_char = KEY_INPUT_CHAR_MAX)
	{
		std::string key_string;
		std::cin >> key_string;

		for (size_t i = 0; i <= max_char; ++i) {

			name[i] = key_string[i];

			if (key_string[i] == '\0') break;
		}

		return 0;
	}

#endif

	const char* asKeyInput(const Pos2& pos2 = pos2_0)
	{
		static char key_string[KEY_INPUT_CHAR_MAX_1];
		for (size_t i = 0; i < KEY_INPUT_CHAR_MAX_1; ++i) key_string[i] = '\0';

		asKeyInput(key_string, pos2);
		return key_string;
	}

}
