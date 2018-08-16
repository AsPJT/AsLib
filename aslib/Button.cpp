#define ASLIB_INCLUDE_DL
#include "AsLib.hpp"

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