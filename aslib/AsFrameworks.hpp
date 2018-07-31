//     ----------     ----------     ----------     ----------     ----------
//
//                                   AsFrameworks
//
//                    Created by Gaccho (wanotaitei@gmail.com)
//
//                                   Ver 0.0.0.0 Alpha
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
#if defined(ASLIB_INCLUDE_OF)
	struct AsBaseApp : public ofBaseApp {
#else
	struct AsBaseApp {
#endif
		AsBaseApp() = default;
		virtual ~AsBaseApp() {}

		virtual void asInit() {}
		virtual void asSetup() {}
		virtual void asStart() {}
		virtual void asUpdate() {}
		virtual void asDraw() {}
		virtual void asExit() {}
		virtual void asQuit() {}
		virtual void asEnd() {}

#if defined(ASLIB_INCLUDE_OF)
		void setup() { asInit(); asSetup(); asStart(); }
		void update() {
			asMousePosSave(true, Pos2(int32_t(mouseX), int32_t(mouseY)));
			asUpdate();
		}
		void draw() { asDraw(); }
		void exit() { asExit(); asQuit(); asEnd(); }
		void mouseMoved(int x, int y) {
			asMouseButtonSave(false, true); //todo
		}
		void mousePressed(int x, int y, int button) {
			asMouseButtonSave(true, false, true, size_t(button));
		}
#endif

	};

	template<typename AsApp>
	const int32_t asRunApp(MainControl& mc, AsApp* const as_app)
	{
#if defined(ASLIB_INCLUDE_OF)
		return ofRunApp(as_app);
#else
		if (as_app == nullptr) return -1;
		as_app->asInit();
		as_app->asSetup();
		while (mc.loop())
		{
			as_app->asUpdate();
			as_app->asDraw();

		}
		as_app->asExit();
		return 0;
#endif
	}

}
