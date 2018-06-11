//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - As���C�u����
//
//                    �����: �������� (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{



	inline int32_t asBrowser(const char* const url_str)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
#if defined(__WINDOWS__)
		const HWND hWnd = {};
		ShellExecute(hWnd, "open", url_str, NULL, NULL, SW_SHOW);
		return 0;
#elif defined(__ANDROID__)
		return int32_t(DxLib::AndroidJumpURL(url_str));
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
#else //Console

#endif
	}

	inline int32_t asTwitter(const char* const url_str)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
#if defined(__WINDOWS__)
		const HWND hWnd = {};
		ShellExecute(hWnd, "open", url_str, NULL, NULL, SW_SHOW);
		return 0;
#elif defined(__ANDROID__)
		return int32_t(DxLib::AndroidJumpURL(url_str, "com.twitter.android"));
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
#else //Console

#endif
	}



	struct Twitter
	{
		Twitter& make() { this->url_str = "https://twitter.com/share?"; return *this; };
		Twitter& makeUrl(const char* const add_str) { this->make(); this->url_str += "url="; this->url_str += add_str; return *this; };
		Twitter& makeText(const char* const add_str) { this->make(); this->url_str += "text="; this->url_str += add_str; return *this; };
		Twitter& makeVia(const char* const add_str) { this->make(); this->url_str += "via="; this->url_str += add_str; return *this; };
		Twitter& makeRelated(const char* const add_str) { this->make(); this->url_str += "related="; this->url_str += add_str; return *this; };
		Twitter& makeHashtags(const char* const add_str) { this->make(); this->url_str += "hashtags="; this->url_str += add_str; return *this; };
		Twitter& url(const char* const add_str) { this->url_str += "&url="; this->url_str += add_str; return *this; };
		Twitter& text(const char* const add_str) { this->url_str += "&text="; this->url_str += add_str; return *this; };
		Twitter& via(const char* const add_str) { this->url_str += "&via="; this->url_str += add_str; return *this; };
		Twitter& related(const char* const add_str) { this->url_str += "&related="; this->url_str += add_str; return *this; };
		Twitter& hashtags(const char* const add_str) { this->url_str += "&hashtags="; this->url_str += add_str; return *this; };
		Twitter& send() { asTwitter(url_str.c_str()); return *this; };
		const char* c_str() const { return url_str.c_str(); };
		size_t length() const { return url_str.length(); };
	private:
		std::string url_str;
	};

}