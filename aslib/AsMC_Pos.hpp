//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - As���C�u����
//
//                    �����: �������� (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{

	inline const Pos4 MainControl::asPos4(const Pos4F pos_)
	{
		const Pos4 pos(pos_, this->init_data.windowSize());
		return pos;
	}


}
