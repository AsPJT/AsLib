﻿/*#######################################################################################
	Made by Kasugaccho
	Made by As Project
	https://github.com/Kasugaccho/AsLib
	wanotaitei@gmail.com

	This code is licensed under CC0.
#######################################################################################*/
#ifndef INCLUDED_AS_PROJECT_LIBRARY_BUTTON
#define INCLUDED_AS_PROJECT_LIBRARY_BUTTON


namespace AsLib
{
	std::string asSizeToString(const std::size_t s_) noexcept {
#if defined(__ANDROID__)
		std::stringstream ss;
		ss << s_;
		return ss.str();
#else
		return std::to_string(s_);
#endif
	}

	//言語リスト
	enum :std::size_t {
		aslib_default_language_eng,
		aslib_default_language_jpn,
	};

	//言語数を記録する関数
	std::size_t asLanguageNumSave(const bool b_, const std::size_t& num_ = 0) noexcept
	{
		static std::size_t num;
		if (b_) num = num_;
		return num;
}
	//言語数を取得する関数
	inline std::size_t asLanguageNum() noexcept { return asLanguageNumSave(false); }

	struct AsWord {
	private:
		std::string str{};
	public:
		AsWord() = default;
		explicit AsWord(const std::string& str_) :str(str_) {}
		void set(const std::string& str_) noexcept { str = str_; }
		std::string get() noexcept { return str; }
	};

	//todo
	inline std::size_t asLanguage() noexcept { return 0; }

	struct AsLanguage {
	private:
		std::unique_ptr<AsWord[]> str;
		std::size_t num{};
	public:
		explicit AsLanguage() :num(asLanguageNum()) { str.reset(new AsWord[asLanguageNum()]); }
		void set(const std::size_t id_, const std::string& str_) noexcept {
			if (id_ >= num || str_.size() == 0) return;
			str[id_].set(str_);
		}
		std::string get() noexcept { return str[asLanguage()].get(); }

	};

	//ボタン種類
	enum :std::size_t {
		aslib_button_type_normal,
		aslib_button_type_number,
	};

	//画像のみを表示するシンプルなボタン
	struct AsTextureButton {
		//位置
		PosA4 pos;
		//画像
		AsTexture* texture{ nullptr };

		bool on_off{ false };

		AsTextureButton() = default;
		explicit AsTextureButton(const PosA4& p_, AsTexture* const t_) :pos(p_), texture(t_) {}

		void reset(const PosA4& p_, AsTexture* const t_) noexcept {
			pos = p_;
			texture = t_;
		}

		//タッチカウント
		Counter counter;
		void update() noexcept { counter.update(asTouch(pos) || asMouseL(pos)); }
		bool down() const noexcept { return counter.down(); };
		bool up() const noexcept { return counter.up(); };
		std::int32_t count() const noexcept { return counter.count(); };
		bool down0() noexcept { return counter.down0(); };
		bool up0() noexcept { return counter.up0(); };
		std::int32_t count0() noexcept { return counter.count0(); };

		AsTextureButton& draw() noexcept {
			if (texture == nullptr) return *this;
			texture->draw(pos);
			if (on_off) asRect(pos, Color(0, 0, 0, 100));
			return *this;
		}
		bool isOn() const noexcept { return on_off; }
		AsTextureButton& bit() noexcept { if (on_off) on_off = false; else on_off = true; return *this; }
		AsTextureButton& bitSet(const bool is_) noexcept { on_off = is_; return *this; }
	};
	//数値ボタン付き
	struct AsTextureNumButton :public AsTextureButton {
		PosA4 p_up;
		PosA4 p_down;

		AsFont font;

		AsTextureNumButton() = default;
		explicit AsTextureNumButton(const PosA4& p_, AsTexture* const t_) :AsTextureButton(p_, t_), p_up(PosA4(p_.x, p_.y - p_.h / 2, p_.w, p_.h / 2)), p_down(PosA4(p_.x, p_.y + p_.h / 2, p_.w, p_.h / 2)), font(p_.h/2) {}
		
