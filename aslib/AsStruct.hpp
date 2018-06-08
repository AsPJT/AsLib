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
		Pos2& operator=(const Pos4& add_pos);
		Pos2& operator=(const PosL4& add_pos);
		Pos2& operator=(const PosA4& add_pos);
		Pos2& operator=(const Pos8& add_pos);
		Pos2& operator()(const int32_t pos_size = 0);
		Pos2& operator()(const int32_t pos_x, const int32_t pos_y);
		operator Pos4();
		operator PosL4();
		operator PosA4();
		operator Pos8();
		Pos2& rand(const Pos2&);
		Pos2& randPlus(const uint32_t);

		int32_t x = 0;
		int32_t y = 0;
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		operator s3d::Point()
		{
			s3d::Point p_;
			p_.x = this->x;
			p_.x = this->y;
			return p_;
		}
		Pos2& operator=(const s3d::Point& add_pos)
		{
			Pos2 pos;
			pos.x = add_pos.x;
			pos.y = add_pos.y;
			return pos;
		}
		operator s3d::Rect()
		{
			const s3d::Rect rect(this->x, this->y);
			return rect;
		}
#endif
	};

	inline Pos2 & Pos2::rand(const Pos2& add_pos)
	{
		this->x = rand32(add_pos.x);
		this->y = rand32(add_pos.y);
		return *this;
	}

	inline Pos2 & Pos2::randPlus(const uint32_t add_pos)
	{
		this->x += (rand32(add_pos) - (add_pos >> 1));
		this->y += (rand32(add_pos) - (add_pos >> 1));
		return *this;
	}

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

	//長方形の大きさ(左上と右下の位置)
	struct Pos4
	{
		Pos4& operator=(const Pos2& add_pos);
		Pos4& operator=(const Pos8& add_pos);
		Pos4& operator=(const PosA4& add_pos);
		Pos4& operator=(const PosL4& add_pos);
		operator Pos2();
		operator Pos8();
		operator PosA4();
		operator PosL4();
		int32_t x1;
		int32_t y1;
		int32_t x2;
		int32_t y2;
		Pos4& rand(const Pos2&);
		Pos4& conv(const Pos4R&, const Pos2&);

		//Pos4() {};
		//Pos4(const int32_t x1_, const int32_t y1_, const int32_t x2_, const int32_t y2_) :x1(x1_), y1(y1_), x2(x2_), y2(y2_) {};
	};

	inline Pos4 & Pos4::rand(const Pos2& add_pos)
	{
		this->x2 = this->x1 + rand32(add_pos.x);
		this->y2 = this->y1 + rand32(add_pos.y);
		return *this;
	}

	//長方形の大きさ(位置と長さ)
	struct PosL4
	{
		PosL4& operator=(const Pos2& add_pos);
		PosL4& operator=(const Pos4& add_pos);
		PosL4& operator=(const PosA4& add_pos);
		PosL4& operator=(const Pos8& add_pos);
		operator Pos2();
		operator Pos4();
		operator PosA4();
		operator Pos8();
		int32_t x = 0;
		int32_t y = 0;
		int32_t w = 0;
		int32_t h = 0;
	};

	//中心位置と大きさを併せ持つ
	struct PosA4
	{
		PosA4& operator=(const Pos2& add_pos);
		PosA4& operator=(const Pos4& add_pos);
		PosA4& operator=(const PosL4& add_pos);
		PosA4& operator=(const Pos8& add_pos);
		operator Pos2();
		operator Pos4();
		operator PosL4();
		operator Pos8();
		PosA4& rand(const Pos2&);
		PosA4& randPlus(const uint32_t);
		int32_t x = 0;
		int32_t y = 0;
		int32_t w = 0;
		int32_t h = 0;
	};

	inline PosA4 & PosA4::randPlus(const uint32_t add_pos)
	{
		this->x += (rand32(add_pos) - (add_pos >> 1));
		this->y += (rand32(add_pos) - (add_pos >> 1));
		return *this;
	}

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

	//四角形の大きさ
	struct Pos8
	{
		Pos8& operator=(const Pos2& add_pos);
		Pos8& operator=(const Pos4& add_pos);
		Pos8& operator=(const PosL4& add_pos);
		Pos8& operator=(const PosA4& add_pos);
		int32_t x1 = 0;
		int32_t y1 = 0;
		int32_t x2 = 0;
		int32_t y2 = 0;
		int32_t x3 = 0;
		int32_t y3 = 0;
		int32_t x4 = 0;
		int32_t y4 = 0;
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

	inline Pos2::operator Pos4()
	{
		Pos4 pos;
		pos.x2 = this->x;
		pos.y2 = this->y;
		return pos;
	}

	inline Pos2::operator PosA4()
	{
		PosA4 pos;
		pos.x = this->x;
		pos.y = this->y;
		return pos;
	}

	inline Pos2::operator PosL4()
	{
		PosL4 pos;
		pos.x = this->x;
		pos.y = this->y;
		return pos;
	}

	inline Pos2::operator Pos8()
	{
		Pos8 pos;
		pos.x2 = this->x;
		pos.y3 = this->y;
		pos.x4 = this->x;
		pos.y4 = this->y;
		return pos;
	}

	inline  PosL4& PosL4::operator=(const Pos4& add_pos)
	{
		this->w = add_pos.x2 - add_pos.x1;
		this->h = add_pos.y2 - add_pos.y1;
		this->x = add_pos.x1;
		this->y = add_pos.y1;
		return *this;
	}

	inline PosL4 & PosL4::operator=(const Pos2 & add_pos)
	{
		this->x = add_pos.x;
		this->y = add_pos.y;
		return *this;
	}

	inline PosL4 & PosL4::operator=(const PosA4 & add_pos)
	{
		this->x = add_pos.x - (add_pos.w >> 1);
		this->y = add_pos.y - (add_pos.h >> 1);
		this->w = add_pos.w;
		this->h = add_pos.h;
		return *this;
	}

	inline PosL4 & PosL4::operator=(const Pos8 & add_pos)
	{
		this->w = add_pos.x4 - add_pos.x1;
		this->h = add_pos.y4 - add_pos.y1;
		this->x = add_pos.x1;
		this->y = add_pos.y1;
		return *this;
	}

	inline Pos4& Pos4::operator=(const PosL4& add_pos)
	{
		this->x1 = add_pos.x;
		this->y1 = add_pos.y;
		this->x2 = add_pos.x + add_pos.w;
		this->y2 = add_pos.y + add_pos.h;
		return *this;
	}

	inline Pos4& Pos4::operator=(const PosA4& add_pos)
	{
		const int32_t pos_w = add_pos.w >> 1;
		const int32_t pos_h = add_pos.h >> 1;
		this->x1 = add_pos.x - pos_w;
		this->y1 = add_pos.y - pos_h;
		this->x2 = add_pos.x + pos_w;
		this->y2 = add_pos.y + pos_h;
		return *this;
	}

	inline Pos4::operator PosL4()
	{
		PosL4 pos;
		pos.w = this->x2 - this->x1;
		pos.h = this->y2 - this->y1;
		pos.x = this->x1;
		pos.y = this->y1;
		return pos;
	}

	inline Pos4::operator PosA4()
	{
		PosA4 pos;
		pos.w = this->x2 - this->x1;
		pos.h = this->y2 - this->y1;
		pos.x = this->x1 + (pos.w >> 1);
		pos.y = this->y1 + (pos.h >> 1);
		return pos;
	}

	inline PosL4::operator PosA4()
	{
		PosA4 pos;
		const int32_t pos_w = this->w >> 1;
		const int32_t pos_h = this->h >> 1;
		pos.x = this->x + pos_w;
		pos.y = this->y + pos_h;
		pos.w = this->w;
		pos.h = this->h;
		return pos;
	}

	inline PosL4::operator Pos8()
	{
		Pos8 pos;
		pos.x1 = this->x;
		pos.y1 = this->y;
		pos.x2 = this->x + this->w;
		pos.y2 = this->y;
		pos.x3 = this->x;
		pos.y3 = this->y + this->h;
		pos.x4 = this->x + this->w;
		pos.y4 = this->y + this->h;
		return pos;
	}
	inline PosL4::operator Pos4()
	{
		Pos4 pos;
		pos.x1 = this->x;
		pos.y1 = this->y;
		pos.x2 = this->x + this->w;
		pos.y2 = this->y + this->h;
		return pos;
	}
	inline PosL4::operator Pos2()
	{
		Pos2 pos;
		pos.x = this->x;
		pos.y = this->y;
		return pos;
	}

	inline PosA4::operator PosL4()
	{
		PosL4 pos;
		pos.x = this->x - (this->w >> 1);
		pos.y = this->y - (this->h >> 1);
		pos.w = this->w;
		pos.h = this->h;
		return pos;
	}

	inline PosA4::operator Pos8()
	{
		Pos8 pos;
		const int32_t pos_w = this->w >> 1;
		const int32_t pos_h = this->h >> 1;
		pos.x1 = this->x - pos_w;
		pos.y1 = this->y - pos_h;
		pos.x2 = this->x + pos_w;
		pos.y2 = this->y - pos_h;
		pos.x3 = this->x - pos_w;
		pos.y3 = this->y + pos_h;
		pos.x4 = this->x + pos_w;
		pos.y4 = this->y + pos_h;
		return pos;
	}

	inline PosA4::operator Pos2()
	{
		Pos2 pos;
		pos.x = this->x;
		pos.y = this->y;
		return pos;
	}

	inline PosA4::operator Pos4()
	{
		Pos4 pos;
		const int32_t pos_w = this->w >> 1;
		const int32_t pos_h = this->h >> 1;
		pos.x1 = this->x - pos_w;
		pos.y1 = this->y - pos_h;
		pos.x2 = this->x + pos_w;
		pos.y2 = this->y + pos_h;
		return pos;
	}

	inline PosA4 & PosA4::rand(const Pos2& add_pos)
	{
		this->x = rand32(add_pos.x);
		this->y = rand32(add_pos.y);
		return *this;
	}

	inline PosA4& PosA4::operator=(const Pos2& add_pos)
	{
		this->x = add_pos.x;
		this->y = add_pos.y;
		return *this;
	}

	inline PosA4& PosA4::operator=(const Pos4& add_pos)
	{
		this->w = add_pos.x2 - add_pos.x1;
		this->h = add_pos.y2 - add_pos.y1;
		this->x = add_pos.x1 + (this->w >> 1);
		this->y = add_pos.y1 + (this->h >> 1);
		return *this;
	}

	inline PosA4& PosA4::operator=(const PosL4& add_pos)
	{
		const int32_t pos_w = add_pos.w >> 1;
		const int32_t pos_h = add_pos.h >> 1;
		this->x = add_pos.x + pos_w;
		this->y = add_pos.y + pos_h;
		this->w = add_pos.w;
		this->h = add_pos.h;
		return *this;
	}

	inline PosA4& PosA4::operator=(const Pos8& add_pos)
	{
		this->w = add_pos.x4 - add_pos.x1;
		this->h = add_pos.y4 - add_pos.y1;
		this->x = add_pos.x1;
		this->y = add_pos.y1;
		return *this;
	}

	//2点位置

	inline Pos2 & Pos2::operator=(const Pos4 & add_pos)
	{
		this->x = add_pos.x2;
		this->y = add_pos.y2;
		return *this;
	}

	inline Pos2 & Pos2::operator=(const PosL4 & add_pos)
	{
		this->x = add_pos.x;
		this->y = add_pos.y;
		return *this;
	}

	inline Pos2 & Pos2::operator=(const PosA4 & add_pos)
	{
		this->x = add_pos.x;
		this->y = add_pos.y;
		return *this;
	}

	inline Pos2& Pos2::operator=(const Pos8& add_pos)
	{
		this->x = add_pos.x4;
		this->y = add_pos.y4;
		return *this;
	}

	inline Pos2& Pos2::operator()(const int32_t pos_x, const int32_t pos_y)
	{
		this->x = pos_x;
		this->y = pos_y;
		return *this;
	}

	inline Pos2& Pos2::operator()(const int32_t pos_size)
	{
		this->x = pos_size;
		this->y = pos_size;
		return *this;
	}

	inline Pos2R& Pos2R::operator=(const Pos8R& add_pos)
	{
		this->x = add_pos.x4;
		this->y = add_pos.y4;
		return *this;
	}

	inline Pos4& Pos4::operator=(const Pos8& add_pos)
	{
		this->x1 = add_pos.x1;
		this->x2 = add_pos.x4;
		this->y1 = add_pos.y1;
		this->y2 = add_pos.y4;
		return *this;
	}

	inline Pos4::operator Pos2()
	{
		Pos2 pos2;
		pos2.x = this->x2;
		pos2.y = this->y2;
		return pos2;
	}

	inline Pos4R& Pos4R::operator=(const Pos8R& add_pos)
	{
		this->x1 = add_pos.x1;
		this->x2 = add_pos.x4;
		this->y1 = add_pos.y1;
		this->y2 = add_pos.y4;
		return *this;
	}

	inline Pos4::operator Pos8()
	{
		Pos8 pos8;
		pos8.x1 = this->x1;
		pos8.y1 = this->y1;
		pos8.x2 = this->x2;
		pos8.y2 = this->y1;
		pos8.x3 = this->x1;
		pos8.y3 = this->y2;
		pos8.x4 = this->x2;
		pos8.y4 = this->y2;
		return pos8;
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

	inline Pos8& Pos8::operator=(const Pos4& add_pos)
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

	inline Pos8& Pos8::operator=(const PosL4& add_pos)
	{
		this->x1 = add_pos.x;
		this->y1 = add_pos.y;
		this->x2 = add_pos.x + add_pos.w;
		this->y2 = add_pos.y;
		this->x3 = add_pos.x;
		this->y3 = add_pos.y + add_pos.h;
		this->x4 = add_pos.x + add_pos.w;
		this->y4 = add_pos.y + add_pos.h;
		return *this;
	}

	inline Pos8& Pos8::operator=(const PosA4& add_pos)
	{
		const int32_t pos_w = add_pos.w >> 1;
		const int32_t pos_h = add_pos.h >> 1;
		this->x1 = add_pos.x - pos_w;
		this->y1 = add_pos.y - pos_h;
		this->x2 = add_pos.x + pos_w;
		this->y2 = add_pos.y - pos_h;
		this->x3 = add_pos.x - pos_w;
		this->y3 = add_pos.y + pos_h;
		this->x4 = add_pos.x + pos_w;
		this->y4 = add_pos.y + pos_h;
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

	inline Pos8& Pos8::operator=(const Pos2& add_pos)
	{
		this->x1 = 0;
		this->y1 = 0;
		this->x2 = add_pos.x;
		this->y2 = 0;
		this->x3 = 0;
		this->y3 = add_pos.y;
		this->x4 = add_pos.x;
		this->y4 = add_pos.y;
		return *this;
	}

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

	inline Pos4& Pos4::operator=(const Pos2& add_pos)
	{
		this->x1 = 0;
		this->y1 = 0;
		this->x2 = add_pos.x;
		this->y2 = add_pos.y;
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

	inline Pos4& Pos4::conv(const Pos4R& pos_, const Pos2& window_pos_)
	{
		this->x1 = int32_t(pos_.x1*window_pos_.x);
		this->x2 = int32_t(pos_.x2*window_pos_.x);
		this->y1 = int32_t(pos_.y1*window_pos_.y);
		this->y2 = int32_t(pos_.y2*window_pos_.y);
		return *this;
	}

}