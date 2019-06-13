/*#######################################################################################
	Made by Kasugaccho
	Made by As Project
	https://github.com/Kasugaccho/AsLib
	wanotaitei@gmail.com

	This code is licensed under CC0.
#######################################################################################*/
#ifndef INCLUDED_AS_PROJECT_LIBRARY_KEYINPUT
#define INCLUDED_AS_PROJECT_LIBRARY_KEYINPUT


namespace AsLib
{
	constexpr std::size_t KEY_INPUT_CHAR_MAX{ 255 };
	constexpr std::size_t KEY_INPUT_CHAR_MAX_1{ KEY_INPUT_CHAR_MAX + 1 };

#if defined(ASLIB_INCLUDE_DL) //DxLib
#if defined(__ANDROID__)

	const char* const asKeyInputAndroid() noexcept
	{
		static std::string InputString;
		InputString = u8"Error!";

		JNIEnv* env;
		const ANativeActivity* const NativeActivity = DxLib::GetNativeActivity();
		std::int32_t InputEnd = 0;

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
			InputEnd = std::int32_t(env->GetIntField(NativeActivity->clazz, jfieldID_InputEnd));

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

	inline std::int32_t asKeyInput(char* name, const Pos2& pos2 = pos2_0, const std::size_t& max_char = KEY_INPUT_CHAR_MAX) noexcept
	{
#if defined(DXLIB_ANDROID_MAKE_FUNCTION)
		std::string InputString = asKeyInputAndroid();
		for (std::size_t i{};; ++i) {
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

	inline const char* const asKeyInput(const Pos2& pos2 = pos2_0) noexcept
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
	inline std::int32_t asKeyInput(char* name, const Pos2& p_, const std::size_t& m_= KEY_INPUT_CHAR_MAX) noexcept
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
#if defined(__WINDOWS__)
		return std::int32_t(DxLib::KeyInputString(int(p_.x), int(p_.y), m_, name, TRUE));
#else
		return 0;
#endif
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
	return 0;
#elif defined(ASLIB_INCLUDE_OF)
		return 0;
#elif defined(ASLIB_INCLUDE_C2)
return 0;
#elif defined(ASLIB_INCLUDE_SF)
return 0;
#elif defined(ASLIB_INCLUDE_TP)
	return 0;
#else //Console
		std::string key_string;
		std::cin >> key_string;

		for (std::size_t i{}; i <= m_; ++i) {

			name[i] = key_string[i];

			if (key_string[i] == '\0') break;
		}

		return 0;
#endif
	}
#endif

	inline std::int32_t asKeyInput1Byte(char* name, const Pos2& pos2 = pos2_0, const std::size_t& max_char = KEY_INPUT_CHAR_MAX) noexcept
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
#if defined(__WINDOWS__)
		return std::int32_t(DxLib::KeyInputSingleCharString(int(pos2.x), int(pos2.y), max_char, name, TRUE));
#else
		return 0;
#endif
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		return 0;
#elif defined(ASLIB_INCLUDE_OF)

#elif defined(ASLIB_INCLUDE_C2)
return 0;
#elif defined(ASLIB_INCLUDE_SF)
return 0;
#elif defined(ASLIB_INCLUDE_TP)
		return 0;
#else //Console
		return 0;
#endif
	}

	inline std::int32_t asKeyInputNum(const Pos2& pos2 = pos2_0, const std::int32_t& max_num = 10, const std::int32_t& min_num = 0) noexcept
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
#if defined(__WINDOWS__)
		return std::int32_t(DxLib::KeyInputNumber(pos2.x, pos2.y, max_num - 1, min_num + 1, TRUE));
#else
		return 0;
#endif
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		return 0;
#elif defined(ASLIB_INCLUDE_OF)

#elif defined(ASLIB_INCLUDE_C2)
return 0;
#elif defined(ASLIB_INCLUDE_SF)
return 0;
#elif defined(ASLIB_INCLUDE_TP)
		return 0;
#else //Console
		return 0;
#endif
	}

#if !defined(__ANDROID__)
	const char* const asKeyInput(const Pos2& p_) noexcept
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
#if defined(__WINDOWS__)
		static char key_string[KEY_INPUT_CHAR_MAX_1];
		for (std::size_t i{}; i < KEY_INPUT_CHAR_MAX_1; ++i) key_string[i] = '\0';

