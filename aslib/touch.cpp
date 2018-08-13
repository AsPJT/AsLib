#define ASLIB_INCLUDE_DL
#include "AsLib.hpp"

//todo
const int32_t asTouchSlide() {
	static bool is_slide = false;
	if (asTouchNum() != 1) {
		is_slide = false;
		return 0;
	}
	static int32_t before_p{};

	const Pos2 after_p = asTouch(0);



	if (!is_slide) {
		is_slide = true;
		//before_p = after_p;
		return 0;
	}
	is_slide = true;
	///const int32_t total_p = after_p - before_p;
	//before_p = after_p;
	//return total_p;
	return 0;
}

int32_t asMain() {
	MainControl mc(u8"AsTouch", Pos2(960, 540));

	Pos2 c(960/2, 540/2);
	int32_t r = 50;

	while (asLoop()) {

		asTouchPinch(r);

		asPrintClear();
		asPrint("%d", asTouchNum());
		asCircle(c, r, Color(255, 255, 255));
	}

}