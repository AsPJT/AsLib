//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asライブラリ
//
//                    制作者: がっちょ (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------

namespace AsLib
{

	//2点位置
	struct Pos2;
	struct Pos2R;

	//4点位置
	struct Pos4;
	struct Pos4R;
	struct PosA4;
	struct PosL4;

	//8点位置
	struct Pos8;
	struct Pos8R;

	//大きさ(2D)
	struct Pos2
	{
		const Pos2& operator=(const Pos4& add_pos);
		const Pos2& operator=(const PosL4& add_pos);
		const Pos2& operator=(const PosA4& add_pos);
		const Pos2& operator=(const Pos8& add_pos);
		const Pos2& operator()(const Pos4& add_pos);
		const Pos2& operator()(const PosL4& add_pos);
		const Pos2& operator()(const PosA4& add_pos);
		const Pos2& operator()(const Pos8& add_pos);
		const Pos2& operator()() { *this = Pos2(0); return *this; }
		const Pos2& operator()(const int32_t pos_size) { *this = Pos2(pos_size); return *this; }
		const Pos2& operator()(const int32_t pos_x, const int32_t pos_y) { *this = Pos2(pos_x, pos_y); return *this; }
		const Pos2& operator()(const double pos_) { this->x = int32_t(this->x*pos_); this->y = int32_t(this->y*pos_); return *this; }
		const Pos2& operator()(const double pos_x, const double pos_y) { this->x = int32_t(this->x*pos_x); this->y = int32_t(this->y*pos_y); return *this; }
		operator Pos4();
		operator PosL4();
		operator PosA4();
		operator Pos8();
		const Pos2& rand(const Pos2&);
		const Pos2& randPlus(const uint32_t);

		int32_t x = 0;
		int32_t y = 0;

		//コンストラクタ
		Pos2() = default;
		constexpr Pos2(const int32_t xy_) :x(xy_), y(xy_) {};
		constexpr Pos2(const int32_t x_, const int32_t y_) :x(x_), y(y_) {};
		constexpr Pos2(const Pos2&);
		constexpr Pos2(const Pos4&);
		constexpr Pos2(const PosL4&);
		constexpr Pos2(const PosA4&);
		constexpr Pos2(const Pos8&);
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		operator s3d::Point()
		{
			s3d::Point p_;
			p_.x = this->x;
			p_.x = this->y;
			return p_;
		}
		Pos2 operator=(const s3d::Point& add_pos) { return Pos2(int32_t(add_pos.x), int32_t(add_pos.y)); }
		operator s3d::Rect()
		{
			const s3d::Rect rect(this->x, this->y);
			return rect;
		}
#endif
	};

	inline const Pos2 & Pos2::rand(const Pos2& add_pos)
	{
		this->x = asRand32(add_pos.x);
		this->y = asRand32(add_pos.y);
		return *this;
	}

	inline const Pos2 & Pos2::randPlus(const uint32_t add_pos)
	{
		this->x += (asRand32(add_pos) - (add_pos >> 1));
		this->y += (asRand32(add_pos) - (add_pos >> 1));
		return *this;
	}

	//長方形の大きさ(左上と右下の位置)
	struct Pos4
	{
		const Pos4& operator=(const Pos2&);
		const Pos4& operator=(const Pos8&);
		const Pos4& operator=(const PosA4&);
		const Pos4& operator=(const PosL4&);
		const Pos4& operator()(const Pos2&);
		const Pos4& operator()(const Pos8&);
		const Pos4& operator()(const PosA4&);
		const Pos4& operator()(const PosL4&);
		operator Pos2();
		operator Pos8();
		operator PosA4();
		operator PosL4();
		int32_t x1;
		int32_t y1;
		int32_t x2;
		int32_t y2;
		const Pos4& rand(const Pos2&);
		const Pos4& operator() (const Pos4R&, const Pos2&);

