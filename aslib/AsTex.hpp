//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asライブラリ
//
//                    制作者: がっちょ (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{



	//画像読み込み
	inline Tex asLoadTex(const char* const name)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		return Tex(DxLib::LoadGraph(name));
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		return s3d::Texture(s3d::Unicode::UTF8ToUTF32(std::string(name)));
#endif
	}

#if defined(ASLIB_INCLUDE_DL) //DxLib
	//画像を分割ロードする
	inline std::unique_ptr<Tex[]> asLoadTex(const char* const name, const size_t tex_num)
	{

		const Tex tex = DxLib::LoadGraph(name);
		if (tex == -1) return nullptr;
		int size_x = 0, size_y = 0;
		DxLib::GetGraphSize(tex, &size_x, &size_y);
		DxLib::DeleteGraph(tex);
		if (size_x == 0 || size_y == 0) return nullptr;

		std::unique_ptr<Tex[]> texs(new Tex[tex_num]);
		DxLib::LoadDivGraph(name, int(tex_num), int(tex_num), 1, size_x / int(tex_num), size_y, texs.get());
		return texs;
	}
#endif

#if defined(ASLIB_INCLUDE_DL) //DxLib
	inline std::unique_ptr<Tex[]> asLoadTex(const char* const name, const size_t tex_num_x, const size_t tex_num_y)
	{
		const Tex tex = DxLib::LoadGraph(name);
		if (tex == -1) return nullptr;
		int size_x = 0, size_y = 0;
		DxLib::GetGraphSize(tex, &size_x, &size_y);
		DxLib::DeleteGraph(tex);
		if (size_x == 0 || size_y == 0) return nullptr;

		std::unique_ptr<Tex[]> texs(new Tex[tex_num_x * tex_num_y]);
		DxLib::LoadDivGraph(name, int(tex_num_x * tex_num_y), int(tex_num_x), int(tex_num_y), size_x / int(tex_num_x), size_y / int(tex_num_y), &texs[0]);
		return texs;
	}
#endif




	int32_t AsTexSize(const Tex& id, Pos2& texture_size)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		static int size_x, size_y;
		size_x = size_y = 0;
		if (DxLib::GetGraphSize(id, &size_x, &size_y) == -1) return -1;
		texture_size(int32_t(size_x), int32_t(size_y));
		return 0;
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		texture_size(int32_t(id.width()), int32_t(id.height()));
		return 0;
#endif
	}

	const Pos2 AsTexSize(const Tex& id)
	{
		Pos2 p;
		AsTexSize(id, p);
		return p;
	}

