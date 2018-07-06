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
	const uint32_t asRand32()
	{
		rand_32 = rand_32 ^ (rand_32 << 13);
		rand_32 = rand_32 ^ (rand_32 >> 17);
		return rand_32 = rand_32 ^ (rand_32 << 5);
	}
	const int32_t asSRand32(const uint32_t srand_32) {
		if (srand_32 == 0) return -1;
		rand_32 = srand_32;
		return 0;
	}

	inline void asRand32(int32_t* const i) { *i = int32_t(asRand32()); }
	inline void asRand32(int32_t* const array_, const size_t s_) { for (size_t i = 0; i < s_; ++i) array_[i] = int32_t(asRand32()); }
	inline void asRand32(std::vector<int32_t>& array_) { const size_t s = array_.size(); for (size_t i = 0; i < s; ++i) array_[i] = int32_t(asRand32()); }

	inline const int32_t asRand() { return int32_t(asRand32()); }


	const int32_t asRand32(const int32_t i)
	{
		if (i <= 0) return 0;

		switch (i) {
		case INT32_MAX:return int32_t(asRand32() & INT32_MAX);
		default:return (int32_t(asRand32() & INT32_MAX) % (i + 1));
		}
	}

	const int32_t asRand32(const uint32_t i)
	{
		if (i == 0) return 0;
		if (i >= INT32_MAX) return int32_t(asRand32() & INT32_MAX);
		return (int32_t(asRand32() & INT32_MAX) % (i + 1));
	}


	static uint8_t rand_8 = UINT8_MAX;
	const uint8_t asRand8()
	{
		rand_8 ^= (rand_8 << 7);
		rand_8 ^= (rand_8 >> 7);
		return rand_8 ^= (rand_8 << 1);
	}

	const int32_t asSRand8(const uint8_t srand_8) {
		if (srand_8 == 0) return -1;
		rand_8 = srand_8;
		return 0;
	}

	const uint8_t asRand8(const uint8_t i)
	{
		switch (i) {
		case 0:return 0;
		case UINT8_MAX:return asRand8();
		default:return (asRand8() % (i + 1));
		}
	}

	inline const uint8_t asRand8(const int32_t i) { return asRand8(uint8_t(i)); }

	const uint8_t asRand8(const int64_t i)
	{
		if (i >= UINT8_MAX) return asRand8(uint8_t(UINT8_MAX));
		else return asRand8(uint8_t(i));
	}

}