		//コンストラクタ
		Pos4() = default;
		constexpr Pos4(const int32_t xy_) :x1(0), y1(0), x2(xy_), y2(xy_) {};
		constexpr Pos4(const int32_t x_, const int32_t y_) :x1(0), y1(0), x2(x_), y2(y_) {};
		constexpr Pos4(const int32_t x_, const int32_t y_,const int32_t l_) :x1(x_), y1(y_), x2(x_+l_), y2(y_+l_) {};
		constexpr Pos4(const int32_t x1_, const int32_t y1_, const int32_t x2_, const int32_t y2_) :x1(x1_), y1(y1_), x2(x2_), y2(y2_) {};
		constexpr Pos4(const Pos2&);
		constexpr Pos4(const Pos4&);
		constexpr Pos4(const PosL4&);
		constexpr Pos4(const PosA4&);
		constexpr Pos4(const Pos8&);

		//比率
		constexpr Pos4(const Pos4R&, const Pos2&);
	};

	inline const Pos4 & Pos4::rand(const Pos2& add_pos)
	{
		this->x2 = this->x1 + asRand32(add_pos.x);
		this->y2 = this->y1 + asRand32(add_pos.y);
		return *this;
	}

	//長方形の大きさ(位置と長さ)
	struct PosL4
	{
		const PosL4& operator=(const Pos2& add_pos);
		const PosL4& operator=(const Pos4& add_pos);
		const PosL4& operator=(const PosA4& add_pos);
		const PosL4& operator=(const Pos8& add_pos);
		const PosL4& operator()(const Pos2& add_pos);
		const PosL4& operator()(const Pos4& add_pos);
		const PosL4& operator()(const PosA4& add_pos);
		const PosL4& operator()(const Pos8& add_pos);
		operator Pos2();
		operator Pos4();
		operator PosA4();
		operator Pos8();
		int32_t x = 0;
		int32_t y = 0;
		int32_t w = 0;
		int32_t h = 0;

		//コンストラクタ
		PosL4() = default;
		constexpr PosL4(const int32_t xy_) :x(0), y(0), w(xy_), h(xy_) {};
		constexpr PosL4(const int32_t x_, const int32_t y_) :x(0), y(0), w(x_), h(y_) {};
		constexpr PosL4(const int32_t x_, const int32_t y_, const int32_t l_) :x(x_), y(y_), w(l_), h(l_) {};
		constexpr PosL4(const int32_t x_, const int32_t y_, const int32_t w_, const int32_t h_) :x(x_), y(y_), w(w_), h(h_) {};
		constexpr PosL4(const Pos2&);
		constexpr PosL4(const Pos4&);
		constexpr PosL4(const PosL4&);
		constexpr PosL4(const PosA4&);
		constexpr PosL4(const Pos8&);
	};

	//中心位置と大きさを併せ持つ
	struct PosA4
	{
		const PosA4& operator=(const Pos2& add_pos);
		const PosA4& operator=(const Pos4& add_pos);
		const PosA4& operator=(const PosL4& add_pos);
		const PosA4& operator=(const Pos8& add_pos);
		const PosA4& operator()(const Pos2& add_pos);
		const PosA4& operator()(const Pos4& add_pos);
		const PosA4& operator()(const PosL4& add_pos);
		const PosA4& operator()(const Pos8& add_pos);
		const Pos2& operator()(const double pos_) { this->w = int32_t(this->w*pos_); this->h = int32_t(this->h*pos_); return *this; }
		const Pos2& operator()(const double pos_x, const double pos_y) { this->w = int32_t(this->w*pos_x); this->h = int32_t(this->h*pos_y); return *this; }
		operator Pos2();
		operator Pos4();
		operator PosL4();
		operator Pos8();
		const PosA4& rand(const Pos2&);
		const PosA4& randPlus(const uint32_t);
		int32_t x = 0;
		int32_t y = 0;
		int32_t w = 0;
		int32_t h = 0;

