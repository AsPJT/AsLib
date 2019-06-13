/*#######################################################################################
	Made by Kasugaccho
	Made by As Project
	https://github.com/Kasugaccho/AsLib
	wanotaitei@gmail.com

	This code is licensed under CC0.
#######################################################################################*/
#ifndef INCLUDED_AS_PROJECT_LIBRARY_TEXTURE
#define INCLUDED_AS_PROJECT_LIBRARY_TEXTURE


namespace AsLib
{

#if defined(ASLIB_INCLUDE_DL) //DxLib
	//DxLibは画像を分割ロードした方が描画しやすい
	//(ファイル名、横の分割数、縦の分割数、透過の有無)
	std::unique_ptr<OriginatorTexture[]> asLoadTexture(const char* const name_, const std::size_t num_x_ = 1, const std::size_t num_y_ = 1,const bool a_=true) noexcept
	{
		//画像の枚数分 配列を作成
		const std::size_t aslib_load_texture_xy{ num_x_ * num_y_ };
		std::unique_ptr<OriginatorTexture[]> texs(new OriginatorTexture[aslib_load_texture_xy]);
		for (std::size_t i{}; i < aslib_load_texture_xy; ++i) texs[i] = -1;
		//ぬるぽチェック
		if (name_ == nullptr) return texs;
		//画像の分割が必要ない場合
		if (num_x_ == 1 && num_y_ == 1) {
			texs[0] = DxLib::LoadGraph(name_);
			return texs;
		}
		//読み込み
		const OriginatorTexture tex{ DxLib::LoadGraph(name_) };
		if (tex == -1) return texs;
		//通常通り画像を読み込み画像サイズを得る
		int size_x{}, size_y{};
		DxLib::GetGraphSize(tex, &size_x, &size_y);
		DxLib::DeleteGraph(tex);
		if (size_x == 0 || size_y == 0) return texs;
		//画像を分割ロード
		DxLib::LoadDivGraph(name_, int(aslib_load_texture_xy), int(num_x_), int(num_y_), size_x / int(num_x_), size_y / int(num_y_), &texs[0]);
		return texs;
	}
#else
	//画像読み込み
	//(ファイル名、横の分割数、縦の分割数、透過の有無)
	inline OriginatorTexture asLoadTexture(const char* const name_, const std::size_t num_x_ = 1, const std::size_t num_y_ = 1) noexcept
	{
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		return s3d::Texture(s3d::Unicode::UTF8ToUTF32(name_));
#elif defined(ASLIB_INCLUDE_OF)
		static OriginatorTexture tex;
		tex.load(name_);
		return tex;
#elif defined(ASLIB_INCLUDE_C2)
		return Sprite::create(name_);
#elif defined(ASLIB_INCLUDE_SF)
return 0;
#elif defined(ASLIB_INCLUDE_TP)
		return 0;
#else //Console
		return 0;
#endif
	}
#endif

	inline void asTextureSize(const OriginatorTexture& id, Pos2& texture_size) noexcept
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		if (id == -1) { texture_size(0, 0); return; }
		int size_x{}, size_y{};
		DxLib::GetGraphSize(id, &size_x, &size_y);
		texture_size(std::int32_t(size_x), std::int32_t(size_y));
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		texture_size(std::int32_t(id.width()), std::int32_t(id.height()));
#elif defined(ASLIB_INCLUDE_OF)
		texture_size(std::int32_t(id.getWidth()), std::int32_t(id.getHeight()));
#elif defined(ASLIB_INCLUDE_C2)

#elif defined(ASLIB_INCLUDE_SF)

#elif defined(ASLIB_INCLUDE_TP)
#else //Console
#endif
	}

	const Pos2 asTextureSize(const OriginatorTexture& id) noexcept
	{
		Pos2 p;
		asTextureSize(id, p);
		return p;
	}

#if defined(ASLIB_INCLUDE_S3) //Siv3D
	inline void asTextureType1(const OriginatorTexture& t_, const Pos2& p_, const Pos2& l_, const PosL4& cut_p_, const std::uint8_t& a_ = (std::uint8_t)255, const float& r_ = 0.0f) noexcept
	{
		t_(cut_p_.x, cut_p_.y, cut_p_.w, cut_p_.h).resized(l_.x, l_.y).rotated(double(r_)).draw(p_.x, p_.y, s3d::Alpha(a_));
	}
