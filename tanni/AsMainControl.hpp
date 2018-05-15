//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asライブラリ
//
//                    制作者: がっちょ (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
	//キーボードのキーの数
	constexpr size_t KEY_MAX = 255;
	constexpr size_t KEY_MAX_1 = KEY_MAX + 1;

	//シーン数 (デフォルトでは256個)
#if defined(AS_USING_SCENE_MAX)
	constexpr size_t SCENE_MAX = ASLIB_SCENE_MAX;
#else
	constexpr size_t SCENE_MAX = 256;
#endif

	//ゲームパッドの数 (デフォルトでは16台)
#if defined(AS_USING_GAME_PAD_MAX)
	constexpr size_t GAME_PAD_MAX = ASLIB_GAME_PAD_MAX;
#else
	constexpr size_t GAME_PAD_MAX = 16;
#endif

	constexpr size_t TEXTURE_MAX = 10;

	//メイン管理クラス
	class MainControl
	{
	public:
		MainControl(MainData& init_data);
		~MainControl();

		//メインループ
		MainControl& loop();
		bool isLoop();

		//シーン系
		MainControl& AddScene(const size_t scene_num, const std::function<void(MainControl&)>& add_scene_func);
		MainControl& sceneSelect(const size_t add_select_scene);
		MainControl& scenePlay();
		MainControl& sceneEnd();

		//キーボード入力
		int32_t countKey(const uint8_t select_key);
		uint8_t clickKey(const uint8_t select_key);
		uint8_t releaseKey(const uint8_t select_key);
		uint8_t keyConfig(const uint8_t select_key);

		//テクスチャ系
		MainControl& textureAdd(const char* const add_name);
		MainControl& texDraw(const size_t select_texture);
		//std::vector<Texture> texture_render;

		std::vector<AS_Texture> texture_render;

	private:
		
		//基本データ
		MainData * init_pointer = nullptr;

		//ループ系
		bool is_loop = true;

		//シーン系
		std::array<std::function<void(MainControl&)>, SCENE_MAX> scene_func;
		size_t select_scene = -1;

		//キーボードの判定
		std::array < int32_t, KEY_MAX_1 > count_key = {};
		std::array < uint8_t, KEY_MAX_1 > click_key = {};
		std::array < uint8_t, KEY_MAX_1 > release_key = {};
		std::array < uint8_t, KEY_MAX_1 > keyconfig = {};

		//画像
		size_t count_texture = 0;
		
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
		//シーンが選択されていない時の処理
		if (select_scene == -1) {
			sceneEnd();
			return *this;
		}

		scene_func[select_scene](*this);
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

	inline MainControl & MainControl::textureAdd(const char * const add_name)
	{
		//Texture add_texture(add_name);
		AS_Texture add_texture;
		add_texture.handle = AsLoadTex(add_name);

		texture_render.emplace_back(add_texture);

		//add_texture.draw();
		//asStop();
		//texture_render[count_texture] = AsLoadTex(add_name);
		//++count_texture;
		//if (count_texture >= TEXTURE_MAX) count_texture = 0;
		return *this;
	}

	inline MainControl & MainControl::texDraw(const size_t select_texture)
	{
		asTex(texture_render[select_texture].handle);
		return *this;
	}

	MainControl::MainControl(MainData& init_data)
	{
		init_pointer = &init_data;
	}


}
