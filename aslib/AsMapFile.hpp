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
	const size_t asAndroidStos(const std::string& str_) {
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

	const size_t asStos(const std::string& str_) {
#if defined(__ANDROID__)
		return asAndroidStos(str_);
#else
		return size_t(stoull(str_));
#endif
	}



	const int32_t asStreamRead(std::ifstream& ifs_, const std::string& str_) {
#if defined(__ANDROID__)
		constexpr size_t file_path_max = 256;
		std::unique_ptr<char[]> file_path(new char[file_path_max]);
		//アプリ内(内部データ)を調べる
		DxLib::GetExternalDataPath(file_path.get(), file_path_max);
		ifs_.open(std::string(file_path.get()) + u8"\\" + str_);
		if (!ifs_) {
			//本体内(外部データ)を調べる
			DxLib::GetInternalDataPath(file_path.get(), file_path_max);
			ifs_.open(std::string(file_path.get()) + u8"\\" + str_);
			if (!ifs_) return 1;
		}
#else
		ifs_.open(str_);
		if (!ifs_) return 1;
#endif
		return 0;
	}
	const int32_t asStreamWrite(std::ofstream& ofs_, const std::string& str_) {
#if defined(__ANDROID__)
		constexpr size_t file_path_max = 256;
		std::unique_ptr<char[]> file_path(new char[file_path_max]);
		//アプリ内(内部データ)を調べる
		DxLib::GetExternalDataPath(file_path.get(), file_path_max);
		ofs_.open(std::string(file_path.get()) + u8"\\" + str_);
		if (!ofs_) {
			//本体内(外部データ)を調べる
			DxLib::GetInternalDataPath(file_path.get(), file_path_max);
			ofs_.open(std::string(file_path.get()) + u8"\\" + str_);
			if (!ofs_) return 1;
		}
#else
		ofs_.open(str_);
		if (!ofs_) return 1;
#endif
		return 0;
	}

	//全てがsize_t型のcsvファイルを読み込む
	const int32_t asSize_t_ReadCSV(const std::string& str_, std::vector<size_t>& vec_, size_t* const x_ = nullptr, size_t* const y_ = nullptr) {
		//ファイル読み込み
		std::ifstream ifs;
		if (asStreamRead(ifs, str_) == 1) return 1;

		std::string str;
		size_t num = 0;
		size_t num_y = 0;

		std::string token;
		while (getline(ifs, str)) {
			std::istringstream stream(str);
			while (getline(stream, token, ',')) {
				vec_.emplace_back(asStos(token));
				++num;
			}
			++num_y;
	}
		//縦と横の長さを格納
		if (x_ != nullptr && num_y != 0) *x_ = num / num_y;
		if (y_ != nullptr) *y_ = num_y;
		return 0;
}

	const int32_t asSize_t_WriteCSV(const std::string& str_, const std::vector<size_t>& vec_, const size_t x_, const size_t y_, const size_t ii_ = 0) {
		//ファイル書き込み
		std::ofstream ofs;
		if (asStreamWrite(ofs, str_) == 1) return 1;

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
		vec_.clear();
		size_t layer = 0;
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

		if (layer == 0) return 1;
		return 0;
	}

	const int32_t asMapWrite(const std::string& str_, const std::vector<size_t>& vec_, const size_t x_, const size_t y_, const size_t layer_) {
		for (size_t i = 0; i < layer_; ++i) {
#if defined(__ANDROID__)
			std::stringstream ss;
			ss << i;
			if (asSize_t_WriteCSV(u8"asrpg_map_" + str_ + u8"_" + ss.str() + u8".csv", vec_, x_, y_, x_*y_*i) == 1) return 1;
#else
			if (asSize_t_WriteCSV(u8"asrpg_map_" + str_ + u8"_" + asSizeToString(i) + u8".csv", vec_, x_, y_, x_*y_*i) == 1) return 1;
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

#if defined(ASLIB_INCLUDE_DL)
		constexpr size_t file_path_max = 256;
		std::unique_ptr<char[]> file_path(new char[file_path_max]);
		int FileHandle = DxLib::FileRead_open(str_.c_str());
		static std::string str__2;
		str__2= u8"";
		while (DxLib::FileRead_eof(FileHandle) == 0)
		{
			DxLib::FileRead_gets(file_path.get(), file_path_max, FileHandle);
			str = std::string(file_path.get());
			std::istringstream stream(str);
			type_id = 0;
			while (getline(stream, token, ',')) {
				if (type_id == 0) name_.emplace_back(token);
				else vec_.emplace_back(asStos(token));
				++type_id;
				++num;
			}
			++num_y;
		}
		if (x_ != nullptr && num_y != 0) *x_ = num / num_y;
		if (y_ != nullptr) *y_ = num_y;

		DxLib::FileRead_close(FileHandle);
		if (vec_.size() != 0) return 0;
#endif
		//ファイル読み込み
		std::ifstream ifs;
		if (asStreamRead(ifs, str_) == 1) return 1;

		while (getline(ifs, str)) {
			std::istringstream stream(str);
			type_id = 0;
			while (getline(stream, token, ',')) {
				if (type_id == 0) name_.emplace_back(token);
				else vec_.emplace_back(asStos(token));
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