		//コンストラクタ
		PosA4() = default;
		constexpr PosA4(const int32_t xy_) :x(xy_), y(xy_), w(0), h(0) {};
		constexpr PosA4(const int32_t x_, const int32_t y_) :x(x_), y(y_), w(0), h(0) {};
		constexpr PosA4(const int32_t x_, const int32_t y_, const int32_t l_) :x(x_), y(y_), w(l_), h(l_) {};
		constexpr PosA4(const int32_t x_, const int32_t y_, const int32_t w_, const int32_t h_) :x(x_), y(y_), w(w_), h(h_) {};
		constexpr PosA4(const Pos2&);
		constexpr PosA4(const Pos4&);
		constexpr PosA4(const PosL4&);
		constexpr PosA4(const PosA4&);
		constexpr PosA4(const Pos8&);
	};

	inline const PosA4 & PosA4::randPlus(const uint32_t add_pos)
	{
		this->x += (asRand32(add_pos) - (add_pos >> 1));
		this->y += (asRand32(add_pos) - (add_pos >> 1));
		return *this;
	}

	//四角形の大きさ
	struct Pos8
	{
		const Pos8& operator=(const Pos2& add_pos);
		const Pos8& operator=(const Pos4& add_pos);
		const Pos8& operator=(const PosL4& add_pos);
		const Pos8& operator=(const PosA4& add_pos);
		const Pos8& operator()(const Pos2& add_pos);
		const Pos8& operator()(const Pos4& add_pos);
		const Pos8& operator()(const PosL4& add_pos);
		const Pos8& operator()(const PosA4& add_pos);
		int32_t x1 = 0;
		int32_t y1 = 0;
		int32_t x2 = 0;
		int32_t y2 = 0;
		int32_t x3 = 0;
		int32_t y3 = 0;
		int32_t x4 = 0;
		int32_t y4 = 0;

		//コンストラクタ
		Pos8() = default;
		constexpr Pos8(const int32_t x1_, const int32_t y1_, const int32_t x2_, const int32_t y2_, const int32_t x3_, const int32_t y3_, const int32_t x4_, const int32_t y4_) : x1(x1_), y1(y1_), x2(x2_), y2(y2_), x3(x3_), y3(y3_), x4(x4_), y4(y4_) {}
		constexpr Pos8(const int32_t x1_, const int32_t y1_, const int32_t x2_, const int32_t y2_) : x1(x1_), y1(y1_), x2(x2_), y2(y1_), x3(x1_), y3(y2_), x4(x2_), y4(y2_) {}
		constexpr Pos8(const int32_t x_, const int32_t y_) : x1(0), y1(0), x2(x_), y2(0), x3(0), y3(y_), x4(x_), y4(y_) {}
		constexpr Pos8(const Pos2&);
		constexpr Pos8(const Pos4&);
		constexpr Pos8(const PosL4&);
		constexpr Pos8(const PosA4&);
		constexpr Pos8(const Pos8&);

		//回転
		const Pos8(const Pos4&, const double);
		const Pos8& operator()(const Pos4& p_, const double r_) { *this = Pos8(p_, r_); return *this; };

		//立体回転
		const Pos8 rotation3D(const Pos4&, const double);

	};

	//画面比での大きさ(2D)
	struct Pos2R
	{
		Pos2R& operator=(const Pos4R& add_pos);
		Pos2R& operator=(const Pos8R& add_pos);
		Pos2R& operator()(const float pos_size = 0.0f);
		Pos2R& operator()(const float pos_x, const float pos_y);
		float x = 1.0f;
		float y = 1.0f;
	};

	//画面比での長方形の大きさ
	struct Pos4R
	{
		Pos4R& operator=(const Pos2R& add_pos);
		Pos4R& operator=(const Pos8R& add_pos);
		float x1 = 0.0f;
		float y1 = 0.0f;
		float x2 = 1.0f;
		float y2 = 1.0f;
	};

	//画面比での四角形の大きさ
	struct Pos8R
	{
		Pos8R& operator=(const Pos2R& add_pos);
		Pos8R& operator=(const Pos4R& add_pos);
		float x1 = 0.0f;
		float y1 = 0.0f;
		float x2 = 1.0f;
		float y2 = 0.0f;
		float x3 = 0.0f;
		float y3 = 1.0f;
		float x4 = 1.0f;
		float y4 = 1.0f;
	};



	//--------------------------------------------------------
	//コンストラクタ
	//--------------------------------------------------------

