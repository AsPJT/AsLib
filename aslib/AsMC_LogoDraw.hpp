//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asライブラリ
//
//                    制作者: がっちょ (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{

	//フェードインアウトのタイトルロゴのシーンチェンジ
	inline MainControl& MainControl::logoAnime(const size_t add_texture_id, const int32_t add_in_time, const int32_t add_out_time, const int32_t add_time, const size_t add_scene)
	{
		static int32_t time_counter = 0;
		time_counter += time_counter_ms / this->fps;

		uint8_t alpha;
		float before_alpha;

		if (time_counter >= add_out_time) {
			before_alpha = float(add_time - time_counter) / float(add_time - add_out_time);
			if (before_alpha < 0) alpha = 0;
			else alpha = uint8_t(255 * before_alpha);
		}
		else if (time_counter <= add_in_time) {
			before_alpha = float(time_counter) / float(add_in_time);
			if (before_alpha < 0) alpha = 0;
			else alpha = uint8_t(255 * before_alpha);
		}
		else alpha = 255;

		vecAnimeUI[add_texture_id].drawA(init_data.windowSize(), alpha).fpsUpdate();

		if (time_counter >= add_time) {
			time_counter = 0;
			scene(add_scene);
		}

		return *this;
	}

#if defined(ASLIB_INCLUDE_DL) //DxLib

#elif defined(ASLIB_INCLUDE_S3) //Siv3D

#else //Console

#endif

}
