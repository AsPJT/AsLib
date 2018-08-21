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
#elif defined(ASLIB_INCLUDE_C2)
	struct AsBaseApp : private cocos2d::Scene {
#else
	struct AsBaseApp {
#endif
		AsBaseApp() = default;
		virtual ~AsBaseApp() {}

		virtual void asInit() {}
		virtual void asSetup() {}
		virtual void asStart() {}
		virtual void asUpdate() {}
		virtual void asUpdateStart() {}
		virtual void asUpdateEnd() {}
		virtual void asDraw() {}
		virtual void asExit() {}
		virtual void asQuit() {}
		virtual void asEnd() {}

#if defined(ASLIB_INCLUDE_OF)
		void setup() { asStart(); asInit(); asSetup(); }
		void update() {
			asMousePosSave(true, Pos2(int32_t(mouseX), int32_t(mouseY)));
			asUpdateStart();
			asUpdate();
		}
		void draw() { asDraw(); asUpdateEnd();}
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
		if (as_app == nullptr) return -1;
		return ofRunApp(as_app);
#elif defined(ASLIB_INCLUDE_C2)
		return Application::getInstance()->run();
#else
		if (as_app == nullptr) return -1;
		as_app->asStart();
		as_app->asInit();
		as_app->asSetup();
		while (asLoop())
		{
			as_app->asUpdateStart();
			as_app->asUpdate();
			as_app->asDraw();
			as_app->asUpdateEnd();
		}
		as_app->asExit();
		as_app->asQuit();
		as_app->asEnd();
		return 0;
#endif
	}

}
