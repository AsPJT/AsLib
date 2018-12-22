//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsProject Library
//
//                    Created by Gaccho (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------
#ifndef INCLUDED_AS_PROJECT_LIBRARY_DRAW
#define INCLUDED_AS_PROJECT_LIBRARY_DRAW


namespace AsLib
{
	bool asIsDraw(const PosL4& p_) noexcept {
		return (p_.x == 0 && p_.y == 0 && p_.w == 0 && p_.h == 0) ? true : false;
	}
	//描画位置を記録する関数
	PosL4 asDrawPosSave(const bool b_=false, const PosL4& p_ = pos4_0) noexcept
	{
		//記録保存変数
		static thread_local PosL4 p(0, 0, 0, 0);
		//読み取り時
		if (b_) {
			p = p_;
			return p;
		}
		PosL4 p2{ p };
		p(0, 0, 0, 0);
		return p2;
	}
	inline PosL4 asSetDrawPosSave(const PosL4& p_ = pos4_0) noexcept {
		return asDrawPosSave(true, p_);
	}
	//描画IDを記録する関数
	size_t asDrawNumSave(const bool b_ = false, const size_t& p_ = 0) noexcept
	{
		//記録保存変数
		static thread_local size_t p{};
		//読み取り時
		if (b_) {
			p = p_;
			return p;
		}
		size_t p2{ p };
		p = 0;
		return p2;
	}
	inline size_t asSetDrawNumSave(const size_t p_ = 0) noexcept {
		return asDrawNumSave(true, p_);
	}
	//描画透過度を記録する関数
	uint8_t asDrawAlphaSave(const bool b_ = false, const uint8_t& p_ = (uint8_t)255) noexcept
	{
		//記録保存変数
		static thread_local uint8_t p{ 255 };
		//読み取り時
		if (b_) {
			p = p_;
			return p;
		}
		uint8_t p2{ p };
		p = (uint8_t)255;
		return p2;
	}
	inline uint8_t asSetDrawAlphaSave(const uint8_t p_ = (uint8_t)255) noexcept {
		return asDrawAlphaSave(true, p_);
	}


}

#endif //Included AsProject Library