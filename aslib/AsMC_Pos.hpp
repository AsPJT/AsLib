//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asƒ‰ƒCƒuƒ‰ƒŠ
//
//                    §ìŽÒ: ‚ª‚Á‚¿‚å (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{

	inline Pos4 MainControl::asPos4(const Pos4R pos_)
	{
		Pos4 pos;
		pos(pos_, this->init_data.windowSize());
		return pos;
	}


}
