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
	_pluginManager->loadPlugin("./Plugins/LuaScriptingPlugin/LuaScriptingPlugin.plg","makePlugin");
	_pluginManager->loadPlugin("./Plugins/JsonConfigurationFileManager/JsonConfigurationFileManager.plg","makePlugin");
	_pluginManager->loadPlugin("./Plugins/Logger/Logger.plg","makePlugin");
	_pluginManager->loadPlugin("./Plugins/OpenGL/OpenGL.plg","makePlugin");
	_pluginManager->loadPlugin("./Plugins/OpenGLScene/OpenGLScene.plg","makePlugin");
	_pluginManager->loadPlugin("./Plugins/OpenGLModelManager/OpenGLModelManager.plg","makePlugin");
	_pluginManager->loadPlugin("./Plugins/TextureRegistrar/TextureRegistrar.plg","makePlugin");

	// ITestPlugin* luaScriptingPlugin = (ITestPlugin*) _pluginManager->getPluginByName("LuaScriptingPlugin", "");
	// IConfigurationManager* config = (IConfigurationManager*) _pluginManager->getPluginByName("JsonConfigurationFileManager", "");
	// ILogger* logger = (ILogger*) _pluginManager->getPluginByName("Logger", "");
	IOpenGL* openGL = (IOpenGL*) _pluginManager->getPluginByName("OpenGL", "app", true);
	IOpenGLScene* openGLScene = (IOpenGLScene*) _pluginManager->getPluginByName("OpenGLScene", "app", true);

	_pluginManager->callOnLoad();
	// if(luaScriptingPlugin != NULL)
	// 	luaScriptingPlugin->displayTestInformation();

	// if(config != NULL)
	// {
	// 	IConfiguration* configFile = config->initializeSource("/home/gwen/Programmation/cpp/game-engine/data/test.json");
	// 	std::cout << configFile->getValue("encoding") << std::endl;
	// 	(*logger)("test", "log message");
	// }
	// if(openGL != NULL)
	// 	openGL->init();

	// if(openGLScene != NULL)
	// 	openGLScene->init();

	if(openGL != NULL)
		openGL->mainLoop();
}

