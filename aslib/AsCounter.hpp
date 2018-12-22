//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsProject Library
//
//                    Created by Gaccho (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------
#ifndef INCLUDED_AS_PROJECT_LIBRARY_COUNTER
#define INCLUDED_AS_PROJECT_LIBRARY_COUNTER


namespace AsLib
{
	struct Counter
	{
	public:
		void update(const bool) noexcept;
		void update(const int32_t u_) noexcept { (u_ == 0) ? this->update(false) : this->update(true); }
		//�o��
		bool down() const noexcept { return this->key_down; };
		bool up() const noexcept { return this->key_up; };
		int32_t count() const noexcept { return this->key_count; };
		bool down0() noexcept { const bool isDown = key_down; this->key_down = false; return isDown; };
		bool up0() noexcept { const bool isUp = key_up; this->key_up = false; return isUp; };
		int32_t count0() noexcept { const int32_t isCount = key_count; this->key_count = 0; return isCount; };

	private:
		bool key_down{ false };
		bool key_up{ false };
		int32_t key_count{};
	};

	inline void Counter::update(const bool is_down) noexcept
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

#endif //Included AsProject Library