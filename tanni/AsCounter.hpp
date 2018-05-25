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

		//出力
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
