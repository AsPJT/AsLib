/*#######################################################################################
	Made by Kasugaccho
	Made by As Project
	https://github.com/Kasugaccho/AsLib
	wanotaitei@gmail.com

	This code is licensed under CC0.
#######################################################################################*/
#ifndef INCLUDED_AS_PROJECT_LIBRARY_MAZE
#define INCLUDED_AS_PROJECT_LIBRARY_MAZE


namespace AsLib
{
	//2次元配列std::vectorから1次元配列std::vectorへ変換する
	std::vector<std::size_t> vector2ToVector1(const std::vector<std::vector<std::size_t>>& map_) noexcept {
		static thread_local std::vector<std::size_t> vmap;
		const std::size_t i_max{ map_.size() };
		const std::size_t j_max{ map_.data()->size() };
		vmap.resize(i_max*j_max);
		for (std::size_t i{}, k{}; i < i_max; ++i) {
			for (std::size_t j{}; j < j_max; ++j, ++k) {
				vmap[k] = map_[i][j];
			}
		}
		return vmap;
	}

	void mazeDig(std::vector<std::vector<std::size_t>>& map, std::size_t x, std::size_t y, const std::size_t aslib_maze_wall, const std::size_t aslib_maze_empty) noexcept
	{
		std::int32_t dx{};
		std::int32_t dy{};
		std::size_t r{ std::size_t(asRand32()) };
		std::size_t c{};
		while (c < 4) {
			switch ((r + c) % 4)
			{
			case 0:
				dx = 0;
				dy = -1;
				break;
			case 1:
				dx = -1;
				dy = 0;
				break;
			case 2:
				dx = 0;
				dy = 1;
				break;
			case 3:
				dx = 1;
				dy = 0;
				break;
			}
			if (x + dx * 2 <= 0 || y + dy * 2 <= 0 || x + dx * 2 >= map.size() - 1 || y + dy * 2 >= map.data()->size() - 1 || map[x + dx * 2][y + dy * 2] == aslib_maze_empty) {
				++c;
			}
			else if (map[x + dx * 2][y + dy * 2] == aslib_maze_wall) {
				map[x + dx][y + dy] = aslib_maze_empty;
				map[x + dx * 2][y + dy * 2] = aslib_maze_empty;
				x += dx * 2;
				y += dy * 2;
				c = 0;
				r = std::size_t(asRand32());
			}
		}
		return;
	}
	void mazeRoot(std::vector<std::vector<std::size_t>>& map, const std::size_t x, const std::size_t y, const std::size_t aslib_maze_empty) noexcept
	{
		static std::size_t b{};
		map[x][y] = 2;
		if (x == map.size() - 2 && y == map.data()->size() - 2) b = 1;
		//上
		if (b != 1 && map[x][y - 1] == 0) mazeRoot(map, x, y - 1, aslib_maze_empty);
		//下
		if (b != 1 && map[x][y + 1] == 0) mazeRoot(map, x, y + 1, aslib_maze_empty);
		//左
		if (b != 1 && map[x - 1][y] == 0) mazeRoot(map, x - 1, y, aslib_maze_empty);
		//右
		if (b != 1 && map[x + 1][y] == 0) mazeRoot(map, x + 1, y, aslib_maze_empty);

		if (b != 1) map[x][y] = aslib_maze_empty;
		return;
	}
	//出力
	void mazeOutput(const std::vector<std::vector<std::size_t>>& map, const std::size_t aslib_maze_wall, const std::size_t aslib_maze_empty) noexcept
	{
		const std::size_t i_max{ map.size() };
		const std::size_t j_max{ map.data()->size() };
		for (std::size_t i{}; i < i_max; ++i) {
			for (std::size_t j{}; j < j_max; ++j) {
				if (map[i][j] == aslib_maze_empty)std::cout << "　";
				else if (map[i][j] == aslib_maze_wall)std::cout << "■";
				else if (map[i][j] == 2)std::cout << "・";
			}
			std::cout << std::endl;
		}
	}
	//迷路生成
	void mazeMake(std::vector<std::vector<std::size_t>>& map, const std::size_t aslib_maze_wall, const std::size_t aslib_maze_empty) noexcept
	{
		map[1][1] = aslib_maze_empty;

		std::size_t a{};
		std::size_t ii{};
		std::unique_ptr<std::size_t[]> X(new std::size_t[map.size()*map.data()->size()]);
		std::unique_ptr<std::size_t[]> Y(new std::size_t[map.size()*map.data()->size()]);
		while (true)
		{
			ii = 0;
			for (std::size_t y = 1; y < map.data()->size() - 1; y += 2) {
				for (std::size_t x = 1; x < map.size() - 1; x += 2) {
					if (map[x][y] != aslib_maze_empty) continue;
					if ((x >= 2 && map[x - 2][y] == aslib_maze_wall) || (y >= 2 && map[x][y - 2] == aslib_maze_wall)) {
						X[ii] = x;
						Y[ii] = y;
						++ii;
					}
					else if ((y == map.data()->size() - 2) && (x == map.size() - 2)) break;
					else if ((x + 2 < map.size() && map[x + 2][y] == aslib_maze_wall) || (y + 2 < map.data()->size() && map[x][y + 2] == aslib_maze_wall)) {
						X[ii] = x;
						Y[ii] = y;
						++ii;
					}
				}
			}
			if (ii == 0) break;
			else {
				a = std::size_t(asRand32()) % ii;
				mazeDig(map, X[a], Y[a], aslib_maze_wall, aslib_maze_empty);
			}
		}
		return;
	}

