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

	inline void asClipboard(const char* const str_) { DxLib::SetClipboardText(str_); }
	inline void asClipboard(const std::string str_) { asClipboard(str_.c_str()); }

	const std::string asClipboard() {
		const size_t b = size_t(DxLib::GetClipboardText(NULL) + 1);
		if (b == 0) return std::string(u8"Error");
		const std::unique_ptr<char[]> ptr(new char[b]);
		DxLib::GetClipboardText(ptr.get());
		return std::string(ptr.get());
	}

#elif defined(ASLIB_INCLUDE_S3) //Siv3D

#elif defined(ASLIB_INCLUDE_OF)

#elif defined(ASLIB_INCLUDE_TP)

#else //Console

#endif

}
