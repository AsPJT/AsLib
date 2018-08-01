//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsProject Library
//
//                    Created by Gaccho (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{

#if defined(ASLIB_INCLUDE_DL) //DxLib

	struct AsScreen {

	private:
		OriginatorScreen screen;
		bool is_alpha = false;
		bool is_error = true;

	public:
		AsScreen(const Pos2& p_, const bool is_alpha = true) :screen(DxLib::MakeScreen(int(p_.x), int(p_.y), (is_alpha == true) ? 1 : 0)), is_alpha(is_alpha), is_error(checkScreen(screen)) {}
		~AsScreen() { DxLib::DeleteGraph(screen); }

		AsScreen& clear() { DxLib::SetDrawScreen(this->screen); DxLib::ClearDrawScreen(); DxLib::SetDrawScreen(DX_SCREEN_BACK); return *this; }

		const bool isError() const { return this->is_error; }
		const bool isAlpha() const { return this->is_alpha; }
		const OriginatorScreen copyScreen() const { return this->screen; }

		

	};

#elif defined(ASLIB_INCLUDE_S3) //Siv3D

#elif defined(ASLIB_INCLUDE_OF)

#elif defined(ASLIB_INCLUDE_TP)

#else //Console

#endif

}
