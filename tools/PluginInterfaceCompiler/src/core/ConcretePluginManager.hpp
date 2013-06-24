#ifndef DEF_CONCRETEPLUGINMANAGER
#define DEF_CONCRETEPLUGINMANAGER

#include "../api/PluginManager.hpp"
#include "../api/CommunicativeObject.hpp"
#include "../api/utility/Terminal_colors.hpp"
#include "../api/Plugin.hpp"

class Application;
class Config;

/** 
* @class ConcretePluginManager
*
* @brief A concrete implementation of the pluginManager
*
* The PluginManager class is a pure virtual class. This is the concrete implementation of this class. 
* Indeed, the effective code to manage plugin should not be embedded into plugins, but they should know methods signatures.
* 
* @author Gwenael Pluchon
* 
*/

class ConcretePluginManager: public PluginManager
{
public:
	ConcretePluginManager(Application* app,int argc, char **argv);
	~ConcretePluginManager();

	/** command line arguments getter
	* @return the command line arguments
	*/
	std::pair<int,char**> getCommandLineArgs();

	bool loadPlugin( std::string file, std::string factory_function);

	/**	Returns all the plugins that are of a specified type.
	*
	*   @param type the type of the searched plugins
	* 	@return a vector of plugins
	*/
	std::vector<Plugin*> getPluginsByType ( PluginType type );

	/**	Returns the plugin that are of a specified type.
	*
	*   @param name the name of the searchef plugin
	* 	@return pointer to plugin
	*/
	Plugin* getPluginByName ( std::string name );

private:
	Application* _app;
	int _argc;
	char ** _argv;
	/**
	* Utility method to load a .so file.
	*/
	void* loadObjectFromBinary( const std::string& soFile, const std::string& makerFunction);

	std::vector<Plugin*> _plugins;
};

#endif /* DEF_CONCRETEPLUGINMANAGER */
