//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asライブラリ
//
//                    制作者: がっちょ (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
//#if defined(USING_DXLIB)
	namespace test
	{
		//
		inline unsigned int GetColor(const int r_, const int g_, const int b_) { return (unsigned int((r_ & 0xff) << 0x10) + unsigned int((g_ & 0xff) << 0x8) + unsigned int(b_ & 0xff)); }
		inline unsigned int GetColor(const ColorRGBA& col_) { return (unsigned int((col_.r & 0xff) << 0x10) + unsigned int((col_.g & 0xff) << 0x8) + unsigned int(col_.b & 0xff)); }

		//使用必須関数
		inline int DxLib_Init() { return 0; }
		inline int DxLib_End() { return 0; }
		inline int ProcessMessage() { return 0; }
		//図形描画関数
		inline int DrawBox(const int x1, const int y1, const int x2, const int y2, const unsigned int col_, const int flag = 1) { return int(asRect(Pos4(int32_t(x1), int32_t(y1), int32_t(x2), int32_t(y2)), ColorRGBA(col_))); }
		inline int DrawBox(const int x1, const int y1, const int x2, const int y2, const ColorRGBA& col_, const int flag = 1) { return int(asRect(Pos4(int32_t(x1), int32_t(y1), int32_t(x2), int32_t(y2)), col_)); }
		inline int DrawBox(const Pos4& p_, const ColorRGBA& col_, const int flag = 1) { return int(asRect(Pos4(p_.x1, p_.y1, p_.x2, p_.y2), col_)); }
		inline int DrawBox(const ColorRGBA& col_, const Pos4& p_, const int flag = 1) { return int(asRect(Pos4(p_.x1, p_.y1, p_.x2, p_.y2), col_)); }
		inline int DrawBox(const Pos4& p_, const unsigned int col_, const int flag = 1) { return int(asRect(Pos4(p_.x1, p_.y1, p_.x2, p_.y2), ColorRGBA(col_))); }

		//
		int ControlGraph(const char id_, const int handle_ = -1, const char* const file_name = nullptr) {
			static std::vector<TextureMainData> DL_tmd;
			switch (id_)
			{
			case 'a':
				DL_tmd.emplace_back(AsLoadTex(file_name));
				return int(DL_tmd.size() - 1);
			case 'd':
				DL_tmd[size_t(handle_)].draw();
				return 0;
			}
			return 0;
		}
		inline int LoadGraph(const char* const file_name) { return ControlGraph('a', -1, file_name); }
		inline int DrawGraph(const int x, const int y, const int handle, const int TransFlag = 1) { return ControlGraph('d', handle); }

		//簡易画面出力関数
		template<typename... Rest>inline int printfDx(const char* const format_string, const Rest&... rest) { return int(asPrint(format_string, rest...)); }

		//タッチパネル入力関連関数
		inline int GetTouchInputNum() { return int(asTouchNum()); }

		//その他画面操作系関数
		inline int SetGraphMode(const int x_, const int y_, const int bit_ = 32) { return int(AsChangeWindowSize(Pos2(int32_t(x_), int32_t(y_)))); }
		inline int SetGraphMode(const Pos2& pos_, const int bit_ = 32) { return int(AsChangeWindowSize(pos_)); }
		inline int SetMainWindowText(const char* const t_) { return int(AsChangeTitle(t_)); }

		//乱数取得関数
		inline int GetRand(const int rand_) { return int(asRand32(int32_t(rand_))); }
		inline int SRand(const int seed_) { return int(asSRand32(int32_t(seed_))); }
	}
//#endif

}
