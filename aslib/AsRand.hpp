//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asƒ‰ƒCƒuƒ‰ƒŠ
//
//                    §ìÒ: ‚ª‚Á‚¿‚å (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{

	static uint32_t rand_32 = UINT32_MAX;
	uint32_t asRand32()
	{
		rand_32 = rand_32 ^ (rand_32 << 13);
		rand_32 = rand_32 ^ (rand_32 >> 17);
		return rand_32 = rand_32 ^ (rand_32 << 5);
	}

	int32_t asSRand32(const uint32_t srand_32) {
		if (srand_32 == 0) return -1;
		rand_32 = srand_32;
		return 0;
	}

	int32_t asRand32(const int32_t i)
	{
		if (i <= 0) return 0;

		switch (i) {
		case INT32_MAX:return int32_t(asRand32() & INT32_MAX);
		default:return (int32_t(asRand32() & INT32_MAX) % (i + 1));
		}
	}

	int32_t asRand32(const uint32_t i)
	{
		if (i == 0) return 0;
		if (i >= INT32_MAX) return int32_t(asRand32() & INT32_MAX);
		return (int32_t(asRand32() & INT32_MAX) % (i + 1));
	}


	static uint8_t rand_8 = UINT8_MAX;
	uint8_t asRand8()
	{
		rand_8 ^= (rand_8 << 7);
		rand_8 ^= (rand_8 >> 7);
		return rand_8 ^= (rand_8 << 1);
	}

	int32_t asSRand8(const uint8_t srand_8) {
		if (srand_8 == 0) return -1;
		rand_8 = srand_8;
		return 0;
	}

	uint8_t asRand8(const uint8_t i)
	{
		switch (i) {
		case 0:return 0;
		case UINT8_MAX:return asRand8();
		default:return (asRand8() % (i + 1));
		}
	}

	uint8_t asRand8(const int64_t i)
	{
		if (i >= UINT8_MAX) return asRand8(uint8_t(UINT8_MAX));
		else return asRand8(uint8_t(i));
	}

}
