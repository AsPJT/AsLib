//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asライブラリ
//
//                    制作者: がっちょ (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
	enum :size_t {
		MAP_VIEW_DRAW_COLOR,
		MAP_VIEW_DRAW_TEXTURE,
		MAP_VIEW_DRAW_ANIME,
	};

	//マップの見える範囲
	struct MapView
	{
	private:
		//マップの中心位置と幅
		PosA4R p;

		//全体の描画
		MapView& drawMob(const Pos2& p_, const size_t num_, ColorRGBA* const col_ = nullptr, TextureMainData* const t_ = nullptr, AnimeMainData* const a_ = nullptr, const size_t id_ = 0)
		{

			if (p_.is_minus()) return *this;

			//1マスの描画幅
			const Pos2R m(asWindowSizeF().x / this->p.w, asWindowSizeF().y / this->p.h);
			//描画ピクセル数
			const PosA4R in_mapA(this->p.x, this->p.y, m.x*(floor(this->p.w) + 2.0f), m.y*(floor(this->p.h) + 2.0f));
			//描画マス数
			const Pos4 in_map(PosA4(int32_t(p.x), int32_t(p.y), int32_t(this->p.w) + 2, int32_t(this->p.h) + 2));

			//描画初期位置
			const Pos2R in_draw((asWindowSizeF().x - in_mapA.w) / 2.0f - m.x*(this->p.x - floor(this->p.x)), (asWindowSizeF().y - in_mapA.h) / 2.0f - m.y*(this->p.y - floor(this->p.y)));

			Pos2 select_map(0);
			Pos2R draw_map(in_draw);

			for (int32_t i = in_map.y1; i <= in_map.y2; ++i) {
				draw_map.x = in_draw.x;
				draw_map.y += m.y;
				select_map.y = i;
				while (select_map.y < 0) { select_map.y += p_.y; }
				select_map.y = select_map.y % p_.y;

				for (int32_t j = in_map.x1; j <= in_map.x2; ++j) {
					draw_map.x += m.x;
					select_map.x = j;
					while (select_map.x < 0) { select_map.x += p_.x; }
					select_map.x = select_map.x % p_.x;

					switch (num_)
					{
					case MAP_VIEW_DRAW_COLOR:
						asRect(Pos4(int32_t(draw_map.x), int32_t(draw_map.y), int32_t(draw_map.x + m.x), int32_t(draw_map.y + m.y)), col_[select_map.y*p_.x + select_map.x]);
						break;
					case MAP_VIEW_DRAW_TEXTURE:
						t_->draw(Pos4(int32_t(draw_map.x), int32_t(draw_map.y), int32_t(draw_map.x + m.x), int32_t(draw_map.y + m.y)));
						break;
					case MAP_VIEW_DRAW_ANIME:
						a_->draw(id_, Pos4(int32_t(draw_map.x), int32_t(draw_map.y), int32_t(draw_map.x + m.x), int32_t(draw_map.y + m.y)));
						break;
					}
				}
			}
			return *this;
		}

	public:
		MapView() = default;
		constexpr MapView(const PosA4R& p_) : p(p_) {}
		MapView(const PosA4R& p_,const char c_) : p(p_) {
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

		//視点変更
		MapView& setMob(PosA4R& p_, const Pos2& p2_) {
			if (p2_.is_minus()) return *this;
			while (p_.x < 0.0f) { p_.x += float(p2_.x); }
			while (p_.y < 0.0f) { p_.y += float(p2_.y); }
			p.x = p_.x += float(int32_t(p_.x) % p2_.x) - floor(p_.x);
			p.y = p_.y += float(int32_t(p_.y) % p2_.y) - floor(p_.y);
			return *this;
		}
		MapView& setMob(const PosA4R& p_) { p.x = p_.x; p.y = p_.y; return *this;}
		MapView& setMap(const PosA4R& p_) { p = p_; return *this;}
		MapView& setMapX(const PosA4R& p_) { p = p_; p.h = p.w*(float(asWindowSize().y) / float(asWindowSize().x)); return *this;}

		//描画する物のサイズ
		MapView& drawMob(const Pos4R& p_, const size_t num_, const ColorRGBA* c_ = nullptr, TextureMainData* t_ = nullptr, AnimeMainData* a_ = nullptr,const size_t id_=0)
		{
			//範囲外は描画無し
			const Pos4R Dp = Pos4R(this->p);
			if (p_.x2 < Dp.x1 || p_.y2 < Dp.y1 || p_.x1 > Dp.x2 || p_.y1 > Dp.y2) return *this;

			const PosL4R Lp = PosL4R(this->p);
			const Pos2 w_ = asWindowSize();
			switch (num_)
			{
			case MAP_VIEW_DRAW_COLOR:
				asRect(Pos4(int32_t((p_.x1 - Lp.x) / Lp.w*w_.x), int32_t((p_.y1 - Lp.y) / Lp.h*w_.y), int32_t((p_.x2 - Lp.x) / Lp.w*w_.x), int32_t((p_.y2 - Lp.y) / Lp.h*w_.y)), *c_);
				break;
			case MAP_VIEW_DRAW_TEXTURE:
				t_->draw(Pos4(int32_t((p_.x1 - Lp.x) / Lp.w*w_.x), int32_t((p_.y1 - Lp.y) / Lp.h*w_.y), int32_t((p_.x2 - Lp.x) / Lp.w*w_.x), int32_t((p_.y2 - Lp.y) / Lp.h*w_.y)));
				break;
			case MAP_VIEW_DRAW_ANIME:
				a_->draw(id_,Pos4(int32_t((p_.x1 - Lp.x) / Lp.w*w_.x), int32_t((p_.y1 - Lp.y) / Lp.h*w_.y), int32_t((p_.x2 - Lp.x) / Lp.w*w_.x), int32_t((p_.y2 - Lp.y) / Lp.h*w_.y)));
				break;
			}
			return *this;
		}

		//プレイヤーの位置、マップサイズ、カラー
		MapView& draw(const PosA4R& p_, const Pos2& p2_, const ColorRGBA& c_)
		{
			if (Pos2(p2_).is_minus()) return *this;
			return this->draw(PosA4R(float((int32_t(p_.x) + p2_.x) % p2_.x) + p_.x - floor(p_.x), float((int32_t(p_.y) + p2_.y) % p2_.y) + p_.y - floor(p_.y), p_.w, p_.h), c_);
		}
		//描画する物のサイズ、画像
		MapView& draw(const Pos4R& p_, const ColorRGBA& c_) { return this->drawMob(p_, MAP_VIEW_DRAW_COLOR, &c_, nullptr, nullptr); }

		//プレイヤーの位置、マップサイズ、画像
		MapView& draw(const PosA4R& p_, const Pos2& p2_, TextureMainData& t_)
		{
			if (Pos2(p2_).is_minus()) return *this;
			return this->draw(PosA4R(float((int32_t(p_.x) + p2_.x) % p2_.x) + p_.x - floor(p_.x), float((int32_t(p_.y) + p2_.y) % p2_.y) + p_.y - floor(p_.y), p_.w, p_.h), t_);
		}
		//描画する物のサイズ、カラー
		MapView& draw(const Pos4R& p_, TextureMainData& t_) { return this->drawMob(p_, MAP_VIEW_DRAW_TEXTURE, nullptr, &t_, nullptr); }
		//プレイヤーの位置、マップサイズ、画像
		MapView& draw(const PosA4R& p_, const Pos2& p2_, AnimeMainData& a_,const size_t id_=0)
		{
			if (Pos2(p2_).is_minus()) return *this;
			return this->draw(PosA4R(float((int32_t(p_.x) + p2_.x) % p2_.x) + p_.x - floor(p_.x), float((int32_t(p_.y) + p2_.y) % p2_.y) + p_.y - floor(p_.y), p_.w, p_.h), a_, id_);
		}
		//描画する物のサイズ、カラー
		MapView& draw(const Pos4R& p_, AnimeMainData& a_, const size_t id_) { return this->drawMob(p_, MAP_VIEW_DRAW_ANIME, nullptr, nullptr, &a_, id_); }

		//色の全体描画
		MapView& draw(ColorRGBA* const col_, const Pos2& p_) { return this->drawMob(p_, MAP_VIEW_DRAW_COLOR, col_, nullptr, nullptr); }
		//画像の全体描画
		MapView& draw(TextureMainData* t_, const Pos2& p_) { return this->drawMob(p_, MAP_VIEW_DRAW_TEXTURE, nullptr, t_, nullptr); }
		//画像の全体描画
		MapView& draw(AnimeMainData* a_, const Pos2& p_, const size_t id_) { return this->drawMob(p_, MAP_VIEW_DRAW_ANIME, nullptr, nullptr, a_, id_); }


	};

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
		const int32_t b_max = b_.x*b_.y;
		const int32_t a_max = a_.x*a_.y;
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
	const bool moveMob(const bool d_, const bool u_, const bool l_, const bool r_, const float s_, PosA4R& p_)
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
	const bool moveMobCross(const bool d_, const bool u_, const bool l_, const bool r_, const float s_, PosA4R& p_)
	{
		if (d_) {
			p_.y += s_; return true;
		}
		else if (u_) {
			p_.y -= s_; return true;
		}
		else if (l_) {
			p_.x -= s_; return true;
		}
		else if (r_) {
			p_.x += s_; return true;
		}
		return false;
	}

	inline const bool moveMobCross(const float s_, PosA4R& p_)
	{
		return moveMobCross(asKey(Keyboard_DownArrow), asKey(Keyboard_UpArrow), asKey(Keyboard_LeftArrow), asKey(Keyboard_RightArrow), s_, p_);
	}

	inline const bool moveMob(const float s_, PosA4R& p_)
	{
		return moveMob(asKey(Keyboard_DownArrow), asKey(Keyboard_UpArrow), asKey(Keyboard_LeftArrow), asKey(Keyboard_RightArrow), s_, p_);
	}


	//class MoveMobControl
	//{
	//private:
	//	PosA4R pos;
	//	float walk_time;
	//	float time_count = 0.0f;

	//public:
	//	MoveMobControl() = default;
	//	constexpr MoveMobControl(const PosA4R& p_, const float t_ = 1000.0f) :pos(p_), walk_time(t_) {};
	//	MoveMobControl& update() {
	//		if()
	//		time_count += (walk_time / (60.0f*1000.0f));
	//		
	//	}

	//	MoveMobControl& setPos(const PosA4R& p_) { this->pos = p_; return *this; }
	//	PosA4R Pos() const { return pos; }
	//	

	//};

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



	//----------------------------------------------------------------------------------------------------------------------------
	//ここから下は仮テスト機能
	
	inline static const size_t a2(const size_t& s_, const size_t& i_, const size_t& j_) { return (s_ * j_ + i_); }
	struct worldMap
	{
		Pos2 s;
		size_t total_size;
		std::unique_ptr<int32_t[]> map_id;
		std::unique_ptr<ColorRGBA[]> col;

		worldMap(const Pos2& xy_) :s({ xy_.x, xy_.y }), total_size(xy_.x*xy_.y), map_id(new int32_t[xy_.x*xy_.y]), col(new ColorRGBA[xy_.x*xy_.y]) { clear(); }
		worldMap(const int32_t x_, const int32_t y_) : s({ x_, y_ }), total_size(x_*y_), map_id(new int32_t[x_*y_]), col(new ColorRGBA[x_*y_]) { clear(); }
		const worldMap& clear() const { for (size_t i = 0; i < total_size; ++i) map_id[i] = 0; return *this; }
		const worldMap& rand() const { asRand32(&map_id[0], total_size); return *this; }
		const worldMap& randC(const uint8_t m_) const { asRand(&col[0], total_size,m_); return *this; }

		const worldMap& drawView(MapView& m_) const {
			int32_t a;
			for (size_t j = 0; j < this->s.y; ++j) {
				for (size_t i = 0; i < this->s.x; ++i) {
					a = map_id[a2(this->s.x, i, j)];
					m_.draw(PosA4R(PosL4R(float(i), float(j), 1.0f, 1.0f)), ColorRGBA(a, a, a, 255));

				}
			}
			return *this;
		}

		const worldMap& draw(const size_t size_) const {
			int32_t a;
			for (size_t j = 0; j < this->s.y; ++j) {
				for (size_t i = 0; i < this->s.x; ++i) {
					a = map_id[a2(this->s.x, i, j)];
					asRect(PosL4(int32_t(i*size_), int32_t(j*size_), int32_t(size_), int32_t(size_)), ColorRGBA(a, a, a, a));
				}
			}
			return *this;
		}

		const worldMap& drawP(const size_t size_, const Pos2& p_) const {
			const int32_t a = map_id[a2(this->s.x, p_.y, p_.x)];
			asRect(PosL4(int32_t(p_.x*size_), int32_t(p_.y*size_), int32_t(size_), int32_t(size_)), ColorRGBA(a, a, a, a));
			return *this;
		}

		//const ColorRGBA drawP_c(const Pos2& p_) const {
		//	const int32_t a = map_id[a2(this->s.x, p_.y, p_.x)];
		//	return ColorRGBA(a, a, a, a);
		//}
	};

}