//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsProject Library
//
//                    Created by Gaccho (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
	std::vector<size_t> vector2ToVector1(const std::vector<std::vector<size_t>>& map_) {
		static thread_local std::vector<size_t> vmap;
		const size_t i_max = map_.size();
		const size_t j_max = map_.data()->size();
		vmap.resize(i_max*j_max);
		for (size_t i = 0, k = 0; i < i_max; ++i) {
			for (size_t j = 0; j < j_max; ++j, ++k) {
				vmap[k] = map_[i][j];
			}
		}
		return vmap;
	}

	void mazeDig(std::vector<std::vector<size_t>>& map, size_t x, size_t y, const size_t aslib_maze_wall, const size_t aslib_maze_empty)
	{
		int32_t dx = 0;
		int32_t dy = 0;
		size_t r = size_t(asRand32());
		size_t c = 0;
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
				r = size_t(asRand32());
			}
		}
		return;
	}
	void mazeRoot(std::vector<std::vector<size_t>>& map, const size_t x, const size_t y, const size_t aslib_maze_empty)
	{
		static size_t b = 0;
		map[x][y] = 2;
		if (x == map.size() - 2 && y == map.data()->size() - 2) b = 1;
		//è„
		if (b != 1 && map[x][y - 1] == 0) mazeRoot(map, x, y - 1, aslib_maze_empty);
		//â∫
		if (b != 1 && map[x][y + 1] == 0) mazeRoot(map, x, y + 1, aslib_maze_empty);
		//ç∂
		if (b != 1 && map[x - 1][y] == 0) mazeRoot(map, x - 1, y, aslib_maze_empty);
		//âE
		if (b != 1 && map[x + 1][y] == 0) mazeRoot(map, x + 1, y, aslib_maze_empty);

		if (b != 1) map[x][y] = aslib_maze_empty;
		return;
	}
	//èoóÕ
	void mazeOutput(const std::vector<std::vector<size_t>>& map, const size_t aslib_maze_wall, const size_t aslib_maze_empty)
	{
		const size_t i_max = map.size();
		const size_t j_max = map.data()->size();
		for (size_t i = 0; i < i_max; ++i) {
			for (size_t j = 0; j < j_max; ++j) {
				if (map[i][j] == aslib_maze_empty)std::cout << "Å@";
				else if (map[i][j] == aslib_maze_wall)std::cout << "Å°";
				else if (map[i][j] == 2)std::cout << "ÅE";
			}
			std::cout << std::endl;
		}
	}
	//ñ¿òHê∂ê¨
	void mazeMake(std::vector<std::vector<size_t>>& map, const size_t aslib_maze_wall, const size_t aslib_maze_empty)
	{
		map[1][1] = aslib_maze_empty;

		size_t a = 0;
		size_t ii = 0;
		std::unique_ptr<size_t[]> X(new size_t[map.size()*map.data()->size()]);
		std::unique_ptr<size_t[]> Y(new size_t[map.size()*map.data()->size()]);
		while (true)
		{
			ii = 0;
			for (size_t y = 1; y < map.data()->size() - 1; y += 2) {
				for (size_t x = 1; x < map.size() - 1; x += 2) {
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
				a = size_t(asRand32()) % ii;
				mazeDig(map, X[a], Y[a], aslib_maze_wall, aslib_maze_empty);
			}
		}
		return;
	}

	std::vector<std::vector<size_t>> asMazeMapMake(const size_t size_x, const size_t size_y, const size_t aslib_maze_wall = 1, const size_t aslib_maze_empty = 0)
	{
		const size_t size_x_2 = (size_x % 2 == 1) ? size_x : size_x - 1;
		const size_t size_y_2 = (size_y % 2 == 1) ? size_y : size_y - 1;

		//ñ¿òHÉ}ÉbÉv
		static thread_local std::vector<std::vector<size_t>> map;
		map = std::vector<std::vector<size_t>>(size_x_2, std::vector<size_t>(size_y_2, aslib_maze_wall));

		//ñ¿òHÇê∂ê¨
		mazeMake(map, aslib_maze_wall, aslib_maze_empty);
		return map;
	}

	std::vector<std::vector<size_t>> asMazeMapDefault(const size_t size_x, const size_t size_y, const size_t aslib_maze_wall = 1, const size_t aslib_maze_empty = 0)
	{
		const size_t size_x_2 = (size_x % 2 == 1) ? size_x : size_x - 1;
		const size_t size_y_2 = (size_y % 2 == 1) ? size_y : size_y - 1;

		//ñ¿òHÉ}ÉbÉv
		static thread_local std::vector<std::vector<size_t>> map;
		map = std::vector<std::vector<size_t>>(size_x_2, std::vector<size_t>(size_y_2, aslib_maze_wall));
		//ñ¿òHÇê∂ê¨
		mazeMake(map, aslib_maze_wall, aslib_maze_empty);
		//åoòHíTçı
		mazeRoot(map, 1, 1, aslib_maze_empty);
		//ì¸ÇËå˚Ç∆èoå˚í«â¡
		map[1][0] = 2;
		map[size_x - 2][size_y - 1] = 2;
		//èoóÕ
		mazeOutput(map, aslib_maze_wall, aslib_maze_empty);
		return map;
	}


}