		void reset(const PosA4& p_, AsTexture* const t_) noexcept {
			pos = p_;
			texture = t_;
			p_up = (PosA4(p_.x, p_.y - p_.h / 2, p_.w, p_.h / 2));
			p_down = (PosA4(p_.x, p_.y + p_.h / 2, p_.w, p_.h / 2));
			font = p_.h / 2;
		}
		
		//タッチカウント
		Counter counter_up;
		void updateUp() noexcept { counter_up.update(asTouch(p_up) || asMouseL(p_up)); }
		bool downUp() const noexcept { return counter_up.down(); };
		bool upUp() const noexcept { return counter_up.up(); };
		std::int32_t countUp() const noexcept { return counter_up.count(); };
		bool down0_Up() noexcept { return counter_up.down0(); };
		bool up0_Up() noexcept { return counter_up.up0(); };
		std::int32_t count0_Up() noexcept { return counter_up.count0(); };
		//タッチカウント
		Counter counter_down;
		void updateDown() noexcept { counter_down.update(asTouch(p_down) || asMouseL(p_down)); }
		bool downDown() const noexcept { return counter_down.down(); };
		bool upDown() const noexcept { return counter_down.up(); };
		std::int32_t countDown() const noexcept { return counter_down.count(); };
		bool down0_Down() noexcept { return counter_down.down0(); };
		bool up0_Down() noexcept { return counter_down.up0(); };
		std::int32_t count0_Down() noexcept { return counter_down.count0(); };

		void drawNum(const std::size_t var_,const Color& c_=aslib_color_black_a) noexcept {
			font.drawAt(asSizeToString(var_).c_str(), Pos2(pos.x, pos.y), c_);
		}
	};

	struct AsButton {
		//種類
		std::size_t type;
		//位置
		PosA4 pos;
		//画像
		AsTexture* texture{ nullptr };
		//文字
		AsLanguage* language{ nullptr };
		std::string str;
		AsFont font;
		std::size_t number{};
		//
		bool on_off{ false };

		//色
		Color button_color = aslib_color_white_a;
		Color string_color = aslib_color_black_a;

		AsButton() = default;
		explicit AsButton(const PosA4& p_, const std::int32_t add_size, const char* const str_) :type(0), pos(p_), font((add_size == 0) ? (p_.h * 3 / 5) : add_size, str_) {}
		explicit AsButton(const PosA4& p_, const char* const str_) :type(0), pos(p_), font(p_.h * 3 / 5, str_) {}
		explicit AsButton(const PosA4& p_, const std::int32_t add_size) :type(0), pos(p_), font((add_size == 0) ? (p_.h * 3 / 5) : add_size) {}
		explicit AsButton(const PosA4& p_) :type(0), pos(p_), font(p_.h * 3 / 5) {}
		explicit AsButton(AsTexture* const t_) :type(0), texture(t_) {}

		void setString(const std::string& str_) noexcept { str = str_; }
		void setButtonColor(const Color& c_) noexcept { button_color = c_; }
		void setStringColor(const Color& c_) noexcept { string_color = c_; }
		void setString(AsLanguage* const l_) noexcept { language = l_; }

		void draw() noexcept {
			if (button_color.a != (std::uint8_t)0) asRect(pos, button_color);
			if (language != nullptr) font.drawAt(language->get().c_str(), Pos2(pos.x, pos.y), string_color);
			else if (str.size() != 0) font.drawAt(str.c_str(), Pos2(pos.x, pos.y), string_color);
		}

		//タッチカウント
		Counter counter;
		void update() noexcept { counter.update(asTouch(pos) || asMouseL(pos)); }
		bool down() const noexcept { return counter.down(); };
		bool up() const noexcept { return counter.up(); };
		std::int32_t count() const noexcept { return counter.count(); };
		bool down0() noexcept { return counter.down0(); };
		bool up0() noexcept { return counter.up0(); };
		std::int32_t count0() noexcept { return counter.count0(); };
	};

}

#endif //Included AsProject Library