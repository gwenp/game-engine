#ifndef DEF_ITESTPLUGIN
#define DEF_ITESTPLUGIN

#include "../Plugin.hpp"
#include "../IApplication.hpp"

#include <string>

class ITestPlugin : public Plugin
{
public:
	ITestPlugin(IApplication* app, std::string name) : Plugin(app, name, TOOL) {};

	virtual void displayTestInformation()=0;
};

#endif /* DEF_ITESTPLUGIN */
