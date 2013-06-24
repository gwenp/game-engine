#include "Plugin.hpp"

#include "PluginManager.hpp"
#include "IApplication.hpp"

Plugin::Plugin(IApplication* app,std::string name, PluginType type) : CommunicativeObject(name), _app(app), _type(type)
{}

Plugin::~Plugin()
{
}

PluginType Plugin::getType()
{
	return _type;
}

PluginManager* Plugin::getPluginManager()
{
	return _app->getPluginManager();
}

IApplication* Plugin::getApplication()
{
	return _app;
}

