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
		Counter& update(const int32_t);
		Counter& update(const bool);

		Counter() = default;
		~Counter() = default;

		//出力
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
		return *this;
	}

	inline Counter& Counter::update(const int32_t is_down)
	{
		//押されたか
		if (is_down > 0) {
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
		return *this;
	}

}
