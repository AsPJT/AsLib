//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsProject Library
//
//                    Created by Gaccho (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------
#ifndef INCLUDED_AS_PROJECT_LIBRARY_BASE64
#define INCLUDED_AS_PROJECT_LIBRARY_BASE64

//Base64の種類を定義
enum :size_t {
	base64_type_default,
	base64_type_url,
};

//Base64の文字列を定義
constexpr char base64_str_table_default[] = u8"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
constexpr char base64_str_table_url[] = u8"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_";
constexpr size_t base64_str_table_length = sizeof(base64_str_table_default) / sizeof(base64_str_table_default[0]) - 1;

//Base64管理構造体
struct Base64 {
	char empty_char = '=';
	size_t type = base64_type_default;
	const char* str_table = nullptr;

	Base64() = default;
	constexpr explicit Base64(const size_t type_, const char* str_table_, const char empty_char_ = '=')
		:empty_char(empty_char_), type(type_), str_table(str_table_) {}
};
constexpr Base64 base64_default(base64_type_default, base64_str_table_default);
constexpr Base64 base64_url(base64_type_url, base64_str_table_url, 0);
//Base64で文字列をエンコードする
std::string base64_Encode(const char* const str_, const size_t length_, const size_t type_ = base64_type_default) noexcept
{
	if (str_ == nullptr) return nullptr;
	const Base64 base64 = (type_ == base64_type_default) ? base64_default : base64_url;

	const size_t length = length_ * 4 / 3 + 3 + 1;
	const std::unique_ptr<char[]> str(new char[length]);
	char* str_ptr = str.get();
	for (size_t i = 0, j = length_; j > 0; i += 3, j -= 3) {
		switch (j)
		{
		case 1:
			*(str_ptr++) = base64.str_table[(str_[i + 0] >> 2 & 63)];
			*(str_ptr++) = base64.str_table[(str_[i + 0] << 4 & 48)];
			*(str_ptr++) = base64.empty_char;
			*(str_ptr++) = base64.empty_char;
			j = 3;
			break;
		case 2:
			*(str_ptr++) = base64.str_table[(str_[i + 0] >> 2 & 63)];
			*(str_ptr++) = base64.str_table[(str_[i + 0] << 4 & 48) | (str_[i + 1] >> 4 & 15)];
			*(str_ptr++) = base64.str_table[(str_[i + 1] << 2 & 60)];
			*(str_ptr++) = base64.empty_char;
			j = 3;
			break;
		default:
			*(str_ptr++) = base64.str_table[(str_[i + 0] >> 2 & 63)];
			*(str_ptr++) = base64.str_table[(str_[i + 0] << 4 & 48) | (str_[i + 1] >> 4 & 15)];
			*(str_ptr++) = base64.str_table[(str_[i + 1] << 2 & 60) | (str_[i + 2] >> 6 & 3)];
			*(str_ptr++) = base64.str_table[(str_[i + 2] << 0 & 63)];
			break;
		}
	}
	*str_ptr = 0;

	static std::string final_str;
	final_str = std::string(str.get());
	return 	final_str;
}
inline std::string base64_EncodeURL(const char* const str_, const size_t length_, const size_t type_ = base64_type_url) noexcept { return base64_Encode(str_, length_, type_); }
inline std::string base64_Encode(const std::string& str_, const size_t type_ = base64_type_default) noexcept { return base64_Encode(str_.c_str(), str_.size(), type_); }
inline std::string base64_EncodeURL(const std::string& str_, const size_t type_ = base64_type_url) noexcept { return base64_Encode(str_.c_str(), str_.size(), type_); }

//Base64で文字列をデコードする
std::string base64_Decode(const char* const str_, const size_t type_ = base64_type_default) noexcept
{
	if (str_ == nullptr) return nullptr;
	const Base64 base64 = (type_ == base64_type_default) ? base64_default : base64_url;

	const size_t length = strlen(str_);
	const std::unique_ptr<char[]> str(new char[length * 3 / 4 + 2 + 1]);
	char str_table[128]{};
	for (size_t i = 0; i < base64_str_table_length; ++i) str_table[base64.str_table[i] & 127] = char(i);
	char *str_ptr = str.get();
	char table_char = 0;
	for (size_t i = 0, j = 0; i < length; ++i, j = i % 4) {
		if (str_[i] == base64.empty_char) break;
		table_char = str_table[size_t(str_[i] & 127)];
		if (table_char & 128) continue;
		switch (j)
		{
		case 0:
			*str_ptr = table_char << 2 & 252;
			break;
		case 1:
			*(str_ptr++) |= table_char >> 4 & 3;
			*str_ptr = table_char << 4 & 240;
			break;
		case 2:
			*(str_ptr++) |= table_char >> 2 & 15;
			*str_ptr = table_char << 6 & 192;
			break;
		default:
			*(str_ptr++) |= table_char & 63;
			break;
		}
	}
	*str_ptr = 0;

	static std::string final_str;
	final_str = std::string(str.get());
	return 	final_str;
}

#endif //Included AsProject Library