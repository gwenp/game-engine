#include "TestPlugin.hpp"

TestPlugin::TestPlugin(IApplication* app) : ITestPlugin(app, "TestPlugin")
{

}

TestPlugin::~TestPlugin()
{

}

void TestPlugin::displayTestInformation()
{
	std::cout << "TestPlugin::displayTestInformation" << std::endl;
}

extern "C"
{
	Plugin* makePlugin(IApplication* app)
	{
		return new TestPlugin(app);
	}
}
