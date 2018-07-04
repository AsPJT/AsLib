//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asライブラリ
//
//                    制作者: がっちょ (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------

namespace AsLib
{
	//変数
#if defined(AS_CHANGE_VAR_POS_INT)
	using pos_int = AS_CHANGE_VAR_POS;
#else
	using pos_int = int_least32_t;
#endif
#if defined(AS_CHANGE_VAR_POS_FLOAT)
	using pos_float = AS_CHANGE_VAR_POS_FLOAT;
#else
	using pos_float = float;
#endif

	//2点位置
	struct Pos2;
	struct Pos2F;

	//4点位置
	struct Pos4;
	struct Pos4F;

	//2点位置+2点サイズ
	struct PosA4;
	struct PosL4;
	struct PosA4F;
	struct PosL4F;

	//8点位置
	struct Pos8;
	struct Pos8F;

	//大きさ(2D)
	struct Pos2
	{
		//メンバ変数----------
		pos_int x{};
		pos_int y{};
		//コンストラクタ----------
		Pos2() = default;
		constexpr Pos2(const pos_int xy_) :x(xy_), y(xy_) {};
		constexpr Pos2(const pos_int x_, const pos_int y_) :x(x_), y(y_) {};
		constexpr Pos2(const Pos2&);
		constexpr Pos2(const Pos4&);
		constexpr Pos2(const PosL4&);
		constexpr Pos2(const PosA4&);
		constexpr Pos2(const Pos8&);
		constexpr Pos2(const Pos2F&);
		constexpr Pos2(const Pos4F&);
		constexpr Pos2(const PosL4F&);
		constexpr Pos2(const PosA4F&);
		constexpr Pos2(const Pos8F&);
		//デストラクタ----------
		~Pos2() = default;
		//型変換----------
		const Pos2 convPos2() const;
		const Pos4 convPos4() const;
		const PosL4 convPosL4() const;
		const PosA4 convPosA4() const;
		const Pos8 convPos8() const;
		const Pos2F convPos2F() const;
		const Pos4F convPos4F() const;
		const PosL4F convPosL4F() const;
		const PosA4F convPosA4F() const;
		const Pos8F convPos8F() const;
		//--------------------

		const Pos2& operator-() { this->x *= -1; this->y *= -1; return *this; }
		const Pos2& operator+() { *this; }

		const Pos2& operator=(const Pos4& add_pos);
		const Pos2& operator=(const PosL4& add_pos);
		const Pos2& operator=(const PosA4& add_pos);
		const Pos2& operator=(const Pos8& add_pos);
		const Pos2& operator+=(const Pos2& add_pos);
		const Pos2& operator+=(const Pos4& add_pos);
		const Pos2& operator+=(const PosL4& add_pos);
		const Pos2& operator+=(const PosA4& add_pos);
		const Pos2& operator+=(const Pos8& add_pos);
		const Pos2& operator()(const Pos4& add_pos);
		const Pos2& operator()(const PosL4& add_pos);
		const Pos2& operator()(const PosA4& add_pos);
		const Pos2& operator()(const Pos8& add_pos);
		const Pos2& operator()() { *this = Pos2(); return *this; }
		const Pos2& operator()(const pos_int pos_size) { *this = Pos2(pos_size); return *this; }
		const Pos2& operator()(const pos_int pos_x, const pos_int pos_y) { *this = Pos2(pos_x, pos_y); return *this; }
		const Pos2& operator()(const double pos_) { this->x = pos_int(this->x*pos_); this->y = pos_int(this->y*pos_); return *this; }
		const Pos2& operator()(const double pos_x, const double pos_y) { this->x = pos_int(this->x*pos_x); this->y = pos_int(this->y*pos_y); return *this; }

		const Pos2& copy(int32_t& x_, int32_t& y_) const { x_ = this->x; y_ = this->y; return *this; }
		const Pos2& copy(int32_t* const x_, int32_t* const y_) const { if (x_ != nullptr)*x_ = this->x; if (y_ != nullptr)*y_ = this->y; return *this; }


		operator Pos4();
		operator PosL4();
		operator PosA4();
		operator Pos8();
		const Pos2& rand(const Pos2&);
		const Pos2& randPlus(const uint32_t);



		const Pos2& operator()(Pos2* const p_) const { *p_ = *this; return *this; }
		const Pos2& operator()(pos_int* const x_, pos_int* const y_) const { *x_ = this->x; *y_ = this->y; return *this; }

		const bool is_minus() const { return (this->x <= 0 || this->y <= 0) ? true : false; };
		const pos_int plus() const { return (this->x + this->y); }
		const pos_float Hypot() const { return pos_float(hypot(this->x, this->y)); }
		const Pos2& Hypot(pos_float& f_) const { f_ = pos_float(hypot(this->x, this->y)); return *this; }
		const Pos2& Hypot(pos_float* f_) const { if (f_ != nullptr)*f_ = pos_float(hypot(this->x, this->y)); return *this; }
		const Pos2& Hypot(double& f_) const { f_ = double(hypot(this->x, this->y)); return *this; }
		const Pos2& Hypot(double* f_) const { if (f_ != nullptr)*f_ = double(hypot(this->x, this->y)); return *this; }
		


#if defined(ASLIB_INCLUDE_S3) //Siv3D
		operator s3d::Point()
		{
			s3d::Point p_;
			p_.x = this->x;
			p_.x = this->y;
			return p_;
		}
		Pos2 operator=(const s3d::Point& add_pos) { return Pos2(pos_int(add_pos.x), pos_int(add_pos.y)); }
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
		//メンバ変数----------
		pos_int x1{};
		pos_int y1{};
		pos_int x2{};
		pos_int y2{};
		//コンストラクタ----------
		Pos4() = default;
		constexpr Pos4(const pos_int xy_) :x1(0), y1(0), x2(xy_), y2(xy_) {};
		constexpr Pos4(const pos_int x_, const pos_int y_) :x1(0), y1(0), x2(x_), y2(y_) {};
		constexpr Pos4(const pos_int x_, const pos_int y_, const pos_int l_) :x1(x_), y1(y_), x2(x_ + l_), y2(y_ + l_) {};
		constexpr Pos4(const pos_int x1_, const pos_int y1_, const pos_int x2_, const pos_int y2_) :x1(x1_), y1(y1_), x2(x2_), y2(y2_) {};
		constexpr Pos4(const Pos2&);
		constexpr Pos4(const Pos4&);
		constexpr Pos4(const PosL4&);
		constexpr Pos4(const PosA4&);
		constexpr Pos4(const Pos8&);
		constexpr Pos4(const Pos2F&);
		constexpr Pos4(const Pos4F&);
		constexpr Pos4(const PosL4F&);
		constexpr Pos4(const PosA4F&);
		constexpr Pos4(const Pos8F&);
		//デストラクタ----------
		~Pos4() = default;
		//型変換----------
		const Pos2 convPos2() const;
		const Pos4 convPos4() const;
		const PosL4 convPosL4() const;
		const PosA4 convPosA4() const;
		const Pos8 convPos8() const;
		const Pos2F convPos2F() const;
		const Pos4F convPos4F() const;
		const PosL4F convPosL4F() const;
		const PosA4F convPosA4F() const;
		const Pos8F convPos8F() const;
		//--------------------

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

		const Pos4& rand(const Pos2&);
		const Pos4& operator() (const Pos4F&, const Pos2&);



		//比率
		constexpr Pos4(const Pos4F&, const Pos2&);

		const Pos4& operator()(Pos4* const p_) const { *p_ = *this; return *this; }


	};



	//長方形の大きさ(位置と長さ)
	struct PosL4
	{
		//メンバ変数----------
		pos_int x{};
		pos_int y{};
		pos_int w{};
		pos_int h{};
		//コンストラクタ----------
		PosL4() = default;
		constexpr PosL4(const pos_int xy_) :x(0), y(0), w(xy_), h(xy_) {};
		constexpr PosL4(const pos_int x_, const pos_int y_) :x(0), y(0), w(x_), h(y_) {};
		constexpr PosL4(const pos_int x_, const pos_int y_, const pos_int l_) :x(x_), y(y_), w(l_), h(l_) {};
		constexpr PosL4(const pos_int x_, const pos_int y_, const pos_int w_, const pos_int h_) :x(x_), y(y_), w(w_), h(h_) {};
		constexpr PosL4(const Pos2&);
		constexpr PosL4(const Pos4&);
		constexpr PosL4(const PosL4&);
		constexpr PosL4(const PosA4&);
		constexpr PosL4(const Pos8&);
		constexpr PosL4(const Pos2F&);
		constexpr PosL4(const Pos4F&);
		constexpr PosL4(const PosL4F&);
		constexpr PosL4(const PosA4F&);
		constexpr PosL4(const Pos8F&);
		//デストラクタ----------
		~PosL4() = default;
		//型変換----------
		const Pos2 convPos2() const;
		const Pos4 convPos4() const;
		const PosL4 convPosL4() const;
		const PosA4 convPosA4() const;
		const Pos8 convPos8() const;
		const Pos2F convPos2F() const;
		const Pos4F convPos4F() const;
		const PosL4F convPosL4F() const;
		const PosA4F convPosA4F() const;
		const Pos8F convPos8F() const;
		//--------------------

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




		const PosL4& operator()(PosL4* const p_) const { *p_ = *this; return *this; }


	};

