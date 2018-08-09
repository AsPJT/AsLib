//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsProject Library
//
//                    Created by Gaccho (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
	//dir
	enum :size_t
	{
		MOB_DOWN,
		MOB_UP,
		MOB_LEFT,
		MOB_RIGHT,
		MOB_LEFT_UP,
		MOB_RIGHT_UP,
		MOB_LEFT_DOWN,
		MOB_RIGHT_DOWN,
		MOB_CENTER,
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
	//フィールドタイプ
	enum :size_t {
		aslib_texture_map_field_type_empty,
		aslib_texture_map_field_type_wall,
	};

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

		AsTextureMap() = default;
		AsTextureMap(const size_t type_, const size_t ftype_, const size_t anime_) :type(type_), field_type(ftype_), anime_counter(anime_) {}
	};

	struct AsTextureMapArray {
		//地形データ
		size_t s_x = 0;
		size_t s_y = 0;
		size_t s_layer = 1;
		std::vector<size_t> s;
		//地面のテクスチャデータ
		std::vector<AsTexture*> t;
		std::vector<AsTextureMap> tm;

		void putBlock(const size_t s_, const Pos2 p_, const size_t layer_ = 0) {
			if (p_.is_minus() || p_.x >= s_x || p_.y >= s_y || layer_ >= s_layer) return;
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
		void mazeMap(const size_t wall_, const size_t empty_ = 0, const size_t layer_ = 0) {
			if (tm.size() < 2 || s_x % 2 == 0 || s_y % 2 == 0 || layer_ >= s_layer) return;
			const std::vector<size_t>& v2v1 = vector2ToVector1(asMazeMapMake(s_y, s_x, wall_, empty_));
			const size_t layer_min = s_x * s_y*layer_;
			const size_t layer_max = layer_min + s_x * s_y;
			for (size_t i = layer_min, k = 0; i < layer_max; ++i, ++k) {
				s[i] = v2v1[k];
			}
			
		}

	};

	enum :size_t {
		MAP_VIEW_DRAW_COLOR,
		MAP_VIEW_DRAW_ANIME,
	};

	//マップの見える範囲
	struct AsMapView
	{
	private:
		//マップの中心位置と幅
		PosA4F p;
		//開始から終了まで
		Pos4 in_map;
		//マップサイズ
		Pos2 p2;

		//全体の描画
		//AsMapView& drawMob(const Pos2& p_, const size_t num_, Color* const col_ = nullptr, AsTextureMapArray* const a_ = nullptr, const size_t id_ = 0)

		AsMapView& drawMap(const Pos2& p_, const size_t num_, Color* const col_ = nullptr, AsTextureMapArray* const a_ = nullptr, const size_t id_ = 0)
		{
			if (p_.is_minus()) return *this;

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
			const Pos2F ce_length(this->p.w/2.0f, this->p.h/2.0f);
			//前
			const Pos2F be_pos(this->p.x - ce_length.x, this->p.y - ce_length.y);
			//後
			const Pos2F af_pos(this->p.x + ce_length.x, this->p.y + ce_length.y);

			const size_t layer_plus = p_.x*p_.y;
			size_t draw_layer_plus = layer_plus;

			//描画初期位置
			const Pos2F in_draw((floor(be_pos.x) - be_pos.x)*m.x-m.x, (floor(be_pos.y) - be_pos.y)*m.y-m.y);
			in_map = Pos4(floor(be_pos.x), floor(be_pos.y), ceil(af_pos.x), ceil(af_pos.y));
			Pos2 select_map;
			Pos2F draw_map(in_draw);
			size_t array_num = 0;

			AsTexture* texture_id = nullptr;
			AsTextureMap* tm_id = nullptr;
			size_t map_field_type = 0;
			bool amap[8]{};
			size_t pym, pyp, pxm, pxp;



			//レイヤー指定
			for (int32_t layer = 0; layer < draw_layer_max; ++layer) {
				draw_layer_plus = layer_plus * layer;
				draw_map = in_draw;

				//Y軸指定
				for (int32_t i = in_map.y1; i < in_map.y2; ++i) {
					draw_map.x = in_draw.x;
					draw_map.y += m.y;
					select_map.y = i;
					while (select_map.y < 0) { select_map.y += p_.y; }
					select_map.y = select_map.y % p_.y;

					//X軸指定
					for (int32_t j = in_map.x1; j < in_map.x2; ++j) {
						draw_map.x += m.x;
						select_map.x = j;
						while (select_map.x < 0) { select_map.x += p_.x; }
						select_map.x = select_map.x % p_.x;

						//描画するデータのある配列の場所
						array_num = select_map.y*p_.x + select_map.x + draw_layer_plus;

						switch (num_)
						{
						case MAP_VIEW_DRAW_COLOR:
							asRect(Pos4(int32_t(draw_map.x), int32_t(draw_map.y), int32_t(draw_map.x + m.x), int32_t(draw_map.y + m.y)), col_[array_num]);
							break;
						case MAP_VIEW_DRAW_ANIME:
							if (array_num >= a_->s.size() || (texture_id = a_->t[a_->s[array_num]]) == nullptr) break;

							switch (a_->tm[a_->s[array_num]].type)
							{
							case aslib_texture_map_type_1n:
								texture_id->draw(a_->tm[a_->s[array_num]].anime_show_id, Pos4(int32_t(draw_map.x), int32_t(draw_map.y), int32_t(draw_map.x + m.x), int32_t(draw_map.y + m.y)));
								break;
							case aslib_texture_map_type_20n:
								tm_id = &a_->tm[a_->s[array_num]];
								map_field_type = tm_id->field_type;
							
								pym = ((select_map.y - 1 + p_.y) % p_.y)*p_.x;
								pyp = ((select_map.y + 1) % p_.y)*p_.x;
								pxm = ((select_map.x - 1 + p_.x) % p_.x);
								pxp = ((select_map.x + 1) % p_.x);

								amap[MOB_LEFT_UP] = (a_->tm[a_->s[pym + pxm + draw_layer_plus]].field_type == map_field_type);
								amap[MOB_UP] = (a_->tm[a_->s[pym + select_map.x + draw_layer_plus]].field_type == map_field_type);
								amap[MOB_RIGHT_UP] = (a_->tm[a_->s[pym + pxp + draw_layer_plus]].field_type == map_field_type);
								amap[MOB_LEFT] = (a_->tm[a_->s[select_map.y*p_.x + pxm + draw_layer_plus]].field_type == map_field_type);
								amap[MOB_RIGHT] = (a_->tm[a_->s[select_map.y*p_.x + pxp + draw_layer_plus]].field_type == map_field_type);
								amap[MOB_LEFT_DOWN] = (a_->tm[a_->s[pyp + pxm + draw_layer_plus]].field_type == map_field_type);
								amap[MOB_DOWN] = (a_->tm[a_->s[pyp + select_map.x + draw_layer_plus]].field_type == map_field_type);
								amap[MOB_RIGHT_DOWN] = (a_->tm[a_->s[pyp + pxp + draw_layer_plus]].field_type == map_field_type);

								texture_id->draw(texture_id->NumX() * 2 * map20n_Number(amap[MOB_LEFT], amap[MOB_UP], amap[MOB_LEFT_UP]) + tm_id->anime_show_id, Pos4(int32_t(draw_map.x), int32_t(draw_map.y), int32_t(draw_map.x + m.x / 2.0f), int32_t(draw_map.y + m.y / 2.0f)));
								texture_id->draw(texture_id->NumX() * 2 * map20n_Number(amap[MOB_RIGHT], amap[MOB_UP], amap[MOB_RIGHT_UP]) + tm_id->anime_show_id+1, Pos4(int32_t(draw_map.x + m.x / 2.0f), int32_t(draw_map.y), int32_t(draw_map.x + m.x), int32_t(draw_map.y + m.y / 2.0f)));
								texture_id->draw(texture_id->NumX() * 2 * map20n_Number(amap[MOB_LEFT], amap[MOB_DOWN], amap[MOB_LEFT_DOWN]) + tm_id->anime_show_id + texture_id->NumX(), Pos4(int32_t(draw_map.x), int32_t(draw_map.y + m.y / 2.0f), int32_t(draw_map.x + m.x / 2.0f), int32_t(draw_map.y + m.y)));
								texture_id->draw(texture_id->NumX() * 2 * map20n_Number(amap[MOB_RIGHT], amap[MOB_DOWN], amap[MOB_RIGHT_DOWN]) + tm_id->anime_show_id+1 + texture_id->NumX(), Pos4(int32_t(draw_map.x + m.x / 2.0f), int32_t(draw_map.y + m.y / 2.0f), int32_t(draw_map.x + m.x), int32_t(draw_map.y + m.y)));
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
		AsMapView() = default;
		constexpr AsMapView(const PosA4F& p_) : p(p_) {}
		AsMapView(const PosA4F& p_,const char c_) : p(p_) {
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

		//中心位置を指定--------------------------------------------------------------

		//
		AsMapView& setMap(const Pos2& p2_) {
			if (p2_.is_minus()) return *this;
			p2 = p2_;
			return *this;
		}

		//視点変更
		AsMapView& setMobView(PosA4F& p_,const size_t type_= aslib_mob_walk_type_small) {
			const Pos2F p2f = p2;
			while (p_.x < 0.0f) { p_.x += p2f.x; }
			while (p_.y < 0.0f) { p_.y += p2f.y; }
			p.x = p_.x += float(int32_t(p_.x) % p2.x) - floor(p_.x);
			p.y = p_.y += float(int32_t(p_.y) % p2.y) - floor(p_.y);

			if (type_ == aslib_mob_walk_type_big) {
				p.x += 0.5f;
				p.y += 0.3f;
			}
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
		AsMapView& setMapX(const PosA4F& p_) { p = p_; p.h = p.w*(float(asWindowSize().y) / float(asWindowSize().x)); return *this;}

		//描画する物のサイズ
		AsMapView& drawMob(const Pos4F& p_, const size_t num_, const Color* c_ = nullptr, AsTexture* a_ = nullptr,const size_t id_=0)
		{
			//範囲外は描画無し
			const Pos4F Dp = Pos4F(this->p);
			if (p_.x2 < Dp.x1 || p_.y2 < Dp.y1 || p_.x1 > Dp.x2 || p_.y1 > Dp.y2) return *this;

			const PosL4F Lp = PosL4F(this->p);
			const Pos2 w_ = asWindowSize();
			switch (num_)
			{
			case MAP_VIEW_DRAW_COLOR:
				asRect(Pos4(int32_t((p_.x1 - Lp.x) / Lp.w*w_.x), int32_t((p_.y1 - Lp.y) / Lp.h*w_.y), int32_t((p_.x2 - Lp.x) / Lp.w*w_.x), int32_t((p_.y2 - Lp.y) / Lp.h*w_.y)), *c_);
				break;
			case MAP_VIEW_DRAW_ANIME:
				a_->draw(id_,Pos4(int32_t((p_.x1 - Lp.x) / Lp.w*w_.x), int32_t((p_.y1 - Lp.y) / Lp.h*w_.y), int32_t((p_.x2 - Lp.x) / Lp.w*w_.x), int32_t((p_.y2 - Lp.y) / Lp.h*w_.y)));
				break;
			}
			return *this;
		}

		//プレイヤーの位置、マップサイズ、カラー
		AsMapView& draw(const PosA4F& p_, const Pos2& p2_, const Color& c_)
		{
			if (Pos2(p2_).is_minus()) return *this;
			return this->draw(PosA4F(float((int32_t(p_.x) + p2_.x) % p2_.x) + p_.x - floor(p_.x), float((int32_t(p_.y) + p2_.y) % p2_.y) + p_.y - floor(p_.y), p_.w, p_.h), c_);
		}
		//描画する物のサイズ、画像
		AsMapView& draw(const Pos4F& p_, const Color& c_) { return this->drawMob(p_, MAP_VIEW_DRAW_COLOR, &c_, nullptr); }

		//描画する物のサイズ、カラー
		AsMapView& draw(const Pos4F& p_, AsTexture& a_, const size_t id_ = 0) { return this->drawMob(p_, MAP_VIEW_DRAW_ANIME, nullptr, &a_, id_); }

		//プレイヤーの位置、マップサイズ、画像
		AsMapView& draw(const PosA4F& p_, const Pos2& p2_, AsTexture& t_)
		{
			if (Pos2(p2_).is_minus()) return *this;
			return this->draw(PosA4F(float((int32_t(p_.x) + p2_.x) % p2_.x) + p_.x - floor(p_.x), float((int32_t(p_.y) + p2_.y) % p2_.y) + p_.y - floor(p_.y), p_.w, p_.h), t_);
		}
		//プレイヤーの位置、マップサイズ、画像
		AsMapView& draw(const PosA4F& p_, const Pos2& p2_, AsTexture& a_,const size_t id_=0,const size_t type_= aslib_mob_walk_type_small)
		{
			if (Pos2(p2_).is_minus()) return *this;
			const PosA4F p_2 = (type_ == aslib_mob_walk_type_big) ? PosA4F(p_.x + 0.5f, p_.y + 0.3f, p_.w, p_.h) : p_;
			return this->draw(PosA4F(float((int32_t(p_2.x) + p2.x) % p2.x) + p_2.x - floor(p_2.x), float((int32_t(p_2.y) + p2.y) % p2.y) + p_2.y - floor(p_2.y), p_2.w, p_2.h), a_, id_);
		}
		//色の全体描画
		AsMapView& draw(Color* const col_) { return this->drawMap(p2, MAP_VIEW_DRAW_COLOR, col_, nullptr); }
		//画像の全体描画
		AsMapView& draw(AsTextureMapArray* const t_) { return this->drawMap(p2, MAP_VIEW_DRAW_ANIME, nullptr, t_); }

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

	//mobに歩行アニメーションをさせる
	const bool mobMoveSet(size_t& move_id_, size_t& count, const size_t move_max = 6)
	{
		switch (move_id_)
		{
		case MOB_STOP:
			++move_id_;
			return true;
		case MOB_MOVE1:
		case MOB_MOVE2:
		case MOB_MOVE3:
			++count;
			if (count >= move_max) {
				count = 0;
				++move_id_;
			}
			return true;
		case MOB_MOVE4:
			++count;
			if (count >= move_max) {
				count = 0;
				move_id_ = MOB_MOVE1;
			}
			return true;
		}
		return false;
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
			if(d_) p_.y+= s_;
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

	inline const bool moveMobCross(const float s_, PosA4F& p_) {
		return (moveMobCross(asKey(aslib_key_DownArrow), asKey(aslib_key_UpArrow), asKey(aslib_key_LeftArrow), asKey(aslib_key_RightArrow), s_, p_) == MOB_CENTER) ? false : true;
	}

	const size_t movingMobCross(const float s_, PosA4F& p_,size_t& is_move_) {

		const Pos2F p2f(p_.x, p_.y);
		switch (is_move_)
		{
		case MOB_DOWN:
			p_.y += s_;
			if (floor(p2f.y) != floor(p_.y)) {
				is_move_ = MOB_CENTER;
				p_.y = floor(p_.y);
			}
			break;
		case MOB_UP:
			p_.y -= s_;
			if (floor(p2f.y) != floor(p_.y)) {
				is_move_ = MOB_CENTER;
				p_.y = floor(p_.y) + 1.0f;
			}
			break;
		case MOB_LEFT:
			p_.x -= s_;
			if (floor(p2f.x) != floor(p_.x)) {
				is_move_ = MOB_CENTER;
				p_.x = floor(p_.x) + 1.0f;
			}
			break;
		case MOB_RIGHT:
			p_.x += s_;
			if (floor(p2f.x) != floor(p_.x)) {
				is_move_ = MOB_CENTER;
				p_.x = floor(p_.x);
			}
			break;
		}

		if (is_move_ == MOB_CENTER) {
			is_move_ = moveMobCross(asKey(aslib_key_DownArrow), asKey(aslib_key_UpArrow), asKey(aslib_key_LeftArrow), asKey(aslib_key_RightArrow), s_, p_);
		}

		return is_move_;
	}

	inline const bool moveMob(const float s_, PosA4F& p_) {
		return moveMob(asKey(aslib_key_DownArrow), asKey(aslib_key_UpArrow), asKey(aslib_key_LeftArrow), asKey(aslib_key_RightArrow), s_, p_);
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
		return directionMobCross(asKey(aslib_key_DownArrow), asKey(aslib_key_UpArrow), asKey(aslib_key_LeftArrow), asKey(aslib_key_RightArrow), dir_);
	}
	//if (asKeyUp()) dir_id = MOB_UP;
	//else if (asKeyDown()) dir_id = MOB_DOWN;
	//else if (asKeyLeft()) dir_id = MOB_LEFT;
	//else if (asKeyRight()) dir_id = MOB_RIGHT;


	//class MoveMobControl
	//{
	//private:
	//	PosA4F pos;
	//	float walk_time;
	//	float time_count = 0.0f;

	//public:
	//	MoveMobControl() = default;
	//	constexpr MoveMobControl(const PosA4F& p_, const float t_ = 1000.0f) :pos(p_), walk_time(t_) {};
	//	MoveMobControl& update() {
	//		if()
	//		time_count += (walk_time / (60.0f*1000.0f));
	//		
	//	}

	//	MoveMobControl& setPos(const PosA4F& p_) { this->pos = p_; return *this; }
	//	PosA4F Pos() const { return pos; }
	//	

	//};



	enum :size_t
	{
		//絶対に通れない場所 or 絶対に通れる者
		MAP_MOVE_ID_100_0,
		//ほとんど通れない場所 or ほとんど通れる者
		MAP_MOVE_ID_95_0,
		//誰でも通れる場所 or どこも通れない者
		MAP_MOVE_ID_0_0,
	};
	//4方向()
	const bool movePassD4(const size_t mob_id, const size_t around_id)
	{
		switch (mob_id)
		{

		case MAP_MOVE_ID_100_0:
			//全て通れる
			return true;

		case MAP_MOVE_ID_95_0:
			switch (around_id)
			{
			case MAP_MOVE_ID_100_0:
				//絶対に通れない場所だけ通れない
				return false;
			}
			return true;

		case MAP_MOVE_ID_0_0:
			return false;
		}
		return false;
	}

	const bool movePass(const size_t mob_id, const size_t* const around_id)
	{

		return false;
	}






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

		const worldMap& drawView(AsMapView& m_) const {
			int32_t a;
			for (size_t j = 0; j < size_t(this->s.y); ++j) {
				for (size_t i = 0; i < size_t(this->s.x); ++i) {
					a = map_id[a2(this->s.x, i, j)];
					m_.draw(PosA4F(PosL4F(float(i), float(j), 1.0f, 1.0f)), Color(uint8_t(a), uint8_t(a), uint8_t(a), uint8_t(255)));

				}
			}
			return *this;
		}

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