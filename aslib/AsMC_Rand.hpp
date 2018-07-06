//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsÉâÉCÉuÉâÉä
//
//                    êßçÏé“: Ç™Ç¡ÇøÇÂ (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{

	inline const int32_t MainControl::rand32_0toMax(const int32_t i)
	{
		if (i <= 0) return 0;

		switch (i) {
		case INT32_MAX:return int32_t(rand32() & INT32_MAX);
		default:return (int32_t(rand32() & INT32_MAX) % (i + 1));
		}
	}


	inline const uint32_t MainControl::rand32()
	{
		rand_32 = rand_32 ^ (rand_32 << 13);
		rand_32 = rand_32 ^ (rand_32 >> 17);
		return rand_32 = rand_32 ^ (rand_32 << 5);
	}

	inline const uint8_t MainControl::rand8_0toMax(const uint8_t i)
	{
		switch (i) {
		case 0:return 0;
		case UINT8_MAX:return this->rand8();
		default:return (this->rand8() % (i + 1));
		}
	}

	inline const uint8_t MainControl::rand8(const uint8_t number)
	{
		uint8_t shift_1, shift_2, shift_3;

		switch (number)
		{
		case 0: shift_1 = 1; shift_2 = 1; shift_3 = 2; break;
		case 1: shift_1 = 1; shift_2 = 1; shift_3 = 3; break;
		case 2: shift_1 = 1; shift_2 = 7; shift_3 = 3; break;
		case 3: shift_1 = 1; shift_2 = 7; shift_3 = 6; break;
		case 4: shift_1 = 1; shift_2 = 7; shift_3 = 7; break;
		case 5: shift_1 = 2; shift_2 = 1; shift_3 = 1; break;
		case 6: shift_1 = 2; shift_2 = 5; shift_3 = 5; break;
		case 7: shift_1 = 3; shift_2 = 1; shift_3 = 1; break;
		case 8: shift_1 = 3; shift_2 = 1; shift_3 = 5; break;
		case 9: shift_1 = 3; shift_2 = 5; shift_3 = 4; break;
		case 10: shift_1 = 3; shift_2 = 5; shift_3 = 5; break;
		case 11: shift_1 = 3; shift_2 = 5; shift_3 = 7; break;
		case 12: shift_1 = 3; shift_2 = 7; shift_3 = 1; break;
		case 13: shift_1 = 4; shift_2 = 5; shift_3 = 3; break;
		case 14: shift_1 = 5; shift_2 = 1; shift_3 = 3; break;
		case 15: shift_1 = 5; shift_2 = 3; shift_3 = 6; break;
		case 16: shift_1 = 5; shift_2 = 3; shift_3 = 7; break;
		case 17: shift_1 = 5; shift_2 = 5; shift_3 = 2; break;
		case 18: shift_1 = 5; shift_2 = 5; shift_3 = 3; break;
		case 19: shift_1 = 6; shift_2 = 3; shift_3 = 5; break;
		case 20: shift_1 = 6; shift_2 = 7; shift_3 = 1; break;
		case 21: shift_1 = 7; shift_2 = 3; shift_3 = 5; break;
		case 22: shift_1 = 7; shift_2 = 5; shift_3 = 3; break;
		case 23: shift_1 = 7; shift_2 = 7; shift_3 = 1; break;
		default: shift_1 = 7; shift_2 = 7; shift_3 = 1; break;
	}

		rand_8 ^= (rand_8 << shift_1);
		rand_8 ^= (rand_8 >> shift_2);
		return rand_8 ^= (rand_8 << shift_3);
}


#if defined(ASLIB_INCLUDE_DL) //DxLib

#elif defined(ASLIB_INCLUDE_S3) //Siv3D

#else //Console

#endif

}