	//中心位置と大きさを併せ持つ
	struct PosA4
	{
		//メンバ変数----------
		pos_int x{};
		pos_int y{};
		pos_int w{};
		pos_int h{};
		//コンストラクタ----------
		PosA4() = default;
		constexpr PosA4(const pos_int xy_) :x(xy_), y(xy_), w(0), h(0) {};
		constexpr PosA4(const pos_int x_, const pos_int y_) :x(x_), y(y_), w(0), h(0) {};
		constexpr PosA4(const pos_int x_, const pos_int y_, const pos_int l_) :x(x_), y(y_), w(l_), h(l_) {};
		constexpr PosA4(const pos_int x_, const pos_int y_, const pos_int w_, const pos_int h_) :x(x_), y(y_), w(w_), h(h_) {};
		constexpr PosA4(const Pos2&);
		constexpr PosA4(const Pos4&);
		constexpr PosA4(const PosL4&);
		constexpr PosA4(const PosA4&);
		constexpr PosA4(const Pos8&);
		constexpr PosA4(const Pos2F&);
		constexpr PosA4(const Pos4F&);
		constexpr PosA4(const PosL4F&);
		constexpr PosA4(const PosA4F&);
		constexpr PosA4(const Pos8F&);
		//デストラクタ----------
		~PosA4() = default;
		//型変換----------
		const Pos2 convPos2() const;
		const Pos4 convPos4() const;
		const PosL4 convPosL4() const;
		const PosA4 convPosA4() const;
		const Pos8 convPos8() const;
		const Pos2F convPos2F() const;
		const Pos4F convPos4F() const;
		const PosL4F convPosL4F() const;
		const PosA4F convPosA4F() const;
		const Pos8F convPos8F() const;
		//--------------------

		const PosA4& operator=(const Pos2& add_pos);
		const PosA4& operator=(const Pos4& add_pos);
		const PosA4& operator=(const PosL4& add_pos);
		const PosA4& operator=(const Pos8& add_pos);
		const PosA4& operator()(const Pos2& add_pos);
		const PosA4& operator()(const Pos4& add_pos);
		const PosA4& operator()(const PosL4& add_pos);
		const PosA4& operator()(const Pos8& add_pos);
		const PosA4& operator()(const double pos_) { this->w = pos_int(this->w*pos_); this->h = pos_int(this->h*pos_); return *this; }
		const PosA4& operator()(const double pos_x, const double pos_y) { this->w = pos_int(this->w*pos_x); this->h = pos_int(this->h*pos_y); return *this; }
		operator Pos2();
		operator Pos4();
		operator PosL4();
		operator Pos8();
		const PosA4& rand(const Pos2&);
		const PosA4& randPlus(const uint32_t);




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
		//メンバ変数----------
		pos_int x1{};
		pos_int y1{};
		pos_int x2{};
		pos_int y2{};
		pos_int x3{};
		pos_int y3{};
		pos_int x4{};
		pos_int y4{};
		//コンストラクタ----------
		Pos8() = default;
		constexpr Pos8(const pos_int x1_, const pos_int y1_, const pos_int x2_, const pos_int y2_, const pos_int x3_, const pos_int y3_, const pos_int x4_, const pos_int y4_) : x1(x1_), y1(y1_), x2(x2_), y2(y2_), x3(x3_), y3(y3_), x4(x4_), y4(y4_) {}
		constexpr Pos8(const pos_int x1_, const pos_int y1_, const pos_int x2_, const pos_int y2_) : x1(x1_), y1(y1_), x2(x2_), y2(y1_), x3(x1_), y3(y2_), x4(x2_), y4(y2_) {}
		constexpr Pos8(const pos_int x_, const pos_int y_) : x1(0), y1(0), x2(x_), y2(0), x3(0), y3(y_), x4(x_), y4(y_) {}
		constexpr Pos8(const Pos2&);
		constexpr Pos8(const Pos4&);
		constexpr Pos8(const PosL4&);
		constexpr Pos8(const PosA4&);
		constexpr Pos8(const Pos8&);
		constexpr Pos8(const Pos2F&);
		constexpr Pos8(const Pos4F&);
		constexpr Pos8(const PosL4F&);
		constexpr Pos8(const PosA4F&);
		constexpr Pos8(const Pos8F&);
		//デストラクタ----------
		~Pos8() = default;
		//型変換----------
		const Pos2 convPos2() const;
		const Pos4 convPos4() const;
		const PosL4 convPosL4() const;
		const PosA4 convPosA4() const;
		const Pos8 convPos8() const;
		const Pos2F convPos2F() const;
		const Pos4F convPos4F() const;
		const PosL4F convPosL4F() const;
		const PosA4F convPosA4F() const;
		const Pos8F convPos8F() const;
		//--------------------

		const Pos8& operator=(const Pos2& add_pos);
		const Pos8& operator=(const Pos4& add_pos);
		const Pos8& operator=(const PosL4& add_pos);
		const Pos8& operator=(const PosA4& add_pos);
		const Pos8& operator()(const Pos2& add_pos);
		const Pos8& operator()(const Pos4& add_pos);
		const Pos8& operator()(const PosL4& add_pos);
		const Pos8& operator()(const PosA4& add_pos);




		//回転
		Pos8(const Pos4&, const double);
		const Pos8& operator()(const Pos4& p_, const double r_) { *this = Pos8(p_, r_); return *this; };

		//立体回転
		const Pos8 rotation3D(const Pos4&, const double);

		const Pos8& operator()(Pos8* const p_) const { *p_ = *this; return *this; }


	};

	//大きさ(2D)
	struct Pos2F
	{
		//メンバ変数----------
		pos_float x{};
		pos_float y{};
		//コンストラクタ----------
		Pos2F() = default;
		constexpr Pos2F(const pos_float xy_) :x(xy_), y(xy_) {};
		constexpr Pos2F(const pos_float x_, const pos_float y_) :x(x_), y(y_) {};
		constexpr Pos2F(const Pos2F&);
		constexpr Pos2F(const Pos4F&);
		constexpr Pos2F(const PosL4F&);
		constexpr Pos2F(const PosA4F&);
		constexpr Pos2F(const Pos8F&);
		constexpr Pos2F(const Pos2&);
		constexpr Pos2F(const Pos4&);
		constexpr Pos2F(const PosL4&);
		constexpr Pos2F(const PosA4&);
		constexpr Pos2F(const Pos8&);
		//デストラクタ----------
		~Pos2F() = default;
		//型変換----------
		const Pos2 convPos2() const;
		const Pos4 convPos4() const;
		const PosL4 convPosL4() const;
		const PosA4 convPosA4() const;
		const Pos8 convPos8() const;
		const Pos2F convPos2F() const;
		const Pos4F convPos4F() const;
		const PosL4F convPosL4F() const;
		const PosA4F convPosA4F() const;
		const Pos8F convPos8F() const;
		//--------------------

		const Pos2F& operator=(const Pos4F& add_pos);
		const Pos2F& operator=(const PosL4F& add_pos);
		const Pos2F& operator=(const PosA4F& add_pos);
		const Pos2F& operator=(const Pos8F& add_pos);
		const Pos2F& operator()(const Pos4F& add_pos);
		const Pos2F& operator()(const PosL4F& add_pos);
		const Pos2F& operator()(const PosA4F& add_pos);
		const Pos2F& operator()(const Pos8F& add_pos);
		const Pos2F& operator()() { *this = Pos2F(0.0f); return *this; }
		const Pos2F& operator()(const pos_float pos_size) { *this = Pos2F(pos_size); return *this; }
		const Pos2F& operator()(const pos_float pos_x, const pos_float pos_y) { *this = Pos2F(pos_x, pos_y); return *this; }
		const Pos2F& operator()(const double pos_) { this->x = pos_float(this->x*pos_); this->y = pos_float(this->y*pos_); return *this; }
		const Pos2F& operator()(const double pos_x, const double pos_y) { this->x = pos_float(this->x*pos_x); this->y = pos_float(this->y*pos_y); return *this; }
		operator Pos4F();
		operator PosL4F();
		operator PosA4F();
		operator Pos8F();





		const Pos2F& operator()(Pos2F* const p_) const { *p_ = *this; return *this; }
		const Pos2F& operator()(pos_float* const x_, pos_float* const y_) const { *x_ = this->x; *y_ = this->y; return *this; }

		const pos_float plus() const { return (this->x + this->y); }
		const pos_float Hypot() const { return hypot(this->x, this->y); }
		const Pos2F& Hypot(pos_float& f_) const { f_ = pos_float(hypot(this->x, this->y)); return *this; }
		const Pos2F& Hypot(pos_float* f_) const { if (f_ != nullptr)*f_ = pos_float(hypot(this->x, this->y)); return *this; }
		const Pos2F& Hypot(double& f_) const { f_ = double(hypot(this->x, this->y)); return *this; }
		const Pos2F& Hypot(double* f_) const { if (f_ != nullptr)*f_ = double(hypot(this->x, this->y)); return *this; }

		const Pos2F& moveHypot(const float f_) const { return Pos2F(this->Hypot()*sin(f_), -this->Hypot()*cos(f_)); }

		const pos_float minusX() const { return -1 * this->x; }
		const pos_float minusY() const { return -1 * this->y; }


	};