	//Pos2
	inline constexpr Pos2::Pos2(const Pos2& pos_) :x(pos_.x), y(pos_.y) {}
	inline constexpr Pos2::Pos2(const Pos4& pos_) : x(pos_.x1), y(pos_.y1) {}
	inline constexpr Pos2::Pos2(const PosL4& pos_) : x(pos_.x), y(pos_.y) {}
	inline constexpr Pos2::Pos2(const PosA4& pos_) : x(pos_.x), y(pos_.y) {}
	inline constexpr Pos2::Pos2(const Pos8& pos_) : x(pos_.x1), y(pos_.y1) {}
	//Pos4
	inline constexpr Pos4::Pos4(const Pos2& pos_) : x1(0), y1(0), x2(pos_.x), y2(pos_.y) {}
	inline constexpr Pos4::Pos4(const Pos4& pos_) : x1(pos_.x1), y1(pos_.y1), x2(pos_.x2), y2(pos_.y2) {}
	inline constexpr Pos4::Pos4(const PosL4& pos_) : x1(pos_.x), y1(pos_.y), x2(pos_.x + pos_.w), y2(pos_.y + pos_.h) {}
	inline constexpr Pos4::Pos4(const PosA4& pos_) : x1(pos_.x - (pos_.w / 2)), y1(pos_.y - (pos_.h / 2)), x2(pos_.x + (pos_.w / 2)), y2(pos_.y + (pos_.h / 2)) {}
	inline constexpr Pos4::Pos4(const Pos8& pos_) : x1(pos_.x1), y1(pos_.y1), x2(pos_.x4), y2(pos_.y4) {}
	//PosL4
	inline constexpr PosL4::PosL4(const Pos2& pos_) : x(pos_.x), y(pos_.y), w(0), h(0) {}
	inline constexpr PosL4::PosL4(const Pos4& pos_) : x(pos_.x1), y(pos_.y1), w(pos_.x2 - pos_.x1), h(pos_.y2 - pos_.y1) {}
	inline constexpr PosL4::PosL4(const PosL4& pos_) : x(pos_.x), y(pos_.y), w(pos_.w), h(pos_.h) {}
	inline constexpr PosL4::PosL4(const PosA4& pos_) : x(pos_.x - (pos_.w / 2)), y(pos_.y - (pos_.h / 2)), w(pos_.w), h(pos_.h) {}
	inline constexpr PosL4::PosL4(const Pos8& pos_) : x(pos_.x1), y(pos_.y1), w(pos_.x4 - pos_.x1), h(pos_.y4 - pos_.y1) {}
	//PosA4
	inline constexpr PosA4::PosA4(const Pos2& pos_) : x(pos_.x), y(pos_.y), w(0), h(0) {}
	inline constexpr PosA4::PosA4(const Pos4& pos_) : x(pos_.x1 + ((pos_.x2 - pos_.x1) / 2)), y(pos_.y1 + ((pos_.y2 - pos_.y1) / 2)), w(pos_.x2 - pos_.x1), h(pos_.y2 - pos_.y1) {}
	inline constexpr PosA4::PosA4(const PosL4& pos_) : x(pos_.x + (pos_.w / 2)), y(pos_.y + (pos_.h / 2)), w(pos_.w), h(pos_.h) {}
	inline constexpr PosA4::PosA4(const PosA4& pos_) : x(pos_.x), y(pos_.y), w(pos_.w), h(pos_.h) {}
	inline constexpr PosA4::PosA4(const Pos8& pos_) : x(pos_.x1 + ((pos_.x4 - pos_.x1) / 2)), y(pos_.y1 + ((pos_.y4 - pos_.y1) / 2)), w(pos_.x4 - pos_.x1), h(pos_.y4 - pos_.y1) {}
	//Pos8
	inline constexpr Pos8::Pos8(const Pos2& pos_) : x1(0), y1(0), x4(pos_.x), y4(pos_.y), x2(pos_.x), y2(0), x3(0), y3(pos_.y) {}
	inline constexpr Pos8::Pos8(const Pos4& pos_) : x1(pos_.x1), y1(pos_.y1), x4(pos_.x2), y4(pos_.y2), x2(pos_.x2), y2(pos_.y1), x3(pos_.x1), y3(pos_.y2) {}
	inline constexpr Pos8::Pos8(const PosL4& pos_) : x1(pos_.x), y1(pos_.y), x4(pos_.x + pos_.w), y4(pos_.y + pos_.h), x2(pos_.x + pos_.w), y2(pos_.y), x3(pos_.x), y3(pos_.y + pos_.h) {}
	inline constexpr Pos8::Pos8(const PosA4& pos_) : x1(pos_.x - (pos_.w / 2)), y1(pos_.y - (pos_.h / 2)), x4(pos_.x + (pos_.w / 2)), y4(pos_.y + (pos_.h / 2)), x2(pos_.x + (pos_.w / 2)), y2(pos_.y - (pos_.h / 2)), x3(pos_.x - (pos_.w / 2)), y3(pos_.y + (pos_.h / 2)) {}
	inline constexpr Pos8::Pos8(const Pos8& pos_) : x1(pos_.x1), y1(pos_.y1), x2(pos_.x2), y2(pos_.y2), x3(pos_.x3), y3(pos_.y3), x4(pos_.x4), y4(pos_.y4) {}