#if defined(ASLIB_INCLUDE_DL) //DxLib

	int32_t asTex(const Tex tex, const PosA4R& p_ = pos4_0, const float r_ = 0.0f, const uint8_t alpha = 255)
	{
		if (DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha) == -1) return -1;
		const Pos2 s = AsTexSize(tex);
		if (DxLib::DrawRotaGraphFast3(int(p_.x), int(p_.y), s.x/2, s.y/2, p_.w / s.x, p_.h / s.y, r_, tex, TRUE) != -1) return 0;

		return -1;
	}

	int32_t asTex8(const Tex tex, const Pos8& pos8 = pos8_100, const uint8_t alpha = 255)
	{
		if (DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, int(alpha)) == -1) return -1;
		if (DxLib::DrawModiGraph(int(pos8.x1), int(pos8.y1), int(pos8.x2), int(pos8.y2), int(pos8.x4), int(pos8.y4), int(pos8.x3), int(pos8.y3), tex, TRUE) != -1) return 0;

		return -1;
	}

	int32_t asTex4(const Tex tex, const Pos8& pos8 = pos8_100, const uint8_t alpha = 255)
	{
		if (DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha) == -1) return -1;
		if (DxLib::DrawExtendGraph(int(pos8.x1), int(pos8.y1), int(pos8.x4), int(pos8.y4), tex, TRUE) != -1) return 0;

		return -1;
	}

	int32_t asTex4(const Tex tex, const Pos4& pos4 = pos4_100, const uint8_t alpha = 255)
	{
		if (DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha) == -1) return -1;
		if (DxLib::DrawExtendGraph(int(pos4.x1), int(pos4.y1), int(pos4.x2), int(pos4.y2), tex, TRUE) != -1) return 0;

		return -1;
	}

	inline int32_t asTex4(const Tex tex, const Pos2& pos2 = pos2_100, const uint8_t alpha = 255) { return asTex4(tex, Pos4(pos2), alpha); }

	//todo
	int32_t asTex(const Tex tex, const Pos4& pos4 = pos4_100, const uint8_t alpha = 255, const ColorRGBA& colorRGBA = color_0)
	{
		if (DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha) == -1) return -1;
		if (DxLib::DrawExtendGraph(int(pos4.x1), int(pos4.y1), int(pos4.x2), int(pos4.y2), tex, TRUE) != -1) return 0;

		if (colorRGBA.a == 0) return -1;
		if (asRect(pos4, colorRGBA) == -1) return -1;
		return -2;
	}

	int32_t AsTexAt(const Tex tex, const Pos4& pos4 = {}, const uint8_t alpha = 255, const ColorRGBA& colorRGBA = color_0) {
		const int32_t sub_x = (pos4.x2 - pos4.x1) >> BIT_SHIFT_DIV_2;
		const int32_t sub_y = (pos4.y2 - pos4.y1) >> BIT_SHIFT_DIV_2;
		const int32_t x1 = pos4.x1 - sub_x;
		const int32_t x2 = pos4.x2 - sub_x;
		const int32_t y1 = pos4.y1 - sub_y;
		const int32_t y2 = pos4.y2 - sub_y;

		const Pos4 new_pos4 = { x1,y1,x2,y2 };
		return asTex(tex, new_pos4, alpha, colorRGBA);
	}

#elif defined(ASLIB_INCLUDE_S3) //Siv3D

	int32_t AsTexSize(const Tex& id, Pos2& texture_size)
	{
		texture_size.x = int32_t(id.width());
		texture_size.y = int32_t(id.height());
		return 0;
	}

	//int32_t asTex4(const Tex tex, const Pos8& pos8 = pos8_100, const uint8_t alpha = 255)
	//{
	//	tex.resized(pos8.x4 - pos8.x1, pos8.y4 - pos8.y1).draw(pos8.x1, pos8.y1, s3d::Alpha(alpha));
	//	return 0;
	//}

	int32_t asTex4(const Tex& tex, const Pos4& pos = pos4_100, const uint8_t alpha = 255)
	{
		tex.resized(pos.x2 - pos.x1, pos.y2 - pos.y1).draw(pos.x1, pos.y1, s3d::Alpha(alpha));
		return 0;
	}

	int32_t asTex4(const Tex& tex, const Pos2& pos2 = pos2_100, const uint8_t alpha = 255)
	{
		tex.resized(pos2.x, pos2.y).draw(0, 0, s3d::Alpha(alpha));

		return -1;
	}

	int32_t asTex4S3(const Tex& tex, const Pos4& pos, const PosL4& pos_, const uint8_t alpha = 255)
	{
		tex(pos_.x, pos_.y, pos_.w, pos_.h).resized(pos.x2 - pos.x1, pos.y2 - pos.y1).draw(pos.x1, pos.y1, s3d::Alpha(alpha));
		return 0;
	}

	int32_t asTex4S3(const Tex& tex, const Pos2& pos2, const PosL4& pos_, const uint8_t alpha = 255)
	{
		tex(pos_.x, pos_.y, pos_.w, pos_.h).resized(pos2.x, pos2.y).draw(0, 0, s3d::Alpha(alpha));
		return -1;
	}

	//todo
	int32_t asTex8(const Tex tex, const Pos8& pos8 = pos8_100, const uint8_t alpha = 255)
	{
		return -1;
	}

