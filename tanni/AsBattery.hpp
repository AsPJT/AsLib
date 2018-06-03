//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asライブラリ
//
//                    制作者: がっちょ (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{

#if defined(ASLIB_INCLUDE_DL) //DxLib

	//バッテリー取得
	inline int32_t asBattery() {
		return int32_t(DxLib::GetBatteryLifePercent());
	}

#elif defined(ASLIB_INCLUDE_S3) //Siv3D

#else //Console

#endif

	//バッテリー描画
	int32_t asBatteryDraw(const PosL4 pos_, const ColorRGBA in_col = { 0,192,32,255 }, const ColorRGBA out_col = { 75,75,75,255 })
	{
		const ColorRGBA empty_col = { 255,255,255,out_col.a };

		//バッテリー外枠
		PosL4 pos = pos_;
		pos.h = pos_.w / 2;

		//バッテリー+
		PosL4 out_pos;
		out_pos.x = pos_.x + pos_.w;
		out_pos.h = (pos.w >> 2);
		out_pos.y = pos_.y + ((pos.h - out_pos.h) >> 1);
		out_pos.w = (pos_.w >> 3);

		//バッテリー空
		PosL4 in_pos;
		in_pos.x = pos_.x+ pos_.w / 10;
		in_pos.y = pos_.y + pos.w * 9 / 100;
		in_pos.w = (pos_.w << 2) / 5;
		in_pos.h = (pos.w << 3) / 25;

		const int32_t battery_power = asBattery();

		//バッテリー容量
		PosL4 in_pos2 = in_pos;
		in_pos2.w = in_pos.w*battery_power / 100;

		asRect(out_col, pos);
		asRect(out_col, out_pos);
		asRect(empty_col, in_pos);
		asRect(in_col, in_pos2);

		return 0;
	}

}