	//--------------------------------------------------------
	//キャスト
	//--------------------------------------------------------

	//Pos2
	inline Pos2::operator Pos4() { return Pos4(*this); }
	inline Pos2::operator PosL4() { return PosL4(*this); }
	inline Pos2::operator PosA4() { return PosA4(*this); }
	inline Pos2::operator Pos8() { return Pos8(*this); }
	//Pos4
	inline Pos4::operator Pos2() { return Pos2(*this); }
	inline Pos4::operator PosL4() { return PosL4(*this); }
	inline Pos4::operator PosA4() { return PosA4(*this); }
	inline Pos4::operator Pos8() { return Pos8(*this); }
	//PosL4
	inline PosL4::operator Pos2() { return Pos2(*this); }
	inline PosL4::operator Pos4() { return Pos4(*this); }
	inline PosL4::operator PosA4() { return PosA4(*this); }
	inline PosL4::operator Pos8() { return Pos8(*this); }
	//PosA4
	inline PosA4::operator Pos2() { return Pos2(*this); }
	inline PosA4::operator Pos4() { return Pos4(*this); }
	inline PosA4::operator PosL4() { return PosL4(*this); }
	inline PosA4::operator Pos8() { return Pos8(*this); }



	//--------------------------------------------------------
	//代入
	//--------------------------------------------------------

	//Pos2
	inline const Pos2 & Pos2::operator=(const Pos4 & add_pos) { *this = Pos2(add_pos); return *this; }
	inline const Pos2 & Pos2::operator=(const PosL4 & add_pos) { *this = Pos2(add_pos); return *this; }
	inline const Pos2 & Pos2::operator=(const PosA4 & add_pos) { *this = Pos2(add_pos); return *this; }
	inline const Pos2& Pos2::operator=(const Pos8& add_pos) { *this = Pos2(add_pos); return *this; }
	//Pos4
	inline const Pos4& Pos4::operator=(const Pos2& add_pos) { *this = Pos4(add_pos); return *this; }
	inline const Pos4& Pos4::operator=(const PosL4& add_pos) { *this = Pos4(add_pos); return *this; }
	inline const Pos4& Pos4::operator=(const PosA4& add_pos) { *this = Pos4(add_pos); return *this; }
	inline const Pos4& Pos4::operator=(const Pos8& add_pos) { *this = Pos4(add_pos); return *this; }
	//PosL4
	inline const PosL4 & PosL4::operator=(const Pos2 & add_pos) { *this = PosL4(add_pos); return *this; }
	inline const PosL4& PosL4::operator=(const Pos4& add_pos) { *this = PosL4(add_pos); return *this; }
	inline const PosL4 & PosL4::operator=(const PosA4 & add_pos) { *this = PosL4(add_pos); return *this; }
	inline const PosL4 & PosL4::operator=(const Pos8 & add_pos) { *this = PosL4(add_pos); return *this; }
	//PosA4
	inline const PosA4& PosA4::operator=(const Pos2& add_pos) { *this = PosA4(add_pos); return *this; }
	inline const PosA4& PosA4::operator=(const Pos4& add_pos) { *this = PosA4(add_pos); return *this; }
	inline const PosA4& PosA4::operator=(const PosL4& add_pos) { *this = PosA4(add_pos); return *this; }
	inline const PosA4& PosA4::operator=(const Pos8& add_pos) { *this = PosA4(add_pos); return *this; }

