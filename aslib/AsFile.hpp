//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsProject Library
//
//                    Created by Gaccho (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
	//VS
#if defined(_MSC_VER)

	const int32_t asSecretRead(const char* const file_name, void* const read_buf, const size_t read_size)
	{
#if defined(__DXLIB)
		const int FileHandle = DxLib::FileRead_open(file_name);
		if (FileHandle == 0) return -1;
		DxLib::FileRead_read(read_buf, int(read_size), int(FileHandle));
		DxLib::FileRead_close(FileHandle);
#endif
		return 0;
	}

	//ファイル読み込み
	const int32_t asRead(const char* const file_name, void* const read_buf, const size_t read_size, const size_t read_nmemb)
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
	const int32_t asWrite(const char* const file_name, void* const write_buf, const size_t write_size, const size_t write_nmemb)
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

	const int32_t asRead(const char* const file_name, void* const read_buf, const size_t read_size, const size_t read_nmemb)
	{
		constexpr size_t file_path_max = 256;

		FILE  *cfp_fp;
		char FilePath[file_path_max];
		DxLib::GetInternalDataPath(FilePath, sizeof(FilePath));

		const std::string fp_name = std::string(FilePath) + u8"\\" + std::string(file_name);
		cfp_fp = fopen(fp_name.c_str(), "rb");

		if (cfp_fp == nullptr) return -1;

		fread(read_buf, read_size, read_nmemb, cfp_fp);
		fclose(cfp_fp);
		return 0;
	}

	const int32_t asWrite(const char* const file_name, void* const write_buf, const size_t write_size, const size_t write_nmemb)
	{
		constexpr size_t file_path_max = 256;

		FILE  *cfp_fp;
		char FilePath[file_path_max];
		DxLib::GetInternalDataPath(FilePath, sizeof(FilePath));

		const std::string fp_name = std::string(FilePath) + u8"\\" + std::string(file_name);
		cfp_fp = fopen(fp_name.c_str(), "wb");

		if (cfp_fp == nullptr) return -1;

		fwrite(write_buf, write_size, write_nmemb, cfp_fp);
		fclose(cfp_fp);
		return 0;
	}

#else

	//ファイル読み込み
	const int32_t asRead(const char* const file_name, void* const read_buf, const size_t read_size, const size_t read_nmemb)
	{
		FILE* const cfp_fp = fopen(file_name, "rb");
		if (cfp_fp == nullptr) return -1;

		fread(read_buf, read_size, read_nmemb, cfp_fp);
		fclose(cfp_fp);
		return 0;
	}

	//ファイル書き込み
	const int32_t asWrite(const char* const file_name, void* const write_buf, const size_t write_size, const size_t write_nmemb)
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
	const int32_t asWrite(const std::string& file_name, const char* const log_)
	{
		FILE* cfp_fp;
		const errno_t cfp_error = fopen_s(&cfp_fp, file_name.c_str(), "w");
		if (cfp_error) return -1;

		fputs(log_, cfp_fp);
		fclose(cfp_fp);
		return 0;
	}

	//ファイル読み込み
	const int32_t asAddWrite(const std::string& file_name, const char* const log_)
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
	const int32_t asWrite(const std::string& file_name, const char* const log_)
	{
		constexpr size_t file_path_max = 256;
		char FilePath[file_path_max];
		DxLib::GetInternalDataPath(FilePath, sizeof(FilePath));

		const std::string fp_name = std::string(FilePath) + u8"\\" + file_name;
		FILE* const cfp_fp = fopen(fp_name.c_str(), "w");

		if (cfp_fp == nullptr) return -1;

		fputs(log_, cfp_fp);
		fclose(cfp_fp);
		return 0;
	}

	//ファイル読み込み
	const int32_t asAddWrite(const std::string& file_name, const char* const log_)
	{
		constexpr size_t file_path_max = 256;
		char FilePath[file_path_max];
		DxLib::GetInternalDataPath(FilePath, sizeof(FilePath));

		const std::string fp_name = std::string(FilePath) + u8"\\" + file_name;
		FILE* const cfp_fp = fopen(fp_name.c_str(), "a");

		if (cfp_fp == nullptr) return -1;

		fputs(log_, cfp_fp);
		fclose(cfp_fp);
		return 0;
	}

