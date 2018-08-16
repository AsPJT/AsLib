//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsProject Library
//
//                    Created by Gaccho (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
	struct Counter
	{
	public:
		void update(const bool);
		void update(const int32_t u_) { (u_ == 0) ? this->update(false) : this->update(true); }
		//�o��
		const bool down() const { return this->key_down; };
		const bool up() const { return this->key_up; };
		const int32_t count() const { return this->key_count; };
		const bool down0() { const bool isDown = key_down; this->key_down = false; return isDown; };
		const bool up0() { const bool isUp = key_up; this->key_up = false; return isUp; };
		const int32_t count0() { const int32_t isCount = key_count; this->key_count = 0; return isCount; };

	private:
		bool key_down = false;
		bool key_up = false;
		int32_t key_count = 0;
	};

	inline void Counter::update(const bool is_down)
	{
		//�����ꂽ��
		if (is_down) {
			//�����ꂽ�u�Ԃ�
			if (key_count == 0) key_down = true;
			else key_down = false;
			//�J�E���g�𑝂₷
			if (key_count < INT32_MAX) ++key_count;
		}
		else {
			//�����ꂽ�u�Ԃ�
			if (key_count != 0) key_up = true;
			else key_up = false;
			//�J�E���g�����Z�b�g
			key_count = 0;
		}
	}
}
