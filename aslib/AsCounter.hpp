//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asライブラリ
//
//                    制作者: がっちょ (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
	struct Counter
	{
	public:
		void update(const bool);
		void update(const int32_t u_) { (u_ == 0) ? this->update(false) : this->update(true); }
		//出力
		const bool Down() const { return this->down; };
		const bool Up() const { return this->up; };
		const int32_t Count() const { return this->count; };
		const bool Down0() { const bool isDown = down; this->down = false; return isDown; };
		const bool Up0() { const bool isUp = up; this->up = false; return isUp; };
		const int32_t Count0() { const int32_t isCount = count; this->count = 0; return isCount; };

	private:
		bool down = false;
		bool up = false;
		int32_t count = 0;
	};

	inline void Counter::update(const bool is_down)
	{
		//押されたか
		if (is_down) {
			//押された瞬間か
			if (count == 0) down = true;
			else down = false;
			//カウントを増やす
			if (count < INT32_MAX) ++count;
		}
		else {
			//離された瞬間か
			if (count != 0) up = true;
			else up = false;
			//カウントをリセット
			count = 0;
		}
	}
}
