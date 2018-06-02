//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - As���C�u����
//
//                    �����: �������� (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
	//VS
#if defined(_MSC_VER)

	//�t�@�C���ǂݍ���
	int32_t asRead(const char* const file_name, void* const read_buf, const size_t read_size, const size_t read_nmemb)
	{
		FILE  *cfp_fp;
		const errno_t cfp_error = fopen_s(&cfp_fp, file_name, "rb");
		if (cfp_error) return -1;

		fread(read_buf, read_size, read_nmemb, cfp_fp);
		fclose(cfp_fp);
		return 0;
}

	//�t�@�C����������
	int32_t asWrite(const char* const file_name, void* const write_buf, const size_t write_size, const size_t write_nmemb)
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

	int32_t asRead(const char* const file_name, void* const read_buf, const size_t read_size, const size_t read_nmemb)
	{
		constexpr size_t file_path_max = 256;

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

	int32_t asWrite(const char* const file_name, void* const write_buf, const size_t write_size, const size_t write_nmemb)
	{
		constexpr size_t file_path_max = 256;

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

	//�t�@�C���ǂݍ���
	int32_t asRead(const char* const file_name, void* const read_buf, const size_t read_size, const size_t read_nmemb)
	{
		FILE* const cfp_fp = fopen(file_name, "rb");
		if (cfp_fp) return -1;

		fread(read_buf, read_size, read_nmemb, cfp_fp);
		fclose(cfp_fp);
		return 0;
	}

	//�t�@�C����������
	int32_t asWrite(const char* const file_name, void* const write_buf, const size_t write_size, const size_t write_nmemb)
	{
		FILE* const cfp_fp = fopen(file_name, "wb");
		if (cfp_fp) return -1;

		fwrite(write_buf, write_size, write_nmemb, cfp_fp);
		fclose(cfp_fp);
		return 0;
	}

#endif
}