	//長方形の大きさ(左上と右下の位置)
	struct Pos4F
	{
		//メンバ変数----------
		pos_float x1{};
		pos_float y1{};
		pos_float x2{};
		pos_float y2{};
		//コンストラクタ----------
		Pos4F() = default;
		constexpr Pos4F(const pos_float xy_) :x1(0.0f), y1(0.0f), x2(xy_), y2(xy_) {};
		constexpr Pos4F(const pos_float x_, const pos_float y_) :x1(0.0f), y1(0.0f), x2(x_), y2(y_) {};
		constexpr Pos4F(const pos_float x_, const pos_float y_, const pos_float l_) :x1(x_), y1(y_), x2(x_ + l_), y2(y_ + l_) {};
		constexpr Pos4F(const pos_float x1_, const pos_float y1_, const pos_float x2_, const pos_float y2_) :x1(x1_), y1(y1_), x2(x2_), y2(y2_) {};
		constexpr Pos4F(const Pos2F&);
		constexpr Pos4F(const Pos4F&);
		constexpr Pos4F(const PosL4F&);
		constexpr Pos4F(const PosA4F&);
		constexpr Pos4F(const Pos8F&);
		constexpr Pos4F(const Pos2&);
		constexpr Pos4F(const Pos4&);
		constexpr Pos4F(const PosL4&);
		constexpr Pos4F(const PosA4&);
		constexpr Pos4F(const Pos8&);
		//デストラクタ----------
		~Pos4F() = default;
		//型変換----------
		const Pos2 convPos2() const;
		const Pos4 convPos4() const;
		const PosL4 convPosL4() const;
		const PosA4 convPosA4() const;
		const Pos8 convPos8() const;
		const Pos2F convPos2F() const;
		const Pos4F convPos4F() const;
		const PosL4F convPosL4F() const;
		const PosA4F convPosA4F() const;
		const Pos8F convPos8F() const;
		//--------------------

		const Pos4F& operator=(const Pos2F&);
		const Pos4F& operator=(const Pos8F&);
		const Pos4F& operator=(const PosA4F&);
		const Pos4F& operator=(const PosL4F&);
		const Pos4F& operator()(const Pos2F&);
		const Pos4F& operator()(const Pos8F&);
		const Pos4F& operator()(const PosA4F&);
		const Pos4F& operator()(const PosL4F&);
		operator Pos2F();
		operator Pos8F();
		operator PosA4F();
		operator PosL4F();




		const Pos4F& operator()(Pos4F* const p_) const { *p_ = *this; return *this; }


	};



	//長方形の大きさ(位置と長さ)
	struct PosL4F
	{
		//メンバ変数----------
		pos_float x{};
		pos_float y{};
		pos_float w{};
		pos_float h{};
		//コンストラクタ----------
		PosL4F() = default;
		constexpr PosL4F(const pos_float xy_) :x(0.0f), y(0.0f), w(xy_), h(xy_) {};
		constexpr PosL4F(const pos_float x_, const pos_float y_) :x(0.0f), y(0.0f), w(x_), h(y_) {};
		constexpr PosL4F(const pos_float x_, const pos_float y_, const pos_float l_) :x(x_), y(y_), w(l_), h(l_) {};
		constexpr PosL4F(const pos_float x_, const pos_float y_, const pos_float w_, const pos_float h_) :x(x_), y(y_), w(w_), h(h_) {};
		constexpr PosL4F(const Pos2F&);
		constexpr PosL4F(const Pos4F&);
		constexpr PosL4F(const PosL4F&);
		constexpr PosL4F(const PosA4F&);
		constexpr PosL4F(const Pos8F&);
		constexpr PosL4F(const Pos2&);
		constexpr PosL4F(const Pos4&);
		constexpr PosL4F(const PosL4&);
		constexpr PosL4F(const PosA4&);
		constexpr PosL4F(const Pos8&);
		//デストラクタ----------
		~PosL4F() = default;
		//型変換----------
		const Pos2 convPos2() const;
		const Pos4 convPos4() const;
		const PosL4 convPosL4() const;
		const PosA4 convPosA4() const;
		const Pos8 convPos8() const;
		const Pos2F convPos2F() const;
		const Pos4F convPos4F() const;
		const PosL4F convPosL4F() const;
		const PosA4F convPosA4F() const;
		const Pos8F convPos8F() const;
		//--------------------

		const PosL4F& operator=(const Pos2F& add_pos);
		const PosL4F& operator=(const Pos4F& add_pos);
		const PosL4F& operator=(const PosA4F& add_pos);
		const PosL4F& operator=(const Pos8F& add_pos);
		const PosL4F& operator()(const Pos2F& add_pos);
		const PosL4F& operator()(const Pos4F& add_pos);
		const PosL4F& operator()(const PosA4F& add_pos);
		const PosL4F& operator()(const Pos8F& add_pos);
		operator Pos2F();
		operator Pos4F();
		operator PosA4F();
		operator Pos8F();




		const PosL4F& operator()(PosL4F* const p_) const { *p_ = *this; return *this; }


	};

	//中心位置と大きさを併せ持つ
	struct PosA4F
	{
		//メンバ変数----------
		pos_float x{};
		pos_float y{};
		pos_float w{};
		pos_float h{};
		//コンストラクタ----------
		PosA4F() = default;
		constexpr PosA4F(const pos_float xy_) :x(xy_), y(xy_), w(0.0f), h(0.0f) {};
		constexpr PosA4F(const pos_float x_, const pos_float y_) :x(x_), y(y_), w(0.0f), h(0.0f) {};
		constexpr PosA4F(const pos_float x_, const pos_float y_, const pos_float l_) :x(x_), y(y_), w(l_), h(l_) {};
		constexpr PosA4F(const pos_float x_, const pos_float y_, const pos_float w_, const pos_float h_) :x(x_), y(y_), w(w_), h(h_) {};
		constexpr PosA4F(const Pos2F&);
		constexpr PosA4F(const Pos4F&);
		constexpr PosA4F(const PosL4F&);
		constexpr PosA4F(const PosA4F&);
		constexpr PosA4F(const Pos8F&);
		constexpr PosA4F(const Pos2&);
		constexpr PosA4F(const Pos4&);
		constexpr PosA4F(const PosL4&);
		constexpr PosA4F(const PosA4&);
		constexpr PosA4F(const Pos8&);
		//デストラクタ----------
		~PosA4F() = default;
		//型変換----------
		const Pos2 convPos2() const;
		const Pos4 convPos4() const;
		const PosL4 convPosL4() const;
		const PosA4 convPosA4() const;
		const Pos8 convPos8() const;
		const Pos2F convPos2F() const;
		const Pos4F convPos4F() const;
		const PosL4F convPosL4F() const;
		const PosA4F convPosA4F() const;
		const Pos8F convPos8F() const;
		//--------------------

		const PosA4F& operator=(const Pos2F& add_pos);
		const PosA4F& operator=(const Pos4F& add_pos);
		const PosA4F& operator=(const PosL4F& add_pos);
		const PosA4F& operator=(const Pos8F& add_pos);
		const PosA4F& operator()(const Pos2F& add_pos);
		const PosA4F& operator()(const Pos4F& add_pos);
		const PosA4F& operator()(const PosL4F& add_pos);
		const PosA4F& operator()(const Pos8F& add_pos);
		const PosA4F& operator()(const double pos_) { this->w = pos_float(this->w*pos_); this->h = pos_float(this->h*pos_); return *this; }
		const PosA4F& operator()(const double pos_x, const double pos_y) { this->w = pos_float(this->w*pos_x); this->h = pos_float(this->h*pos_y); return *this; }
		operator Pos2F();
		operator Pos4F();
		operator PosL4F();
		operator Pos8F();




		const PosA4F& operator()(PosA4F* const p_) const { *p_ = *this; return *this; }


	};

	//四角形の大きさ
	struct Pos8F
	{
		//メンバ変数----------
		pos_float x1{};
		pos_float y1{};
		pos_float x2{};
		pos_float y2{};
		pos_float x3{};
		pos_float y3{};
		pos_float x4{};
		pos_float y4{};
		//コンストラクタ----------
		Pos8F() = default;
		constexpr Pos8F(const pos_float x1_, const pos_float y1_, const pos_float x2_, const pos_float y2_, const pos_float x3_, const pos_float y3_, const pos_float x4_, const pos_float y4_) : x1(x1_), y1(y1_), x2(x2_), y2(y2_), x3(x3_), y3(y3_), x4(x4_), y4(y4_) {}
		constexpr Pos8F(const pos_float x1_, const pos_float y1_, const pos_float x2_, const pos_float y2_) : x1(x1_), y1(y1_), x2(x2_), y2(y1_), x3(x1_), y3(y2_), x4(x2_), y4(y2_) {}
		constexpr Pos8F(const pos_float x_, const pos_float y_) : x1(0.0f), y1(0.0f), x2(x_), y2(0.0f), x3(0.0f), y3(y_), x4(x_), y4(y_) {}
		constexpr Pos8F(const Pos2F&);
		constexpr Pos8F(const Pos4F&);
		constexpr Pos8F(const PosL4F&);
		constexpr Pos8F(const PosA4F&);
		constexpr Pos8F(const Pos8F&);
		constexpr Pos8F(const Pos2&);
		constexpr Pos8F(const Pos4&);
		constexpr Pos8F(const PosL4&);
		constexpr Pos8F(const PosA4&);
		constexpr Pos8F(const Pos8&);
		//デストラクタ----------
		~Pos8F() = default;
		//型変換----------
		const Pos2 convPos2() const;
		const Pos4 convPos4() const;
		const PosL4 convPosL4() const;
		const PosA4 convPosA4() const;
		const Pos8 convPos8() const;
		const Pos2F convPos2F() const;
		const Pos4F convPos4F() const;
		const PosL4F convPosL4F() const;
		const PosA4F convPosA4F() const;
		const Pos8F convPos8F() const;
		//--------------------

