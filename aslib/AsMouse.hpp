//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asライブラリ
//
//                    制作者: がっちょ (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{

	//マウスID
	enum :size_t {
		MOUSE_LEFT,
		MOUSE_RIGHT,
		MOUSE_MIDDLE,
		MOUSE_4,
		MOUSE_5,
		MOUSE_6,
		MOUSE_7,
		MOUSE_8,
		MOUSE_9,
		MOUSE_10,
	};

	//マウスのボタン数
	constexpr size_t mouse_button_num = 10;



	//マウスの位置
	Pos2 mousePos()
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		int mouse_x = 0, mouse_y = 0;
		DxLib::GetMousePoint(&mouse_x, &mouse_y);

		Pos2 pos;
		pos(int32_t(mouse_x), int32_t(mouse_y));
		return pos;
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		//todo
		Pos2 pos;
		pos= s3d::Cursor::Pos();
		return pos;
#else //Console

#endif
	}

	//マウスのホイール回転量(奥:負 手前:正)
	inline int32_t mouseWheel()
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		//return int32_t(DxLib::GetMouseWheelRotVol(TRUE));
		return 0;
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		return int32_t(s3d::Mouse::Wheel());
#else //Console

#endif
	}

	inline void mouseButton(Counter count[mouse_button_num])
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		const int mouse_input = DxLib::GetMouseInput();
		count[MOUSE_LEFT].update((mouse_input & MOUSE_INPUT_LEFT) != 0);
		count[MOUSE_RIGHT].update((mouse_input & MOUSE_INPUT_RIGHT) != 0);
		count[MOUSE_MIDDLE].update((mouse_input & MOUSE_INPUT_MIDDLE) != 0);
		count[MOUSE_4].update((mouse_input & MOUSE_INPUT_4) != 0);
		count[MOUSE_5].update((mouse_input & MOUSE_INPUT_5) != 0);
		count[MOUSE_6].update((mouse_input & MOUSE_INPUT_6) != 0);
		count[MOUSE_7].update((mouse_input & MOUSE_INPUT_7) != 0);
		count[MOUSE_8].update((mouse_input & MOUSE_INPUT_8) != 0);
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		count[MOUSE_LEFT].update(s3d::MouseL.pressed() != 0);
		count[MOUSE_RIGHT].update(s3d::MouseR.pressed() != 0);
		count[MOUSE_MIDDLE].update(s3d::MouseM.pressed() != 0);
		count[MOUSE_4].update(s3d::MouseX1.pressed() != 0);
		count[MOUSE_5].update(s3d::MouseX2.pressed() != 0);
		count[MOUSE_6].update(s3d::MouseX3.pressed() != 0);
		count[MOUSE_7].update(s3d::MouseX4.pressed() != 0);
		count[MOUSE_8].update(s3d::MouseX5.pressed() != 0);
#else //Console

#endif
	}



	class Mouse 
	{
	public:
		Pos2 Pos() const { return mousePos(); };
		int32_t Wheel() const { return this->wheel; };
		Counter Count(const size_t count_num) const { return this->counter[count_num]; };

		Mouse& update();
		bool down() const { return this->counter[MOUSE_LEFT].Down(); };
		bool up() const { return this->counter[MOUSE_LEFT].Up(); };
		int32_t count() const { return this->counter[MOUSE_LEFT].Count(); };

	private:
		Pos2 pos;
		int32_t wheel;
		
		Counter counter[mouse_button_num];
	};

	inline Mouse& Mouse::update()
	{
		this->pos = mousePos();
		this->wheel = mouseWheel();
		mouseButton(this->counter);
		return *this;
	}

}
