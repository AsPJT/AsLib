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


	//1�b=1000ms
	constexpr int32_t time_counter_ms = 1000;

	//���C���Ǘ��N���X
	class MainControl
	{
		//��{�f�[�^�n
	public:
		Pos2 windowSize() const { return this->init_data.windowSize(); };
		ColorRGB colorBG() const { return this->init_data.colorBG(); };
		const char* title() const { return this->init_data.title(); };
	private:
		MainData init_data;

	private:
		//���[�v�n
		bool is_loop = true;

	public:
		MainControl(const MainData& init_data);
		MainControl(const char* const add_title = "", const Pos2& add_window_size = WINDOW_SIZE, const ColorRGB& add_BG_color = BG_COLOR);
		~MainControl();

		//���C�����[�v
		MainControl& loop();
		bool isLoop() const;

		//�V�[���n
		MainControl& AddScene(const size_t, const std::function<void(MainControl&)>&);
		MainControl& AddScene(const size_t, const std::function<void(MainControl&)>&, const ColorRGB&);
		MainControl& scene(const size_t add_select_scene);
		MainControl& scenePlay();
		MainControl& sceneEnd();

		//�L�[�{�[�h����
		int32_t countKey(const uint8_t select_key) const;
		uint8_t clickKey(const uint8_t select_key) const;
		uint8_t releaseKey(const uint8_t select_key) const;
		uint8_t keyConfig(const uint8_t select_key) const;

		//�e�N�X�`���n
		MainControl& textureAdd(const char* const add_name);
		MainControl& animeAdd(const char* const add_name, const size_t);
		//MainControl& textureUI_Add(const size_t add_number, const uint8_t add_alpha, const Pos4& add_pos4);
		MainControl& textureUI_Add(const size_t add_number, const uint8_t add_alpha, const Pos4& add_pos4);
		MainControl& animeUI_Add(const size_t add_number, const uint8_t add_alpha, const Pos4& add_pos4);
		MainControl& texture(const size_t select_texture);
		MainControl& anime(const size_t select_texture);
		//std::vector<Texture> texture_ui_render;

		//�^�C�g�����S
		MainControl& drawLogo(const size_t add_texture_ui, const int32_t add_time, const size_t add_scene);
		MainControl& drawLogoOut(const size_t add_texture_ui, const int32_t add_out_time, const int32_t add_time, const size_t add_scene);
		MainControl& logoTex(const size_t add_texture_ui, const int32_t add_in_time, const int32_t add_out_time, const int32_t add_time, const size_t add_scene);
		MainControl& logoAnime(const size_t add_texture_ui, const int32_t add_in_time, const int32_t add_out_time, const int32_t add_time, const size_t add_scene);

		//�^�b�`�n
	public:
		bool touchTex(const size_t ui_id) const { return (this->texture_ui_render[ui_id].Touch() > 0); };
		bool touchTex0(const size_t ui_id) { return (this->texture_ui_render[ui_id].Touch0() > 0); };
		bool touchAnime(const size_t ui_id) const { return (this->anime_ui_render[ui_id].Touch() > 0); };
		bool touchAnime0(const size_t ui_id) { return (this->anime_ui_render[ui_id].Touch0() > 0); };
		bool upTex(const size_t ui_id) const { return (this->texture_ui_render[ui_id].Up()); };
		bool upTex0(const size_t ui_id) { return (this->texture_ui_render[ui_id].Up0()); };
		bool upAnime(const size_t ui_id) const { return (this->anime_ui_render[ui_id].Up()); };
		bool upAnime0(const size_t ui_id) { return (this->anime_ui_render[ui_id].Up0()); };
		bool downTex(const size_t ui_id) const { return (this->texture_ui_render[ui_id].Down()); };
		bool downTex0(const size_t ui_id) { return (this->texture_ui_render[ui_id].Down0()); };
		bool downAnime(const size_t ui_id) const { return (this->anime_ui_render[ui_id].Down()); };
		bool downAnime0(const size_t ui_id) { return (this->anime_ui_render[ui_id].Down0()); };
		bool isTouch() const { return (touch_all_num > 0); };
		bool isTouch0() { const bool is_touch = (touch_all_num > 0); touch_all_num = 0; return is_touch; };
		bool isUp() const { return this->is_up_all; };
		bool isUp0() { const bool is_up = this->is_up_all; this->is_up_all = 0; return is_up; };
		bool isDown() const { return this->is_down_all; };
		bool isDown0() { const bool is_down = this->is_down_all; this->is_down_all = 0; return is_down; };
	private:
		int32_t touch_all_num = 0;
		bool is_up_all = false;
		bool is_down_all = false;
		Mouse mouse;

	public:
		
		MainControl& loopEnd() { this->is_loop = 0; return *this; };

		//�e�N�X�`���n
		std::vector<TextureMainData> texture_main_data_render;
		std::vector<TextureUI> texture_ui_render;
		std::vector<AnimeMainData> anime_main_data_render;
		std::vector<AnimeUI> anime_ui_render;

		//std::vector<>

		//�����n
		std::vector<int> font_render;



		//�����n--------------------------------------------------
	public:
		uint8_t rand8(const uint8_t= 0);
		MainControl& srand8(const uint8_t randSeed) { rand_8 = randSeed; return *this; }
		uint8_t rand8_0toMax(const uint8_t i = UINT8_MAX);
		uint32_t rand32();
		MainControl& srand32(const uint32_t randSeed) { rand_32 = randSeed; return *this; }
		int32_t rand32_0toMax(const int32_t i = INT32_MAX);
	private:
		uint8_t rand_8;
		uint32_t rand_32;

	private:

		void checkTouch();

		//�`��X�L�b�v
		bool is_skip = false;

		//�V�[���n
		std::array<std::function<void(MainControl&)>, SCENE_MAX> scene_func = {};
		std::array<ColorRGB, SCENE_MAX> scene_BG = {};
		size_t select_scene = 0;

		//�L�[�{�[�h�̔���
		std::array < int32_t, KEY_MAX_1 > count_key = {};
		std::array < uint8_t, KEY_MAX_1 > click_key = {};
		std::array < uint8_t, KEY_MAX_1 > release_key = {};
		std::array < uint8_t, KEY_MAX_1 > keyconfig = {};

		//�摜
		//size_t count_texture = 0;

		//fps�擾 todo
		int32_t fps = 60;
		
		bool is_change_scene = false;
};

	//���t���[���̃^�b�`�̉ӏ�����͂���
	inline void MainControl::checkTouch()
	{
		this->is_down_all = false;
		this->is_up_all = false;

		//UI�̃^�b�`�񐔂�������
		for (TextureUI &i : texture_ui_render) i.initTouch();
		for (AnimeUI &i : anime_ui_render) i.initTouch();

		//�^�b�`���ꂽ�����擾
		const int32_t check_touch_all_num = asTouchNum();
		int32_t check_touch_mouse_all_num = check_touch_all_num;

		//�}�E�X�̃^�b�`�𓱓�
		if (check_touch_all_num == 0) {
			if (mouse.count() > 0) {
				//�}�E�X�̂����蔻��
				for (TextureUI &j : texture_ui_render) j.touch(mouse.Pos());
				for (AnimeUI &j : anime_ui_render) j.touch(mouse.Pos());
				++check_touch_mouse_all_num;
			}
		}

		//��ʂ̃N���b�N�������[�X
		if (check_touch_mouse_all_num > 0 && this->touch_all_num == 0) this->is_down_all = true;
		if (check_touch_mouse_all_num == 0 && this->touch_all_num > 0) this->is_up_all = true;
		this->touch_all_num = check_touch_mouse_all_num;
		Pos2 touch_pos = {};

		//�^�b�`�̂�
		for (int32_t i = 0; i < check_touch_all_num; ++i) {
			asTouch(i, touch_pos);

			//�^�b�`�̂����蔻��
			for (TextureUI &j : texture_ui_render) j.touch(touch_pos);
			for (AnimeUI &j : anime_ui_render) j.touch(touch_pos);
		}

		//����^�b�`���ꂽ���J�E���g
		for (TextureUI &j : texture_ui_render) j.update();
		for (AnimeUI &j : anime_ui_render) j.update();
	}

	MainControl::~MainControl()
	{
	}

	inline MainControl& MainControl::loop()
	{

		
		return *this;
	}

	inline bool MainControl::isLoop() const
	{

		return is_loop;
	}

	inline MainControl & MainControl::AddScene(const size_t scene_num, const std::function<void(MainControl&)>& add_scene_func)
	{
		scene_BG[scene_num] = this->init_data.colorBG();
		scene_func[scene_num] = add_scene_func;
		return *this;
	}

	inline MainControl & MainControl::AddScene(const size_t scene_num, const std::function<void(MainControl&)>& add_scene_func, const ColorRGB& add_scene_BG)
	{
		scene_BG[scene_num] = add_scene_BG;
		scene_func[scene_num] = add_scene_func;
		return *this;
	}

	inline MainControl & MainControl::scene(const size_t add_select_scene)
	{
		//UI�̃^�b�`�񐔂�������
		for (TextureUI &i : texture_ui_render) i.initTouch();
		for (AnimeUI &i : anime_ui_render) i.initTouch();

		//�w�i�F�ύX
		AsChangeColorBG(scene_BG[add_select_scene]);

		if (add_select_scene < SCENE_MAX) select_scene = add_select_scene;
		is_change_scene = true;
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

		//�t���[�����X�V
		if (!AsLoop()) sceneEnd();

		//�^�b�`���擾
		this->mouse.update();
		this->checkTouch();

		return *this;
	}

	inline MainControl & MainControl::sceneEnd()
	{
		select_scene = 0;
		is_loop = false;
		return *this;
	}

	inline int32_t MainControl::countKey(const uint8_t select_key) const
	{
		return count_key[size_t(select_key)];
	}

	inline uint8_t MainControl::clickKey(const uint8_t select_key) const
	{
		return click_key[size_t(select_key)];
	}

	inline uint8_t MainControl::releaseKey(const uint8_t select_key) const
	{
		return release_key[size_t(select_key)];
	}

	inline uint8_t MainControl::keyConfig(const uint8_t select_key) const
	{
		return keyconfig[size_t(select_key)];
	}

	inline MainControl& MainControl::textureUI_Add(const size_t add_number, const uint8_t add_alpha, const Pos4& add_pos4)
	{
		const TextureUI add_texture_ui(&texture_main_data_render[add_number], add_alpha, add_pos4);
		texture_ui_render.emplace_back(add_texture_ui);
		return *this;
	}

	inline MainControl& MainControl::animeUI_Add(const size_t add_number, const uint8_t add_alpha, const Pos4& add_pos4)
	{
		const AnimeUI add_texture_ui(&anime_main_data_render[add_number], add_alpha, add_pos4);
		anime_ui_render.emplace_back(add_texture_ui);
		return *this;
	}

	inline MainControl & MainControl::textureAdd(const char * const add_name)
	{
		const TextureMainData add_texture(AsLoadTex(add_name));
		texture_main_data_render.emplace_back(add_texture);
		return *this;
	}

	inline MainControl & MainControl::animeAdd(const char * const add_name,const size_t add_num)
	{
		const AnimeMainData add_texture(add_num, AsLoadTex(add_name, add_num));
		anime_main_data_render.emplace_back(add_texture);
		return *this;
	}

	inline MainControl & MainControl::texture(const size_t select_texture)
	{
		texture_ui_render[select_texture].draw();
		return *this;
	}

	inline MainControl & MainControl::anime(const size_t select_texture)
	{
		anime_ui_render[select_texture].fpsUpdate();
		anime_ui_render[select_texture].draw();
		return *this;
	}


	//�R���X�g���N�^----------

	MainControl::MainControl(const MainData& add_init_data)
	{
		AsInit(init_data.title(), init_data.windowSize(), init_data.colorBG());
		const MainData main_init_data(add_init_data.title(), asWindowSizeTrue(add_init_data.windowSize()), add_init_data.colorBG());
		init_data = add_init_data;
		
	}

	MainControl::MainControl(const char* const add_title, const Pos2& add_window_size, const ColorRGB& add_BG_color)
	{
		AsInit(add_title, add_window_size, add_BG_color);
		const MainData add_init_data(add_title, asWindowSizeTrue(add_window_size), add_BG_color);
		init_data = add_init_data;
	}


}
