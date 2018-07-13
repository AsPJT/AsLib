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
		if (name == nullptr) return nullptr;
		const OriginatorTexture tex = DxLib::LoadGraph(name);
		if (tex == -1) return nullptr;
		int size_x = 0, size_y = 0;
		DxLib::GetGraphSize(tex, &size_x, &size_y);
		DxLib::DeleteGraph(tex);
		if (size_x == 0 || size_y == 0) return nullptr;

		std::unique_ptr<OriginatorTexture[]> texs(new OriginatorTexture[tex_num_x * tex_num_y]);
		DxLib::LoadDivGraph(name, int(tex_num_x * tex_num_y), int(tex_num_x), int(tex_num_y), size_x / int(tex_num_x), size_y / int(tex_num_y), &texs[0]);
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
		Texture(const size_t id_num, const TexSize2& add_id) :id(add_id.t), num(id_num)
		{
			//画像サイズ取得
			asTextureSize(this->id, this->pixel_size);
			this->pixel_size.x /= int32_t(add_id.x);
			this->pixel_size.y /= int32_t(add_id.y);
			this->turn_id = size_t(add_id.x);
		}
		Texture(const TexSize2& add_id) :id(add_id.t), num(1)
		{
			//画像サイズ取得
			asTextureSize(this->id, this->pixel_size);
			this->pixel_size.x /= int32_t(add_id.x);
			this->pixel_size.y /= int32_t(add_id.y);
			this->turn_id = size_t(add_id.x);
		}
		Texture& operator()(const size_t id_num, const TexSize2& add_id)
		{
			id=add_id.t;
			num = id_num;
			//画像サイズ取得
			asTextureSize(this->id, this->pixel_size);
			this->pixel_size.x /= int32_t(add_id.x);
			this->pixel_size.y /= int32_t(add_id.y);
			this->turn_id = size_t(add_id.x);
			return *this;
		}
		Texture& operator()(const TexSize2& add_id)
		{
			id = add_id.t;
			num = 1;
			//画像サイズ取得
			asTextureSize(this->id, this->pixel_size);
			this->pixel_size.x /= int32_t(add_id.x);
			this->pixel_size.y /= int32_t(add_id.y);
			this->turn_id = size_t(add_id.x);
			return *this;
		}