		asKeyInput(key_string, p_);
		return key_string;
#else
		return nullptr;
#endif
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		return 0;
#elif defined(ASLIB_INCLUDE_OF)
		return 0;
#elif defined(ASLIB_INCLUDE_C2)
return 0;
#elif defined(ASLIB_INCLUDE_SF)
return 0;
#elif defined(ASLIB_INCLUDE_TP)
		return 0;
#else //Console
		return 0;
#endif
	}
#endif

	const int setKeyInput(const int handle_ = -1, const bool is_ = false) noexcept {
		static thread_local int handle = -1;
		if (is_) handle = handle_;
		return handle;
	}

	//文字入力システム
	struct AsKeyInput {
		std::size_t size = 0;
		int handle = -1;
		bool is_on = false;
		char mode = 'a';
		std::string str{};

#if defined(ASLIB_INCLUDE_DL) //DxLib
#if defined(__WINDOWS__)
		AsKeyInput(const std::size_t s_, const char mode_ = 'a') :size(s_), mode(mode_),
			handle(DxLib::MakeKeyInput((s_ == 0) ? 1 : size, FALSE, (mode_ == 'h') ? TRUE : FALSE, (mode_ == 'n') ? TRUE : FALSE)){}

		void on() noexcept {
			DxLib::SetActiveKeyInput(handle);
			setKeyInput(handle, true);
			is_on = true;
			str.clear();
		}
		void off() noexcept { if (handle == setKeyInput()) DxLib::SetActiveKeyInput(-1); is_on = false; }
		const bool check() {
			if (handle != setKeyInput()) is_on = false;
			if (!is_on) return false;
			return (DxLib::CheckKeyInput(handle) != 0);
		}
		void draw(const Pos2& p_) noexcept {
			if (handle != setKeyInput()) is_on = false;
			if (is_on) DxLib::DrawKeyInputString(p_.x, p_.y, handle);
		}
		const std::string output() noexcept {
			if (size == 0) return str;
			std::unique_ptr<char[]> unique_str(new char[size]);
			for (std::size_t i{}; i < size; ++i) unique_str[i] = 0;
			DxLib::GetKeyInputString(unique_str.get(), handle);
			str = std::string(unique_str.get());
			return str;
		}
		void clear() noexcept {
			DxLib::DeleteKeyInput(handle);
			str.clear();
			str.shrink_to_fit();
			handle = -1;
		}
		const std::int32_t outputNum() noexcept {
			if (mode != 'n') return 0;
			return DxLib::GetKeyInputNumber(handle);
		}
		void inputNum(const std::int32_t num_) noexcept {
			if (mode != 'n') return;
			DxLib::SetKeyInputNumber(num_, handle);
		}
		void input(const char* const str_) noexcept {
			DxLib::SetKeyInputString(str_, handle);
		}
#endif
#endif
	};

	class AsKeyButton {
	private:
		AsKeyInput ki;
		AsFont f;
		Pos4 p;

		//タッチカウント
		Counter counter;
	public:
		AsKeyButton(const std::size_t num_, const Pos4& p_) :ki(num_), p(p_), f(std::int32_t((p_.y2 - p_.y1)*0.8f)) {}

		void drawButton() noexcept {
			asRect(Color(255, 255, 255, 255), p);
		}
		void on(const bool is_) noexcept { if (is_)ki.on(); }
		void off(const bool is_) noexcept { if (is_)ki.off(); }
		void on() noexcept { ki.on(); }
		void off() noexcept { ki.off(); }

		void drawString() noexcept {
			if(ki.is_on) f.draw(std::string(ki.output()+u8"|").c_str(), Pos2(p.x1, p.y1), Color(0,0,0));
			else f.draw(ki.output().c_str(), Pos2(p.x1, p.y1), Color(0, 0, 0));
		}

		//タッチカウント
		void update() noexcept { counter.update(asTouch(p) || asMouseL(p)); }
		const bool down() const noexcept { return counter.down(); };
		const bool up() const noexcept { return counter.up(); };
		const std::int32_t count() const noexcept { return counter.count(); };
		const bool down0() noexcept { return counter.down0(); };
		const bool up0() noexcept { return counter.up0(); };
		const std::int32_t count0() noexcept { return counter.count0(); };

	};




}

#endif //Included AsProject Library