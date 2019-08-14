/*#######################################################################################
	Made by Kasugaccho
	Made by As Project
	https://github.com/Kasugaccho/AsLib
	wanotaitei@gmail.com

	This code is licensed under CC0.
#######################################################################################*/
#ifndef INCLUDED_AS_PROJECT_LIBRARY_MAP
#define INCLUDED_AS_PROJECT_LIBRARY_MAP


namespace AsLib
{



	//イベント起動
	enum :std::size_t {
		aslib_event_init_touch,
		aslib_event_init_tolk,
		aslib_event_auto,
		aslib_event_timer,
	};

	//イベントタイプ
	enum :std::size_t {
	aslib_event_type_empty,
	aslib_event_type_talk,
	};




	//属性
	enum :std::size_t {
		aslib_pass_true,
		aslib_pass_false,
		aslib_pass_no_wall_false,
	};
	//デフォルト属性
	enum :std::size_t {
		aslib_attribute_human,
		aslib_attribute_fish,
		aslib_attribute_bird,
		aslib_attribute_ghost,
		aslib_attribute_magma,
		aslib_attribute_no,
		aslib_attribute_num
	};
	//フィールドタイプ
	enum :std::size_t {
		aslib_texture_map_field_type_empty,
		aslib_texture_map_field_type_wall,
		aslib_texture_map_field_type_water,
		aslib_texture_map_field_type_keep_out,
	};

	constexpr std::size_t aslib_default_field_attribute_empty[aslib_attribute_num] = {
		aslib_pass_true,
		aslib_pass_true,
		aslib_pass_true,
		aslib_pass_true,
		aslib_pass_true,
		aslib_pass_false
	};
	constexpr std::size_t aslib_default_field_attribute_wall[aslib_attribute_num] = {
		aslib_pass_false,
		aslib_pass_false,
		aslib_pass_false,
		aslib_pass_true,
		aslib_pass_false,
		aslib_pass_false
	};
	constexpr std::size_t aslib_default_field_attribute_water[aslib_attribute_num] = {
		aslib_pass_no_wall_false,
		aslib_pass_true,
		aslib_pass_true,
		aslib_pass_true,
		aslib_pass_no_wall_false,
		aslib_pass_false
	};
	constexpr std::size_t aslib_default_field_attribute_keep_out[aslib_attribute_num] = {
		aslib_pass_false,
		aslib_pass_false,
		aslib_pass_false,
		aslib_pass_false,
		aslib_pass_false,
		aslib_pass_false
	};
	constexpr std::size_t aslib_default_field_attribute_magma[aslib_attribute_num] = {
		aslib_pass_no_wall_false,
		aslib_pass_no_wall_false,
		aslib_pass_true,
		aslib_pass_true,
		aslib_pass_true,
		aslib_pass_false
	};

	//dir_move
	enum :std::size_t
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
	enum :std::size_t
	{
		MOB_STOP,//静止
		MOB_MOVE1,//左足
		MOB_MOVE2,//真ん中
		MOB_MOVE3,//右足
		MOB_MOVE4,//真ん中
	};

	enum :std::size_t {
		aslib_mob_walk_type_small,
		aslib_mob_walk_type_big,
	};

	enum :std::size_t {
		aslib_texture_map_type_empty,
		aslib_texture_map_type_1n,
		aslib_texture_map_type_1n_n,
		aslib_texture_map_type_20n,
	};
	//描画タイプ
	enum :std::size_t {
		MAP_VIEW_DRAW_COLOR,
		MAP_VIEW_DRAW_ANIME,
	};

	//属性数を記録
	std::size_t asAttributeSave(const bool b_, const std::size_t p_ = 0) noexcept
	{
		static thread_local std::size_t p{ 1 };
		if (b_) p = p_;
		return p;
	}
	//属性数を取得する関数
	inline std::size_t asAttribute() noexcept { return asAttributeSave(false); }
	inline std::size_t asSetAttribute(const std::size_t p_ = 0) noexcept { return asAttributeSave(true, p_); }

