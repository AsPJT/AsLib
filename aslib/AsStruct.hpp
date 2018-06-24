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
	struct PosA4R;
	struct PosL4R;

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
		constexpr Pos2(const Pos2R&);
		constexpr Pos2(const Pos4R&);
		constexpr Pos2(const PosL4R&);
		constexpr Pos2(const PosA4R&);
		constexpr Pos2(const Pos8R&);

		const Pos2& operator()(Pos2* const p_) const { *p_ = *this; return *this; }
		const Pos2& operator()(int32_t* const x_, int32_t* const y_) const { *x_ = this->x; *y_ = this->y; return *this; }

		const bool is_minus() const { return (this->x <= 0 || this->y <= 0) ? true : false; };
		const int32_t plus() const { return (this->x + this->y); }
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
		constexpr Pos4(const int32_t x_, const int32_t y_, const int32_t l_) :x1(x_), y1(y_), x2(x_ + l_), y2(y_ + l_) {};
		constexpr Pos4(const int32_t x1_, const int32_t y1_, const int32_t x2_, const int32_t y2_) :x1(x1_), y1(y1_), x2(x2_), y2(y2_) {};
		constexpr Pos4(const Pos2&);
		constexpr Pos4(const Pos4&);
		constexpr Pos4(const PosL4&);
		constexpr Pos4(const PosA4&);
		constexpr Pos4(const Pos8&);
		constexpr Pos4(const Pos2R&);
		constexpr Pos4(const Pos4R&);
		constexpr Pos4(const PosL4R&);
		constexpr Pos4(const PosA4R&);
		constexpr Pos4(const Pos8R&);

		//比率
		constexpr Pos4(const Pos4R&, const Pos2&);

		const Pos4& operator()(Pos4* const p_) const { *p_ = *this; return *this; }
	};



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
		constexpr PosL4(const Pos2R&);
		constexpr PosL4(const Pos4R&);
		constexpr PosL4(const PosL4R&);
		constexpr PosL4(const PosA4R&);
		constexpr PosL4(const Pos8R&);

		const PosL4& operator()(PosL4* const p_) const { *p_ = *this; return *this; }
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
		const PosA4& operator()(const double pos_) { this->w = int32_t(this->w*pos_); this->h = int32_t(this->h*pos_); return *this; }
		const PosA4& operator()(const double pos_x, const double pos_y) { this->w = int32_t(this->w*pos_x); this->h = int32_t(this->h*pos_y); return *this; }
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
		constexpr PosA4(const Pos2R&);
		constexpr PosA4(const Pos4R&);
		constexpr PosA4(const PosL4R&);
		constexpr PosA4(const PosA4R&);
		constexpr PosA4(const Pos8R&);

		const PosA4& operator()(PosA4* const p_) const { *p_ = *this; return *this; }
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
		constexpr Pos8(const Pos2R&);
		constexpr Pos8(const Pos4R&);
		constexpr Pos8(const PosL4R&);
		constexpr Pos8(const PosA4R&);
		constexpr Pos8(const Pos8R&);

		//回転
		Pos8(const Pos4&, const double);
		const Pos8& operator()(const Pos4& p_, const double r_) { *this = Pos8(p_, r_); return *this; };

		//立体回転
		const Pos8 rotation3D(const Pos4&, const double);

		const Pos8& operator()(Pos8* const p_) const { *p_ = *this; return *this; }
	};

	//大きさ(2D)
	struct Pos2R
	{
		const Pos2R& operator=(const Pos4R& add_pos);
		const Pos2R& operator=(const PosL4R& add_pos);
		const Pos2R& operator=(const PosA4R& add_pos);
		const Pos2R& operator=(const Pos8R& add_pos);
		const Pos2R& operator()(const Pos4R& add_pos);
		const Pos2R& operator()(const PosL4R& add_pos);
		const Pos2R& operator()(const PosA4R& add_pos);
		const Pos2R& operator()(const Pos8R& add_pos);
		const Pos2R& operator()() { *this = Pos2R(0.0f); return *this; }
		const Pos2R& operator()(const float pos_size) { *this = Pos2R(pos_size); return *this; }
		const Pos2R& operator()(const float pos_x, const float pos_y) { *this = Pos2R(pos_x, pos_y); return *this; }
		const Pos2R& operator()(const double pos_) { this->x = float(this->x*pos_); this->y = float(this->y*pos_); return *this; }
		const Pos2R& operator()(const double pos_x, const double pos_y) { this->x = float(this->x*pos_x); this->y = float(this->y*pos_y); return *this; }
		operator Pos4R();
		operator PosL4R();
		operator PosA4R();
		operator Pos8R();

		float x = 0.0f;
		float y = 0.0f;

		//コンストラクタ
		Pos2R() = default;
		constexpr Pos2R(const float xy_) :x(xy_), y(xy_) {};
		constexpr Pos2R(const float x_, const float y_) :x(x_), y(y_) {};
		constexpr Pos2R(const Pos2R&);
		constexpr Pos2R(const Pos4R&);
		constexpr Pos2R(const PosL4R&);
		constexpr Pos2R(const PosA4R&);
		constexpr Pos2R(const Pos8R&);
		constexpr Pos2R(const Pos2&);
		constexpr Pos2R(const Pos4&);
		constexpr Pos2R(const PosL4&);
		constexpr Pos2R(const PosA4&);
		constexpr Pos2R(const Pos8&);

		const Pos2R& operator()(Pos2R* const p_) const { *p_ = *this; return *this; }
		const Pos2R& operator()(float* const x_, float* const y_) const { *x_ = this->x; *y_ = this->y; return *this; }

		const float plus() const { return (this->x + this->y); }
	};

	//長方形の大きさ(左上と右下の位置)
	struct Pos4R
	{
		const Pos4R& operator=(const Pos2R&);
		const Pos4R& operator=(const Pos8R&);
		const Pos4R& operator=(const PosA4R&);
		const Pos4R& operator=(const PosL4R&);
		const Pos4R& operator()(const Pos2R&);
		const Pos4R& operator()(const Pos8R&);
		const Pos4R& operator()(const PosA4R&);
		const Pos4R& operator()(const PosL4R&);
		operator Pos2R();
		operator Pos8R();
		operator PosA4R();
		operator PosL4R();
		float x1;
		float y1;
		float x2;
		float y2;

		//コンストラクタ
		Pos4R() = default;
		constexpr Pos4R(const float xy_) :x1(0.0f), y1(0.0f), x2(xy_), y2(xy_) {};
		constexpr Pos4R(const float x_, const float y_) :x1(0.0f), y1(0.0f), x2(x_), y2(y_) {};
		constexpr Pos4R(const float x_, const float y_, const float l_) :x1(x_), y1(y_), x2(x_ + l_), y2(y_ + l_) {};
		constexpr Pos4R(const float x1_, const float y1_, const float x2_, const float y2_) :x1(x1_), y1(y1_), x2(x2_), y2(y2_) {};
		constexpr Pos4R(const Pos2R&);
		constexpr Pos4R(const Pos4R&);
		constexpr Pos4R(const PosL4R&);
		constexpr Pos4R(const PosA4R&);
		constexpr Pos4R(const Pos8R&);
		constexpr Pos4R(const Pos2&);
		constexpr Pos4R(const Pos4&);
		constexpr Pos4R(const PosL4&);
		constexpr Pos4R(const PosA4&);
		constexpr Pos4R(const Pos8&);

		const Pos4R& operator()(Pos4R* const p_) const { *p_ = *this; return *this; }
	};



	//長方形の大きさ(位置と長さ)
	struct PosL4R
	{
		const PosL4R& operator=(const Pos2R& add_pos);
		const PosL4R& operator=(const Pos4R& add_pos);
		const PosL4R& operator=(const PosA4R& add_pos);
		const PosL4R& operator=(const Pos8R& add_pos);
		const PosL4R& operator()(const Pos2R& add_pos);
		const PosL4R& operator()(const Pos4R& add_pos);
		const PosL4R& operator()(const PosA4R& add_pos);
		const PosL4R& operator()(const Pos8R& add_pos);
		operator Pos2R();
		operator Pos4R();
		operator PosA4R();
		operator Pos8R();
		float x = 0.0f;
		float y = 0.0f;
		float w = 0.0f;
		float h = 0.0f;

		//コンストラクタ
		PosL4R() = default;
		constexpr PosL4R(const float xy_) :x(0.0f), y(0.0f), w(xy_), h(xy_) {};
		constexpr PosL4R(const float x_, const float y_) :x(0.0f), y(0.0f), w(x_), h(y_) {};
		constexpr PosL4R(const float x_, const float y_, const float l_) :x(x_), y(y_), w(l_), h(l_) {};
		constexpr PosL4R(const float x_, const float y_, const float w_, const float h_) :x(x_), y(y_), w(w_), h(h_) {};
		constexpr PosL4R(const Pos2R&);
		constexpr PosL4R(const Pos4R&);
		constexpr PosL4R(const PosL4R&);
		constexpr PosL4R(const PosA4R&);
		constexpr PosL4R(const Pos8R&);
		constexpr PosL4R(const Pos2&);
		constexpr PosL4R(const Pos4&);
		constexpr PosL4R(const PosL4&);
		constexpr PosL4R(const PosA4&);
		constexpr PosL4R(const Pos8&);

		const PosL4R& operator()(PosL4R* const p_) const { *p_ = *this; return *this; }
	};

	//中心位置と大きさを併せ持つ
	struct PosA4R
	{
		const PosA4R& operator=(const Pos2R& add_pos);
		const PosA4R& operator=(const Pos4R& add_pos);
		const PosA4R& operator=(const PosL4R& add_pos);
		const PosA4R& operator=(const Pos8R& add_pos);
		const PosA4R& operator()(const Pos2R& add_pos);
		const PosA4R& operator()(const Pos4R& add_pos);
		const PosA4R& operator()(const PosL4R& add_pos);
		const PosA4R& operator()(const Pos8R& add_pos);
		const PosA4R& operator()(const double pos_) { this->w = float(this->w*pos_); this->h = float(this->h*pos_); return *this; }
		const PosA4R& operator()(const double pos_x, const double pos_y) { this->w = float(this->w*pos_x); this->h = float(this->h*pos_y); return *this; }
		operator Pos2R();
		operator Pos4R();
		operator PosL4R();
		operator Pos8R();
		float x = 0.0f;
		float y = 0.0f;
		float w = 0.0f;
		float h = 0.0f;

		//コンストラクタ
		PosA4R() = default;
		constexpr PosA4R(const float xy_) :x(xy_), y(xy_), w(0.0f), h(0.0f) {};
		constexpr PosA4R(const float x_, const float y_) :x(x_), y(y_), w(0.0f), h(0.0f) {};
		constexpr PosA4R(const float x_, const float y_, const float l_) :x(x_), y(y_), w(l_), h(l_) {};
		constexpr PosA4R(const float x_, const float y_, const float w_, const float h_) :x(x_), y(y_), w(w_), h(h_) {};
		constexpr PosA4R(const Pos2R&);
		constexpr PosA4R(const Pos4R&);
		constexpr PosA4R(const PosL4R&);
		constexpr PosA4R(const PosA4R&);
		constexpr PosA4R(const Pos8R&);
		constexpr PosA4R(const Pos2&);
		constexpr PosA4R(const Pos4&);
		constexpr PosA4R(const PosL4&);
		constexpr PosA4R(const PosA4&);
		constexpr PosA4R(const Pos8&);

		const PosA4R& operator()(PosA4R* const p_) const { *p_ = *this; return *this; }
	};

	//四角形の大きさ
	struct Pos8R
	{
		const Pos8R& operator=(const Pos2R& add_pos);
		const Pos8R& operator=(const Pos4R& add_pos);
		const Pos8R& operator=(const PosL4R& add_pos);
		const Pos8R& operator=(const PosA4R& add_pos);
		const Pos8R& operator()(const Pos2R& add_pos);
		const Pos8R& operator()(const Pos4R& add_pos);
		const Pos8R& operator()(const PosL4R& add_pos);
		const Pos8R& operator()(const PosA4R& add_pos);
		float x1 = 0.0f;
		float y1 = 0.0f;
		float x2 = 0.0f;
		float y2 = 0.0f;
		float x3 = 0.0f;
		float y3 = 0.0f;
		float x4 = 0.0f;
		float y4 = 0.0f;

		//コンストラクタ
		Pos8R() = default;
		constexpr Pos8R(const float x1_, const float y1_, const float x2_, const float y2_, const float x3_, const float y3_, const float x4_, const float y4_) : x1(x1_), y1(y1_), x2(x2_), y2(y2_), x3(x3_), y3(y3_), x4(x4_), y4(y4_) {}
		constexpr Pos8R(const float x1_, const float y1_, const float x2_, const float y2_) : x1(x1_), y1(y1_), x2(x2_), y2(y1_), x3(x1_), y3(y2_), x4(x2_), y4(y2_) {}
		constexpr Pos8R(const float x_, const float y_) : x1(0.0f), y1(0.0f), x2(x_), y2(0.0f), x3(0.0f), y3(y_), x4(x_), y4(y_) {}
		constexpr Pos8R(const Pos2R&);
		constexpr Pos8R(const Pos4R&);
		constexpr Pos8R(const PosL4R&);
		constexpr Pos8R(const PosA4R&);
		constexpr Pos8R(const Pos8R&);
		constexpr Pos8R(const Pos2&);
		constexpr Pos8R(const Pos4&);
		constexpr Pos8R(const PosL4&);
		constexpr Pos8R(const PosA4&);
		constexpr Pos8R(const Pos8&);

		const Pos8R& operator()(Pos8R* const p_) const { *p_ = *this; return *this; }
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

	inline const Pos4 & Pos4::rand(const Pos2& add_pos)
	{
		this->x2 = this->x1 + asRand32(add_pos.x);
		this->y2 = this->y1 + asRand32(add_pos.y);
		return *this;
	}

	//--------------------------------------------------------
	//コンストラクタ
	//--------------------------------------------------------

	//Pos2
	inline constexpr Pos2::Pos2(const Pos2& pos_) :x(pos_.x), y(pos_.y) {}
	inline constexpr Pos2::Pos2(const Pos4& pos_) : x(pos_.x1), y(pos_.y1) {}
	inline constexpr Pos2::Pos2(const PosL4& pos_) : x(pos_.x), y(pos_.y) {}
	inline constexpr Pos2::Pos2(const PosA4& pos_) : x(pos_.x), y(pos_.y) {}
	inline constexpr Pos2::Pos2(const Pos8& pos_) : x(pos_.x1), y(pos_.y1) {}
	inline constexpr Pos2::Pos2(const Pos2R& pos_) : x(int32_t(pos_.x)), y(int32_t(pos_.y)) {}
	inline constexpr Pos2::Pos2(const Pos4R& pos_) : x(int32_t(pos_.x1)), y(int32_t(pos_.y1)) {}
	inline constexpr Pos2::Pos2(const PosL4R& pos_) : x(int32_t(pos_.x)), y(int32_t(pos_.y)) {}
	inline constexpr Pos2::Pos2(const PosA4R& pos_) : x(int32_t(pos_.x)), y(int32_t(pos_.y)) {}
	inline constexpr Pos2::Pos2(const Pos8R& pos_) : x(int32_t(pos_.x1)), y(int32_t(pos_.y1)) {}
	//Pos4
	inline constexpr Pos4::Pos4(const Pos2& pos_) : x1(0), y1(0), x2(pos_.x), y2(pos_.y) {}
	inline constexpr Pos4::Pos4(const Pos4& pos_) : x1(pos_.x1), y1(pos_.y1), x2(pos_.x2), y2(pos_.y2) {}
	inline constexpr Pos4::Pos4(const PosL4& pos_) : x1(pos_.x), y1(pos_.y), x2(pos_.x + pos_.w), y2(pos_.y + pos_.h) {}
	inline constexpr Pos4::Pos4(const PosA4& pos_) : x1(pos_.x - (pos_.w / 2)), y1(pos_.y - (pos_.h / 2)), x2(pos_.x + (pos_.w / 2)), y2(pos_.y + (pos_.h / 2)) {}
	inline constexpr Pos4::Pos4(const Pos8& pos_) : x1(pos_.x1), y1(pos_.y1), x2(pos_.x4), y2(pos_.y4) {}
	inline constexpr Pos4::Pos4(const Pos2R& pos_) : x1(int32_t(0)), y1(int32_t(0)), x2(int32_t(pos_.x)), y2(int32_t(pos_.y)) {}
	inline constexpr Pos4::Pos4(const Pos4R& pos_) : x1(int32_t(pos_.x1)), y1(int32_t(pos_.y1)), x2(int32_t(pos_.x2)), y2(int32_t(pos_.y2)) {}
	inline constexpr Pos4::Pos4(const PosL4R& pos_) : x1(int32_t(pos_.x)), y1(int32_t(pos_.y)), x2(int32_t(pos_.x + pos_.w)), y2(int32_t(pos_.y + pos_.h)) {}
	inline constexpr Pos4::Pos4(const PosA4R& pos_) : x1(int32_t(pos_.x - (pos_.w / 2))), y1(int32_t(pos_.y - (pos_.h / 2))), x2(int32_t(pos_.x + (pos_.w / 2))), y2(int32_t(pos_.y + (pos_.h / 2))) {}
	inline constexpr Pos4::Pos4(const Pos8R& pos_) : x1(int32_t(pos_.x1)), y1(int32_t(pos_.y1)), x2(int32_t(pos_.x4)), y2(int32_t(pos_.y4)) {}

	//PosL4
	inline constexpr PosL4::PosL4(const Pos2& pos_) : x(pos_.x), y(pos_.y), w(0), h(0) {}
	inline constexpr PosL4::PosL4(const Pos4& pos_) : x(pos_.x1), y(pos_.y1), w(pos_.x2 - pos_.x1), h(pos_.y2 - pos_.y1) {}
	inline constexpr PosL4::PosL4(const PosL4& pos_) : x(pos_.x), y(pos_.y), w(pos_.w), h(pos_.h) {}
	inline constexpr PosL4::PosL4(const PosA4& pos_) : x(pos_.x - (pos_.w / 2)), y(pos_.y - (pos_.h / 2)), w(pos_.w), h(pos_.h) {}
	inline constexpr PosL4::PosL4(const Pos8& pos_) : x(pos_.x1), y(pos_.y1), w(pos_.x4 - pos_.x1), h(pos_.y4 - pos_.y1) {}
	inline constexpr PosL4::PosL4(const Pos2R& pos_) : x(int32_t(pos_.x)), y(int32_t(pos_.y)), w(int32_t(0)), h(int32_t(0)) {}
	inline constexpr PosL4::PosL4(const Pos4R& pos_) : x(int32_t(pos_.x1)), y(int32_t(pos_.y1)), w(int32_t(pos_.x2 - pos_.x1)), h(int32_t(pos_.y2 - pos_.y1)) {}
	inline constexpr PosL4::PosL4(const PosL4R& pos_) : x(int32_t(pos_.x)), y(int32_t(pos_.y)), w(int32_t(pos_.w)), h(int32_t(pos_.h)) {}
	inline constexpr PosL4::PosL4(const PosA4R& pos_) : x(int32_t(pos_.x - (pos_.w / 2))), y(int32_t(pos_.y - (pos_.h / 2))), w(int32_t(pos_.w)), h(int32_t(pos_.h)) {}
	inline constexpr PosL4::PosL4(const Pos8R& pos_) : x(int32_t(pos_.x1)), y(int32_t(pos_.y1)), w(int32_t(pos_.x4 - pos_.x1)), h(int32_t(pos_.y4 - pos_.y1)) {}

	//PosA4
	inline constexpr PosA4::PosA4(const Pos2& pos_) : x(pos_.x), y(pos_.y), w(0), h(0) {}
	inline constexpr PosA4::PosA4(const Pos4& pos_) : x(pos_.x1 + ((pos_.x2 - pos_.x1) / 2)), y(pos_.y1 + ((pos_.y2 - pos_.y1) / 2)), w(pos_.x2 - pos_.x1), h(pos_.y2 - pos_.y1) {}
	inline constexpr PosA4::PosA4(const PosL4& pos_) : x(pos_.x + (pos_.w / 2)), y(pos_.y + (pos_.h / 2)), w(pos_.w), h(pos_.h) {}
	inline constexpr PosA4::PosA4(const PosA4& pos_) : x(pos_.x), y(pos_.y), w(pos_.w), h(pos_.h) {}
	inline constexpr PosA4::PosA4(const Pos8& pos_) : x(pos_.x1 + ((pos_.x4 - pos_.x1) / 2)), y(pos_.y1 + ((pos_.y4 - pos_.y1) / 2)), w(pos_.x4 - pos_.x1), h(pos_.y4 - pos_.y1) {}
	inline constexpr PosA4::PosA4(const Pos2R& pos_) : x(int32_t(pos_.x)), y(int32_t(pos_.y)), w(int32_t(0)), h(int32_t(0)) {}
	inline constexpr PosA4::PosA4(const Pos4R& pos_) : x(int32_t(pos_.x1 + ((pos_.x2 - pos_.x1) / 2))), y(int32_t(pos_.y1 + ((pos_.y2 - pos_.y1) / 2))), w(int32_t(pos_.x2 - pos_.x1)), h(int32_t(pos_.y2 - pos_.y1)) {}
	inline constexpr PosA4::PosA4(const PosL4R& pos_) : x(int32_t(pos_.x + (pos_.w / 2))), y(int32_t(pos_.y + (pos_.h / 2))), w(int32_t(pos_.w)), h(int32_t(pos_.h)) {}
	inline constexpr PosA4::PosA4(const PosA4R& pos_) : x(int32_t(pos_.x)), y(int32_t(pos_.y)), w(int32_t(pos_.w)), h(int32_t(pos_.h)) {}
	inline constexpr PosA4::PosA4(const Pos8R& pos_) : x(int32_t(pos_.x1 + ((pos_.x4 - pos_.x1) / 2))), y(int32_t(pos_.y1 + ((pos_.y4 - pos_.y1) / 2))), w(int32_t(pos_.x4 - pos_.x1)), h(int32_t(pos_.y4 - pos_.y1)) {}

	//Pos8
	inline constexpr Pos8::Pos8(const Pos2& pos_) : x1(0), y1(0), x4(pos_.x), y4(pos_.y), x2(pos_.x), y2(0), x3(0), y3(pos_.y) {}
	inline constexpr Pos8::Pos8(const Pos4& pos_) : x1(pos_.x1), y1(pos_.y1), x4(pos_.x2), y4(pos_.y2), x2(pos_.x2), y2(pos_.y1), x3(pos_.x1), y3(pos_.y2) {}
	inline constexpr Pos8::Pos8(const PosL4& pos_) : x1(pos_.x), y1(pos_.y), x4(pos_.x + pos_.w), y4(pos_.y + pos_.h), x2(pos_.x + pos_.w), y2(pos_.y), x3(pos_.x), y3(pos_.y + pos_.h) {}
	inline constexpr Pos8::Pos8(const PosA4& pos_) : x1(pos_.x - (pos_.w / 2)), y1(pos_.y - (pos_.h / 2)), x4(pos_.x + (pos_.w / 2)), y4(pos_.y + (pos_.h / 2)), x2(pos_.x + (pos_.w / 2)), y2(pos_.y - (pos_.h / 2)), x3(pos_.x - (pos_.w / 2)), y3(pos_.y + (pos_.h / 2)) {}
	inline constexpr Pos8::Pos8(const Pos8& pos_) : x1(pos_.x1), y1(pos_.y1), x2(pos_.x2), y2(pos_.y2), x3(pos_.x3), y3(pos_.y3), x4(pos_.x4), y4(pos_.y4) {}
	inline constexpr Pos8::Pos8(const Pos2R& pos_) : x1(int32_t(0)), y1(int32_t(0)), x4(int32_t(pos_.x)), y4(int32_t(pos_.y)), x2(int32_t(pos_.x)), y2(int32_t(0)), x3(int32_t(0)), y3(int32_t(pos_.y)) {}
	inline constexpr Pos8::Pos8(const Pos4R& pos_) : x1(int32_t(pos_.x1)), y1(int32_t(pos_.y1)), x4(int32_t(pos_.x2)), y4(int32_t(pos_.y2)), x2(int32_t(pos_.x2)), y2(int32_t(pos_.y1)), x3(int32_t(pos_.x1)), y3(int32_t(pos_.y2)) {}
	inline constexpr Pos8::Pos8(const PosL4R& pos_) : x1(int32_t(pos_.x)), y1(int32_t(pos_.y)), x4(int32_t(pos_.x + pos_.w)), y4(int32_t(pos_.y + pos_.h)), x2(int32_t(pos_.x + pos_.w)), y2(int32_t(pos_.y)), x3(int32_t(pos_.x)), y3(int32_t(pos_.y + pos_.h)) {}
	inline constexpr Pos8::Pos8(const PosA4R& pos_) : x1(int32_t(pos_.x - (pos_.w / 2))), y1(int32_t(pos_.y - (pos_.h / 2))), x4(int32_t(pos_.x + (pos_.w / 2))), y4(int32_t(pos_.y + (pos_.h / 2))), x2(int32_t(pos_.x + (pos_.w / 2))), y2(int32_t(pos_.y - (pos_.h / 2))), x3(int32_t(pos_.x - (pos_.w / 2))), y3(int32_t(pos_.y + (pos_.h / 2))) {}
	inline constexpr Pos8::Pos8(const Pos8R& pos_) : x1(int32_t(pos_.x1)), y1(int32_t(pos_.y1)), x2(int32_t(pos_.x2)), y2(int32_t(pos_.y2)), x3(int32_t(pos_.x3)), y3(int32_t(pos_.y3)), x4(int32_t(pos_.x4)), y4(int32_t(pos_.y4)) {}



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
		const int32_t size_y = int32_t(fabs((p_.y2 - p_.y1) / 2.0));
		const int32_t size_x = int32_t(fabs((p_.x2 - p_.x1) / 2.0));
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




	//-------------------------------------------------------------------

	inline constexpr Pos4::Pos4(const Pos4R& pos_, const Pos2& window_pos_) :x1(int32_t(pos_.x1*window_pos_.x)), y1(int32_t(pos_.y1*window_pos_.y)), x2(int32_t(pos_.x2*window_pos_.x)), y2(int32_t(pos_.y2*window_pos_.y)) {}

	inline const Pos4& Pos4::operator()(const Pos4R& pos_, const Pos2& window_pos_)
	{
		*this = Pos4(pos_, window_pos_);
		return *this;
	}


	//--------------------------------------------------------
	//コンストラクタ
	//--------------------------------------------------------

	//Pos2R
	inline constexpr Pos2R::Pos2R(const Pos2R& pos_) :x(pos_.x), y(pos_.y) {}
	inline constexpr Pos2R::Pos2R(const Pos4R& pos_) : x(pos_.x1), y(pos_.y1) {}
	inline constexpr Pos2R::Pos2R(const PosL4R& pos_) : x(pos_.x), y(pos_.y) {}
	inline constexpr Pos2R::Pos2R(const PosA4R& pos_) : x(pos_.x), y(pos_.y) {}
	inline constexpr Pos2R::Pos2R(const Pos8R& pos_) : x(pos_.x1), y(pos_.y1) {}
	inline constexpr Pos2R::Pos2R(const Pos2& pos_) : x(float(pos_.x)), y(float(pos_.y)) {}
	inline constexpr Pos2R::Pos2R(const Pos4& pos_) : x(float(pos_.x1)), y(float(pos_.y1)) {}
	inline constexpr Pos2R::Pos2R(const PosL4& pos_) : x(float(pos_.x)), y(float(pos_.y)) {}
	inline constexpr Pos2R::Pos2R(const PosA4& pos_) : x(float(pos_.x)), y(float(pos_.y)) {}
	inline constexpr Pos2R::Pos2R(const Pos8& pos_) : x(float(pos_.x1)), y(float(pos_.y1)) {}

	//Pos4R
	inline constexpr Pos4R::Pos4R(const Pos2R& pos_) : x1(0.0f), y1(0.0f), x2(pos_.x), y2(pos_.y) {}
	inline constexpr Pos4R::Pos4R(const Pos4R& pos_) : x1(pos_.x1), y1(pos_.y1), x2(pos_.x2), y2(pos_.y2) {}
	inline constexpr Pos4R::Pos4R(const PosL4R& pos_) : x1(pos_.x), y1(pos_.y), x2(pos_.x + pos_.w), y2(pos_.y + pos_.h) {}
	inline constexpr Pos4R::Pos4R(const PosA4R& pos_) : x1(pos_.x - (pos_.w / 2)), y1(pos_.y - (pos_.h / 2)), x2(pos_.x + (pos_.w / 2)), y2(pos_.y + (pos_.h / 2)) {}
	inline constexpr Pos4R::Pos4R(const Pos8R& pos_) : x1(pos_.x1), y1(pos_.y1), x2(pos_.x4), y2(pos_.y4) {}
	inline constexpr Pos4R::Pos4R(const Pos2& pos_) : x1(float(0)), y1(float(0)), x2(float(pos_.x)), y2(float(pos_.y)) {}
	inline constexpr Pos4R::Pos4R(const Pos4& pos_) : x1(float(pos_.x1)), y1(float(pos_.y1)), x2(float(pos_.x2)), y2(float(pos_.y2)) {}
	inline constexpr Pos4R::Pos4R(const PosL4& pos_) : x1(float(pos_.x)), y1(float(pos_.y)), x2(float(pos_.x + pos_.w)), y2(float(pos_.y + pos_.h)) {}
	inline constexpr Pos4R::Pos4R(const PosA4& pos_) : x1(float(pos_.x - (pos_.w / 2))), y1(float(pos_.y - (pos_.h / 2))), x2(float(pos_.x + (pos_.w / 2))), y2(float(pos_.y + (pos_.h / 2))) {}
	inline constexpr Pos4R::Pos4R(const Pos8& pos_) : x1(float(pos_.x1)), y1(float(pos_.y1)), x2(float(pos_.x4)), y2(float(pos_.y4)) {}

	//PosL4R
	inline constexpr PosL4R::PosL4R(const Pos2R& pos_) : x(pos_.x), y(pos_.y), w(0.0f), h(0.0f) {}
	inline constexpr PosL4R::PosL4R(const Pos4R& pos_) : x(pos_.x1), y(pos_.y1), w(pos_.x2 - pos_.x1), h(pos_.y2 - pos_.y1) {}
	inline constexpr PosL4R::PosL4R(const PosL4R& pos_) : x(pos_.x), y(pos_.y), w(pos_.w), h(pos_.h) {}
	inline constexpr PosL4R::PosL4R(const PosA4R& pos_) : x(pos_.x - (pos_.w / 2)), y(pos_.y - (pos_.h / 2)), w(pos_.w), h(pos_.h) {}
	inline constexpr PosL4R::PosL4R(const Pos8R& pos_) : x(pos_.x1), y(pos_.y1), w(pos_.x4 - pos_.x1), h(pos_.y4 - pos_.y1) {}
	inline constexpr PosL4R::PosL4R(const Pos2& pos_) : x(float(pos_.x)), y(float(pos_.y)), w(float(0)), h(float(0)) {}
	inline constexpr PosL4R::PosL4R(const Pos4& pos_) : x(float(pos_.x1)), y(float(pos_.y1)), w(float(pos_.x2 - pos_.x1)), h(float(pos_.y2 - pos_.y1)) {}
	inline constexpr PosL4R::PosL4R(const PosL4& pos_) : x(float(pos_.x)), y(float(pos_.y)), w(float(pos_.w)), h(float(pos_.h)) {}
	inline constexpr PosL4R::PosL4R(const PosA4& pos_) : x(float(pos_.x - (pos_.w / 2))), y(float(pos_.y - (pos_.h / 2))), w(float(pos_.w)), h(float(pos_.h)) {}
	inline constexpr PosL4R::PosL4R(const Pos8& pos_) : x(float(pos_.x1)), y(float(pos_.y1)), w(float(pos_.x4 - pos_.x1)), h(float(pos_.y4 - pos_.y1)) {}

	//PosA4R
	inline constexpr PosA4R::PosA4R(const Pos2R& pos_) : x(pos_.x), y(pos_.y), w(0.0f), h(0.0f) {}
	inline constexpr PosA4R::PosA4R(const Pos4R& pos_) : x(pos_.x1 + ((pos_.x2 - pos_.x1) / 2)), y(pos_.y1 + ((pos_.y2 - pos_.y1) / 2)), w(pos_.x2 - pos_.x1), h(pos_.y2 - pos_.y1) {}
	inline constexpr PosA4R::PosA4R(const PosL4R& pos_) : x(pos_.x + (pos_.w / 2)), y(pos_.y + (pos_.h / 2)), w(pos_.w), h(pos_.h) {}
	inline constexpr PosA4R::PosA4R(const PosA4R& pos_) : x(pos_.x), y(pos_.y), w(pos_.w), h(pos_.h) {}
	inline constexpr PosA4R::PosA4R(const Pos8R& pos_) : x(pos_.x1 + ((pos_.x4 - pos_.x1) / 2)), y(pos_.y1 + ((pos_.y4 - pos_.y1) / 2)), w(pos_.x4 - pos_.x1), h(pos_.y4 - pos_.y1) {}
	inline constexpr PosA4R::PosA4R(const Pos2& pos_) : x(float(pos_.x)), y(float(pos_.y)), w(float(0)), h(float(0)) {}
	inline constexpr PosA4R::PosA4R(const Pos4& pos_) : x(float(pos_.x1 + ((pos_.x2 - pos_.x1) / 2))), y(float(pos_.y1 + ((pos_.y2 - pos_.y1) / 2))), w(float(pos_.x2 - pos_.x1)), h(float(pos_.y2 - pos_.y1)) {}
	inline constexpr PosA4R::PosA4R(const PosL4& pos_) : x(float(pos_.x + (pos_.w / 2))), y(float(pos_.y + (pos_.h / 2))), w(float(pos_.w)), h(float(pos_.h)) {}
	inline constexpr PosA4R::PosA4R(const PosA4& pos_) : x(float(pos_.x)), y(float(pos_.y)), w(float(pos_.w)), h(float(pos_.h)) {}
	inline constexpr PosA4R::PosA4R(const Pos8& pos_) : x(float(pos_.x1 + ((pos_.x4 - pos_.x1) / 2))), y(float(pos_.y1 + ((pos_.y4 - pos_.y1) / 2))), w(float(pos_.x4 - pos_.x1)), h(float(pos_.y4 - pos_.y1)) {}

	//Pos8R
	inline constexpr Pos8R::Pos8R(const Pos2R& pos_) : x1(0.0f), y1(0.0f), x4(pos_.x), y4(pos_.y), x2(pos_.x), y2(0.0f), x3(0.0f), y3(pos_.y) {}
	inline constexpr Pos8R::Pos8R(const Pos4R& pos_) : x1(pos_.x1), y1(pos_.y1), x4(pos_.x2), y4(pos_.y2), x2(pos_.x2), y2(pos_.y1), x3(pos_.x1), y3(pos_.y2) {}
	inline constexpr Pos8R::Pos8R(const PosL4R& pos_) : x1(pos_.x), y1(pos_.y), x4(pos_.x + pos_.w), y4(pos_.y + pos_.h), x2(pos_.x + pos_.w), y2(pos_.y), x3(pos_.x), y3(pos_.y + pos_.h) {}
	inline constexpr Pos8R::Pos8R(const PosA4R& pos_) : x1(pos_.x - (pos_.w / 2)), y1(pos_.y - (pos_.h / 2)), x4(pos_.x + (pos_.w / 2)), y4(pos_.y + (pos_.h / 2)), x2(pos_.x + (pos_.w / 2)), y2(pos_.y - (pos_.h / 2)), x3(pos_.x - (pos_.w / 2)), y3(pos_.y + (pos_.h / 2)) {}
	inline constexpr Pos8R::Pos8R(const Pos8R& pos_) : x1(pos_.x1), y1(pos_.y1), x2(pos_.x2), y2(pos_.y2), x3(pos_.x3), y3(pos_.y3), x4(pos_.x4), y4(pos_.y4) {}
	inline constexpr Pos8R::Pos8R(const Pos2& pos_) : x1(float(0)), y1(float(0)), x4(float(pos_.x)), y4(float(pos_.y)), x2(float(pos_.x)), y2(float(0)), x3(float(0)), y3(float(pos_.y)) {}
	inline constexpr Pos8R::Pos8R(const Pos4& pos_) : x1(float(pos_.x1)), y1(float(pos_.y1)), x4(float(pos_.x2)), y4(float(pos_.y2)), x2(float(pos_.x2)), y2(float(pos_.y1)), x3(float(pos_.x1)), y3(float(pos_.y2)) {}
	inline constexpr Pos8R::Pos8R(const PosL4& pos_) : x1(float(pos_.x)), y1(float(pos_.y)), x4(float(pos_.x + pos_.w)), y4(float(pos_.y + pos_.h)), x2(float(pos_.x + pos_.w)), y2(float(pos_.y)), x3(float(pos_.x)), y3(float(pos_.y + pos_.h)) {}
	inline constexpr Pos8R::Pos8R(const PosA4& pos_) : x1(float(pos_.x - (pos_.w / 2))), y1(float(pos_.y - (pos_.h / 2))), x4(float(pos_.x + (pos_.w / 2))), y4(float(pos_.y + (pos_.h / 2))), x2(float(pos_.x + (pos_.w / 2))), y2(float(pos_.y - (pos_.h / 2))), x3(float(pos_.x - (pos_.w / 2))), y3(float(pos_.y + (pos_.h / 2))) {}
	inline constexpr Pos8R::Pos8R(const Pos8& pos_) : x1(float(pos_.x1)), y1(float(pos_.y1)), x2(float(pos_.x2)), y2(float(pos_.y2)), x3(float(pos_.x3)), y3(float(pos_.y3)), x4(float(pos_.x4)), y4(float(pos_.y4)) {}



	//--------------------------------------------------------
	//キャスト
	//--------------------------------------------------------

	//Pos2R
	inline Pos2R::operator Pos4R() { return Pos4R(*this); }
	inline Pos2R::operator PosL4R() { return PosL4R(*this); }
	inline Pos2R::operator PosA4R() { return PosA4R(*this); }
	inline Pos2R::operator Pos8R() { return Pos8R(*this); }
	//Pos4R
	inline Pos4R::operator Pos2R() { return Pos2R(*this); }
	inline Pos4R::operator PosL4R() { return PosL4R(*this); }
	inline Pos4R::operator PosA4R() { return PosA4R(*this); }
	inline Pos4R::operator Pos8R() { return Pos8R(*this); }
	//PosL4R
	inline PosL4R::operator Pos2R() { return Pos2R(*this); }
	inline PosL4R::operator Pos4R() { return Pos4R(*this); }
	inline PosL4R::operator PosA4R() { return PosA4R(*this); }
	inline PosL4R::operator Pos8R() { return Pos8R(*this); }
	//PosA4R
	inline PosA4R::operator Pos2R() { return Pos2R(*this); }
	inline PosA4R::operator Pos4R() { return Pos4R(*this); }
	inline PosA4R::operator PosL4R() { return PosL4R(*this); }
	inline PosA4R::operator Pos8R() { return Pos8R(*this); }



	//--------------------------------------------------------
	//代入
	//--------------------------------------------------------

	//Pos2R
	inline const Pos2R & Pos2R::operator=(const Pos4R & add_pos) { *this = Pos2R(add_pos); return *this; }
	inline const Pos2R & Pos2R::operator=(const PosL4R & add_pos) { *this = Pos2R(add_pos); return *this; }
	inline const Pos2R & Pos2R::operator=(const PosA4R & add_pos) { *this = Pos2R(add_pos); return *this; }
	inline const Pos2R& Pos2R::operator=(const Pos8R& add_pos) { *this = Pos2R(add_pos); return *this; }
	//Pos4R
	inline const Pos4R& Pos4R::operator=(const Pos2R& add_pos) { *this = Pos4R(add_pos); return *this; }
	inline const Pos4R& Pos4R::operator=(const PosL4R& add_pos) { *this = Pos4R(add_pos); return *this; }
	inline const Pos4R& Pos4R::operator=(const PosA4R& add_pos) { *this = Pos4R(add_pos); return *this; }
	inline const Pos4R& Pos4R::operator=(const Pos8R& add_pos) { *this = Pos4R(add_pos); return *this; }
	//PosL4R
	inline const PosL4R & PosL4R::operator=(const Pos2R & add_pos) { *this = PosL4R(add_pos); return *this; }
	inline const PosL4R& PosL4R::operator=(const Pos4R& add_pos) { *this = PosL4R(add_pos); return *this; }
	inline const PosL4R & PosL4R::operator=(const PosA4R & add_pos) { *this = PosL4R(add_pos); return *this; }
	inline const PosL4R & PosL4R::operator=(const Pos8R & add_pos) { *this = PosL4R(add_pos); return *this; }
	//PosA4R
	inline const PosA4R& PosA4R::operator=(const Pos2R& add_pos) { *this = PosA4R(add_pos); return *this; }
	inline const PosA4R& PosA4R::operator=(const Pos4R& add_pos) { *this = PosA4R(add_pos); return *this; }
	inline const PosA4R& PosA4R::operator=(const PosL4R& add_pos) { *this = PosA4R(add_pos); return *this; }
	inline const PosA4R& PosA4R::operator=(const Pos8R& add_pos) { *this = PosA4R(add_pos); return *this; }

	inline const Pos8R& Pos8R::operator=(const Pos4R& add_pos) { *this = Pos8R(add_pos); return *this; }
	inline const Pos8R& Pos8R::operator=(const PosL4R& add_pos) { *this = Pos8R(add_pos); return *this; }
	inline const Pos8R& Pos8R::operator=(const PosA4R& add_pos) { *this = Pos8R(add_pos); return *this; }
	inline const Pos8R& Pos8R::operator=(const Pos2R& add_pos) { *this = Pos8R(add_pos); return *this; }



	//--------------------------------------------------------
	//括弧代入
	//--------------------------------------------------------

	//Pos2R
	inline const Pos2R & Pos2R::operator()(const Pos4R & add_pos) { *this = Pos2R(add_pos); return *this; }
	inline const Pos2R & Pos2R::operator()(const PosL4R & add_pos) { *this = Pos2R(add_pos); return *this; }
	inline const Pos2R & Pos2R::operator()(const PosA4R & add_pos) { *this = Pos2R(add_pos); return *this; }
	inline const Pos2R& Pos2R::operator()(const Pos8R& add_pos) { *this = Pos2R(add_pos); return *this; }
	//Pos4R
	inline const Pos4R& Pos4R::operator()(const Pos2R& add_pos) { *this = Pos4R(add_pos); return *this; }
	inline const Pos4R& Pos4R::operator()(const PosL4R& add_pos) { *this = Pos4R(add_pos); return *this; }
	inline const Pos4R& Pos4R::operator()(const PosA4R& add_pos) { *this = Pos4R(add_pos); return *this; }
	inline const Pos4R& Pos4R::operator()(const Pos8R& add_pos) { *this = Pos4R(add_pos); return *this; }
	//PosL4R
	inline const PosL4R & PosL4R::operator()(const Pos2R & add_pos) { *this = PosL4R(add_pos); return *this; }
	inline const PosL4R& PosL4R::operator()(const Pos4R& add_pos) { *this = PosL4R(add_pos); return *this; }
	inline const PosL4R & PosL4R::operator()(const PosA4R & add_pos) { *this = PosL4R(add_pos); return *this; }
	inline const PosL4R & PosL4R::operator()(const Pos8R & add_pos) { *this = PosL4R(add_pos); return *this; }
	//PosA4R
	inline const PosA4R& PosA4R::operator()(const Pos2R& add_pos) { *this = PosA4R(add_pos); return *this; }
	inline const PosA4R& PosA4R::operator()(const Pos4R& add_pos) { *this = PosA4R(add_pos); return *this; }
	inline const PosA4R& PosA4R::operator()(const PosL4R& add_pos) { *this = PosA4R(add_pos); return *this; }
	inline const PosA4R& PosA4R::operator()(const Pos8R& add_pos) { *this = PosA4R(add_pos); return *this; }

	inline const Pos8R& Pos8R::operator()(const Pos4R& add_pos) { *this = Pos8R(add_pos); return *this; }
	inline const Pos8R& Pos8R::operator()(const PosL4R& add_pos) { *this = Pos8R(add_pos); return *this; }
	inline const Pos8R& Pos8R::operator()(const PosA4R& add_pos) { *this = Pos8R(add_pos); return *this; }
	inline const Pos8R& Pos8R::operator()(const Pos2R& add_pos) { *this = Pos8R(add_pos); return *this; }


	//--------------------------------------------------------
	//その他、位置関連の関数
	//--------------------------------------------------------
	inline void asRand(Pos2& p_) { p_.x = asRand(); p_.y = asRand(); }
	inline void asRand(Pos2R& p_) { p_.x = float(asRand()); p_.y = float(asRand()); }
	inline void asRand(Pos4& p_) { p_.x1 = asRand(); p_.y1 = asRand(); p_.x2 = asRand(); p_.y2 = asRand(); }
	inline void asRand(Pos4R& p_) { p_.x1 = float(asRand()); p_.y1 = float(asRand()); p_.x2 = float(asRand()); p_.y2 = float(asRand()); }
	inline void asRand(PosL4& p_) { p_.x = asRand(); p_.y = asRand(); p_.w = asRand(); p_.h = asRand(); }
	inline void asRand(PosL4R& p_) { p_.x = float(asRand()); p_.y = float(asRand()); p_.w = float(asRand()); p_.h = float(asRand()); }
	inline void asRand(PosA4& p_) { p_.x = asRand(); p_.y = asRand(); p_.w = asRand(); p_.h = asRand(); }
	inline void asRand(PosA4R& p_) { p_.x = float(asRand()); p_.y = float(asRand()); p_.w = float(asRand()); p_.h = float(asRand()); }
	inline void asRand(Pos8& p_) { p_.x1 = asRand(); p_.y1 = asRand(); p_.x2 = asRand(); p_.y2 = asRand(); p_.x3 = asRand(); p_.y3 = asRand(); p_.x4 = asRand(); p_.y4 = asRand(); }
	inline void asRand(Pos8R& p_) { p_.x1 = float(asRand()); p_.y1 = float(asRand()); p_.x2 = float(asRand()); p_.y2 = float(asRand()); p_.x3 = float(asRand()); p_.y3 = float(asRand()); p_.x4 = float(asRand()); p_.y4 = float(asRand()); }

	inline void asRand(Pos2* const array_, const size_t s_) { for (size_t i = 0; i < s_; ++i) asRand(array_[i]); }
	inline void asRand(std::vector<Pos2>& array_) { const size_t s = array_.size(); for (size_t i = 0; i < s; ++i) asRand(array_[i]); }
	inline void asRand(Pos2R* const array_, const size_t s_) { for (size_t i = 0; i < s_; ++i) asRand(array_[i]); }
	inline void asRand(std::vector<Pos2R>& array_) { const size_t s = array_.size(); for (size_t i = 0; i < s; ++i) asRand(array_[i]); }
	inline void asRand(Pos4* const array_, const size_t s_) { for (size_t i = 0; i < s_; ++i) asRand(array_[i]); }
	inline void asRand(std::vector<Pos4>& array_) { const size_t s = array_.size(); for (size_t i = 0; i < s; ++i) asRand(array_[i]); }
	inline void asRand(Pos4R* const array_, const size_t s_) { for (size_t i = 0; i < s_; ++i) asRand(array_[i]); }
	inline void asRand(std::vector<Pos4R>& array_) { const size_t s = array_.size(); for (size_t i = 0; i < s; ++i) asRand(array_[i]); }
	inline void asRand(PosL4* const array_, const size_t s_) { for (size_t i = 0; i < s_; ++i) asRand(array_[i]); }
	inline void asRand(std::vector<PosL4>& array_) { const size_t s = array_.size(); for (size_t i = 0; i < s; ++i) asRand(array_[i]); }
	inline void asRand(PosL4R* const array_, const size_t s_) { for (size_t i = 0; i < s_; ++i) asRand(array_[i]); }
	inline void asRand(std::vector<PosL4R>& array_) { const size_t s = array_.size(); for (size_t i = 0; i < s; ++i) asRand(array_[i]); }
	inline void asRand(PosA4* const array_, const size_t s_) { for (size_t i = 0; i < s_; ++i) asRand(array_[i]); }
	inline void asRand(std::vector<PosA4>& array_) { const size_t s = array_.size(); for (size_t i = 0; i < s; ++i) asRand(array_[i]); }
	inline void asRand(PosA4R* const array_, const size_t s_) { for (size_t i = 0; i < s_; ++i) asRand(array_[i]); }
	inline void asRand(std::vector<PosA4R>& array_) { const size_t s = array_.size(); for (size_t i = 0; i < s; ++i) asRand(array_[i]); }
	inline void asRand(Pos8* const array_, const size_t s_) { for (size_t i = 0; i < s_; ++i) asRand(array_[i]); }
	inline void asRand(std::vector<Pos8>& array_) { const size_t s = array_.size(); for (size_t i = 0; i < s; ++i) asRand(array_[i]); }
	inline void asRand(Pos8R* const array_, const size_t s_) { for (size_t i = 0; i < s_; ++i) asRand(array_[i]); }
	inline void asRand(std::vector<Pos8R>& array_) { const size_t s = array_.size(); for (size_t i = 0; i < s; ++i) asRand(array_[i]); }
}