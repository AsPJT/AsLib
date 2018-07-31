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
#elif defined(ASLIB_INCLUDE_TP)
#else //Console
		return 0;
#endif
}

	class BGM {
	private:
		OriginatorBGM sound;
	public:
		BGM() = default;
		BGM(const char* const name_) :sound(asLoadBGM(name_)) {}
		BGM& set(const char* const name_) { if (name_ != nullptr) sound = asLoadBGM(name_); return *this; }
#if defined(ASLIB_INCLUDE_DL) //DxLib
		BGM& stop() { DxLib::StopSoundMem(sound); return *this; }
		BGM& volume(const uint8_t vol_) { DxLib::ChangeVolumeSoundMem(vol_, sound); return *this; }
		BGM& playStart() { DxLib::PlaySoundMem(sound, DX_PLAYTYPE_BACK, TRUE); return *this; }
		BGM& playStartLoop() { DxLib::PlaySoundMem(sound, DX_PLAYTYPE_LOOP, TRUE); return *this; }
		BGM& play() { DxLib::PlaySoundMem(sound, DX_PLAYTYPE_BACK, FALSE); return *this; }
		BGM& playLoop() { DxLib::PlaySoundMem(sound, DX_PLAYTYPE_LOOP, FALSE); return *this; }
		const bool isPlay() { if (DxLib::CheckSoundMem(sound) == 1) { return true; }return false; }
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		BGM& stop() { sound.pause(); return *this; }
		BGM& play() { sound.play(); return *this; }
		BGM& playStart() { sound.stop(); return this->play(); }
		BGM& playStartLoop() { sound.stop(); sound.setLoop(true); return this->play(); }
		BGM& playLoop() { sound.setLoop(true); return this->play(); }
		BGM& volume(const uint8_t vol_) { sound.setVolume(double(vol_) / 255.0); return *this; }
#elif defined(ASLIB_INCLUDE_OF)
		BGM& stop() { return *this; }
		BGM& play() { return *this; }
		BGM& playStart() { return *this; }
		BGM& playStartLoop() { return *this; }
		BGM& playLoop() { return *this; }
		BGM& volume(const uint8_t vol_) { return *this; }
#else //Console
		BGM& stop() { return *this; }
		BGM& play() { return *this; }
		BGM& playStart() { return *this; }
		BGM& playStartLoop() { return *this; }
		BGM& playLoop() { return *this; }
		BGM& volume(const uint8_t vol_) { return *this; }
#endif
	};


	


}