		const Pos8F& operator=(const Pos2F& add_pos);
		const Pos8F& operator=(const Pos4F& add_pos);
		const Pos8F& operator=(const PosL4F& add_pos);
		const Pos8F& operator=(const PosA4F& add_pos);
		const Pos8F& operator()(const Pos2F& add_pos);
		const Pos8F& operator()(const Pos4F& add_pos);
		const Pos8F& operator()(const PosL4F& add_pos);
		const Pos8F& operator()(const PosA4F& add_pos);




		const Pos8F& operator()(Pos8F* const p_) const { *p_ = *this; return *this; }


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
	inline constexpr Pos2::Pos2(const Pos2F& pos_) : x(pos_int(pos_.x)), y(pos_int(pos_.y)) {}
	inline constexpr Pos2::Pos2(const Pos4F& pos_) : x(pos_int(pos_.x1)), y(pos_int(pos_.y1)) {}
	inline constexpr Pos2::Pos2(const PosL4F& pos_) : x(pos_int(pos_.x)), y(pos_int(pos_.y)) {}
	inline constexpr Pos2::Pos2(const PosA4F& pos_) : x(pos_int(pos_.x)), y(pos_int(pos_.y)) {}
	inline constexpr Pos2::Pos2(const Pos8F& pos_) : x(pos_int(pos_.x1)), y(pos_int(pos_.y1)) {}
	//Pos4
	inline constexpr Pos4::Pos4(const Pos2& pos_) : x1(0), y1(0), x2(pos_.x), y2(pos_.y) {}
	inline constexpr Pos4::Pos4(const Pos4& pos_) : x1(pos_.x1), y1(pos_.y1), x2(pos_.x2), y2(pos_.y2) {}
	inline constexpr Pos4::Pos4(const PosL4& pos_) : x1(pos_.x), y1(pos_.y), x2(pos_.x + pos_.w), y2(pos_.y + pos_.h) {}
	inline constexpr Pos4::Pos4(const PosA4& pos_) : x1(pos_.x - (pos_.w / 2)), y1(pos_.y - (pos_.h / 2)), x2(pos_.x + (pos_.w / 2)), y2(pos_.y + (pos_.h / 2)) {}
	inline constexpr Pos4::Pos4(const Pos8& pos_) : x1(pos_.x1), y1(pos_.y1), x2(pos_.x4), y2(pos_.y4) {}
	inline constexpr Pos4::Pos4(const Pos2F& pos_) : x1(pos_int(0)), y1(pos_int(0)), x2(pos_int(pos_.x)), y2(pos_int(pos_.y)) {}
	inline constexpr Pos4::Pos4(const Pos4F& pos_) : x1(pos_int(pos_.x1)), y1(pos_int(pos_.y1)), x2(pos_int(pos_.x2)), y2(pos_int(pos_.y2)) {}
	inline constexpr Pos4::Pos4(const PosL4F& pos_) : x1(pos_int(pos_.x)), y1(pos_int(pos_.y)), x2(pos_int(pos_.x + pos_.w)), y2(pos_int(pos_.y + pos_.h)) {}
	inline constexpr Pos4::Pos4(const PosA4F& pos_) : x1(pos_int(pos_.x - (pos_.w / 2))), y1(pos_int(pos_.y - (pos_.h / 2))), x2(pos_int(pos_.x + (pos_.w / 2))), y2(pos_int(pos_.y + (pos_.h / 2))) {}
	inline constexpr Pos4::Pos4(const Pos8F& pos_) : x1(pos_int(pos_.x1)), y1(pos_int(pos_.y1)), x2(pos_int(pos_.x4)), y2(pos_int(pos_.y4)) {}

	//PosL4
	inline constexpr PosL4::PosL4(const Pos2& pos_) : x(pos_.x), y(pos_.y), w(0), h(0) {}
	inline constexpr PosL4::PosL4(const Pos4& pos_) : x(pos_.x1), y(pos_.y1), w(pos_.x2 - pos_.x1), h(pos_.y2 - pos_.y1) {}
	inline constexpr PosL4::PosL4(const PosL4& pos_) : x(pos_.x), y(pos_.y), w(pos_.w), h(pos_.h) {}
	inline constexpr PosL4::PosL4(const PosA4& pos_) : x(pos_.x - (pos_.w / 2)), y(pos_.y - (pos_.h / 2)), w(pos_.w), h(pos_.h) {}
	inline constexpr PosL4::PosL4(const Pos8& pos_) : x(pos_.x1), y(pos_.y1), w(pos_.x4 - pos_.x1), h(pos_.y4 - pos_.y1) {}
	inline constexpr PosL4::PosL4(const Pos2F& pos_) : x(pos_int(pos_.x)), y(pos_int(pos_.y)), w(pos_int(0)), h(pos_int(0)) {}
	inline constexpr PosL4::PosL4(const Pos4F& pos_) : x(pos_int(pos_.x1)), y(pos_int(pos_.y1)), w(pos_int(pos_.x2 - pos_.x1)), h(pos_int(pos_.y2 - pos_.y1)) {}
	inline constexpr PosL4::PosL4(const PosL4F& pos_) : x(pos_int(pos_.x)), y(pos_int(pos_.y)), w(pos_int(pos_.w)), h(pos_int(pos_.h)) {}
	inline constexpr PosL4::PosL4(const PosA4F& pos_) : x(pos_int(pos_.x - (pos_.w / 2))), y(pos_int(pos_.y - (pos_.h / 2))), w(pos_int(pos_.w)), h(pos_int(pos_.h)) {}
	inline constexpr PosL4::PosL4(const Pos8F& pos_) : x(pos_int(pos_.x1)), y(pos_int(pos_.y1)), w(pos_int(pos_.x4 - pos_.x1)), h(pos_int(pos_.y4 - pos_.y1)) {}

	//PosA4
	inline constexpr PosA4::PosA4(const Pos2& pos_) : x(pos_.x), y(pos_.y), w(0), h(0) {}
	inline constexpr PosA4::PosA4(const Pos4& pos_) : x(pos_.x1 + ((pos_.x2 - pos_.x1) / 2)), y(pos_.y1 + ((pos_.y2 - pos_.y1) / 2)), w(pos_.x2 - pos_.x1), h(pos_.y2 - pos_.y1) {}
	inline constexpr PosA4::PosA4(const PosL4& pos_) : x(pos_.x + (pos_.w / 2)), y(pos_.y + (pos_.h / 2)), w(pos_.w), h(pos_.h) {}
	inline constexpr PosA4::PosA4(const PosA4& pos_) : x(pos_.x), y(pos_.y), w(pos_.w), h(pos_.h) {}
	inline constexpr PosA4::PosA4(const Pos8& pos_) : x(pos_.x1 + ((pos_.x4 - pos_.x1) / 2)), y(pos_.y1 + ((pos_.y4 - pos_.y1) / 2)), w(pos_.x4 - pos_.x1), h(pos_.y4 - pos_.y1) {}
	inline constexpr PosA4::PosA4(const Pos2F& pos_) : x(pos_int(pos_.x)), y(pos_int(pos_.y)), w(pos_int(0)), h(pos_int(0)) {}
	inline constexpr PosA4::PosA4(const Pos4F& pos_) : x(pos_int(pos_.x1 + ((pos_.x2 - pos_.x1) / 2))), y(pos_int(pos_.y1 + ((pos_.y2 - pos_.y1) / 2))), w(pos_int(pos_.x2 - pos_.x1)), h(pos_int(pos_.y2 - pos_.y1)) {}
	inline constexpr PosA4::PosA4(const PosL4F& pos_) : x(pos_int(pos_.x + (pos_.w / 2))), y(pos_int(pos_.y + (pos_.h / 2))), w(pos_int(pos_.w)), h(pos_int(pos_.h)) {}
	inline constexpr PosA4::PosA4(const PosA4F& pos_) : x(pos_int(pos_.x)), y(pos_int(pos_.y)), w(pos_int(pos_.w)), h(pos_int(pos_.h)) {}
	inline constexpr PosA4::PosA4(const Pos8F& pos_) : x(pos_int(pos_.x1 + ((pos_.x4 - pos_.x1) / 2))), y(pos_int(pos_.y1 + ((pos_.y4 - pos_.y1) / 2))), w(pos_int(pos_.x4 - pos_.x1)), h(pos_int(pos_.y4 - pos_.y1)) {}