#elif defined(ASLIB_INCLUDE_OF)
	inline void asTextureType1(const OriginatorTexture& t_, const Pos2& p_, const Pos2& l_, const PosL4& cut_p_, const std::uint8_t& a_ = 255) noexcept
	{
		//ofTranslate(l_.x / 2, l_.y / 2);
		//ofRotateRad(r_);
		ofSetColor(255, 255, 255, int(a_));
		t_.drawSubsection(p_.x, p_.y, l_.x, l_.y, cut_p_.x, cut_p_.y, cut_p_.w, cut_p_.h);
		//t_.drawSubsection(0,0,200,200,0,0,480,480);
		//t_.drawSubsection(cut_p_.x, cut_p_.y,cut_p_.w, cut_p_.h, p_.x, p_.y, l_.x, l_.y);
	}
	//todo
	inline void asTextureType1(const OriginatorTexture& t_, const Pos2& p_, const Pos2& l_, const PosL4& cut_p_, const std::uint8_t& a_, const float& r_) noexcept
	{
		//ofTranslate(l_.x / 2, l_.y / 2);
		//ofRotateRad(r_);
		ofSetColor(255, 255, 255, int(a_));
		t_.drawSubsection(p_.x, p_.y, l_.x, l_.y, cut_p_.x, cut_p_.y, cut_p_.w, cut_p_.h);
		//t_.drawSubsection(0,0,200,200,0,0,480,480);
		//t_.drawSubsection(cut_p_.x, cut_p_.y,cut_p_.w, cut_p_.h, p_.x, p_.y, l_.x, l_.y);
	}
#endif

	inline void asTexture(const OriginatorTexture& tex, const PosA4F& p_, const float& r_, const std::uint8_t& alpha = 255, const bool is_a_ = true) noexcept
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
	inline void asTexture(const OriginatorTexture& tex, const Pos4& pos, const std::uint8_t& alpha = 255, const bool is_a_ = true) noexcept
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
		std::size_t turn_id = 1;
#elif defined(ANIME_TEXTURE_2)
		//画像ID
		std::unique_ptr<OriginatorTexture[]> id;
#elif defined(ANIME_TEXTURE_3)
		std::int32_t id;
#elif defined(ANIME_TEXTURE_4)
		OriginatorTexture id;
#endif
		Pos2 before_pixel_size;
		//画像サイズ
		Pos2 pixel_size;
		//合計サイズ
		std::size_t num{};
		//横サイズ
		std::size_t num_x{};
		//縦サイズ
		std::size_t num_y{};
		//透過の有無
		bool is_alpha{ true };
	public:
		AsTexture() = default;
		~AsTexture() { 
#if defined(ASLIB_INCLUDE_DL)
			for (std::size_t i{}; i < num; ++i) DxLib::DeleteGraph(id[i]);
#endif
		}
#if defined(ANIME_TEXTURE_1)
		AsTexture(const char* const name_, const std::size_t x_ = 1, const std::size_t y_ = 1, const bool a_ = true) :id(asLoadTexture(name_, x_, y_)), num(x_*y_), num_x(x_), num_y(y_), is_alpha(a_)
		{
			//画像サイズ取得
			asTextureSize(this->id, this->pixel_size);
			this->pixel_size.x /= std::int32_t(x_);
			this->pixel_size.y /= std::int32_t(y_);
			this->turn_id = std::size_t(x_);
		}
		AsTexture& operator()(const char* const name_, const std::size_t x_ = 1, const std::size_t y_ = 1, const bool a_ = true)
		{
			id = asLoadTexture(name_, x_, y_);
			num = x_ * y_;
			num_x = x_;
			num_y = y_;
			is_alpha = a_;
			//画像サイズ取得
			asTextureSize(this->id, this->pixel_size);
			this->pixel_size.x /= std::int32_t(x_);
			this->pixel_size.y /= std::int32_t(y_);
			this->turn_id = std::size_t(x_);
			return *this;
		}