	inline const Pos8& Pos8::operator=(const Pos4& add_pos) { *this = Pos8(add_pos); return *this; }
	inline const Pos8& Pos8::operator=(const PosL4& add_pos) { *this = Pos8(add_pos); return *this; }
	inline const Pos8& Pos8::operator=(const PosA4& add_pos) { *this = Pos8(add_pos); return *this; }
	inline const Pos8& Pos8::operator=(const Pos2& add_pos) { *this = Pos8(add_pos); return *this; }



	//--------------------------------------------------------
	//括弧代入
	//--------------------------------------------------------

	//Pos2
	inline const Pos2 & Pos2::operator()(const Pos4 & add_pos) { *this = Pos2(add_pos); return *this; }
	inline const Pos2 & Pos2::operator()(const PosL4 & add_pos) { *this = Pos2(add_pos); return *this; }
	inline const Pos2 & Pos2::operator()(const PosA4 & add_pos) { *this = Pos2(add_pos); return *this; }
	inline const Pos2& Pos2::operator()(const Pos8& add_pos) { *this = Pos2(add_pos); return *this; }
	//Pos4
	inline const Pos4& Pos4::operator()(const Pos2& add_pos) { *this = Pos4(add_pos); return *this; }
	inline const Pos4& Pos4::operator()(const PosL4& add_pos) { *this = Pos4(add_pos); return *this; }
	inline const Pos4& Pos4::operator()(const PosA4& add_pos) { *this = Pos4(add_pos); return *this; }
	inline const Pos4& Pos4::operator()(const Pos8& add_pos) { *this = Pos4(add_pos); return *this; }
	//PosL4
	inline const PosL4 & PosL4::operator()(const Pos2 & add_pos) { *this = PosL4(add_pos); return *this; }
	inline const PosL4& PosL4::operator()(const Pos4& add_pos) { *this = PosL4(add_pos); return *this; }
	inline const PosL4 & PosL4::operator()(const PosA4 & add_pos) { *this = PosL4(add_pos); return *this; }
	inline const PosL4 & PosL4::operator()(const Pos8 & add_pos) { *this = PosL4(add_pos); return *this; }
	//PosA4
	inline const PosA4& PosA4::operator()(const Pos2& add_pos) { *this = PosA4(add_pos); return *this; }
	inline const PosA4& PosA4::operator()(const Pos4& add_pos) { *this = PosA4(add_pos); return *this; }
	inline const PosA4& PosA4::operator()(const PosL4& add_pos) { *this = PosA4(add_pos); return *this; }
	inline const PosA4& PosA4::operator()(const Pos8& add_pos) { *this = PosA4(add_pos); return *this; }

	inline const Pos8& Pos8::operator()(const Pos4& add_pos) { *this = Pos8(add_pos); return *this; }
	inline const Pos8& Pos8::operator()(const PosL4& add_pos) { *this = Pos8(add_pos); return *this; }
	inline const Pos8& Pos8::operator()(const PosA4& add_pos) { *this = Pos8(add_pos); return *this; }
	inline const Pos8& Pos8::operator()(const Pos2& add_pos) { *this = Pos8(add_pos); return *this; }

	//乱数
	inline const PosA4 & PosA4::rand(const Pos2& add_pos) { *this = PosA4(add_pos); return *this; }

	//回転
	inline Pos8::Pos8(const Pos4& p_, const double r_) {
		//todo
	}