	//Pos8
	inline constexpr Pos8::Pos8(const Pos2& pos_) : x1(0), y1(0), x4(pos_.x), y4(pos_.y), x2(pos_.x), y2(0), x3(0), y3(pos_.y) {}
	inline constexpr Pos8::Pos8(const Pos4& pos_) : x1(pos_.x1), y1(pos_.y1), x4(pos_.x2), y4(pos_.y2), x2(pos_.x2), y2(pos_.y1), x3(pos_.x1), y3(pos_.y2) {}
	inline constexpr Pos8::Pos8(const PosL4& pos_) : x1(pos_.x), y1(pos_.y), x4(pos_.x + pos_.w), y4(pos_.y + pos_.h), x2(pos_.x + pos_.w), y2(pos_.y), x3(pos_.x), y3(pos_.y + pos_.h) {}
	inline constexpr Pos8::Pos8(const PosA4& pos_) : x1(pos_.x - (pos_.w / 2)), y1(pos_.y - (pos_.h / 2)), x4(pos_.x + (pos_.w / 2)), y4(pos_.y + (pos_.h / 2)), x2(pos_.x + (pos_.w / 2)), y2(pos_.y - (pos_.h / 2)), x3(pos_.x - (pos_.w / 2)), y3(pos_.y + (pos_.h / 2)) {}
	inline constexpr Pos8::Pos8(const Pos8& pos_) : x1(pos_.x1), y1(pos_.y1), x2(pos_.x2), y2(pos_.y2), x3(pos_.x3), y3(pos_.y3), x4(pos_.x4), y4(pos_.y4) {}
	inline constexpr Pos8::Pos8(const Pos2F& pos_) : x1(pos_int(0)), y1(pos_int(0)), x4(pos_int(pos_.x)), y4(pos_int(pos_.y)), x2(pos_int(pos_.x)), y2(pos_int(0)), x3(pos_int(0)), y3(pos_int(pos_.y)) {}
	inline constexpr Pos8::Pos8(const Pos4F& pos_) : x1(pos_int(pos_.x1)), y1(pos_int(pos_.y1)), x4(pos_int(pos_.x2)), y4(pos_int(pos_.y2)), x2(pos_int(pos_.x2)), y2(pos_int(pos_.y1)), x3(pos_int(pos_.x1)), y3(pos_int(pos_.y2)) {}
	inline constexpr Pos8::Pos8(const PosL4F& pos_) : x1(pos_int(pos_.x)), y1(pos_int(pos_.y)), x4(pos_int(pos_.x + pos_.w)), y4(pos_int(pos_.y + pos_.h)), x2(pos_int(pos_.x + pos_.w)), y2(pos_int(pos_.y)), x3(pos_int(pos_.x)), y3(pos_int(pos_.y + pos_.h)) {}
	inline constexpr Pos8::Pos8(const PosA4F& pos_) : x1(pos_int(pos_.x - (pos_.w / 2))), y1(pos_int(pos_.y - (pos_.h / 2))), x4(pos_int(pos_.x + (pos_.w / 2))), y4(pos_int(pos_.y + (pos_.h / 2))), x2(pos_int(pos_.x + (pos_.w / 2))), y2(pos_int(pos_.y - (pos_.h / 2))), x3(pos_int(pos_.x - (pos_.w / 2))), y3(pos_int(pos_.y + (pos_.h / 2))) {}
	inline constexpr Pos8::Pos8(const Pos8F& pos_) : x1(pos_int(pos_.x1)), y1(pos_int(pos_.y1)), x2(pos_int(pos_.x2)), y2(pos_int(pos_.y2)), x3(pos_int(pos_.x3)), y3(pos_int(pos_.y3)), x4(pos_int(pos_.x4)), y4(pos_int(pos_.y4)) {}



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
	//加算代入
	//--------------------------------------------------------

	//Pos2
	inline const Pos2 & Pos2::operator+=(const Pos2 & add_pos) { *this = Pos2(this->x + add_pos.x, this->y + add_pos.y); return *this; }
	inline const Pos2 & Pos2::operator+=(const Pos4 & add_pos) { *this = Pos2(this->x + add_pos.x2, this->y + add_pos.y2); return *this; }
	inline const Pos2 & Pos2::operator+=(const PosL4 & add_pos) { *this = Pos2(this->x + add_pos.x, this->y + add_pos.y); return *this; }
	inline const Pos2 & Pos2::operator+=(const PosA4 & add_pos) { *this = Pos2(this->x + add_pos.x, this->y + add_pos.y); return *this; }
	inline const Pos2& Pos2::operator+=(const Pos8& add_pos) { *this = Pos2(this->x + add_pos.x4, this->y + add_pos.y4); return *this; }

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
		const pos_int size_y = pos_int(fabs((p_.y2 - p_.y1) / 2.0));
		const pos_int size_x = pos_int(fabs((p_.x2 - p_.x1) / 2.0));
		//中心位置からの半径
		const double size_r = sqrt(size_y * size_y + size_x * size_x);
		//位置の角度
		const double pos_r = r_ + atan2(size_y, size_x);

		//中心位置
		const pos_int pos_x = size_x + p_.x1;
		const pos_int pos_y = size_y + p_.y1;

		this->x1 = pos_x + pos_int(round(size_r*cos(pos_r + pos_pi)));
		this->y1 = pos_y + pos_int(round(size_r*sin(pos_r + pos_pi)));
		this->x2 = pos_x + pos_int(round(size_r*cos(-pos_r)));
		this->y2 = pos_y + pos_int(round(size_r*sin(-pos_r)));
		this->x3 = pos_x + pos_int(round(size_r*cos(-pos_r + pos_pi)));
		this->y3 = pos_y + pos_int(round(size_r*sin(-pos_r + pos_pi)));
		this->x4 = pos_x + pos_int(round(size_r*cos(pos_r)));
		this->y4 = pos_y + pos_int(round(size_r*sin(pos_r)));
		return *this;
	}




	//-------------------------------------------------------------------

	inline constexpr Pos4::Pos4(const Pos4F& pos_, const Pos2& window_pos_) :x1(pos_int(pos_.x1*window_pos_.x)), y1(pos_int(pos_.y1*window_pos_.y)), x2(pos_int(pos_.x2*window_pos_.x)), y2(pos_int(pos_.y2*window_pos_.y)) {}

	inline const Pos4& Pos4::operator()(const Pos4F& pos_, const Pos2& window_pos_)
	{
		*this = Pos4(pos_, window_pos_);
		return *this;
	}


	//--------------------------------------------------------
	//コンストラクタ
	//--------------------------------------------------------

	//Pos2F
	inline constexpr Pos2F::Pos2F(const Pos2F& pos_) :x(pos_.x), y(pos_.y) {}
	inline constexpr Pos2F::Pos2F(const Pos4F& pos_) : x(pos_.x1), y(pos_.y1) {}
	inline constexpr Pos2F::Pos2F(const PosL4F& pos_) : x(pos_.x), y(pos_.y) {}
	inline constexpr Pos2F::Pos2F(const PosA4F& pos_) : x(pos_.x), y(pos_.y) {}
	inline constexpr Pos2F::Pos2F(const Pos8F& pos_) : x(pos_.x1), y(pos_.y1) {}
	inline constexpr Pos2F::Pos2F(const Pos2& pos_) : x(pos_float(pos_.x)), y(pos_float(pos_.y)) {}
	inline constexpr Pos2F::Pos2F(const Pos4& pos_) : x(pos_float(pos_.x1)), y(pos_float(pos_.y1)) {}
	inline constexpr Pos2F::Pos2F(const PosL4& pos_) : x(pos_float(pos_.x)), y(pos_float(pos_.y)) {}
	inline constexpr Pos2F::Pos2F(const PosA4& pos_) : x(pos_float(pos_.x)), y(pos_float(pos_.y)) {}
	inline constexpr Pos2F::Pos2F(const Pos8& pos_) : x(pos_float(pos_.x1)), y(pos_float(pos_.y1)) {}

	//Pos4F
	inline constexpr Pos4F::Pos4F(const Pos2F& pos_) : x1(0.0f), y1(0.0f), x2(pos_.x), y2(pos_.y) {}
	inline constexpr Pos4F::Pos4F(const Pos4F& pos_) : x1(pos_.x1), y1(pos_.y1), x2(pos_.x2), y2(pos_.y2) {}
	inline constexpr Pos4F::Pos4F(const PosL4F& pos_) : x1(pos_.x), y1(pos_.y), x2(pos_.x + pos_.w), y2(pos_.y + pos_.h) {}
	inline constexpr Pos4F::Pos4F(const PosA4F& pos_) : x1(pos_.x - (pos_.w / 2)), y1(pos_.y - (pos_.h / 2)), x2(pos_.x + (pos_.w / 2)), y2(pos_.y + (pos_.h / 2)) {}
	inline constexpr Pos4F::Pos4F(const Pos8F& pos_) : x1(pos_.x1), y1(pos_.y1), x2(pos_.x4), y2(pos_.y4) {}
	inline constexpr Pos4F::Pos4F(const Pos2& pos_) : x1(pos_float(0)), y1(pos_float(0)), x2(pos_float(pos_.x)), y2(pos_float(pos_.y)) {}
	inline constexpr Pos4F::Pos4F(const Pos4& pos_) : x1(pos_float(pos_.x1)), y1(pos_float(pos_.y1)), x2(pos_float(pos_.x2)), y2(pos_float(pos_.y2)) {}
	inline constexpr Pos4F::Pos4F(const PosL4& pos_) : x1(pos_float(pos_.x)), y1(pos_float(pos_.y)), x2(pos_float(pos_.x + pos_.w)), y2(pos_float(pos_.y + pos_.h)) {}
	inline constexpr Pos4F::Pos4F(const PosA4& pos_) : x1(pos_float(pos_.x - (pos_.w / 2))), y1(pos_float(pos_.y - (pos_.h / 2))), x2(pos_float(pos_.x + (pos_.w / 2))), y2(pos_float(pos_.y + (pos_.h / 2))) {}
	inline constexpr Pos4F::Pos4F(const Pos8& pos_) : x1(pos_float(pos_.x1)), y1(pos_float(pos_.y1)), x2(pos_float(pos_.x4)), y2(pos_float(pos_.y4)) {}

