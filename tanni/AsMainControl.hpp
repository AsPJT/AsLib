//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - As���C�u����
//
//                    �����: �������� (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
	//�L�[�{�[�h�̃L�[�̐�
	constexpr size_t KEY_MAX = 255;
	constexpr size_t KEY_MAX_1 = KEY_MAX + 1;

	//�V�[���� (�f�t�H���g�ł�256��)
#if defined(AS_USING_SCENE_MAX)
	constexpr size_t SCENE_MAX = ASLIB_SCENE_MAX;
#else
	constexpr size_t SCENE_MAX = 256;
#endif

	//�Q�[���p�b�h�̐� (�f�t�H���g�ł�16��)
#if defined(AS_USING_GAME_PAD_MAX)
	constexpr size_t GAME_PAD_MAX = ASLIB_GAME_PAD_MAX;
#else
	constexpr size_t GAME_PAD_MAX = 16;
#endif

	constexpr size_t TEXTURE_MAX = 10;


	constexpr int32_t time_counter_ms = 1000;

	//���C���Ǘ��N���X
	class MainControl
	{
	public:
		MainControl(const MainData& init_data);
		MainControl(const char* const add_title = "", const Pos2& add_window_size = WINDOW_SIZE, const ColorRGB& add_BG_color = BG_COLOR);
		~MainControl();

		//���C�����[�v
		MainControl& loop();
		bool isLoop();

		//�V�[���n
		MainControl& AddScene(const size_t scene_num, const std::function<void(MainControl&)>& add_scene_func);
		MainControl& sceneSelect(const size_t add_select_scene);
		MainControl& scenePlay();
		MainControl& sceneEnd();

		//�L�[�{�[�h����
		int32_t countKey(const uint8_t select_key);
		uint8_t clickKey(const uint8_t select_key);
		uint8_t releaseKey(const uint8_t select_key);
		uint8_t keyConfig(const uint8_t select_key);

		//�e�N�X�`���n
		MainControl& textureAdd(const char* const add_name);
		MainControl& textureUI_Add(const size_t add_number, const uint8_t add_alpha, const Pos8& add_pos8);
		MainControl& textureUI_Add(const size_t add_number, const uint8_t add_alpha, Pos4& add_pos4);
		MainControl& draw8(const size_t select_texture);
		//std::vector<Texture> texture_ui_render;

		//�^�C�g�����S
		MainControl& drawLogo(const size_t add_texture_ui, const int32_t add_time, const size_t add_scene);
		MainControl& drawLogoOut(const size_t add_texture_ui, const int32_t add_out_time, const int32_t add_time, const size_t add_scene);
		MainControl& drawLogoInOut(const size_t add_texture_ui, const int32_t add_in_time, const int32_t add_out_time, const int32_t add_time, const size_t add_scene);

		std::vector<TextureMainData> texture_main_data_render;
		std::vector<TextureUI> texture_ui_render;

	private:
		
		//��{�f�[�^
		MainData init_data;

		//���[�v�n
		bool is_loop = true;

		//�V�[���n
		std::array<std::function<void(MainControl&)>, SCENE_MAX> scene_func = {};
		size_t select_scene = 0;

		//�L�[�{�[�h�̔���
		std::array < int32_t, KEY_MAX_1 > count_key = {};
		std::array < uint8_t, KEY_MAX_1 > click_key = {};
		std::array < uint8_t, KEY_MAX_1 > release_key = {};
		std::array < uint8_t, KEY_MAX_1 > keyconfig = {};

		//�摜
		size_t count_texture = 0;

		//fps�擾 todo
		int32_t fps = 60;
		
};

	MainControl::~MainControl()
	{
	}

	inline MainControl& MainControl::loop()
	{

		
		return *this;
	}

	inline bool MainControl::isLoop()
	{
		return is_loop;
	}

	inline MainControl & MainControl::AddScene(const size_t scene_num, const std::function<void(MainControl&)>& add_scene_func)
	{
		scene_func[scene_num] = add_scene_func;
		return *this;
	}

	inline MainControl & MainControl::sceneSelect(const size_t add_select_scene)
	{
		if (add_select_scene >= 0 && add_select_scene < SCENE_MAX) select_scene = add_select_scene;
		return *this;
	}



	inline MainControl & MainControl::scenePlay()
	{
		//�V�[�����I������Ă��Ȃ����̏���
		if (scene_func[select_scene] == nullptr) {
			sceneEnd();
			return *this;
		}

		//�I�����ꂽ�V�[�������s
		scene_func[select_scene](*this);

		//���͔���̏���
		if (!AsLoop()) sceneEnd();
		return *this;
	}

	inline MainControl & MainControl::sceneEnd()
	{
		select_scene = -1;
		is_loop = false;
		return *this;
	}

	inline int32_t MainControl::countKey(const uint8_t select_key)
	{
		return count_key[size_t(select_key)];
	}

	inline uint8_t MainControl::clickKey(const uint8_t select_key)
	{
		return click_key[size_t(select_key)];
	}

	inline uint8_t MainControl::releaseKey(const uint8_t select_key)
	{
		return release_key[size_t(select_key)];
	}

	inline uint8_t MainControl::keyConfig(const uint8_t select_key)
	{
		return keyconfig[size_t(select_key)];
	}

	inline MainControl& MainControl::textureUI_Add(const size_t add_number, const uint8_t add_alpha, const Pos8& add_pos8=pos8_100)
	{
		const TextureUI add_texture_ui(&texture_main_data_render[add_number], add_alpha, add_pos8);
		texture_ui_render.emplace_back(add_texture_ui);
		return *this;
	}

	inline MainControl& MainControl::textureUI_Add(const size_t add_number, const uint8_t add_alpha, Pos4& add_pos4)
	{
		const Pos8 add_pos8 = add_pos4;
		const TextureUI add_texture_ui(&texture_main_data_render[add_number], add_alpha, add_pos8);
		texture_ui_render.emplace_back(add_texture_ui);
		return *this;
	}

	inline MainControl & MainControl::textureAdd(const char * const add_name)
	{
		const TextureMainData add_texture(AsLoadTex(add_name));
		texture_main_data_render.emplace_back(add_texture);
		return *this;
	}

	inline MainControl & MainControl::draw8(const size_t select_texture)
	{
		asTex8(texture_ui_render[select_texture].point()->ID(), texture_ui_render[select_texture].pos(), texture_ui_render[select_texture].a());
		return *this;
	}



	//�R���X�g���N�^----------

	MainControl::MainControl(const MainData& add_init_data)
	{
		init_data = add_init_data;
		AsInit(init_data.title(), init_data.windowSize(), init_data.colorBG());
	}

	MainControl::MainControl(const char* const add_title, const Pos2& add_window_size, const ColorRGB& add_BG_color)
	{
		const MainData add_init_data(add_title, add_window_size, add_BG_color);
		init_data = add_init_data;
		AsInit(init_data.title(), init_data.windowSize(), init_data.colorBG());
	}


}
