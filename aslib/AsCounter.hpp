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
		Counter& update(const bool);

		Counter() = default;
		~Counter() = default;

		//�o��
		bool Down() const { return this->down; };
		bool Up() const { return this->up; };
		int32_t Count() const { return this->count; };
		bool Down0() { const bool isDown = down; this->down = false; return isDown; };
		bool Up0() { const bool isUp = up; this->up = false; return isUp; };
		int32_t Count0() { const int32_t isCount = count; this->count = 0; return isCount; };

	private:
		bool down = false;
		bool up = false;
		int32_t count = 0;
	};

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
