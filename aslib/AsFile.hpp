/*#######################################################################################
	Made by Kasugaccho
	Made by As Project
	https://github.com/Kasugaccho/AsLib
	wanotaitei@gmail.com

	This code is licensed under CC0.
#######################################################################################*/
#ifndef INCLUDED_AS_PROJECT_LIBRARY_FILE
#define INCLUDED_AS_PROJECT_LIBRARY_FILE


namespace AsLib
{
	//VS
#if defined(_MSC_VER)

	std::int32_t asSecretRead(const char* const file_name, void* const read_buf, const std::size_t read_size) noexcept
	{
#if defined(__DXLIB)
		const int FileHandle = DxLib::FileRead_open(file_name);
		if (FileHandle == 0) return -1;
		DxLib::FileRead_read(read_buf, int(read_size), int(FileHandle));
		DxLib::FileRead_close(FileHandle);
#else
		file_name; read_buf; read_size;
#endif
		return 0;
	}

	//ファイル読み込み
	std::int32_t asRead(const char* const file_name, void* const read_buf, const std::size_t read_size, const std::size_t read_nmemb) noexcept
	{
		FILE  *cfp_fp;
		const errno_t cfp_error = fopen_s(&cfp_fp, file_name, "rb");
		if (cfp_error) {
#if defined(__DXLIB)
			return (read_nmemb == 1) ? asSecretRead(file_name, read_buf, read_size) : -1;
#else 
			return -1;
#endif
		}

		fread(read_buf, read_size, read_nmemb, cfp_fp);
		fclose(cfp_fp);
		return 0;
	}

	//ファイル書き込み
	std::int32_t asWrite(const char* const file_name, void* const write_buf, const std::size_t write_size, const std::size_t write_nmemb) noexcept
	{
		FILE  *cfp_fp;
		const errno_t cfp_error = fopen_s(&cfp_fp, file_name, "wb");
		if (cfp_error) return -1;

		fwrite(write_buf, write_size, write_nmemb, cfp_fp);
		fclose(cfp_fp);
		return 0;
	}

	//Android(VS)
#elif defined(__ANDROID__)

	std::int32_t asRead(const char* const file_name, void* const read_buf, const std::size_t read_size, const std::size_t read_nmemb) noexcept
	{
		constexpr std::size_t file_path_max = 256;

		FILE  *cfp_fp;
		char FilePath[file_path_max];
		DxLib::GetInternalDataPath(FilePath, sizeof(FilePath));
		const std::string fp_name = std::string(FilePath) + "\\" + std::string(file_name);
		cfp_fp = fopen(fp_name.c_str(), "rb");

		if (cfp_fp == nullptr) return -1;

		fread(read_buf, read_size, read_nmemb, cfp_fp);
		fclose(cfp_fp);
		return 0;
	}

	std::int32_t asWrite(const char* const file_name, void* const write_buf, const std::size_t write_size, const std::size_t write_nmemb) noexcept
	{
		constexpr std::size_t file_path_max = 256;

		FILE  *cfp_fp;
		char FilePath[file_path_max];
		DxLib::GetInternalDataPath(FilePath, sizeof(FilePath));
		const std::string fp_name = std::string(FilePath) + "\\" + std::string(file_name);
		cfp_fp = fopen(fp_name.c_str(), "wb");

		if (cfp_fp == nullptr) return -1;

		fwrite(write_buf, write_size, write_nmemb, cfp_fp);
		fclose(cfp_fp);
		return 0;
	}

#else

	//ファイル読み込み
	std::int32_t asRead(const char* const file_name, void* const read_buf, const std::size_t read_size, const std::size_t read_nmemb) noexcept
	{
		FILE* const cfp_fp = fopen(file_name, "rb");
		if (cfp_fp == nullptr) return -1;

		fread(read_buf, read_size, read_nmemb, cfp_fp);
		fclose(cfp_fp);
		return 0;
	}

	//ファイル書き込み
	std::int32_t asWrite(const char* const file_name, void* const write_buf, const std::size_t write_size, const std::size_t write_nmemb) noexcept
	{
		FILE* const cfp_fp = fopen(file_name, "wb");
		if (cfp_fp == nullptr) return -1;

		fwrite(write_buf, write_size, write_nmemb, cfp_fp);
		fclose(cfp_fp);
		return 0;
	}

#endif

	//VS
#if defined(_MSC_VER)

	//ファイル読み込み
	std::int32_t asWrite(const std::string& file_name, const char* const log_) noexcept
	{
		FILE* cfp_fp;
		const errno_t cfp_error = fopen_s(&cfp_fp, file_name.c_str(), "w");
		if (cfp_error) return -1;

		fputs(log_, cfp_fp);
		fclose(cfp_fp);
		return 0;
	}

	//ファイル読み込み
	std::int32_t asAddWrite(const std::string& file_name, const char* const log_) noexcept
	{
		FILE* cfp_fp;
		const errno_t cfp_error = fopen_s(&cfp_fp, file_name.c_str(), "a");
		if (cfp_error) return -1;

		fputs(log_, cfp_fp);
		fclose(cfp_fp);
		return 0;
	}

	//Android(VS)
#elif defined(__ANDROID__)

