//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asライブラリ
//
//                    制作者: がっちょ (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
	struct TexSize2
	{
		const OriginatorTexture t;
		const size_t x;
		const size_t y;
		TexSize2(const OriginatorTexture& t_, const size_t x_, const size_t y_) :t(t_), x(x_), y(y_) {}
	};

#if defined(ASLIB_INCLUDE_DL) //DxLib
	//画像を分割ロードする
	std::unique_ptr<OriginatorTexture[]> asLoadTexture(const char* const name, const size_t tex_num_x = 1, const size_t tex_num_y = 1)
	{
		const size_t aslib_load_texture_xy = tex_num_x * tex_num_y;
		std::unique_ptr<OriginatorTexture[]> texs(new OriginatorTexture[aslib_load_texture_xy]);

		for (size_t i = 0; i < aslib_load_texture_xy; ++i) texs[i] = -1;
		if (name == nullptr) return texs;

		const OriginatorTexture tex = DxLib::LoadGraph(name);
		if (tex == -1) return texs;

		int size_x = 0, size_y = 0;
		DxLib::GetGraphSize(tex, &size_x, &size_y);
		DxLib::DeleteGraph(tex);
		if (size_x == 0 || size_y == 0) return texs;
		
		DxLib::LoadDivGraph(name, int(aslib_load_texture_xy), int(tex_num_x), int(tex_num_y), size_x / int(tex_num_x), size_y / int(tex_num_y), &texs[0]);
		return texs;
	}
#else


	//画像読み込み
	inline TexSize2 asLoadTexture(const char* const name, const size_t tex_num_x = 1, const size_t tex_num_y = 1)
	{
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		return TexSize2(s3d::Texture(s3d::Unicode::UTF8ToUTF32(std::string(name))), tex_num_x, tex_num_y);
#elif defined(ASLIB_INCLUDE_OF)
		static OriginatorTexture tex;
		tex.load(name);
		return TexSize2(tex, tex_num_x, tex_num_y);
#elif defined(ASLIB_INCLUDE_TP)
		return TexSize2();
#else //Console
		return TexSize2();
#endif
	}
#endif

	inline void asTextureSize(const OriginatorTexture& id, Pos2& texture_size)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		if (id == -1) { texture_size(0, 0); return; }
		int size_x = 0, size_y = 0;
		DxLib::GetGraphSize(id, &size_x, &size_y);
		texture_size(int32_t(size_x), int32_t(size_y));
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		texture_size(int32_t(id.width()), int32_t(id.height()));
#elif defined(ASLIB_INCLUDE_OF)
		texture_size(int32_t(id.getWidth()), int32_t(id.getHeight()));
#elif defined(ASLIB_INCLUDE_TP)
#else //Console
#endif
	}

	const Pos2 asTextureSize(const OriginatorTexture& id)
	{
		Pos2 p;
		asTextureSize(id, p);
		return p;
	}

#if defined(ASLIB_INCLUDE_S3) //Siv3D
	inline void asTextureType1(const OriginatorTexture& t_, const Pos2& p_, const Pos2& l_, const PosL4& cut_p_, const uint8_t& a_ = (uint8_t)255, const float& r_ = 0.0f)
	{
		t_(cut_p_.x, cut_p_.y, cut_p_.w, cut_p_.h).resized(l_.x, l_.y).rotated(double(r_)).draw(p_.x, p_.y, s3d::Alpha(a_));
	}
#elif defined(ASLIB_INCLUDE_OF)
	inline void asTextureType1(const OriginatorTexture& t_, const Pos2& p_, const Pos2& l_, const PosL4& cut_p_, const uint8_t& a_ = 255, const float& r_ = 0.0f)
	{
		ofTranslate(l_.x / 2, l_.y / 2);
		ofRotateRad(r_);
		ofSetColor(255, 255, 255, int(a_));
		t_.drawSubsection(cut_p_.x, cut_p_.y, cut_p_.w, cut_p_.h, p_.x, p_.y, l_.x, l_.y);
	}
