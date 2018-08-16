//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsProject Library
//
//                    Created by Gaccho (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{

	//マウスID
	enum :size_t {
		aslib_mouse_left,
		aslib_mouse_right,
		aslib_mouse_middle,
		aslib_mouse_4,
		aslib_mouse_5,
		aslib_mouse_6,
		aslib_mouse_7,
		aslib_mouse_8,
		aslib_mouse_9,
		aslib_mouse_10,
	};

	//マウスのボタン数
	constexpr size_t mouse_button_num = 10;


	//マウス位置を記録する関数
	const Pos2 asMousePosSave(const bool b_, const Pos2& p_ = pos2_0)
	{
		static Pos2 p;
		if (b_) p = p_;
		return p;
	}

	//マウスの位置
	const Pos2 mousePos()
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		int mouse_x = 0, mouse_y = 0;
		DxLib::GetMousePoint(&mouse_x, &mouse_y);
		return Pos2(int32_t(mouse_x), int32_t(mouse_y));
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		return Pos2(int32_t(s3d::Cursor::Pos().x), int32_t(s3d::Cursor::Pos().y));
#elif defined(ASLIB_INCLUDE_OF)
		return asMousePosSave(false);
#elif defined(ASLIB_INCLUDE_TP)
		return Pos2();
#else //Console
		return Pos2();
#endif
	}

	inline const PosA4 mousePos(const int32_t l_) { return PosA4(mousePos(), l_); }
	inline const PosA4 mousePos(const int32_t w_, const int32_t h_) { return PosA4(mousePos(), w_, h_); }

	//マウスのホイール回転量(奥:負 手前:正)
	inline const int32_t mouseWheel()
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		return int32_t(DxLib::GetMouseWheelRotVol(TRUE));
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		return int32_t(s3d::Mouse::Wheel());
#elif defined(ASLIB_INCLUDE_OF)
		return 0;
#elif defined(ASLIB_INCLUDE_TP)
		return 0;
#else //Console
		return 0;
#endif
	}

	const int32_t asMouseWheel(const Pos4& p_) {
		const int32_t wheel = mouseWheel();
		if (wheel == 0) return 0;

		const Pos2 touch_p = mousePos();
		if (touch_p.x > p_.x1&&touch_p.y > p_.y1&&touch_p.x < p_.x2&&touch_p.y < p_.y2) return wheel;
		return 0;
	}
	inline void asMouseWheel(PosA4F& add_, const float f_ = 5.0, const int32_t view_max_ = 0, Pos4 area_ = aslib_default_area) {
		if (!isArea(area_)) area_ = asWindowSize4();
		float pinch = asMouseWheel(area_) / f_;
		add_.w -= pinch;
		add_.h -= pinch;
		if (add_.w < 1.0f) add_.w = 1.0f;
		if (add_.h < 1.0f) add_.h = 1.0f;
		if (view_max_ == 0) return;
		if (int32_t(add_.w) >= view_max_) add_.w = float(view_max_);
		if (int32_t(add_.h) >= view_max_) add_.h = float(view_max_);
	}

	//ウィンドウサイズを記録する関数
	const bool* const asMouseButtonSave(const bool b_, const bool c_ = false, const bool p_ = false, const size_t s_ = 0)
	{
		static bool p[mouse_button_num];
		if (c_) for (size_t i = 0; i < mouse_button_num; ++i) p[i] = false;
		if (b_) p[s_] = p_;
		return p;
	}

	inline void mouseButton(Counter count[mouse_button_num])
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		const int mouse_input = DxLib::GetMouseInput();
		count[aslib_mouse_left].update((mouse_input & MOUSE_INPUT_LEFT) != 0);
		count[aslib_mouse_right].update((mouse_input & MOUSE_INPUT_RIGHT) != 0);
		count[aslib_mouse_middle].update((mouse_input & MOUSE_INPUT_MIDDLE) != 0);
		count[aslib_mouse_4].update((mouse_input & MOUSE_INPUT_4) != 0);
		count[aslib_mouse_5].update((mouse_input & MOUSE_INPUT_5) != 0);
		count[aslib_mouse_6].update((mouse_input & MOUSE_INPUT_6) != 0);
		count[aslib_mouse_7].update((mouse_input & MOUSE_INPUT_7) != 0);
		count[aslib_mouse_8].update((mouse_input & MOUSE_INPUT_8) != 0);
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		count[aslib_mouse_left].update(s3d::MouseL.pressed() != 0);
		count[aslib_mouse_right].update(s3d::MouseR.pressed() != 0);
		count[aslib_mouse_middle].update(s3d::MouseM.pressed() != 0);
		count[aslib_mouse_4].update(s3d::MouseX1.pressed() != 0);
		count[aslib_mouse_5].update(s3d::MouseX2.pressed() != 0);
		count[aslib_mouse_6].update(s3d::MouseX3.pressed() != 0);
		count[aslib_mouse_7].update(s3d::MouseX4.pressed() != 0);
		count[aslib_mouse_8].update(s3d::MouseX5.pressed() != 0);
