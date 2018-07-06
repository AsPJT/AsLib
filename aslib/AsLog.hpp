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

	//ファイル読み込み
	const int32_t asWrite(const char* const file_name, const char* const log_)
	{
		FILE* cfp_fp;
		const errno_t cfp_error = fopen_s(&cfp_fp, file_name, "w");
		if (cfp_error) return -1;

		fprintf(cfp_fp, log_);
		fclose(cfp_fp);
		return 0;
	}

	//ファイル読み込み
	const int32_t asAddWrite(const char* const file_name, const char* const log_)
	{
		FILE* cfp_fp;
		const errno_t cfp_error = fopen_s(&cfp_fp, file_name, "a");
		if (cfp_error) return -1;

		fprintf(cfp_fp, log_);
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

		const std::string fp_name = std::string(FilePath) + "\\" + std::string(file_name);
		FILE* const cfp_fp = fopen(fp_name.c_str(), "w");

		if (cfp_fp == nullptr) return -1;

		fprintf(cfp_fp, log_);
		fclose(cfp_fp);
		return 0;
	}

	//ファイル読み込み
	const int32_t asAddWrite(const char* const file_name, const char* const log_)
	{
		constexpr size_t file_path_max = 256;
		char FilePath[file_path_max];
		DxLib::GetInternalDataPath(FilePath, sizeof(FilePath));

		const std::string fp_name = std::string(FilePath) + "\\" + std::string(file_name);
		FILE* const cfp_fp = fopen(fp_name.c_str(), "a");

		if (cfp_fp == nullptr) return -1;

		fprintf(cfp_fp, log_);
		fclose(cfp_fp);
		return 0;
}

#else

	//ファイル読み込み
	const int32_t asWrite(const char* const file_name, const char* const log_)
	{
		FILE* const cfp_fp = fopen(file_name, "w");
		if (cfp_fp == nullptr) return -1;

		fprintf(cfp_fp, log_);
		fclose(cfp_fp);
		return 0;
	}

	//ファイル読み込み
	const int32_t asAddWrite(const char* const file_name, const char* const log_)
	{
		FILE* const cfp_fp = fopen(file_name, "a");
		if (cfp_fp == nullptr) return -1;

		fprintf(cfp_fp, log_);
		fclose(cfp_fp);
		return 0;
	}

#endif

	const int32_t makeLog()
	{
		asWrite("log.html", "<!DOCTYPE html><html lang=\"ja\"><head><meta charset=\"UTF-8\"/>");
		asAddWrite("log.html", "<title>test</title>");
		asAddWrite("log.html", "</head><body>");
		asAddWrite("log.html", "<h2>test</h2><br><h3>Licenses</h3>");

		asAddWrite("log.html", "</body></html>");


		return 0;
	}

}
