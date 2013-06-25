#include "JsonConfigurationFileManager.hpp"

JsonConfigurationFileManager::JsonConfigurationFileManager(IApplication* app) : IConfigurationManager(app, "JsonConfigurationFileManager")
{

}

JsonConfigurationFileManager::~JsonConfigurationFileManager()
{}

IConfiguration* JsonConfigurationFileManager::initializeSource(std::string sourceUrl)
{
	return new JsonConfiguration(sourceUrl);
}

extern "C"
{
	Plugin* makePlugin(IApplication* app)
	{
		return new JsonConfigurationFileManager(app);
	}
}
