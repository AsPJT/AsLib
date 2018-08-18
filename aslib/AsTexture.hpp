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
	//画像を分割ロードする
	std::unique_ptr<OriginatorTexture[]> asLoadTexture(const char* const name, const size_t tex_num_x = 1, const size_t tex_num_y = 1,const bool a_=true)
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
	inline OriginatorTexture asLoadTexture(const char* const name, const size_t tex_num_x = 1, const size_t tex_num_y = 1)
	{
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		return s3d::Texture(s3d::Unicode::UTF8ToUTF32(name));
#elif defined(ASLIB_INCLUDE_OF)
		static OriginatorTexture tex;
		tex.load(name);
		return tex;
#elif defined(ASLIB_INCLUDE_TP)
		return 0;
#else //Console
		return 0;
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

	inline void asTexture(const OriginatorTexture& tex, const PosA4F& p_, const float& r_, const uint8_t& alpha = 255, const bool is_a_ = true)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		DxLib::SetDrawBlendMode(1, int(alpha));
		const Pos2 s(asTextureSize(tex));
		DxLib::DrawRotaGraphFast3(int(p_.x), int(p_.y), s.x / 2, s.y / 2, p_.w / s.x, p_.h / s.y, r_, tex, (is_a_) ? TRUE : FALSE);
#else
#if defined(ANIME_TEXTURE_1)

#endif
#endif
	}
	inline void asTexture(const OriginatorTexture& tex, const Pos4& pos, const uint8_t& alpha = 255, const bool is_a_ = true)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		DxLib::SetDrawBlendMode(1, int(alpha));
		DxLib::DrawExtendGraph(int(pos.x1), int(pos.y1), int(pos.x2), int(pos.y2), tex, (is_a_) ? TRUE : FALSE);
#else //Console
#if defined(ANIME_TEXTURE_1)

#endif
#endif
	}

	//画像を管理する
	struct AsTexture
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
		Pos2 before_pixel_size;
		Pos2 pixel_size;
		size_t num = 0;
		size_t num_x = 0;
		size_t num_y = 0;
		bool is_alpha = true;
	public:
		AsTexture() = default;
		~AsTexture() { 
#if defined(ASLIB_INCLUDE_DL)
			for (size_t i = 0; i < num; ++i) DxLib::DeleteGraph(id[i]);
#endif
		}
#if defined(ANIME_TEXTURE_1)
		AsTexture(const char* const name_, const size_t x_ = 1, const size_t y_ = 1, const bool a_ = true) :id(asLoadTexture(name_, x_, y_)), num(x_*y_), num_x(x_), num_y(y_), is_alpha(a_)
		{
			//画像サイズ取得
			asTextureSize(this->id, this->pixel_size);
			this->pixel_size.x /= int32_t(x_);
			this->pixel_size.y /= int32_t(y_);
			this->turn_id = size_t(x_);
		}
		AsTexture& operator()(const char* const name_, const size_t x_ = 1, const size_t y_ = 1, const bool a_ = true)
		{
			id = asLoadTexture(name_, x_, y_);
			num = x_ * y_;
			num_x = x_;
			num_y = y_;
			is_alpha = a_;
			//画像サイズ取得
			asTextureSize(this->id, this->pixel_size);
			this->pixel_size.x /= int32_t(x_);
			this->pixel_size.y /= int32_t(y_);
			this->turn_id = size_t(x_);
			return *this;
		}
#elif defined(ANIME_TEXTURE_2)
		AsTexture(const char* const name_, const size_t x_ = 1, const size_t y_ = 1, const bool a_ = true) :id(asLoadTexture(name_,x_,y_)), pixel_size(asTextureSize(this->id[0])), num(x_*y_), num_x(x_), num_y(y_), is_alpha(a_) {}//stdmovea
		AsTexture& operator()(const char* const name_, const size_t x_ = 1, const size_t y_ = 1, const bool a_ = true)
		{
#if defined(ASLIB_INCLUDE_DL)
			//以前のデータを削除
			for (size_t i = 0; i < num; ++i) DxLib::DeleteGraph(id[i]);
#endif
			id = asLoadTexture(name_, x_, y_);//stdmovea
			pixel_size = asTextureSize(this->id[0]);
			num = x_ * y_;
			num_x = x_;
			num_y = y_;
			is_alpha = a_;
			return *this;
		}
#elif defined(ANIME_TEXTURE_3)
		AsTexture(const size_t id_num, const int32_t add_id) {}
