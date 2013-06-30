#ifndef DEF_PLUGIN
#define DEF_PLUGIN



#include "CommunicativeObject.hpp"

#include <string>
#include <iostream>
#include <map>

class IApplication;
class PluginManager;

//TODO dynamise this shit
enum PluginType { EXPORT, GUI, PARSER, GFXEMBED, GFX, TOOL, STRATEGY, PROJECTMANAGER, POLICY };
typedef std::string PluginKey;


/** 
* @class Plugin
*
* @brief the base hierarchy of full-C++ plugin system
*
* Each part of the program written as a plugin should inherit from this. 
* It handles events (one only atm) send by the kernel or other plugins.
* 
* @author Gwenael Pluchon
* 
*/

class Plugin : public CommunicativeObject
{
public:
	Plugin(IApplication* app, std::string name, PluginType type);
	~Plugin();
	/**
	* This method is called by the kernel itself to let plugin act with others when a plugin is loaded
	*/
	virtual void onLoad(){};

	/**
	 * @brief PluginType getter
	 * @return the type of the plugin
	 */
	virtual PluginType getType();

	/**
	 * @brief Application getter
	 * @return the Application interface
	 */
	virtual IApplication* getApplication();

	PluginKey getKey();

protected:

	Plugin* getPlugin(std::string pluginName);

private:
	/**
	 * @brief PluginManager getter
	 * @return the PluginManager interface
	 */
	PluginManager* getPluginManager();


	std::map<std::string, bool> _methods;

	IApplication* _app;
	PluginType _type;

};


/**
 * @brief the Plugin factory function.
 * This function MUST BE IMPLEMENTED for every plugin. This is the main entry point of every Plugin .so file.
 */
typedef Plugin *(*maker_plugin)(IApplication* app);

#endif /* DEF_PLUGIN */
