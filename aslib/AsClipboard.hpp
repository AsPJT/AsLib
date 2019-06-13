/*#######################################################################################
	Made by Kasugaccho
	Made by As Project
	https://github.com/Kasugaccho/AsLib
	wanotaitei@gmail.com

	This code is licensed under CC0.
#######################################################################################*/
#ifndef INCLUDED_AS_PROJECT_LIBRARY_CLIPBOARD
#define INCLUDED_AS_PROJECT_LIBRARY_CLIPBOARD


namespace AsLib
{

#if defined(ASLIB_INCLUDE_DL) //DxLib

#if defined(__WINDOWS__)
	inline void asClipboard(const char* const str_) noexcept { DxLib::SetClipboardText(str_); }
	inline void asClipboard(const std::string& str_) noexcept { asClipboard(str_.c_str()); }

	std::string asClipboard() noexcept {
		const std::size_t b{ std::size_t(DxLib::GetClipboardText(NULL) + 1) };
		if (b == 0) return std::string(u8"Error");
		const std::unique_ptr<char[]> ptr(new char[b]);
		DxLib::GetClipboardText(ptr.get());
		return std::string(ptr.get());
	}

	std::string asDrag() noexcept {
		if (DxLib::GetDragFileNum() < 1) return u8"";
		const std::size_t b{ std::size_t(DxLib::GetDragFilePath(NULL) + 1) };
		if (b == 0) return std::string(u8"Error");
		const std::unique_ptr<char[]> ptr(new char[b]);
		DxLib::GetDragFilePath(ptr.get());
		DxLib::DragFileInfoClear();
		return std::string(ptr.get());
	}
#endif

#elif defined(ASLIB_INCLUDE_S3) //Siv3D

#elif defined(ASLIB_INCLUDE_OF)

#elif defined(ASLIB_INCLUDE_C2)

#elif defined(ASLIB_INCLUDE_SF)
return 0;
#elif defined(ASLIB_INCLUDE_TP)

#else //Console

#endif

}

#endif //Included AsProject Library