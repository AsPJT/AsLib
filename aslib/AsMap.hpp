//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - As���C�u����
//
//                    �����: �������� (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{

	//�z��T�C�Y
	struct Size2
	{
		size_t x = 0;
		size_t y = 0;
		Size2() = default;
		constexpr Size2(const size_t x_, const size_t y_) :x(x_), y(y_) {}
	};
	inline const size_t a2(const size_t& s_, const size_t& i_, const size_t& j_) { return (s_ * j_ + i_); }


	//�}�b�v�̌�����͈�
	struct MapView
	{
	private:
		//�}�b�v�̒��S�ʒu�ƕ�
		PosA4R p;

	public:
		MapView() = default;
		constexpr MapView(const PosA4R& p_) : p(p_) {}
		MapView(const PosA4R& p_,const char c_) : p(p_) {
			switch (c_)
			{
				//�����`
			case 'x': p.h = p.w*(float(asWindowSize().y) / float(asWindowSize().x)); break;
			case 'y': p.w = p.h*(float(asWindowSize().x) / float(asWindowSize().y)); break;
				//��ʃT�C�Y�Ɠ��䗦
			case 'X': p.h = p.w; break;
			case 'Y': p.w = p.h; break;
			}
		}

		//���S�ʒu���w��--------------------------------------------------------------

		//�}�b�v���Ɏ��߂�
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
			//�͈͊O�͕`�斳��
			const Pos4R Dp = Pos4R(this->p);
			if (p_.x2 < Dp.x1 || p_.y2 < Dp.y1 || p_.x1 > Dp.x2 || p_.y1 > Dp.y2) return *this;

			const PosL4R Lp = PosL4R(this->p);
			const Pos2 w_ = asWindowSize();
			asRect(Pos4(int32_t((p_.x1 - Lp.x) / Lp.w*w_.x), int32_t((p_.y1 - Lp.y) / Lp.h*w_.y), int32_t((p_.x2 - Lp.x) / Lp.w*w_.x), int32_t((p_.y2 - Lp.y) / Lp.h*w_.y)), c_);
			return *this;
		}
		MapView& colorMob(ColorRGBA* col_)
		{

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