//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsProject Library
//
//                    Created by Gaccho (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
#if defined(__ANDROID__)
	const size_t stos(const std::string& str_) {
		if (str_.size() == 0) return 0;
		size_t s = 0;
		switch (str_[0])
		{
		case '0':s = 0; break;
		case '1':s = 1; break;
		case '2':s = 2; break;
		case '3':s = 3; break;
		case '4':s = 4; break;
		case '5':s = 5; break;
		case '6':s = 6; break;
		case '7':s = 7; break;
		case '8':s = 8; break;
		case '9':s = 9; break;
		}
		for (size_t i = 1; i < str_.size(); ++i) {
			if (SIZE_MAX / 10 < s) return SIZE_MAX;
			switch (str_[i])
			{
			case '0':s *= 10; s += 0; break;
			case '1':s *= 10; s += 1; break;
			case '2':s *= 10; s += 2; break;
			case '3':s *= 10; s += 3; break;
			case '4':s *= 10; s += 4; break;
			case '5':s *= 10; s += 5; break;
			case '6':s *= 10; s += 6; break;
			case '7':s *= 10; s += 7; break;
			case '8':s *= 10; s += 8; break;
			case '9':s *= 10; s += 9; break;
			}
		}
		return s;
}
#endif

	const int32_t asSize_t_ReadCSV(const std::string& str_, std::vector<size_t>& vec_, size_t* const x_ = nullptr, size_t* const y_ = nullptr) {
#if defined(__ANDROID__)
		constexpr size_t file_path_max = 256;
		char FilePath[file_path_max];
		DxLib::GetInternalDataPath(FilePath, sizeof(FilePath));
		std::ifstream ifs(std::string(FilePath) + u8"\\" + str_);
		if (!ifs) {
			DxLib::GetExternalDataPath(FilePath, sizeof(FilePath));
			std::ifstream ifs(std::string(FilePath) + u8"\\" + str_);
			if (!ifs) return 1;
		}
#else
		std::ifstream ifs(str_);
		if (!ifs) return 1;
#endif

		std::string str;
		size_t num = 0;
		size_t num_y = 0;

		std::string token;
		while (getline(ifs, str)) {
			std::istringstream stream(str);
			while (getline(stream, token, ',')) {
#if defined(__ANDROID__)
				vec_.emplace_back(stos(token));
#else
				vec_.emplace_back(size_t(stoull(token)));
#endif
				++num;
			}
			++num_y;
	}

		if (x_ != nullptr && num_y != 0) *x_ = num / num_y;
		if (y_ != nullptr) *y_ = num_y;

		return 0;
}

	const int32_t asSize_t_WriteCSV(const std::string& str_, const std::vector<size_t>& vec_, const size_t x_, const size_t y_, const size_t ii_ = 0) {
#if defined(__ANDROID__)
		constexpr size_t file_path_max = 256;
		char FilePath[file_path_max];
		DxLib::GetInternalDataPath(FilePath, sizeof(FilePath));
		std::ofstream ofs(std::string(FilePath) + u8"\\" + str_);
		if (!ofs) {
			DxLib::GetExternalDataPath(FilePath, sizeof(FilePath));
			std::ifstream ifs(std::string(FilePath) + u8"\\" + str_);
			if (!ofs) return 1;
		}
#else
		std::ofstream ofs(str_);
		if (!ofs) return 1;
#endif
		const size_t xy_ = ii_ + x_ * y_;
		for (size_t i = ii_, k = 1; i < xy_; ++i, ++k) {
			ofs << vec_[i] << ',';
			if (k != x_) continue;
			ofs << std::endl;
			k = 0;
		}
		return 0;
	}

	const int32_t asMapRead(const std::string& str_, std::vector<size_t>& vec_, size_t* const x_ = nullptr, size_t* const y_ = nullptr, size_t* const layer_ = nullptr) {
		size_t layer = 0;
		vec_.clear();
		while (true) {
#if defined(__ANDROID__)
			std::stringstream ss;
			ss << layer;
			if (asSize_t_ReadCSV(u8"asrpg_map_" + str_ + u8"_" + ss.str() + u8".csv", vec_, x_, y_) == 1) break;
#else
			if (asSize_t_ReadCSV(u8"asrpg_map_" + str_ + u8"_" + std::to_string(layer) + u8".csv", vec_, x_, y_) == 1) break;
#endif
			++layer;
		}
		if (layer_ != nullptr) *layer_ = layer;
		return 0;
	}

	const int32_t asMapWrite(const std::string& str_, const std::vector<size_t>& vec_, const size_t x_, const size_t y_, const size_t layer_) {
		for (size_t i = 0; i < layer_; ++i) {
#if defined(__ANDROID__)
			std::stringstream ss;
			ss << i;
			asSize_t_WriteCSV(u8"asrpg_map_" + str_ + u8"_" + ss.str() + u8".csv", vec_, x_, y_, x_*y_*i);
#else
			asSize_t_WriteCSV(u8"asrpg_map_" + str_ + u8"_" + std::to_string(i) + u8".csv", vec_, x_, y_, x_*y_*i);
#endif
		}
		return 0;
	}


	const int32_t asSize_t_MapReadCSV(const std::string& str_, std::vector<std::string>& name_, std::vector<size_t>& vec_, size_t* const x_ = nullptr, size_t* const y_ = nullptr) {

		std::string str;
		size_t num = 0;
		size_t num_y = 0;
		size_t type_id = 0;
		
		std::string token;
#if defined(__ANDROID__)

		char String[256];
		int FileHandle = DxLib::FileRead_open(str_.c_str());
		static std::string str__2;
		str__2= u8"";
		while (DxLib::FileRead_eof(FileHandle) == 0)
		{
			DxLib::FileRead_gets(String, 256, FileHandle);
			str = String;
			std::istringstream stream(str);
			type_id = 0;
			while (getline(stream, token, ',')) {
				if (type_id == 0) {
					name_.emplace_back(token);
				}
				else {
					vec_.emplace_back(stos(token));
				}
				++type_id;
				++num;
			}
			++num_y;
		}
		if (x_ != nullptr && num_y != 0) *x_ = num / num_y;
		if (y_ != nullptr) *y_ = num_y;

		DxLib::FileRead_close(FileHandle);
		if (vec_.size() != 0) return 0;

		constexpr size_t file_path_max = 256;
		char FilePath[file_path_max];
		DxLib::GetInternalDataPath(FilePath, sizeof(FilePath));
		std::ifstream ifs(std::string(FilePath) + u8"\\" + str_);
		if (!ifs) {
			DxLib::GetExternalDataPath(FilePath, sizeof(FilePath));
			std::ifstream ifs(std::string(FilePath) + u8"\\" + str_);
			if (!ifs) return 1;
		}
#else
		std::ifstream ifs(str_);
		if (!ifs) return 1;
#endif
		while (getline(ifs, str)) {
			std::istringstream stream(str);
			type_id = 0;
			while (getline(stream, token, ',')) {
				if (type_id == 0) {
					name_.emplace_back(token);
				}
				else {
#if defined(__ANDROID__)
					vec_.emplace_back(stos(token));
#else
					vec_.emplace_back(size_t(stoull(token)));
#endif

				}
				++type_id;
				++num;
			}
			++num_y;
		}

		if (x_ != nullptr && num_y != 0) *x_ = num / num_y;
		if (y_ != nullptr) *y_ = num_y;

		return 0;
	}

}
