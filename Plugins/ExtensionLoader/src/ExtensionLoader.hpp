#ifndef DEF_EXTENSIONLOADER
#define DEF_EXTENSIONLOADER

#include "../../src/api/Plugin.hpp"
#include <iostream>

class ExtensionLoader : public Plugin
{
public:
	ExtensionLoader(IApplication* app);
	~ExtensionLoader();

	void onLoad();

private:
};

#endif /* DEF_EXTENSIONLOADER */
