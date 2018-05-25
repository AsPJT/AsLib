//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - As���C�u����
//
//                    �����: �������� (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{

	struct Counter
	{
	public:
		Counter& update(const int32_t);

		//�o��
		bool Down() const { return down; };
		bool Up() const { return up; };
		int32_t Count() const { return count; };

	private:
		bool down = false;
		bool up = false;
		int32_t count = 0;
	};

	inline Counter& Counter::update(const int32_t is_down)
	{
		//�����ꂽ��
		if (is_down > 0) {
			//�����ꂽ�u�Ԃ�
			if (count == 0) down = true;
			else down = false;
			//�J�E���g�𑝂₷
			if (count < INT32_MAX) ++count;
		}
		else {
			//�����ꂽ�u�Ԃ�
			if (count != 0) up = true;
			else up = false;
			//�J�E���g�����Z�b�g
			count = 0;
		}
		return *this;
	}

}
