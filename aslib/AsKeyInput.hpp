//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsProject Library
//
//                    Created by Gaccho (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
	constexpr size_t KEY_INPUT_CHAR_MAX = 255;
	constexpr size_t KEY_INPUT_CHAR_MAX_1 = KEY_INPUT_CHAR_MAX + 1;

#if defined(ASLIB_INCLUDE_DL) //DxLib
#if defined(__ANDROID__)

	const char* const asKeyInputAndroid()
	{
		static std::string InputString;
		InputString = u8"Error!";

		JNIEnv* env;
		const ANativeActivity* const NativeActivity = DxLib::GetNativeActivity();
		int32_t InputEnd = 0;

		if (NativeActivity->vm->AttachCurrentThreadAsDaemon(&env, NULL) != JNI_OK) return InputString.c_str();
		const jclass jclass_ = env->GetObjectClass(NativeActivity->clazz);
		const jmethodID jmethodID_StartInputDialog = env->GetMethodID(jclass_, u8"StartInputStringDialog", u8"()V");
		env->CallVoidMethod(NativeActivity->clazz, jmethodID_StartInputDialog);
		env->DeleteLocalRef(jclass_);
		NativeActivity->vm->DetachCurrentThread();

		while (!DxLib::ProcessMessage())
		{
			if (InputEnd) break;

			if (NativeActivity->vm->AttachCurrentThreadAsDaemon(&env, NULL) != JNI_OK) return InputString.c_str();

			const jclass jclass_ = env->GetObjectClass(NativeActivity->clazz);
			const jfieldID jfieldID_InputEnd = env->GetFieldID(jclass_, u8"InputEnd", u8"I");
			InputEnd = int32_t(env->GetIntField(NativeActivity->clazz, jfieldID_InputEnd));

			if (InputEnd == 1) {
				const jfieldID jfieldID_InputString = env->GetFieldID(jclass_, u8"InputString", u8"Ljava/lang/String;");
				const jstring jstring_InputString = (jstring)env->GetObjectField(NativeActivity->clazz, jfieldID_InputString);
				const char* const chars_InputString = env->GetStringUTFChars(jstring_InputString, NULL);

				InputString = std::string(chars_InputString);
				env->ReleaseStringUTFChars(jstring_InputString, chars_InputString);
				env->DeleteLocalRef(jstring_InputString);

			}
			env->DeleteLocalRef(jclass_);
			NativeActivity->vm->DetachCurrentThread();
		}
		return InputString.c_str();
	}

	inline int32_t asKeyInput(char* name, const Pos2& pos2 = pos2_0, const size_t& max_char = KEY_INPUT_CHAR_MAX)
	{
#if defined(DXLIB_ANDROID_MAKE_FUNCTION)
		std::string InputString = asKeyInputAndroid();
		for (size_t i = 0;; ++i) {
			name[i] = InputString[i];

			if (InputString[i] == 0) break;
			if (i == KEY_INPUT_CHAR_MAX - 1) {
				name[i + 1] = 0;
				break;
			}
		}
		return 0;
#else
		return 0;
#endif
	}

	inline const char* const asKeyInput(const Pos2& pos2 = pos2_0)
	{
#if defined(DXLIB_ANDROID_MAKE_FUNCTION)
		return asKeyInputAndroid();
#else
		return u8"";
#endif
	}

#endif
#endif


#if !defined(__ANDROID__)
	inline int32_t asKeyInput(char* name, const Pos2& p_, const size_t& m_= KEY_INPUT_CHAR_MAX)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
#if defined(__WINDOWS__)
		return int32_t(DxLib::KeyInputString(int(p_.x), int(p_.y), m_, name, TRUE));
#else
		return 0;
#endif
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
	return 0;
#elif defined(ASLIB_INCLUDE_OF)

#elif defined(ASLIB_INCLUDE_TP)
	return 0;
#else //Console
		std::string key_string;
		std::cin >> key_string;

		for (size_t i = 0; i <= m_; ++i) {

			name[i] = key_string[i];

			if (key_string[i] == '\0') break;
		}

		return 0;
#endif
	}
#endif

	inline int32_t asKeyInput1Byte(char* name, const Pos2& pos2 = pos2_0, const size_t& max_char = KEY_INPUT_CHAR_MAX)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
#if defined(__WINDOWS__)
		return int32_t(DxLib::KeyInputSingleCharString(int(pos2.x), int(pos2.y), max_char, name, TRUE));
#else
		return 0;
#endif
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		return 0;
#elif defined(ASLIB_INCLUDE_OF)

#elif defined(ASLIB_INCLUDE_TP)
		return 0;
#else //Console
		return 0;
#endif
	}

	inline int32_t asKeyInputNum(const Pos2& pos2 = pos2_0, const int32_t& max_num = 10, const int32_t& min_num = 0)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
#if defined(__WINDOWS__)
		return int32_t(DxLib::KeyInputNumber(pos2.x, pos2.y, max_num - 1, min_num + 1, TRUE));
#else
		return 0;
#endif
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		return 0;
#elif defined(ASLIB_INCLUDE_OF)

#elif defined(ASLIB_INCLUDE_TP)
		return 0;
#else //Console
		return 0;
#endif
	}

#if !defined(__ANDROID__)
	const char* const asKeyInput(const Pos2& p_)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
#if defined(__WINDOWS__)
		static char key_string[KEY_INPUT_CHAR_MAX_1];
		for (size_t i = 0; i < KEY_INPUT_CHAR_MAX_1; ++i) key_string[i] = '\0';

		asKeyInput(key_string, p_);
		return key_string;
#else
		return nullptr;
#endif
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		return 0;
#elif defined(ASLIB_INCLUDE_OF)
		return 0;
#elif defined(ASLIB_INCLUDE_TP)
		return 0;
#else //Console
		return 0;
#endif
	}
#endif



}