#elif defined(ANIME_TEXTURE_2)
		Texture(const size_t id_num, std::unique_ptr<OriginatorTexture[]>&& add_id) : id(std::move(add_id)), pixel_size(asTextureSize(this->id[0])), num(id_num) {}
		Texture(std::unique_ptr<OriginatorTexture[]>&& add_id) : id(std::move(add_id)), pixel_size(asTextureSize(this->id[0])), num(1) {}
		Texture& operator()(const size_t id_num, std::unique_ptr<OriginatorTexture[]>&& add_id)
		{
			id = std::move(add_id);
			pixel_size = asTextureSize(this->id[0]);
			num = id_num;
			return *this;
		}
		Texture& operator()(std::unique_ptr<OriginatorTexture[]>&& add_id)
		{
			id = std::move(add_id);
			pixel_size = asTextureSize(this->id[0]);
			num = 1;
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
		Pos2 win_pos{};

		int32_t win_timer = 0;
		bool win_is_timer = false;

		std::u32string win_in32_str{};
		size_t win_str32_timer = 0;
		bool win_is_str32 = false;

		std::string win_out_str{};
	public:
#if defined(ANIME_TEXTURE_1)
		TextureWindow(const size_t id_num, const TexSize2& add_id) : Texture(id_num, add_id) {}
		TextureWindow(const TexSize2& add_id) : Texture(add_id) {}
#elif defined(ANIME_TEXTURE_2)
		TextureWindow(const size_t id_num, std::unique_ptr<OriginatorTexture[]>&& add_id) : Texture(id_num, std::move(add_id)) {}
		TextureWindow(std::unique_ptr<OriginatorTexture[]>&& add_id) : Texture(std::move(add_id)) {}
#endif
		TextureWindow& drawWindow(const PosL4& p_) {
			if (this->Num() != 9) return *this;
			this->win_pos(p_.x + this->pixelSize().x, p_.y + this->pixelSize().y);
			this->draw(0, Pos4(PosL4(p_.x, p_.y, this->pixelSize().x, this->pixelSize().y)));
			this->draw(1, Pos4(PosL4(p_.x + this->pixelSize().x, p_.y, p_.w - 2 * this->pixelSize().x, this->pixelSize().y)));
			this->draw(2, Pos4(PosL4(p_.x + p_.w - this->pixelSize().x, p_.y, this->pixelSize().x, this->pixelSize().y)));
			this->draw(3, Pos4(PosL4(p_.x, p_.y + this->pixelSize().y, this->pixelSize().x, p_.h - 2 * this->pixelSize().y)));
			this->draw(4, Pos4(PosL4(p_.x + this->pixelSize().x, p_.y + this->pixelSize().y, p_.w - 2 * this->pixelSize().x, p_.h - 2 * this->pixelSize().y)));
			this->draw(5, Pos4(PosL4(p_.x + p_.w - this->pixelSize().x, p_.y + this->pixelSize().y, this->pixelSize().x, p_.h - 2 * this->pixelSize().y)));
			this->draw(6, Pos4(PosL4(p_.x, p_.y + p_.h - this->pixelSize().y, this->pixelSize().x, this->pixelSize().y)));
			this->draw(7, Pos4(PosL4(p_.x + this->pixelSize().x, p_.y + p_.h - this->pixelSize().y, p_.w - 2 * this->pixelSize().x, this->pixelSize().y)));
			this->draw(8, Pos4(PosL4(p_.x + p_.w - this->pixelSize().x, p_.y + p_.h - this->pixelSize().y, this->pixelSize().x, this->pixelSize().y)));
			return *this;
		}
		TextureWindow& drawWindow(const PosL4& p_,const Pos2& p2_) {
			if (this->Num() != 9) return *this;
			this->win_pos(p_.x + p2_.x, p_.y + p2_.y);
			this->draw(0, Pos4(PosL4(p_.x, p_.y, p2_.x, p2_.y)));
			this->draw(1, Pos4(PosL4(p_.x + p2_.x, p_.y, p_.w - 2 * p2_.x, p2_.y)));
			this->draw(2, Pos4(PosL4(p_.x + p_.w - p2_.x, p_.y, p2_.x, p2_.y)));
			this->draw(3, Pos4(PosL4(p_.x, p_.y + p2_.y, p2_.x, p_.h - 2 * p2_.y)));
			this->draw(4, Pos4(PosL4(p_.x + p2_.x, p_.y + p2_.y, p_.w - 2 * p2_.x, p_.h - 2 * p2_.y)));
			this->draw(5, Pos4(PosL4(p_.x + p_.w - p2_.x, p_.y + p2_.y, p2_.x, p_.h - 2 * p2_.y)));
			this->draw(6, Pos4(PosL4(p_.x, p_.y + p_.h - p2_.y, p2_.x, p2_.y)));
			this->draw(7, Pos4(PosL4(p_.x + p2_.x, p_.y + p_.h - p2_.y, p_.w - 2 * p2_.x, p2_.y)));
			this->draw(8, Pos4(PosL4(p_.x + p_.w - p2_.x, p_.y + p_.h - p2_.y, p2_.x, p2_.y)));
			return *this;
		}

		TextureWindow& setString32(const char* const str8_) {
			win_in32_str = utf32(str8_);
			win_is_str32 = true;
			win_str32_timer = 0;
			win_out_str = u8"";
			return *this;
		}
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
		TextureWindow& writeString() {
			if (!win_is_timer || !win_is_str32) return *this;
			win_out_str += utf8(win_in32_str[win_str32_timer]);
			++win_str32_timer;
			if (win_str32_timer >= win_in32_str.size()) win_is_str32 = false;
			return *this;
		}
		TextureWindow& printString(FontMainData& font_) {
			font_.draw(win_out_str.c_str(), this->win_pos, Color(255,255,255));
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
				const int32_t check_touch_all_num = asTouchNum();

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