#elif defined(ASLIB_INCLUDE_OF)
		for (size_t i = 0; i < mouse_button_num; ++i) {
			count[i].update(asMouseButtonSave(false)[i]);
		}
#elif defined(ASLIB_INCLUDE_TP)

#else //Console

#endif
	}
	//マウス左クリック
	const bool asMouseL(Pos2* const p_=nullptr) {
		if (p_ != nullptr) *p_ = mousePos();
#if defined(ASLIB_INCLUDE_DL) //DxLib
		return ((DxLib::GetMouseInput() & MOUSE_INPUT_LEFT) != 0);
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		return (s3d::MouseL.pressed() != 0);
#elif defined(ASLIB_INCLUDE_OF)
		return (asMouseButtonSave(false)[aslib_mouse_left]);
#elif defined(ASLIB_INCLUDE_TP)
		return false;
#else //Console

#endif
	}

	const bool asMouseL_Down(const bool is_=false) {
		static bool is_down = false;
		static bool hit = false;

		if (!is_) return hit;
		//押したとき
		if (!is_down &&asMouseL()) hit = true;
		else hit = false;
		is_down = asMouseL();

		return hit;
	}

	const bool asMouseL(const Pos4& p_) {
		if (!asMouseL()) return false;
		Pos2 touch_p = mousePos();
		if (touch_p.x > p_.x1&&touch_p.y > p_.y1&&touch_p.x < p_.x2&&touch_p.y < p_.y2) return true;
		return false;
	}

	const Pos2 asMouseSlide(const bool is_update = false) {
		static Pos2 total_p(0,0);
		if (!is_update) return total_p;

		static bool is_pinch = false;
		if (!asMouseL()) {
			is_pinch = false;
			return total_p(0, 0);
			asPrint("a");
		}
		static Pos2 before_p{};
		const Pos2 after_p = mousePos();

		if (!is_pinch) {
			is_pinch = true;
			before_p = after_p;
			return 0;
		}
		is_pinch = true;
		total_p(before_p.x - after_p.x, before_p.y - after_p.y);
		before_p = after_p;
		return total_p;
	}

	const Pos2 asMouseSlide(const Pos4& area_) {
		if (!asMouseL()) return 0;
		if (!isArea(area_, mousePos())) return 0;
		return asMouseSlide();
	}


	inline Counter* const mouseButton()
	{
		static Counter count[mouse_button_num];
		mouseButton(count);
		return count;
	}

	const bool updateMouse()
	{
		//スライド更新
		asMouseSlide(true);
		asMouseL_Down(true);
		return true;
	}


	class Mouse
	{
	public:
		const Pos2 Pos() const { return this->pos; };
		const int32_t Wheel() const { return this->wheel; };
		const Counter count(const size_t count_num) const { return this->counter[count_num]; };

		const bool down() const { return this->counter[aslib_mouse_left].down(); };
		const bool up() const { return this->counter[aslib_mouse_left].up(); };
		const int32_t count() const { return this->counter[aslib_mouse_left].count(); };

		const bool downL() const { return this->counter[aslib_mouse_left].down(); };
		const bool upL() const { return this->counter[aslib_mouse_left].up(); };
		const int32_t countL() const { return this->counter[aslib_mouse_left].count(); };

		const bool downR() const { return this->counter[aslib_mouse_right].down(); };
		const bool upR() const { return this->counter[aslib_mouse_right].up(); };
		const int32_t countR() const { return this->counter[aslib_mouse_right].count(); };

		const bool downM() const { return this->counter[aslib_mouse_middle].down(); };
		const bool upM() const { return this->counter[aslib_mouse_middle].up(); };
		const int32_t countM() const { return this->counter[aslib_mouse_middle].count(); };

		const bool down4() const { return this->counter[aslib_mouse_4].down(); };
		const bool up4() const { return this->counter[aslib_mouse_4].up(); };
		const int32_t count4() const { return this->counter[aslib_mouse_4].count(); };

		const bool down5() const { return this->counter[aslib_mouse_5].down(); };
		const bool up5() const { return this->counter[aslib_mouse_5].up(); };
		const int32_t count5() const { return this->counter[aslib_mouse_5].count(); };

		const bool down6() const { return this->counter[aslib_mouse_6].down(); };
		const bool up6() const { return this->counter[aslib_mouse_6].up(); };
		const int32_t count6() const { return this->counter[aslib_mouse_6].count(); };

		const bool down7() const { return this->counter[aslib_mouse_7].down(); };
		const bool up7() const { return this->counter[aslib_mouse_7].up(); };
		const int32_t count7() const { return this->counter[aslib_mouse_7].count(); };

		const bool down8() const { return this->counter[aslib_mouse_8].down(); };
		const bool up8() const { return this->counter[aslib_mouse_8].up(); };
		const int32_t count8() const { return this->counter[aslib_mouse_8].count(); };

		Mouse() :pos(mousePos()), wheel(mouseWheel()), counter(mouseButton()) {}

		void update() {
			this->pos = mousePos();
			this->wheel = mouseWheel();
			mouseButton(this->counter);
		}

	private:
		Pos2 pos;
		int32_t wheel;
		Counter* const counter;
	};
}