	//ファイル読み込み
	std::int32_t asWrite(const std::string& file_name, const char* const log_) noexcept
	{
		constexpr std::size_t file_path_max = 256;
		char FilePath[file_path_max];
		DxLib::GetInternalDataPath(FilePath, sizeof(FilePath));

		const std::string fp_name = std::string(FilePath) + "\\" + file_name;
		FILE* const cfp_fp = fopen(fp_name.c_str(), "w");

		if (cfp_fp == nullptr) return -1;

		fputs(log_, cfp_fp);
		fclose(cfp_fp);
		return 0;
	}

	//ファイル読み込み
	std::int32_t asAddWrite(const std::string& file_name, const char* const log_) noexcept
	{
		constexpr std::size_t file_path_max = 256;
		char FilePath[file_path_max];
		DxLib::GetInternalDataPath(FilePath, sizeof(FilePath));

		const std::string fp_name = std::string(FilePath) + "\\" + file_name;
		FILE* const cfp_fp = fopen(fp_name.c_str(), "a");

		if (cfp_fp == nullptr) return -1;

		fputs(log_, cfp_fp);
		fclose(cfp_fp);
		return 0;
	}

#else

	//ファイル読み込み
	std::int32_t asWrite(const std::string& file_name, const char* const log_) noexcept
	{
		FILE* const cfp_fp = fopen(file_name.c_str(), "w");
		if (cfp_fp == nullptr) return -1;

		fputs(log_, cfp_fp);
		fclose(cfp_fp);
		return 0;
	}

	//ファイル読み込み
	std::int32_t asAddWrite(const std::string& file_name, const char* const log_) noexcept
	{
		FILE* const cfp_fp = fopen(file_name.c_str(), "a");
		if (cfp_fp == nullptr) return -1;

		fputs(log_, cfp_fp);
		fclose(cfp_fp);
		return 0;
	}

#endif


#if defined(__ANDROID__)
	std::string asAllRead(const char* const str_) noexcept
	{
		char String[256];
		int FileHandle = DxLib::FileRead_open(str_);
		static std::string str;
		str = "";
		while (DxLib::FileRead_eof(FileHandle) == 0)
		{
			DxLib::FileRead_gets(String, 256, FileHandle);
			str += String;
			str.push_back('\n');
		}
		DxLib::FileRead_close(FileHandle);
		return str;
	}
#else
	//ファイル読み込み
	std::string asAllRead(const char* const str_) noexcept
	{
		std::ifstream ifs(str_);
		if (ifs.fail()) return std::string("(データを読み込めませんでした)");
		std::istreambuf_iterator<char> it(ifs);
		std::istreambuf_iterator<char> last;

		static std::string final_str;
		final_str = std::string(it, last);
		return 	final_str;
	}
#endif

	inline std::string asAllReadBase64(const char* const str_) noexcept { return base64_Decode(asAllRead(str_).c_str()); }
	inline std::int32_t asAllWriteBase64(const std::string& file_name, const char* const log_) noexcept { return asWrite(file_name, base64_Encode(log_).c_str()); }
	inline std::int32_t asWriteBase64(const std::string& file_name, const char* const log_) noexcept { return asWrite(file_name, base64_Encode(log_).c_str()); }
	inline std::int32_t asAddWriteBase64(const std::string& file_name, const char* const log_) noexcept { return asAddWrite(file_name, base64_Encode(log_).c_str()); }

	std::vector<std::size_t> asAllReadToSize_t(const std::string& str_) noexcept {
		static std::vector<std::size_t> final_str;
		final_str.clear();

		const std::size_t size = sizeof(std::size_t);
		std::size_t total_size = 0;

		for (std::size_t i{}; i < str_.size(); i+=size) {
			for (std::size_t j = 0; j < size; ++j) {
				total_size <<= 8;
				total_size += str_[i + j];
			}
			final_str.emplace_back(total_size);
			total_size = 0;
		}
		return 	final_str;
	}
	
	std::vector<std::size_t> asReadArraySize_t(const char* const str_) noexcept { return asAllReadToSize_t(asAllRead(str_)); }
	std::vector<std::size_t> asReadBase64ArraySize_t(const char* const str_) noexcept { return asAllReadToSize_t(asAllReadBase64(str_)); }



	struct AsArray {
		uint64_t x{};
		uint64_t y{};
		uint64_t s{};
		std::vector<uint64_t> v;
	};

	//todo
	void asReadArray(const std::string& str_,AsArray& array_) noexcept {
		if (str_.size() < 13) return;
		array_.x = (uint64_t(str_[0]) << 24) + (uint64_t(str_[1]) << 16) + (uint64_t(str_[2]) << 8) + uint64_t(str_[3]);
		array_.y = (uint64_t(str_[4]) << 24) + (uint64_t(str_[5]) << 16) + (uint64_t(str_[6]) << 8) + uint64_t(str_[7]);
		array_.s = (uint64_t(str_[8]) << 24) + (uint64_t(str_[9]) << 16) + (uint64_t(str_[10]) << 8) + uint64_t(str_[11]);

		array_.v.resize(std::size_t(array_.x*array_.y));

	}

}

#endif //Included AsProject Library