	inline const Pos8 Pos8::rotation3D(const Pos4& p_, const double r_) {
		constexpr double pos_pi = 3.141592653589793238462643383279502884197;
		//中心位置からの幅
		const int32_t size_y = int32_t(abs((p_.y2 - p_.y1) / 2));
		const int32_t size_x = int32_t(abs((p_.x2 - p_.x1) / 2));
		//中心位置からの半径
		const double size_r = sqrt(size_y * size_y + size_x * size_x);
		//位置の角度
		const double pos_r = r_ + atan2(size_y, size_x);

		//中心位置
		const int32_t pos_x = size_x + p_.x1;
		const int32_t pos_y = size_y + p_.y1;

		this->x1 = pos_x + int32_t(round(size_r*cos(pos_r + pos_pi)));
		this->y1 = pos_y + int32_t(round(size_r*sin(pos_r + pos_pi)));
		this->x2 = pos_x + int32_t(round(size_r*cos(-pos_r)));
		this->y2 = pos_y + int32_t(round(size_r*sin(-pos_r)));
		this->x3 = pos_x + int32_t(round(size_r*cos(-pos_r + pos_pi)));
		this->y3 = pos_y + int32_t(round(size_r*sin(-pos_r + pos_pi)));
		this->x4 = pos_x + int32_t(round(size_r*cos(pos_r)));
		this->y4 = pos_y + int32_t(round(size_r*sin(pos_r)));
		return *this;
	}


	inline Pos2R& Pos2R::operator=(const Pos8R& add_pos)
	{
		this->x = add_pos.x4;
		this->y = add_pos.y4;
		return *this;
	}
	inline Pos4R& Pos4R::operator=(const Pos8R& add_pos)
	{
		this->x1 = add_pos.x1;
		this->x2 = add_pos.x4;
		this->y1 = add_pos.y1;
		this->y2 = add_pos.y4;
		return *this;
	}
	inline Pos8R& Pos8R::operator=(const Pos4R& add_pos)
	{
		this->x1 = add_pos.x1;
		this->y1 = add_pos.y1;
		this->x2 = add_pos.x2;
		this->y2 = add_pos.y1;
		this->x3 = add_pos.x1;
		this->y3 = add_pos.y2;
		this->x4 = add_pos.x2;
		this->y4 = add_pos.y2;
		return *this;
	}

	inline Pos8R& Pos8R::operator=(const Pos2R& add_pos)
	{
		this->x1 = 0.0f;
		this->y1 = 0.0f;
		this->x2 = add_pos.x;
		this->y2 = 0.0f;
		this->x3 = 0.0f;
		this->y3 = add_pos.y;
		this->x4 = add_pos.x;
		this->y4 = add_pos.y;
		return *this;
	}



	//-------------------------------------------------------------------------------------

	inline Pos2R& Pos2R::operator()(const float pos_x, const float pos_y)
	{
		this->x = pos_x;
		this->y = pos_y;
		return *this;
	}

	inline Pos2R& Pos2R::operator()(const float pos_size)
	{
		this->x = pos_size;
		this->y = pos_size;
		return *this;
	}

	inline Pos2R& Pos2R::operator=(const Pos4R& add_pos)
	{
		this->x = add_pos.x2;
		this->y = add_pos.y2;
		return *this;
	}

	inline Pos4R& Pos4R::operator=(const Pos2R& add_pos)
	{
		this->x1 = 0.0f;
		this->y1 = 0.0f;
		this->x2 = add_pos.x;
		this->y2 = add_pos.y;
		return *this;
	}

	//-------------------------------------------------------------------

	inline constexpr Pos4::Pos4(const Pos4R& pos_, const Pos2& window_pos_) :x1(int32_t(pos_.x1*window_pos_.x)), y1(int32_t(pos_.y1*window_pos_.y)), x2(int32_t(pos_.x2*window_pos_.x)), y2(int32_t(pos_.y2*window_pos_.y)) {}

	inline const Pos4& Pos4::operator()(const Pos4R& pos_, const Pos2& window_pos_)
	{
		*this = Pos4(pos_, window_pos_);
		return *this;
	}

}