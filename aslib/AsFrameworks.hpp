//     ----------     ----------     ----------     ----------     ----------
//
//                                   AsFrameworks
//
//                    êßçÏé“: Ç™Ç¡ÇøÇÂ (wanotaitei@gmail.com)
//
//                                   Ver 0.0.0.0 Alpha
//
//     ----------     ----------     ----------     ----------     ----------

#if defined(ASLIB_INCLUDE_OF)
struct AsBaseApp : public ofBaseApp {
#else
struct AsBaseApp {
#endif
	AsBaseApp() {}
	virtual ~AsBaseApp() {}

	virtual void asInit() {}
	virtual void asSetup() {}
	virtual void asUpdate() {}
	virtual void asDraw() {}
	virtual void asExit() {}

#if defined(ASLIB_INCLUDE_OF)
	void setup() { asInit(); asSetup(); }
	void update() { asUpdate(); }
	void draw() { asDraw(); }
	void exit() { asExit(); }
#endif

};

template<typename AsApp>
const int32_t asRunApp(MainControl& mc, AsApp* const as_app)
{
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
}