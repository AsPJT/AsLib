//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asライブラリ
//
//                    制作者: がっちょ (wanotaitei@gmail.com)
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

		DxLib::printfDx("Old:%s\n", fp_name.c_str());

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
	const int32_t asWrite(const char* const file_name, const char* const log_)
	{
		FILE* cfp_fp;
		const errno_t cfp_error = fopen_s(&cfp_fp, file_name, "w");
		if (cfp_error) return -1;

		fputs(log_, cfp_fp);
		fclose(cfp_fp);
		return 0;
	}

	//ファイル読み込み
	const int32_t asAddWrite(const char* const file_name, const char* const log_)
	{
		FILE* cfp_fp;
		const errno_t cfp_error = fopen_s(&cfp_fp, file_name, "a");
		if (cfp_error) return -1;

		fputs(log_, cfp_fp);
		fclose(cfp_fp);
		return 0;
	}

	//Android(VS)
#elif defined(__ANDROID__)

	//ファイル読み込み
	const int32_t asWrite(const char* const file_name, const char* const log_)
	{
		constexpr size_t file_path_max = 256;
		char FilePath[file_path_max];
		DxLib::GetInternalDataPath(FilePath, sizeof(FilePath));

		const std::string fp_name = std::string(FilePath) + u8"\\" + std::string(file_name);
		FILE* const cfp_fp = fopen(fp_name.c_str(), "w");

		if (cfp_fp == nullptr) return -1;

		fputs(log_, cfp_fp);
		fclose(cfp_fp);
		return 0;
	}

	//ファイル読み込み
	const int32_t asAddWrite(const char* const file_name, const char* const log_)
	{
		constexpr size_t file_path_max = 256;
		char FilePath[file_path_max];
		DxLib::GetInternalDataPath(FilePath, sizeof(FilePath));

		const std::string fp_name = std::string(FilePath) + u8"\\" + std::string(file_name);
		FILE* const cfp_fp = fopen(fp_name.c_str(), "a");

		if (cfp_fp == nullptr) return -1;

		fputs(log_, cfp_fp);
		fclose(cfp_fp);
		return 0;
	}

#else

	//ファイル読み込み
	const int32_t asWrite(const char* const file_name, const char* const log_)
	{
		FILE* const cfp_fp = fopen(file_name, "w");
		if (cfp_fp == nullptr) return -1;

		fputs(log_, cfp_fp);
		fclose(cfp_fp);
		return 0;
	}

	//ファイル読み込み
	const int32_t asAddWrite(const char* const file_name, const char* const log_)
	{
		FILE* const cfp_fp = fopen(file_name, "a");
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
		std::string str = u8"";
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
		return std::string(it, last);
	}
#endif

}
