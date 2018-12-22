//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsProject Library
//
//                    Created by Gaccho (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------
#ifndef INCLUDED_AS_PROJECT_LIBRARY_CLIPBOARD
#define INCLUDED_AS_PROJECT_LIBRARY_CLIPBOARD


namespace AsLib
{

#if defined(ASLIB_INCLUDE_DL) //DxLib

#if defined(__WINDOWS__)
	inline void asClipboard(const char* const str_) { DxLib::SetClipboardText(str_); }
	inline void asClipboard(const std::string& str_) { asClipboard(str_.c_str()); }

	const std::string asClipboard() {
		const size_t b = size_t(DxLib::GetClipboardText(NULL) + 1);
		if (b == 0) return std::string(u8"Error");
		const std::unique_ptr<char[]> ptr(new char[b]);
		DxLib::GetClipboardText(ptr.get());
		return std::string(ptr.get());
	}

	const std::string asDrag() {
		if (DxLib::GetDragFileNum() < 1) return u8"";
		const size_t b = size_t(DxLib::GetDragFilePath(NULL) + 1);
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