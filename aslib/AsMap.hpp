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
		const MapView(const PosA4R& p_,const char c_) : p(p_) {
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

		//中心位置を指定
		void setMob(const PosA4R& p_) { p.x = p_.x; p.y = p_.y; }
		void setMap(const PosA4R& p_) { p = p_; }
		void setMapX(const PosA4R& p_) { p = p_; p.h = p.w*(float(asWindowSize().y) / float(asWindowSize().x)); }

		void colorMob(const Pos4R& p_, const ColorRGBA& c_)
		{
			//範囲外は描画無し
			const Pos4R Dp = Pos4R(this->p);
			if (p_.x2 < Dp.x1 || p_.y2 < Dp.y1 || p_.x1 > Dp.x2 || p_.y1 > Dp.y2) return;

			const PosL4R Lp = PosL4R(this->p);
			const Pos2 w_ = asWindowSize();
			asRect(Pos4(int32_t((p_.x1 - Lp.x) / Lp.w*w_.x), int32_t((p_.y1 - Lp.y) / Lp.h*w_.y), int32_t((p_.x2 - Lp.x) / Lp.w*w_.x), int32_t((p_.y2 - Lp.y) / Lp.h*w_.y)), c_);
		}


	};










	struct worldMap
	{
		Size2 s;
		size_t total_size;
		std::unique_ptr<int32_t[]> map_id;

		const worldMap(const Size2& xy_) :s({ xy_.x, xy_.y }), total_size(xy_.x*xy_.y), map_id(new int32_t[xy_.x*xy_.y]) { clear(); }
		const worldMap(const size_t x_, const size_t y_) : s({ x_, y_ }), total_size(x_*y_), map_id(new int32_t[x_*y_]) { clear(); }
		const worldMap& clear() const { for (size_t i = 0; i < total_size; ++i) map_id[i] = 0; return *this; }
		const worldMap& rand() const { for (size_t i = 0; i < total_size; ++i) map_id[i] = asRand32(); return *this; }

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
					asRect(PosL4(i*size_, j*size_, int32_t(size_), int32_t(size_)), ColorRGBA(a, a, a, a));
				}
			}
			return *this;
		}

		const worldMap& drawP(const size_t size_, const Pos2& p_) const {
			const int32_t a = map_id[a2(this->s.x, p_.y, p_.x)];
			asRect(PosL4(p_.x*size_, p_.y*size_, size_, size_), ColorRGBA(a, a, a, a));
			return *this;
		}

		//const ColorRGBA drawP_c(const Pos2& p_) const {
		//	const int32_t a = map_id[a2(this->s.x, p_.y, p_.x)];
		//	return ColorRGBA(a, a, a, a);
		//}
	};

}