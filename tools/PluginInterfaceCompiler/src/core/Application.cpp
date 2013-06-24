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
	_pluginManager->loadPlugin("./Plugins/InputManifestFile/InputManifestFile.plg","makePlugin");
	_pluginManager->loadPlugin("./Plugins/OutputApiHeader/OutputApiHeader.plg","makePlugin");

	IParserPlugin* input = (IParserPlugin*) _pluginManager->getPluginByName("InputManifestFile");
	IOutputPlugin* output = (IOutputPlugin*) _pluginManager->getPluginByName("OutputApiHeader");

	output->doExport("test/Plugins/TestPlugin");
}

