//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsProject Library
//
//                    Created by Gaccho (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------
#ifndef INCLUDED_AS_PROJECT_LIBRARY_MAIN_CONTROL
#define INCLUDED_AS_PROJECT_LIBRARY_MAIN_CONTROL


namespace AsLib
{
	//メイン管理クラス
	class MainControl
	{
	private:
		int32_t init_true{ false };
		//ウィンドウサイズ
		Pos2 window_size;
		//背景色
		Color color;
		//タイトル
		std::string title_name;
	public:
		MainControl(const char* const title_=u8"AsLib", const Pos2& window_size_ = aslib_default_window_size, const Color& c_ = aslib_bg_color) :window_size(asWindowSizeSave(true,window_size_)), color(c_), title_name(title_)
		{
			//OF例外措置
#if defined(ASLIB_INCLUDE_OF)
			asWindowSizeSave(true, window_size);
			ofSetupOpenGL(window_size_.x, window_size_.y, OF_WINDOW);
#endif
			init_true = AsInit(title_, window_size_, c_);
		}
		~MainControl() {}
		Pos2 windowSize() const noexcept {
			return window_size;
		}
	};
}

#endif //Included AsProject Library