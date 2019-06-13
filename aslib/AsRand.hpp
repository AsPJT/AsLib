/*#######################################################################################
	Made by Kasugaccho
	Made by As Project
	https://github.com/Kasugaccho/AsLib
	wanotaitei@gmail.com

	This code is licensed under CC0.
#######################################################################################*/
#ifndef INCLUDED_AS_PROJECT_LIBRARY_RAND
#define INCLUDED_AS_PROJECT_LIBRARY_RAND


namespace AsLib
{

	static std::uint32_t rand_32{ UINT32_MAX };
	std::uint32_t asRand32() noexcept
	{
		rand_32 = rand_32 ^ (rand_32 << 13);
		rand_32 = rand_32 ^ (rand_32 >> 17);
		return rand_32 = rand_32 ^ (rand_32 << 5);
	}
	std::int32_t asSRand32(const std::uint32_t srand_32) noexcept {
		if (srand_32 == 0) return -1;
		rand_32 = srand_32;
		return 0;
	}

	inline void asRand32(std::int32_t* const i) noexcept { *i = std::int32_t(asRand32()); }
	inline void asRand32(std::int32_t* const array_, const std::size_t s_) noexcept { for (std::size_t i{}; i < s_; ++i) array_[i] = std::int32_t(asRand32()); }
	inline void asRand32(std::vector<std::int32_t>& array_) noexcept { const std::size_t s = array_.size(); for (std::size_t i{}; i < s; ++i) array_[i] = std::int32_t(asRand32()); }

	inline std::int32_t asRand() noexcept { return std::int32_t(asRand32()); }

	std::int32_t asRand32(const std::int32_t i) noexcept
	{
		if (i <= 0) return 0;

		switch (i) {
		case INT32_MAX:return std::int32_t(asRand32() & INT32_MAX);
		default:return (std::int32_t(asRand32() & INT32_MAX) % (i + 1));
		}
	}

	std::int32_t asRand32(const std::uint32_t i) noexcept
	{
		if (i == 0) return 0;
		if (i >= INT32_MAX) return std::int32_t(asRand32() & INT32_MAX);
		return (std::int32_t(asRand32() & INT32_MAX) % (i + 1));
	}
	inline std::int32_t asRand(const std::uint32_t rand_) noexcept { return std::int32_t(asRand32(rand_)); }


	static std::uint8_t rand_8{ UINT8_MAX };
	std::uint8_t asRand8() noexcept
	{
		rand_8 ^= (rand_8 << 7);
		rand_8 ^= (rand_8 >> 7);
		return rand_8 ^= (rand_8 << 1);
	}

	std::int32_t asSRand8(const std::uint8_t srand_8) noexcept {
		if (srand_8 == 0) return -1;
		rand_8 = srand_8;
		return 0;
	}

	std::uint8_t asRand8(const std::uint8_t i) noexcept
	{
		switch (i) {
		case 0:return 0;
		case UINT8_MAX:return asRand8();
		default:return (asRand8() % (i + 1));
		}
	}

	inline std::uint8_t asRand8(const std::int32_t i) noexcept { return asRand8(std::uint8_t(i)); }

	std::uint8_t asRand8(const std::int64_t i) noexcept
	{
		if (i >= UINT8_MAX) return asRand8(std::uint8_t(UINT8_MAX));
		else return asRand8(std::uint8_t(i));
	}

}

#endif //Included AsProject Library