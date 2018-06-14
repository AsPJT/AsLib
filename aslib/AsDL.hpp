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
		enum:size_t
		{
			USING_DL_GRAPH_LOAD,
			USING_DL_GRAPH_SIMPLE_DRAW,
			USING_DL_GRAPH_DRAW,
			USING_DL_GRAPH_EXTEND_DRAW,
			USING_DL_GRAPH_PIXEL_SIZE,
		};

		inline bool ControlHandle(const int handle_, const size_t id_) { return (handle_ < 0 || size_t(handle_) >= id_); }
		int ControlGraph(const size_t id_, const int handle_ = -1, const char* const f_ = nullptr, const Pos4& p_ = pos4_0, const Pos2& p2_ = pos2_0, int* const x_ = nullptr, int* const y_ = nullptr) {
			static std::vector<TextureMainData> DL_tmd;
			switch (id_)
			{
			case USING_DL_GRAPH_LOAD:
				DL_tmd.emplace_back(AsLoadTex(f_));
				return int(DL_tmd.size() - 1);
			case USING_DL_GRAPH_DRAW:
				if (ControlHandle(handle_, DL_tmd.size())) return -1;
				DL_tmd[size_t(handle_)].drawP(p2_);
				return 0;
			case USING_DL_GRAPH_SIMPLE_DRAW:
				if (ControlHandle(handle_, DL_tmd.size())) return -1;
				DL_tmd[size_t(handle_)].draw();
				return 0;
			case USING_DL_GRAPH_EXTEND_DRAW:
				if (ControlHandle(handle_, DL_tmd.size())) return -1;
				DL_tmd[size_t(handle_)].draw(p_);
				return 0;
			case USING_DL_GRAPH_PIXEL_SIZE:
				if (ControlHandle(handle_, DL_tmd.size())) {
					*x_ = *y_ = 0;
					return -1;
				}
				const Pos2 p = DL_tmd[size_t(handle_)].pixelSize();
				*x_ = int(p.x);
				*y_ = int(p.y);
				return 0;
			}
			return 0;
		}
		inline int ControlPixelGraph(const int handle_, int* const x_, int* const y_) { return ControlGraph(USING_DL_GRAPH_PIXEL_SIZE, handle_, nullptr, pos4_0, pos2_0, x_, y_); }

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

		//グラフィックデータ制御関数
		inline int LoadGraph(const char* const f_) { return ControlGraph(USING_DL_GRAPH_LOAD, -1, f_); }
		inline int DrawGraph(const int handle, const int flag = 1) { return ControlGraph(USING_DL_GRAPH_SIMPLE_DRAW, handle,nullptr); }
		inline int DrawGraph(const int x, const int y, const int handle, const int flag = 1) { return ControlGraph(USING_DL_GRAPH_DRAW, handle, nullptr, pos4_0, Pos2(int32_t(x), int32_t(y))); }//todo
		inline int DrawExtendGraph(const int x1, const int y1, const int x2, const int y2, const int handle, const int flag=1) { return ControlGraph(USING_DL_GRAPH_EXTEND_DRAW, handle, nullptr, Pos4(int32_t(x1), int32_t(y1), int32_t(x2), int32_t(y2))); }
		inline int DrawExtendGraph(const Pos4& p_, const int handle, const int flag = 1) { return ControlGraph(USING_DL_GRAPH_EXTEND_DRAW, handle, nullptr, p_); }
		inline int GetGraphSize(const int handle, int * const x_, int * const y_) { return ControlPixelGraph(handle, x_, y_); }
		int LoadGraphScreen(const int x_, const int y_, const char* const f_, const int flag = 1) { return TextureMainData(AsLoadTex(f_)).drawP(Pos2(int32_t(x_),int32_t(y_))).return0(); }

		//簡易画面出力関数
		template<typename... Rest>inline int printfDx(const char* const format_string, const Rest&... rest) { return int(asPrint(format_string, rest...)); }

		//タッチパネル入力関連関数
		inline int GetTouchInputNum() { return int(asTouchNum()); }

		//その他画面操作系関数
		inline int SetGraphMode(const int x_, const int y_, const int bit_ = 32) { return int(AsChangeWindowSize(Pos2(int32_t(x_), int32_t(y_)))); }
		inline int SetGraphMode(const Pos2& pos_, const int bit_ = 32) { return int(AsChangeWindowSize(pos_)); }
		inline int SetFullScreenResolutionMode(const int ResolutionMode = 1) { return 0; }
		inline int SetFullScreenScalingMode(const int ScalingMode = 1) { return 0; }
		int GetScreenState(int* const x_, int* const y_, int* const col) { const Pos2 p = asWindowSize(); *x_ = int(p.x); *y_ = int(p.y); *col = 32; return 0; }
		int GetScreenState(int* const x_, int* const y_) { const Pos2 p = asWindowSize(); *x_ = int(p.x); *y_ = int(p.y); return 0; }
		int GetScreenState(int& x_, int& y_, int* const col) { const Pos2 p = asWindowSize(); x_ = int(p.x); y_ = int(p.y); *col = 32; return 0; }
		int GetScreenState(int& x_, int& y_) { const Pos2 p = asWindowSize(); x_ = int(p.x); y_ = int(p.y); return 0; }
		int GetScreenState(Pos2& pos_, int* const col) { pos_ = asWindowSize(); *col = 32; return 0; }
		int GetScreenState(Pos2& pos_) { pos_ = asWindowSize(); return 0; }
		int GetScreenState(Pos2* const pos_, int* const col) { *pos_ = asWindowSize(); *col = 32; return 0; }
		int GetScreenState(Pos2* const pos_) { *pos_ = asWindowSize(); return 0; }
		inline int SetDrawArea(const int x1, const int y1, const int x2, const int y2) { return 0; }//todo
		inline int SetDrawArea(const Pos4& p_) { return 0; }//todo
		inline int ClearDrawScreen() { return 0; }
		inline int SetBackgroundColor(const int r_, const int g_, const int b_) { return AsChangeColorBG(ColorRGB(uint8_t(r_ & 0xff), uint8_t(g_ & 0xff), uint8_t(b_ & 0xff))); }
		inline unsigned int GetColor(const int r_, const int g_, const int b_) { return (unsigned int((r_ & 0xff) << 0x10) + unsigned int((g_ & 0xff) << 0x8) + unsigned int(b_ & 0xff)); }
		inline unsigned int GetColor(const ColorRGBA& col_) { return (unsigned int((col_.r & 0xff) << 0x10) + unsigned int((col_.g & 0xff) << 0x8) + unsigned int(col_.b & 0xff)); }
		inline int SetDrawScreen(const int draw_screen = 1) { return 0; }
		inline int ScreenFlip() { return int(asLoop()); }

		//ウインドウモード関係
		inline int ChangeWindowMode(const int flag = 1) { return 0; }
		inline int SetMainWindowText(const char* const t_) { return int(AsChangeTitle(t_)); }
		inline int SetWindowIconID(const int ID = 1) { return 0; }
		inline int SetWindowSizeChangeEnableFlag(const int flag = 1) { return 0; }
		inline int SetWindowSizeExtendRate(const double ExRate = 1.0) { return 0; }


		//乱数取得関数
		inline int GetRand(const int rand_) { return int(asRand32(int32_t(rand_))); }
		inline int SRand(const int seed_) { return int(asSRand32(int32_t(seed_))); }
	}
//#endif

}
