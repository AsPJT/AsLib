//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsProject Library
//
//                    Created by Gaccho (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------
#ifndef INCLUDED_AS_PROJECT_LIBRARY_EFFECT
#define INCLUDED_AS_PROJECT_LIBRARY_EFFECT


namespace AsLib
{

	struct Effect {

	private:

		float in{ 0.0f };
		float out{ 0.0f };

	public:

		float floatIn() const noexcept { return this->in; }
		float floatOut() const noexcept { return this->out; }
		double doubleIn() const noexcept { return double(this->in); }
		double doubleOut() const noexcept { return double(this->out); }
		uint8_t uint8_In() const noexcept { return uint8_t(this->in*255.0f); }
		uint8_t uint8_Out() const noexcept { return uint8_t(this->out*255.0f); }
		int32_t int32_In() const noexcept { return int32_t(this->in*255.0f); }
		int32_t int32_Out() const noexcept { return int32_t(this->out*255.0f); }

		Effect& setIn(const uint8_t var_) noexcept { this->in = float(var_) / 255.0f; return *this; }
		Effect& setIn(const int32_t var_) noexcept { this->in = float(var_) / 255.0f; return *this; }
		Effect& setIn(const float var_) noexcept { this->in = var_; return *this; }
		Effect& setIn(const double var_) noexcept { this->in = float(var_); return *this; }

		Effect& setOut(const uint8_t var_) noexcept { this->out = float(var_) / 255.0f; return *this; }
		Effect& setOut(const int32_t var_) noexcept { this->out = float(var_) / 255.0f; return *this; }
		Effect& setOut(const float var_) noexcept { this->out = var_; return *this; }
		Effect& setOut(const double var_) noexcept { this->out = float(var_); return *this; }

	};

#if defined(ASLIB_INCLUDE_DL) //DxLib

#elif defined(ASLIB_INCLUDE_S3) //Siv3D

#elif defined(ASLIB_INCLUDE_OF)

#elif defined(ASLIB_INCLUDE_C2)

#elif defined(ASLIB_INCLUDE_SF)
return 0;
#elif defined(ASLIB_INCLUDE_TP)

#else //Console

#endif

}

#endif //Included AsProject Library