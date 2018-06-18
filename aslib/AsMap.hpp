//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asライブラリ
//
//                    制作者: がっちょ (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{

	//配列サイズ
	struct Size2
	{
		size_t x = 0;
		size_t y = 0;
		Size2() = default;
		constexpr Size2(const size_t x_, const size_t y_) :x(x_), y(y_) {}
	};
	inline const size_t a2(const size_t& s_, const size_t& i_, const size_t& j_) { return (s_ * j_ + i_); }


	//マップの見える範囲
	struct MapView
	{
	private:
		//マップの中心位置と幅
		PosA4R p;

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

		//マップ内に収める
		MapView& setMob(PosA4R& p_, const Pos2& p2_) {
			if (Pos2(p2_).is_minus()) return *this;
			if (p_.x < 0.0f) p_.x += float(p2_.x);
			if (p_.y < 0.0f) p_.y += float(p2_.y);
			p_.x += float(int32_t(p_.x) % p2_.x) - floor(p_.x);
			p_.y += float(int32_t(p_.y) % p2_.y) - floor(p_.y);
			p.x = p_.x;
			p.y = p_.y;
			return *this;
		}
		MapView& setMob(const PosA4R& p_) { p.x = p_.x; p.y = p_.y; return *this;}
		MapView& setMap(const PosA4R& p_) { p = p_; return *this;}
		MapView& setMapX(const PosA4R& p_) { p = p_; p.h = p.w*(float(asWindowSize().y) / float(asWindowSize().x)); return *this;}

		MapView& colorMob(const PosA4R& p_, const Pos2& p2_, const ColorRGBA& c_)
		{
			if (Pos2(p2_).is_minus()) return *this;
			return this->colorMob(PosA4R(float((int32_t(p_.x) + p2_.x) % p2_.x) + p_.x - floor(p_.x), float((int32_t(p_.y) + p2_.y) % p2_.y) + p_.y - floor(p_.y), p_.w, p_.h), c_);
		}
		MapView& colorMob(const Pos4R& p_, const ColorRGBA& c_)
		{
			//範囲外は描画無し
			const Pos4R Dp = Pos4R(this->p);
			if (p_.x2 < Dp.x1 || p_.y2 < Dp.y1 || p_.x1 > Dp.x2 || p_.y1 > Dp.y2) return *this;

			const PosL4R Lp = PosL4R(this->p);
			const Pos2 w_ = asWindowSize();
			asRect(Pos4(int32_t((p_.x1 - Lp.x) / Lp.w*w_.x), int32_t((p_.y1 - Lp.y) / Lp.h*w_.y), int32_t((p_.x2 - Lp.x) / Lp.w*w_.x), int32_t((p_.y2 - Lp.y) / Lp.h*w_.y)), c_);
			return *this;
		}
		MapView& colorMob(ColorRGBA* const col_, const Pos2& p_)
		{
			if (Pos2(p_).is_minus()) return *this;

			//1マスの描画幅o
			const Pos2R m(asWindowSizeF().x / this->p.w, asWindowSizeF().y / this->p.h);
			//描画ピクセル数o
			const PosA4R in_mapA(this->p.x, this->p.y, m.x*(floor(this->p.w) + 2.0f), m.y*(floor(this->p.h) + 2.0f));
			//描画マス数
			const Pos4 in_map(PosA4(int32_t(p.x), int32_t(p.y), int32_t(this->p.w) + 2, int32_t(this->p.h) + 2));

			//todo
			const Pos2R in_draw((asWindowSizeF().x- in_mapA.w)/2 - m.x*(this->p.x - floor(this->p.x)), (asWindowSizeF().y - in_mapA.h) / 2 - m.y*(this->p.y - floor(this->p.y)));

			Pos2 select_map(0);
			Pos2R draw_map(in_draw);

			for (int32_t i = in_map.y1; i <= in_map.y2; ++i) {
				draw_map.x = in_draw.x;
				draw_map.y += m.y;

				select_map.y = i;
				while (1) { if (select_map.y >= 0) break; else select_map.y += p_.y; }
				select_map.y = select_map.y % p_.y;

				for (int32_t j = in_map.x1; j <= in_map.x2; ++j) {
					draw_map.x += m.x;

					select_map.x = j;
					while (1) { if (select_map.x >= 0) break; else select_map.x += p_.x; }
					select_map.x = select_map.x % p_.x;
					//描画
					asRect(PosL4(int32_t(draw_map.x), int32_t(draw_map.y), int32_t(m.x), int32_t(m.y)), col_[select_map.y*p_.x + select_map.x]);
				}
			}

			DxLib::clsDx();
			DxLib::printfDx("in_map:%d,%d,%d,%d\n", in_map.x1, in_map.y1, in_map.x2, in_map.y2);
			DxLib::printfDx("in_map:%f,%f,%f,%f\n", in_mapA.x, in_mapA.y, in_mapA.w, in_mapA.h);
			DxLib::printfDx("select_map:%d,%d\n", select_map.x, select_map.y);
			DxLib::printfDx("draw_map:%f,%f\n", draw_map.x, draw_map.y);
			DxLib::printfDx("m:%f,%f\n", m.x, m.y);

			return *this;
		}


	};


	







	struct worldMap
	{
		Size2 s;
		size_t total_size;
		std::unique_ptr<int32_t[]> map_id;
		std::unique_ptr<ColorRGBA[]> col;

		worldMap(const Size2& xy_) :s({ xy_.x, xy_.y }), total_size(xy_.x*xy_.y), map_id(new int32_t[xy_.x*xy_.y]), col(new ColorRGBA[xy_.x*xy_.y]) { clear(); }
		worldMap(const size_t x_, const size_t y_) : s({ x_, y_ }), total_size(x_*y_), map_id(new int32_t[x_*y_]), col(new ColorRGBA[x_*y_]) { clear(); }
		const worldMap& clear() const { for (size_t i = 0; i < total_size; ++i) map_id[i] = 0; return *this; }
		const worldMap& rand() const { asRand32(&map_id[0], total_size); return *this; }
		const worldMap& randC(const uint8_t m_) const { asRand(&col[0], total_size,m_); return *this; }

		const worldMap& drawView(MapView& m_) const {
			int32_t a;
			for (size_t j = 0; j < this->s.y; ++j) {
				for (size_t i = 0; i < this->s.x; ++i) {
					a = map_id[a2(this->s.x, i, j)];
					//asRect(PosL4(i*size_, j*size_, size_, size_), ColorRGBA(a, a, a, a));
					m_.colorMob(PosA4R(PosL4R(float(i), float(j), 1.0f, 1.0f)), ColorRGBA(a, a, a, 255));

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