	std::vector<std::vector<std::size_t>> asMazeMapMake(const std::size_t size_x, const std::size_t size_y, const std::size_t aslib_maze_wall = 1, const std::size_t aslib_maze_empty = 0) noexcept
	{
		const std::size_t size_x_2{ (size_x % 2 == 1) ? size_x : size_x - 1 };
		const std::size_t size_y_2{ (size_y % 2 == 1) ? size_y : size_y - 1 };

		//迷路マップ
		static thread_local std::vector<std::vector<std::size_t>> map;
		map = std::vector<std::vector<std::size_t>>(size_x_2, std::vector<std::size_t>(size_y_2, aslib_maze_wall));

		//迷路を生成
		mazeMake(map, aslib_maze_wall, aslib_maze_empty);
		return map;
	}

	std::vector<std::vector<std::size_t>> asMazeMapDefault(const std::size_t size_x, const std::size_t size_y, const std::size_t aslib_maze_wall = 1, const std::size_t aslib_maze_empty = 0) noexcept
	{
		const std::size_t size_x_2{ (size_x % 2 == 1) ? size_x : size_x - 1 };
		const std::size_t size_y_2{ (size_y % 2 == 1) ? size_y : size_y - 1 };

		//迷路マップ
		static thread_local std::vector<std::vector<std::size_t>> map;
		map = std::vector<std::vector<std::size_t>>(size_x_2, std::vector<std::size_t>(size_y_2, aslib_maze_wall));
		//迷路を生成
		mazeMake(map, aslib_maze_wall, aslib_maze_empty);
		//経路探索
		mazeRoot(map, 1, 1, aslib_maze_empty);
		//入り口と出口追加
		map[1][0] = 2;
		map[size_x - 2][size_y - 1] = 2;
		//出力
		mazeOutput(map, aslib_maze_wall, aslib_maze_empty);
		return map;
	}


	//チャンク生成
	void asWorldMapMake(const std::size_t x_, const std::size_t y_, const std::size_t size_, const std::size_t t1_, const std::size_t t2_, const std::size_t t3_, const std::size_t t4_, std::size_t map_[17][17]) noexcept
	{
		//再起の終了処理
		if (size_ == 0) return;
		//頂点の高さを決める
		const std::size_t mapPlus{ ((t1_ + t2_ + t3_ + t4_) >> 2) + asRand(static_cast<std::uint32_t>(size_)) };
		map_[x_][y_] = (mapPlus >= 255) ? 255 : mapPlus;
		//四角形の2点同士の中点の高さを決定
		const std::size_t s1{ ((t1_ + t2_) >> 1) };
		const std::size_t s2{ ((t1_ + t3_) >> 1) };
		const std::size_t s3{ ((t2_ + t4_) >> 1) };
		const std::size_t s4{ ((t3_ + t4_) >> 1) };
		//4つの地点の座標を決める
		map_[x_ + size_][y_] = s3;
		map_[x_ - size_][y_] = s2;
		map_[x_][y_ + size_] = s4;
		map_[x_][y_ - size_] = s1;
		//分割サイズを半分にする
		const std::size_t size{ size_ >> 1 };
		//4つに分割
		asWorldMapMake(x_ - size, y_ - size, size, t1_, s1, s2, map_[x_][y_], map_);
		asWorldMapMake(x_ + size, y_ - size, size, s1, t2_, map_[x_][y_], s3, map_);
		asWorldMapMake(x_ - size, y_ + size, size, s2, map_[x_][y_], t3_, s4, map_);
		asWorldMapMake(x_ + size, y_ + size, size, map_[x_][y_], s3, s4, t4_, map_);
	}

