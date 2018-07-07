//     ----------     ----------     ----------     ----------     ----------
//
//                                   AsFrameworks
//
//                    êßçÏé“: Ç™Ç¡ÇøÇÂ (wanotaitei@gmail.com)
//
//                                   Ver 0.0.0.0 Alpha
//
//     ----------     ----------     ----------     ----------     ----------

struct AsBaseApp {
	AsBaseApp() {}
	virtual ~AsBaseApp() {}

	virtual void asInit() {}
	virtual void asSetup() {}
	virtual void asUpdate() {}
	virtual void asDraw() {}
	virtual void asExit() {}
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