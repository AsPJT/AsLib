//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsÉâÉCÉuÉâÉä
//
//                    êßçÏé“: Ç™Ç¡ÇøÇÂ (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
	OriginatorBGM asLoadBGM(const char* const name_) {
		return 	DxLib::LoadSoundMem(name_);
	}

	class BGM {
	private:
		OriginatorBGM sound;
	public:
		BGM() = default;
		BGM(const char* const name_) :sound(DxLib::LoadSoundMem(name_)) {}
		BGM(OriginatorBGM&& sound_) :sound(std::move(sound_)) {}

		BGM& set(const char* const name_) { sound = DxLib::LoadSoundMem(name_); return *this; }

		BGM& stop() { DxLib::StopSoundMem(sound); return *this; }
		BGM& volume(uint8_t vol_) { DxLib::ChangeVolumeSoundMem(vol_, sound); return *this; }
		BGM& playStart() { DxLib::PlaySoundMem(sound, DX_PLAYTYPE_BACK, TRUE); return *this; }
		BGM& playStartLoop() { DxLib::PlaySoundMem(sound, DX_PLAYTYPE_LOOP, TRUE); return *this; }
		BGM& play() { DxLib::PlaySoundMem(sound, DX_PLAYTYPE_BACK, FALSE); return *this; }
		BGM& playLoop() { DxLib::PlaySoundMem(sound, DX_PLAYTYPE_LOOP, FALSE); return *this; }
		const bool isPlay() { if (DxLib::CheckSoundMem(sound) == 1) { return true; }return false; }

	};

#if defined(ASLIB_INCLUDE_DL) //DxLib
	
#elif defined(ASLIB_INCLUDE_S3) //Siv3D

#elif defined(ASLIB_INCLUDE_OF)

#elif defined(ASLIB_INCLUDE_TP)

#else //Console

#endif

}