#elif defined(ANIME_TEXTURE_2)
		AsTexture(const char* const name_, const std::size_t x_ = 1, const std::size_t y_ = 1, const bool a_ = true) :id(asLoadTexture(name_,x_,y_)), pixel_size(asTextureSize(this->id[0])), num(x_*y_), num_x(x_), num_y(y_), is_alpha(a_) {}//stdmovea
		AsTexture& operator()(const char* const name_, const std::size_t x_ = 1, const std::size_t y_ = 1, const bool a_ = true) noexcept
		{
#if defined(ASLIB_INCLUDE_DL)
			//以前のデータを削除
			for (std::size_t i{}; i < num; ++i) DxLib::DeleteGraph(id[i]);
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
		AsTexture(const char* const name_, const std::size_t x_ = 1, const std::size_t y_ = 1, const bool a_ = true) :id(asLoadTexture(name_, x_, y_)) {}//stdmovea
		AsTexture& operator()(const char* const name_, const std::size_t x_ = 1, const std::size_t y_ = 1, const bool a_ = true) { return *this; }
#elif defined(ANIME_TEXTURE_4)
		AsTexture(const char* const name_, const std::size_t x_ = 1, const std::size_t y_ = 1, const bool a_ = true) : id(asLoadTexture(name_, x_, y_)) {}//stdmovea
		AsTexture& operator()(const char* const name_, const std::size_t x_ = 1, const std::size_t y_ = 1, const bool a_ = true) { return *this; }
#endif

		//--------------------------------------------------
		//描画テスト機能
		//--------------------------------------------------

		//描画範囲(大きさ)
		AsTexture& operator()(const PosL4& p_) noexcept {asSetDrawPosSave(p_);return *this;}
		AsTexture& operator()(const std::int32_t x_, const std::int32_t y_, const std::int32_t w_, const std::int32_t h_) noexcept {asSetDrawPosSave(PosL4(x_, y_, w_, h_));return *this;}
		AsTexture& operator()(const std::int32_t x_, const std::int32_t y_, const std::int32_t l_) noexcept {asSetDrawPosSave(PosL4(x_, y_, l_));return *this;}
		AsTexture& setRect(const PosL4& p_) noexcept {asSetDrawPosSave(p_);return *this;}
		AsTexture& setRect(const std::int32_t x_, const std::int32_t y_, const std::int32_t w_, const std::int32_t h_) noexcept {asSetDrawPosSave(PosL4(x_, y_, w_, h_));return *this;}
		AsTexture& setRect(const std::int32_t x_, const std::int32_t y_, const std::int32_t l_) noexcept {asSetDrawPosSave(PosL4(x_, y_, l_));return *this;}
		//描画ID
		AsTexture& setID(const std::size_t num_ = 0) noexcept {
			asSetDrawNumSave(num_);
			return *this;
		}
		//描画透過度
		AsTexture& setAlpha(const std::uint8_t num_ = 255) noexcept {
			asSetDrawAlphaSave(num_);
			return *this;
		}

		AsTexture& drawAuto() noexcept {
#if defined(ANIME_TEXTURE_2)
			//描画サイズを決める
			PosL4 p{ asDrawPosSave() };
			if (asIsDraw(p)) p = PosL4(0, 0, this->pixel_size.x, this->pixel_size.y);

			int a{};

			DxLib::SetDrawBlendMode(1, a=int(asDrawAlphaSave()));

			DxLib::printfDx("(%d)", a);

			DxLib::DrawExtendGraph(p.x, p.y, p.x + p.w, p.y + p.h, this->id[0], is_alpha);
#endif
			return *this;
		}
		//--------------------------------------------------
		//描画
		//--------------------------------------------------

		//サイズ 指定なし 透明度 指定あり
		AsTexture& draw(const std::size_t anime_size, const std::uint8_t alpha = 255) noexcept
		{
#if defined(ANIME_TEXTURE_1)
			asTextureType1(this->id, Pos2(), this->pixel_size, PosL4(this->pixel_size.x*std::int32_t(anime_size%this->turn_id), this->pixel_size.y*std::int32_t(anime_size / this->turn_id), this->pixel_size.x, this->pixel_size.y), alpha);
#elif defined(ANIME_TEXTURE_2)
			asTexture(this->id[anime_size], this->pixel_size, alpha, is_alpha);
#endif
			return *this;
		}
		AsTexture& draw(const std::uint8_t alpha = 255) noexcept { return this->draw((std::size_t)0, alpha); }

		//サイズ等倍 位置指定
		AsTexture& draw(const std::size_t anime_size, const Pos4& add_pos, const std::uint8_t alpha=255) noexcept
		{
#if defined(ANIME_TEXTURE_1)
			asTextureType1(this->id, Pos2(add_pos.x1, add_pos.y1), Pos2(add_pos.x2 - add_pos.x1, add_pos.y2 - add_pos.y1), PosL4(this->pixel_size.x*std::int32_t(anime_size%this->turn_id), this->pixel_size.y*std::int32_t(anime_size / this->turn_id), this->pixel_size.x, this->pixel_size.y), alpha);
#elif defined(ANIME_TEXTURE_2)
			asTexture(this->id[anime_size], add_pos, alpha, is_alpha);
#endif
			return *this;
		}
		AsTexture& draw(const Pos4& add_pos, const std::uint8_t alpha=255) noexcept { return this->draw((std::size_t)0, add_pos, alpha); }
		const AsTexture& draw(const std::size_t, const PosA4F&, const float, const std::uint8_t = 255);


		//サイズ等倍 位置指定
		AsTexture& drawArea(const std::size_t anime_size, const Pos4& add_pos, const std::uint8_t alpha = 255, Pos4 area_ = aslib_default_area) noexcept
		{
#if defined(ASLIB_INCLUDE_S3)
			s3d::ViewportBlock2D area(area_.x1, area_.y1, area_.x2 - area_.x1, area_.y2 - area_.y1);
			asTextureType1(this->id, Pos2(add_pos.x1, add_pos.y1), Pos2(add_pos.x2 - add_pos.x1, add_pos.y2 - add_pos.y1), PosL4(this->pixel_size.x*std::int32_t(anime_size%this->turn_id), this->pixel_size.y*std::int32_t(anime_size / this->turn_id), this->pixel_size.x, this->pixel_size.y), alpha);
#endif
#if defined(ASLIB_INCLUDE_OF)
			asTextureType1(this->id, Pos2(area_.x1+add_pos.x1, area_.y1+add_pos.y1), Pos2(add_pos.x2 - add_pos.x1, add_pos.y2 - add_pos.y1), PosL4(this->pixel_size.x*std::int32_t(anime_size%this->turn_id), this->pixel_size.y*std::int32_t(anime_size / this->turn_id), this->pixel_size.x, this->pixel_size.y), alpha);
			//return *this;
			//asTextureType1(this->id, Pos2(add_pos.x1, add_pos.y1), Pos2(add_pos.x2 - add_pos.x1, add_pos.y2 - add_pos.y1), PosL4(this->pixel_size.x*std::int32_t(anime_size%this->turn_id), this->pixel_size.y*std::int32_t(anime_size / this->turn_id), this->pixel_size.x, this->pixel_size.y), alpha);
#endif
#if defined(ANIME_TEXTURE_1)
			//asTextureType1(this->id, Pos2(add_pos.x1, add_pos.y1), Pos2(add_pos.x2 - add_pos.x1, add_pos.y2 - add_pos.y1), PosL4(this->pixel_size.x*std::int32_t(anime_size%this->turn_id), this->pixel_size.y*std::int32_t(anime_size / this->turn_id), this->pixel_size.x, this->pixel_size.y), alpha);
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

		std::size_t Num() const noexcept { return this->num; };
		std::size_t NumX() const noexcept { return this->num_x; };
		std::size_t NumY() const noexcept { return this->num_y; };
		Pos2 pixelSize() const noexcept { return this->pixel_size; };
		float pixelNumX() const noexcept { return float(this->pixel_size.x) / this->pixel_size.y; };
		float pixelNumY() const noexcept { return float(this->pixel_size.y) / this->pixel_size.x; };
	};

	//複数の画像UIの情報を管理する
	struct TextureUI
	{
	private:
		AsTexture* id;
		std::size_t anime_count{};
		//毎フレーム
		std::size_t fps_size{ 2 };
		std::size_t fps_count{};

		//画像透明度
		std::uint8_t alpha{ 255 };

		//画像回転率
		float rota{ 0.0f };

		//四角形描画位置
		Pos4 pos4;
		PosA4F pR;

		//あたり判定
		Counter counter;

		//タッチ数
		std::int32_t touch_num{};
	public:
		TextureUI() = default;
		TextureUI(AsTexture* const add_tmd, const std::uint8_t add_alpha, const Pos4& add_pos4) :id(add_tmd), alpha(add_alpha), pos4(add_pos4) {}
		TextureUI(AsTexture* const add_tmd, const std::uint8_t add_alpha, const PosA4F& add_pR) : id(add_tmd), alpha(add_alpha), pR(add_pR) {}
		TextureUI & fpsUpdate();

		//出力
		const AsTexture* const Point() const noexcept { return this->id; };
		std::uint8_t Alpha() const noexcept { return this->alpha; };
		Pos4 Pos() const noexcept { return this->pos4; };
		PosA4F PosF() const noexcept { return this->pR; };
		std::int32_t Touch() const noexcept { return this->touch_num; };
		std::int32_t Touch0() noexcept { const std::int32_t num = this->touch_num; this->touch_num = 0; return num; };

		//カウンター出力
		bool down() const noexcept { return counter.down(); };
		bool up() const noexcept { return counter.up(); };
		std::int32_t count() const noexcept { return counter.count(); };
		bool down0() noexcept { return counter.down0(); };
		bool up0() noexcept { return counter.up0(); };
		std::int32_t count0() noexcept { return counter.count0(); };

		TextureUI& touch(const Pos2&);
		TextureUI& initTouch() noexcept { this->touch_num = 0; return *this; };

		TextureUI& p() noexcept { return *this; }

		//
		//TextureUI& setRota(const float r_) { rota = r_; return *this; }
		TextureUI& setRota(const float r_, const float r_2) noexcept {
			const float new_r = (rota - r_);
			
			if (new_r > abs(r_2)) rota -= abs(r_2);
			else if (new_r < -abs(r_2)) rota += abs(r_2);
			else rota += new_r;
			//rota = r_;
			return *this;
		}
		TextureUI& addRota(const float r_) noexcept { rota += r_; return *this; }
		const float Rota() const noexcept { return this->rota; };

		TextureUI& setUI(AsTexture* const add_tmd, const std::uint8_t add_alpha, const PosA4F& add_pR) noexcept { id = add_tmd; alpha = add_alpha; pR = add_pR; return *this; }
		TextureUI& setPosF(const PosA4F& pR_) noexcept { pR = pR_; return *this; }
		bool isOutWindowF() noexcept {
			const Pos2F w2(asWindowSizeF()); const Pos4F p4r(pR);
			if (p4r.x2<0.0f || p4r.y2<0.0f || p4r.x1>w2.x || p4r.y1>w2.y) return true;
			return false;
		}

		//大きさ加算
		TextureUI& addSizeF(const Pos2F& p2_) noexcept { pR.w += p2_.x; pR.h += p2_.y; return *this; }
		TextureUI& addSizeF(const Pos2F& p2_, const Pos2F& p2_2) noexcept { if (pR.w < p2_2.x)pR.w += p2_.x; if (pR.h < p2_2.y)pR.h += p2_.y; return *this; }
		TextureUI& addPosF(const Pos2F& p2_) noexcept { pR.x += p2_.x; pR.y += p2_.y; return *this; }
		TextureUI& addPosF(const float p2_xy) noexcept { pR.x += p2_xy; pR.y += p2_xy; return *this; }
		TextureUI& addPosF(const float p2_x, const float p2_y) noexcept { pR.x += p2_x; pR.y += p2_y; return *this; }
		TextureUI& setPosF(const Pos2F& p2_) noexcept { if (pR.x < 0.0f) pR.x = 0.0f; if (pR.y < 0.0f) pR.y = 0.0f; if (pR.x > p2_.x) pR.x = p2_.x; if (pR.y > p2_.y) pR.y = p2_.y; return *this; }

		//描画
		TextureUI& draw() noexcept { this->id->draw(anime_count, pos4, alpha); return *this; };
		TextureUI& draw(const std::uint8_t alpha_) noexcept { this->id->draw(anime_count, pos4, alpha_); return *this; };
		TextureUI& draw(const std::uint8_t alpha_, const Pos4 pos_) noexcept { this->id->draw(anime_count, pos_, alpha_); return *this; };
		TextureUI& draw(const Pos4 pos_) noexcept { this->id->draw(anime_count, pos_, alpha); return *this; };
		TextureUI& draw(const Pos4 pos_, const std::uint8_t alpha_) noexcept { this->id->draw(anime_count, pos_, alpha_); return *this; };

		TextureUI& drawF() noexcept { this->id->draw(anime_count, Pos4(pR), alpha); return *this; };
		TextureUI& drawF(const std::uint8_t alpha_) noexcept { this->id->draw(anime_count, Pos4(pR), alpha_); return *this; };
		TextureUI& drawF(const std::uint8_t alpha_, const PosA4F pR_) noexcept { this->id->draw(anime_count, Pos4(pR_), alpha_); return *this; };
		TextureUI& drawF(const PosA4F pR_) noexcept { this->id->draw(anime_count, Pos4(pR), alpha); return *this; };
		TextureUI& drawF(const PosA4F pR_, const std::uint8_t alpha_) noexcept { this->id->draw(anime_count, Pos4(pR), alpha_); return *this; };

		TextureUI& drawRF() noexcept { this->id->draw(anime_count, Pos4(pR), rota, alpha); return *this; };
		TextureUI& drawRF(const std::uint8_t alpha_) noexcept { this->id->draw(anime_count, Pos4(pR), rota, alpha_); return *this; };
		TextureUI& drawRF(const std::uint8_t alpha_, const PosA4F pR_) noexcept { this->id->draw(anime_count, Pos4(pR_), rota, alpha_); return *this; };
		TextureUI& drawRF(const PosA4F pR_) noexcept { this->id->draw(anime_count, Pos4(pR), rota, alpha); return *this; };
		TextureUI& drawRF(const PosA4F pR_, const std::uint8_t alpha_) noexcept { this->id->draw(anime_count, Pos4(pR), rota, alpha_); return *this; };

		TextureUI& drawA(const Pos2 pos2, const std::uint8_t alpha_) noexcept {
			static Pos4 aspect_pos;
			const Pos2 posWS{ this->id->pixelSize() };
			aspect_pos.x2 = std::int32_t(posWS.x*pos2.y / float(posWS.y));
			if (aspect_pos.x2 > pos2.x) {
				aspect_pos.x1 = 0;
				aspect_pos.x2 = pos2.x;
				aspect_pos.y2 = std::int32_t(posWS.y*pos2.x / float(posWS.x));
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
		TextureUI& update() noexcept {
			this->initTouch();
			//タッチされた数を取得
			const std::size_t check_touch_all_num{ asTouchNum() };

			//マウスのタッチを導入
			const Mouse mouse;
			if (check_touch_all_num == 0 && mouse.count() > 0) this->touch(mouse.Pos());

			//画面のクリック＆リリース
			Pos2 touch_pos;
			//タッチのみ
			for (std::size_t i{}; i < check_touch_all_num; ++i) {
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
		bool is_touch{ false };
		const Pos4 p(pos4.x1 - add_pos.x, pos4.y1 - add_pos.y, pos4.x2 - add_pos.x, pos4.y2 - add_pos.y);

		//タッチのあたり判定
		if (p.x1 <= 0 && p.y1 <= 0 && p.x2 >= 0 && p.y2 >= 0) is_touch = true;
		else if (p.x1 > 0 && p.y1 > 0 && p.x2 < 0 && p.y2 < 0) is_touch = true;

		//タッチの数をカウント
		if (is_touch && this->touch_num != INT32_MAX) ++this->touch_num;
		return *this;
	}



	//サイズ等倍 位置指定 回転指定あり
	inline const AsTexture& AsTexture::draw(const std::size_t anime_size, const PosA4F& add_pos, const float r_, const std::uint8_t alpha)
	{
#if defined(ANIME_TEXTURE_1)
		const Pos4 add_pos_(add_pos);
		asTextureType1(this->id, Pos2(add_pos_.x1, add_pos_.y1), Pos2(std::int32_t(add_pos.w), std::int32_t(add_pos.h)), PosL4(this->pixel_size.x*std::int32_t(anime_size%this->turn_id), this->pixel_size.y*std::int32_t(anime_size / this->turn_id), this->pixel_size.x, this->pixel_size.y), alpha, r_);
#elif defined(ANIME_TEXTURE_2)
		asTexture(this->id[anime_size], add_pos,r_, alpha);
#endif
		return *this;
	}
}

#endif //Included AsProject Library