	//PosL4F
	inline constexpr PosL4F::PosL4F(const Pos2F& pos_) : x(pos_.x), y(pos_.y), w(0.0f), h(0.0f) {}
	inline constexpr PosL4F::PosL4F(const Pos4F& pos_) : x(pos_.x1), y(pos_.y1), w(pos_.x2 - pos_.x1), h(pos_.y2 - pos_.y1) {}
	inline constexpr PosL4F::PosL4F(const PosL4F& pos_) : x(pos_.x), y(pos_.y), w(pos_.w), h(pos_.h) {}
	inline constexpr PosL4F::PosL4F(const PosA4F& pos_) : x(pos_.x - (pos_.w / 2)), y(pos_.y - (pos_.h / 2)), w(pos_.w), h(pos_.h) {}
	inline constexpr PosL4F::PosL4F(const Pos8F& pos_) : x(pos_.x1), y(pos_.y1), w(pos_.x4 - pos_.x1), h(pos_.y4 - pos_.y1) {}
	inline constexpr PosL4F::PosL4F(const Pos2& pos_) : x(pos_float(pos_.x)), y(pos_float(pos_.y)), w(pos_float(0)), h(pos_float(0)) {}
	inline constexpr PosL4F::PosL4F(const Pos4& pos_) : x(pos_float(pos_.x1)), y(pos_float(pos_.y1)), w(pos_float(pos_.x2 - pos_.x1)), h(pos_float(pos_.y2 - pos_.y1)) {}
	inline constexpr PosL4F::PosL4F(const PosL4& pos_) : x(pos_float(pos_.x)), y(pos_float(pos_.y)), w(pos_float(pos_.w)), h(pos_float(pos_.h)) {}
	inline constexpr PosL4F::PosL4F(const PosA4& pos_) : x(pos_float(pos_.x - (pos_.w / 2))), y(pos_float(pos_.y - (pos_.h / 2))), w(pos_float(pos_.w)), h(pos_float(pos_.h)) {}
	inline constexpr PosL4F::PosL4F(const Pos8& pos_) : x(pos_float(pos_.x1)), y(pos_float(pos_.y1)), w(pos_float(pos_.x4 - pos_.x1)), h(pos_float(pos_.y4 - pos_.y1)) {}

	//PosA4F
	inline constexpr PosA4F::PosA4F(const Pos2F& pos_) : x(pos_.x), y(pos_.y), w(0.0f), h(0.0f) {}
	inline constexpr PosA4F::PosA4F(const Pos4F& pos_) : x(pos_.x1 + ((pos_.x2 - pos_.x1) / 2)), y(pos_.y1 + ((pos_.y2 - pos_.y1) / 2)), w(pos_.x2 - pos_.x1), h(pos_.y2 - pos_.y1) {}
	inline constexpr PosA4F::PosA4F(const PosL4F& pos_) : x(pos_.x + (pos_.w / 2)), y(pos_.y + (pos_.h / 2)), w(pos_.w), h(pos_.h) {}
	inline constexpr PosA4F::PosA4F(const PosA4F& pos_) : x(pos_.x), y(pos_.y), w(pos_.w), h(pos_.h) {}
	inline constexpr PosA4F::PosA4F(const Pos8F& pos_) : x(pos_.x1 + ((pos_.x4 - pos_.x1) / 2)), y(pos_.y1 + ((pos_.y4 - pos_.y1) / 2)), w(pos_.x4 - pos_.x1), h(pos_.y4 - pos_.y1) {}
	inline constexpr PosA4F::PosA4F(const Pos2& pos_) : x(pos_float(pos_.x)), y(pos_float(pos_.y)), w(pos_float(0)), h(pos_float(0)) {}
	inline constexpr PosA4F::PosA4F(const Pos4& pos_) : x(pos_float(pos_.x1 + ((pos_.x2 - pos_.x1) / 2))), y(pos_float(pos_.y1 + ((pos_.y2 - pos_.y1) / 2))), w(pos_float(pos_.x2 - pos_.x1)), h(pos_float(pos_.y2 - pos_.y1)) {}
	inline constexpr PosA4F::PosA4F(const PosL4& pos_) : x(pos_float(pos_.x + (pos_.w / 2))), y(pos_float(pos_.y + (pos_.h / 2))), w(pos_float(pos_.w)), h(pos_float(pos_.h)) {}
	inline constexpr PosA4F::PosA4F(const PosA4& pos_) : x(pos_float(pos_.x)), y(pos_float(pos_.y)), w(pos_float(pos_.w)), h(pos_float(pos_.h)) {}
	inline constexpr PosA4F::PosA4F(const Pos8& pos_) : x(pos_float(pos_.x1 + ((pos_.x4 - pos_.x1) / 2))), y(pos_float(pos_.y1 + ((pos_.y4 - pos_.y1) / 2))), w(pos_float(pos_.x4 - pos_.x1)), h(pos_float(pos_.y4 - pos_.y1)) {}

	//Pos8F
	inline constexpr Pos8F::Pos8F(const Pos2F& pos_) : x1(0.0f), y1(0.0f), x4(pos_.x), y4(pos_.y), x2(pos_.x), y2(0.0f), x3(0.0f), y3(pos_.y) {}
	inline constexpr Pos8F::Pos8F(const Pos4F& pos_) : x1(pos_.x1), y1(pos_.y1), x4(pos_.x2), y4(pos_.y2), x2(pos_.x2), y2(pos_.y1), x3(pos_.x1), y3(pos_.y2) {}
	inline constexpr Pos8F::Pos8F(const PosL4F& pos_) : x1(pos_.x), y1(pos_.y), x4(pos_.x + pos_.w), y4(pos_.y + pos_.h), x2(pos_.x + pos_.w), y2(pos_.y), x3(pos_.x), y3(pos_.y + pos_.h) {}
	inline constexpr Pos8F::Pos8F(const PosA4F& pos_) : x1(pos_.x - (pos_.w / 2)), y1(pos_.y - (pos_.h / 2)), x4(pos_.x + (pos_.w / 2)), y4(pos_.y + (pos_.h / 2)), x2(pos_.x + (pos_.w / 2)), y2(pos_.y - (pos_.h / 2)), x3(pos_.x - (pos_.w / 2)), y3(pos_.y + (pos_.h / 2)) {}
	inline constexpr Pos8F::Pos8F(const Pos8F& pos_) : x1(pos_.x1), y1(pos_.y1), x2(pos_.x2), y2(pos_.y2), x3(pos_.x3), y3(pos_.y3), x4(pos_.x4), y4(pos_.y4) {}
	inline constexpr Pos8F::Pos8F(const Pos2& pos_) : x1(pos_float(0)), y1(pos_float(0)), x4(pos_float(pos_.x)), y4(pos_float(pos_.y)), x2(pos_float(pos_.x)), y2(pos_float(0)), x3(pos_float(0)), y3(pos_float(pos_.y)) {}
	inline constexpr Pos8F::Pos8F(const Pos4& pos_) : x1(pos_float(pos_.x1)), y1(pos_float(pos_.y1)), x4(pos_float(pos_.x2)), y4(pos_float(pos_.y2)), x2(pos_float(pos_.x2)), y2(pos_float(pos_.y1)), x3(pos_float(pos_.x1)), y3(pos_float(pos_.y2)) {}
	inline constexpr Pos8F::Pos8F(const PosL4& pos_) : x1(pos_float(pos_.x)), y1(pos_float(pos_.y)), x4(pos_float(pos_.x + pos_.w)), y4(pos_float(pos_.y + pos_.h)), x2(pos_float(pos_.x + pos_.w)), y2(pos_float(pos_.y)), x3(pos_float(pos_.x)), y3(pos_float(pos_.y + pos_.h)) {}
	inline constexpr Pos8F::Pos8F(const PosA4& pos_) : x1(pos_float(pos_.x - (pos_.w / 2))), y1(pos_float(pos_.y - (pos_.h / 2))), x4(pos_float(pos_.x + (pos_.w / 2))), y4(pos_float(pos_.y + (pos_.h / 2))), x2(pos_float(pos_.x + (pos_.w / 2))), y2(pos_float(pos_.y - (pos_.h / 2))), x3(pos_float(pos_.x - (pos_.w / 2))), y3(pos_float(pos_.y + (pos_.h / 2))) {}
	inline constexpr Pos8F::Pos8F(const Pos8& pos_) : x1(pos_float(pos_.x1)), y1(pos_float(pos_.y1)), x2(pos_float(pos_.x2)), y2(pos_float(pos_.y2)), x3(pos_float(pos_.x3)), y3(pos_float(pos_.y3)), x4(pos_float(pos_.x4)), y4(pos_float(pos_.y4)) {}



	//--------------------------------------------------------
	//キャスト
	//--------------------------------------------------------

