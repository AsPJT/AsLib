//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsProject Library
//
//                    Created by Gaccho (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------
#ifndef INCLUDED_AS_PROJECT_LIBRARY_RAND
#define INCLUDED_AS_PROJECT_LIBRARY_RAND


namespace AsLib
{

	static uint32_t rand_32{ UINT32_MAX };
	uint32_t asRand32() noexcept
	{
		rand_32 = rand_32 ^ (rand_32 << 13);
		rand_32 = rand_32 ^ (rand_32 >> 17);
		return rand_32 = rand_32 ^ (rand_32 << 5);
	}
	int32_t asSRand32(const uint32_t srand_32) noexcept {
		if (srand_32 == 0) return -1;
		rand_32 = srand_32;
		return 0;
	}

	inline void asRand32(int32_t* const i) noexcept { *i = int32_t(asRand32()); }
	inline void asRand32(int32_t* const array_, const size_t s_) noexcept { for (size_t i{}; i < s_; ++i) array_[i] = int32_t(asRand32()); }
	inline void asRand32(std::vector<int32_t>& array_) noexcept { const size_t s = array_.size(); for (size_t i{}; i < s; ++i) array_[i] = int32_t(asRand32()); }

	inline int32_t asRand() noexcept { return int32_t(asRand32()); }

	int32_t asRand32(const int32_t i) noexcept
	{
		if (i <= 0) return 0;

		switch (i) {
		case INT32_MAX:return int32_t(asRand32() & INT32_MAX);
		default:return (int32_t(asRand32() & INT32_MAX) % (i + 1));
		}
	}

	int32_t asRand32(const uint32_t i) noexcept
	{
		if (i == 0) return 0;
		if (i >= INT32_MAX) return int32_t(asRand32() & INT32_MAX);
		return (int32_t(asRand32() & INT32_MAX) % (i + 1));
	}
	inline int32_t asRand(const uint32_t rand_) noexcept { return int32_t(asRand32(rand_)); }


	static uint8_t rand_8{ UINT8_MAX };
	uint8_t asRand8() noexcept
	{
		rand_8 ^= (rand_8 << 7);
		rand_8 ^= (rand_8 >> 7);
		return rand_8 ^= (rand_8 << 1);
	}

	int32_t asSRand8(const uint8_t srand_8) noexcept {
		if (srand_8 == 0) return -1;
		rand_8 = srand_8;
		return 0;
	}

	uint8_t asRand8(const uint8_t i) noexcept
	{
		switch (i) {
		case 0:return 0;
		case UINT8_MAX:return asRand8();
		default:return (asRand8() % (i + 1));
		}
	}

	inline uint8_t asRand8(const int32_t i) noexcept { return asRand8(uint8_t(i)); }

	uint8_t asRand8(const int64_t i) noexcept
	{
		if (i >= UINT8_MAX) return asRand8(uint8_t(UINT8_MAX));
		else return asRand8(uint8_t(i));
	}

}

#endif //Included AsProject Library