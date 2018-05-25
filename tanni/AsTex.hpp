//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asライブラリ
//
//                    制作者: がっちょ (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{

#if defined(__DXLIB) //DxLib

	inline Tex AsLoadTex(const char* const name)
	{
		return Tex(DxLib::LoadGraph(name));
	}

	int32_t AsTexSize(const Tex id, Pos2& texture_size)
	{
		int size_x = 0, size_y = 0;
		if (DxLib::GetGraphSize(id, &size_x, &size_y) == -1) return -1;
		texture_size.x = int32_t(size_x);
		texture_size.y = int32_t(size_y);
		return 0;
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

	int32_t asTex4(const Tex tex, const Pos2& pos2 = pos2_100, const uint8_t alpha = 255)
	{
		if (DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha) == -1) return -1;
		if (DxLib::DrawExtendGraph(0, 0, int(pos2.x), int(pos2.y), tex, TRUE) != -1) return 0;

		return -1;
	}

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








	struct TextureMainData
	{
	private:

		//画像番号
		int id;

		//画像サイズ
		Pos2 pixel_size;

	public:
		TextureMainData(const int add_id);

		TextureMainData& draw();
		TextureMainData& draw(const uint8_t);
		TextureMainData& draw(const Pos2&, const uint8_t = 255);
		TextureMainData& draw(const Pos4&, const uint8_t = 255);
		TextureMainData& draw(const Pos8&, const uint8_t = 255);

		//表示
		int ID();
		Pos2 pixelSize();

	};

	//サイズ等倍 位置指定
	inline TextureMainData& TextureMainData::draw(const Pos8& add_pos, const uint8_t alpha)
	{
		DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
		DxLib::DrawModiGraph(add_pos.x1, add_pos.y1, add_pos.x2, add_pos.y2, add_pos.x4, add_pos.y4, add_pos.x3, add_pos.y3, this->id, TRUE);
		return *this;
	}

	//サイズ等倍 位置指定
	inline TextureMainData& TextureMainData::draw(const Pos4& add_pos, const uint8_t alpha)
	{
		DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
		DxLib::DrawExtendGraph(add_pos.x1, add_pos.y1, add_pos.x2, add_pos.y2, this->id, TRUE);
		return *this;
	}

	//サイズ等倍 位置指定
	inline TextureMainData& TextureMainData::draw(const Pos2& add_pos, const uint8_t alpha)
	{
		DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
		DxLib::DrawGraph(add_pos.x, add_pos.y, this->id, TRUE);
		return *this;
	}

	//サイズ 指定なし 透明度 指定あり
	inline TextureMainData& TextureMainData::draw(const uint8_t alpha)
	{
		DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
		DxLib::DrawGraph(0, 0, this->id, TRUE);
		return *this;
	}

	//サイズ・透明度 指定なし
	inline TextureMainData& TextureMainData::draw()
	{
		DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
		DxLib::DrawGraph(0, 0, this->id, TRUE);
		return *this;
	}

	inline TextureMainData::TextureMainData(const int add_id)
	{
		this->id = add_id;

		//画像サイズ取得
		int size_x = 0, size_y = 0;
		DxLib::GetGraphSize(id, &size_x, &size_y);
		this->pixel_size.x = int32_t(size_x);
		this->pixel_size.y = int32_t(size_y);
	}



	struct TextureUI
	{
		TextureUI(TextureMainData* const add_tmd, const uint8_t add_alpha, const Pos4& add_pos4);

		//出力
		TextureMainData* Point() const { return this->tmd; };
		uint8_t Alpha() const { return this->alpha; };
		Pos4 Pos() const { return this->pos4; };
		int32_t Touch() const { return this->touch_num; };

		//カウンター出力
		bool Down() const { return counter.Down(); };
		bool Up() const { return counter.Up(); };
		int32_t Count() const { return counter.Count(); };

		TextureUI& touch(const Pos2&);
		TextureUI& initTouch() { this->touch_num = 0; return *this; };

		//描画
		TextureUI& draw() { tmd->draw(pos4, alpha); return *this; };

		//タッチカウント
		TextureUI& update() { this->counter.update(this->touch_num); return *this; };

	private:

		TextureMainData * tmd;

		//画像透明度
		uint8_t alpha = 255;

		//四角形描画位置 (todo:Pos8R)
		Pos4 pos4;

		//あたり判定
		Counter counter;

		//タッチ数
		int32_t touch_num = 0;
	};

	inline TextureUI& TextureUI::touch(const Pos2& add_pos)
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

	TextureUI::TextureUI(TextureMainData* const add_tmd, const uint8_t add_alpha, const Pos4& add_pos4)
	{
		tmd = add_tmd;
		alpha = add_alpha;
		pos4 = add_pos4;
	}

	int TextureMainData::ID()
	{
		return this->id;
	}

	Pos2 TextureMainData::pixelSize()
	{
		return this->pixel_size;
	}



#elif defined(SIV3D_INCLUDED) //Siv3D

#else //Console

#endif

}