	std::size_t mobMoveDirect(const std::size_t mob_direct_id, const std::size_t mob_move_id) noexcept
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
	template<typename Map_> void mapSize(const Pos2& b_, const Pos2& a_, Map_* m_, const Map_ count_ = Map_(0)) noexcept
	{
		if (b_.is_minus() || a_.is_minus()) return;
		const std::int32_t b_max{ b_.x*b_.y };
		const std::int32_t a_max{ a_.x*a_.y };

		//空白部分を任意の数字で埋める
		for (std::int32_t i{ b_max }; i < a_max; ++i) m_[i] = count_;

		if (a_.x > b_.x) {
			//値を移動
			const std::int32_t f{ ((a_.x < b_.x) ? (a_.x - 1) : (b_.x - 1)) };
			for (std::int32_t i{ b_max - b_.x }, ii{ (a_.x*b_.y) - a_.x }; i > 0; i -= b_.x, ii -= a_.x) {
				for (std::int32_t j{ f }; j >= 0; --j) {
					m_[ii + j] = m_[i + j];
					m_[i + j] = count_;
				}
			}
		}
		else if (a_.x < b_.x) {
			//値を移動
			const std::int32_t f{ ((a_.x < b_.x) ? (a_.x) : (b_.x)) };
			for (std::int32_t i{ b_.x }, ii{ a_.x }; i < b_max; i += b_.x, ii += a_.x) {
				for (std::int32_t j{}; j < f; ++j) {
					m_[ii + j] = m_[i + j];
					m_[i + j] = count_;
				}
			}
		}
		return;
	}
	//マップサイズを変更する(Vector)
	template<typename Map_> void mapSize(const Pos2& b_, const Pos2& a_, std::vector<Map_>& m_, const Map_ count_ = Map_(0)) noexcept
	{
		if (b_.is_minus() || a_.is_minus()) return;
		//const std::int32_t b_max = b_.x*b_.y;
		//const std::int32_t a_max = a_.x*a_.y;
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
	bool moveMob(const bool d_, const bool u_, const bool l_, const bool r_, const float s_, PosA4F& p_) noexcept
	{
		std::size_t count{};
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
	std::size_t moveMobCross(const bool d_, const bool u_, const bool l_, const bool r_, const float s_, PosA4F& p_) noexcept
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

	std::size_t moveMobCross(const std::size_t id_, const float s_, PosA4F& p_) noexcept
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

	inline bool moveMobCross(const float s_, PosA4F& p_) noexcept {
		return (moveMobCross(asKey(aslib_key_down), asKey(aslib_key_up), asKey(aslib_key_left), asKey(aslib_key_right), s_, p_) == MOB_CENTER) ? false : true;
	}

	bool directionMobCross(const bool d_, const bool u_, const bool l_, const bool r_, std::size_t& dir_) noexcept
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

	bool directionMobCross(std::size_t& dir_) noexcept {
		return directionMobCross(asKey(aslib_key_down), asKey(aslib_key_up), asKey(aslib_key_left), asKey(aslib_key_right), dir_);
	}

	struct AsAttribute {
		//通過設定

		//各属性のID
		std::vector<std::size_t> id;
		AsAttribute() { id.resize(asAttribute(), 0); }

		void add(const std::size_t* const type_) noexcept {
			if (type_ == nullptr) return;
			for (std::size_t i{}; i < id.size(); ++i) {
				id[i]=type_[i];
			}

		}
		AsAttribute(const std::size_t* const type_) { id.resize(asAttribute(), 0); add(type_); }

	};
	struct AsAllAttribute {
		std::vector<AsAttribute> all_id;
		AsAllAttribute() = default;
		void push(const std::size_t* const id_) noexcept {
			all_id.emplace_back(id_);
		}
	};

	//斜め移動あたり判定
	std::size_t asMoveMobDiagonal(const std::size_t lr_, const std::size_t uw_, const std::size_t dia_) noexcept {

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
	inline bool asMoveMobCross(const std::size_t lruw_) noexcept {
		return (lruw_ == aslib_pass_true) ? true : false;
	}

	std::size_t map20n_Number(const bool lr_, const bool ud_, const bool dia_) noexcept {
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
		std::size_t type = aslib_texture_map_type_empty;
		std::size_t array_num{};//配列番号
		std::size_t total_num{};
		//アニメーションフレーム
		std::size_t anime_count{ 60 };
		std::size_t anime_counter{};
		std::size_t anime_show_id{};

		//地形タイプ
		std::size_t field_type{ aslib_texture_map_field_type_empty };
		//通過設定
		std::size_t pass{ aslib_pass_true };

		AsAllAttribute* att{ nullptr };
		AsTextureMap() = default;
		AsTextureMap(const std::size_t type_, const std::size_t array_, const std::size_t ftype_, const std::size_t anime_) :type(type_),array_num(array_), anime_count(anime_), field_type(ftype_) {}
		//AsTextureMap(const std::size_t type_, const std::size_t ftype_, const std::size_t anime_) :type(type_), field_type(ftype_), anime_counter(anime_),att(asAttribute()) {}
	};

	struct AsTextureMapArray {
		//地形データ
		std::size_t s_x{};
		std::size_t s_y{};
		std::size_t s_layer{ 1 };
		std::string s_name{ u8"main" };
		std::vector<std::size_t> s;
		//地面のテクスチャデータ
		std::vector<AsTexture*> t;
		std::vector<AsTextureMap> tm;

		AsTextureMapArray() = default;

		std::unique_ptr<AsTexture[]> readMapCSV(const std::string str_, std::size_t* const s_ = nullptr, std::size_t* const var_ = nullptr) noexcept {
			std::unique_ptr<AsTexture[]> as_t;
			std::size_t read_x = 0;
			std::size_t read_y = 0;
			std::vector<std::string> name_;
			std::vector<std::size_t> vec_;
			std::vector<std::size_t> type_;
			std::vector<std::size_t> field_;
			if (asSize_t_MapReadCSV(str_, name_, vec_, type_, field_, &read_x, &read_y) != 0) {
				if (s_ != nullptr) *s_ = 0;
				if (var_ != nullptr) *var_ = this->t.size();
				return as_t;
			}
			as_t.reset(new AsTexture[read_y]);
			for (std::size_t i{}; i < name_.size(); ++i) {
				switch (type_[i])
				{
				case 1://基本タイル単体
					as_t[i](name_[i].c_str(), vec_[i]);
					this->push(&as_t[i], 0, field_[i]);
					break;
				case 2://オートタイル
					as_t[i](name_[i].c_str(), vec_[i] * 2, 10);
					this->push(&as_t[i], 0, field_[i]);
					break;
				case 3://基本タイル複数
					AsTexture ast(name_[i].c_str());
					as_t[i](name_[i].c_str(), 8, (ast.pixelSize().x == 0) ? 1 : (ast.pixelSize().y * 8 / ast.pixelSize().x));
					for (std::size_t j = 0, as_t_num = as_t[i].Num(); j < as_t_num; ++j) {
						this->push(&as_t[i], j, field_[i]);//field属性//todo
					}
					break;
				}
			}
			if (s_ != nullptr) *s_ = name_.size();
			if (var_ != nullptr) *var_ = this->t.size();
			return as_t;
		}
		std::int32_t readCSV() noexcept {
			return asMapRead(s_name, s, &s_x, &s_y, &s_layer);
		}
		std::int32_t readBackupCSV() noexcept {
			return asMapRead(u8"backup_" + s_name, s, &s_x, &s_y, &s_layer);
		}
		std::int32_t readCSV(const std::string& str_) noexcept {
			return asMapRead(str_, s, &s_x, &s_y, &s_layer);
		}
		std::int32_t writeCSV() noexcept {
			return asMapWrite(s_name, s, s_x, s_y, s_layer);
		}
		std::int32_t writeBackupCSV() noexcept {
			return asMapWrite(u8"backup_" + s_name, s, s_x, s_y, s_layer);
		}
		std::int32_t writeCSV(const std::string& str_) noexcept {
			return asMapWrite(str_, s, s_x, s_y, s_layer);
		}

		void putTexture(const std::size_t layer_ = 0) noexcept {
			if (layer_ >= s_layer) return;

			const std::size_t t_total{ t.size() };

			const std::size_t layer_min{ s_x * s_y*layer_ };
			const std::size_t layer_max{ layer_min + s_x * s_y };
			for (std::size_t i{ layer_min }, k{}; i < layer_max && k < t_total; ++i, ++k) {//
				s[i] = k;
			}
		}
		void putBlock(const std::size_t s_, const Pos2 p_, const std::size_t layer_ = 0) noexcept {
			if (p_.is_minus() || p_.x >= (signed)s_x || p_.y >= (signed)s_y || layer_ >= s_layer) return;
			this->s[layer_*this->s_x*this->s_y + p_.y*this->s_x + p_.x] = s_;
		}
		void update() noexcept {
			if (tm.size() != t.size()) return;
			for (std::size_t i{}; i < tm.size(); ++i) {
				if (t[i] == nullptr || t[i]->Num() < 2) continue;

				++tm[i].anime_counter;
				if (tm[i].anime_counter < tm[i].anime_count) continue;

				switch (tm[i].type)
				{
				case aslib_texture_map_type_1n:

					tm[i].anime_show_id = (tm[i].anime_show_id + 1) % t[i]->Num();
					tm[i].anime_counter = 0;
					break;
				case aslib_texture_map_type_1n_n:
					tm[i].anime_show_id = 0;
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
		void push(AsTexture* const t_, const std::size_t array_=0,const std::size_t ftype_= aslib_texture_map_field_type_empty, const std::size_t anime_=10) noexcept {
			std::size_t ltype{};
			if (t_ == nullptr) {
				ltype = aslib_texture_map_type_empty;
			}
			else if (t_->NumY() == 10 && t_->NumX() % 2 == 0) {
				ltype = aslib_texture_map_type_20n;
			}
			else if (t_->NumX() == 8) {
				ltype = aslib_texture_map_type_1n_n;
			}
			else {
				ltype = aslib_texture_map_type_1n;
			}

			AsTextureMap ltm(ltype, array_,ftype_, anime_);

			tm.emplace_back(ltm);
			t.emplace_back(t_);
		}

		void resizeID(const std::size_t size_) noexcept {
			std::size_t t_size{ t.size() };
			tm.resize(size_);
			t.resize(size_);
			for (std::size_t i{ t_size }; i < size_; ++i) t[i] = nullptr;
		}
		void resizeMap(const Pos2& p_, const std::size_t layer_ = 1) noexcept {
			s_x = p_.x;
			s_y = p_.y;
			s_layer = layer_;
			s.resize(p_.x*p_.y*layer_, 0);
		}
		void setLayer(const std::size_t layer_ = 1, const std::size_t var_ = 0) noexcept {
			s.resize(s_x*s_y*layer_);
			const std::size_t layer_max{ s_x * s_y };
			for (std::size_t i{}; i < layer_max; ++i) {
				s[i] = var_;
			}
			for (std::size_t i{ layer_max }; i < s.size(); ++i) {
				s[i] = 0;
			}
			s_layer = layer_;
		}
		void putMap(const std::size_t id_ = 0, const std::size_t layer_ = 0) noexcept {
			if (tm.size() < 2 || layer_ >= s_layer) return;
			const std::size_t layer_min{ s_x * s_y*layer_ };
			const std::size_t layer_max{ layer_min + s_x * s_y };
			for (std::size_t i{ layer_min }; i < layer_max; ++i) {
				s[i] = id_;
			}
		}
		void randMap(const std::size_t layer_ = 0) noexcept {
			if (tm.size() < 2 || layer_ >= s_layer) return;
			const std::size_t layer_min{ s_x * s_y*layer_ };
			const std::size_t layer_max{ layer_min + s_x * s_y };
			for (std::size_t i{ layer_min }; i < layer_max; ++i) {
				s[i] = std::size_t(1 + asRand32(std::uint32_t(tm.size() - 2)));
			}
		}
		void randMap(const std::size_t tile1_, const std::size_t tile2_, const std::size_t layer_ = 0) noexcept {
			if (tm.size() < 2 || layer_ >= s_layer || tile1_ >= tm.size() || tile2_ >= tm.size()) return;
			const std::size_t layer_min{ s_x * s_y*layer_ };
			const std::size_t layer_max{ layer_min + s_x * s_y };
			for (std::size_t i{ layer_min }; i < layer_max; ++i) {
				s[i] = (asRand8(1) == 0) ? tile1_ : tile2_;
			}
		}
		void mazeMap(const std::size_t wall_, const std::size_t empty_ = 0, const std::size_t layer_ = 0) noexcept {
			if (tm.size() < 2 || s_x % 2 == 0 || s_y % 2 == 0 || layer_ >= s_layer) return;
			const std::vector<std::size_t>& v2v1{ vector2ToVector1(asMazeMapMake(s_y, s_x, wall_, empty_)) };
			const std::size_t layer_min{ s_x * s_y*layer_ };
			const std::size_t layer_max{ layer_min + s_x * s_y };
			for (std::size_t i{ layer_min }, k{}; i < layer_max; ++i, ++k) {
				s[i] = v2v1[k];
			}	
		}
		void worldMap(const std::size_t under_, const std::size_t sea_, const std::size_t green_, const std::size_t snow_, const std::size_t seed_ = 0) noexcept {
			asWorldMapSimplePaint(s, s_x, s_y, s_layer, under_, sea_, green_, snow_, seed_);
		}

	};

	enum :std::size_t {
		aslib_map_return_empty,
		aslib_map_return_paint,
		aslib_map_return_bucket,
	};

	struct AsmapReturn {
		//巻き戻しのタイプ
		std::size_t type{ aslib_map_return_empty };
		//巻き戻しするマップID
		std::size_t id{};
		//変換後のマップID
		std::size_t after_id{};
		//座標X
		std::size_t size_x{};
		//座標Y
		std::size_t size_y{};
		//巻き戻しするレイヤー
		std::size_t layer{};
		AsmapReturn() = default;
	};

	struct AsMapReturnControl {
		//登録数の最大の長さ
		std::size_t max_len{};
		//登録数の今の長さ
		std::size_t now_len{};
		//登録数の最小数
		std::size_t min_len{};
		//最大の長さ
		std::size_t return_map_num;
		std::unique_ptr<AsmapReturn[]> return_map;

		AsMapReturnControl() = default;
		AsMapReturnControl(const std::size_t num_) :return_map_num(num_), return_map(new AsmapReturn[num_]) {}
		void reset(const std::size_t num_) noexcept {
			return_map_num = num_;
			return_map.reset(new AsmapReturn[num_]);
		}

		//登録するものを入れる
		AsMapReturnControl& push(const std::size_t type_, const std::size_t id_, const std::size_t after_id_, const std::size_t x_, const std::size_t y_, const std::size_t layer_) noexcept {
			if (id_ == after_id_) return *this;
			AsmapReturn* b{ &return_map[(max_len - 1 + return_map_num) % return_map_num] };
			if (b->size_x == x_ && b->size_y == y_ && b->layer == layer_ && b->after_id == after_id_) return *this;

			max_len = now_len;

			return_map[max_len].type = type_;
			return_map[max_len].id = id_;
			return_map[max_len].after_id = after_id_;
			return_map[max_len].size_x = x_;
			return_map[max_len].size_y = y_;
			return_map[max_len].layer = layer_;

			++max_len;
			max_len %= return_map_num;

			if (max_len == min_len) {
				++min_len;
				min_len %= return_map_num;
			}

			now_len = max_len;
			return *this;
		}

		AsMapReturnControl& left(AsTextureMapArray* const tma_) noexcept {
			if (tma_ == nullptr || now_len == min_len) return *this;
			--now_len;
			now_len += return_map_num;
			now_len %= return_map_num;
			std::size_t x, y, id, layer;

			switch (return_map[now_len].type)
			{
			case aslib_map_return_empty:return *this;
			case aslib_map_return_paint:
				x = return_map[now_len].size_x;
				y = return_map[now_len].size_y;
				id = return_map[now_len].id;
				layer = return_map[now_len].layer;
				tma_->s[(tma_->s_x*y + x) + tma_->s_x*tma_->s_y*layer] = id;
				return *this;
			case aslib_map_return_bucket:
				x = return_map[now_len].size_x;
				y = return_map[now_len].size_y;
				id = return_map[now_len].id;
				layer = return_map[now_len].layer;

				const std::size_t wp = tma_->s_x*tma_->s_y*layer;
				const std::size_t wpm = tma_->s_x*tma_->s_y*(layer + 1);

				std::vector<std::size_t> vmap;
				vmap.resize(tma_->s_x*tma_->s_y);
				for (std::size_t i = wp, k = 0; i < wpm; ++i, ++k) vmap[k] = tma_->s[i];
				asPaintTool(vmap, tma_->s_x, x, y, id);
				for (std::size_t i = wp, k = 0; i < wpm; ++i, ++k) tma_->s[i] = vmap[k];
				return *this;
			}

			return *this;
		}
		AsMapReturnControl& right(AsTextureMapArray* const tma_) noexcept {
			if (tma_ == nullptr || now_len == max_len) return *this;
			std::size_t x, y, id, layer;

			switch (return_map[now_len].type)
			{
			case aslib_map_return_empty:return *this;
			case aslib_map_return_paint:
				x = return_map[now_len].size_x;
				y = return_map[now_len].size_y;
				id = return_map[now_len].after_id;
				layer = return_map[now_len].layer;
				tma_->s[(tma_->s_x*y + x) + tma_->s_x*tma_->s_y*layer] = id;
				break;
			case aslib_map_return_bucket:
				x = return_map[now_len].size_x;
				y = return_map[now_len].size_y;
				id = return_map[now_len].after_id;
				layer = return_map[now_len].layer;

				const std::size_t wp = tma_->s_x*tma_->s_y*layer;
				const std::size_t wpm = tma_->s_x*tma_->s_y*(layer + 1);

				std::vector<std::size_t> vmap;
				vmap.resize(tma_->s_x*tma_->s_y);
				for (std::size_t i = wp, k = 0; i < wpm; ++i, ++k) vmap[k] = tma_->s[i];
				asPaintTool(vmap, tma_->s_x, x, y, id);
				for (std::size_t i = wp, k = 0; i < wpm; ++i, ++k) tma_->s[i] = vmap[k];
				break;
			}
			++now_len;
			now_len %= return_map_num;

			return *this;
		}

	};


	//あたり判定
	bool movingCollisionDetection(const AsAllAttribute& att_, const AsTextureMapArray& tma_, const Pos2& p_, std::size_t& is_move_, const std::size_t player_id_ = aslib_attribute_human) noexcept {

		const std::size_t map_total{ tma_.s_x*tma_.s_y };
		std::size_t move_array{};
		std::size_t move_array_lr{};
		std::size_t move_array_uw{};

		bool is_moving{ false };
		std::size_t moving_id{ 4 };

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

		for (std::size_t i{}; i < tma_.s_layer; ++i) {

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
	bool directionMob(const std::size_t& moving_, std::size_t& dir_) noexcept {
		switch (moving_)
		{
		case MOB_DOWN:case MOB_UP:case MOB_LEFT:case MOB_RIGHT:
		case MOB_LEFT_UP:case MOB_RIGHT_UP:case MOB_LEFT_DOWN:case MOB_RIGHT_DOWN:
			dir_ = moving_;
			return true;
		}
		return false;
	}
	bool movingMob8_true(const AsKeyList& kl_, const float s_, PosA4F& p_, std::size_t& is_move_, std::size_t& dir_id_) noexcept {
		if (is_move_ != MOB_CENTER) return true;
		is_move_ = kl_.playerMove8();
		if (is_move_ == MOB_CENTER) return false;

		directionMob(is_move_, dir_id_);
		is_move_ = moveMobCross(is_move_, s_, p_);

		return true;
	}
	bool movingMob8(const AsAllAttribute& att_, const AsTextureMapArray& tma_, const AsKeyList& kl_, const float s_, PosA4F& p_, std::size_t& is_move_, std::size_t& dir_id_) noexcept {
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
	bool movingMob8_AI(const AsAllAttribute& att_, const AsTextureMapArray& tma_, const float s_, PosA4F& p_, std::size_t& is_move_, std::size_t& dir_id_) noexcept {
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

	inline bool moveMob(const float s_, PosA4F& p_) noexcept {
		return moveMob(asKey(aslib_key_down), asKey(aslib_key_up), asKey(aslib_key_left), asKey(aslib_key_right), s_, p_);
	}

	//イベントの属性
	enum :std::size_t {
		aslib_map_event_type_empty,
		aslib_map_event_type_mob,
		aslib_map_event_type_move,
	};
	//イベントの知能
	enum :std::size_t {
		aslib_map_event_ai_empty,
		aslib_map_event_ai_human,
		aslib_map_event_ai_ai,
		aslib_map_event_ai_stay
	};

	//メッセージウィンドウイベント管理
	struct AsEventMessageWindow {
		MessageWindow* const mw{ nullptr };
		AsEventMessageWindow(MessageWindow* const mw_, const char* const str_) :mw(mw_), str(str_) {}
		//文字
		std::string str{ "" };

		bool play() noexcept {
			if (mw == nullptr) return false;

		}
	};
	//イベント管理
	struct AsMapEventData {
		std::size_t event_type{ aslib_event_type_empty };
		AsEventMessageWindow* emw{ nullptr };

		AsMapEventData() = default;
		AsMapEventData(AsEventMessageWindow* emw_) :event_type(aslib_event_type_talk),emw(emw_) {}
	};
	//マップ上のイベント管理
	struct AsMapEvent {
		//イベントタイプ
		std::size_t type{ aslib_map_event_type_empty };
		//行動
		std::size_t ai{ aslib_map_event_ai_ai };
		//向き
		std::size_t dir_id{ MOB_DOWN };
		//移動ID
		std::size_t move_id{ MOB_STOP };
		//移動状態
		std::size_t moving{ MOB_CENTER };
		//移動属性(あたり判定の種類)
		std::size_t pl_field_type{ aslib_attribute_human };
		//アニメーションフレーム
		std::size_t count{};
		std::size_t move_count_max{ 6 };
		//位置と大きさ
		PosA4F pl;
		//移動する距離(移動速度)
		float fps{ 0.1f };
		//移動頻度(NEW)
		float move_cadence{ 0.1f };
		//画像
		AsTexture* t{ nullptr };
		//あたり判定
		bool is_collision_detection{ true };
		//イベント中
		std::size_t is_event{};

		//イベント開始条件
		std::size_t event_init{ aslib_event_init_touch };
		//イベント開始範囲
		PosA4F event_init_pos;

		//イベントデータ
		std::vector<AsMapEventData> med;

		AsMapEvent(AsTexture* const t_ = nullptr, const PosA4F& p_ = { 0.0f,0.0f,1.0f,1.0f }, const std::size_t& type_ = aslib_map_event_type_empty, const std::size_t ai_ = aslib_map_event_ai_ai) :type(type_), ai(ai_), pl(p_), t(t_) {}
	};

	std::size_t movingMob(AsMapEvent* const me_,const std::size_t x_,const std::size_t y_) noexcept {
		if (me_ == nullptr) return MOB_CENTER;

		const Pos2F p2f(me_->pl.x, me_->pl.y);
		switch (me_->moving)
		{
		case MOB_DOWN:
			me_->pl.y += me_->fps;
			if (floor(p2f.y) == floor(me_->pl.y)) return me_->moving;
				me_->moving = MOB_CENTER;
				me_->pl.y = float((std::int32_t(floor(me_->pl.y)) + y_) % y_);
			return me_->moving;
		case MOB_UP:
			me_->pl.y -= me_->fps;
			if (floor(p2f.y) == floor(me_->pl.y)) return me_->moving;
				me_->moving = MOB_CENTER;
				me_->pl.y = float((std::int32_t(floor(me_->pl.y) + 1.0f) + y_) % y_);
			return me_->moving;
		case MOB_LEFT:
			me_->pl.x -= me_->fps;
			if (floor(p2f.x) == floor(me_->pl.x)) return me_->moving;
				me_->moving = MOB_CENTER;
				me_->pl.x = float((std::int32_t(floor(me_->pl.x) + 1.0f) + x_) % x_);
			return me_->moving;
		case MOB_RIGHT:
			me_->pl.x += me_->fps;
			if (floor(p2f.x) == floor(me_->pl.x)) return me_->moving;
				me_->moving = MOB_CENTER;
				me_->pl.x = float((std::int32_t(floor(me_->pl.x)) + x_) % x_);
			return me_->moving;
		case MOB_LEFT_UP:
			me_->pl.x -= me_->fps;
			me_->pl.y -= me_->fps;
			if (floor(p2f.x) != floor(me_->pl.x)) {
				me_->moving = MOB_UP;
				me_->pl.x = float((std::int32_t(floor(me_->pl.x) + 1.0f) + x_) % x_);
			}
			if (floor(p2f.y) != floor(me_->pl.y)) {
				me_->moving = (me_->moving == MOB_UP) ? MOB_CENTER : MOB_LEFT;
				me_->pl.y = float((std::int32_t(floor(me_->pl.y) + 1.0f) + y_) % y_);
			}
			return me_->moving;
		case MOB_RIGHT_UP:
			me_->pl.x += me_->fps;
			me_->pl.y -= me_->fps;
			if (floor(p2f.x) != floor(me_->pl.x)) {
				me_->moving = MOB_UP;
				me_->pl.x = float((std::int32_t(floor(me_->pl.x)) + x_) % x_);
			}
			if (floor(p2f.y) != floor(me_->pl.y)) {
				me_->moving = (me_->moving == MOB_UP) ? MOB_CENTER : MOB_RIGHT;
				me_->pl.y = float((std::int32_t(floor(me_->pl.y) + 1.0f) + y_) % y_);
			}
			return me_->moving;
		case MOB_LEFT_DOWN:
			me_->pl.x -= me_->fps;
			me_->pl.y += me_->fps;
			if (floor(p2f.x) != floor(me_->pl.x)) {
				me_->moving = MOB_DOWN;
				me_->pl.x = float((std::int32_t(floor(me_->pl.x) + 1.0f) + x_) % x_);
			}
			if (floor(p2f.y) != floor(me_->pl.y)) {
				me_->moving = (me_->moving == MOB_DOWN) ? MOB_CENTER : MOB_LEFT;
				me_->pl.y = float((std::int32_t(floor(me_->pl.y)) + y_) % y_);
			}
			return me_->moving;
		case MOB_RIGHT_DOWN:
			me_->pl.x += me_->fps;
			me_->pl.y += me_->fps;
			if (floor(p2f.x) != floor(me_->pl.x)) {
				me_->moving = MOB_DOWN;
				me_->pl.x = float((std::int32_t(floor(me_->pl.x)) + x_) % x_);
			}
			if (floor(p2f.y) != floor(me_->pl.y)) {
				me_->moving = (me_->moving == MOB_DOWN) ? MOB_CENTER : MOB_RIGHT;
				me_->pl.y = float((std::int32_t(floor(me_->pl.y)) + y_) % y_);
			}
			return me_->moving;
		}
		return me_->moving;
	}
	//mobに歩行アニメーションをさせる
	bool mobMoveSet(AsMapEvent* const me_) noexcept {
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
		Pos2 size{ 1,1 };
		std::size_t view_id{};
		std::size_t walk_type{ aslib_mob_walk_type_small };

		bool is_spawn{ true };

		AsMapEventControl() = default;
		std::vector<AsMapEvent> me;
		AsMapEventControl(const Pos2 size_,const std::size_t walk_type_, AsTexture* const t_ = nullptr, const PosA4F& p_ = { 0.0f,0.0f,1.0f,1.0f }, const std::size_t& type_ = aslib_map_event_type_empty) :size(size_),walk_type(walk_type_) { me.emplace_back(t_,p_, type_, aslib_map_event_ai_human); }

		void reset(const Pos2 size_, const std::size_t walk_type_, AsTexture* const t_ = nullptr, const PosA4F& p_ = { 0.0f,0.0f,1.0f,1.0f }, const std::size_t& type_ = aslib_map_event_type_empty) noexcept {
			size=size_; 
			walk_type = walk_type_;
			
			me.clear();
			me.emplace_back(t_, p_, type_, aslib_map_event_ai_human);
		}

		void add(AsTexture* const t_ = nullptr, const PosA4F& p_ = { 0.0f,0.0f,1.0f,1.0f }, const std::size_t& type_ = aslib_map_event_type_empty, const std::size_t ai_ = aslib_map_event_ai_ai) noexcept {
			if(is_spawn) me.emplace_back(t_, p_, type_, ai_);
		}
		//初期イベント管理・実行
		AsMapEventControl& start_event(std::size_t me_id_) noexcept {
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
		AsMapEventControl& play_event() noexcept {
			for (std::size_t i{}; i < me.size(); ++i) {
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

		AsMapEventControl& talk(const bool is_true) noexcept {
			//会話キーが押されていない・視点が配列外・視点キャラが移動中
			if (!is_true || view_id >= me.size() || me[view_id].moving != MOB_CENTER) return *this;
			Pos2 player_pos(std::int32_t(me[view_id].pl.x), std::int32_t(me[view_id].pl.y));
			switch (me[view_id].dir_id)
			{
			case MOB_DOWN:
				player_pos.x = std::int32_t(me[view_id].pl.x);
				player_pos.y = (std::int32_t(me[view_id].pl.y) + 1) % size.y;
				break;
			case MOB_UP:
				player_pos.x = std::int32_t(me[view_id].pl.x);
				player_pos.y = (std::int32_t(me[view_id].pl.y) - 1 + size.y) % size.y;
				break;
			case MOB_LEFT:
				player_pos.x = (std::int32_t(me[view_id].pl.x) - 1 + size.x) % size.x;
				player_pos.y = std::int32_t(me[view_id].pl.y);
				break;
			case MOB_RIGHT:
				player_pos.x = (std::int32_t(me[view_id].pl.x) + 1) % size.x;
				player_pos.y = std::int32_t(me[view_id].pl.y);
				break;
			case MOB_LEFT_UP:
				player_pos.x = (std::int32_t(me[view_id].pl.x) - 1 + size.x) % size.x;
				player_pos.y = (std::int32_t(me[view_id].pl.y) - 1 + size.y) % size.y;
				break;
			case MOB_RIGHT_UP:
				player_pos.x = (std::int32_t(me[view_id].pl.x) + 1) % size.x;
				player_pos.y = (std::int32_t(me[view_id].pl.y) - 1 + size.y) % size.y;
				break;
			case MOB_LEFT_DOWN:
				player_pos.x = (std::int32_t(me[view_id].pl.x) - 1 + size.x) % size.x;
				player_pos.y = (std::int32_t(me[view_id].pl.y) + 1) % size.y;
				break;
			case MOB_RIGHT_DOWN:
				player_pos.x = (std::int32_t(me[view_id].pl.x) + 1) % size.x;
				player_pos.y = (std::int32_t(me[view_id].pl.y) + 1) % size.y;
				break;
			}
			for (std::size_t i{}; i < me.size(); ++i) {
				//選択イベントの開始条件が会話じゃない・選択イベントが移動中・イベントがONになっている・イベント数が0
				if (me[i].event_init != aslib_event_init_tolk || me[i].moving != MOB_CENTER || me[i].is_event > 0 || me[i].med.size() == 0) continue;
				//視点キャラの向いている方向にいるかどうか
				if (std::int32_t(me[i].pl.x) != player_pos.x || std::int32_t(me[i].pl.y) != player_pos.y) continue;
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
		AsMapEventControl& spawn(const float rand_) noexcept {
			if (std::uint32_t(UINT32_MAX*(rand_/100.0f)) >= asRand32()) is_spawn = true;
			else is_spawn = false;
			return *this;
		}
		AsMapEventControl& setSpawn(const PosA4F p_) noexcept {
			if (view_id >= me.size()) return *this;
			me[view_id].pl = p_;
			return *this;
		}
		AsMapEventControl& setLandSpawn(const AsTextureMapArray& tma_, AsAllAttribute& att_) noexcept {
			if (view_id >= me.size()) return *this;
			const std::size_t xy_{ tma_.s_x*tma_.s_y };
			const std::size_t pl_field{ me[view_id].pl_field_type };

			for (std::size_t i{}, k{}; i < xy_; ++i) {
				if (att_.all_id[tma_.tm[tma_.s[i]].field_type].id[pl_field] != aslib_pass_true) continue;
				for (std::size_t j{ 1 }; j < tma_.s_layer; ++j) {
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
		AsMapEventControl& spawn() noexcept { is_spawn = true; return *this; }

		void update(const AsTextureMapArray& tma_, const AsAllAttribute& att_, const AsKeyList& kl_) noexcept {
			for (std::size_t i{}; i < me.size(); ++i) {
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
				case aslib_map_event_ai_empty:
					me[i].moving = movingMob(&me[i], tma_.s_x, tma_.s_y);
					if (movingMob8_true(kl_, me[i].fps, me[i].pl, me[i].moving, me[i].dir_id)) {
						mobMoveSet(&me[i]);
					}
					else me[i].move_id = MOB_STOP;
					break;
				case aslib_map_event_ai_stay:

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
		AsMapView(const PosA4F& p_) : p(p_) {}
		AsMapView(const PosA4F& p_, const char c_, Pos4 area_ = aslib_default_area) : p(p_) {
			if (!isArea(area_)) area_ = asWindowSize4();
			const Pos2F mm(float(area_.x2 - area_.x1), float(area_.y2 - area_.y1));
			switch (c_)
			{
				//正方形
			case 'x': p.h = p.w*(mm.y / mm.x); break;
			case 'y': p.w = p.h*(mm.x / mm.y); break;
				//画面サイズと同比率
			case 'X': p.h = p.w; break;
			case 'Y': p.w = p.h; break;
			}
		}
		//todo
		AsMapView& reset(const PosA4F& p_, const char c_, Pos4 area_ = aslib_default_area) noexcept {
			p = p_;
			if (!isArea(area_)) area_ = asWindowSize4();
			const Pos2F mm(float(area_.x2 - area_.x1), float(area_.y2 - area_.y1));
			switch (c_)
			{
				//正方形
			case 'x': p.h = p.w*(mm.y / mm.x); break;
			case 'y': p.w = p.h*(mm.x / mm.y); break;
				//画面サイズと同比率
			case 'X': p.h = p.w; break;
			case 'Y': p.w = p.h; break;
			}
			return *this;
		}
		AsMapView& setLookSize(const PosA4F& p_, const char c_, Pos4 area_ = aslib_default_area) noexcept {
			p = p_;
			if (!isArea(area_)) area_ = asWindowSize4();
			const Pos2F mm(float(area_.x2 - area_.x1), float(area_.y2 - area_.y1));
			switch (c_)
			{
				//正方形
			case 'x': p.h = p.w*(mm.y / mm.x); break;
			case 'y': p.w = p.h*(mm.x / mm.y); break;
				//画面サイズと同比率
			case 'X': p.h = p.w; break;
			case 'Y': p.w = p.h; break;
			}
			return *this;
		}
	private:
		//マップの中心位置と幅
		PosA4F p;
		//マップサイズ
		Pos2 p2;

		//チップを描画
		AsMapView& drawChip(AsTexture* const t_, const std::size_t id_, const Pos4& p_, const std::uint8_t a_, const Pos4& area_) noexcept {
			if (t_ == nullptr) return *this;
			t_->drawArea(id_, p_, a_, area_);
			return *this;
		}

		//マップ描画・分岐
		AsMapView& drawMapBranch(const AsTextureMapArray* const a_, const std::size_t s_num, const Pos2F& draw_map, const Pos4& area_, const std::size_t draw_layer_plus, const Pos2& select_map, const Pos2F& m) noexcept {
			if (a_ == nullptr) return *this;
			AsTexture* const texture_id{ a_->t[s_num] };
			if (texture_id == nullptr) return *this;
			switch (a_->tm[s_num].type)
			{
			case aslib_texture_map_type_1n:
				this->drawChip(texture_id, a_->tm[s_num].anime_show_id, Pos4(std::int32_t(draw_map.x), std::int32_t(draw_map.y), std::int32_t(draw_map.x + m.x), std::int32_t(draw_map.y + m.y)), 255, area_);
				break;
			case aslib_texture_map_type_1n_n:
				this->drawChip(texture_id, a_->tm[s_num].array_num, Pos4(std::int32_t(draw_map.x), std::int32_t(draw_map.y), std::int32_t(draw_map.x + m.x), std::int32_t(draw_map.y + m.y)), 255, area_);
				break;
			case aslib_texture_map_type_20n:
				const std::size_t pym{ std::size_t(((select_map.y - 1 + p2.y) % p2.y)*p2.x) };
				const std::size_t pxm{ std::size_t(((select_map.x - 1 + p2.x) % p2.x)) };
				if (pym + pxm + draw_layer_plus >= a_->s.size()) return *this;
				const std::size_t pyp{ std::size_t(((select_map.y + 1) % p2.y)*p2.x) };
				const std::size_t pxp{ std::size_t(((select_map.x + 1) % p2.x)) };
				const std::size_t tm_id{ a_->tm[s_num].anime_show_id };

				const bool map_left_up{ (a_->s[pym + pxm + draw_layer_plus] == s_num) };
				const bool map_up{ (a_->s[pym + select_map.x + draw_layer_plus] == s_num) };
				const bool map_right_up{ (a_->s[pym + pxp + draw_layer_plus] == s_num) };
				const bool map_left{ (a_->s[select_map.y*p2.x + pxm + draw_layer_plus] == s_num) };
				const bool map_right{ (a_->s[select_map.y*p2.x + pxp + draw_layer_plus] == s_num) };
				const bool map_left_down{ (a_->s[pyp + pxm + draw_layer_plus] == s_num) };
				const bool map_down{ (a_->s[pyp + select_map.x + draw_layer_plus] == s_num) };
				const bool map_right_down{ (a_->s[pyp + pxp + draw_layer_plus] == s_num) };

				this->drawChip(texture_id, texture_id->NumX() * 2 * map20n_Number(map_left, map_up, map_left_up) + tm_id, Pos4(std::int32_t(draw_map.x), std::int32_t(draw_map.y), std::int32_t(draw_map.x + m.x / 2.0f), std::int32_t(draw_map.y + m.y / 2.0f)), 255, area_);
				this->drawChip(texture_id, texture_id->NumX() * 2 * map20n_Number(map_right, map_up, map_right_up) + tm_id + 1, Pos4(std::int32_t(draw_map.x + m.x / 2.0f), std::int32_t(draw_map.y), std::int32_t(draw_map.x + m.x), std::int32_t(draw_map.y + m.y / 2.0f)), 255, area_);
				this->drawChip(texture_id, texture_id->NumX() * 2 * map20n_Number(map_left, map_down, map_left_down) + tm_id + texture_id->NumX(), Pos4(std::int32_t(draw_map.x), std::int32_t(draw_map.y + m.y / 2.0f), std::int32_t(draw_map.x + m.x / 2.0f), std::int32_t(draw_map.y + m.y)), 255, area_);
				this->drawChip(texture_id, texture_id->NumX() * 2 * map20n_Number(map_right, map_down, map_right_down) + tm_id + 1 + texture_id->NumX(), Pos4(std::int32_t(draw_map.x + m.x / 2.0f), std::int32_t(draw_map.y + m.y / 2.0f), std::int32_t(draw_map.x + m.x), std::int32_t(draw_map.y + m.y)), 255, area_);
				return *this;
			}
			return *this;
		}

		//マップ描画・X座標
		AsMapView& drawMapX(const AsTextureMapArray* const a_, const Pos4& in_map, Pos2F& draw_map, const Pos4& area_, const std::size_t draw_layer_plus, Pos2& select_map, const Pos2F& m) noexcept {
			if (a_ == nullptr) return *this;
			std::size_t array_num{};
			std::size_t s_num{};
			//X軸指定
			for (std::int32_t j{ in_map.x1 }; j < in_map.x2; ++j) {
				draw_map.x += m.x;
				select_map.x = j;
				while (select_map.x < 0) select_map.x += p2.x;
				select_map.x = select_map.x % p2.x;
				//描画するデータのある配列の場所
				array_num = select_map.y*p2.x + select_map.x + draw_layer_plus;
				//例外
				if (array_num >= a_->s.size() || (s_num = a_->s[array_num]) >= a_->tm.size()) return *this;
				//画像がないとき
				if (a_->t[s_num] == nullptr) continue;
				this->drawMapBranch(a_, s_num, draw_map, area_, draw_layer_plus, select_map, m);
			}
			return *this;
		}

		//マップ描画・Y座標
		AsMapView& drawMapY(const AsTextureMapArray* const a_, const Pos2F& in_draw,const Pos4& in_map, Pos2F& draw_map, const Pos4& area_, const std::size_t draw_layer_plus, const Pos2F& m) noexcept {
			if (a_ == nullptr) return *this;
			Pos2 select_map;
			//Y軸指定
			for (std::int32_t i{ in_map.y1 }; i < in_map.y2; ++i) {
				draw_map.x = in_draw.x;
				draw_map.y += m.y;
				select_map.y = i;
				while (select_map.y < 0) select_map.y += p2.y;
				select_map.y = select_map.y % p2.y;
				this->drawMapX(a_, in_map, draw_map, area_, draw_layer_plus, select_map, m);
			}
			return *this;
		}
		//マップ描画・レイヤー
		AsMapView& drawMapLayer(const std::size_t min_,const std::size_t max_,const AsTextureMapArray* const a_, const Pos2F& in_draw, const Pos4& in_map, const Pos4& area_, const Pos2F& m) noexcept {
			if (a_ == nullptr) return *this;
			const std::size_t layer_plus{ std::size_t(p2.x*p2.y) };
			std::size_t draw_layer_plus{ layer_plus };
			Pos2F draw_map(in_draw);
			//レイヤー指定
			for (std::size_t layer{ min_ }; layer < max_; ++layer) {
				draw_layer_plus = layer_plus * layer;
				draw_map = in_draw;
				this->drawMapY(a_, in_draw, in_map, draw_map, area_, draw_layer_plus, m);
			}
			return *this;
		}

		AsMapView& drawMap(const std::size_t* const min_ = nullptr, const std::size_t* const max_ = nullptr, AsTextureMapArray* const a_ = nullptr, Pos4 area_ = aslib_default_area) noexcept
		{
			if (a_ == nullptr) return *this;
			if (!isArea(area_)) area_ = asWindowSize4();
			//中心幅
			const Pos2F ce_length(this->p.w / 2.0f, this->p.h / 2.0f);
			//前
			const Pos2F be_pos(this->p.x - ce_length.x, this->p.y - ce_length.y);
			//後
			const Pos2F af_pos(this->p.x + ce_length.x, this->p.y + ce_length.y);

			//1マスの描画幅
			const Pos2F m((area_.x2 - area_.x1) / this->p.w, (area_.y2 - area_.y1) / this->p.h);
			//描画初期位置
			const Pos2F in_draw((floor(be_pos.x) - be_pos.x)*m.x - m.x, (floor(be_pos.y) - be_pos.y)*m.y - m.y);
			
			//開始から終了まで
			const Pos4 in_map{ Pos4(Pos4F(floor(be_pos.x), floor(be_pos.y), ceil(af_pos.x), ceil(af_pos.y))) };
			const std::size_t&& draw_layer_min{ (min_ == nullptr) ? 0 : *min_ };
			const std::size_t&& draw_layer_max{ (max_ == nullptr) ? ((min_ == nullptr) ? a_->s_layer : (*min_ + 1)) : *max_ };
			this->drawMapLayer(draw_layer_min, draw_layer_max, a_, in_draw, in_map, area_, m);
			return *this;
		}

	public:

		//中心位置を指定--------------------------------------------------------------

		//
		AsMapView& setMap(const Pos2& p2_) noexcept {
			if (p2_.is_minus()) return *this;
			p2 = p2_;
			return *this;
		}

		//視点変更
		AsMapView& setMobView(PosA4F& p_, const std::size_t type_ = aslib_mob_walk_type_small) noexcept {
			const Pos2F p2f{ p2 };
			while (p_.x < 0.0f) { p_.x += p2f.x; }
			while (p_.y < 0.0f) { p_.y += p2f.y; }
			p.x = p_.x += float(std::int32_t(p_.x) % p2.x) - floor(p_.x);
			p.y = p_.y += float(std::int32_t(p_.y) % p2.y) - floor(p_.y);

			if (type_ == aslib_mob_walk_type_big) {
				p.x += 0.5f;
				p.y += (0.6f - 0.3f*p_.h);
			}
			return *this;
		}
		AsMapView& setTouchSlide(AsMapEventControl& mec_, Pos4 area_ = aslib_default_area, const char c_ = 'o') noexcept {
			if (mec_.view_id >= mec_.me.size()) return *this;
			if (!isArea(area_)) area_ = asWindowSize4();
			//1マスの描画幅
			const Pos2F m((area_.x2 - area_.x1) / this->p.w, (area_.y2 - area_.y1) / this->p.h);
			if (c_ != 'y')  mec_.me[mec_.view_id].pl.x += float(asTouchSlide(area_).x) / m.x;
			if (c_ != 'x') mec_.me[mec_.view_id].pl.y += float(asTouchSlide(area_).y) / m.y;
			return *this;
		}
		AsMapView& setMouseSlide(AsMapEventControl& mec_, Pos4 area_ = aslib_default_area, const char c_ = 'o') noexcept {
			if (mec_.view_id >= mec_.me.size()) return *this;
			if (!isArea(area_)) area_ = asWindowSize4();
			//1マスの描画幅
			const Pos2F m((area_.x2 - area_.x1) / this->p.w, (area_.y2 - area_.y1) / this->p.h);
			if (c_ != 'y')  mec_.me[mec_.view_id].pl.x += float(asMouseSlide(area_).x) / m.x;
			if (c_ != 'x') mec_.me[mec_.view_id].pl.y += float(asMouseSlide(area_).y) / m.y;
			return *this;
		}
		AsMapView& setMobView(AsMapEventControl& mec_) noexcept {
			if (mec_.view_id >= mec_.me.size()) return *this;
			this->setMobView(mec_.me[mec_.view_id].pl, mec_.walk_type);
			return *this;
		}
		AsMapView& setMobPos(PosA4F& p_) noexcept {
			const Pos2F p2f{ p2 };
			while (p_.x < 0.0f) { p_.x += p2f.x; }
			while (p_.y < 0.0f) { p_.y += p2f.y; }
			p_.x += float(std::int32_t(p_.x) % p2.x) - floor(p_.x);
			p_.y += float(std::int32_t(p_.y) % p2.y) - floor(p_.y);
			return *this;
		}
		AsMapView& setMobPos(std::vector<PosA4F>& p_) noexcept {
			const Pos2F p2f{ p2 };
			for (std::size_t i{}; i < p_.size(); ++i) {
				while (p_[i].x < 0.0f) { p_[i].x += p2f.x; }
				while (p_[i].y < 0.0f) { p_[i].y += p2f.y; }
				p_[i].x += float(std::int32_t(p_[i].x) % p2.x) - floor(p_[i].x);
				p_[i].y += float(std::int32_t(p_[i].y) % p2.y) - floor(p_[i].y);
			}
			return *this;
		}
		AsMapView& setMap(const PosA4F& p_) noexcept { p = p_; return *this; }
		AsMapView& setMapX(const PosA4F& p_) noexcept { p = p_; p.h = p.w*(float(asWindowSize().y) / float(asWindowSize().x)); return *this; }
		
		enum :std::size_t {
			aslib_map_view_type_paint,
			aslib_map_view_type_select,
			aslib_map_view_type_bucket,
			aslib_map_view_type_mouse_select,
			aslib_map_view_type_event_select,
		};
		//鉛筆ツール
		bool allSelect(const std::size_t type_, AsTextureMapArray* const t_ = nullptr, AsMapEventControl* const mec_ = nullptr, AsMapReturnControl* const mrc_ = nullptr, const std::size_t layer_ = 0, Pos2* const p_=nullptr, std::size_t* const id_ = 0, Pos4 area_ = aslib_default_area) noexcept
		{
			switch (type_)
			{
			case aslib_map_view_type_paint:
			case aslib_map_view_type_bucket:
			case aslib_map_view_type_select:
			case aslib_map_view_type_mouse_select:
				//nullptrの場合
				if (t_ == nullptr || t_->t.size() == 0) return false;
				break;
			case aslib_map_view_type_event_select:
				//nullptrの場合
				if (mec_ == nullptr || mec_->me.size() == 0) return false;
				break;
			}


			if (!isArea(area_)) area_ = asWindowSize4();
			//1マスの描画幅
			const Pos2F m((area_.x2 - area_.x1) / this->p.w, (area_.y2 - area_.y1) / this->p.h);
			//中央
			const Pos2 pos(area_.x1 + (area_.x2 - area_.x1) / 2, area_.y1 + (area_.y2 - area_.y1) / 2);
			Pos2 t_p;
			Pos2 draw_p;
			std::size_t draw_id{};
			bool is_touch{ false };

			const std::size_t wp{ p2.x*p2.y*layer_ };
			const std::size_t wpm{ p2.x*p2.y*(layer_ + 1) };

			std::vector<std::size_t> vmap;

			std::size_t touch_num{ asTouchNum() };
			for (std::size_t i{}; i <= touch_num; ++i) {
				if (i == touch_num) {
					if (type_ != aslib_map_view_type_mouse_select && !asMouseL()) return false;
					t_p = mousePos();
				}
				else t_p = asTouch(i);

				if (!isArea(area_, t_p)) continue;
				is_touch = true;

				draw_p.y = std::int32_t(floor(this->p.y + float(t_p.y - pos.y) / m.y));
				draw_p.x = std::int32_t(floor(this->p.x + float(t_p.x - pos.x) / m.x));

				while (draw_p.x < 0) { draw_p.x += p2.x; }
				while (draw_p.y < 0) { draw_p.y += p2.y; }
				draw_p.x %= p2.x;
				draw_p.y %= p2.y;

				if (p_ != nullptr) *p_ = Pos2(draw_p.x, draw_p.y);

				switch (type_)
				{
				case aslib_map_view_type_paint:
					//書き換え
					if (mrc_ != nullptr) mrc_->push(aslib_map_return_paint, t_->s[draw_id = draw_p.y*p2.x + draw_p.x + wp], *id_, draw_p.x, draw_p.y, layer_);
					t_->s[draw_id] = *id_;
					break;
				case aslib_map_view_type_bucket:
					if (!asTouchDown() && !asMouseL_Down()) continue;
						//書き換え
						if (mrc_ != nullptr) mrc_->push(aslib_map_return_bucket, t_->s[draw_id = draw_p.y*p2.x + draw_p.x + wp], *id_, draw_p.x, draw_p.y, layer_);
						vmap.resize(t_->s_x*t_->s_y);
						for (std::size_t ii{ wp }, k{}; ii < wpm; ++ii, ++k) vmap[k] = t_->s[ii];
						asPaintTool(vmap, t_->s_x, draw_p.x, draw_p.y, *id_);
						for (std::size_t ii{ wp }, k{}; ii < wpm; ++ii, ++k) t_->s[ii] = vmap[k];
					return true;
				case aslib_map_view_type_select:
				case aslib_map_view_type_mouse_select:
					//選択
					if (id_ != nullptr) *id_ = t_->s[draw_p.y*p2.x + draw_p.x + wp];
					return true;
				case aslib_map_view_type_event_select:
					for (std::size_t ii{ 1 }; ii < mec_->me.size(); ++ii) {
						if (std::int32_t(floor(mec_->me[ii].pl.x)) != draw_p.x || std::int32_t(floor(mec_->me[ii].pl.y)) != draw_p.y) continue;
						mec_->me[ii].pl.x += 1.0f;
						return true;
					}
					return false;
				}
			}
			return is_touch;
		}
		//イベント選択ツール
		const bool eventSelect(AsMapEventControl* const mec_ = nullptr, AsMapReturnControl* const mrc_ = nullptr, const std::size_t layer_ = 0, Pos2* const p_ = nullptr, std::size_t* const id_ = 0, Pos4 area_ = aslib_default_area) noexcept
		{
			return this->allSelect(aslib_map_view_type_event_select, nullptr, mec_, mrc_, layer_, p_, id_, area_);
		}
		//塗りツール
		const bool bucket(AsTextureMapArray* const t_ = nullptr, AsMapReturnControl* const mrc_ = nullptr, const std::size_t layer_ = 0, std::size_t id_ = 0, Pos4 area_ = aslib_default_area) noexcept
		{
			return this->allSelect(aslib_map_view_type_bucket, t_, nullptr, mrc_, layer_, nullptr, &id_, area_);
		}
		//鉛筆ツール
		const bool paint(AsTextureMapArray* const t_ = nullptr, AsMapReturnControl* const mrc_=nullptr, const std::size_t layer_ = 0, std::size_t id_ = 0,Pos4 area_=aslib_default_area) noexcept
		{
			return this->allSelect(aslib_map_view_type_paint, t_, nullptr, mrc_, layer_, nullptr, &id_, area_);
		}
		//選択ツール
		const bool select(AsTextureMapArray* const t_ = nullptr, AsMapReturnControl* const mrc_ = nullptr, const std::size_t layer_ = 0, Pos2* const p_=nullptr, std::size_t* const id_ = 0,Pos4 area_ = aslib_default_area) noexcept
		{
			return this->allSelect(aslib_map_view_type_select, t_, nullptr, mrc_, layer_, p_, id_, area_);
		}
		//マウス位置ツール
		const bool mouseSelect(AsTextureMapArray* const t_ = nullptr, AsMapReturnControl* const mrc_ = nullptr, const std::size_t layer_ = 0, Pos2* const p_ = nullptr, std::size_t* const id_ = 0, Pos4 area_ = aslib_default_area) noexcept
		{
			return this->allSelect(aslib_map_view_type_mouse_select, t_, nullptr, mrc_, layer_, p_, id_, area_);
		}
		//イベント描画
		AsMapView& drawEvent(AsMapEventControl* const mec_, const Pos2F& draw_map, const Pos2& select_map, const Pos4& area_, const Pos2F& m) noexcept {
			if (mec_ == nullptr || mec_->me.size() == 0) return *this;
			std::size_t id_{};
			Pos2 player_p;
			PosA4F p_a4f;
			for (std::size_t k{}; k < mec_->me.size(); ++k) {
				if (mec_->me[k].t == nullptr) continue;
				if (mec_->me[k].type == aslib_map_event_type_mob) id_ = mobMoveDirect(mec_->me[k].dir_id, mec_->me[k].move_id);
				if (mec_->me[k].t->Num() <= id_) continue;

				p_a4f = (mec_->walk_type == aslib_mob_walk_type_big) ? PosA4F(mec_->me[k].pl.x + 0.5f, mec_->me[k].pl.y + 0.6f - 0.3f*mec_->me[k].pl.h, mec_->me[k].pl.w, mec_->me[k].pl.h) : mec_->me[k].pl;

				player_p = Pos2(std::int32_t(floor(p_a4f.x)), std::int32_t(floor(p_a4f.y)));
				while (player_p.x < 0) player_p.x += p2.x;
				while (player_p.y < 0) player_p.y += p2.y;

				player_p.x = player_p.x%p2.x;
				player_p.y = player_p.y%p2.y;

				if (select_map.x != player_p.x || select_map.y != player_p.y) continue;

				//描画するデータのある配列の場所
				const PosA4F&& draw_mob{ PosA4F(draw_map.x + (p_a4f.x - floor(p_a4f.x))*m.x, draw_map.y + (p_a4f.y - floor(p_a4f.y))*m.y, m.x*p_a4f.w, m.y*p_a4f.h) };
				this->drawChip(mec_->me[k].t, id_, draw_mob, (std::uint8_t)255, area_);
			}
			return *this;
		}
		//イベント描画・X軸
		AsMapView& drawEventX(AsMapEventControl* const mec_, const Pos4& in_map, Pos2F& draw_map, Pos2& select_map, const Pos4& area_, const Pos2F& m) noexcept {
			if (mec_ == nullptr || mec_->me.size() == 0) return *this;
			//X軸指定
			for (std::int32_t j{ in_map.x1 }; j < in_map.x2; ++j) {
				draw_map.x += m.x;
				select_map.x = j;
				while (select_map.x < 0) { select_map.x += p2.x; }
				select_map.x = select_map.x % p2.x;
				this->drawEvent(mec_, draw_map, select_map, area_, m);
			}
			return *this;
		}

		AsMapView& drawEventY(AsMapEventControl* const mec_, const Pos2F& in_draw,const Pos4& in_map, const Pos4& area_, const Pos2F& m) noexcept {
			if (mec_ == nullptr || mec_->me.size() == 0) return *this;
			Pos2F draw_map(in_draw);
			Pos2 select_map;
			//Y軸指定
			for (std::int32_t i{ in_map.y1 }; i < in_map.y2; ++i) {
				draw_map.x = in_draw.x;
				draw_map.y += m.y;
				select_map.y = i;
				while (select_map.y < 0) { select_map.y += p2.y; }
				select_map.y = select_map.y % p2.y;
				this->drawEventX(mec_, in_map, draw_map, select_map, area_, m);
			}
			return *this;
		}

		//描画する物のサイズ
		AsMapView& draw(AsMapEventControl* const mec_ = nullptr, Pos4 area_ = aslib_default_area) noexcept
		{
			if (mec_ == nullptr || mec_->me.size() == 0) return *this;
			if (!isArea(area_)) area_ = asWindowSize4();
			//1マスの描画幅
			const Pos2F m((area_.x2 - area_.x1) / this->p.w, (area_.y2 - area_.y1) / this->p.h);
			//中心幅
			const Pos2F ce_length(this->p.w / 2.0f, this->p.h / 2.0f);
			//前
			const Pos2F be_pos(this->p.x - ce_length.x, this->p.y - ce_length.y);
			//後
			const Pos2F af_pos(this->p.x + ce_length.x, this->p.y + ce_length.y);

			//描画初期位置
			const Pos2F in_draw((floor(be_pos.x) - be_pos.x)*m.x - m.x, (floor(be_pos.y) - be_pos.y)*m.y - m.y);
			const Pos4 in_map{ Pos4(Pos4F(floor(be_pos.x), floor(be_pos.y), ceil(af_pos.x), ceil(af_pos.y))) };

			this->drawEventY(mec_, in_draw, in_map, area_, m);
			return *this;
		}
		//画像の全体描画
		AsMapView& draw(AsTextureMapArray* const t_, const std::size_t* const min_, const std::size_t* const max_, Pos4 area_ = aslib_default_area) noexcept { return this->drawMap(min_,max_,t_,area_); }
		AsMapView& draw(AsTextureMapArray* const t_, const std::size_t* const min_, Pos4 area_ = aslib_default_area) noexcept { return this->drawMap(min_, nullptr, t_, area_); }
		AsMapView& draw(AsTextureMapArray* const t_, Pos4 area_ = aslib_default_area) noexcept { return this->drawMap(nullptr, nullptr, t_, area_); }

	};

}

#endif //Included AsProject Library