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
		Counter& update(const bool);
		uint8_t Down();
		uint8_t Up();
		int32_t Count();

	private:
		uint8_t down = false;
		uint8_t up = false;
		int32_t count = 0;
	};

	inline uint8_t Counter::Down()
	{
		return down;
	}

	inline uint8_t Counter::Up()
	{
		return up;
	}

	inline int32_t Counter::Count()
	{
		return count;
	}

	inline Counter& Counter::update(const bool is_down)
	{
		//�����ꂽ��
		if (is_down) {
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