	//チャンク生成の呼び出し
	inline void asWorldMapSimple(std::size_t map_[17][17]) noexcept
	{
		//チャンク生成を実行
		asWorldMapMake(8, 8, 8, map_[0][0], map_[16][0], map_[0][16], map_[16][16], map_);
	}

	constexpr std::size_t aslib_world_make_seed1{ 0x3220 };
	constexpr std::size_t aslib_world_make_seed2{ 0x292 };

	//ワールドマップ生成
	void asWorldMake(std::vector<std::vector<std::size_t>>& world_map, std::size_t seed_ = 0) noexcept
	{
		if (seed_ == 0) seed_ = asRand(65535);
		static std::size_t map_[17][17]{};
		
		//横画面サイズ
		const std::size_t map_x{ world_map.size() };
		//縦画面サイズ
		const std::size_t map_y{ world_map.front().size() };

		const std::size_t chunk_x{ (map_x >> 4) };
		const std::size_t chunk_y{ (map_y >> 4) };

		for (std::size_t i{}; i < chunk_x; ++i) {
			for (std::size_t j{}; j < chunk_y; ++j) {

				//四角形の4点の高さを決定
				asSRand32(static_cast<std::uint32_t>(seed_ + i + (j * aslib_world_make_seed1) + ((i^j) * aslib_world_make_seed2)));
				map_[0][0] = asRand(255);
				asSRand32(static_cast<std::uint32_t>(seed_ + ((i + 1) % chunk_x) + (j * aslib_world_make_seed1) + ((((i + 1) % chunk_x) ^ j) * aslib_world_make_seed2)));
				map_[16][0] = asRand(255);
				asSRand32(static_cast<std::uint32_t>(seed_ + i + (((j + 1) % chunk_y) * aslib_world_make_seed1) + ((i ^ ((j + 1) % chunk_y)) * aslib_world_make_seed2)));
				map_[0][16] = asRand(255);
				asSRand32(static_cast<std::uint32_t>(seed_ + ((i + 1) % chunk_x) + (((j + 1) % chunk_y) * aslib_world_make_seed1) + ((((i + 1) % chunk_x) ^ ((j + 1) % chunk_y)) * aslib_world_make_seed2)));
				map_[16][16] = asRand(255);

				//チャンク生成
				asWorldMapSimple(map_);

				//生成したチャンクをワールドマップにコピペ
				for (std::size_t i2{}; i2 < 16; ++i2)
					for (std::size_t j2{}; j2 < 16; ++j2)
						world_map[(i << 4) + i2][(j << 4) + j2] = map_[i2][j2];

			}
		}
	}

	//世界をIDへ変換
	void asWorldMapSimplePaint(std::vector<std::size_t>& vec_, const std::size_t& x_, const std::size_t& y_, std::size_t& layer_, const std::size_t under_, const std::size_t sea_, const std::size_t green_, const std::size_t snow_, const std::size_t seed_ = 0) noexcept {
		std::vector<std::vector<std::size_t>> wmap(x_, std::vector<std::size_t>(y_, 255));
		//wmap = std::vector<std::vector<std::size_t>>(x_, std::vector<std::size_t>(y_, 255));
		//wmap.shrink_to_fit();

		asWorldMake(wmap, seed_);

		const std::size_t xy_{ x_ * y_ };

		layer_ = 2;
		vec_.resize(xy_ * layer_);
		for (std::size_t i{}; i < xy_; ++i) {
			vec_[i] = under_;
		}

		const std::size_t xyl_{ xy_ * layer_ };
		for (std::size_t k{ xy_ }, i{}, j = 0; k < xyl_; ++k, ++j) {
			if (x_ <= j) {
				j = 0;
				++i;
			}
			//ワールドマップの線画
			if (wmap[i][j] <= 110 && wmap[i][j] > 50) continue;
			else if (wmap[i][j] < 15) {
				vec_[k] = snow_;
			}//内陸
			else if (wmap[i][j] <= 50) {
				vec_[k] = green_;
			}
			else {//海
				vec_[k] = sea_;
			}
		}
	}


	struct AsPaintLine {
		std::size_t lx{};
		std::size_t rx{};
		std::size_t y{};
		std::size_t oy{};
	};

