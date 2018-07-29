//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asライブラリ
//
//                    制作者: がっちょ (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
	//メイン管理クラス
	class MainControl
	{
	private:
		int32_t init_true = false;
		//ウィンドウサイズ
		Pos2 window_size;
		//背景色
		Color color;
		//タイトル
		std::string title_name;
	public:
		MainControl(const char* const title_, const Pos2& window_size_ = WINDOW_SIZE, const Color& c_ = BG_COLOR) 
			:window_size(window_size_), color(c_), title_name(title_)
		{
			//OF例外措置
#if defined(ASLIB_INCLUDE_OF)
			ofSetupOpenGL(window_size_.x, window_size_.y, OF_WINDOW);
#endif
			init_true = AsInit(title_, window_size_, c_);
		}
		~MainControl() {}
	};
}
