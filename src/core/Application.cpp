#include "Application.hpp"

Application::Application(int argc, char *argv[]) : IApplication()
{
	Application* app = this;
	_pluginManager = new ConcretePluginManager(app,argc,argv);
}

Application::~Application()
{
	delete _pluginManager;
}

void Application::loadPlugins(int argc, char *argv[])
{
	_pluginManager->loadPlugin("./Plugins/ExtensionLoader/ExtensionLoader.plg","makePlugin");
	_pluginManager->loadPlugin("./Plugins/TestPlugin/TestPlugin.plg","makePlugin");
	_pluginManager->loadPlugin("./Plugins/LuaScriptingPlugin/LuaScriptingPlugin.plg","makePlugin");

	ITestPlugin* testPlugin = (ITestPlugin*) _pluginManager->getPluginByName("TestPlugin");
	ITestPlugin* luaScriptingPlugin = (ITestPlugin*) _pluginManager->getPluginByName("LuaScriptingPlugin");

	if(testPlugin != NULL)
		testPlugin->displayTestInformation();

	if(luaScriptingPlugin != NULL)
		luaScriptingPlugin->displayTestInformation();
}

