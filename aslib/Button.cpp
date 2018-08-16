#define ASLIB_INCLUDE_DL
#include "AsLib.hpp"

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
	AsLanguage() :num(asLanguageNum()){ str.reset(new AsWord[asLanguageNum()]); }
	void set(const size_t id_,const std::string& str_) {
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
	AsButton(const PosA4& p_, const char* const str_) :pos(p_), font(p_.h*3/5, str_) {}
	AsButton(const PosA4& p_, const int32_t add_size) :pos(p_), font((add_size == 0) ? (p_.h*3/5) : add_size) {}
	AsButton(const PosA4& p_) :pos(p_), font(p_.h*3/5) {}
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

#include <chrono>

int32_t asMain()
{
	std::chrono::system_clock::time_point start, end;
	std::common_type_t<std::chrono::system_clock::duration, std::chrono::system_clock::duration> dur;
	long long msec;

	start = std::chrono::system_clock::now();
	//タイトル
	MainControl mc(u8"AsRPG", Pos2(960, 540));
	end = std::chrono::system_clock::now();
	dur = end - start;
	msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
	asPrint("start:%d\n",msec);

	start = std::chrono::system_clock::now();
	AsFont font(20);

	//std::string name;
	//name = asKeyInput(Pos2(0, 0));
	
	asLanguageNumSave(true, 2);
	AsLanguage b_str;
	b_str.set(aslib_default_language_eng, u8"Button");
	b_str.set(aslib_default_language_jpn, u8"ボタン");

	AsButton b(PosA4(300, 300, 200, 50));
	b.setString(&b_str);
	b.setString(u8"derageボタン");

	end = std::chrono::system_clock::now();
	dur = end - start;
	msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
	asPrint("next:%d", msec);

	//asPrint("%s", name.c_str());
	while (asLoop())
	{
		b.update();
		b.draw();

		if (b.up()) asPrint("a");

	}
	return 0;
}