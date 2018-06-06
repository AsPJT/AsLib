//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asƒ‰ƒCƒuƒ‰ƒŠ
//
//                    §ìÒ: ‚ª‚Á‚¿‚å (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{

#if defined(ASLIB_INCLUDE_DL) //DxLib

	inline int32_t asBrowser(const char* const url_str)
	{
#if defined(__WINDOWS__)
		const HWND hWnd = {};
		ShellExecute(hWnd, "open", url_str, NULL, NULL, SW_SHOW);
		return 0;
#elif defined(__ANDROID__)
		return int32_t(DxLib::AndroidJumpURL(url_str));
#endif
	}

	inline int32_t asTwitter(const char* const url_str)
	{
#if defined(__WINDOWS__)
		const HWND hWnd = {};
		ShellExecute(hWnd, "open", url_str, NULL, NULL, SW_SHOW);
		return 0;
#elif defined(__ANDROID__)
		return int32_t(DxLib::AndroidJumpURL(url_str, "com.twitter.android"));
#endif
	}

#elif defined(ASLIB_INCLUDE_S3) //Siv3D

#else //Console

#endif

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
