//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asƒ‰ƒCƒuƒ‰ƒŠ
//
//                    §ìÒ: ‚ª‚Á‚¿‚å (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{

	struct Map2D
	{
	public:
		Map2D(std::unique_ptr<int32_t[]>&& map_, const size_t x_, const size_t y_) :map_id(std::move(map_)), x(x_), y(y_), xy(x_*y_) { map_id.reset(new int32_t[x_ * y_]); this->clear(); };
		Map2D(const size_t x_, const size_t y_) :x(x_), y(y_), xy(x_*y_) { map_id.reset(new int32_t[x_ * y_]); this->clear(); };
		Map2D(const size_t xy_) :x(xy_), y(1), xy(xy_) { map_id.reset(new int32_t[xy_]); this->clear(); };
		int32_t id(const size_t y_, const size_t x_) const { return this->map_id[this->x*y_ + x_]; }
		int32_t id(const size_t xy_) const { return this->map_id[xy_]; }
		void clear() { for (size_t i = 0; i < this->xy; ++i) this->map_id[i] = 0; }
		void reset(const size_t x_, const size_t y_) { this->x = x_; this->y = y_; this->xy = x_ * y_; map_id.reset(new int32_t[x_ * y_]); };

		std::unique_ptr<int32_t[]> map_id;

	private:
		size_t x;
		size_t y;
		size_t xy;
	};




}