	//Pos2F
	inline Pos2F::operator Pos4F() { return Pos4F(*this); }
	inline Pos2F::operator PosL4F() { return PosL4F(*this); }
	inline Pos2F::operator PosA4F() { return PosA4F(*this); }
	inline Pos2F::operator Pos8F() { return Pos8F(*this); }
	//Pos4F
	inline Pos4F::operator Pos2F() { return Pos2F(*this); }
	inline Pos4F::operator PosL4F() { return PosL4F(*this); }
	inline Pos4F::operator PosA4F() { return PosA4F(*this); }
	inline Pos4F::operator Pos8F() { return Pos8F(*this); }
	//PosL4F
	inline PosL4F::operator Pos2F() { return Pos2F(*this); }
	inline PosL4F::operator Pos4F() { return Pos4F(*this); }
	inline PosL4F::operator PosA4F() { return PosA4F(*this); }
	inline PosL4F::operator Pos8F() { return Pos8F(*this); }
	//PosA4F
	inline PosA4F::operator Pos2F() { return Pos2F(*this); }
	inline PosA4F::operator Pos4F() { return Pos4F(*this); }
	inline PosA4F::operator PosL4F() { return PosL4F(*this); }
	inline PosA4F::operator Pos8F() { return Pos8F(*this); }



	//--------------------------------------------------------
	//代入
	//--------------------------------------------------------

	//Pos2F
	inline const Pos2F & Pos2F::operator=(const Pos4F & add_pos) { *this = Pos2F(add_pos); return *this; }
	inline const Pos2F & Pos2F::operator=(const PosL4F & add_pos) { *this = Pos2F(add_pos); return *this; }
	inline const Pos2F & Pos2F::operator=(const PosA4F & add_pos) { *this = Pos2F(add_pos); return *this; }
	inline const Pos2F& Pos2F::operator=(const Pos8F& add_pos) { *this = Pos2F(add_pos); return *this; }
	//Pos4F
	inline const Pos4F& Pos4F::operator=(const Pos2F& add_pos) { *this = Pos4F(add_pos); return *this; }
	inline const Pos4F& Pos4F::operator=(const PosL4F& add_pos) { *this = Pos4F(add_pos); return *this; }
	inline const Pos4F& Pos4F::operator=(const PosA4F& add_pos) { *this = Pos4F(add_pos); return *this; }
	inline const Pos4F& Pos4F::operator=(const Pos8F& add_pos) { *this = Pos4F(add_pos); return *this; }
	//PosL4F
	inline const PosL4F & PosL4F::operator=(const Pos2F & add_pos) { *this = PosL4F(add_pos); return *this; }
	inline const PosL4F& PosL4F::operator=(const Pos4F& add_pos) { *this = PosL4F(add_pos); return *this; }
	inline const PosL4F & PosL4F::operator=(const PosA4F & add_pos) { *this = PosL4F(add_pos); return *this; }
	inline const PosL4F & PosL4F::operator=(const Pos8F & add_pos) { *this = PosL4F(add_pos); return *this; }
	//PosA4F
	inline const PosA4F& PosA4F::operator=(const Pos2F& add_pos) { *this = PosA4F(add_pos); return *this; }
	inline const PosA4F& PosA4F::operator=(const Pos4F& add_pos) { *this = PosA4F(add_pos); return *this; }
	inline const PosA4F& PosA4F::operator=(const PosL4F& add_pos) { *this = PosA4F(add_pos); return *this; }
	inline const PosA4F& PosA4F::operator=(const Pos8F& add_pos) { *this = PosA4F(add_pos); return *this; }

	inline const Pos8F& Pos8F::operator=(const Pos4F& add_pos) { *this = Pos8F(add_pos); return *this; }
	inline const Pos8F& Pos8F::operator=(const PosL4F& add_pos) { *this = Pos8F(add_pos); return *this; }
	inline const Pos8F& Pos8F::operator=(const PosA4F& add_pos) { *this = Pos8F(add_pos); return *this; }
	inline const Pos8F& Pos8F::operator=(const Pos2F& add_pos) { *this = Pos8F(add_pos); return *this; }



	//--------------------------------------------------------
	//括弧代入
	//--------------------------------------------------------

	//Pos2F
	inline const Pos2F & Pos2F::operator()(const Pos4F & add_pos) { *this = Pos2F(add_pos); return *this; }
	inline const Pos2F & Pos2F::operator()(const PosL4F & add_pos) { *this = Pos2F(add_pos); return *this; }
	inline const Pos2F & Pos2F::operator()(const PosA4F & add_pos) { *this = Pos2F(add_pos); return *this; }
	inline const Pos2F& Pos2F::operator()(const Pos8F& add_pos) { *this = Pos2F(add_pos); return *this; }
	//Pos4F
	inline const Pos4F& Pos4F::operator()(const Pos2F& add_pos) { *this = Pos4F(add_pos); return *this; }
	inline const Pos4F& Pos4F::operator()(const PosL4F& add_pos) { *this = Pos4F(add_pos); return *this; }
	inline const Pos4F& Pos4F::operator()(const PosA4F& add_pos) { *this = Pos4F(add_pos); return *this; }
	inline const Pos4F& Pos4F::operator()(const Pos8F& add_pos) { *this = Pos4F(add_pos); return *this; }
	//PosL4F
	inline const PosL4F & PosL4F::operator()(const Pos2F & add_pos) { *this = PosL4F(add_pos); return *this; }
	inline const PosL4F& PosL4F::operator()(const Pos4F& add_pos) { *this = PosL4F(add_pos); return *this; }
	inline const PosL4F & PosL4F::operator()(const PosA4F & add_pos) { *this = PosL4F(add_pos); return *this; }
	inline const PosL4F & PosL4F::operator()(const Pos8F & add_pos) { *this = PosL4F(add_pos); return *this; }
	//PosA4F
	inline const PosA4F& PosA4F::operator()(const Pos2F& add_pos) { *this = PosA4F(add_pos); return *this; }
	inline const PosA4F& PosA4F::operator()(const Pos4F& add_pos) { *this = PosA4F(add_pos); return *this; }
	inline const PosA4F& PosA4F::operator()(const PosL4F& add_pos) { *this = PosA4F(add_pos); return *this; }
	inline const PosA4F& PosA4F::operator()(const Pos8F& add_pos) { *this = PosA4F(add_pos); return *this; }

	inline const Pos8F& Pos8F::operator()(const Pos4F& add_pos) { *this = Pos8F(add_pos); return *this; }
	inline const Pos8F& Pos8F::operator()(const PosL4F& add_pos) { *this = Pos8F(add_pos); return *this; }
	inline const Pos8F& Pos8F::operator()(const PosA4F& add_pos) { *this = Pos8F(add_pos); return *this; }
	inline const Pos8F& Pos8F::operator()(const Pos2F& add_pos) { *this = Pos8F(add_pos); return *this; }


	//--------------------------------------------------------
	//型変換
	//--------------------------------------------------------