#endif

		//--------------------------------------------------
		//描画
		//--------------------------------------------------

		//サイズ 指定なし 透明度 指定あり
		AsTexture& draw(const size_t anime_size, const uint8_t alpha = 255)
		{
#if defined(ANIME_TEXTURE_1)
			asTextureType1(this->id, Pos2(), this->pixel_size, PosL4(this->pixel_size.x*int32_t(anime_size%this->turn_id), this->pixel_size.y*int32_t(anime_size / this->turn_id), this->pixel_size.x, this->pixel_size.y), alpha);
#elif defined(ANIME_TEXTURE_2)
			asTexture(this->id[anime_size], this->pixel_size, alpha, is_alpha);
#endif
			return *this;
		}
		AsTexture& draw(const uint8_t alpha = 255) { return this->draw((size_t)0, alpha); }

		//サイズ等倍 位置指定
		AsTexture& draw(const size_t anime_size, const Pos4& add_pos, const uint8_t alpha=255)
		{
#if defined(ANIME_TEXTURE_1)
			asTextureType1(this->id, Pos2(add_pos.x1, add_pos.y1), Pos2(add_pos.x2 - add_pos.x1, add_pos.y2 - add_pos.y1), PosL4(this->pixel_size.x*int32_t(anime_size%this->turn_id), this->pixel_size.y*int32_t(anime_size / this->turn_id), this->pixel_size.x, this->pixel_size.y), alpha);
#elif defined(ANIME_TEXTURE_2)
			asTexture(this->id[anime_size], add_pos, alpha, is_alpha);
#endif
			return *this;
		}
		AsTexture& draw(const Pos4& add_pos, const uint8_t alpha=255) { return this->draw((size_t)0, add_pos, alpha); }
		const AsTexture& draw(const size_t, const PosA4F&, const float, const uint8_t = 255);


		//サイズ等倍 位置指定
		AsTexture& drawArea(const size_t anime_size, const Pos4& add_pos, const uint8_t alpha = 255, Pos4 area_ = aslib_default_area)
		{
#if defined(ASLIB_INCLUDE_S3)
			s3d::ViewportBlock2D area(area_.x1, area_.y1, area_.x2 - area_.x1, area_.y2 - area_.y1);
#endif
#if defined(ANIME_TEXTURE_1)
			asTextureType1(this->id, Pos2(add_pos.x1, add_pos.y1), Pos2(add_pos.x2 - add_pos.x1, add_pos.y2 - add_pos.y1), PosL4(this->pixel_size.x*int32_t(anime_size%this->turn_id), this->pixel_size.y*int32_t(anime_size / this->turn_id), this->pixel_size.x, this->pixel_size.y), alpha);
#elif defined(ANIME_TEXTURE_2)
#if defined(ASLIB_INCLUDE_DL)
			//bool is_area = false;
			//if (add_pos.x1 < area_.x1 || add_pos.y1 < area_.y1 || add_pos.x2 > area_.x2 || add_pos.y2 > area_.y2) is_area = true;
			//if(is_area) 
				DxLib::SetDrawArea(area_.x1, area_.y1, area_.x2, area_.y2);
			//if(is_area) 
				asTexture(this->id[anime_size], Pos4(add_pos.x1 + area_.x1, add_pos.y1 + area_.y1, add_pos.x2 + area_.x1, add_pos.y2 + area_.y1), alpha, is_alpha);

				DxLib::SetDrawAreaFull();
#else
			asTexture(this->id[anime_size], add_pos, alpha);
#endif
#endif
			return *this;
		}
		//, AsScreen* const s_=nullptr

		const size_t Num() const { return this->num; };
		const size_t NumX() const { return this->num_x; };
		const size_t NumY() const { return this->num_y; };
		const Pos2 pixelSize() const { return this->pixel_size; };
		const float pixelNumX() const { return float(this->pixel_size.x) / this->pixel_size.y; };
		const float pixelNumY() const { return float(this->pixel_size.y) / this->pixel_size.x; };
	};

	//複数の画像UIの情報を管理する
	struct TextureUI
	{
	private:
		AsTexture* id;
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
		TextureUI(AsTexture* const add_tmd, const uint8_t add_alpha, const Pos4& add_pos4) :id(add_tmd), alpha(add_alpha), pos4(add_pos4) {}
		TextureUI(AsTexture* const add_tmd, const uint8_t add_alpha, const PosA4F& add_pR) : id(add_tmd), alpha(add_alpha), pR(add_pR) {}
		TextureUI & fpsUpdate();

		//出力
		const AsTexture* const Point() const { return this->id; };
		uint8_t Alpha() const { return this->alpha; };
		Pos4 Pos() const { return this->pos4; };
		PosA4F PosF() const { return this->pR; };
		int32_t Touch() const { return this->touch_num; };
		int32_t Touch0() { const int32_t num = this->touch_num; this->touch_num = 0; return num; };

		//カウンター出力
		bool down() const { return counter.down(); };
		bool up() const { return counter.up(); };
		int32_t count() const { return counter.count(); };
		bool down0() { return counter.down0(); };
		bool up0() { return counter.up0(); };
		int32_t count0() { return counter.count0(); };

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

		TextureUI& setUI(AsTexture* const add_tmd, const uint8_t add_alpha, const PosA4F& add_pR) { id = add_tmd; alpha = add_alpha; pR = add_pR; return *this; }
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
				for (size_t i = 0; i < check_touch_all_num; ++i) {
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
	inline const AsTexture& AsTexture::draw(const size_t anime_size, const PosA4F& add_pos, const float r_, const uint8_t alpha)
	{
#if defined(ANIME_TEXTURE_1)
		const Pos4 add_pos_(add_pos);
		asTextureType1(this->id, Pos2(add_pos_.x1, add_pos_.y1), Pos2(int32_t(add_pos.w), int32_t(add_pos.h)), PosL4(this->pixel_size.x*int32_t(anime_size%this->turn_id), this->pixel_size.y*int32_t(anime_size / this->turn_id), this->pixel_size.x, this->pixel_size.y), alpha, r_);
#elif defined(ANIME_TEXTURE_2)
		asTexture(this->id[anime_size], add_pos,r_, alpha);
#endif
		return *this;
	}
}