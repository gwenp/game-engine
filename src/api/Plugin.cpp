#include "Plugin.hpp"

#include "PluginManager.hpp"
#include "IApplication.hpp"

Plugin::Plugin(IApplication* app,std::string name, PluginType type) : CommunicativeObject(name), _app(app), _type(type)
{}

Plugin::~Plugin()
{}

PluginType Plugin::getType()
{
	return _type;
}

IApplication* Plugin::getApplication()
{
	return _app;
}

PluginKey Plugin::getKey()
{
	return getName();
}


Plugin* Plugin::getPlugin(std::string pluginName)
{
	return getPluginManager()->getPluginByName(pluginName, getKey());
}


PluginManager* Plugin::getPluginManager()
{
	return _app->getPluginManager();
}