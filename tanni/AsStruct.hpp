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

	//8点位置
	struct Pos8;
	struct Pos8R;

	//大きさ(2D)
	struct Pos2
	{
		Pos2& operator=(const Pos4& add_pos);
		Pos2& operator=(const Pos8& add_pos);
		Pos2& operator()(const int32_t pos_size = 0);
		Pos2& operator()(const int32_t pos_x, const int32_t pos_y);
		Pos2& rand(const Pos2&);

		int32_t x = 0;
		int32_t y = 0;
	};

	inline Pos2 & Pos2::rand(const Pos2& add_pos)
	{
		this->x = rand32(add_pos.x);
		this->y = rand32(add_pos.y);
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

	//長方形の大きさ
	struct Pos4
	{
		Pos4& operator=(const Pos2& add_pos);
		Pos4& operator=(const Pos8& add_pos);
		operator Pos2();
		operator Pos8();
		int32_t x1 = 0;
		int32_t y1 = 0;
		int32_t x2 = 0;
		int32_t y2 = 0;
	};

	struct PosA4
	{
		PosA4& operator=(const Pos2& add_pos);
		operator Pos4();
		PosA4& rand(const Pos2&);
		int32_t x = 0;
		int32_t y = 0;
		int32_t w = 0;
		int32_t h = 0;
	};

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

	inline PosA4::operator Pos4()
	{
		Pos4 pos;
		pos.x1 = this->x - (this->w >> 1);
		pos.y1 = this->y - (this->h >> 1);
		pos.x2 = this->x + (this->w >> 1);
		pos.y2 = this->y + (this->h >> 1);
		return pos;
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

	//2点位置

	inline Pos2 & Pos2::operator=(const Pos4 & add_pos)
	{
		this->x = add_pos.x2;
		this->y = add_pos.y2;
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

}