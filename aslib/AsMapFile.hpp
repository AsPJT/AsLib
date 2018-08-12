//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsProject Library
//
//                    Created by Gaccho (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{

	const int32_t asSize_t_ReadCSV(const std::string& str_, std::vector<size_t>& vec_, size_t* const x_ = nullptr, size_t* const y_ = nullptr) {
		std::ifstream ifs(str_);
		if (!ifs) return 1;

		std::string str;
		size_t num = 0;
		size_t num_y = 0;

		std::string token;
		while (getline(ifs, str)) {
			std::istringstream stream(str);
			while (getline(stream, token, ',')) {
				vec_.emplace_back(size_t(stoull(token)));
				++num;
			}
			++num_y;
	}

		if (x_ != nullptr && num_y != 0) *x_ = num / num_y;
		if (y_ != nullptr) *y_ = num_y;

		return 0;
}

	const int32_t asSize_t_WriteCSV(const std::string& str_, const std::vector<size_t>& vec_, const size_t x_, const size_t y_, const size_t ii_ = 0) {
		std::ofstream ofs(str_);
		if (!ofs) return 1;
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
			if (asSize_t_ReadCSV(u8"asrpg_map_" + str_ + u8"_" + std::to_string(layer) + u8".csv", vec_, x_, y_) == 1) break;
			++layer;
		}
		if (layer_ != nullptr) *layer_ = layer;
		return 0;
	}

	const int32_t asMapWrite(const std::string& str_, const std::vector<size_t>& vec_, const size_t x_, const size_t y_, const size_t layer_) {
		for (size_t i = 0; i < layer_; ++i) {
			asSize_t_WriteCSV(u8"asrpg_map_" + str_ + u8"_" + std::to_string(i) + u8".csv", vec_, x_, y_, x_*y_*i);
		}
		return 0;
	}

}
