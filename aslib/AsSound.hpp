//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsProject Library
//
//                    Created by Gaccho (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------
#ifndef INCLUDED_AS_PROJECT_LIBRARY_SOUND
#define INCLUDED_AS_PROJECT_LIBRARY_SOUND


namespace AsLib
{
	OriginatorBGM asLoadBGM(const char* const name_) noexcept {
#if defined(ASLIB_INCLUDE_DL) //DxLib
		return 	DxLib::LoadSoundMem(name_);
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		return OriginatorBGM(s3d::Unicode::UTF8ToUTF32(std::string(name_)));
#elif defined(ASLIB_INCLUDE_OF)
		return 0;
#elif defined(ASLIB_INCLUDE_C2)
return 0;
#elif defined(ASLIB_INCLUDE_SF)
return 0;
#elif defined(ASLIB_INCLUDE_TP)
#else //Console
		return 0;
#endif
}

	class AsBGM {
	private:
		OriginatorBGM sound;
	public:
		AsBGM() = default;
		AsBGM(const char* const name_) :sound(asLoadBGM(name_)) {}
		AsBGM& set(const char* const name_) noexcept { if (name_ != nullptr) sound = asLoadBGM(name_); return *this; }
#if defined(ASLIB_INCLUDE_DL) //DxLib
		AsBGM& stop() noexcept { DxLib::StopSoundMem(sound); return *this; }
		AsBGM& volume(const uint8_t vol_) noexcept { DxLib::ChangeVolumeSoundMem(vol_, sound); return *this; }
		AsBGM& playStart() noexcept { DxLib::PlaySoundMem(sound, DX_PLAYTYPE_BACK, TRUE); return *this; }
		AsBGM& playStartLoop() noexcept { DxLib::PlaySoundMem(sound, DX_PLAYTYPE_LOOP, TRUE); return *this; }
		AsBGM& play() noexcept { DxLib::PlaySoundMem(sound, DX_PLAYTYPE_BACK, FALSE); return *this; }
		AsBGM& playLoop() noexcept { DxLib::PlaySoundMem(sound, DX_PLAYTYPE_LOOP, FALSE); return *this; }
		bool isPlay() noexcept { if (DxLib::CheckSoundMem(sound) == 1) { return true; }return false; }
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		AsBGM& stop() noexcept { sound.pause(); return *this; }
		AsBGM& play() noexcept { sound.play(); return *this; }
		AsBGM& playStart() noexcept { sound.stop(); return this->play(); }
		AsBGM& playStartLoop() noexcept { sound.stop(); sound.setLoop(true); return this->play(); }
		AsBGM& playLoop() noexcept { sound.setLoop(true); return this->play(); }
		AsBGM& volume(const uint8_t vol_) noexcept { sound.setVolume(double(vol_) / 255.0); return *this; }
#elif defined(ASLIB_INCLUDE_OF)
		AsBGM& stop() noexcept { return *this; }
		AsBGM& play() noexcept { return *this; }
		AsBGM& playStart() noexcept { return *this; }
		AsBGM& playStartLoop() noexcept { return *this; }
		AsBGM& playLoop() noexcept { return *this; }
		AsBGM& volume(const uint8_t vol_) noexcept { return *this; }
#else //Console
		AsBGM& stop() noexcept { return *this; }
		AsBGM& play() noexcept { return *this; }
		AsBGM& playStart() noexcept { return *this; }
		AsBGM& playStartLoop() noexcept { return *this; }
		AsBGM& playLoop() noexcept { return *this; }
		AsBGM& volume(const uint8_t vol_) noexcept { return *this; }
#endif
	};


	


}

#endif //Included AsProject Library