	static AsPaintLine *end_b = nullptr;
	void asPaintScanLine(std::vector<std::size_t>& map_, const std::size_t size_x_, std::unique_ptr<AsPaintLine[]>& buffer_, const std::size_t b_max_, std::int32_t lx_, const std::int32_t rx_, const std::size_t y_, const std::size_t oy_, const std::size_t id_) noexcept
	{
		while (lx_ <= rx_) {

			for (; lx_ < rx_; ++lx_) {
				if (map_[y_*size_x_ + lx_] == id_) break;
			}
			if (map_[y_*size_x_ + lx_] != id_) break;

			end_b->lx = lx_;

			for (; lx_ <= rx_; ++lx_) {
				if (map_[y_*size_x_ + lx_] != id_) break;
			}

			end_b->rx = lx_ - 1;
			end_b->y = y_;
			end_b->oy = oy_;

			if (++end_b == &buffer_[b_max_]) end_b = buffer_.get();
		}
	}

	struct AsPaintSave {
		std::size_t x{};
		std::size_t y{};
		std::size_t before_id{};
		std::size_t after_id{};
		AsPaintSave() = default;
		AsPaintSave(const std::size_t x_, const std::size_t y_, const std::size_t bid_, const std::size_t aid_)
			:x(x_), y(y_), before_id(bid_), after_id(aid_) {}
	};
	struct AsPaintSaveAll {
	private:
		std::vector<AsPaintSave> save;
	public:
		void push(const std::size_t x_, const std::size_t y_, const std::size_t bid_, const std::size_t aid_) noexcept {
			save.emplace_back(x_, y_, bid_, aid_);
		}
	};

	//塗りツール
	void asPaintTool(std::vector<std::size_t>& map_, const std::size_t size_x_, const std::size_t x_, const std::size_t y_, const std::size_t id_, AsPaintSaveAll* const save_=nullptr) noexcept
	{
		const std::size_t size_y_{ map_.size() / size_x_ };
		const std::size_t map_xy{ (size_x_ >= size_y_) ? size_x_ : size_y_ };
		const std::size_t map_x{ size_x_ - 1 };
		const std::size_t map_y{ size_y_ - 1 };

		std::unique_ptr<AsPaintLine[]> buffer(new AsPaintLine[map_xy]);
		AsPaintLine *start_b{ buffer.get() };

		const std::size_t col{ map_[y_*size_x_ + x_] };
		if (col == id_) return;

		end_b = buffer.get() + 1;
		start_b->lx = start_b->rx = x_;
		start_b->y = start_b->oy = y_;

		std::size_t lx, rx;
		do {
			lx = start_b->lx;
			rx = start_b->rx;
			std::size_t& ly{ start_b->y };
			std::size_t& oy{ start_b->oy };

			const std::size_t lxsav{ lx - 1 };
			const std::size_t rxsav{ rx + 1 };

			if (++start_b == &buffer[map_xy]) start_b = buffer.get();	

			if (map_[ly*size_x_ + lx] != col)
				continue;

			while (rx < map_x) {
				if (map_[ly*size_x_ + rx + 1] != col) break;
				++rx;
			}
			while (lx > 0) {//x_
				if (map_[ly*size_x_ + lx - 1] != col) break;
				--lx;
			}
			for (std::size_t i{ lx }; i <= rx; ++i) {
				map_[ly*size_x_ + i] = id_;
				if (save_ != nullptr) save_->push(i, ly, map_[ly*size_x_ + i], id_);
			}

			if (ly >= 1) {//y_
				if (ly == oy + 1) {
					asPaintScanLine(map_, size_x_, buffer, map_xy, static_cast<std::int32_t>(lx), static_cast<std::int32_t>(lxsav), ly - 1, ly, col);
					asPaintScanLine(map_, size_x_, buffer, map_xy, static_cast<std::int32_t>(rxsav), static_cast<std::int32_t>(rx), ly - 1, ly, col);
				}
				else {
					asPaintScanLine(map_, size_x_, buffer, map_xy, static_cast<std::int32_t>(lx), static_cast<std::int32_t>(rx), ly - 1, ly, col);
				}
			}

			if (ly + 1 <= map_y) {
				if (ly + 1 == oy) {
					asPaintScanLine(map_, size_x_, buffer, map_xy, static_cast<std::int32_t>(lx), static_cast<std::int32_t>(lxsav), ly + 1, ly, col);
					asPaintScanLine(map_, size_x_, buffer, map_xy, static_cast<std::int32_t>(rxsav), static_cast<std::int32_t>(rx), ly + 1, ly, col);
				}
				else {
					asPaintScanLine(map_, size_x_, buffer, map_xy, static_cast<std::int32_t>(lx), static_cast<std::int32_t>(rx), static_cast<std::int32_t>(ly) + 1, ly, col);
				}
			}

		} while (start_b != end_b);
	}

}

#endif //Included AsProject Library