	//Pos2
	inline const Pos2 Pos2::convPos2() const { return *this; }
	inline const Pos4 Pos2::convPos4() const { return *this; }
	inline const PosL4 Pos2::convPosL4() const { return *this; }
	inline const PosA4 Pos2::convPosA4() const { return *this; }
	inline const Pos8 Pos2::convPos8() const { return *this; }
	inline const Pos2F Pos2::convPos2F() const { return *this; }
	inline const Pos4F Pos2::convPos4F() const { return *this; }
	inline const PosL4F Pos2::convPosL4F() const { return *this; }
	inline const PosA4F Pos2::convPosA4F() const { return *this; }
	inline const Pos8F Pos2::convPos8F() const { return *this; }
	//Pos4
	inline const Pos2 Pos4::convPos2() const { return *this; }
	inline const Pos4 Pos4::convPos4() const { return *this; }
	inline const PosL4 Pos4::convPosL4() const { return *this; }
	inline const PosA4 Pos4::convPosA4() const { return *this; }
	inline const Pos8 Pos4::convPos8() const { return *this; }
	inline const Pos2F Pos4::convPos2F() const { return *this; }
	inline const Pos4F Pos4::convPos4F() const { return *this; }
	inline const PosL4F Pos4::convPosL4F() const { return *this; }
	inline const PosA4F Pos4::convPosA4F() const { return *this; }
	inline const Pos8F Pos4::convPos8F() const { return *this; }
	//PosL4
	inline const Pos2 PosL4::convPos2() const { return *this; }
	inline const Pos4 PosL4::convPos4() const { return *this; }
	inline const PosL4 PosL4::convPosL4() const { return *this; }
	inline const PosA4 PosL4::convPosA4() const { return *this; }
	inline const Pos8 PosL4::convPos8() const { return *this; }
	inline const Pos2F PosL4::convPos2F() const { return *this; }
	inline const Pos4F PosL4::convPos4F() const { return *this; }
	inline const PosL4F PosL4::convPosL4F() const { return *this; }
	inline const PosA4F PosL4::convPosA4F() const { return *this; }
	inline const Pos8F PosL4::convPos8F() const { return *this; }
	//PosA4
	inline const Pos2 PosA4::convPos2() const { return *this; }
	inline const Pos4 PosA4::convPos4() const { return *this; }
	inline const PosL4 PosA4::convPosL4() const { return *this; }
	inline const PosA4 PosA4::convPosA4() const { return *this; }
	inline const Pos8 PosA4::convPos8() const { return *this; }
	inline const Pos2F PosA4::convPos2F() const { return *this; }
	inline const Pos4F PosA4::convPos4F() const { return *this; }
	inline const PosL4F PosA4::convPosL4F() const { return *this; }
	inline const PosA4F PosA4::convPosA4F() const { return *this; }
	inline const Pos8F PosA4::convPos8F() const { return *this; }
	//Pos8
	inline const Pos2 Pos8::convPos2() const { return *this; }
	inline const Pos4 Pos8::convPos4() const { return *this; }
	inline const PosL4 Pos8::convPosL4() const { return *this; }
	inline const PosA4 Pos8::convPosA4() const { return *this; }
	inline const Pos8 Pos8::convPos8() const { return *this; }
	inline const Pos2F Pos8::convPos2F() const { return *this; }
	inline const Pos4F Pos8::convPos4F() const { return *this; }
	inline const PosL4F Pos8::convPosL4F() const { return *this; }
	inline const PosA4F Pos8::convPosA4F() const { return *this; }
	inline const Pos8F Pos8::convPos8F() const { return *this; }
	//Pos2F
	inline const Pos2 Pos2F::convPos2() const { return *this; }
	inline const Pos4 Pos2F::convPos4() const { return *this; }
	inline const PosL4 Pos2F::convPosL4() const { return *this; }
	inline const PosA4 Pos2F::convPosA4() const { return *this; }
	inline const Pos8 Pos2F::convPos8() const { return *this; }
	inline const Pos2F Pos2F::convPos2F() const { return *this; }
	inline const Pos4F Pos2F::convPos4F() const { return *this; }
	inline const PosL4F Pos2F::convPosL4F() const { return *this; }
	inline const PosA4F Pos2F::convPosA4F() const { return *this; }
	inline const Pos8F Pos2F::convPos8F() const { return *this; }
	//Pos4F
	inline const Pos2 Pos4F::convPos2() const { return *this; }
	inline const Pos4 Pos4F::convPos4() const { return *this; }
	inline const PosL4 Pos4F::convPosL4() const { return *this; }
	inline const PosA4 Pos4F::convPosA4() const { return *this; }
	inline const Pos8 Pos4F::convPos8() const { return *this; }
	inline const Pos2F Pos4F::convPos2F() const { return *this; }
	inline const Pos4F Pos4F::convPos4F() const { return *this; }
	inline const PosL4F Pos4F::convPosL4F() const { return *this; }
	inline const PosA4F Pos4F::convPosA4F() const { return *this; }
	inline const Pos8F Pos4F::convPos8F() const { return *this; }
	//PosL4F
	inline const Pos2 PosL4F::convPos2() const { return *this; }
	inline const Pos4 PosL4F::convPos4() const { return *this; }
	inline const PosL4 PosL4F::convPosL4() const { return *this; }
	inline const PosA4 PosL4F::convPosA4() const { return *this; }
	inline const Pos8 PosL4F::convPos8() const { return *this; }
	inline const Pos2F PosL4F::convPos2F() const { return *this; }
	inline const Pos4F PosL4F::convPos4F() const { return *this; }
	inline const PosL4F PosL4F::convPosL4F() const { return *this; }
	inline const PosA4F PosL4F::convPosA4F() const { return *this; }
	inline const Pos8F PosL4F::convPos8F() const { return *this; }
	//PosA4F
	inline const Pos2 PosA4F::convPos2() const { return *this; }
	inline const Pos4 PosA4F::convPos4() const { return *this; }
	inline const PosL4 PosA4F::convPosL4() const { return *this; }
	inline const PosA4 PosA4F::convPosA4() const { return *this; }
	inline const Pos8 PosA4F::convPos8() const { return *this; }
	inline const Pos2F PosA4F::convPos2F() const { return *this; }
	inline const Pos4F PosA4F::convPos4F() const { return *this; }
	inline const PosL4F PosA4F::convPosL4F() const { return *this; }
	inline const PosA4F PosA4F::convPosA4F() const { return *this; }
	inline const Pos8F PosA4F::convPos8F() const { return *this; }
	//Pos8F
	inline const Pos2 Pos8F::convPos2() const { return *this; }
	inline const Pos4 Pos8F::convPos4() const { return *this; }
	inline const PosL4 Pos8F::convPosL4() const { return *this; }
	inline const PosA4 Pos8F::convPosA4() const { return *this; }
	inline const Pos8 Pos8F::convPos8() const { return *this; }
	inline const Pos2F Pos8F::convPos2F() const { return *this; }
	inline const Pos4F Pos8F::convPos4F() const { return *this; }
	inline const PosL4F Pos8F::convPosL4F() const { return *this; }
	inline const PosA4F Pos8F::convPosA4F() const { return *this; }
	inline const Pos8F Pos8F::convPos8F() const { return *this; }


	//--------------------------------------------------------
	//その他、位置関連の関数
	//--------------------------------------------------------
	inline void asRand(Pos2& p_) { p_.x = asRand(); p_.y = asRand(); }
	inline void asRand(Pos2F& p_) { p_.x = pos_float(asRand()); p_.y = pos_float(asRand()); }
	inline void asRand(Pos4& p_) { p_.x1 = asRand(); p_.y1 = asRand(); p_.x2 = asRand(); p_.y2 = asRand(); }
	inline void asRand(Pos4F& p_) { p_.x1 = pos_float(asRand()); p_.y1 = pos_float(asRand()); p_.x2 = pos_float(asRand()); p_.y2 = pos_float(asRand()); }
	inline void asRand(PosL4& p_) { p_.x = asRand(); p_.y = asRand(); p_.w = asRand(); p_.h = asRand(); }
	inline void asRand(PosL4F& p_) { p_.x = pos_float(asRand()); p_.y = pos_float(asRand()); p_.w = pos_float(asRand()); p_.h = pos_float(asRand()); }
	inline void asRand(PosA4& p_) { p_.x = asRand(); p_.y = asRand(); p_.w = asRand(); p_.h = asRand(); }
	inline void asRand(PosA4F& p_) { p_.x = pos_float(asRand()); p_.y = pos_float(asRand()); p_.w = pos_float(asRand()); p_.h = pos_float(asRand()); }
	inline void asRand(Pos8& p_) { p_.x1 = asRand(); p_.y1 = asRand(); p_.x2 = asRand(); p_.y2 = asRand(); p_.x3 = asRand(); p_.y3 = asRand(); p_.x4 = asRand(); p_.y4 = asRand(); }
	inline void asRand(Pos8F& p_) { p_.x1 = pos_float(asRand()); p_.y1 = pos_float(asRand()); p_.x2 = pos_float(asRand()); p_.y2 = pos_float(asRand()); p_.x3 = pos_float(asRand()); p_.y3 = pos_float(asRand()); p_.x4 = pos_float(asRand()); p_.y4 = pos_float(asRand()); }

	inline void asRand(Pos2* const array_, const size_t s_) { for (size_t i = 0; i < s_; ++i) asRand(array_[i]); }
	inline void asRand(std::vector<Pos2>& array_) { const size_t s = array_.size(); for (size_t i = 0; i < s; ++i) asRand(array_[i]); }
	inline void asRand(Pos2F* const array_, const size_t s_) { for (size_t i = 0; i < s_; ++i) asRand(array_[i]); }
	inline void asRand(std::vector<Pos2F>& array_) { const size_t s = array_.size(); for (size_t i = 0; i < s; ++i) asRand(array_[i]); }
	inline void asRand(Pos4* const array_, const size_t s_) { for (size_t i = 0; i < s_; ++i) asRand(array_[i]); }
	inline void asRand(std::vector<Pos4>& array_) { const size_t s = array_.size(); for (size_t i = 0; i < s; ++i) asRand(array_[i]); }
	inline void asRand(Pos4F* const array_, const size_t s_) { for (size_t i = 0; i < s_; ++i) asRand(array_[i]); }
	inline void asRand(std::vector<Pos4F>& array_) { const size_t s = array_.size(); for (size_t i = 0; i < s; ++i) asRand(array_[i]); }
	inline void asRand(PosL4* const array_, const size_t s_) { for (size_t i = 0; i < s_; ++i) asRand(array_[i]); }
	inline void asRand(std::vector<PosL4>& array_) { const size_t s = array_.size(); for (size_t i = 0; i < s; ++i) asRand(array_[i]); }
	inline void asRand(PosL4F* const array_, const size_t s_) { for (size_t i = 0; i < s_; ++i) asRand(array_[i]); }
	inline void asRand(std::vector<PosL4F>& array_) { const size_t s = array_.size(); for (size_t i = 0; i < s; ++i) asRand(array_[i]); }
	inline void asRand(PosA4* const array_, const size_t s_) { for (size_t i = 0; i < s_; ++i) asRand(array_[i]); }
	inline void asRand(std::vector<PosA4>& array_) { const size_t s = array_.size(); for (size_t i = 0; i < s; ++i) asRand(array_[i]); }
	inline void asRand(PosA4F* const array_, const size_t s_) { for (size_t i = 0; i < s_; ++i) asRand(array_[i]); }
	inline void asRand(std::vector<PosA4F>& array_) { const size_t s = array_.size(); for (size_t i = 0; i < s; ++i) asRand(array_[i]); }
	inline void asRand(Pos8* const array_, const size_t s_) { for (size_t i = 0; i < s_; ++i) asRand(array_[i]); }
	inline void asRand(std::vector<Pos8>& array_) { const size_t s = array_.size(); for (size_t i = 0; i < s; ++i) asRand(array_[i]); }
	inline void asRand(Pos8F* const array_, const size_t s_) { for (size_t i = 0; i < s_; ++i) asRand(array_[i]); }
	inline void asRand(std::vector<Pos8F>& array_) { const size_t s = array_.size(); for (size_t i = 0; i < s; ++i) asRand(array_[i]); }



}