#ifndef DEF_PLUGINMANAGER
#define DEF_PLUGINMANAGER

#include "CommunicativeObject.hpp"
#include "Plugin.hpp"

#include <dlfcn.h> /* for library loading */
#include <vector>
#include <iostream>
#include <utility>
#include <iostream>


/** 
* @class PluginManager
*
* @brief The standard plugin manager for "full-C++" plugins
*
* It inherits CommunicativeObject in the case it have (or the core) to communicate directy with plugins. 
* But a perfect software should be only plugins, doesn't it?
* 
* @author Gwenael Pluchon
* 
*/
class PluginManager:public CommunicativeObject
{
public:
	PluginManager(int /* argc */, char ** /* argv */):CommunicativeObject("PluginManager"){};
	
	virtual std::pair<int,char**> getCommandLineArgs()=0;

	/**	loads the library file "file" (.so library).
	*	calls the method "factory_function" to get an instance of the master class of the plugin.
	* 	push_back the plugin onto a collection of plugin
	*
	*   @param file path of the library
	*   @param factory_function method creating an instance of the master class of the plugin
	*	@return true if the plugin is effectively loaded, else false.
	*/
	virtual bool loadPlugin(std::string file, std::string factory_function)=0;

	/**	Returns all plugins that are of a specified type.
	*
	*   @param type a type of plugin
	* 	@return a vector of plugins
	*/
	virtual std::vector<Plugin*> getPluginsByType ( PluginType type )=0;

	/**	Returns the plugin that are of a specified type.
	*
	*   @param name the name of the searched plugin
	* 	@return pointer to plugin
	*/
	virtual Plugin* getPluginByName ( std::string name )=0;
};


#endif /* DEF_PLUGINMANAGER */
