//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asライブラリ
//
//                    制作者: がっちょ (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{



	//バッテリー取得
	inline const int32_t asBattery() {
#if defined(ASLIB_INCLUDE_DL) //DxLib
		return int32_t(DxLib::GetBatteryLifePercent());
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
#if defined(SIV3D_TARGET_WINDOWS)
		SYSTEM_POWER_STATUS sps;
		if (!GetSystemPowerStatus(&sps)) return 0;
		if (sps.BatteryLifePercent == BATTERY_PERCENTAGE_UNKNOWN) return 0;
		else return sps.BatteryLifePercent;
#endif
#elif defined(ASLIB_INCLUDE_OF)
		return 0;
#elif defined(ASLIB_INCLUDE_TP)
		return 0;
#else //Console
		return 0;
#endif
	}

	//バッテリー描画
	const int32_t asBatteryDraw(const PosL4 pos_, const Color battery_col = { 0,192,32,255 }, const Color out_col = { 75,75,75,255 })
	{
		const Color empty_col = { 255,255,255,out_col.a };

		//バッテリー外枠
		PosL4 out_pos = pos_;
		out_pos.h = pos_.w / 2;

		//バッテリー+
		PosL4 plus_pos;
		plus_pos.x = pos_.x + pos_.w;
		plus_pos.h = (out_pos.w >> 2);
		plus_pos.y = pos_.y + ((out_pos.h - plus_pos.h) >> 1);
		plus_pos.w = (pos_.w >> 3);

		//バッテリー空
		PosL4 empty_pos;
		empty_pos.x = pos_.x + pos_.w / 10;
		empty_pos.y = pos_.y + out_pos.w * 9 / 100;
		empty_pos.w = (pos_.w << 2) / 5;
		empty_pos.h = (out_pos.w << 3) / 25;

		const int32_t battery_power = asBattery();

		//バッテリー容量
		PosL4 battery_pos = empty_pos;
		battery_pos.w = empty_pos.w*battery_power / 100;

		asRect(out_col, out_pos);
		asRect(out_col, plus_pos);
		asRect(empty_col, empty_pos);
		asRect(battery_col, battery_pos);

		
		return 0;
	}

	struct Battery {
	public:
		Battery(const PosL4 pos_ = { 0,0,100,0 }, const Color in_col_ = { 0,192,32,255 }, const Color out_col_ = { 75,75,75,255 })
		{
			this->make(pos_, in_col_, out_col_);
		};
		Battery& make(const PosL4 pos_ = { 0,0,100,0 }, const Color in_col_ = { 0,192,32,255 }, const Color out_col_ = { 75,75,75,255 })
		{
			out_pos = pos_;
			battery_col = in_col_;
			out_col = out_col_;

			empty_col = Color( 255,255,255,out_col.a );

			//バッテリー外枠
			out_pos.h = pos_.w / 2;

			//バッテリー+
			plus_pos.x = pos_.x + pos_.w;
			plus_pos.h = (out_pos.w >> 2);
			plus_pos.y = pos_.y + ((out_pos.h - plus_pos.h) >> 1);
			plus_pos.w = (pos_.w >> 3);

			//バッテリー空
			empty_pos.x = pos_.x + pos_.w / 10;
			empty_pos.y = pos_.y + out_pos.w * 9 / 100;
			empty_pos.w = (pos_.w << 2) / 5;
			empty_pos.h = (out_pos.w << 3) / 25;

			battery_power = asBattery();

			//バッテリー容量
			battery_pos = empty_pos;
			battery_pos.w = empty_pos.w*battery_power / 100;

			//タッチの座標
			touch_pos.x1 = out_pos.x;
			touch_pos.y1 = out_pos.y;
			touch_pos.x2 = out_pos.x + out_pos.w + plus_pos.w;
			touch_pos.y2 = out_pos.y + out_pos.h;
			return *this;
		}
		Battery& draw()
		{
			battery_power = asBattery();
			battery_pos.w = empty_pos.w*battery_power / 100;

			asRect(out_col, out_pos);
			asRect(out_col, plus_pos);
			asRect(empty_col, empty_pos);
			asRect(battery_col, battery_pos);
			return *this;
		}

		//カウンター出力
		bool Down() const { return counter.Down(); };
		bool Up() const { return counter.Up(); };
		int32_t Count() const { return counter.Count(); };
		bool Down0() { return counter.Down0(); };
		bool Up0() { return counter.Up0(); };
		int32_t Count0() { return counter.Count0(); };
		int32_t Touch() const { return this->touch_num; };
		int32_t Touch0() { const int32_t num = this->touch_num; this->touch_num = 0; return num; };
		Battery& touch(const Pos2& add_pos)
		{
			bool is_touch = false;
			const Pos4 p = { this->touch_pos.x1 - add_pos.x ,this->touch_pos.y1 - add_pos.y ,this->touch_pos.x2 - add_pos.x ,this->touch_pos.y2 - add_pos.y };

			//タッチのあたり判定
			if (p.x1 <= 0 && p.y1 <= 0 && p.x2 >= 0 && p.y2 >= 0) is_touch = true;
			else if (p.x1 > 0 && p.y1 > 0 && p.x2 < 0 && p.y2 < 0) is_touch = true;

			//タッチの数をカウント
			if (is_touch && this->touch_num != INT32_MAX) this->touch_num++;
			return *this;
		}
		//タッチ初期化
		Battery& initTouch() { this->touch_num = 0; return *this; };
		//タッチカウント
		Battery& update() { this->counter.update(this->touch_num); return *this; };

		//バッテリー専用の出力
		int32_t Power() { return this->battery_power = asBattery(); }

	private:

		PosL4 out_pos;
		PosL4 plus_pos;
		PosL4 empty_pos;
		PosL4 battery_pos;
		Pos4 touch_pos;

		Color empty_col;
		Color battery_col;
		Color out_col;

		int32_t battery_power;

		//あたり判定
		Counter counter;

		//タッチ数
		int32_t touch_num = 0;

	};


}
