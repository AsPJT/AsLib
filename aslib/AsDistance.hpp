//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - As���C�u����
//
//                    �����: �������� (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
	//�Q�_�Ԃ̋��������߂�
	inline const float asHypot(const Pos2R& p_1, const Pos2R& p_2) { return hypot(p_1.x - p_2.x, p_1.y - p_2.y); }

	inline const void asHypot(float& dis_, const Pos2R& p_1, const Pos2R& p_2) { dis_ = asHypot(p_1, p_2); }
	inline const void asHypot(float* dis_, const Pos2R& p_1, const Pos2R& p_2) { *dis_ = asHypot(p_1, p_2); }
	inline const void asHypot(const Pos2R& p_1, float& dis_, const Pos2R& p_2) { dis_ = asHypot(p_1, p_2); }
	inline const void asHypot(const Pos2R& p_1, float* dis_, const Pos2R& p_2) { *dis_ = asHypot(p_1, p_2); }
	inline const void asHypot(const Pos2R& p_1, const Pos2R& p_2, float& dis_) { dis_ = asHypot(p_1, p_2); }
	inline const void asHypot(const Pos2R& p_1, const Pos2R& p_2, float* dis_) { *dis_ = asHypot(p_1, p_2); }

	//�Q�_�Ԃ̋����ƍŏ��l���r���ď������l��Ԃ�
	inline void asHypotMin(const Pos2R& p_1, const Pos2R& p_2, float& now_)
	{
		const float dis = asHypot(p_1, p_2);
		if (dis < now_) now_ = dis;
	}
	//�Q�_�Ԃ̋����ƍŏ��l���r���đ傫���l��Ԃ�
	inline void asHypotMax(const Pos2R& p_1, const Pos2R& p_2, float& now_)
	{
		const float dis = asHypot(p_1, p_2);
		if (dis > now_) now_ = dis;
	}

	inline void asHypotMin(const Pos2R& p_1, const Pos2R& p_2, float& now_, size_t& id_, const size_t& id2_)
	{
		const float dis = asHypot(p_1, p_2);
		if (dis < now_) {
			now_ = dis;
			id_ = id2_;
		}
	}
	inline void asHypotMax(const Pos2R& p_1, const Pos2R& p_2, float& now_, size_t& id_, const size_t& id2_)
	{
		const float dis = asHypot(p_1, p_2);
		if (dis > now_) {
			now_ = dis;
			id_ = id2_;
		}
	}

	template<typename T>
	int32_t searchMin(const std::vector<T>& t_, const Pos2& p_, size_t& dis_id, float* const dis_ = nullptr)
	{
		if (t_.size() == 0) return -1;

		float dis = FLT_MAX;
		for (size_t i = 0; i < t_.size(); ++i) { asHypotMin(p_, t_[i].PosF(), dis, dis_id, i); }
		if (dis_ != nullptr) *dis_ = dis;
		return 0;
	}

}
