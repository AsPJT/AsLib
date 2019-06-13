/*#######################################################################################
	Made by Kasugaccho
	Made by As Project
	https://github.com/Kasugaccho/AsLib
	wanotaitei@gmail.com

	This code is licensed under CC0.
#######################################################################################*/
#ifndef INCLUDED_AS_PROJECT_LIBRARY_SNS
#define INCLUDED_AS_PROJECT_LIBRARY_SNS


namespace AsLib
{



	inline std::int32_t asBrowser(const char* const url_str) noexcept
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
#if defined(__WINDOWS__)
		const HWND hWnd{};
		ShellExecute(hWnd, "open", url_str, NULL, NULL, SW_SHOW);
		return 0;
#elif defined(__ANDROID__)
		return std::int32_t(DxLib::AndroidJumpURL(url_str));
#endif

#elif defined(ASLIB_INCLUDE_S3) //Siv3D
#if defined(SIV3D_TARGET_WINDOWS)
		const HWND hWnd = {};
		const std::string url_ = url_str;
		const std::wstring stemp = std::wstring(url_.begin(), url_.end());
		ShellExecute(hWnd, L"open", stemp.c_str(), NULL, NULL, SW_SHOW);
		return 0;
#else
		return 0;
#endif
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

	inline std::int32_t asTwitter(const char* const url_str) noexcept
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
#if defined(__WINDOWS__)
		const HWND hWnd{};
		ShellExecute(hWnd, "open", url_str, NULL, NULL, SW_SHOW);
		return 0;
#elif defined(__ANDROID__)
		return std::int32_t(DxLib::AndroidJumpURL(url_str, u8"com.twitter.android"));
#endif

#elif defined(ASLIB_INCLUDE_S3) //Siv3D
#if defined(SIV3D_TARGET_WINDOWS)
		const HWND hWnd = {};
		const std::string url_ = url_str;
		const std::wstring stemp = std::wstring(url_.begin(), url_.end());
		ShellExecute(hWnd, L"open", stemp.c_str(), NULL, NULL, SW_SHOW);
		return 0;
#else
		return 0;
#endif
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



	struct Twitter
	{
		Twitter& make() noexcept { this->url_str = u8"https://twitter.com/share?"; return *this; };
		Twitter& makeUrl(const char* const add_str) noexcept { this->make(); this->url_str += u8"url="; this->url_str += add_str; return *this; };
		Twitter& makeText(const char* const add_str) noexcept { this->make(); this->url_str += u8"text="; this->url_str += add_str; return *this; };
		Twitter& makeVia(const char* const add_str) noexcept { this->make(); this->url_str += u8"via="; this->url_str += add_str; return *this; };
		Twitter& makeRelated(const char* const add_str) noexcept { this->make(); this->url_str += u8"related="; this->url_str += add_str; return *this; };
		Twitter& makeHashtags(const char* const add_str) noexcept { this->make(); this->url_str += u8"hashtags="; this->url_str += add_str; return *this; };
		Twitter& url(const char* const add_str) noexcept { this->url_str += u8"&url="; this->url_str += add_str; return *this; };
		Twitter& text(const char* const add_str) noexcept { this->url_str += u8"&text="; this->url_str += add_str; return *this; };
		Twitter& via(const char* const add_str) noexcept { this->url_str += u8"&via="; this->url_str += add_str; return *this; };
		Twitter& related(const char* const add_str) noexcept { this->url_str += u8"&related="; this->url_str += add_str; return *this; };
		Twitter& hashtags(const char* const add_str) noexcept { this->url_str += u8"&hashtags="; this->url_str += add_str; return *this; };
		Twitter& send() noexcept { asTwitter(url_str.c_str()); return *this; };
		const char* const c_str() const noexcept { return url_str.c_str(); };
		std::size_t length() const noexcept { return url_str.length(); };
	private:
		std::string url_str;
	};

}

#endif //Included AsProject Library