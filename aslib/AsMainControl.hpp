//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - As���C�u����
//
//                    �����: �������� (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
	//���C���Ǘ��N���X
	class MainControl
	{
	private:
		int32_t init_true = false;
		//�E�B���h�E�T�C�Y
		Pos2 window_size;
		//�w�i�F
		Color color;
		//�^�C�g��
		std::string title_name;
	public:
		MainControl(const char* const title_, const Pos2& window_size_ = WINDOW_SIZE, const Color& c_ = BG_COLOR) :init_true(AsInit(title_, window_size_, c_)), window_size(window_size_), color(c_), title_name(title_)
		{
			//OF��O�[�u
#if defined(ASLIB_INCLUDE_OF)
			ofSetupOpenGL(add_window_size.x, add_window_size.y, OF_WINDOW);
#endif
		}
		~MainControl() {}
	};
}
