#ifndef DEF_APPLICATION
#define DEF_APPLICATION

#include <string>

#include <map>
#include <iostream>

#include "ConcretePluginManager.hpp"

#include "../api/IApplication.hpp"
#include "../api/Interfaces/ITestPlugin.hpp"
#include "../api/Interfaces/ILogger.hpp"
#include "../api/Interfaces/OpenGL/IOpenGL.hpp"
#include "../api/Interfaces/OpenGL/IOpenGLScene.hpp"
#include "../api/Interfaces/Configuration/IConfigurationManager.hpp"

/** 
* @class Application
*
* @author Gwenael Pluchon
*
* @brief The main class of the program.
* 
* This is a singleton. It is the base class of the kernel. Here are defined the plugin manager, and other useful classes
* 
*/

class Application : public IApplication
{
public:
	Application(int argc, char **argv);
	~Application();

	/**	
	*	Loads the plugins that are launched at the launch of the program. This is not for lazy-loading plugins
	*/
	void loadPlugins(int argc, char *argv[]);
	
	PluginManager* getPluginManager(){ return _pluginManager; };
private:
	ConcretePluginManager* _pluginManager;
};

#endif /* DEF_APPLICATION */
