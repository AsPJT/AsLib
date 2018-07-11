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

		const std::string fp_name = std::string(FilePath) + u8"\\" + std::string(file_name);
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

		const std::string fp_name = std::string(FilePath) + u8"\\" + std::string(file_name);
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

	const int32_t makeLog(const char* const str_)
	{
		//タイトルのサイズ
		constexpr size_t aslib_title_size = 256;
		char title_str[aslib_title_size];

		asWrite(str_, u8"<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"/>");
		snprintf(title_str, aslib_title_size, u8"<title>%s</title>", asTitle());
		asAddWrite(str_, title_str);
		asAddWrite(str_, u8"<style>body{background-color:#f9f9f9;font-family:'SegoeUI','メイリオ','Meiryo','ヒラギノ角ゴProW3','HiraginoKakuGothicPro','Osaka','ＭＳＰゴシック','MSPGothic','Arial',sans-serif;}h2{color:#333333;text-align:center;font-size:28px;}h3{color:#333333;text-align:center;font-size:24px;}main{font-size:14px;line-height:2;word-wrap:break-word;}main.name{color:#333333;text-align:center;font-size:20px;}main.copyright{padding-bottom:8px;color:#555555;text-align:center;font-size:12px;}main.license{padding-bottom:24px;color:#888888;text-align:center;font-size:9px;}</style></head><body>");
		snprintf(title_str, aslib_title_size, u8"<h2>%s</h2><br><h3>Licenses</h3>", asTitle());
		asAddWrite(str_, title_str);

		std::string license_name = u8"";
		std::vector<Copyright> license_copyright;
		std::string license_str = u8"";
		for (size_t i = 0; i < aslib_license_size; ++i) {
			license_copyright.clear();
			asLicense(aslib_license[i], license_name, license_copyright, license_str);

			asAddWrite(str_, u8"<main class=\"name\">");
			asAddWrite(str_, license_name.c_str());
			asAddWrite(str_, u8"</main>");

			for (size_t j = 0; j < license_copyright.size(); ++j) {
				asAddWrite(str_, u8"<main class=\"copyright\">");
				asAddWrite(str_, license_copyright[j].write());
				asAddWrite(str_, u8"</main>");
			}

			asAddWrite(str_, u8"<main class=\"license\">");
			asAddWrite(str_, license_str.c_str());
			asAddWrite(str_, u8"</main>");
		}

		asAddWrite(str_, u8"</body></html>");
		return 0;
	}

	const int32_t makeLog() {
		char str[256];
		snprintf(str, 256, u8"%s_Licenses.html", asTitle());
		return makeLog(str);
	}
}
