//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asƒ‰ƒCƒuƒ‰ƒŠ
//
//                    §ìÒ: ‚ª‚Á‚¿‚å (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
	struct Map2D1Byte
	{
		uint8_t* id;
	};
	
	struct Map3D
	{
	public:
		Map3D& resize(const size_t, const size_t, const size_t);
		Map3D& resize(const size_t, const size_t);
		Map3D& resize(const size_t);

		size_t H() const { return h_max; };
		size_t Y() const { return y_max; };
		size_t X() const { return x_max; };

	private:
		std::vector<std::vector<std::vector<bool> > > a;

		size_t h_max = 0;
		size_t y_max = 0;
		size_t x_max = 0;

	};

	inline Map3D& Map3D::resize(const size_t add_xyh_max)
	{
		return this->resize(add_xyh_max, add_xyh_max, add_xyh_max);
	}

	inline Map3D& Map3D::resize(const size_t add_xy_max, const size_t add_h_max)
	{
		return this->resize(add_xy_max, add_xy_max, add_h_max);
	}

	inline Map3D& Map3D::resize(const size_t add_x_max, const size_t add_y_max, const size_t add_h_max)
	{
		h_max = add_h_max;
		y_max = add_y_max;
		x_max = add_x_max;

		a.resize(h_max);
		for (size_t i = 0; i < h_max; ++i) {
			a[i].resize(y_max);
			for (size_t j = 0; j < y_max; ++j) {
				a[i][j].resize(x_max);
			}
		}
	}



#if defined(ASLIB_INCLUDE_DL) //DxLib

#elif defined(ASLIB_INCLUDE_S3) //Siv3D

#else //Console

#endif

}
