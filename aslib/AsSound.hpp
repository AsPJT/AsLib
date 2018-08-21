//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsProject Library
//
//                    Created by Gaccho (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
	OriginatorBGM asLoadBGM(const char* const name_) {
#if defined(ASLIB_INCLUDE_DL) //DxLib
		return 	DxLib::LoadSoundMem(name_);
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		return OriginatorBGM(s3d::Unicode::UTF8ToUTF32(std::string(name_)));
#elif defined(ASLIB_INCLUDE_OF)
		return 0;
#elif defined(ASLIB_INCLUDE_C2)
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
		AsBGM& set(const char* const name_) { if (name_ != nullptr) sound = asLoadBGM(name_); return *this; }
#if defined(ASLIB_INCLUDE_DL) //DxLib
		AsBGM& stop() { DxLib::StopSoundMem(sound); return *this; }
		AsBGM& volume(const uint8_t vol_) { DxLib::ChangeVolumeSoundMem(vol_, sound); return *this; }
		AsBGM& playStart() { DxLib::PlaySoundMem(sound, DX_PLAYTYPE_BACK, TRUE); return *this; }
		AsBGM& playStartLoop() { DxLib::PlaySoundMem(sound, DX_PLAYTYPE_LOOP, TRUE); return *this; }
		AsBGM& play() { DxLib::PlaySoundMem(sound, DX_PLAYTYPE_BACK, FALSE); return *this; }
		AsBGM& playLoop() { DxLib::PlaySoundMem(sound, DX_PLAYTYPE_LOOP, FALSE); return *this; }
		const bool isPlay() { if (DxLib::CheckSoundMem(sound) == 1) { return true; }return false; }
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		AsBGM& stop() { sound.pause(); return *this; }
		AsBGM& play() { sound.play(); return *this; }
		AsBGM& playStart() { sound.stop(); return this->play(); }
		AsBGM& playStartLoop() { sound.stop(); sound.setLoop(true); return this->play(); }
		AsBGM& playLoop() { sound.setLoop(true); return this->play(); }
		AsBGM& volume(const uint8_t vol_) { sound.setVolume(double(vol_) / 255.0); return *this; }
#elif defined(ASLIB_INCLUDE_OF)
		AsBGM& stop() { return *this; }
		AsBGM& play() { return *this; }
		AsBGM& playStart() { return *this; }
		AsBGM& playStartLoop() { return *this; }
		AsBGM& playLoop() { return *this; }
		AsBGM& volume(const uint8_t vol_) { return *this; }
#else //Console
		AsBGM& stop() { return *this; }
		AsBGM& play() { return *this; }
		AsBGM& playStart() { return *this; }
		AsBGM& playStartLoop() { return *this; }
		AsBGM& playLoop() { return *this; }
		AsBGM& volume(const uint8_t vol_) { return *this; }
#endif
	};


	


}
