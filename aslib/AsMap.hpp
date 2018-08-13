//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsProject Library
//
//                    Created by Gaccho (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
	//イベント起動
	enum :size_t {
		aslib_event_init_touch,
		aslib_event_init_tolk,
		aslib_event_auto,
		aslib_event_timer,
	};

	//イベントタイプ
	enum :size_t {
	aslib_event_type_empty,
	aslib_event_type_talk,
	};




	//属性
	enum :size_t {
		aslib_pass_true,
		aslib_pass_false,
		aslib_pass_no_wall_false,
	};
	//デフォルト属性
	enum :size_t {
		aslib_attribute_human,
		aslib_attribute_fish,
		aslib_attribute_bird,
		aslib_attribute_ghost,
		aslib_attribute_magma,
		aslib_attribute_no,
		aslib_attribute_num
	};
	//フィールドタイプ
	enum :size_t {
		aslib_texture_map_field_type_empty,
		aslib_texture_map_field_type_wall,
		aslib_texture_map_field_type_water,
		aslib_texture_map_field_type_keep_out,
	};

	constexpr size_t aslib_default_field_attribute_empty[aslib_attribute_num] = {
		aslib_pass_true,
		aslib_pass_true,
		aslib_pass_true,
		aslib_pass_true,
		aslib_pass_true,
		aslib_pass_false
	};
	constexpr size_t aslib_default_field_attribute_wall[aslib_attribute_num] = {
		aslib_pass_false,
		aslib_pass_false,
		aslib_pass_false,
		aslib_pass_true,
		aslib_pass_false,
		aslib_pass_false
	};
	constexpr size_t aslib_default_field_attribute_water[aslib_attribute_num] = {
		aslib_pass_no_wall_false,
		aslib_pass_true,
		aslib_pass_true,
		aslib_pass_true,
		aslib_pass_no_wall_false,
		aslib_pass_false
	};
	constexpr size_t aslib_default_field_attribute_keep_out[aslib_attribute_num] = {
		aslib_pass_false,
		aslib_pass_false,
		aslib_pass_false,
		aslib_pass_false,
		aslib_pass_false,
		aslib_pass_false
	};
	constexpr size_t aslib_default_field_attribute_magma[aslib_attribute_num] = {
		aslib_pass_no_wall_false,
		aslib_pass_no_wall_false,
		aslib_pass_true,
		aslib_pass_true,
		aslib_pass_true,
		aslib_pass_false
	};

	//dir_move
	enum :size_t
	{
		MOB_DOWN_MOVE1,
		MOB_DOWN_STOP,
		MOB_DOWN_MOVE2,
		MOB_LEFT_DOWN_MOVE1,
		MOB_LEFT_DOWN_STOP,
		MOB_LEFT_DOWN_MOVE2,
		MOB_LEFT_MOVE1,
		MOB_LEFT_STOP,
		MOB_LEFT_MOVE2,
		MOB_RIGHT_DOWN_MOVE1,
		MOB_RIGHT_DOWN_STOP,
		MOB_RIGHT_DOWN_MOVE2,
		MOB_RIGHT_MOVE1,
		MOB_RIGHT_STOP,
		MOB_RIGHT_MOVE2,
		MOB_LEFT_UP_MOVE1,
		MOB_LEFT_UP_STOP,
		MOB_LEFT_UP_MOVE2,
		MOB_UP_MOVE1,
		MOB_UP_STOP,
		MOB_UP_MOVE2,
		MOB_RIGHT_UP_MOVE1,
		MOB_RIGHT_UP_STOP,
		MOB_RIGHT_UP_MOVE2,
	};

	//move
	enum :size_t
	{
		MOB_STOP,//静止
		MOB_MOVE1,//左足
		MOB_MOVE2,//真ん中
		MOB_MOVE3,//右足
		MOB_MOVE4,//真ん中
	};

	enum :size_t {
		aslib_mob_walk_type_small,
		aslib_mob_walk_type_big,
	};

	enum :size_t {
		aslib_texture_map_type_empty,
		aslib_texture_map_type_1n,
		aslib_texture_map_type_20n,
	};
	//描画タイプ
	enum :size_t {
		MAP_VIEW_DRAW_COLOR,
		MAP_VIEW_DRAW_ANIME,
	};

	//属性数を記録
	const size_t asAttributeSave(const bool b_, const size_t p_ = 0)
	{
		static thread_local size_t p = 1;
		if (b_) p = p_;
		return p;
	}
	//属性数を取得する関数
	inline const size_t asAttribute() { return asAttributeSave(false); }
	inline const size_t asSetAttribute(const size_t p_ = 0) { return asAttributeSave(true, p_); }

	const size_t mobMoveDirect(const size_t mob_direct_id, const size_t mob_move_id)
	{
		switch (mob_move_id)
		{
		case MOB_STOP:
			switch (mob_direct_id) {
			case MOB_DOWN:return MOB_DOWN_STOP;
			case MOB_UP:return MOB_UP_STOP;
			case MOB_LEFT:return MOB_LEFT_STOP;
			case MOB_RIGHT:return MOB_RIGHT_STOP;
			case MOB_LEFT_UP:return MOB_LEFT_UP_STOP;
			case MOB_RIGHT_UP:return MOB_RIGHT_UP_STOP;
			case MOB_LEFT_DOWN:return MOB_LEFT_DOWN_STOP;
			case MOB_RIGHT_DOWN:return MOB_RIGHT_DOWN_STOP;
			}
			return 0;
		case MOB_MOVE1:
			switch (mob_direct_id) {
			case MOB_DOWN:return MOB_DOWN_MOVE1;
			case MOB_UP:return MOB_UP_MOVE1;
			case MOB_LEFT:return MOB_LEFT_MOVE1;
			case MOB_RIGHT:return MOB_RIGHT_MOVE1;
			case MOB_LEFT_UP:return MOB_LEFT_UP_MOVE1;
			case MOB_RIGHT_UP:return MOB_RIGHT_UP_MOVE1;
			case MOB_LEFT_DOWN:return MOB_LEFT_DOWN_MOVE1;
			case MOB_RIGHT_DOWN:return MOB_RIGHT_DOWN_MOVE1;
			}
			return 0;
		case MOB_MOVE2:
			switch (mob_direct_id) {
			case MOB_DOWN:return MOB_DOWN_STOP;
			case MOB_UP:return MOB_UP_STOP;
			case MOB_LEFT:return MOB_LEFT_STOP;
			case MOB_RIGHT:return MOB_RIGHT_STOP;
			case MOB_LEFT_UP:return MOB_LEFT_UP_STOP;
			case MOB_RIGHT_UP:return MOB_RIGHT_UP_STOP;
			case MOB_LEFT_DOWN:return MOB_LEFT_DOWN_STOP;
			case MOB_RIGHT_DOWN:return MOB_RIGHT_DOWN_STOP;
			}
			return 0;
		case MOB_MOVE3:
			switch (mob_direct_id) {
			case MOB_DOWN:return MOB_DOWN_MOVE2;
			case MOB_UP:return MOB_UP_MOVE2;
			case MOB_LEFT:return MOB_LEFT_MOVE2;
			case MOB_RIGHT:return MOB_RIGHT_MOVE2;
			case MOB_LEFT_UP:return MOB_LEFT_UP_MOVE2;
			case MOB_RIGHT_UP:return MOB_RIGHT_UP_MOVE2;
			case MOB_LEFT_DOWN:return MOB_LEFT_DOWN_MOVE2;
			case MOB_RIGHT_DOWN:return MOB_RIGHT_DOWN_MOVE2;
			}
			return 0;
		case MOB_MOVE4:
			switch (mob_direct_id) {
			case MOB_DOWN:return MOB_DOWN_STOP;
			case MOB_UP:return MOB_UP_STOP;
			case MOB_LEFT:return MOB_LEFT_STOP;
			case MOB_RIGHT:return MOB_RIGHT_STOP;
			case MOB_LEFT_UP:return MOB_LEFT_UP_STOP;
			case MOB_RIGHT_UP:return MOB_RIGHT_UP_STOP;
			case MOB_LEFT_DOWN:return MOB_LEFT_DOWN_STOP;
			case MOB_RIGHT_DOWN:return MOB_RIGHT_DOWN_STOP;
			}
			return 0;
		}
		return 0;
	}







	//マップサイズを変更する
	template<typename Map_> void mapSize(const Pos2& b_, const Pos2& a_, Map_* m_, const Map_ count_ = Map_(0))
	{
		if (b_.is_minus() || a_.is_minus()) return;
		const int32_t b_max = b_.x*b_.y;
		const int32_t a_max = a_.x*a_.y;

		//空白部分を任意の数字で埋める
		for (int32_t i = b_max; i < a_max; ++i) m_[i] = count_;

		if (a_.x > b_.x) {
			//値を移動
			const int32_t f = ((a_.x < b_.x) ? (a_.x - 1) : (b_.x - 1));
			for (int32_t i = b_max - b_.x, ii = (a_.x*b_.y) - a_.x; i > 0; i -= b_.x, ii -= a_.x) {
				for (int32_t j = f; j >= 0; --j) {
					m_[ii + j] = m_[i + j];
					m_[i + j] = count_;
				}
			}
		}
		else if (a_.x < b_.x) {
			//値を移動
			const int32_t f = ((a_.x < b_.x) ? (a_.x) : (b_.x));
			for (int32_t i = b_.x, ii = a_.x; i < b_max; i += b_.x, ii += a_.x) {
				for (int32_t j = 0; j < f; ++j) {
					m_[ii + j] = m_[i + j];
					m_[i + j] = count_;
				}
			}
		}
		return;
	}
	//マップサイズを変更する(Vector)
	template<typename Map_> void mapSize(const Pos2& b_, const Pos2& a_, std::vector<Map_>& m_, const Map_ count_ = Map_(0))
	{
		if (b_.is_minus() || a_.is_minus()) return;
		//const int32_t b_max = b_.x*b_.y;
		//const int32_t a_max = a_.x*a_.y;
		if (a_.x >= b_.x) {
			m_.resize(a_.x*a_.y);
			mapSize(b_, a_, m_.data(), count_);
		}
		else if (b_.x > a_.x) {
			mapSize(b_, a_, m_.data(), count_);
			m_.resize(a_.x*a_.y);
		}
		return;
	}
	//動く判定
	const bool moveMob(const bool d_, const bool u_, const bool l_, const bool r_, const float s_, PosA4F& p_)
	{
		size_t count = 0;
		if (d_) ++count;
		if (u_) ++count;
		if (l_) ++count;
		if (r_) ++count;

		switch (count)
		{
		case 1:
			if (d_) p_.y += s_;
			else if (u_) p_.y -= s_;
			else if (l_) p_.x -= s_;
			else if (r_) p_.x += s_;
			return true;
		case 2:
			const float sqrt_s = s_ / sqrt(2.0f);
			if (d_) p_.y += sqrt_s;
			if (u_) p_.y -= sqrt_s;
			if (l_) p_.x -= sqrt_s;
			if (r_) p_.x += sqrt_s;
			return true;
		}
		return false;
	}
	//動く判定
	const size_t moveMobCross(const bool d_, const bool u_, const bool l_, const bool r_, const float s_, PosA4F& p_)
	{
		if (d_) {
			p_.y += s_; return MOB_DOWN;
		}
		else if (u_) {
			p_.y -= s_; return MOB_UP;
		}
		else if (l_) {
			p_.x -= s_; return MOB_LEFT;
		}
		else if (r_) {
			p_.x += s_; return MOB_RIGHT;
		}
		return MOB_CENTER;
	}

	const size_t moveMobCross(const size_t id_, const float s_, PosA4F& p_)
	{
		switch (id_)
		{
		case MOB_UP:
			p_.y -= s_;
			break;
		case MOB_DOWN:
			p_.y += s_;
			break;
		case MOB_LEFT:
			p_.x -= s_;
			break;
		case MOB_RIGHT:
			p_.x += s_;
			break;
		case MOB_LEFT_UP:
			p_.x -= s_;
			p_.y -= s_;
			break;
		case MOB_RIGHT_UP:
			p_.x += s_;
			p_.y -= s_;
			break;
		case MOB_LEFT_DOWN:
			p_.x -= s_;
			p_.y += s_;
			break;
		case MOB_RIGHT_DOWN:
			p_.x += s_;
			p_.y += s_;
			break;
		}
		return id_;
	}

	inline const bool moveMobCross(const float s_, PosA4F& p_) {
		return (moveMobCross(asKey(aslib_key_down), asKey(aslib_key_up), asKey(aslib_key_left), asKey(aslib_key_right), s_, p_) == MOB_CENTER) ? false : true;
	}

	const bool directionMobCross(const bool d_, const bool u_, const bool l_, const bool r_, size_t& dir_)
	{
		if (d_) {
			dir_ = MOB_DOWN; return true;
		}
		else if (u_) {
			dir_ = MOB_UP; return true;
		}
		else if (l_) {
			dir_ = MOB_LEFT; return true;
		}
		else if (r_) {
			dir_ = MOB_RIGHT; return true;
		}
		return false;
	}

	const bool directionMobCross(size_t& dir_) {
		return directionMobCross(asKey(aslib_key_down), asKey(aslib_key_up), asKey(aslib_key_left), asKey(aslib_key_right), dir_);
	}

	struct AsAttribute {
		//通過設定

		//各属性のID
		std::vector<size_t> id;
		AsAttribute() { id.resize(asAttribute(), 0); }

		void add(const size_t* const type_) {
			if (type_ == nullptr) return;
			for (size_t i = 0; i < id.size(); ++i) {
				id[i]=type_[i];
			}

		}
		AsAttribute(const size_t* const type_) { id.resize(asAttribute(), 0); add(type_); }

	};
	struct AsAllAttribute {
		std::vector<AsAttribute> all_id;
		AsAllAttribute() = default;
		void push(const size_t* const id_) {
			all_id.emplace_back(id_);
		}
	};

	//斜め移動あたり判定
	const size_t asMoveMobDiagonal(const size_t lr_, const size_t uw_, const size_t dia_) {

		//asPrint("(%d,%d,%d)", lr_, uw_, dia_);

		switch (dia_)
		{
		case aslib_pass_false:
		case aslib_pass_no_wall_false:
			switch (uw_)
			{
			case aslib_pass_false:
				switch (lr_)
				{
				case aslib_pass_false:return 0;
				case aslib_pass_no_wall_false:return 0;
				case aslib_pass_true:return 1;
				}
				break;
			case aslib_pass_no_wall_false:
				switch (lr_)
				{
				case aslib_pass_false:return 0;
				case aslib_pass_no_wall_false:return 0;
				case aslib_pass_true:return 1;
				}
				break;
			case aslib_pass_true:
				switch (lr_)
				{
				case aslib_pass_false:return 2;
				case aslib_pass_no_wall_false:return 2;
				case aslib_pass_true:return 0;
				}
				break;
			}
			break;
		case aslib_pass_true:
			switch (uw_)
			{
			case aslib_pass_false:
				switch (lr_)
				{
				case aslib_pass_false:return 0;
				case aslib_pass_no_wall_false:return 0;
				case aslib_pass_true:return 1;
				}
				break;
			case aslib_pass_no_wall_false:
				switch (lr_)
				{
				case aslib_pass_false:return 0;
				case aslib_pass_no_wall_false:return 3;
				case aslib_pass_true:return 3;
				}
				break;
			case aslib_pass_true:
				switch (lr_)
				{
				case aslib_pass_false:return 2;
				case aslib_pass_no_wall_false:return 3;
				case aslib_pass_true:return 3;
				}
				break;
			}
			break;
		}

		return 3;
	}
	//縦横あたり判定
	inline const bool asMoveMobCross(const size_t lruw_) {
		return (lruw_ == aslib_pass_true) ? true : false;
	}

	const size_t map20n_Number(const bool lr_, const bool ud_, const bool dia_) {
		if (lr_) {
			if (ud_) {//ooo
				if (dia_) return 4;
				//oox
				return 3;
			}//ox
			return 2;
		}//xo
		else if (ud_) return 1;
		//xx
		return 0;
	}

	struct AsTextureMap {
		//マップタイプ
		size_t type = aslib_texture_map_type_empty;
		size_t total_num = 0;
		//アニメーションフレーム
		size_t anime_count = 60;
		size_t anime_counter = 0;
		size_t anime_show_id = 0;

		//地形タイプ
		size_t field_type = aslib_texture_map_field_type_empty;
		//通過設定
		size_t pass = aslib_pass_true;

		AsAllAttribute* att = nullptr;
		AsTextureMap() = default;
		AsTextureMap(const size_t type_, const size_t ftype_, const size_t anime_) :type(type_), anime_count(anime_), field_type(ftype_) {}
		//AsTextureMap(const size_t type_, const size_t ftype_, const size_t anime_) :type(type_), field_type(ftype_), anime_counter(anime_),att(asAttribute()) {}
	};

	struct AsTextureMapArray {
		//地形データ
		size_t s_x = 0;
		size_t s_y = 0;
		size_t s_layer = 1;
		std::string s_name = u8"main";
		std::vector<size_t> s;
		//地面のテクスチャデータ
		std::vector<AsTexture*> t;
		std::vector<AsTextureMap> tm;

		AsTextureMapArray() = default;

		const int32_t readCSV() {
			return asMapRead(s_name, s, &s_x, &s_y, &s_layer);
		}
		const int32_t readBackupCSV() {
			return asMapRead(u8"backup_" + s_name, s, &s_x, &s_y, &s_layer);
		}
		const int32_t readCSV(const std::string& str_) {
			return asMapRead(str_, s, &s_x, &s_y, &s_layer);
		}
		const int32_t writeCSV() {
			return asMapWrite(s_name, s, s_x, s_y, s_layer);
		}
		const int32_t writeBackupCSV() {
			return asMapWrite(u8"backup_" + s_name, s, s_x, s_y, s_layer);
		}
		const int32_t writeCSV(const std::string& str_) {
			return asMapWrite(str_, s, s_x, s_y, s_layer);
		}

		void putTexture(const size_t layer_ = 0) {
			if (layer_ >= s_layer) return;

			const size_t t_total = t.size();

			const size_t layer_min = s_x * s_y*layer_;
			const size_t layer_max = layer_min + s_x * s_y;
			for (size_t i = layer_min, k = 0; i < layer_max && k < t_total; ++i, ++k) {//
				s[i] = k;
			}
		}

		void putBlock(const size_t s_, const Pos2 p_, const size_t layer_ = 0) {
			if (p_.is_minus() || p_.x >= (signed)s_x || p_.y >= (signed)s_y || layer_ >= s_layer) return;
			this->s[layer_*this->s_x*this->s_y + p_.y*this->s_x + p_.x] = s_;
		}
		void update() {
			if (tm.size() != t.size()) return;
			for (size_t i = 0; i < tm.size(); ++i) {
				if (t[i] == nullptr || t[i]->Num() < 2) continue;

				++tm[i].anime_counter;
				if (tm[i].anime_counter < tm[i].anime_count) continue;

				switch (tm[i].type)
				{
				case aslib_texture_map_type_1n:

					tm[i].anime_show_id = (tm[i].anime_show_id + 1) % t[i]->Num();
					tm[i].anime_counter = 0;
					break;
				case aslib_texture_map_type_20n:
					if (t[i]->NumX() < 3) break;
					tm[i].anime_show_id = (tm[i].anime_show_id + 2) % t[i]->NumX();
					tm[i].anime_counter = 0;
					break;
				}

			}
		}
		void push(AsTexture* const t_, const size_t ftype_= aslib_texture_map_field_type_empty, const size_t anime_=10) {
			size_t ltype = 0;
			if (t_ == nullptr) {
				ltype = aslib_texture_map_type_empty;
			}
			else if (t_->NumY() == 10 && t_->NumX() % 2 == 0) {
				ltype = aslib_texture_map_type_20n;
			}
			else {
				ltype = aslib_texture_map_type_1n;
			}

			AsTextureMap ltm(ltype, ftype_, anime_);

			tm.emplace_back(ltm);
			t.emplace_back(t_);
		}

		void resizeID(const size_t size_) {
			size_t t_size = t.size();
			tm.resize(size_);
			t.resize(size_);
			for (size_t i = t_size; i < size_; ++i) t[i] = nullptr;
		}
		void resizeMap(const Pos2& p_, const size_t layer_ = 1) {
			s_x = p_.x;
			s_y = p_.y;
			s_layer = layer_;
			s.resize(p_.x*p_.y*layer_, 0);
		}
		void setLayer(const size_t layer_ = 1, const size_t var_ = 0) {
			s.resize(s_x*s_y*layer_);
			const size_t layer_max = s_x * s_y;
			for (size_t i = 0; i < layer_max; ++i) {
				s[i] = var_;
			}
			for (size_t i = layer_max; i < s.size(); ++i) {
				s[i] = 0;
			}
			s_layer = layer_;
		}
		void putMap(const size_t id_ = 0, const size_t layer_ = 0) {
			if (tm.size() < 2 || layer_ >= s_layer) return;
			const size_t layer_min = s_x * s_y*layer_;
			const size_t layer_max = layer_min + s_x * s_y;
			for (size_t i = layer_min; i < layer_max; ++i) {
				s[i] = id_;
			}
		}
		void randMap(const size_t layer_ = 0) {
			if (tm.size() < 2 || layer_ >= s_layer) return;
			const size_t layer_min = s_x * s_y*layer_;
			const size_t layer_max = layer_min + s_x * s_y;
			for (size_t i = layer_min; i < layer_max; ++i) {
				s[i] = size_t(1 + asRand32(uint32_t(tm.size() - 2)));
			}
		}
		void randMap(const size_t tile1_, const size_t tile2_, const size_t layer_ = 0) {
			if (tm.size() < 2 || layer_ >= s_layer || tile1_ >= tm.size() || tile2_ >= tm.size()) return;
			const size_t layer_min = s_x * s_y*layer_;
			const size_t layer_max = layer_min + s_x * s_y;
			for (size_t i = layer_min; i < layer_max; ++i) {
				s[i] = (asRand8(1) == 0) ? tile1_ : tile2_;
			}
		}
		void mazeMap(const size_t wall_, const size_t empty_ = 0, const size_t layer_ = 0) {
			if (tm.size() < 2 || s_x % 2 == 0 || s_y % 2 == 0 || layer_ >= s_layer) return;
			const std::vector<size_t>& v2v1 = vector2ToVector1(asMazeMapMake(s_y, s_x, wall_, empty_));
			const size_t layer_min = s_x * s_y*layer_;
			const size_t layer_max = layer_min + s_x * s_y;
			for (size_t i = layer_min, k = 0; i < layer_max; ++i, ++k) {
				s[i] = v2v1[k];
			}	
		}
		void worldMap(const size_t under_, const size_t sea_, const size_t green_, const size_t snow_, const size_t seed_ = 0) {
			asWorldMapSimplePaint(s, s_x, s_y, s_layer, under_, sea_, green_, snow_, seed_);
		}

	};


	//あたり判定
	const bool movingCollisionDetection(const AsAllAttribute& att_, const AsTextureMapArray& tma_, const Pos2& p_, size_t& is_move_, const size_t player_id_ = aslib_attribute_human) {

		const size_t map_total = tma_.s_x*tma_.s_y;
		size_t move_array = 0;
		size_t move_array_lr = 0;
		size_t move_array_uw = 0;

		bool is_moving = false;
		size_t moving_id = 4;

		switch (is_move_)
		{
		case MOB_DOWN:
			move_array = ((p_.y + 1) % tma_.s_y)*tma_.s_x + ((p_.x + tma_.s_x) % tma_.s_x);
			break;
		case MOB_UP:
			move_array = (((p_.y - 1) + tma_.s_y) % tma_.s_y)*tma_.s_x + ((p_.x + tma_.s_x) % tma_.s_x);
			break;
		case MOB_LEFT:
			move_array = ((p_.y + tma_.s_y) % tma_.s_y)*tma_.s_x + (((p_.x - 1) + tma_.s_x) % tma_.s_x);
			break;
		case MOB_RIGHT:
			move_array = ((p_.y + tma_.s_y) % tma_.s_y)*tma_.s_x + ((p_.x + 1) % tma_.s_x);
			break;
		case MOB_LEFT_UP:
			move_array_lr = ((p_.y + tma_.s_y) % tma_.s_y)*tma_.s_x + (((p_.x - 1) + tma_.s_x) % tma_.s_x);
			move_array_uw = (((p_.y - 1) + tma_.s_y) % tma_.s_y)*tma_.s_x + ((p_.x + tma_.s_x) % tma_.s_x);
			move_array = (((p_.y - 1) + tma_.s_y) % tma_.s_y)*tma_.s_x + (((p_.x - 1) + tma_.s_x) % tma_.s_x);
			break;
		case MOB_RIGHT_UP:
			move_array_lr = ((p_.y + tma_.s_y) % tma_.s_y)*tma_.s_x + ((p_.x + 1) % tma_.s_x);
			move_array_uw = (((p_.y - 1) + tma_.s_y) % tma_.s_y)*tma_.s_x + ((p_.x + tma_.s_x) % tma_.s_x);
			move_array = (((p_.y - 1) + tma_.s_y) % tma_.s_y)*tma_.s_x + ((p_.x + 1) % tma_.s_x);
			break;
		case MOB_LEFT_DOWN:
			move_array_lr = ((p_.y + tma_.s_y) % tma_.s_y)*tma_.s_x + (((p_.x - 1) + tma_.s_x) % tma_.s_x);
			move_array_uw = ((p_.y + 1) % tma_.s_y)*tma_.s_x + ((p_.x + tma_.s_x) % tma_.s_x);
			move_array = ((p_.y + 1) % tma_.s_y)*tma_.s_x + (((p_.x - 1) + tma_.s_x) % tma_.s_x);
			break;
		case MOB_RIGHT_DOWN:
			move_array_lr = ((p_.y + tma_.s_y) % tma_.s_y)*tma_.s_x + ((p_.x + 1) % tma_.s_x);
			move_array_uw = ((p_.y + 1) % tma_.s_y)*tma_.s_x + ((p_.x + tma_.s_x) % tma_.s_x);
			move_array = ((p_.y + 1) % tma_.s_y)*tma_.s_x + ((p_.x + 1) % tma_.s_x);
			break;
		default:return false;
		}

		for (size_t i = 0; i < tma_.s_layer; ++i) {

			switch (is_move_)
			{
			case MOB_DOWN:
			case MOB_UP:
			case MOB_LEFT:
			case MOB_RIGHT:
				if (move_array + map_total * i >= tma_.s.size()) { asPrint("ca:(%d:%d+%d*%d>=%d)", is_move_, move_array, map_total, i, tma_.s.size()); break; }
				is_moving = asMoveMobCross(att_.all_id[tma_.tm[tma_.s[move_array + map_total * i]].field_type].id[player_id_]);
				if (!is_moving) return is_moving;
				break;
			case MOB_LEFT_UP:
			case MOB_RIGHT_UP:
			case MOB_LEFT_DOWN:
			case MOB_RIGHT_DOWN:
				switch (asMoveMobDiagonal(att_.all_id[tma_.tm[tma_.s[move_array_lr + map_total * i]].field_type].id[player_id_], att_.all_id[tma_.tm[tma_.s[move_array_uw + map_total * i]].field_type].id[player_id_], att_.all_id[tma_.tm[tma_.s[move_array + map_total * i]].field_type].id[player_id_])) {
				case 0:return false;
				case 1:
					if (moving_id == 2) return false;
					moving_id = 1;
					break;
				case 2:
					if (moving_id == 1) return false;
					moving_id = 2;
					break;
				case 3:
					if (moving_id == 4) moving_id = 3;
					break;
				}
				break;
			}
		}
		switch (is_move_)
		{
		case MOB_LEFT_UP:
			switch (moving_id)
			{
			case 1:is_move_ = MOB_LEFT; return true;
			case 2:is_move_ = MOB_UP; return true;
			case 3:return true;
			}
			break;
		case MOB_RIGHT_UP:
			switch (moving_id)
			{
			case 1:is_move_ = MOB_RIGHT; return true;
			case 2:is_move_ = MOB_UP; return true;
			case 3:return true;
			}
			break;
		case MOB_LEFT_DOWN:
			switch (moving_id)
			{
			case 1:is_move_ = MOB_LEFT; return true;
			case 2:is_move_ = MOB_DOWN; return true;
			case 3:return true;
			}
			break;
		case MOB_RIGHT_DOWN:
			switch (moving_id)
			{
			case 1:is_move_ = MOB_RIGHT; return true;
			case 2:is_move_ = MOB_DOWN; return true;
			case 3:return true;
			}
			break;
		}

		return is_moving;
	}
	//向きを決定する
	const bool directionMob(const size_t& moving_, size_t& dir_) {
		switch (moving_)
		{
		case MOB_DOWN:case MOB_UP:case MOB_LEFT:case MOB_RIGHT:
		case MOB_LEFT_UP:case MOB_RIGHT_UP:case MOB_LEFT_DOWN:case MOB_RIGHT_DOWN:
			dir_ = moving_;
			return true;
		}
		return false;
	}

	const bool movingMob8(const AsAllAttribute& att_, const AsTextureMapArray& tma_, const AsKeyList& kl_, const float s_, PosA4F& p_, size_t& is_move_, size_t& dir_id_) {
		if (is_move_ != MOB_CENTER) return true;
		is_move_ = kl_.playerMove8();
		if (is_move_ == MOB_CENTER) return false;

		directionMob(is_move_, dir_id_);

		if (!movingCollisionDetection(att_, tma_, p_, is_move_)) {
			is_move_ = MOB_CENTER;
		}
		else is_move_ = moveMobCross(is_move_, s_, p_);

		return true;
	}
	const bool movingMob8_AI(const AsAllAttribute& att_, const AsTextureMapArray& tma_, const float s_, PosA4F& p_, size_t& is_move_, size_t& dir_id_) {
		if (is_move_ != MOB_CENTER) return true;
		is_move_ = asRand8(7);
		if (is_move_ == MOB_CENTER) return false;

		directionMob(is_move_, dir_id_);

		if (!movingCollisionDetection(att_, tma_, p_, is_move_)) {
			is_move_ = MOB_CENTER;
		}
		else is_move_ = moveMobCross(is_move_, s_, p_);

		return true;
	}

	inline const bool moveMob(const float s_, PosA4F& p_) {
		return moveMob(asKey(aslib_key_down), asKey(aslib_key_up), asKey(aslib_key_left), asKey(aslib_key_right), s_, p_);
	}

	//イベントの属性
	enum :size_t {
		aslib_map_event_type_empty,
		aslib_map_event_type_mob,
		aslib_map_event_type_move,
	};
	//イベントの知能
	enum :size_t {
		aslib_map_event_ai_human,
		aslib_map_event_ai_ai
	};

	//メッセージウィンドウイベント管理
	struct AsEventMessageWindow {
		MessageWindow* const mw = nullptr;
		AsEventMessageWindow(MessageWindow* const mw_, const char* const str_) :mw(mw_), str(str_) {}
		//文字
		std::string str = "";

		const bool play() {
			if (mw == nullptr) return false;

		}
	};
	//イベント管理
	struct AsMapEventData {
		size_t event_type = aslib_event_type_empty;
		AsEventMessageWindow* emw = nullptr;

		AsMapEventData() = default;
		AsMapEventData(AsEventMessageWindow* emw_) :event_type(aslib_event_type_talk),emw(emw_) {}
	};
	//マップ上のイベント管理
	struct AsMapEvent {
		//イベントタイプ
		size_t type = aslib_map_event_type_empty;
		//行動
		size_t ai = aslib_map_event_ai_ai;
		//向き
		size_t dir_id = MOB_DOWN;
		//移動ID
		size_t move_id = MOB_STOP;
		//移動状態
		size_t moving = MOB_CENTER;
		//移動属性
		size_t pl_field_type = aslib_attribute_human;
		//アニメーションフレーム
		size_t count = 0;
		size_t move_count_max = 6;
		//位置と大きさ
		PosA4F pl;
		//移動する距離
		float fps = 0.1f;
		//画像
		AsTexture* t = nullptr;
		//あたり判定
		bool is_collision_detection = true;
		//イベント中
		size_t is_event = 0;

		//イベント開始条件
		size_t event_init = aslib_event_init_touch;
		//イベント開始範囲
		PosA4F event_init_pos;

		//イベントデータ
		std::vector<AsMapEventData> med;

		AsMapEvent(AsTexture* const t_ = nullptr, const PosA4F& p_ = { 0.0f,0.0f,1.0f,1.0f }, const size_t& type_ = aslib_map_event_type_empty, const size_t ai_ = aslib_map_event_ai_ai) :type(type_), ai(ai_), pl(p_), t(t_) {}
	};

	const size_t movingMob(AsMapEvent* const me_,const size_t x_,const size_t y_) {
		if (me_ == nullptr) return MOB_CENTER;

		const Pos2F p2f(me_->pl.x, me_->pl.y);
		switch (me_->moving)
		{
		case MOB_DOWN:
			me_->pl.y += me_->fps;
			if (floor(p2f.y) == floor(me_->pl.y)) return me_->moving;
				me_->moving = MOB_CENTER;
				me_->pl.y = float((int32_t(floor(me_->pl.y)) + y_) % y_);
			return me_->moving;
		case MOB_UP:
			me_->pl.y -= me_->fps;
			if (floor(p2f.y) == floor(me_->pl.y)) return me_->moving;
				me_->moving = MOB_CENTER;
				me_->pl.y = float((int32_t(floor(me_->pl.y) + 1.0f) + y_) % y_);
			return me_->moving;
		case MOB_LEFT:
			me_->pl.x -= me_->fps;
			if (floor(p2f.x) == floor(me_->pl.x)) return me_->moving;
				me_->moving = MOB_CENTER;
				me_->pl.x = float((int32_t(floor(me_->pl.x) + 1.0f) + x_) % x_);
			return me_->moving;
		case MOB_RIGHT:
			me_->pl.x += me_->fps;
			if (floor(p2f.x) == floor(me_->pl.x)) return me_->moving;
				me_->moving = MOB_CENTER;
				me_->pl.x = float((int32_t(floor(me_->pl.x)) + x_) % x_);
			return me_->moving;
		case MOB_LEFT_UP:
			me_->pl.x -= me_->fps;
			me_->pl.y -= me_->fps;
			if (floor(p2f.x) != floor(me_->pl.x)) {
				me_->moving = MOB_UP;
				me_->pl.x = float((int32_t(floor(me_->pl.x) + 1.0f) + x_) % x_);
			}
			if (floor(p2f.y) != floor(me_->pl.y)) {
				me_->moving = (me_->moving == MOB_UP) ? MOB_CENTER : MOB_LEFT;
				me_->pl.y = float((int32_t(floor(me_->pl.y) + 1.0f) + y_) % y_);
			}
			return me_->moving;
		case MOB_RIGHT_UP:
			me_->pl.x += me_->fps;
			me_->pl.y -= me_->fps;
			if (floor(p2f.x) != floor(me_->pl.x)) {
				me_->moving = MOB_UP;
				me_->pl.x = float((int32_t(floor(me_->pl.x)) + x_) % x_);
			}
			if (floor(p2f.y) != floor(me_->pl.y)) {
				me_->moving = (me_->moving == MOB_UP) ? MOB_CENTER : MOB_RIGHT;
				me_->pl.y = float((int32_t(floor(me_->pl.y) + 1.0f) + y_) % y_);
			}
			return me_->moving;
		case MOB_LEFT_DOWN:
			me_->pl.x -= me_->fps;
			me_->pl.y += me_->fps;
			if (floor(p2f.x) != floor(me_->pl.x)) {
				me_->moving = MOB_DOWN;
				me_->pl.x = float((int32_t(floor(me_->pl.x) + 1.0f) + x_) % x_);
			}
			if (floor(p2f.y) != floor(me_->pl.y)) {
				me_->moving = (me_->moving == MOB_DOWN) ? MOB_CENTER : MOB_LEFT;
				me_->pl.y = float((int32_t(floor(me_->pl.y)) + y_) % y_);
			}
			return me_->moving;
		case MOB_RIGHT_DOWN:
			me_->pl.x += me_->fps;
			me_->pl.y += me_->fps;
			if (floor(p2f.x) != floor(me_->pl.x)) {
				me_->moving = MOB_DOWN;
				me_->pl.x = float((int32_t(floor(me_->pl.x)) + x_) % x_);
			}
			if (floor(p2f.y) != floor(me_->pl.y)) {
				me_->moving = (me_->moving == MOB_DOWN) ? MOB_CENTER : MOB_RIGHT;
				me_->pl.y = float((int32_t(floor(me_->pl.y)) + y_) % y_);
			}
			return me_->moving;
		}
		return me_->moving;
	}
	//mobに歩行アニメーションをさせる
	const bool mobMoveSet(AsMapEvent* const me_) {
		if (me_ == nullptr) return false;

		switch (me_->move_id)
		{
		case MOB_STOP:
			++me_->move_id;
			return true;
		case MOB_MOVE1:
		case MOB_MOVE2:
		case MOB_MOVE3:
			++me_->count;
			if (me_->count >= me_->move_count_max) {
				me_->count = 0;
				++me_->move_id;
			}
			return true;
		case MOB_MOVE4:
			++me_->count;
			if (me_->count >= me_->move_count_max) {
				me_->count = 0;
				me_->move_id = MOB_MOVE1;
			}
			return true;
		}
		return false;
	}
	struct AsMapEventControl {
		Pos2 size = { 1,1 };
		size_t view_id = 0;
		size_t walk_type = aslib_mob_walk_type_small;

		bool is_spawn = true;

		std::vector<AsMapEvent> me;
		AsMapEventControl(const Pos2 size_,const size_t walk_type_, AsTexture* const t_ = nullptr, const PosA4F& p_ = { 0.0f,0.0f,1.0f,1.0f }, const size_t& type_ = aslib_map_event_type_empty) :size(size_),walk_type(walk_type_) { me.emplace_back(t_,p_, type_, aslib_map_event_ai_human); }
		void add(AsTexture* const t_ = nullptr, const PosA4F& p_ = { 0.0f,0.0f,1.0f,1.0f }, const size_t& type_ = aslib_map_event_type_empty, const size_t ai_ = aslib_map_event_ai_ai) {
			if(is_spawn) me.emplace_back(t_, p_, type_, ai_);
		}
		//初期イベント管理・実行
		AsMapEventControl& start_event(size_t me_id_) {
			if (me_id_ >= me.size()) return *this;
			me[me_id_].is_event = 1;
			//イベント種類分け
			switch (me[me_id_].med[me[me_id_].is_event - 1].event_type)
			{
				//空(から)イベント
			case aslib_event_type_empty:
				++me[me_id_].is_event;
				if (me[me_id_].is_event > me[me_id_].med.size()) me[me_id_].is_event = 0;
				else this->start_event(me_id_);
				return *this;
				//会話イベント
			case aslib_event_type_talk:
				//nullptrの時
				if (me[me_id_].med[me[me_id_].is_event - 1].emw == nullptr || me[me_id_].med[me[me_id_].is_event - 1].emw->mw == nullptr) {
					++me[me_id_].is_event;
					if (me[me_id_].is_event > me[me_id_].med.size()) me[me_id_].is_event = 0;
					else this->start_event(me_id_);
					break;
				}
				//文字を代入
				me[me_id_].med[me[me_id_].is_event - 1].emw->mw->readSetString32(me[me_id_].med[me[me_id_].is_event - 1].emw->str.c_str());
				break;
			}
		}
		//イベント管理・実行
		AsMapEventControl& play_event() {
			for (size_t i = 0; i < me.size(); ++i) {
				//イベントOFFの時
				if (me[i].is_event == 0) continue;
				//イベント種類分け
				switch (me[i].med[me[i].is_event - 1].event_type)
				{
					//空(から)イベント
				case aslib_event_type_empty:
					++me[i].is_event;
					if (me[i].is_event > me[i].med.size()) me[i].is_event = 0;
					else this->start_event(i);
					return *this;
					//会話イベント
				case aslib_event_type_talk:
					//nullptrの時
					if (me[i].med[me[i].is_event - 1].emw == nullptr|| me[i].med[me[i].is_event - 1].emw->mw == nullptr|| !me[i].med[me[i].is_event - 1].emw->mw->isWindow()) {
						++me[i].is_event;
						if (me[i].is_event > me[i].med.size()) me[i].is_event = 0;
						else this->start_event(i);
						return *this;
					}
					break;
				}
			}
		}

		AsMapEventControl& talk(const bool is_true) {
			//会話キーが押されていない・視点が配列外・視点キャラが移動中
			if (!is_true || view_id >= me.size() || me[view_id].moving != MOB_CENTER) return *this;
			Pos2 player_pos(int32_t(me[view_id].pl.x), int32_t(me[view_id].pl.y));
			switch (me[view_id].dir_id)
			{
			case MOB_DOWN:
				player_pos.x = int32_t(me[view_id].pl.x);
				player_pos.y = (int32_t(me[view_id].pl.y) + 1) % size.y;
				break;
			case MOB_UP:
				player_pos.x = int32_t(me[view_id].pl.x);
				player_pos.y = (int32_t(me[view_id].pl.y) - 1 + size.y) % size.y;
				break;
			case MOB_LEFT:
				player_pos.x = (int32_t(me[view_id].pl.x) - 1 + size.x) % size.x;
				player_pos.y = int32_t(me[view_id].pl.y);
				break;
			case MOB_RIGHT:
				player_pos.x = (int32_t(me[view_id].pl.x) + 1) % size.x;
				player_pos.y = int32_t(me[view_id].pl.y);
				break;
			case MOB_LEFT_UP:
				player_pos.x = (int32_t(me[view_id].pl.x) - 1 + size.x) % size.x;
				player_pos.y = (int32_t(me[view_id].pl.y) - 1 + size.y) % size.y;
				break;
			case MOB_RIGHT_UP:
				player_pos.x = (int32_t(me[view_id].pl.x) + 1) % size.x;
				player_pos.y = (int32_t(me[view_id].pl.y) - 1 + size.y) % size.y;
				break;
			case MOB_LEFT_DOWN:
				player_pos.x = (int32_t(me[view_id].pl.x) - 1 + size.x) % size.x;
				player_pos.y = (int32_t(me[view_id].pl.y) + 1) % size.y;
				break;
			case MOB_RIGHT_DOWN:
				player_pos.x = (int32_t(me[view_id].pl.x) + 1) % size.x;
				player_pos.y = (int32_t(me[view_id].pl.y) + 1) % size.y;
				break;
			}
			for (size_t i = 0; i < me.size(); ++i) {

				//asPrint("(%d,%d,%d,%d)",me[i].event_init != aslib_event_init_tolk , me[i].moving != MOB_CENTER , me[i].is_event > 0 , me[i].med.size() == 0);

				//選択イベントの開始条件が会話じゃない・選択イベントが移動中・イベントがONになっている・イベント数が0
				if (me[i].event_init != aslib_event_init_tolk || me[i].moving != MOB_CENTER || me[i].is_event > 0 || me[i].med.size() == 0) continue;
				//視点キャラの向いている方向にいるかどうか
				if (int32_t(me[i].pl.x) != player_pos.x || int32_t(me[i].pl.y) != player_pos.y) continue;
				//イベントON
				this->start_event(i);

				switch (me[view_id].dir_id)
				{
				case MOB_DOWN:me[i].dir_id = MOB_UP; break;
				case MOB_UP:me[i].dir_id = MOB_DOWN; break;
				case MOB_LEFT:me[i].dir_id = MOB_RIGHT; break;
				case MOB_RIGHT:me[i].dir_id = MOB_LEFT; break;
				case MOB_LEFT_UP:me[i].dir_id = MOB_RIGHT_DOWN; break;
				case MOB_RIGHT_UP:me[i].dir_id = MOB_LEFT_DOWN; break;
				case MOB_LEFT_DOWN:me[i].dir_id = MOB_RIGHT_UP; break;
				case MOB_RIGHT_DOWN:me[i].dir_id = MOB_LEFT_UP; break;
				}
				break;
			}
			return *this;
		}
		AsMapEventControl& spawn(const float rand_) {
			if (uint32_t(UINT32_MAX*(rand_/100.0f)) >= asRand32()) is_spawn = true;
			else is_spawn = false;
			return *this;
		}
		AsMapEventControl& setSpawn(const PosA4F p_) {
			if (view_id >= me.size()) return *this;
			me[view_id].pl = p_;
			return *this;
		}
		AsMapEventControl& setLandSpawn(const AsTextureMapArray& tma_, AsAllAttribute& att_) {
			if (view_id >= me.size()) return *this;
			const size_t xy_ = tma_.s_x*tma_.s_y;
			const size_t pl_field = me[view_id].pl_field_type;

			for (size_t i = 0, k = 0; i < xy_; ++i) {
				if (att_.all_id[tma_.tm[tma_.s[i]].field_type].id[pl_field] != aslib_pass_true) continue;
				for (size_t j = 1; j < tma_.s_layer; ++j) {
					if (att_.all_id[tma_.tm[tma_.s[i + xy_ * j]].field_type].id[pl_field] != aslib_pass_true) {
						k = 0;
						break;
					}
					++k;
				}
				if (k > 0) {
					me[view_id].pl.x = float(i % tma_.s_x);
					me[view_id].pl.y = float(i / tma_.s_x);
					return *this;
				}
			}
			return *this;
		}
		AsMapEventControl& spawn() { is_spawn = true; return *this; }

		void update(const AsTextureMapArray& tma_, const AsAllAttribute& att_, const AsKeyList& kl_) {
			for (size_t i = 0; i < me.size(); ++i) {
				switch (me[i].ai)
				{
				case aslib_map_event_ai_human:
					me[i].moving = movingMob(&me[i], tma_.s_x, tma_.s_y);
					if (movingMob8(att_, tma_, kl_, me[i].fps, me[i].pl, me[i].moving, me[i].dir_id)) {
						mobMoveSet(&me[i]);
					}
					else me[i].move_id = MOB_STOP;
					break;
				case aslib_map_event_ai_ai:
					if (me[i].is_event > 0) break;//イベント中は歩行無し
					me[i].moving = movingMob(&me[i], tma_.s_x, tma_.s_y);
					if (asRand8(100) > 1) break;
					if (movingMob8_AI(att_, tma_, me[i].fps, me[i].pl, me[i].moving, me[i].dir_id)) {
						mobMoveSet(&me[i]);
					}
					break;
				}
			}
		}
	};

	//マップの見える範囲
	struct AsMapView
	{
	public:
		AsMapView() = default;
		constexpr AsMapView(const PosA4F& p_) : p(p_) {}
		AsMapView(const PosA4F& p_, const char c_) : p(p_) {
			switch (c_)
			{
				//正方形
			case 'x': p.h = p.w*(float(asWindowSize().y) / float(asWindowSize().x)); break;
			case 'y': p.w = p.h*(float(asWindowSize().x) / float(asWindowSize().y)); break;
				//画面サイズと同比率
			case 'X': p.h = p.w; break;
			case 'Y': p.w = p.h; break;
			}
		}
		AsMapView& setLookSize(const PosA4F& p_, const char c_) {
			p = p_;
			switch (c_)
			{
				//正方形
			case 'x': p.h = p.w*(float(asWindowSize().y) / float(asWindowSize().x)); break;
			case 'y': p.w = p.h*(float(asWindowSize().x) / float(asWindowSize().y)); break;
				//画面サイズと同比率
			case 'X': p.h = p.w; break;
			case 'Y': p.w = p.h; break;
			}
			return *this;
		}
	private:
		//マップの中心位置と幅
		PosA4F p;
		//開始から終了まで
		Pos4 in_map;
		//マップサイズ
		Pos2 p2;

		AsMapView& drawMap(const size_t num_, Color* const col_ = nullptr, AsTextureMapArray* const a_ = nullptr)
		{
			size_t draw_layer_max = 1;
			switch (num_)
			{
			case MAP_VIEW_DRAW_COLOR:
				if (col_ == nullptr) return *this;
				break;
			case MAP_VIEW_DRAW_ANIME:
				if (a_ == nullptr) return *this;
				draw_layer_max = a_->s_layer;
				break;
			}

			//1マスの描画幅
			const Pos2F m(asWindowSizeF().x / this->p.w, asWindowSizeF().y / this->p.h);

			//中心幅
			const Pos2F ce_length(this->p.w / 2.0f, this->p.h / 2.0f);
			//前
			const Pos2F be_pos(this->p.x - ce_length.x, this->p.y - ce_length.y);
			//後
			const Pos2F af_pos(this->p.x + ce_length.x, this->p.y + ce_length.y);

			const size_t layer_plus = p2.x*p2.y;
			size_t draw_layer_plus = layer_plus;

			//描画初期位置
			const Pos2F in_draw((floor(be_pos.x) - be_pos.x)*m.x - m.x, (floor(be_pos.y) - be_pos.y)*m.y - m.y);
			in_map = Pos4(Pos4F(floor(be_pos.x), floor(be_pos.y), ceil(af_pos.x), ceil(af_pos.y)));
			Pos2 select_map;
			Pos2F draw_map(in_draw);
			size_t array_num = 0;

			AsTexture* texture_id = nullptr;
			AsTextureMap* tm_id = nullptr;
			size_t map_field_type = 0;
			bool amap[8]{};
			size_t pym, pyp, pxm, pxp;

			const size_t tma_size = a_->s.size();

			//レイヤー指定
			for (size_t layer = 0; layer < draw_layer_max; ++layer) {
				draw_layer_plus = layer_plus * layer;
				draw_map = in_draw;

				//Y軸指定
				for (int32_t i = in_map.y1; i < in_map.y2; ++i) {
					draw_map.x = in_draw.x;
					draw_map.y += m.y;
					select_map.y = i;
					while (select_map.y < 0) { select_map.y += p2.y; }
					select_map.y = select_map.y % p2.y;

					//X軸指定
					for (int32_t j = in_map.x1; j < in_map.x2; ++j) {


						draw_map.x += m.x;
						select_map.x = j;
						while (select_map.x < 0) { select_map.x += p2.x; }
						select_map.x = select_map.x % p2.x;

						//描画するデータのある配列の場所
						array_num = select_map.y*p2.x + select_map.x + draw_layer_plus;
						if (array_num >= tma_size) continue;

						switch (num_)
						{
						case MAP_VIEW_DRAW_COLOR:
							asRect(Pos4(int32_t(draw_map.x), int32_t(draw_map.y), int32_t(draw_map.x + m.x), int32_t(draw_map.y + m.y)), col_[array_num]);
							break;
						case MAP_VIEW_DRAW_ANIME:
							if (array_num >= a_->s.size() || a_->s[array_num] >= a_->tm.size() || (texture_id = a_->t[a_->s[array_num]]) == nullptr) break;

							switch (a_->tm[a_->s[array_num]].type)
							{
							case aslib_texture_map_type_1n:
								texture_id->draw(a_->tm[a_->s[array_num]].anime_show_id, Pos4(int32_t(draw_map.x), int32_t(draw_map.y), int32_t(draw_map.x + m.x), int32_t(draw_map.y + m.y)));
								break;
							case aslib_texture_map_type_20n:
								tm_id = &a_->tm[a_->s[array_num]];
								map_field_type = tm_id->field_type;

								pym = ((select_map.y - 1 + p2.y) % p2.y)*p2.x;
								pyp = ((select_map.y + 1) % p2.y)*p2.x;
								pxm = ((select_map.x - 1 + p2.x) % p2.x);
								pxp = ((select_map.x + 1) % p2.x);

								if (pym + pxm + draw_layer_plus >= a_->s.size()) break;

								amap[MOB_LEFT_UP] = (a_->tm[a_->s[pym + pxm + draw_layer_plus]].field_type == map_field_type);
								amap[MOB_UP] = (a_->tm[a_->s[pym + select_map.x + draw_layer_plus]].field_type == map_field_type);
								amap[MOB_RIGHT_UP] = (a_->tm[a_->s[pym + pxp + draw_layer_plus]].field_type == map_field_type);
								amap[MOB_LEFT] = (a_->tm[a_->s[select_map.y*p2.x + pxm + draw_layer_plus]].field_type == map_field_type);
								amap[MOB_RIGHT] = (a_->tm[a_->s[select_map.y*p2.x + pxp + draw_layer_plus]].field_type == map_field_type);
								amap[MOB_LEFT_DOWN] = (a_->tm[a_->s[pyp + pxm + draw_layer_plus]].field_type == map_field_type);
								amap[MOB_DOWN] = (a_->tm[a_->s[pyp + select_map.x + draw_layer_plus]].field_type == map_field_type);
								amap[MOB_RIGHT_DOWN] = (a_->tm[a_->s[pyp + pxp + draw_layer_plus]].field_type == map_field_type);

								texture_id->draw(texture_id->NumX() * 2 * map20n_Number(amap[MOB_LEFT], amap[MOB_UP], amap[MOB_LEFT_UP]) + tm_id->anime_show_id, Pos4(int32_t(draw_map.x), int32_t(draw_map.y), int32_t(draw_map.x + m.x / 2.0f), int32_t(draw_map.y + m.y / 2.0f)));
								texture_id->draw(texture_id->NumX() * 2 * map20n_Number(amap[MOB_RIGHT], amap[MOB_UP], amap[MOB_RIGHT_UP]) + tm_id->anime_show_id + 1, Pos4(int32_t(draw_map.x + m.x / 2.0f), int32_t(draw_map.y), int32_t(draw_map.x + m.x), int32_t(draw_map.y + m.y / 2.0f)));
								texture_id->draw(texture_id->NumX() * 2 * map20n_Number(amap[MOB_LEFT], amap[MOB_DOWN], amap[MOB_LEFT_DOWN]) + tm_id->anime_show_id + texture_id->NumX(), Pos4(int32_t(draw_map.x), int32_t(draw_map.y + m.y / 2.0f), int32_t(draw_map.x + m.x / 2.0f), int32_t(draw_map.y + m.y)));
								texture_id->draw(texture_id->NumX() * 2 * map20n_Number(amap[MOB_RIGHT], amap[MOB_DOWN], amap[MOB_RIGHT_DOWN]) + tm_id->anime_show_id + 1 + texture_id->NumX(), Pos4(int32_t(draw_map.x + m.x / 2.0f), int32_t(draw_map.y + m.y / 2.0f), int32_t(draw_map.x + m.x), int32_t(draw_map.y + m.y)));
								break;
							}
							break;
						}
					}
				}
			}
			return *this;
		}

	public:

		//中心位置を指定--------------------------------------------------------------

		//
		AsMapView& setMap(const Pos2& p2_) {
			if (p2_.is_minus()) return *this;
			p2 = p2_;
			return *this;
		}

		//視点変更
		AsMapView& setMobView(PosA4F& p_, const size_t type_ = aslib_mob_walk_type_small) {
			const Pos2F p2f = p2;
			while (p_.x < 0.0f) { p_.x += p2f.x; }
			while (p_.y < 0.0f) { p_.y += p2f.y; }
			p.x = p_.x += float(int32_t(p_.x) % p2.x) - floor(p_.x);
			p.y = p_.y += float(int32_t(p_.y) % p2.y) - floor(p_.y);

			if (type_ == aslib_mob_walk_type_big) {
				p.x += 0.5f;
				p.y += (0.6f - 0.3f*p_.h);
			}
			return *this;
		}
		AsMapView& setMobView(AsMapEventControl& mec_) {
			if (mec_.view_id >= mec_.me.size()) return *this;
			this->setMobView(mec_.me[mec_.view_id].pl, mec_.walk_type);
			return *this;
		}
		AsMapView& setMobPos(PosA4F& p_) {
			const Pos2F p2f = p2;
			while (p_.x < 0.0f) { p_.x += p2f.x; }
			while (p_.y < 0.0f) { p_.y += p2f.y; }
			p_.x += float(int32_t(p_.x) % p2.x) - floor(p_.x);
			p_.y += float(int32_t(p_.y) % p2.y) - floor(p_.y);
			return *this;
		}
		AsMapView& setMobPos(std::vector<PosA4F>& p_) {
			const Pos2F p2f = p2;
			for (size_t i = 0; i < p_.size(); ++i) {
				while (p_[i].x < 0.0f) { p_[i].x += p2f.x; }
				while (p_[i].y < 0.0f) { p_[i].y += p2f.y; }
				p_[i].x += float(int32_t(p_[i].x) % p2.x) - floor(p_[i].x);
				p_[i].y += float(int32_t(p_[i].y) % p2.y) - floor(p_[i].y);
			}
			return *this;
		}
		AsMapView& setMap(const PosA4F& p_) { p = p_; return *this; }
		AsMapView& setMapX(const PosA4F& p_) { p = p_; p.h = p.w*(float(asWindowSize().y) / float(asWindowSize().x)); return *this; }

		//描画する物のサイズ
		AsMapView& draw(AsMapEventControl* const mec_ = nullptr)
		{
			if (mec_ == nullptr || mec_->me.size() == 0) return *this;

			//1マスの描画幅
			const Pos2F m(asWindowSizeF().x / this->p.w, asWindowSizeF().y / this->p.h);
			//中心幅
			const Pos2F ce_length(this->p.w / 2.0f, this->p.h / 2.0f);
			//前
			const Pos2F be_pos(this->p.x - ce_length.x, this->p.y - ce_length.y);
			//後
			const Pos2F af_pos(this->p.x + ce_length.x, this->p.y + ce_length.y);

			//描画初期位置
			const Pos2F in_draw((floor(be_pos.x) - be_pos.x)*m.x - m.x, (floor(be_pos.y) - be_pos.y)*m.y - m.y);
			in_map = Pos4(Pos4F(floor(be_pos.x), floor(be_pos.y), ceil(af_pos.x), ceil(af_pos.y)));
			Pos2 select_map;
			Pos2F draw_map(in_draw);
			size_t array_num = 0;

			PosA4F draw_mob;
			size_t id_;
			PosA4F p_a4f;
			Pos2 player_p;

			//Y軸指定
			for (int32_t i = in_map.y1; i < in_map.y2; ++i) {
				draw_map.x = in_draw.x;
				draw_map.y += m.y;
				select_map.y = i;
				while (select_map.y < 0) { select_map.y += p2.y; }
				select_map.y = select_map.y % p2.y;

				//X軸指定
				for (int32_t j = in_map.x1; j < in_map.x2; ++j) {
					draw_map.x += m.x;
					select_map.x = j;
					while (select_map.x < 0) { select_map.x += p2.x; }
					select_map.x = select_map.x % p2.x;

					for (size_t k = 0; k < mec_->me.size(); ++k) {
						if (mec_->me[k].t == nullptr) continue;
						id_ = mobMoveDirect(mec_->me[k].dir_id, mec_->me[k].move_id);
						if (mec_->me[k].t->Num() <= id_) continue;

						p_a4f = (mec_->walk_type == aslib_mob_walk_type_big) ? PosA4F(mec_->me[k].pl.x + 0.5f, mec_->me[k].pl.y + 0.6f - 0.3f*mec_->me[k].pl.h, mec_->me[k].pl.w, mec_->me[k].pl.h) : mec_->me[k].pl;

						player_p = Pos2(int32_t(floor(p_a4f.x)), int32_t(floor(p_a4f.y)));
						while (player_p.x < 0) player_p.x += p2.x;
						while (player_p.y < 0) player_p.y += p2.y;

						player_p.x = player_p.x%p2.x;
						player_p.y = player_p.y%p2.y;

						if (select_map.x != player_p.x || select_map.y != player_p.y) continue;

						//描画するデータのある配列の場所
						array_num = select_map.y*p2.x + select_map.x;
						draw_mob = PosA4F(draw_map.x + (p_a4f.x - floor(p_a4f.x))*m.x, draw_map.y + (p_a4f.y - floor(p_a4f.y))*m.y, m.x*p_a4f.w, m.y*p_a4f.h);

						mec_->me[k].t->draw(id_, draw_mob);
					}
				}
			}
			return *this;
		}

		//色の全体描画
		AsMapView& draw(Color* const col_) { return this->drawMap(MAP_VIEW_DRAW_COLOR, col_, nullptr); }
		//画像の全体描画
		AsMapView& draw(AsTextureMapArray* const t_) { return this->drawMap(MAP_VIEW_DRAW_ANIME, nullptr, t_); }

	};







	inline static const size_t a2(const size_t& s_, const size_t& i_, const size_t& j_) { return (s_ * j_ + i_); }
	struct worldMap
	{
		Pos2 s;
		size_t total_size;
		std::unique_ptr<int32_t[]> map_id;
		std::unique_ptr<Color[]> col;

#if defined(__ANDROID__)//todo
		
#else
		worldMap(const Pos2& xy_) : s({ xy_.x, xy_.y }), total_size(xy_.x*xy_.y), map_id(new int32_t[xy_.x*xy_.y]), col(new Color[xy_.x*xy_.y]) { clear(); }
		worldMap(const int32_t x_, const int32_t y_) : s({ x_, y_ }), total_size(x_*y_), map_id(new int32_t[x_*y_]), col(new Color[x_*y_]) { clear(); }
#endif

		const worldMap& clear() const { for (size_t i = 0; i < total_size; ++i) map_id[i] = 0; return *this; }
		const worldMap& rand() const { asRand32(&map_id[0], total_size); return *this; }
		const worldMap& randC(const uint8_t m_) const { asRand(&col[0], total_size,m_); return *this; }

		const worldMap& draw(const size_t size_) const {
			int32_t a;
			for (size_t j = 0; j < size_t(this->s.y); ++j) {
				for (size_t i = 0; i < size_t(this->s.x); ++i) {
					a = map_id[a2(this->s.x, i, j)];
					asRect(PosL4(int32_t(i*size_), int32_t(j*size_), int32_t(size_), int32_t(size_)), Color(uint8_t(a), uint8_t(a), uint8_t(a), uint8_t(a)));
				}
			}
			return *this;
		}

		const worldMap& drawP(const size_t size_, const Pos2& p_) const {
			const int32_t a = map_id[a2(this->s.x, p_.y, p_.x)];
			asRect(PosL4(int32_t(p_.x*size_), int32_t(p_.y*size_), int32_t(size_), int32_t(size_)), Color(uint8_t(a), uint8_t(a), uint8_t(a), uint8_t(a)));
			return *this;
		}
	};

}