#endif

	inline void asTexture(const OriginatorTexture& tex, const PosA4F& p_, const float& r_, const uint8_t& alpha = 255)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		DxLib::SetDrawBlendMode(1, int(alpha));
		const Pos2 s(asTextureSize(tex));
		DxLib::DrawRotaGraphFast3(int(p_.x), int(p_.y), s.x / 2, s.y / 2, p_.w / s.x, p_.h / s.y, r_, tex, 1);
#else
#if defined(ANIME_TEXTURE_1)

#endif
#endif
	}
	inline void asTexture(const OriginatorTexture& tex, const Pos4& pos, const uint8_t& alpha = 255)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		DxLib::SetDrawBlendMode(1, int(alpha));
		DxLib::DrawExtendGraph(int(pos.x1), int(pos.y1), int(pos.x2), int(pos.y2), tex, TRUE);
#else //Console
#if defined(ANIME_TEXTURE_1)

#endif
#endif
	}

	//画像を管理する
	struct Texture
	{
	private:
#if defined(ANIME_TEXTURE_1)
		OriginatorTexture id;
		size_t turn_id = 1;
#elif defined(ANIME_TEXTURE_2)
		std::unique_ptr<OriginatorTexture[]> id;
#elif defined(ANIME_TEXTURE_3)
		int32_t id;
#endif
		Pos2 pixel_size;
		size_t num = 0;
	public:
		Texture() = default;
#if defined(ANIME_TEXTURE_1)
		Texture(const char* const name_, const size_t x_ = 1, const size_t y_ = 1) :id(asLoadTexture(name_, x_, y_).t), num(x_*y_) 
		{
			//画像サイズ取得
			asTextureSize(this->id, this->pixel_size);
			this->pixel_size.x /= int32_t(x_);
			this->pixel_size.y /= int32_t(y_);
			this->turn_id = size_t(x_);
		}
		Texture& operator()(const char* const name_, const size_t x_ = 1, const size_t y_ = 1)
		{
			id = asLoadTexture(name_, x_, y_).t;
			num = x_ * y_;
			//画像サイズ取得
			asTextureSize(this->id, this->pixel_size);
			this->pixel_size.x /= int32_t(x_);
			this->pixel_size.y /= int32_t(y_);
			this->turn_id = size_t(x_);
			return *this;
		}
#elif defined(ANIME_TEXTURE_2)
		Texture(const char* const name_, const size_t x_ = 1, const size_t y_ = 1) :id(asLoadTexture(name_,x_,y_)), pixel_size(asTextureSize(this->id[0])), num(x_*y_) {}//stdmovea

		Texture& operator()(const char* const name_, const size_t x_ = 1, const size_t y_ = 1)
		{
			id = asLoadTexture(name_, x_, y_);//stdmovea
			pixel_size = asTextureSize(this->id[0]);
			num = x_ * y_;
			return *this;
		}
#elif defined(ANIME_TEXTURE_3)
		Texture(const size_t id_num, const int32_t add_id) {}
#endif

		//--------------------------------------------------
		//描画
		//--------------------------------------------------

		//サイズ 指定なし 透明度 指定あり
		Texture& draw(const size_t anime_size, const uint8_t alpha = 255)
		{
#if defined(ANIME_TEXTURE_1)
			asTextureType1(this->id, Pos2(), this->pixel_size, PosL4(this->pixel_size.x*int32_t(anime_size%this->turn_id), this->pixel_size.y*int32_t(anime_size / this->turn_id), this->pixel_size.x, this->pixel_size.y), alpha);
#elif defined(ANIME_TEXTURE_2)
			asTexture(this->id[anime_size], this->pixel_size, alpha);
#endif
			return *this;
		}
		Texture& draw(const uint8_t alpha = 255) { return this->draw((size_t)0, alpha); }

		//サイズ等倍 位置指定
		Texture& draw(const size_t anime_size, const Pos4& add_pos, const uint8_t alpha=255)
		{
#if defined(ANIME_TEXTURE_1)
			asTextureType1(this->id, Pos2(add_pos.x1, add_pos.y1), Pos2(add_pos.x2 - add_pos.x1, add_pos.y2 - add_pos.y1), PosL4(this->pixel_size.x*int32_t(anime_size%this->turn_id), this->pixel_size.y*int32_t(anime_size / this->turn_id), this->pixel_size.x, this->pixel_size.y), alpha);
#elif defined(ANIME_TEXTURE_2)
			asTexture(this->id[anime_size], add_pos, alpha);
#endif
			return *this;
		}
		Texture& draw(const Pos4& add_pos, const uint8_t alpha=255) { return this->draw((size_t)0, add_pos, alpha); }
		const Texture& draw(const size_t, const PosA4F&, const float, const uint8_t = 255);

		const size_t Num() const { return this->num; };
		const Pos2 pixelSize() const { return this->pixel_size; };
	};

	//ウィンドウ専用
	struct TextureWindow :public Texture {
	private:
		//メッセージを表示するか否か
		bool win_is_on = false;
		//メッセージを終了するか否か
		bool win_is_exit = false;

		Pos2 win_pos{};
		Pos2 win_end_pos{};
		PosL4 win_size_pos{};

		int32_t win_timer = 0;
		bool win_is_timer = false;

		std::u32string win_in32_str{};
		size_t win_str32_timer = 0;
		bool win_is_str32 = false;

		bool win_is_end_timer = false;
		int32_t win_end_timer = 0;
		bool win_is_end_str = true;

		//
		bool win_is_end_texture = false;

		//ウィンドウとともに流される音
		BGM sound;
		//何番目の音を流すか
		int32_t count_sound = 0;
		//音のファイル名
		std::string win_sound_name{};
		//音の拡張子
		std::string win_sound_extension{};
		//音を再生する(実行する)
		bool win_is_sound = false;

		//話している人の名前
		std::string win_speaker_name{};

		//出力する文字列
		std::string win_out_str{};

		//ウィンドウ内の最大行数
		int32_t number_of_lines = 4;

		//ウィンドウのデフォルトサイズ
		Pos4 win_pos_default{};
		//ふちのデフォルトサイズ
		Pos2 win_frame_default{};

		//ウィンドウ内のフォント
		FontMainData font;

		//早送り機能を使用するか
		bool win_is_fast_forward = false;
		//早送りを実行するか
		bool win_is_on_fast_forward = false;
		//一時早送りを実行するか
		bool win_is_on_special_fast_forward = false;

		//文字をクリアするか
		bool win_on_str_clear = true;

		//人物画像を表示するか
		bool win_is_person = false;
		Effect person_effect;
		


	public:
#if defined(ANIME_TEXTURE_1)
		TextureWindow(const char* const name_, const size_t x_ = 1, const size_t y_ = 1) : Texture(name_, x_, y_), font(30) {}
#elif defined(ANIME_TEXTURE_2)
		TextureWindow(const char* const name_, const size_t x_ = 1, const size_t y_ = 1) : Texture(name_, x_, y_), font(30) {}
#endif
		TextureWindow& setPerson(const bool is_) {
			win_is_person = is_;
			return *this;
		}
		TextureWindow& setFastForward(const bool fast_) {
			win_is_fast_forward = fast_;
			return *this;
		}
		TextureWindow& setOnFastForward(const bool fast_) {
			win_is_on_fast_forward = fast_;
			return *this;
		}
		TextureWindow& setFont(FontMainData& font_) {
			font = font_;
			return *this;
		}
		TextureWindow& setLine(const int32_t var_) {
			number_of_lines = var_+1;
			font = FontMainData((PosL4(win_pos_default).h - win_frame_default.y * 2) / number_of_lines, font.fontName());
			return *this;
		}
		TextureWindow& setPos(const Pos4& pos_) {
			win_pos_default = pos_;
			return *this;
		}
		TextureWindow& setFrame(const Pos2& pos_) {
			win_frame_default = pos_;
			return *this;
		}
		const bool isWindow() const { return win_is_on; }
		Texture& setName(const char* const name_) {
			win_speaker_name = name_;
			return *this;
		}
		TextureWindow& setSound(const char* const name_, const char* const name2_=u8"mp3") {
			win_sound_name = name_;
			win_sound_extension = name2_;
			win_is_sound = true;
			return *this;
		}

		TextureWindow& playSound() {
			if (!win_is_sound || win_sound_name[0] == 0) return *this;
			char sound_str[64];
			snprintf(sound_str, 64, "%s%d.%s", win_sound_name.c_str(),count_sound, win_sound_extension.c_str());
			sound.set(sound_str);
			sound.play();
			win_is_sound = false;
			return *this;
		}
		TextureWindow& drawWindow(const PosL4& p_, const Pos2& p2_,Texture& texture) {
			if (this->Num() != 9) return *this;
			this->win_size_pos = p_;
			Pos2 p2_2(p2_);
			
			if (p2_.x < 0) p2_2.x = 0;
			if (p2_.y < 0) p2_2.y = 0;
			if (p2_.x > p_.w / 3) p2_2.x = p_.w / 3;
			if (p2_.y > p_.h / 3) p2_2.y = p_.h / 3;

			this->win_pos(this->win_size_pos.x + p2_2.x, this->win_size_pos.y + p2_2.y);
			this->win_end_pos(this->win_size_pos.x + this->win_size_pos.w - 2 * p2_2.x, this->win_size_pos.y + this->win_size_pos.h - 2 * p2_2.y);
			texture.draw(0, Pos4(PosL4(this->win_size_pos.x, this->win_size_pos.y, p2_2.x, p2_2.y)));
			texture.draw(1, Pos4(PosL4(this->win_size_pos.x + p2_2.x, this->win_size_pos.y, this->win_size_pos.w - 2 * p2_2.x, p2_2.y)));
			texture.draw(2, Pos4(PosL4(this->win_size_pos.x + this->win_size_pos.w - p2_2.x, this->win_size_pos.y, p2_2.x, p2_2.y)));
			texture.draw(3, Pos4(PosL4(this->win_size_pos.x, this->win_size_pos.y + p2_2.y, p2_2.x, this->win_size_pos.h - 2 * p2_2.y)));
			texture.draw(4, Pos4(PosL4(this->win_size_pos.x + p2_2.x, this->win_size_pos.y + p2_2.y, this->win_size_pos.w - 2 * p2_2.x, this->win_size_pos.h - 2 * p2_2.y)));
			texture.draw(5, Pos4(PosL4(this->win_size_pos.x + this->win_size_pos.w - p2_2.x, this->win_size_pos.y + p2_2.y, p2_2.x, this->win_size_pos.h - 2 * p2_2.y)));
			texture.draw(6, Pos4(PosL4(this->win_size_pos.x, this->win_size_pos.y + this->win_size_pos.h - p2_2.y, p2_2.x, p2_2.y)));
			texture.draw(7, Pos4(PosL4(this->win_size_pos.x + p2_2.x, this->win_size_pos.y + this->win_size_pos.h - p2_2.y, this->win_size_pos.w - 2 * p2_2.x, p2_2.y)));
			texture.draw(8, Pos4(PosL4(this->win_size_pos.x + this->win_size_pos.w - p2_2.x, this->win_size_pos.y + this->win_size_pos.h - p2_2.y, p2_2.x, p2_2.y)));
			return *this;
		}
		TextureWindow& drawWindow(const PosL4& p_, const Pos2& p2_) { return drawWindow(p_, p2_, *this); }
		TextureWindow& drawWindow(const PosL4& p_) { return drawWindow(p_, this->pixelSize(), *this); }
		TextureWindow& drawWindow() { return drawWindow(win_pos_default, win_frame_default, *this); }
		TextureWindow& drawWindow(Texture& texture_) { return drawWindow(win_pos_default, win_frame_default, texture_); }

		TextureWindow& initWindow() {
			win_is_on = true;
			if (win_sound_name[0] != 0) sound.stop();

			win_timer = 0;
			win_is_timer = false;

			win_str32_timer = 0;
			count_sound = 0;
			win_is_sound = true;

			win_is_end_timer = false;
			win_end_timer = 0;
			win_is_end_str = true;
			win_is_end_texture = false;

			win_out_str = u8"";
			return *this;
		}
		TextureWindow& initWindow(const bool is_init_) { return (is_init_) ? this->initWindow() : *this; }
		TextureWindow& setString32(const char* const str8_) {
			if (str8_ == nullptr) return *this;
			win_in32_str = utf32(str8_);
			win_is_str32 = true;
			return this->initWindow();
		}
		TextureWindow& printName(FontMainData& font_) {
			drawWindow(PosL4(win_pos_default.x1, win_pos_default.y1 - (win_pos_default.y2 - win_pos_default.y1) / number_of_lines - win_frame_default.y * 2, (win_pos_default.x2 - win_pos_default.x1) / 3, (win_pos_default.y2 - win_pos_default.y1) / number_of_lines + win_frame_default.y * 2), win_frame_default);
			font_.draw(win_speaker_name.c_str(), Pos2(win_pos.x, win_pos_default.y1 - (win_pos_default.y2 - win_pos_default.y1) / number_of_lines - win_frame_default.y), Color(255, 255, 255));
			return *this;
		}
		TextureWindow& printName() { return printName(this->font); }

		const std::string readString(const char* const str_) {
			std::ifstream ifs(str_);
			if (ifs.fail()) return std::string(u8"(データを読み込めませんでした)");
			std::istreambuf_iterator<char> it(ifs);
			std::istreambuf_iterator<char> last;
			return std::string(it, last);
		}
		TextureWindow& readSetString32(const char* const str_) { return setString32(this->readString(str_).c_str()); }

		TextureWindow& setString(const char* const str8_) {
			win_out_str = str8_;
			win_is_str32 = false;
			return *this;
		}
		TextureWindow& update(const int32_t count_) {
			++win_timer;
			if (win_timer >= count_) {
				win_timer = 0;
				win_is_timer = true;
			}
			else {
				win_is_timer = false;
			}
			return *this;
		}
		TextureWindow& endString() {
			win_is_str32 = false;
			win_is_end_str = true;
			win_is_on_fast_forward = false;
			win_is_on_special_fast_forward = false;
			win_is_exit = true;
			return *this;
		}
		TextureWindow& writeString() {
			if (!win_is_timer || !win_is_str32) return *this;

			do {
				switch (win_in32_str[win_str32_timer]) {
				case U'\0':return this->endString();
				case U'\\':

					++win_str32_timer;
					switch (win_in32_str[win_str32_timer]) {
					case U'\0':return this->endString();
					case U'!':
						win_is_str32 = false;
						win_is_end_str = true;
						win_is_on_fast_forward = false;
						win_is_on_special_fast_forward = false;

						win_on_str_clear = false;
						++win_str32_timer;
						break;
					case U'#':
						win_is_str32 = false;
						win_is_end_str = true;
						win_is_on_fast_forward = false;
						win_is_on_special_fast_forward = false;
						++count_sound;
						++win_str32_timer;
						if (win_in32_str[win_str32_timer] == U'\n') ++win_str32_timer;
						return *this;
					case U'>':
						++win_str32_timer;
						win_is_on_special_fast_forward = true;
						break;
					case U'<':
						++win_str32_timer;
						win_is_on_special_fast_forward = false;
						break;
					default:
						win_out_str += utf8(win_in32_str[win_str32_timer]);
						++win_str32_timer;
						break;
					}
					break;

				default:
					win_out_str += utf8(win_in32_str[win_str32_timer]);
					++win_str32_timer;
					break;
				}
			} while (win_is_on_fast_forward || win_is_on_special_fast_forward);
			return *this;
		}
		//終端記号をつける
		TextureWindow& updateEnd(const int32_t count_) {
			++win_end_timer;
			//タイマーがたまったら
			if (win_end_timer >= count_) {
				//タイマー初期化
				win_end_timer = 0;
				//タイマーたまったフラグ
				win_is_end_timer = true;
				//終端記号入れ替え
				if (win_is_end_str) win_is_end_str = false;
				else win_is_end_str = true;
			}
			else {
				//タイマーたまってないフラグ
				win_is_end_timer = false;
			}
			return *this;
		}
		TextureWindow& writeEndString(const char* const end_str_) {
			if (!win_is_end_timer || win_is_str32) return *this;
			const size_t str_count = strlen(end_str_);
			if (win_is_end_str) { for (size_t i = 0; i < str_count; ++i) win_out_str.pop_back(); }
			else win_out_str += end_str_;
			return *this;
		}
		TextureWindow& drawEndTexture(Texture& texture_, const Pos2& p_) {
			//表示機関に指定した画像を描画
			if (win_is_end_texture) texture_.draw(Pos4(win_end_pos.x - p_.x / 4, win_end_pos.y - p_.y / 4, win_end_pos.x, win_end_pos.y));

			if (!win_is_end_timer || win_is_str32) return *this;
			if (win_is_end_str) win_is_end_texture = false;
			else win_is_end_texture = true;
			return *this;
		}
		TextureWindow& drawEndTexture(Texture& texture_) {
			return drawEndTexture(texture_, Pos2(this->win_size_pos.h, this->win_size_pos.h));
		}
		TextureWindow& drawEndAnime(Texture& texture_, const Pos2& p_) {
			if (win_is_str32) return *this;
			static size_t draw_id = 0;
			//指定した画像を描画
			texture_.draw(draw_id,Pos4(win_end_pos.x - p_.x, win_end_pos.y - p_.y, win_end_pos.x, win_end_pos.y));
			if (!win_is_end_timer) return *this;
			if (win_is_end_str) {
				++draw_id;
				if (draw_id >= texture_.Num()) draw_id = 0;
			}
			return *this;
		}
		TextureWindow& drawEndAnime(Texture& texture_) {
			return drawEndAnime(texture_, Pos2(this->win_size_pos.h/2, this->win_size_pos.h/2));
		}
		TextureWindow& printString(FontMainData& font_, const Color& color_ = { 255,255,255,255 }) {
			font_.draw(win_out_str.c_str(), this->win_pos, color_);
			return *this;
		}
		TextureWindow& printString(const Color& color_ = { 255,255,255,255 }) { return printString(font, color_); }
		TextureWindow& next(const bool is_next) {
			if (!is_next) return *this;
			if (win_is_str32) {
				win_is_on_fast_forward = true;
				return *this;
			}
			
			if (win_sound_name[0] != 0) sound.stop();

			if (win_is_exit) {
				win_is_on = false;
				win_is_exit = false;
			}
			else win_is_sound = true;

			if(win_on_str_clear) this->win_out_str = u8"";
			win_on_str_clear = true;
			win_is_str32 = true;
			win_is_end_str = true;
			win_is_end_texture = false;
			return *this;
		}
		TextureWindow& next(const std::vector<bool>& is_next) { for (size_t i = 0; i < is_next.size(); ++i) this->next(is_next[i]); return *this; }
		TextureWindow& next(const bool* const is_next, const size_t size_) { if (is_next == nullptr) return *this; for (size_t i = 0; i < size_; ++i) this->next(is_next[i]); return *this; }
		TextureWindow& drawPerson(Texture& t_ ) {
			if (!win_is_person) return *this;

			t_.draw(PosA4(asWindowSize().x / 2, asWindowSize().y / 2, asWindowSize().y* t_.pixelSize().x / t_.pixelSize().y, asWindowSize().y));
			return *this;
		}


	};




	//複数の画像UIの情報を管理する
	struct TextureUI
	{
	private:
		Texture* id;
		size_t anime_count = 0;
		//毎フレーム
		size_t fps_size = 2;
		size_t fps_count = 0;

		//画像透明度
		uint8_t alpha = 255;

		//画像回転率
		float rota = 0.0f;

		//四角形描画位置
		Pos4 pos4;
		PosA4F pR;

		//あたり判定
		Counter counter;

		//タッチ数
		int32_t touch_num = 0;
	public:
		TextureUI() = default;
		TextureUI(Texture* const add_tmd, const uint8_t add_alpha, const Pos4& add_pos4) :id(add_tmd), alpha(add_alpha), pos4(add_pos4) {}
		TextureUI(Texture* const add_tmd, const uint8_t add_alpha, const PosA4F& add_pR) : id(add_tmd), alpha(add_alpha), pR(add_pR) {}
		TextureUI & fpsUpdate();

		//出力
		const Texture* const Point() const { return this->id; };
		uint8_t Alpha() const { return this->alpha; };
		Pos4 Pos() const { return this->pos4; };
		PosA4F PosF() const { return this->pR; };
		int32_t Touch() const { return this->touch_num; };
		int32_t Touch0() { const int32_t num = this->touch_num; this->touch_num = 0; return num; };

		//カウンター出力
		bool Down() const { return counter.Down(); };
		bool Up() const { return counter.Up(); };
		int32_t Count() const { return counter.Count(); };
		bool Down0() { return counter.Down0(); };
		bool Up0() { return counter.Up0(); };
		int32_t Count0() { return counter.Count0(); };

		TextureUI& touch(const Pos2&);
		TextureUI& initTouch() { this->touch_num = 0; return *this; };

		TextureUI& p() { return *this; }

		//
		//TextureUI& setRota(const float r_) { rota = r_; return *this; }
		TextureUI& setRota(const float r_, const float r_2) {
			const float new_r = (rota - r_);
			
			if (new_r > abs(r_2)) rota -= abs(r_2);
			else if (new_r < -abs(r_2)) rota += abs(r_2);
			else rota += new_r;
			//rota = r_;
			return *this;
		}
		TextureUI& addRota(const float r_) { rota += r_; return *this; }
		const float Rota() const { return this->rota; };

		TextureUI& setUI(Texture* const add_tmd, const uint8_t add_alpha, const PosA4F& add_pR) { id = add_tmd; alpha = add_alpha; pR = add_pR; return *this; }
		TextureUI& setPosF(const PosA4F& pR_) { pR = pR_; return *this; }
		bool isOutWindowF() {
			const Pos2F w2(asWindowSizeF()); const Pos4F p4r(pR);
			if (p4r.x2<0.0f || p4r.y2<0.0f || p4r.x1>w2.x || p4r.y1>w2.y) return true;
			return false;
		}

		//大きさ加算
		TextureUI& addSizeF(const Pos2F& p2_) { pR.w += p2_.x; pR.h += p2_.y; return *this; }
		TextureUI& addSizeF(const Pos2F& p2_, const Pos2F& p2_2) { if (pR.w < p2_2.x)pR.w += p2_.x; if (pR.h < p2_2.y)pR.h += p2_.y; return *this; }
		TextureUI& addPosF(const Pos2F& p2_) { pR.x += p2_.x; pR.y += p2_.y; return *this; }
		TextureUI& addPosF(const float p2_xy) { pR.x += p2_xy; pR.y += p2_xy; return *this; }
		TextureUI& addPosF(const float p2_x, const float p2_y) { pR.x += p2_x; pR.y += p2_y; return *this; }
		TextureUI& setPosF(const Pos2F& p2_) { if (pR.x < 0.0f) pR.x = 0.0f; if (pR.y < 0.0f) pR.y = 0.0f; if (pR.x > p2_.x) pR.x = p2_.x; if (pR.y > p2_.y) pR.y = p2_.y; return *this; }

		//描画
		TextureUI& draw() { this->id->draw(anime_count, pos4, alpha); return *this; };
		TextureUI& draw(const uint8_t alpha_) { this->id->draw(anime_count, pos4, alpha_); return *this; };
		TextureUI& draw(const uint8_t alpha_, const Pos4 pos_) { this->id->draw(anime_count, pos_, alpha_); return *this; };
		TextureUI& draw(const Pos4 pos_) { this->id->draw(anime_count, pos_, alpha); return *this; };
		TextureUI& draw(const Pos4 pos_, const uint8_t alpha_) { this->id->draw(anime_count, pos_, alpha_); return *this; };

		TextureUI& drawF() { this->id->draw(anime_count, Pos4(pR), alpha); return *this; };
		TextureUI& drawF(const uint8_t alpha_) { this->id->draw(anime_count, Pos4(pR), alpha_); return *this; };
		TextureUI& drawF(const uint8_t alpha_, const PosA4F pR_) { this->id->draw(anime_count, Pos4(pR_), alpha_); return *this; };
		TextureUI& drawF(const PosA4F pR_) { this->id->draw(anime_count, Pos4(pR), alpha); return *this; };
		TextureUI& drawF(const PosA4F pR_, const uint8_t alpha_) { this->id->draw(anime_count, Pos4(pR), alpha_); return *this; };

		TextureUI& drawRF() { this->id->draw(anime_count, Pos4(pR), rota, alpha); return *this; };
		TextureUI& drawRF(const uint8_t alpha_) { this->id->draw(anime_count, Pos4(pR), rota, alpha_); return *this; };
		TextureUI& drawRF(const uint8_t alpha_, const PosA4F pR_) { this->id->draw(anime_count, Pos4(pR_), rota, alpha_); return *this; };
		TextureUI& drawRF(const PosA4F pR_) { this->id->draw(anime_count, Pos4(pR), rota, alpha); return *this; };
		TextureUI& drawRF(const PosA4F pR_, const uint8_t alpha_) { this->id->draw(anime_count, Pos4(pR), rota, alpha_); return *this; };

		TextureUI& drawA(const Pos2 pos2, const uint8_t alpha_) {
			static Pos4 aspect_pos;
			const Pos2 posWS = this->id->pixelSize();
			aspect_pos.x2 = int32_t(posWS.x*pos2.y / float(posWS.y));
			if (aspect_pos.x2 > pos2.x) {
				aspect_pos.x1 = 0;
				aspect_pos.x2 = pos2.x;
				aspect_pos.y2 = int32_t(posWS.y*pos2.x / float(posWS.x));
				aspect_pos.y1 = ((pos2.y - aspect_pos.y2) >> 1);
				aspect_pos.y2 += ((pos2.y - aspect_pos.y2) >> 1);
			}
			else {
				aspect_pos.y1 = 0;
				aspect_pos.y2 = pos2.y;
				aspect_pos.x1 = ((pos2.x - aspect_pos.x2) >> 1);
				aspect_pos.x2 += ((pos2.x - aspect_pos.x2) >> 1);
			}
			this->id->draw(anime_count, aspect_pos, alpha_); return *this;
		};

		//タッチカウント
		TextureUI& update() {
			this->initTouch();
				//タッチされた数を取得
				const size_t check_touch_all_num = asTouchNum();

				//マウスのタッチを導入
				const Mouse mouse;
				if (check_touch_all_num == 0 && mouse.count() > 0) this->touch(mouse.Pos());

				//画面のクリック＆リリース
				Pos2 touch_pos;
				//タッチのみ
				for (int32_t i = 0; i < check_touch_all_num; ++i) {
					asTouch(i, touch_pos);
					//タッチのあたり判定
					this->touch(touch_pos);
				}
				//何回タッチされたかカウント
				this->counter.update(this->touch_num);
				return *this;
		}
	};

	inline TextureUI& TextureUI::fpsUpdate()
	{
		if (fps_count == SIZE_MAX) return *this;
		++fps_count;

		if (fps_count == fps_size) {
			fps_count = 0;
			++anime_count;
			if (anime_count >= this->id->Num()) anime_count = 0;
		}

		return *this;
	}

	inline TextureUI& TextureUI::touch(const Pos2& add_pos)
	{
		bool is_touch = false;
		const Pos4 p(pos4.x1 - add_pos.x, pos4.y1 - add_pos.y, pos4.x2 - add_pos.x, pos4.y2 - add_pos.y);

		//タッチのあたり判定
		if (p.x1 <= 0 && p.y1 <= 0 && p.x2 >= 0 && p.y2 >= 0) is_touch = true;
		else if (p.x1 > 0 && p.y1 > 0 && p.x2 < 0 && p.y2 < 0) is_touch = true;

		//タッチの数をカウント
		if (is_touch && this->touch_num != INT32_MAX) ++this->touch_num;
		return *this;
	}



	//サイズ等倍 位置指定 回転指定あり
	inline const Texture& Texture::draw(const size_t anime_size, const PosA4F& add_pos, const float r_, const uint8_t alpha)
	{
#if defined(ANIME_TEXTURE_1)
		const Pos4 add_pos_(add_pos);
		asTextureType1(this->id, Pos2(add_pos_.x1, add_pos_.y1), Pos2(add_pos.w, add_pos.h), PosL4(this->pixel_size.x*int32_t(anime_size%this->turn_id), this->pixel_size.y*int32_t(anime_size / this->turn_id), this->pixel_size.x, this->pixel_size.y), alpha, r_);
#elif defined(ANIME_TEXTURE_2)
		asTexture(this->id[anime_size], add_pos,r_, alpha);
#endif
		return *this;
	}
}