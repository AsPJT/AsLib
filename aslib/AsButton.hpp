//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsProject Library
//
//                    Created by Gaccho (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
	const std::string asSizeToString(const size_t s_) {
#if defined(__ANDROID__)
		std::stringstream ss;
		ss << s_;
		return ss.str();
#else
		return std::to_string(s_);
#endif
	}

	//言語リスト
	enum :size_t {
		aslib_default_language_eng,
		aslib_default_language_jpn,
	};

	//言語数を記録する関数
	const size_t asLanguageNumSave(const bool b_, const size_t& num_ = 0)
	{
		static size_t num;
		if (b_) num = num_;
		return num;
}
	//言語数を取得する関数
	inline const size_t asLanguageNum() { return asLanguageNumSave(false); }

	struct AsWord {
	private:
		std::string str{};
	public:
		AsWord() = default;
		AsWord(const std::string& str_) :str(str_) {}
		void set(const std::string& str_) { str = str_; }
		std::string get() { return str; }
	};

	//todo
	inline const size_t asLanguage() { return 0; }

	struct AsLanguage {
	private:
		std::unique_ptr<AsWord[]> str;
		size_t num = 0;
	public:
		AsLanguage() :num(asLanguageNum()) { str.reset(new AsWord[asLanguageNum()]); }
		void set(const size_t id_, const std::string& str_) {
			if (id_ >= num || str_.size() == 0) return;
			str[id_].set(str_);
		}
		std::string get() { return str[asLanguage()].get(); }

	};

	//ボタン種類
	enum :size_t {
		aslib_button_type_normal,
		aslib_button_type_number,
	};

	//画像のみを表示するシンプルなボタン
	struct AsTextureButton {
		//位置
		PosA4 pos;
		//画像
		AsTexture* texture = nullptr;

		bool on_off = false;

		AsTextureButton() = default;
		AsTextureButton(const PosA4& p_, AsTexture* const t_) :pos(p_), texture(t_) {}

		void reset(const PosA4& p_, AsTexture* const t_) {
			pos = p_;
			texture = t_;
		}

		//タッチカウント
		Counter counter;
		void update() { counter.update(asTouch(pos) || asMouseL(pos)); }
		const bool down() const { return counter.down(); };
		const bool up() const { return counter.up(); };
		const int32_t count() const { return counter.count(); };
		const bool down0() { return counter.down0(); };
		const bool up0() { return counter.up0(); };
		const int32_t count0() { return counter.count0(); };

		AsTextureButton& draw() {
			if (texture == nullptr) return *this;
			texture->draw(pos);
			if (on_off) asRect(pos, Color(0, 0, 0, 100));
			return *this;
		}
		const bool isOn() const { return on_off; }
		AsTextureButton& bit() { if (on_off) on_off = false; else on_off = true; return *this; }
		AsTextureButton& bitSet(const bool is_) { on_off = is_; return *this; }
	};
	//数値ボタン付き
	struct AsTextureNumButton :public AsTextureButton {
		PosA4 p_up;
		PosA4 p_down;

		AsFont font;

		AsTextureNumButton() = default;
		AsTextureNumButton(const PosA4& p_, AsTexture* const t_) :AsTextureButton(p_, t_), p_up(PosA4(p_.x, p_.y - p_.h / 2, p_.w, p_.h / 2)), p_down(PosA4(p_.x, p_.y + p_.h / 2, p_.w, p_.h / 2)), font(p_.h/2) {}
		
		void reset(const PosA4& p_, AsTexture* const t_) {
			pos = p_;
			texture = t_;
			p_up = (PosA4(p_.x, p_.y - p_.h / 2, p_.w, p_.h / 2));
			p_down = (PosA4(p_.x, p_.y + p_.h / 2, p_.w, p_.h / 2));
			font = p_.h / 2;
		}
		
		//タッチカウント
		Counter counter_up;
		void updateUp() { counter_up.update(asTouch(p_up) || asMouseL(p_up)); }
		const bool downUp() const { return counter_up.down(); };
		const bool upUp() const { return counter_up.up(); };
		const int32_t countUp() const { return counter_up.count(); };
		const bool down0_Up() { return counter_up.down0(); };
		const bool up0_Up() { return counter_up.up0(); };
		const int32_t count0_Up() { return counter_up.count0(); };
		//タッチカウント
		Counter counter_down;
		void updateDown() { counter_down.update(asTouch(p_down) || asMouseL(p_down)); }
		const bool downDown() const { return counter_down.down(); };
		const bool upDown() const { return counter_down.up(); };
		const int32_t countDown() const { return counter_down.count(); };
		const bool down0_Down() { return counter_down.down0(); };
		const bool up0_Down() { return counter_down.up0(); };
		const int32_t count0_Down() { return counter_down.count0(); };

		void drawNum(const size_t var_,const Color& c_=aslib_color_black_a) {
			font.drawAt(asSizeToString(var_).c_str(), Pos2(pos.x, pos.y), c_);
		}
	};

	struct AsButton {
		//種類
		size_t type;
		//位置
		PosA4 pos;
		//画像
		AsTexture* texture = nullptr;
		//文字
		AsLanguage* language = nullptr;
		std::string str;
		AsFont font;
		size_t number = 0;
		//
		bool on_off = false;

		//色
		Color button_color = aslib_color_white_a;
		Color string_color = aslib_color_black_a;

		AsButton() = default;
		AsButton(const PosA4& p_, const int32_t add_size, const char* const str_) :pos(p_), font((add_size == 0) ? (p_.h * 3 / 5) : add_size, str_) {}
		AsButton(const PosA4& p_, const char* const str_) :pos(p_), font(p_.h * 3 / 5, str_) {}
		AsButton(const PosA4& p_, const int32_t add_size) :pos(p_), font((add_size == 0) ? (p_.h * 3 / 5) : add_size) {}
		AsButton(const PosA4& p_) :pos(p_), font(p_.h * 3 / 5) {}
		AsButton(AsTexture* const t_) :texture(t_) {}

		void setString(const std::string& str_) { str = str_; }
		void setButtonColor(const Color& c_) { button_color = c_; }
		void setStringColor(const Color& c_) { string_color = c_; }
		void setString(AsLanguage* const l_) { language = l_; }

		void draw() {
			if (button_color.a != (uint8_t)0) asRect(pos, button_color);
			if (language != nullptr) font.drawAt(language->get().c_str(), Pos2(pos.x, pos.y), string_color);
			else if (str.size() != 0) font.drawAt(str.c_str(), Pos2(pos.x, pos.y), string_color);
		}

		//タッチカウント
		Counter counter;
		void update() { counter.update(asTouch(pos) || asMouseL(pos)); }
		const bool down() const { return counter.down(); };
		const bool up() const { return counter.up(); };
		const int32_t count() const { return counter.count(); };
		const bool down0() { return counter.down0(); };
		const bool up0() { return counter.up0(); };
		const int32_t count0() { return counter.count0(); };
	};

}
