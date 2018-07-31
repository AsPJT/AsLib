//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsProject Library
//
//                    Created by Gaccho (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{

	struct Effect {

	private:

		float in=0.0f;
		float out=0.0f;

	public:

		const float floatIn() const { return this->in; }
		const float floatOut() const { return this->out; }
		const double doubleIn() const { return double(this->in); }
		const double doubleOut() const { return double(this->out); }
		const uint8_t uint8_In() const { return uint8_t(this->in*255.0f); }
		const uint8_t uint8_Out() const { return uint8_t(this->out*255.0f); }
		const int32_t int32_In() const { return int32_t(this->in*255.0f); }
		const int32_t int32_Out() const { return int32_t(this->out*255.0f); }

		Effect& setIn(const uint8_t var_) { this->in = float(var_) / 255.0f; return *this; }
		Effect& setIn(const int32_t var_) { this->in = float(var_) / 255.0f; return *this; }
		Effect& setIn(const float var_) { this->in = var_; return *this; }
		Effect& setIn(const double var_) { this->in = float(var_); return *this; }

		Effect& setOut(const uint8_t var_) { this->out = float(var_) / 255.0f; return *this; }
		Effect& setOut(const int32_t var_) { this->out = float(var_) / 255.0f; return *this; }
		Effect& setOut(const float var_) { this->out = var_; return *this; }
		Effect& setOut(const double var_) { this->out = float(var_); return *this; }

	};

#if defined(ASLIB_INCLUDE_DL) //DxLib

#elif defined(ASLIB_INCLUDE_S3) //Siv3D

#elif defined(ASLIB_INCLUDE_OF)

#elif defined(ASLIB_INCLUDE_TP)

#else //Console

#endif

}
