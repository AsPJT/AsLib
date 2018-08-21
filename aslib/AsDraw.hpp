//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsProject Library
//
//                    Created by Gaccho (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
	const bool asIsDraw(const PosL4& p_) {
		return (p_.x == 0 && p_.y == 0 && p_.w == 0 && p_.h == 0) ? true : false;
	}
	//描画位置を記録する関数
	const PosL4 asDrawPosSave(const bool b_=false, const PosL4& p_ = pos4_0)
	{
		//記録保存変数
		static thread_local PosL4 p(0, 0, 0, 0);
		//読み取り時
		if (b_) {
			p = p_;
			return p;
		}
		PosL4 p2 = p;
		p(0, 0, 0, 0);
		return p2;
	}
	inline const PosL4 asSetDrawPosSave(const PosL4& p_ = pos4_0) {
		return asDrawPosSave(true, p_);
	}
	//描画IDを記録する関数
	const size_t asDrawNumSave(const bool b_ = false, const size_t& p_ = 0)
	{
		//記録保存変数
		static thread_local size_t p{};
		//読み取り時
		if (b_) {
			p = p_;
			return p;
		}
		size_t p2 = p;
		p = 0;
		return p2;
	}
	inline const size_t asSetDrawNumSave(const size_t p_ = 0) {
		return asDrawNumSave(true, p_);
	}
	//描画透過度を記録する関数
	const uint8_t asDrawAlphaSave(const bool b_ = false, const uint8_t& p_ = (uint8_t)255)
	{
		//記録保存変数
		static thread_local uint8_t p = 255;
		//読み取り時
		if (b_) {
			p = p_;
			return p;
		}
		uint8_t p2 = p;
		p = (uint8_t)255;
		return p2;
	}
	inline const uint8_t asSetDrawAlphaSave(const uint8_t p_ = (uint8_t)255) {
		return asDrawAlphaSave(true, p_);
	}


}
