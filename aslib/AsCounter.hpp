/*#######################################################################################
	Made by Kasugaccho
	Made by As Project
	https://github.com/Kasugaccho/AsLib
	wanotaitei@gmail.com

	This code is licensed under CC0.
#######################################################################################*/
#ifndef INCLUDED_AS_PROJECT_LIBRARY_COUNTER
#define INCLUDED_AS_PROJECT_LIBRARY_COUNTER


namespace AsLib
{
	struct Counter
	{
	public:
		void update(const bool) noexcept;
		void update(const std::int32_t u_) noexcept { (u_ == 0) ? this->update(false) : this->update(true); }
		//出力
		bool down() const noexcept { return this->key_down; };
		bool up() const noexcept { return this->key_up; };
		std::int32_t count() const noexcept { return this->key_count; };
		bool down0() noexcept { const bool isDown = key_down; this->key_down = false; return isDown; };
		bool up0() noexcept { const bool isUp = key_up; this->key_up = false; return isUp; };
		std::int32_t count0() noexcept { const std::int32_t isCount = key_count; this->key_count = 0; return isCount; };

	private:
		bool key_down{ false };
		bool key_up{ false };
		std::int32_t key_count{};
	};

	inline void Counter::update(const bool is_down) noexcept
	{
		//押されたか
		if (is_down) {
			//押された瞬間か
			if (key_count == 0) key_down = true;
			else key_down = false;
			//カウントを増やす
			if (key_count < INT32_MAX) ++key_count;
		}
		else {
			//離された瞬間か
			if (key_count != 0) key_up = true;
			else key_up = false;
			//カウントをリセット
			key_count = 0;
		}
	}
}

#endif //Included AsProject Library