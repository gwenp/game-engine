#ifndef DEF_TESTPLUGIN
#define DEF_TESTPLUGIN

#include "../../src/api/Interfaces/ITestPlugin.hpp"
#include <iostream>

class TestPlugin : public ITestPlugin
{
public:
	TestPlugin(IApplication* app);
	~TestPlugin();

	void displayTestInformation(); 
private:
};

#endif /* DEF_TESTPLUGIN */
