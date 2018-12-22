//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsProject Library
//
//                    Created by Gaccho (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------
#ifndef INCLUDED_AS_PROJECT_LIBRARY_DISTANCE
#define INCLUDED_AS_PROJECT_LIBRARY_DISTANCE


namespace AsLib
{
	//ÇQì_ä‘ÇÃãóó£ÇãÅÇﬂÇÈ
	inline float asHypot(const Pos2F& p_1, const Pos2F& p_2) noexcept { return hypot(p_1.x - p_2.x, p_1.y - p_2.y); }

	inline void asHypot(float& dis_, const Pos2F& p_1, const Pos2F& p_2) noexcept { dis_ = asHypot(p_1, p_2); }
	inline void asHypot(float* dis_, const Pos2F& p_1, const Pos2F& p_2) noexcept { *dis_ = asHypot(p_1, p_2); }
	inline void asHypot(const Pos2F& p_1, float& dis_, const Pos2F& p_2) noexcept { dis_ = asHypot(p_1, p_2); }
	inline void asHypot(const Pos2F& p_1, float* dis_, const Pos2F& p_2) noexcept { *dis_ = asHypot(p_1, p_2); }
	inline void asHypot(const Pos2F& p_1, const Pos2F& p_2, float& dis_) noexcept { dis_ = asHypot(p_1, p_2); }
	inline void asHypot(const Pos2F& p_1, const Pos2F& p_2, float* dis_) noexcept { *dis_ = asHypot(p_1, p_2); }

	//ÇQì_ä‘ÇÃãóó£Ç∆ç≈è¨ílÇî‰ärÇµÇƒè¨Ç≥Ç¢ílÇï‘Ç∑
	inline void asHypotMin(const Pos2F& p_1, const Pos2F& p_2, float& now_) noexcept
	{
		const float dis{ asHypot(p_1, p_2) };
		if (dis < now_) now_ = dis;
	}
	//ÇQì_ä‘ÇÃãóó£Ç∆ç≈è¨ílÇî‰ärÇµÇƒëÂÇ´Ç¢ílÇï‘Ç∑
	inline void asHypotMax(const Pos2F& p_1, const Pos2F& p_2, float& now_) noexcept
	{
		const float dis{ asHypot(p_1, p_2) };
		if (dis > now_) now_ = dis;
	}

	inline void asHypotMin(const Pos2F& p_1, const Pos2F& p_2, float& now_, size_t& id_, const size_t& id2_) noexcept
	{
		const float dis{ asHypot(p_1, p_2) };
		if (dis < now_) {
			now_ = dis;
			id_ = id2_;
		}
	}
	inline void asHypotMax(const Pos2F& p_1, const Pos2F& p_2, float& now_, size_t& id_, const size_t& id2_) noexcept
	{
		const float dis{ asHypot(p_1, p_2) };
		if (dis > now_) {
			now_ = dis;
			id_ = id2_;
		}
	}

	template<typename T>
	const int32_t searchMin(const std::vector<T>& t_, const Pos2& p_, size_t& dis_id, float* const dis_ = nullptr) noexcept
	{
		if (t_.size() == 0) return -1;

		float dis{ FLT_MAX };
		for (size_t i{}; i < t_.size(); ++i) { asHypotMin(p_, t_[i].PosF(), dis, dis_id, i); }
		if (dis_ != nullptr) *dis_ = dis;
		return 0;
	}

}

#endif //Included AsProject Library