#else //Console

#endif



	//１つの画像を管理する
	struct TextureMainData
	{
	private:

		//画像番号
		const Tex id;

		//画像サイズ
		const Pos2 pixel_size;

	public:
		const TextureMainData() = default;
		const TextureMainData(const Tex& add_id) :id(add_id), pixel_size(AsTexSize(add_id)) {}
		const TextureMainData& drawP(const Pos2&, const uint8_t = 255) const;
		const TextureMainData& draw() const;
		const TextureMainData& draw(const uint8_t) const;
		const TextureMainData& draw(const Pos2&, const uint8_t = 255) const;
		const TextureMainData& draw(const Pos4&, const uint8_t = 255) const;
		const TextureMainData& draw(const Pos8&, const uint8_t = 255) const;
		const TextureMainData& drawA(const Pos2 pos2, const uint8_t alpha_) const{
			static Pos4 aspect_pos;
			const Pos2 posWS = this->pixelSize();
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
			this->draw(aspect_pos, alpha_); return *this;
		};

		//出力
		const Tex ID() const { return this->id; }
		const Pos2 pixelSize() const { return this->pixel_size; }
		const int32_t return0() const { return 0; }

	};

	//１つの画像UIの情報を管理する
	struct TextureUI
	{
		constexpr TextureUI(TextureMainData* const t_, const uint8_t a_, const Pos4& p_) :tmd(t_), alpha(a_), pos4(p_) {}

		//メンバ変数を出力
		const TextureMainData* const Point() const { return this->tmd; };
		const uint8_t Alpha() const { return this->alpha; };
		const Pos4 Pos() const { return this->pos4; };
		const int32_t Touch() const { return this->touch_num; };
		const int32_t Touch0() { const int32_t num = this->touch_num; this->touch_num = 0; return num; };

		//カウンターを出力
		const bool Down() const { return counter.Down(); };
		const bool Up() const { return counter.Up(); };
		const int32_t Count() const { return counter.Count(); };
		const bool Down0() { return counter.Down0(); };
		const bool Up0() { return counter.Up0(); };
		const int32_t Count0() { return counter.Count0(); };

		const TextureUI& touch(const Pos2&);
		const TextureUI& initTouch() { this->touch_num = 0; return *this; };

		//描画
		const TextureUI& draw() const { tmd->draw(pos4, alpha); return *this; };
		const TextureUI& drawA(const Pos2 pos2, const uint8_t alpha_) {
			static Pos4 aspect_pos;
			const Pos2 posWS = this->tmd->pixelSize();
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
			this->tmd->draw(aspect_pos, alpha_); return *this;
		};

		//タッチカウント
		const TextureUI& update() { this->counter.update(this->touch_num); return *this; };

	private:

		TextureMainData * tmd;

		//画像透明度
		uint8_t alpha = 255;

		//四角形描画位置
		Pos4 pos4;

		//あたり判定
		Counter counter;

		//タッチ数
		int32_t touch_num = 0;
	};

	//複数の画像を管理する
	struct AnimeMainData
	{
	private:
#if defined(ANIME_TEXTURE_1)
		Tex id;
#elif defined(ANIME_TEXTURE_2)
		std::unique_ptr<Tex[]> id;
#endif
		Pos2 pixel_size;
		size_t num = 0;
	public:
#if defined(ANIME_TEXTURE_1)
		AnimeMainData(const size_t id_num, const Tex& add_id) :id(std::move(add_id)), num(id_num)
		{
			//画像サイズ取得
			AsTexSize(this->id, this->pixel_size);
			this->pixel_size.x /= int32_t(id_num);
		}
#elif defined(ANIME_TEXTURE_2)
		const AnimeMainData(const size_t id_num, std::unique_ptr<Tex[]>&& add_id) :id(std::move(add_id)), pixel_size(AsTexSize(this->id[0])), num(id_num) {}
#endif
		const AnimeMainData& draw(const size_t) const;
		const AnimeMainData& draw(const size_t, const uint8_t) const;
		const AnimeMainData& draw(const size_t, const Pos2&, const uint8_t = 255) const;
		const AnimeMainData& draw(const size_t, const Pos4&, const uint8_t = 255) const;
		const AnimeMainData& draw(const size_t, const PosA4R&, const float, const uint8_t = 255) const;
		const size_t Num() const { return this->num; };
		const Pos2 pixelSize() const { return this->pixel_size; };
	};

	//複数の画像UIの情報を管理する
	struct AnimeUI
	{
	private:
		const AnimeMainData* id;
		//size_t anime_size = 0;
		size_t anime_count = 0;
		//毎フレーム
		size_t fps_size = 10;
		size_t fps_count = 0;

		//画像透明度
		uint8_t alpha = 255;

		//画像回転率
		float rota = 0.0f;

		//四角形描画位置
		Pos4 pos4;
		PosA4R pR;

		//あたり判定
		Counter counter;

		//タッチ数
		int32_t touch_num = 0;
	public:
		const AnimeUI() = default;
		const AnimeUI(const AnimeMainData* const add_tmd, const uint8_t add_alpha, const Pos4& add_pos4) :id(add_tmd), alpha(add_alpha), pos4(add_pos4) {}
		const AnimeUI(const AnimeMainData* const add_tmd, const uint8_t add_alpha, const PosA4R& add_pR) : id(add_tmd), alpha(add_alpha), pR(add_pR) {}
		AnimeUI & fpsUpdate();

		//出力
		const AnimeMainData* const Point() const { return this->id; };
		uint8_t Alpha() const { return this->alpha; };
		Pos4 Pos() const { return this->pos4; };
		PosA4R PosF() const { return this->pR; };
		int32_t Touch() const { return this->touch_num; };
		int32_t Touch0() { const int32_t num = this->touch_num; this->touch_num = 0; return num; };

		//カウンター出力
		bool Down() const { return counter.Down(); };
		bool Up() const { return counter.Up(); };
		int32_t Count() const { return counter.Count(); };
		bool Down0() { return counter.Down0(); };
		bool Up0() { return counter.Up0(); };
		int32_t Count0() { return counter.Count0(); };

		AnimeUI& touch(const Pos2&);
		AnimeUI& initTouch() { this->touch_num = 0; return *this; };

		AnimeUI& p() { return *this; }

		//
		AnimeUI& setRota(const float r_) { rota = r_; return *this; }
		AnimeUI& addRota(const float r_) { rota += r_; return *this; }

		AnimeUI& setUI(const AnimeMainData* const add_tmd, const uint8_t add_alpha, const PosA4R& add_pR) { id = add_tmd; alpha = add_alpha; pR = add_pR; return *this; }
		AnimeUI& setPosF(const PosA4R pR_) { pR = pR_; return *this; }
		bool isOutWindowF() {
			const Pos2R w2(asWindowSizeF()); const Pos4R p4r(pR);
			if (p4r.x2<0.0f || p4r.y2<0.0f || p4r.x1>w2.x || p4r.y1>w2.y) return true;
			return false;
		}

		//大きさ加算
		AnimeUI& addSizeF(const Pos2R& p2_) { pR.w += p2_.x; pR.h += p2_.y; return *this; }
		AnimeUI& addSizeF(const Pos2R& p2_, const Pos2R& p2_2) { if (pR.w < p2_2.x)pR.w += p2_.x; if (pR.h < p2_2.y)pR.h += p2_.y; return *this; }
		AnimeUI& addPosF(const Pos2R& p2_) { pR.x += p2_.x; pR.y += p2_.y; return *this; }
		AnimeUI& addPosF(const float p2_xy) { pR.x += p2_xy; pR.y += p2_xy; return *this; }
		AnimeUI& addPosF(const float p2_x, const float p2_y) { pR.x += p2_x; pR.y += p2_y; return *this; }

		//描画
		AnimeUI& draw() { this->id->draw(anime_count, pos4, alpha); return *this; };
		AnimeUI& draw(const uint8_t alpha_) { this->id->draw(anime_count, pos4, alpha_); return *this; };
		AnimeUI& draw(const uint8_t alpha_, const Pos4 pos_) { this->id->draw(anime_count, pos_, alpha_); return *this; };
		AnimeUI& draw(const Pos4 pos_) { this->id->draw(anime_count, pos_, alpha); return *this; };
		AnimeUI& draw(const Pos4 pos_, const uint8_t alpha_) { this->id->draw(anime_count, pos_, alpha_); return *this; };

		AnimeUI& drawF() { this->id->draw(anime_count, Pos4(pR), alpha); return *this; };
		AnimeUI& drawF(const uint8_t alpha_) { this->id->draw(anime_count, Pos4(pR), alpha_); return *this; };
		AnimeUI& drawF(const uint8_t alpha_, const PosA4R pR_) { this->id->draw(anime_count, Pos4(pR_), alpha_); return *this; };
		AnimeUI& drawF(const PosA4R pR_) { this->id->draw(anime_count, Pos4(pR), alpha); return *this; };
		AnimeUI& drawF(const PosA4R pR_, const uint8_t alpha_) { this->id->draw(anime_count, Pos4(pR), alpha_); return *this; };

		AnimeUI& drawRF() { this->id->draw(anime_count, Pos4(pR), rota, alpha); return *this; };
		AnimeUI& drawRF(const uint8_t alpha_) { this->id->draw(anime_count, Pos4(pR), rota, alpha_); return *this; };
		AnimeUI& drawRF(const uint8_t alpha_, const PosA4R pR_) { this->id->draw(anime_count, Pos4(pR_), rota, alpha_); return *this; };
		AnimeUI& drawRF(const PosA4R pR_) { this->id->draw(anime_count, Pos4(pR), rota, alpha); return *this; };
		AnimeUI& drawRF(const PosA4R pR_, const uint8_t alpha_) { this->id->draw(anime_count, Pos4(pR), rota, alpha_); return *this; };

		AnimeUI& drawA(const Pos2 pos2, const uint8_t alpha_) {
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
		AnimeUI& update() {
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

	inline AnimeUI& AnimeUI::fpsUpdate()
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

//サイズ等倍 位置指定
	inline const TextureMainData& TextureMainData::draw(const Pos8& add_pos, const uint8_t alpha)const
	{
		asTex8(this->id, add_pos, alpha);
		return *this;
	}

	inline const TextureUI& TextureUI::touch(const Pos2& add_pos)
	{
		bool is_touch = false;
		const Pos4 p = { pos4.x1 - add_pos.x ,pos4.y1 - add_pos.y ,pos4.x2 - add_pos.x ,pos4.y2 - add_pos.y };

		//タッチのあたり判定
		if (p.x1 <= 0 && p.y1 <= 0 && p.x2 >= 0 && p.y2 >= 0) is_touch = true;
		else if (p.x1 > 0 && p.y1 > 0 && p.x2 < 0 && p.y2 < 0) is_touch = true;

		//タッチの数をカウント
		if (is_touch && this->touch_num != INT32_MAX) this->touch_num++;
		return *this;
	}

	inline AnimeUI& AnimeUI::touch(const Pos2& add_pos)
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

	//サイズ等倍 位置指定
	inline const TextureMainData& TextureMainData::draw(const Pos4& add_pos, const uint8_t alpha)const
	{
		asTex4(this->id, add_pos, alpha);
		return *this;
	}

	//サイズ等倍 位置指定
	inline const TextureMainData& TextureMainData::draw(const Pos2& add_pos, const uint8_t alpha)const
	{
		asTex4(this->id, add_pos, alpha);
		return *this;
	}

	//サイズ 指定なし 透明度 指定あり
	inline const TextureMainData& TextureMainData::draw(const uint8_t alpha)const
	{
		asTex4(this->id, this->pixel_size, alpha);
		return *this;
	}

	//サイズ・透明度 指定なし
	inline const TextureMainData& TextureMainData::draw()const
	{
		asTex4(this->id, this->pixel_size);
		return *this;
	}

	//サイズ・透明度 指定なし・初期位置指定あり
	inline const TextureMainData& TextureMainData::drawP(const Pos2& add_pos, const uint8_t alpha)const
	{
		const Pos4 p{ add_pos.x, add_pos.y, add_pos.x + this->pixel_size.x, add_pos.y + this->pixel_size.y };
		asTex4(this->id, p, alpha);
		return *this;
	}

	//サイズ等倍 位置指定
	inline const AnimeMainData& AnimeMainData::draw(const size_t anime_size, const Pos4& add_pos, const uint8_t alpha) const
	{
#if defined(ANIME_TEXTURE_1)
		PosL4 pos_;
		pos_.w = this->pixel_size.x;
		pos_.h = this->pixel_size.y;
		pos_.x = this->pixel_size.x*int32_t(anime_size);
		asTex4S3(this->id, add_pos, pos_, alpha);
#elif defined(ANIME_TEXTURE_2)
		asTex4(this->id[anime_size], add_pos, alpha);
#endif
		return *this;
	}

	//サイズ等倍 位置指定 回転指定あり
	inline const AnimeMainData& AnimeMainData::draw(const size_t anime_size, const PosA4R& add_pos, const float r_, const uint8_t alpha) const
	{
#if defined(ANIME_TEXTURE_1)
		PosL4 pos_;
		pos_.w = this->pixel_size.x;
		pos_.h = this->pixel_size.y;
		pos_.x = this->pixel_size.x*int32_t(anime_size);
		asTex4S3(this->id, add_pos, pos_, alpha);
#elif defined(ANIME_TEXTURE_2)
		asTex(this->id[anime_size], add_pos,r_, alpha);
#endif
		return *this;
	}

	//サイズ等倍 位置指定
	inline const AnimeMainData& AnimeMainData::draw(const size_t anime_size, const Pos2& add_pos, const uint8_t alpha) const
	{
#if defined(ANIME_TEXTURE_1)
		PosL4 pos_;
		pos_.w = this->pixel_size.x;
		pos_.h = this->pixel_size.y;
		pos_.x = this->pixel_size.x*int32_t(anime_size);
		asTex4S3(this->id, add_pos, pos_, alpha);
#elif defined(ANIME_TEXTURE_2)
		asTex4(this->id[anime_size], add_pos, alpha);
#endif
		return *this;
	}

	//サイズ 指定なし 透明度 指定あり
	inline const AnimeMainData& AnimeMainData::draw(const size_t anime_size, const uint8_t alpha) const
	{
#if defined(ANIME_TEXTURE_1)
		PosL4 pos_;
		pos_.w = this->pixel_size.x;
		pos_.h = this->pixel_size.y;
		pos_.x = this->pixel_size.x*int32_t(anime_size);
		asTex4S3(this->id, this->pixel_size, pos_, alpha);
#elif defined(ANIME_TEXTURE_2)
		asTex4(this->id[anime_size], this->pixel_size, alpha);
#endif
		return *this;
	}

	//サイズ・透明度 指定なし
	inline const AnimeMainData& AnimeMainData::draw(const size_t anime_size) const
	{
#if defined(ANIME_TEXTURE_1)
		PosL4 pos_;
		pos_.w = this->pixel_size.x;
		pos_.h = this->pixel_size.y;
		pos_.x = this->pixel_size.x*int32_t(anime_size);
		asTex4S3(this->id, this->pixel_size, pos_);
#elif defined(ANIME_TEXTURE_2)
		asTex4(this->id[anime_size], this->pixel_size);
#endif
		return *this;
	}

}