#else

	//ファイル読み込み
	const int32_t asWrite(const std::string& file_name, const char* const log_)
	{
		FILE* const cfp_fp = fopen(file_name.c_str(), "w");
		if (cfp_fp == nullptr) return -1;

		fputs(log_, cfp_fp);
		fclose(cfp_fp);
		return 0;
	}

	//ファイル読み込み
	const int32_t asAddWrite(const std::string& file_name, const char* const log_)
	{
		FILE* const cfp_fp = fopen(file_name.c_str(), "a");
		if (cfp_fp == nullptr) return -1;

		fputs(log_, cfp_fp);
		fclose(cfp_fp);
		return 0;
	}

#endif


#if defined(__ANDROID__)
	const std::string asAllRead(const char* const str_)
	{
		char String[256];
		int FileHandle = DxLib::FileRead_open(str_);
		static thread_local std::string str;
		str = u8"";
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
	const std::string asAllRead(const char* const str_)
	{
		std::ifstream ifs(str_);
		if (ifs.fail()) return std::string(u8"(データを読み込めませんでした)");
		std::istreambuf_iterator<char> it(ifs);
		std::istreambuf_iterator<char> last;

		static thread_local std::string final_str;
		final_str = std::string(it, last);
		return 	final_str;
	}
#endif

	inline const std::string asAllReadBase64(const char* const str_) { return base64_Decode(asAllRead(str_).c_str()); }
	inline int32_t asAllWriteBase64(const std::string& file_name, const char* const log_) { return asWrite(file_name, base64_Encode(log_).c_str()); }
	inline int32_t asWriteBase64(const std::string& file_name, const char* const log_) { return asWrite(file_name, base64_Encode(log_).c_str()); }
	inline int32_t asAddWriteBase64(const std::string& file_name, const char* const log_) { return asAddWrite(file_name, base64_Encode(log_).c_str()); }

	const std::vector<size_t> asAllReadToSize_t(const std::string& str_) {
		static thread_local std::vector<size_t> final_str;
		final_str.resize(0);

		const size_t size = sizeof(size_t);
		size_t total_size = 0;

		for (size_t i = 0; i < str_.size(); i+=size) {
			for (size_t j = 0; j < size; ++j) {
				total_size <<= 8;
				total_size += str_[i + j];
			}
			final_str.emplace_back(total_size);
			total_size = 0;
		}
		return 	final_str;
	}
	
	const std::vector<size_t> asReadArraySize_t(const char* const str_) { return asAllReadToSize_t(asAllRead(str_)); }
	const std::vector<size_t> asReadBase64ArraySize_t(const char* const str_) { return asAllReadToSize_t(asAllReadBase64(str_)); }



	struct AsArray {
		uint64_t x = 0;
		uint64_t y = 0;
		uint64_t s = 0;
		std::vector<uint64_t> v;
	};

	//todo
	void asReadArray(const std::string& str_,AsArray& array_) {
		if (str_.size() < 13) return;
		array_.x = (uint64_t(str_[0]) << 24) + (uint64_t(str_[1]) << 16) + (uint64_t(str_[2]) << 8) + uint64_t(str_[3]);
		array_.y = (uint64_t(str_[4]) << 24) + (uint64_t(str_[5]) << 16) + (uint64_t(str_[6]) << 8) + uint64_t(str_[7]);
		array_.s = (uint64_t(str_[8]) << 24) + (uint64_t(str_[9]) << 16) + (uint64_t(str_[10]) << 8) + uint64_t(str_[11]);

		array_.v.resize(size_t(array_.x*array_.y));

	}

}
